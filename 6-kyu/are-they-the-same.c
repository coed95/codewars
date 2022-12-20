#include <stdbool.h>
#include <stdlib.h>

#define square(x) (x * x)

int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

bool comp(const int *a, const int *b, size_t n)
{
    size_t i;
    int sa[n], sb[n];
  
    for (i = 0; i < n; ++i)
    {
        sa[i] = a[i];
        sb[i] = b[i];
    }
  
    qsort(sa, n, sizeof(int), cmp);
    qsort(sb, n, sizeof(int), cmp);
  
    for (i = 0; i < n; ++i)
    {
        if (square(sa[i]) != sb[i])
            return false;
    }
  
    return true;
}