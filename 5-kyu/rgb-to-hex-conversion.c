#include <stdio.h>
#include <string.h>

#define RGB_LEN 3
#define MIN_CLOSEST 0
#define MAX_CLOSEST 255

int rgb(int r, int g, int b, char *output)
{
    char hex_rep[RGB_LEN];
    int i, rgb[] = {r, g, b};
  
    output[0] = '\0';
  
    for (i = 0; i < RGB_LEN; ++i)
    {
        if (rgb[i] < MIN_CLOSEST)
          sprintf(hex_rep, "%02X", 0);
        else if (rgb[i] > MAX_CLOSEST)
          sprintf(hex_rep, "%02X", 255);
        else
          sprintf(hex_rep, "%02X", rgb[i]);
      
        strcat(output, hex_rep);
    }
  
    return 0;
}