#!/bin/sh

cwd=$(pwd)

submoduleshit ()
{
	git fetch
	git merge origin/master
}


#kernel
cd $cwd/dobbyOS/kernel
submoduleshit

#musllibc
cd $cwd/dobbyOS/projects/musllibc
submoduleshit

#sel4_libs
cd $cwd/dobbyOS/projects/sel4_libs
submoduleshit

#sel4runtime
cd $cwd/dobbyOS/projects/sel4runtime
submoduleshit

#util_libs
cd $cwd/dobbyOS/projects/util_libs
submoduleshit

# tools
cd $cwd/tools
submoduleshit


