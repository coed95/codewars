#include <stddef.h>

int sum_array(const int *values, size_t count)
{
    int i, total = 0;
  
    if (count < 1)
        return 0;
  
    for (i = 0; i < (int) count; i++)
      total += values[i];
  
    return total;
}