# The Binary Search Algorithm : list pass in ascending order

def find_x(x, array):
    location = 0
    i = 0
    j = len(array) - 1
    while i < j:
        mid = int((i + j) / 2)
        if x > array[mid]:
            i = mid + 1
        else:
            j = mid

    if array[i] == x:
        location = i + 1 # As index start from 0.
    return location

array = [1, 2, 3, 5, 6, 7, 8, 10, 12, 13, 15, 16, 18, 19, 20, 22]
print(find_x(19, array))

# What's going on:
"""
    ) array passes in ascending order.
    ) i = left end index of array
    ) j = right end index of array
    ) we compare x with mid value of array, and shortening the i and j range.
    ) if x is greater than mid value of array, it's means x is somwhere right
      to the mid of array, left side ignored, i becomes i = mid + 1 and j remain
      same. if x is less than mid of array, it's means x is somwhere left of mid
      of array, right side ignored, i remains same and j = mid.
    ) we have to do above point again and again until our range contains only one
      value means i = j, start and end point bexomes same from i was less than j.
    ) so we can use while loop of condition !(i==j) or (i<j)
    ) after looping, final i or j index value if equal to x, position is i+1 or j+1
      , adding one because index start from 0.
"""
