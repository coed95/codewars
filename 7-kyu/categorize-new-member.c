#include <stddef.h>

#define SENIOR_AGE 55
#define HANDICAP 7

enum membership {OPEN = 1, SENIOR = 2};

void open_or_senior (size_t n, const int members[n][2], enum membership memberships[n])
{
// write to the memberships[] array  
	memberships[0] = SENIOR;
  size_t index;
  
  for (index = 0; index < n; ++index)
  {
    if (members[index][0] >= SENIOR_AGE && members[index][1] > HANDICAP)
      memberships[index] = SENIOR;
    else
      memberships[index] = OPEN;
  }
}