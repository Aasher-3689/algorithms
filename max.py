# Finding the Maximum Element in a Finite Sequence.

def find_max(array):
    max_num = array[0]
    for i in array:
        if i > max_num:
            max_num = i
    return max_num

array = [1, 2, 5, 3, 7, 9, 3]
print(find_max(array))

#   Time Complexity:
#   n = elements in array
#   max_num = array[0] ===> O(1)
#   loop runs for n times in worst case ===> O(n)
#   max_num = i > O(1) ===> in worst case assign n times ===> O(n)
#   O(1) + O(n) + O(n) + [O(1) for return]
#   = 2O(n) + 2O(1)

#   O(n) = Dominant = Time complexity
