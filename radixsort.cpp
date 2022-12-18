#include<bits/stdc++.h>
using namespace std;

int getmax(int arr[],int n)
{
    int maxi = -1100;
    for (int i = 0; i < n;i++)
    {
        if(maxi<arr[i])
        {
            maxi = arr[i];
        }
    }

    return maxi;
}

void countsort(int arr[],int n,int pos)
{
    int brr[n];
    int count[10] = {0};
    for (int i = 0; i < n;i++)
    {
        ++count[(arr[i] / pos) % 10];
    }
    for (int i = 1; i <= 9;i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i >= 0;i--)
    {
        brr[--count[((arr[i] / pos) % 10)]] = arr[i];
    }

    for (int i = 0; i < n;i++)
    {
        arr[i] = brr[i];
    }
}

void radixsort(int arr[],int n)
{
    int max;
    max = getmax(arr, n);

    for (int pos = 1; max / pos > 0;pos=pos*10)
    {
        countsort(arr, n, pos);
    }
}

int main()
{
    int arr[5] = {122, 345, 432, 678, 987};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);

    for (int i = 0; i< n;i++)
    {
        cout << arr[i];
    }
}
