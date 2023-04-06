long zeros(long n) {
  int count, i;
  
  for (count = 0, i = 5; n / i >= 1; i *= 5) {
    count += n / i;
  }
  return (long) count;
}