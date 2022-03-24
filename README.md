# stud-os
implementation of an operating system for riscv

# setup
## to do once
**install docker on your system**
visit https://www.docker.com/ and figure out yourself
start docker deamon 

**clone the repo**
```
git clone https://github.com/43-50ph14/stud-os.git
```
**initialize submodule stuff**

```
# initialize submodules (you are at the top level directory)
git submodule init
git submodule update
# now navigate to dobbyOS/tools and do the same again
git submodule init
git submodule update
```

start docker container (you must be in seL4-CAmkES-L4v-dockerfiles directory)
```
make user_sel4-riscv HOST_DIR=/<whatever>/stud-os/dobbyOS
```
reference: https://docs.sel4.systems/projects/dockerfiles/

## init build dir
 ```
 # start container
 # initialize build
 mkdir build && cd build
 ../init-build.sh  -DPLATFORM=spike -DSIMULATION=TRUE -DCROSS_COMPILER_PREFIX=riscv64-unknown-linux-gnu- 
ninja
# simulate 
./simulate
```
 
## updating submodules

to update all submodules simply run the `update_submodule.sh` script.
 
## something like a workflow [TODO]

1. work do stuff whatever
2. simulate/compile


⚠️ never ever bring a build directory to git!!! ⚠️

## metapad

https://md.margau.net/studienarbeit-meta?view

