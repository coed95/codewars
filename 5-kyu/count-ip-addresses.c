#include <stdio.h>
#include <inttypes.h>

uint32_t ips_between (const char *start, const char *end)
{
  unsigned short num1[4], num2[4];
  uint32_t a, b;
  
  sscanf(start, "%hu.%hu.%hu.%hu", &num1[0], &num1[1], &num1[2], &num1[3]);
  sscanf(end, "%hu.%hu.%hu.%hu", &num2[0], &num2[1], &num2[2], &num2[3]);
  
  a = (num1[0] * 256 * 256 * 256) + (num1[1] * 256 * 256) + (num1[2] * 256) + num1[3];
  b = (num2[0] * 256 * 256 * 256) + (num2[1] * 256 * 256) + (num2[2] * 256) + num2[3];
  
  return b - a;
}
