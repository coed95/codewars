char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
    int num, i;
  
    for (num = 0, i = 0; num < 10; ++num)
    {
        if (num == 0) {
          phnum[i++] = '(';
          phnum[i++] = nums[num] + '0';
        }
        else if (num == 3) {
          phnum[i++] = ')';
          phnum[i++] = ' ';
          phnum[i++] = nums[num] + '0';
        }
        else if (num == 6) {
          phnum[i++] = '-';
          phnum[i++] = nums[num] + '0';
        }
        else {
          phnum[i++] = nums[num] + '0';
        }
    }
  
    phnum[i] = '\0';
  
    return phnum;
}
