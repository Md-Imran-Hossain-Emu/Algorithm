#include <bits/stdc++.h>
using namespace std;

void knapsack(int capacity,int weight[],int profit[],int item)
{
    int i,w;
    int v[item+1][capacity+1];

    for(i = 0; i <= item; i++)
        v[i][0] = 0;
    for(w = 0; w <= capacity; w++)
        v[0][w] = 0;

    for(i = 1; i <= item; i++) {
        for(w = 1; w <= capacity; w++) {
            if(weight[i] <= w) {
                v[i][w] = max(v[i-1][w], profit[i] + v[i-1][w - weight[i]]);
            }
            else {
                v[i][w] = v[i-1][w];
            }
        }
    }

    for(i = 0; i <= item; i++) {
        for(w = 0; w <= capacity; w++){
            cout << v[i][w] << " ";
        }
        cout << endl;
    }

    cout << "Maximum Profit is: " << v[item][capacity] << endl;

    i = item, w = capacity;
    int x[item] = {0};

    while( i>0 && w >0){
        if(v[i][w] != v[i-1][w]){
            x[i] = 1;
            w = w-weight[i];
            i--;

        }
        else
            i--;
    }
    cout << "Taken items: ";
    for(i=1;i<=item;i++){
        if(x[i] == 1)
            cout << i << " ";
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int item,capacity;

    cin >> item;

    int profit[item];
    int weight[item];

    for(int i=1;i<=item;i++){
        cin >> profit[i] >> weight[i];
    }

    cin >> capacity;

    knapsack(capacity,weight,profit,item);

    return 0;
}
