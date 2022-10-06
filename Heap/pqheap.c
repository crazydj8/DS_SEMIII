#include <stdio.h>
#include <stdlib.h>

void shift_up(int h[], int n)
{
    int i = n, j = i / 2, temp;
    while (i > 1 && h[i] >= h[j])
    {
        temp = h[j];
        h[j] = h[i];
        h[i] = temp;
        i = j;
        j = i / 2;
    }
}

void insert(int h[], int *n)
{
    int x;
    printf("Enter the priority:");
    scanf("%d", &x);
    *n = *n + 1;
    h[*n] = x;
    shift_up(h, *n);
}

void shift_down(int h[], int n)
{
    int k = 1, v = h[k], heap = 0, j;
    while (!heap && 2 * k <= n)
    {
        j = 2 * k;
        if (j < n)
        {
            if (h[j + 1] > h[j])
            {
                j++;
            }
        }
        if (v >= h[j])
        {
            heap = 1;
        }
        else
        {
            h[k] = h[j];
            k = j;
        }
    }
    h[k] = v;
}

void pqdelete(int h[], int *n)
{
    if (*n == 0)
    {
        printf("Empty\n");
        return;
    }
    printf("deleted element with priority = %d\n", h[1]);
    h[1] = h[*n];
    *n = *n - 1;
    shift_down(h, *n);
}

void display(int h[], int n)
{
    if (n == 0)
    {
        printf("Empty\n");
        return;
    }
    printf("P.Queue = \n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", h[i]);
    }
}

int main()
{
    int h1[20], ch, n = 0;
    do
    {
        printf("Options: 1.Insert 2.Delete 3.Display\nEnter:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(h1, &n);
            break;
        case 2:
            pqdelete(h1, &n);
            break;
        case 3:
            display(h1, n);
            break;
        }
    } while (ch != 4);
    return 0;
}
