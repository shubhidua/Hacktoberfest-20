#include <iostream>

using namespace std;

int main()
{
    int arr[6]={10,25,9,56,15,59};
    cout<<"Input array is: ";
    for(int i=0;i<6;i++)
    {
        cout<<arr[i];
        cout<<"\t";
    }
    int temp;
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            if(arr[j]<arr[i])
            {
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout<<"\nSorted array is: ";
    for(int i=0;i<6;i++)
    {
        cout<<arr[i];
        cout<<"\t";
    }
    return 0;
}