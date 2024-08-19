#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left +1;
    int n2 = right -mid;
    int L[n1], R[n2];
    for(int i =0;i<n1; i++){ L[i] = arr[left+i]; }
    for(int j =0;j<n2; j++){ R[j] = arr[mid+j+1]; }
    i=0;j=0;k=left;
    
    while(i<n1 && j<n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    
}

void mergeSort(int arr[], int left, int right){
    if(left<right){
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j =low;j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}
    
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 5, 6,49,84,7,1,91,97,1,19,51,9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    //insertionSort(arr, n);
    //bubbleSort(arr, n);
    //mergeSort(arr, 0, n-1);
    quickSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}

