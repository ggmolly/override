import sys
import os

MAX_SERIAL = (2**32 - 1) // 2 # 32-bit signed integer max

def keygen(username: str) -> int:
    serial = (ord(username[3]) ^ 0x1337) + 0x5eeded
    for c in username:
        serial += (ord(c) ^ serial) % 0x539
    return serial % MAX_SERIAL

if __name__ == "__main__":
    username = os.getenv("USER") if len(sys.argv) < 2 else sys.argv[1]
    if len(username) <= 5:
        print("[!] username must be at least 6 characters long")
        exit(1)
    print(keygen(username))