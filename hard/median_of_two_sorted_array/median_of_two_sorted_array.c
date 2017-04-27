#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int binary_search(int value, int* arr, int left,int right);


int main(int argc ,char *argv[]){


    int a[4] = {1,3,5,7};
    int b[5] = {2,4,6,8,10};
    int c = findMedianSortedArrays(a,4,b,5);

    printf("c:%d\b",c);
    

    return 0;
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
   int median_index = (nums1Size + nums2Size) >> 1 ;
   int left_1 = 0 , left_2 = 0,right_1 = nums1Size , right_2 = nums2Size; //index for array 1 and array 2
   int before_mid = INT_MAX;
   int pivot, mid; 
   int result_left, result_right;

   // always start from array 1 
   while( before_mid != median_index )
   {
        mid = (left_1 + right_1) >> 1;
        pivot = nums1[mid];
        result_right = binary_search(pivot,nums2,left_2,right_2);
        before_mid
   }
}



int binary_search(int value, int* arr, int left,int right)
{
    int mid;

    while (left < right)
    {
        mid = (left + right) >> 1;
        if (arr[mid] < value) left = mid;
        else if (arr[mid] > value)right = mid;
        else return mid;
    }

    return mid;
}

