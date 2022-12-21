#include <stddef.h>

int find_odd (size_t length, const int array[length])
{
    size_t i, j;
    size_t count;
  
    for (i = 0; i < length; ++i)
    {
        count = 0;
      
        for (j = 0; j < length; ++j)
        {
            if (array[i] == array[j])
                ++count;
        }
      
        if ((count % 2) != 0)
            return array[i];           
    }
  
    return 0;
}

/* 
   here a version with bit manipulation
  (thanks to the user andriyrom!)

int find_odd2 (size_t length, const int array[length])
{
  int odd_int = 0;

  for (size_t i = 0; i < length; i++)
    odd_int ^= array[i];

  return odd_int;
}
*/