#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int auth(char *username, unsigned int serial)
{
    username[strcspn(username, "\n")] = '\0';
    size_t username_length = strnlen(username, 32);
    int ret = 0;
    if (username_length <= 5)
        return (1);
    int valid_serial = ((username[3] ^ 0x1337) + 0x5eeded);
    int i = 0;
    while (i < username_length)
    {
        if (username[i] <= 0x1f)
        {
            return (1);
        }
        valid_serial += (username[i] ^ valid_serial) % 0x539;
        i++;
    }
    printf("valid_serial=%u\n", valid_serial);
    printf("serial=%u\n", serial);
    return serial != valid_serial;
}

int main(int argc, char** argv)
{
    char username[32];
    unsigned int serial;
    puts("********************************…");
    puts("*\t\tlevel06\t\t  *");
    puts("********************************…");
    printf("-> Enter Login: ");
    fgets(username, 0x20, stdin);
    puts("********************************…");
    puts("***** NEW ACCOUNT DETECTED *****…");
    puts("********************************…");
    printf("-> Enter Serial: ");
    scanf("%u", &serial);
    int ret;
    if (auth(username, serial) != 0)
        ret = 1;
    else
    {
        puts("Authenticated!");
        system("/bin/sh");
        ret = 0;
    }
}
