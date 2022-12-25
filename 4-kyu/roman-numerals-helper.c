#include <string.h>

int from_roman(char* roman)
{
  unsigned i, result;

  result = 0;
  
  for (i = 0; roman[i] != '\0'; ++i)
  {
    switch (roman[i])
    {
      case 'I':
        if (roman[i + 1] == 'V') {
          result += 4;
            i++;
        }
        else if (roman[i + 1] == 'X') {
          result += 9;
          i++;
        }
        else {
          result += 1;
        }
        break;
            
      case 'X':
        if (roman[i + 1] == 'L') {
          result += 40;
          i++;
        }
        else if (roman[i + 1] == 'C') {
          result += 90;
          i++;
        }
        else {
          result += 10;
        }
        break;
            
      case 'C':
        if (roman[i + 1] == 'D') {
          result += 400;
          i++;
        }
        else if (roman[i + 1] == 'M') {
          result += 900;
          i++;
        }
        else {
          result += 100;
        }
        break;
            
      case 'V':
        result += 5;
        break;
            
      case 'L':
        result += 50;
        break;
            
      case 'D':
        result += 500;
        break;
            
      case 'M':
        result += 1000;
        break;
      }
    }
  
    return result;
}

void to_roman(int number, char* destination)
{
    int i, numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *letters[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  
    while (number != 0)
    {
        for (i = 0; i < 13; i++) {
            if (number >= numbers[i]) {
                strcat(destination, letters[i]);
                number -= numbers[i];
              
                break;
            }
        }
    }
}