
#include <stdio.h>
#include <sel4/sel4.h>
#include <sel4platsupport/bootinfo.h>
#include <utils/util.h>

int main(int argc, char *argv[]) {
    /* parse the location of the seL4_BootInfo data structure from
    the environment variables set up by the default crt0.S */
    seL4_BootInfo *info = platsupport_get_bootinfo();


    printf("    CSlot   \tPaddr           \tSize\tType\n");
    for (seL4_CPtr slot = info->untyped.start; slot != info->untyped.end; slot++) {
        seL4_UntypedDesc *desc = &info->untypedList[slot - info->untyped.start];
        printf("%8p\t%16p\t2^%d\t%s\n", (void *) slot, (void *) desc->paddr, desc->sizeBits, desc->isDevice ? "device untyped" : "untyped");
    }
    seL4_Error error;

    // list of general seL4 objects
    seL4_Word objects[] = {seL4_TCBObject, seL4_EndpointObject, seL4_NotificationObject};
    // list of general seL4 object size_bits
    seL4_Word sizes[] = {seL4_TCBBits, seL4_EndpointBits, seL4_NotificationBits};

    // seL4_EndpointBits and seL4_NotificationBits are both less than seL4_TCBBits, which
    // means that all objects together fit into the size of two TCBs, or 2^(seL4_TCBBits + 1):
    seL4_Word untyped_size_bits = seL4_TCBBits + 1;
    seL4_CPtr parent_untyped = 0;
    seL4_CPtr child_untyped = info->empty.start;

    // First, find an untyped big enough to fit all of our objects
    for (int i = 0; i < (info->untyped.end - info->untyped.start); i++) {
        if (info->untypedList[i].sizeBits >= untyped_size_bits && !info->untypedList[i].isDevice) {
            parent_untyped = info->untyped.start + i;
            break;
        }
    }
    // create an untyped big enough to retype all of the above objects from
    printf("parent: %d\nuntypedo: %d\nsizebits: %d\ncapthread: %d\nchild: %d\n", parent_untyped, seL4_UntypedObject, untyped_size_bits, seL4_CapInitThreadCNode, child_untyped);
   
    parent_untyped = 394;
 
    error = seL4_Untyped_Retype(parent_untyped, // the untyped capability to retype
                                seL4_UntypedObject, // type
                                untyped_size_bits,  //size
                                seL4_CapInitThreadCNode, // root
                                0, // node_index
                                0, // node_depth
                                child_untyped, // node_offset
                                1 // num_caps
                                );
    ZF_LOGF_IF(error != seL4_NoError, "Failed to retype");

    // use the slot after child_untyped for the new TCB cap:
    seL4_CPtr child_tcb = child_untyped + 1;
    seL4_Untyped_Retype(child_untyped, seL4_TCBObject, 0, seL4_CapInitThreadCNode, 0, 0, child_tcb, 1);

    // try to set the TCB priority
    error = seL4_TCB_SetPriority(child_tcb, seL4_CapInitThreadTCB, 10);
    ZF_LOGF_IF(error != seL4_NoError, "Failed to set priority");

    // use the slot after child_tcb for the new endpoint cap:
    seL4_CPtr child_ep = child_tcb + 1;
    seL4_Untyped_Retype(child_untyped, seL4_EndpointObject, 0, seL4_CapInitThreadCNode, 0, 0, child_ep, 1);

    // identify the type of child_ep
    uint32_t cap_id = seL4_DebugCapIdentify(child_ep);
    ZF_LOGF_IF(cap_id == 0, "Endpoint cap is null cap");

    // use the slot after child_ep for the new notification cap:
    seL4_CPtr child_ntfn = child_ep + 1;
    seL4_Untyped_Retype(child_untyped, seL4_NotificationObject, 0, seL4_CapInitThreadCNode, 0, 0, child_ntfn, 1);

    // try to use child_ntfn
    error = seL4_TCB_BindNotification(child_tcb, child_ntfn);
    ZF_LOGF_IF(error != seL4_NoError, "Failed to bind notification.");

    error = seL4_CNode_Revoke(seL4_CapInitThreadCNode, child_untyped, seL4_WordBits);
    assert(error == seL4_NoError);

    // allocate the whole child_untyped as endpoints
    // Remember the sizes are exponents, so this computes 2^untyped_size_bits / 2^seL4_EndpointBits:
    seL4_Word num_eps = BIT(untyped_size_bits - seL4_EndpointBits);
    error = seL4_Untyped_Retype(child_untyped, seL4_EndpointObject, 0, seL4_CapInitThreadCNode, 0, 0, child_tcb, num_eps);
    ZF_LOGF_IF(error != seL4_NoError, "Failed to create endpoints.");

    printf("Success\n");

    return 0;
}
