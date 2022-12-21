#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *camel_case(const char *s)
{
    char *cap_s = NULL;
    int i, j, len;
  
    if (*s == '\0') {
        cap_s = (char*) malloc(2 * sizeof(char*));
        cap_s[1] = '\0';
        cap_s[0] = *s;
      
        return cap_s;
    }
  
    len = strlen(s);
    cap_s = (char*) malloc(len * sizeof(char*));
  
    for (i = 0, j = 0; i < len; ++i)
    {
        if ((i == 0 && isalpha(s[i])) || (isalpha(s[i]) && isblank(s[i - 1])))
              cap_s[j++] = toupper(s[i]);
        else if (!isblank(s[i]))
              cap_s[j++] = s[i];
    }
  
    cap_s[j] = '\0';
  
    return cap_s;
}