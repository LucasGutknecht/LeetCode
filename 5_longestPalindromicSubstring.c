#include <string.h>

char* mancherAlgorithm(char *s)
{
  size_t sizeString = strlen(s);
  char *modifiedString = (char *)calloc(2 * sizeString + 2, sizeof(char));
  int index = 0;

  for (int i = 0; i < sizeString; i++)
  {
    char currentChar = s[i];
    modifiedString[index++] = '#';

    modifiedString[index++] = currentChar;
  }

  modifiedString[index] = '#';

  size_t sizeStringModified = 2 * sizeString + 1;

  int *vector;
  vector = (int *)calloc(sizeStringModified, sizeof(int));

  int left = 0;
  int right = 1;

  for (int i = 0; i <= sizeStringModified - 1; i++)
  {
    if (i > right)
    {
      vector[i] = 0;
    }
    else
    {
      int mirror = left + right - i;
      if (mirror - vector[mirror] <= left)
      {
        vector[i] = right - i;
      }
      else
      {
        vector[i] = vector[mirror];
      }
    }
    while (i - vector[i] - 1 >= 0 && i + vector[i] + 1 < sizeStringModified && modifiedString[i - vector[i] - 1] == modifiedString[i + vector[i] + 1])
    {
      vector[i]++;
    }

    if (i + vector[i] > right)
    {
      left = i - vector[i];
      right = i + vector[i];
    }
  }
  int maxLength = 0;
  int centerIndex = 0;
  for (int i = 0; i <= sizeStringModified - 1; i++)
  {
    if (vector[i] > maxLength)
    {
      maxLength = vector[i];
      centerIndex = i;
    }
  }
  int length = maxLength;
  int start = (centerIndex - maxLength) / 2;
  int end = start + length - 1;
  char *result = (char *)malloc((length + 1) * sizeof(char));
  strncpy(result, s + start, length);
  result[length] = '\0';

  free(vector);
  free(modifiedString);

  return result;
}

char* longestPalindrome(char *s)
{
  return mancherAlgorithm(s);
}
