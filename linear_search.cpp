// The Linear Search Algorithm.

#include <iostream>
using namespace std;

int find_x(int x, int array[], int size)
{
    int location = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == x)
        {
            location = i + 1; // As index starts from 0.
            break;
        }
    }
    return location;
}

int main()
{
    int array[7] = {1, 2, 5, 3, 7, 9, 3};
    cout << find_x(5, array, 7) << endl;
    return 0;
}

//   Time Complexity:
//   n = elements in array
//   location = 0 ===> O(1)
//   loop runs for n times in worst case ===> O(n)
//   location = i+1 > O(1)
//   O(1) + O(n) + O(1) + [O(1) for return]
//
//   O(n) = Dominant = Time complexity