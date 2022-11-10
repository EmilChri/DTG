#include <stdio.h>     //https://www.mygreatlearning.com/blog/merge-sort/

void merge(int arr[], int start, int mid, int end);    //proto
void mergeSort(int arr[], int start, int end);         //proto
void display(int arr[], int size);                     //proto

int main() {
    int arr[] = {5, 3, 8, 1, 6, 10,7,2,4,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array\n");display(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array\n");display(arr, size);
}

void merge(int arr[], int start, int mid, int end) {

    int len1 = mid - start + 1;
    int len2 = end - mid;
    int leftArr[len1], rightArr[len2];

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < len2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {

        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}