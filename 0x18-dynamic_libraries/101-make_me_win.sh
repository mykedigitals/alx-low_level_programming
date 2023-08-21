#!/bin/bash

wget -P .. https://raw.githubusercontent.com/x9x96/alx-low_level_programming/master/0x18-dynamic_libraries/injection.so
export LD_PRELOAD=/tmp/injection.so
