#!/bin/bash

../../../tools/asl/bin/asl -U -L spec128_0.a80
../../../tools/asl/bin/p2bin spec128_0.p ../basic128.rom -r '$-$' -k
