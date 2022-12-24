#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_ISBN_10 (const char *ISBN)
{
  int i, ISBN_len;
  int result;
  
  ISBN_len = strlen(ISBN);
  
  if (ISBN_len != 10)
    return false;
  
  for (i = 0, result = 0; i < ISBN_len; i++)
  {
    if (i != ISBN_len - 1 && !isdigit(ISBN[i]))
      return false;
    else if (i == ISBN_len - 1 && !isdigit(ISBN[i]) && ISBN[i] != 'X')
      return false;
    else
      result += (ISBN[i] == 'X') ? (10 * (i + 1)) : (ISBN[i] - '0') * (i + 1);
  }
  
  return ((result % 11) == 0) ? true : false;
}