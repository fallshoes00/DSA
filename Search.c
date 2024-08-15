#include <stdio.h>
#include <stdlib.h>

// Linear Search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1; // Not found
}

// Binary Search
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // x剛好在中間，直接return
        if (arr[mid] == x)
            return mid;
        // x大，忽略左邊；x小，忽略右邊
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Not found
}

// Exponential Search
int exponentialSearch(int arr[], int n, int x) {
    // 依序從第1、2、4、8、16、32...去確認目標大略位置
    // 找到之後再啟動Binary Search去找到確切位置
    // 目標直接在第 0個
    if (arr[0] == x)
        return 0;

    // 找大略位置
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    // 找確切位置，fmin取兩者較小的數值，確保search不會超出array range
    return binarySearch(arr, i / 2, fmin(i, n - 1), x);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    // Test Linear Search
    int result = linearSearch(arr, n, x);
    if (result == -1)
        printf("目標沒有在array裡面(Linear Search)\n");
    else
        printf("目標在第%d個位置(Linear Search)\n", result);

    // Test Binary Search
    result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("目標沒有在array裡面(Binary Search)\n");
    else
        printf("目標在第%d個位置(Binary Search)\n", result);

    // Test Exponential Search
    result = exponentialSearch(arr, n, x);
    if (result == -1)
        printf("目標沒有在array裡面(Exponential Search)\n");
    else
        printf("目標在第%d個位置(Exponential Search)\n", result);

    return 0;
}
