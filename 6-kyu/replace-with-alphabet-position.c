#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text) {
    char *converted_text;
    int i, length;
    int digit;
    char s_digit[4];
  
    length = strlen(text);
    converted_text = (char*) malloc(length * sizeof(char*));
    converted_text[0] = '\0';
  
    for (i = 0; i < length; ++i)
    {
      if (tolower(text[i]) >= 'a' && tolower(text[i]) <= 'z')
      {
          digit = (tolower(text[i]) - 'a') + 1;
          sprintf(s_digit, "%d", digit);
        
          strcat(converted_text, s_digit);
          strcat(converted_text, " ");
      }
    }
  
    length = strlen(converted_text);
    converted_text[length - 1] = '\0';
  
    return converted_text;
}
