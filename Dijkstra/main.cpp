#include <bits/stdc++.h>
using namespace std;

#define inf 99999999999;
int node, edge;
int adj[100][100];

void dijkstra(int source){
    int distance[100], prev[100];
    int visited[100]={0}, countl, mindis, nextnode, i, j;

    for(i = 1;i <= node; i++){
		prev[i]= source;
		distance[i] = adj[source][i];
	}

	distance[source] = 0;
	visited[source] = 1;
	countl = 1;

	while(countl < node - 1){
		mindis = inf;
		for(i = 1;i<= node; i++){
			if(distance[i] < mindis && visited[i]==0){
				mindis=distance[i];
				nextnode=i;
			}
		}
		visited[nextnode] = 1;
		for(i = 1;i <= node; i++){
			if(visited[i]==0){
				if(mindis + adj[nextnode][i] < distance[i]){
					distance[i] = mindis + adj[nextnode][i];
					prev[i]=nextnode;
				}
			}
		}
		countl++;
	}

	int print[100]={0};
	int k=0;
	i = node;
    if(i!=source){
        print[k]=i;
        k++;
        j=i;
        do{
            j=prev[j];

            print[k]=j;
            k++;
        }
        while(j != source);
    }

    int temp = 0;
    k= 0;
    while(print[k]!=0){
        temp++;
        k++;
    }
    int t=temp;
    while(t--)
        cout << print[t] << " ";
    cout << endl;
}

int main()
{
    int source;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>> node;
    cin>> edge;
    int n1, n2, w;

    for(int i = 0; i< edge; i++){
        cin>>n1>>n2>>w;
        adj[n1][n2] = w;
    }

    for(int i = 1; i<= node; i++){
        for(int j = 1; j<=node; j++){
            if(adj[i][j] == 0){
                adj[i][j] = inf;
            }

        }

    }

    source = 1;
    dijkstra(source);

    return 0;
}
