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
```
to make your live easier, set an alias to start the docker container
```
echo $'alias container=\'make -C /<path>/<to>/seL4-CAmkES-L4v-dockerfiles user HOST_DIR=$(pwd)\'' 
```
in a new terminal run
```
source ~/.bashrc
```
reference: https://docs.sel4.systems/projects/dockerfiles/

