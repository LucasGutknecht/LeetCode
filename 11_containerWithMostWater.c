#include <stdio.h>
#include <stdlib.h>

// fonte da solucao: https://www.geeksforgeeks.org/dsa/two-pointers-technique/

int maxArea(int *height, int heightSize)
{
  if (heightSize < 2) return 0;

  long long max = 0;
  int left = 0;
  int right = heightSize - 1;

  while (left < right)
  {
    int h = height[left] < height[right] ? height[left] : height[right];
    long long area = (long long)h * (right - left);
    if (area > max) max = area;

    if (height[left] < height[right])
      left++;
    else
      right--;
  }

  return (int)max;
}
