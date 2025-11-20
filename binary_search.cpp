// The Binary Search Algorithm : list pass in ascending order

#include <iostream>
using namespace std;

int find_x(int x, int array[], int size)
{
    int location = 0;
    int i = 0, j = size - 1;
    while (i < j)
    {
        int mid = (i + j) / 2;
        if (x > array[mid]) i = mid + 1;
        else j = mid;
    }
    
    if (array[i] == x) location = i + 1; // As index starts from 0.
    return location;
}

int main()
{
    int array[16] = {1, 2, 3, 5, 6, 7, 8, 10, 12, 13, 15, 16, 18, 19, 20, 22};
    cout << find_x(19, array, 16) << endl;
    return 0;
}

// What's going on:
/*
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
*/

// Time complexity:
/*
    1) location = 0 >>>>> O(1)
    2) i = 0 >>>>> O(1)
    3) j = len(array) - 1 >>>>> O(1)
    
    ) mid = int((i + j) / 2) >>> O(1)
    ) i = mid + 1 >>>> O(1) ||| j = mid >>>> O(1)
    ) overall O(1) for one iteration.

    ) no. of iterations w.r.t size?
    ) first iteration: n
    ) 2nd iteration: n/2 = n/2¹
    ) 3rd iteration: n/4 = n/2²
    ) ...
    ) last iteration: n/2ᵏ = 1 (at the end size remains one)
    ) solving for k:
    ) 2ᵏ = n
    ) k = log₂n

    ) for one iteration O(1)
    4) for log₂n times O(1) = log₂n
    5) location = i + 1 >>>>> O(1)
    6) return O(1)

    Result) log₂n = Dominant = Time Complexity
*/