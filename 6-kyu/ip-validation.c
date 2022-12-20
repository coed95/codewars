/* no arpa/inet.h */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define MIN_LEN  7
#define MAX_LEN  15

bool is_valid_ip(const char * addr)
{
    unsigned int i, len;
    unsigned int dots;
    unsigned int num[4];
  
    len = strlen(addr);
    dots = 0;
  
    if (len < MIN_LEN || len > MAX_LEN)
        return false;
  
    for (i = 0; i < len; ++i)
    {
        if (addr[i] == ' ')
            return false;
      
        if (addr[i] == '.' && addr[i + 1] == '0')
            return false;
      
        if (addr[i] == '.')
            ++dots;
    }
  
    if (dots > 3)
        return false;
  
    if (sscanf(addr, "%3u.%3u.%3u.%3u", &num[0], &num[1], &num[2], &num[3]) != 4)
        return false;
  
    for (i = 0; i < 4; ++i)
    {
        if (num[i] > 255)
            return false;
    }
  
    return true;
}
