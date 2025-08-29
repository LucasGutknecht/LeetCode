#include <stdio.h>
#include <stdlib.h>

int compareInt(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int *mergeArrays(int arr1[], int n1, int arr2[], int n2)
{

  // Allocating array for storing result
  int *res = (int *)malloc((n1 + n2) * sizeof(int));

  // Copy elements of the first array to the result array
  for (int i = 0; i < n1; i++)
    res[i] = arr1[i];

  // Copy elements of the second array to the result array
  for (int i = 0; i < n2; i++)
    res[n1 + i] = arr2[i];

  return res;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
  int *arrayMerged = mergeArrays(nums1, nums1Size, nums2, nums2Size);
  int totalSize = nums1Size + nums2Size;
  int sizeEven = (totalSize % 2 == 0) ? 1 : 0;

  qsort(arrayMerged, totalSize, sizeof(int), compareInt);

  double result;

  if (!sizeEven)
  {
    int middle_index = totalSize / 2;
    result = arrayMerged[middle_index];
  }
  else
  {
    int middle_index1 = totalSize / 2 - 1;
    int middle_index2 = totalSize / 2;

    int middle_value1 = arrayMerged[middle_index1];
    int middle_value2 = arrayMerged[middle_index2];

    result = (middle_value1 + middle_value2) / 2.0;
  }

  free(arrayMerged);
  return result;
}
