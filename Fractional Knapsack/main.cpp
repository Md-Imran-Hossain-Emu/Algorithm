#include <bits/stdc++.h>

using namespace std;

struct Item
{
    double value,weight;
};

bool comp(struct Item a, struct Item b)
{
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;

    return ratio1 > ratio2;
}

double knapsack(int cap, struct Item array[], int n)
{
    sort(array, array + n, comp);

    for (int i = 0; i < n; i++){
        cout << array[i].weight << " " << array[i].value << ": " << ((double)array[i].value / array[i].weight) << endl;
    }

    int cw = 0;
    double finalvalue = 0.0;
    float x[n] = {0.0};

    for (int i = 0; i < n; i++)
    {
        if (cw + array[i].weight <= cap)
        {
            x[i] = 1.0;
            cw = cw + array[i].weight;
            finalvalue = finalvalue + array[i].value;
        }

        else
        {
            int remain =  cap - cw;
            x[i] = remain / array[i].weight;
            finalvalue = finalvalue + array[i].value * ((double) remain / array[i].weight);
            break;
        }
    }

    for (int i = 0; i < n; i++)
        cout << x[i] << " ";

    cout << endl;

    return finalvalue;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    Item array[n];

    for(int i=0;i<n;i++){
        cin >> array[i].weight >> array[i].value;
    }

    int capacity;
    cin >> capacity;

    cout << "Profit: " << knapsack(capacity,array,n);

    return 0;
}
