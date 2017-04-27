#include <stdio.h>
#include <iostream>

int arr[20];
int buf[20];

void msort(int* arr, int start, int end) {
    if (end <= start) return;
    int mid = (start+end)/2;
    msort(arr, start, mid);
    msort(arr, mid+1, end);

    int idx = start;
    int lidx = start;
    int ridx = mid+1;
    while(lidx <= mid && ridx <=end) {
        if (arr[lidx] < arr[ridx]) buf[idx++] = arr[lidx++];
        else buf[idx++] = arr[ridx++];
    }
    while(lidx <= mid) buf[idx++] = arr[lidx++];
    while(ridx <= end) buf[idx++] = arr[ridx++];
    for (int i=start; i<=end; ++i) arr[i] = buf[i];
}

int main()
{
    freopen("input.txt","r", stdin);

    for (int i=0; i<10; ++i) scanf("%d",arr+i);

    msort(arr, 0, 9);
    for (int i=0; i<10; ++i) printf("%d ",arr[i]);

    return 0;
}
