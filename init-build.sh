#!/bin/bash
# intended to be symlinked into the same location as your roor CMakeList.txt file
# invoced from empty build dir

set -eu

# path to script
SCRIPT_PATH=${0%/*}
# save name for debut messages
SCRIPT_NAME=${0##*/}
CACHE_DIR="/cache"
# script path and current dir should not be the same (should be triggerd from build dir)
if [ "PWD" = "$SCRIPT_PATH" ]
then 
  echo "\"$SCRIPT_NAME\" should be invoced rom build directory, not source directory" >&2
  exit 1
fi

# initialize cmake
 cmake -DCMAKE_TOOLCHAIN_FILE="$SCRIPT_PATH"/kernel/gcc.cmake -G Ninja "$@" \
        -DSEL4_CACHE_DIR="$CACHE_DIR" -C "$SCRIPT_PATH/settings.cmake" "$SCRIPT_PATH"
