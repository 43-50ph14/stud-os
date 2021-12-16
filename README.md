# stud-os
implementation of an operating system for riscv

# setup
## to do once
**install docker on your system**
visit https://www.docker.com/ and figure out yourself

**clone the repo**
```
git clone https://github.com/43-50ph14/stud-os.git
# submodule stuff
# symlink stuff
```
start docker container
```
make user_sel4-riscv HOST_DIR=/mnt/space/coding/UniZeug/sem05/studienarbeit/stud-os/dobbyOS
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
 
## something like a workflow [TODO]

1. work do stuff whatever
2. simulate/compile
```
# in your directory with the code
conatiner_risc-v
cd build
ninja
./simulate
```


⚠️ never ever bring a build directory to git!!! ⚠️

