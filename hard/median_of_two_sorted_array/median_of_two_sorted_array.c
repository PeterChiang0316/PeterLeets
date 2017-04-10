#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main(int argc ,char *argv[]){


    int a[4] = {1,3,5,7};
    int b[5] = {2,4,6,8.10};
    int c = findMedianSortedArrays(a,4,b,5);

    printf("c:%d\b",c);
    

    return 0;
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
   int median_index = (nums1Size + nums2Size) >> 1 ;
   int i = nums1Size , j = nums2Size; //index for array 1 and array 2
   int k = 0;
   if 
}

