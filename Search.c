#include <stdio.h>

int min(int a, int b){
    if (a>b) return b;
    else return a;
}

int linear_search(int arr[], int size, int target){
    for(int i =0; i<size; i++){
        if(arr[i] == target)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int low, int high, int target){
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if (arr[mid] == target) 
            return mid;
        
        if(arr[mid] < target){
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return -1;
}

int exponential_search(int arr[], int n, int target ){
    if (arr[0] == target ) return 0;
    
    int i=1;
    while(arr[i] < target){
        i *= 2;
    }
    return binary_search(arr, i/2, min(i, n), target);
}


// Driver code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40,189,491,5261};
    int target = 189;
    int size = sizeof(arr)/sizeof(arr[0]);
    //int result = linear_search(arr, size, target);
    //int result = binary_search(arr, 0, size-1, target);
    int result = exponential_search(arr, size, target);
    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
    return 0;
}
