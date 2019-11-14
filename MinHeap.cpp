#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int array[100]={0};
    priority_queue <int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);

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
