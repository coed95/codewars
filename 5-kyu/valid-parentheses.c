#include <stdbool.h>

bool validParentheses(const char *str_in) {
    int index, rounds = 0;
  
    for (index = 0; str_in[index] != '\0'; ++index)
    {
        if (rounds < 0)
            return false;
      
        if (str_in[index] == '(')
            ++rounds;
      
        if (str_in[index] == ')')
            --rounds;
    }
  
    if (rounds != 0)
        return false;
    else
        return true;
}