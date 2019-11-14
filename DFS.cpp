#include<bits/stdc++.h>
using namespace std;
int cost[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10];

int main()
{
    int m;
    cin >> n;
    cin >> m;
    for(k=1;k<=m;k++)
    {
        cin >>i>>j;
        cost[i][j]=1;
    }

    cin >>v;
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
    for(j=n;j>=1;j--)
        if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
        {
            visit[j]=1;
            stk[top]=j;
            top++;
        }
        v=stk[--top];
        cout<<v << " ";
        k++;
        visit[v]=0; visited[v]=1;
    }
}
