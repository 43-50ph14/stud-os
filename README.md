# stud-os
implementation of an operating system for riscv

# setup
## to do once
**install docker on your system**
visit https://www.docker.com/ and figure out yourself

**clone the repo**
```
git clone https://github.com/43-50ph14/stud-os.git
cd seL4-CAmkEs-L4v-dockerfiles
make user
make user_sel4-riscv
```
to make your live easier, set an alias to start the docker container
```
echo $'alias container_risc-v=\'make -C /<path>/<to>/seL4-CAmkES-L4v-dockerfiles user_sel4-riscv HOST_DIR=$(pwd)\'' >> ~/.bashrc
```
in a new terminal run
```
source ~/.bashrc
```
reference: https://docs.sel4.systems/projects/dockerfiles/

## init build dir
 ```
 cd dobbyOS
 # start container
 container_risc-v
 # initialize build
 mkdir build && cd build
 ../init-build.sh -DPLATFORM=spike -DSIMULATION=TRUE
ninja
# simulate 
./simulate
```
 
## something like a workflow

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

