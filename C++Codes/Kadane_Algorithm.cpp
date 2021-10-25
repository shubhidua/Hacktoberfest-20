// C++ program to print largest contiguous array sum
//Kadane’s Algorithm

#include <bits/stdc++.h>
using namespace std;

//function for largest contiguous array sum
int maxSum(int a[], int size)
{
    int max_before = INT_MIN, max_end = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_end = max_end + a[i];
        if (max_before < max_end)
            max_before = max_end;
 
        if (max_end < 0)
            max_end = 0;
    }
    return max_before;
}
 
//Driver program
int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    int max_sum = maxSum(arr, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}