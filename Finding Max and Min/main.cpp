#include<bits/stdc++.h>
using namespace std;

int arr[1000];

void MaxMin(int low,int high,int &max,int &min)
{
    if(low == high)
        max = min = arr[low];
    else if(low == high-1){
        if(arr[low] < arr[high]){
            max = arr[high];
            min = arr[low];
        }
        else{
            max = arr[low];
            min = arr[high];
        }
    }
    else{
        int mid = (int)(low+high)/2;
        int max1,min1;

        MaxMin(low,mid,max,min);
        MaxMin(mid+1,high,max1,min1);

        if(max < max1)
            max = max1;
        if(min > min1)
            min = min1;
        }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        cin >> arr[i];
    int low = 0;
    int high = n-1;

    int max,min;
    MaxMin(low,high,max,min);

    cout << "Maximum Value is: " << max << endl << "Minimum Value is: " << min << endl;

    return 0;
}
