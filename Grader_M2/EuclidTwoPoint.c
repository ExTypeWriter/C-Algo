#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 20000
#define INF 1e9

typedef struct
{
    double x, y;
} Point;

int compareX(const void *a, const void *b)
{
    return ((Point *)a)->x - ((Point *)b)->x;
}

int compareY(const void *a, const void *b)
{
    return ((Point *)a)->y - ((Point *)b)->y;
}

double min(double a, double b)
{
    return (a < b) ? a : b;
}

double distance(Point a, Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void merge(Point arr[], int l, int m, int r, int (*compare)(const void *, const void *))
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Point L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (compare(&L[i], &R[j]) <= 0)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Point arr[], int l, int r, int (*compare)(const void *, const void *))
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, compare);
        mergeSort(arr, m + 1, r, compare);

        merge(arr, l, m, r, compare);
    }
}

double closestPair(Point points[], int left, int right)
{
    if (left >= right)
    {
        return INF;
    }

    int mid = (left + right) / 2;
    double xMid = points[mid].x;
    double dl = closestPair(points, left, mid);
    double dr = closestPair(points, mid + 1, right);
    double d = min(dl, dr);

    Point strip[MAX_POINTS];
    int j = 0;
    for (int i = left; i <= right; i++)
    {
        if (fabs(points[i].x - xMid) < d)
        {
            strip[j++] = points[i];
        }
    }

    mergeSort(strip, 0, j - 1, compareY);

    for (int i = 0; i < j; i++)
    {
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; k++)
        {
            d = min(d, distance(strip[i], strip[k]));
        }
    }

    return d;
}

int main()
{
    int n;
    scanf("%d", &n);

    Point points[MAX_POINTS];
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    mergeSort(points, 0, n - 1, compareX);
    double result = closestPair(points, 0, n - 1);
    printf("%.4lf\n", floor(result * 10000) / 10000);

    return 0;
}