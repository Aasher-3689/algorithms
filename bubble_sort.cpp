// The Bubble Sort.

#include <iostream>
using namespace std;

void sort_ascending(int array[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (array[j] > array[j+1])
      {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}

int main()
{
    int array[16] = {7, 3, 15, 1, 12, 20, 5, 18, 2, 22, 10, 8, 19, 6, 13, 16};
    sort_ascending(array, 16);
    
    cout << "[";
    for (int x : array) cout << x << ", ";
    cout << "]" << endl;
    return 0;
}

// What's going on:
/*
    ) Bubble sort compares two adjacent elements (pairs) and swaps them if they
      are in the wrong order (bigger number on the left).
    ) After the first full pass, the largest element is pushed to the last
      position (index 15). So in the next pass, we do not need to touch that
      last element again.

    # Outer loop explanation:
    #
    # We run the outer loop (size - 1) times because:
    #
    #   - In each pass, one largest element moves to its correct position
    #     at the end of the array.
    #
    #   - After the first pass, the largest element is fixed at index size-1.
    #   - After the second pass, the next largest is fixed at index size-2.
    #   - After the third pass, the next one is fixed at index size-3.
    #
    #   - This continues until only one element remains unsorted — and the last
    #     remaining element must already be correct, so no need for an last pass.
    #
    # Therefore, only (size - 1) passes are required.
    #

    # Inner loop explanation:
    #
    # For first pass:  (size - 1 - 0 (i))
    #     > compare all pairs
    #
    # For second pass: (size - 1 - 1 (i))
    #     > compare all pairs except the last one,
    #       because the last element is already sorted
    #
    # For third pass:  (size - 1 - 2 (i))
    #     > compare all pairs except the last two,
    #       because the last two elements are already in correct position
    #
    # In general:
    #     * i prevents checking the already sorted portion at the end
    #     * -1 prevents comparing the last element with a next element
    #       (which does not exist)
    #
*/

// Time Complexity
/*
    1) size >>>>> O(1)
    2) i = 0 (initialization) >>>>> O(1)
    3) j = 0 (initialization) >>>>> O(1)

    # Work inside inner loop:
        array[j] > array[j+1]   >>> O(1)
        temp = array[j]         >>> O(1)
        array[j] = array[j+1]   >>> O(1)
        array[j+1] = temp       >>> O(1)

        >> One comparison + swap takes O(1)

    # Inner loop counts (worst case):
        First pass:  size - 1 - 0  = size - 1
        Second pass: size - 1 - 1  = size - 2
        Third pass:  size - 1 - 2  = size - 3
        ...
        Last pass:   size - 1 - (size - 2) = 1

    # Total comparisons (worst case):
        (size - 1) + (size - 2) + ... + 1

        This is the famous sum:
            n(n - 1) / 2

        Which grows approximately like:
            n² / 2  >>> O(n²)

        So all nested loops together = >>> O(n²)

    # Return statement is O(1)

    RESULT:
        Dominant term = O(n²)
        Therefore Time Complexity = O(n²)
*/