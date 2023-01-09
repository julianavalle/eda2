#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int meio, int r)
{
    int *v2 = malloc((r - l + 1) * sizeof(int));

    int k = 0;
    int i = l;
    int j = meio + 1;

    while (i <= meio && j <= r)
    {
        if (v[i] <= v[j])
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++];
    }

    while (i <= meio)
        v2[k++] = v[i++];
    while (j <= r)
        v2[k++] = v[j++];

    k = 0;
    for (i = l; i <= r; i++)
        v[i] = v2[k++];
    free(v2);
}

void mergesort(int *v, int l, int r)
{
    if (l >= r)
        return;
    int meio = (r + l) / 2;
    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int main()
{
    int *v = malloc(sizeof(int));
    int size = 0, n = 0;

    for (int j = 8; j >= 1; j--)
    {
        scanf("%d", &n);

        if (n != 0)
        {
            v = realloc(v, sizeof(int) * (size + n));

            for (int i = 0; i < n; i++)
            {
                scanf("%d", &v[size + i]);
            }
        }

        size += n;
    }

    mergesort(v, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");

    return 0;
}