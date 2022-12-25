/* no sscanf version */

#include <stdlib.h>

typedef struct {
    int r, g, b;
} rgb;

rgb hex_str_to_rgb(const char *hex_str) {
    char hex[3];
    int rgb_a[3];
    int i, j;
    rgb color;
  
    for (i = 0, j = 1; hex_str[j] != '\0'; i++, j += 2) {
        hex[0] = hex_str[j];
        hex[1] = hex_str[j + 1];
      
        rgb_a[i] = strtol(hex, NULL, 16);
    }
  
    color.r = rgb_a[0];
    color.g = rgb_a[1];
    color.b = rgb_a[2];
  
    return color;
}