#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_LEN 3
#define MIN_CLOSEST 0
#define MAX_CLOSEST 255

int rgb(int r, int g, int b, char *output)
{
    char hex_rep[HEX_LEN];
    int i, rgb[] = {r, g, b};
  
    output[0] = '\0';
  
    for (i = 0; i < 3; ++i)
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