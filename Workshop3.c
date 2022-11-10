#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Merge(int L[], int start, int mid, int end);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

int main()
{
    int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 };
    int L_size = sizeof(L) / sizeof(L[0]);

    printf("Given list \n");
    printList(L, L_size);

    MergeSort(L, 0, L_size - 1);

    printf("The sorted list \n");
    printList(L, L_size);
    return 0;
}

void Merge(int L[], int start, int mid, int end)
{
    int length_L1 = mid - start + 1;
    int length_L2 = end - mid;
    int L1[length_L1];
    int L2[length_L2];
    for (int i = 0; i < length_L1 ; ++i)
    {
        L1[i] = L[start + i];
    }
    for (int j = 0; j < length_L2 ; ++j)
    {
        L2[j] = L[mid + 1 + j];
    }

    int i = 0;
    int j = 0;

    while ((i < (length_L1)) && (j < (length_L2)))
    {
        if(L1[i]<= L2[j]){
            L[start+i+j]=L1[i];
            i++;
        } else{
            L[start+i+j] = L2[j];
            j++;
        }
    }
    if(i == length_L1){
        for (int k = j; k <= (end-mid-1); ++k) {
            L[start+i+k]=L2[k];
        }
    }
    else
        for (int k = i; k <= (mid-start); ++k) {
            L[start+j+k]=L1[k];
        }
}

void MergeSort(int L[], int start, int end)
{
    if (start < end)
    {
        int m = floor(start + (end - start)/2);
        MergeSort(L,start,m);
        MergeSort(L,m+1,end);
        Merge(L,start,m,end);
    }
}

void printList(int L[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", L[i]);
    }
    printf("\n");
}