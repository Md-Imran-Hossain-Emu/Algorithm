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

    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
