int find_min_pos(int *tills, int n)
{
    int i, min;
  
    min = 0;
  
    for (i = 1; i < n; ++i)
    {
        if (tills[i] < tills[min])
            min = i;
    }
  
    return min;
}

int max_value(int *tills, int n)
{
    int i;
    int max;

    max = tills[0];
  
    for (i = 1; i < n; ++i)
    {
        if (max < tills[i])
            max = tills[i];
    }
  
    return max;
}

int queue_time(const int *customers, int customers_length, int n)
{
    int i, pos;
    int tills[n];
  
    for (i = 0; i < n; ++i)
        tills[i] = 0;
  
    for (i = 0; i < customers_length; ++i)
    {
        pos = find_min_pos(tills, n);
        tills[pos] += customers[i];
    }
  
    return max_value(tills, n);
}
