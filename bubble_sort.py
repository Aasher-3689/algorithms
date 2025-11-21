# The Bubble Sort.

def sort_ascending(array):
    n = len(array)
    for i in range(n-1):
        for j in range(n - i - 1):
            if array[j] > array[j+1]:
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
    return array
    

array = [7, 3, 15, 1, 12, 20, 5, 18, 2, 22, 10, 8, 19, 6, 13, 16]
print(sort_ascending(array))

# What's going on:
"""
    ) Bubble sort compares two adjacent elements (pairs) and swaps them if they
      are in the wrong order (bigger number on the left).
    ) After the first full pass, the largest element is pushed to the last
      position (index 15). So in the next pass, we do not need to touch that
      last element again.

    # Outer loop explanation:
    #
    # We run the outer loop (n - 1) times because:
    #
    #   - In each pass, one largest element moves to its correct position
    #     at the end of the array.
    #
    #   - After the first pass, the largest element is fixed at index n-1.
    #   - After the second pass, the next largest is fixed at index n-2.
    #   - After the third pass, the next one is fixed at index n-3.
    #
    #   - This continues until only one element remains unsorted — and the last
    #     remaining element must already be correct, so no need for an nth pass.
    #
    # Therefore, only (n - 1) passes are required.
    #

    # Inner loop explanation:
    #
    # For first pass:  n - 1 - 0 (i)
    #     > compare all pairs
    #
    # For second pass: n - 1 - 1 (i)
    #     > compare all pairs except the last one,
    #       because the last element is already sorted
    #
    # For third pass:  n - 1 - 2 (i)
    #     > compare all pairs except the last two,
    #       because the last two elements are already in correct position
    #
    # In general:
    #     * i prevents checking the already sorted portion at the end
    #     * -1 prevents comparing the last element with a next element
    #       (which does not exist)
    #
"""

# Time complexity:
"""
    1) n = len(array)                     >>>> O(1)
    2) i = 0 (outer loop initialization)  >>>> O(1)
    3) j = 0 (inner loop initialization)  >>>> O(1)

    Each inner-loop iteration does:
        - array[j] > array[j+1] (comparison)   >>> O(1)
        - temp = array[j]                      >>> O(1)
        - array[j] = array[j+1]                >>> O(1)
        - array[j+1] = temp                    >>> O(1)
    So one comparison+swap =                 >>> O(1)

    Now count how many times inner loop runs:

    First pass (i = 0): inner loop runs n-1 times
    Second pass (i = 1): inner loop runs n-2 times
    Third pass (i = 2): inner loop runs n-3 times
    ...
    Last pass (i = n-2): inner loop runs 1 time

    Total inner-loop work:
        (n-1) + (n-2) + (n-3) + ... + 1
        = n*(n-1)/2
        = approx                                     >>>> O(n²)

    Outer loop runs (n-1) times                      >>>> O(n)

    Return statement                                 >>>> O(1)

    Final Result:
    Dominant term = inner loop = O(n²)
    Time Complexity = O(n²)
"""
