for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
        if (x[i] == x[j])
        {
            for (k = j; k < n - 1; k++)
                x[k] = x[k + 1];
            n = n - 1;
            j = i;
        }