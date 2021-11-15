/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

/*
 * This file is autogenerated by <kernel>/tools/hardware/outputs/c_header.py.
 */

#pragma once

#define physBase 0x80000000

#ifndef __ASSEMBLER__

#include <config.h>
#include <mode/hardware.h>  /* for KDEV_BASE */
#include <linker.h>         /* for BOOT_RODATA */
#include <basic_types.h>    /* for p_region_t, kernel_frame_t (arch/types.h) */

/* INTERRUPTS */
/* KERNEL DEVICES */

/* The C parser used for formal verification process follows strict C rules,
 * which do not allow empty arrays. Thus this is defined as NULL.
 */
static const kernel_frame_t BOOT_RODATA *const kernel_device_frames = NULL;
#define NUM_KERNEL_DEVICE_FRAMES 0

/* PHYSICAL MEMORY */
static const p_region_t BOOT_RODATA avail_p_regs[] = {
    /* /memory@80000000 */
    {
        .start = 0x80200000,
        .end   = 0x17ff00000
    },
};

#endif /* !__ASSEMBLER__ */