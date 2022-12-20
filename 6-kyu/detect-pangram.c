#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHA_LENGTH 26
#define TO_LOWER 32

bool is_pangram(const char *str_in) {
    const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char str[64];
    int alpha_count[ALPHA_LENGTH];
    int i, j, len;
  
    len = strlen(str_in);
    strcpy(str, str_in);
  
    for (i = 0; i < ALPHA_LENGTH; ++i)
      alpha_count[i] = 0;
  
    for (i = 0; i < len; ++i)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] += TO_LOWER;
        
      for (j = 0; j < ALPHA_LENGTH; ++j)
      {
        if (str[i] == alpha[j])
          ++alpha_count[str[i] - 'a'];   
      }
    }
  
    for (i = 0; i < ALPHA_LENGTH; ++i)
    {
      if (alpha_count[i] < 1)
        return false;
    }
  
    return true;
}