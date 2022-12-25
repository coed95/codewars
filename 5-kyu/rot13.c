#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>

char *rot13(const char *src)
{
    int i;
    char *dest = NULL;
  
    for (i = 0; src[i] != '\0'; i++)
    {
        dest = realloc(dest, i + 1);
      
        if (!isalpha(src[i]))
            dest[i] = src[i];
        else if ((src[i] >= 'a' && src[i] <= 'm') || (src[i] >= 'A' && src[i] <= 'M'))
            dest[i] = src[i] + 13;
        else
            dest[i] = src[i] - 13;
    }
    dest[i] = '\0';
  
    return dest;
}