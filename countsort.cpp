#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[],int n)
{
    int brr[n] = {0};
    int crr[10];

    for (int i = 0; i <10;i++)
    {
        crr[i] = 0;
    }

    for (int i = 0; i < n;i++)
    {
        crr[arr[i]] = crr[arr[i]] + 1;
    }

    for (int i = 1; i < 10;i++)
    {
        crr[i] = crr[i - 1] + crr[i];
    }

    for (int i = n - 1; i >= 0;i--)
    {
        brr[crr[arr[i]] - 1] = arr[i];
        crr[arr[i]] = crr[arr[i]] - 1;
    }

    for (int i = 0; i < n;i++)
    {
        brr[i] = arr[i];
    }
}

int main()
{
    int arr[7] = {1, 5, 6, 7, 4,8, 9};
    
    
    

    countsort(arr, 7 );

    for (int i = 0; i < 7;i++)
    {
        cout << arr[i];
    }
}