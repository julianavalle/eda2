void intercala(int x[], int m, int y[], int n, int z[])
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (x[i] < y[j])
        {
            z[k] = x[i];
            i++;
        }
        else
        {
            z[k] = y[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de x[], se houver
    while (i < m)
    {
        z[k] = x[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de y[], se houver
    while (j < n)
    {
        z[k] = y[j];
        j++;
        k++;
    }
}
