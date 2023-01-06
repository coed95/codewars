#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   YEARS   0
#define   DAYS    1
#define   HOURS   2
#define   MINUTES 3
#define   SECONDS 4

char *formatDuration (int n) {
    int years, days, hours, minutes, seconds;
    int total_time[5];
    int fmt_size, unit, n_units;
    char *fmt = calloc(1, sizeof(char*));
    char *notation = NULL;
  
    if (n == 0) {
        fmt = realloc(fmt, 4);
        strcpy(fmt, "now");
      
        return fmt;
    }
  
    fmt[0] = '\0';
    fmt_size = 0;

    years = n / 31556952;
    days = n / (24 * 3600) % 365;
    hours = (n % (24 * 3600)) / 3600;
    minutes = (n % (24 * 3600 * 3600) / 60) % 60;
    seconds = n % 60;
  
    total_time[YEARS] = years;
    total_time[DAYS] = days;
    total_time[HOURS] = hours;
    total_time[MINUTES] = minutes;
    total_time[SECONDS] = seconds;

    for (unit = 0, n_units = 0; unit < 5; unit++)
    {
        if (total_time[unit] != 0)
            n_units++;
    }
  
    for (unit = 0; unit < 5; unit++) {
        if (total_time[unit] != 0) {
            fmt_size += 10;
            notation = realloc(notation, fmt_size);
          
            switch (unit) {
                case YEARS:
                    snprintf(notation, fmt_size, "%d year", total_time[YEARS]);
                    break;
                case DAYS:
                    snprintf(notation, fmt_size, "%d day", total_time[DAYS]);
                    break;
                case HOURS:
                    snprintf(notation, fmt_size, "%d hour", total_time[HOURS]);
                    break;
                case MINUTES:
                    snprintf(notation, fmt_size, "%d minute", total_time[MINUTES]);
                    break;
                case SECONDS:
                    snprintf(notation, fmt_size, "%d second", total_time[SECONDS]);
                    break;
            }
            fmt = realloc(fmt, fmt_size);
            strncat(fmt, notation, fmt_size);

            if (total_time[unit] > 1) {
                fmt_size++;
                fmt = realloc(fmt, fmt_size);
                strcat(fmt, "s");
            }

            n_units--;

            if (n_units == 0)
                break;

            if (n_units == 1) {
                fmt_size += 6;
                fmt = realloc(fmt, fmt_size);
                strcat(fmt, " and ");
            }
            else {
                fmt_size += 3;
                fmt = realloc(fmt, fmt_size);
                strcat(fmt, ", ");
            }

        }
    }
  
    return fmt;
}