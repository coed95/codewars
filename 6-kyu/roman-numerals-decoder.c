#define   I   1
#define   V   5
#define   X   10
#define   L   50
#define   C   100
#define   D   500
#define   M   1000

unsigned decode_roman (const char *roman_number)
{
    unsigned i, result;

    result = 0;
  
    for (i = 0; roman_number[i] != '\0'; ++i)
    {
        switch (roman_number[i])
        {
            case 'I':
                if (roman_number[i + 1] == 'V') {
                    result += V - I;
                    i++;
                }
                else if (roman_number[i + 1] == 'X') {
                    result += X - I;
                    i++;
                }
                else {
                    result += I;
                }
                break;
            
              case 'X':
                  if (roman_number[i + 1] == 'L') {
                      result += L - X;
                      i++;
                  }
                  else if (roman_number[i + 1] == 'C') {
                      result += C - X;
                      i++;
                  }
                  else {
                      result += X;
                  }
                  break;
            
                case 'C':
                  if (roman_number[i + 1] == 'D') {
                      result += D - C;
                      i++;
                  }
                  else if (roman_number[i + 1] == 'M') {
                      result += M - C;
                      i++;
                  }
                  else {
                      result += C;
                  }
                  break;
            
                  case 'V':
                      result += V;
                      break;
            
                  case 'L':
                      result += L;
                      break;
            
                  case 'D':
                      result += D;
                      break;
            
                  case 'M':
                      result += M;
                      break;
        }
    }
  
    return result;
}