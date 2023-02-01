#include <stdio.h>
#include <stdlib.h>
 
 
/* holds the address of the array of which the sorted index
 * order needs to be found
 */
int *base_arr;
 
/* Note how the compare function compares the values of the
 * array to be sorted. The passed value to this function
 * by `qsort' are actually the `idx' array elements.
 */
static int
compar (const void *a, const void *b)
{
  int aa = *((int *) a), bb = *((int *) b);
  if (base_arr[aa] < base_arr[bb])
    return -1;
  if (base_arr[aa] == base_arr[bb])
    return 0;
  if (base_arr[aa] > base_arr[bb])
    return 1;
}
 
int
main (void)
{
  int *arr, *idx, n, i;
 
  printf ("\nEnter n: ");
  scanf ("%d", &n);
 
  arr = malloc (sizeof (int) * n);
  idx = malloc (sizeof (int) * n);
  printf ("\nEnter the list: ");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &arr[i]);
    }
 
  /* initialize initial index permutation of unmodified `arr'
   */
  for (i = 0; i < n; i++)
    {
      idx[i] = i;
    }
 
  /* Assign the address of out original array to the static global
   * pointer, this will be used by the compare function to index 
   * into the original array using `idx' values
   */
  base_arr = arr;
 
  qsort (idx, n, sizeof (int), compar);
 
  printf ("\nOriginal list: ");
  for (i = 0; i < n; i++)
    {
      printf ("%d ", arr[i]);
    }
 
  printf ("\nSorted index: ");
  for (i = 0; i < n; i++)
    {
      printf ("%d ", idx[i]);
    }
 
  printf ("\nSorted array using arr[sorted_idx[i]]: ");
  for (i = 0; i < n; i++)
    {
      printf ("%d ", arr[idx[i]]);
    }
 
 
  free (arr);
  free (idx);
 
  printf ("\n");
  return 0;
}