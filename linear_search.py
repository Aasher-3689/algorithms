# The Linear Search Algorithm.

def find_x(x, array):
    location = 0
    for i in range(len(array)):
        if array[i] == x:
            location = i + 1    # As index start from 0.
            break
    return location

array = [1, 2, 5, 3, 7, 9, 3]
print(find_x(5, array))

#   Time Complexity:
#   n = elements in array
#   location = 0 ===> O(1)
#   loop runs for n times in worst case ===> O(n)
#   location = i+1 > O(1)
#   O(1) + O(n) + O(1) + [O(1) for return]

#   O(n) = Dominant = Time complexity
