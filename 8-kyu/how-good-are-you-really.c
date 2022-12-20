#include <stdbool.h>

bool better_than_average(const int class_points[], int class_size, int your_points) {
  int index;
  int score;
  
  score = 0;
  
  for (index = 0; index < class_size; ++index)
    score += class_points[index];
  
  score /= class_size;
  
  return (your_points > score);
}
