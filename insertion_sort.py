# The Insertion Sort.

def sort_ascending(array):
    n = len(array)
    for i in range(1, n):
        curr = i
        for j in range(i):
            if array[j] > array[curr]:
                temp = array[j]
                array[j] = array[curr]
                array[curr] = temp
    return array
    

array = [7, 3, 15, 1, 12, 20, 5, 18, 2, 22, 10, 8, 19, 6, 13, 16]
print(sort_ascending(array))

# What's going on:
"""
    1) We start from 2nd element of array and compare it with all the elements
      to its left.
    ) first 2nd element is compared with 1st element.
    ) then 3rd element is compared with 1st and 2nd element.
    ) then 4th elemnt is compared with 1st, 2nd, and 3rd element.
    ) ...
    ) then nth element is compared with all elements upto n-1th element.

    2) In each comparison, we compare if any leftside element is greater than
       the current element, swap them.

    3) UNDERSTANDING CODE:
       - starting from second element to nth means from 1st to n-1th index.
       - taking one element index at a time curr=i to compare it with all its
         leftside elements.
       - for  i=1, there is only one index at left i.e, 0
       - for  i=2, there are two indexes at left i.e, 0,1
       - is not its means, we want to move inner loop upto (i-1)th time? exactly.
       - that's, what we did.
       - inside it we, write our main comparison, easily understandable.
"""

# Time complexity:
"""
    O(n²)
"""
