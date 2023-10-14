#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} POINT_T;

float min(float a, float b) {
    return a < b ? a : b;
}

int comparePointsX(const void *a, const void *b) {
    POINT_T *point1 = (POINT_T *)a;
    POINT_T *point2 = (POINT_T *)b;

    if (point1->x < point2->x) {
        return -1;
    } else if (point1->x > point2->x) {
        return 1;
    } else {
        return 0;
    }
}

int comparePointsY(const void *a, const void *b) {
    POINT_T *point1 = (POINT_T *)a;
    POINT_T *point2 = (POINT_T *)b;

    if (point1->y < point2->y) {
        return -1;
    } else if (point1->y > point2->y) {
        return 1;
    } else {
        return 0;
    }
}

float EuclidDistance(POINT_T point1, POINT_T point2) {
    float result = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
    return result;
}

float stripClosest(POINT_T strip[], int size, float minDistance) {
    float min = minDistance;
    qsort(strip, size, sizeof(POINT_T), comparePointsY);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; j++) {
            float distance = EuclidDistance(strip[i], strip[j]);
            if (distance < min) {
                min = distance;
            }
        }
    }

    return min;
}

float closestPair(POINT_T arr[], int size) {
    qsort(arr, size, sizeof(POINT_T), comparePointsX);
    if (size <= 3) { // Guard clause to use bruteforce for small data.
        float min = FLT_MAX;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                float distance = EuclidDistance(arr[i], arr[j]);
                if (distance < min) {
                    min = distance;
                }
            }
        }
        return min;
    }

    int middle = size / 2;
    POINT_T middlePoint = arr[middle];
    POINT_T leftHalf[middle];
    POINT_T rightHalf[size - middle];
    for (int i = 0; i < middle; i++) {
        leftHalf[i] = arr[i];
    }
    for (int i = middle; i < size; i++) {
        rightHalf[i - middle] = arr[i];
    }

    float leftClosest = closestPair(leftHalf, middle);
    float rightClosest = closestPair(rightHalf, size - middle);
    float minDistance = min(leftClosest, rightClosest);

    POINT_T strip[size];
    int stripSize = 0;

    for (int i = 0; i < size; i++) {
        if (fabs(arr[i].x - middlePoint.x) < minDistance) {
            strip[stripSize] = arr[i];
            stripSize++;
        }
    }
    float stripClosestDistance = stripClosest(strip, stripSize, minDistance);

    return min(minDistance, stripClosestDistance);
}

int main() {
    int n;
    scanf("%d", &n);
    POINT_T arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &arr[i].x, &arr[i].y);
    }
    float minDistance = closestPair(arr, n);
    printf("%.4f\n", minDistance);
    return 0;
}
