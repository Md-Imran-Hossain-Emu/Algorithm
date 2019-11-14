#include<bits/stdc++.h>
using namespace std;

int main()
{
    int adj[100][100];
    freopen("adjacencyinput.txt","r",stdin);
    freopen("adjacencyoutput.txt","w",stdout);
    int nodes,edges;
    int n1,n2;
    cin>>nodes>>edges;
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cin >>n1>>n2;
            adj[n1][n2]=1;
        adj[n2][n1]=1;
        }

    }
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout << adj[i][j];
        }
        cout << endl;
    }
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            if(adj[i][j]==1)
                cout << i <<"------>" << j << "  ";
        }
        cout << endl;
    }
}
