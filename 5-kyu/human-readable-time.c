#include <stdio.h>

char *human_readable_time (unsigned seconds, char *time_string)
{
  int hours, minutes;
  
  hours = seconds / 3600;
  minutes = (seconds - (3600 * hours)) / 60;
  seconds = (seconds - (3600 * hours) - (minutes * 60));
  
  sprintf(time_string, "%02d:%02d:%02d", hours, minutes, seconds);
  
	return time_string;
}