void intercalaRecursiva(int x[], int m, int y[], int n, int z[], int k)
{
    if (m == 0 && n == 0)
        return; // base case

    if (m == 0)
    {
        z[k] = y[0];
        intercalaRecursiva(x, m, y + 1, n - 1, z, k + 1);
    }
    else if (n == 0)
    {
        z[k] = x[0];
        intercalaRecursiva(x + 1, m - 1, y, n, z, k + 1);
    }
    else
    {
        if (x[0] < y[0])
        {
            z[k] = x[0];
            intercalaRecursiva(x + 1, m - 1, y, n, z, k + 1);
        }
        else
        {
            z[k] = y[0];
            intercalaRecursiva(x, m, y + 1, n - 1, z, k + 1);
        }
    }
}
