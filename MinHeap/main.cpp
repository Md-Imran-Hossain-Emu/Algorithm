#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int array[100]={0};
    priority_queue <int> pq;

    int n;
    while(scanf("%d",&n)!=EOF){
        pq.push(n);
    }

    int i=0;

    while (pq.empty() == false)
    {
        array[i] = pq.top();
        i++;
        pq.pop();
    }

    while(i--){
        cout << array[i] << " " ;
    }

    return 0;
}
