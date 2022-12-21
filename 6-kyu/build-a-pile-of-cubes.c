#define cube(n) (n * n * n)

long long findNb(long long m)
{
    long long total;
    long long n;
  
    total = 0;
    n = 0;
  
    while (total < m) {
        ++n;
        total += cube(n);
    }
  
    return (total == m) ? n : -1;
}