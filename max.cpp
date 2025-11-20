// Finding the Maximum Element in a Finite Sequence.

#include <iostream>
using namespace std;

int find_max(int array[], int size)
{
    int max_num = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max_num) max_num = array[i];
    }
    return max_num;
}

int main()
{
    int array[7] = {1, 2, 5, 3, 7, 9, 3};
    cout << find_max(array, 7) << endl;
    return 0;
}

//   Time Complexity:
//   n = elements in array
//   max_num = array[0] ===> O(1)
//   loop runs for n times in worst case ===> O(n)
//   max_num = i > O(1) ===> in worst case assign n times ===> O(n)
//   O(1) + O(n) + O(n) + [O(1) for return]
//   = 2O(n) + 2O(1)
//
//   O(n) = Dominant = Time complexity