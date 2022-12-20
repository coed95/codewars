#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

unsigned long long square_digits (unsigned n)
{
  char n_str[MAX];
  char c_str[MAX];
  char s_result[MAX];
  unsigned long long converted, result;
  int i, len;
  
  sprintf(n_str, "%u", n);
  
  len = strlen(n_str);
  s_result[0] = '\0';
  
  for (i = 0; i < len; ++i)
  {
    converted = n_str[i] - '0';
    converted = converted * converted;
    
    sprintf(c_str, "%llu", converted);
    strcat(s_result, c_str);
  }
  
  result = strtoull(s_result, NULL, 10);
  
    return result;
}