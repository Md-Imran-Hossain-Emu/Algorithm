///BFS ----------------------------------- 8
///DFS ---------------------------------- 50
///Dijkstra ---------------------------- 113
///Max-Min ----------------------------- 215
///LCS --------------------------------- 273
///Fractional Knapsack------------------ 343

///BFS
/*
#include<bits/stdc++.h>
using namespace std;

int cost[10][10],i,j,k,n,qu[10],front,rare,v,visit[10],visited[10];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m;
    cin >> n;
    cin >> m;
    for(k=1;k<=m;k++)
    {
        cin >>i>>j;
        cost[i][j]=1;
    }

    cin >> v ;
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=1;j<=n;j++)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                qu[rare++]=j;
            }
        v=qu[front++];
        cout<<v << " ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
}
*/
///------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------
///DFS
/*
#include<bits/stdc++.h>
#define max_vertices 100
using namespace std;

vector<vector<int> > adjacecy_list(max_vertices);
bool visited[max_vertices]={0};
vector<int> mystack;

void call_dfs()
{	int curr;
	while(!mystack.empty())
	{
		curr = mystack[mystack.size()-1];

		cout<<curr<<" ";

		mystack.pop_back();

		for(int i=0;i<adjacecy_list[curr].size();i++)
		{
			if(visited[adjacecy_list[curr][i]]==0){
				visited[adjacecy_list[curr][i]]=1;
				mystack.push_back(adjacecy_list[curr][i]);
			}
		}
	}
	cout<<endl;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int number_of_vertices;
	int number_of_edges;
	int u,v;

	cin>>number_of_vertices;
	cin>>number_of_edges;

	for(int i=0;i<number_of_edges;i++)
	{
		cin>>u>>v;

		adjacecy_list[u].push_back(v);
		adjacecy_list[v].push_back(u);
	}

	for(int i=0;i<number_of_vertices;i++)
	{
		if(visited[i]==0){
			visited[i]=1;
			mystack.push_back(i);
			call_dfs();
		}
	}
}
*/
///------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------
///Dijkstra
/*
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
*/
///------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------
///Max-Min
/*
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
*/
///------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------
///LCS
/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char x[100], y[100], LCS[100];
    int xlen, ylen, rows, cols, L[100][100], i, r, c;

    cout<<"Enter the first string:";
    cin>>x;
    cout<<"Enter the second string:";
    cin>>y;

    xlen = strlen(x);
    ylen = strlen(y);

    rows = xlen + 1;
    cols = ylen + 1;

    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            L[0][c] = 0;
            L[r][0] = 0;
            if(x[r-1] == y[c-1]){
                L[r][c] = L[r-1][c-1] + 1;
            }
            else{
                L[r][c] = max(L[r-1][c], L[r][c-1]);
            }
        }
    }

    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
           cout<<L[r][c]<<" ";
        }
        cout<<endl;
    }

    cout<<"Length of the Longest common subsequence is: "<<L[xlen][ylen]<<endl;

    r = xlen;
    c = ylen;
    i = L[r][c];

    while(r>0 && c>0){
        if(x[r-1] == y[c-1]){
            LCS[i-1] = x[r-1];
            i--;
            r--;
            c--;
        }
        else if(L[r-1][c] > L[r][c-1]){
            r--;
        }
        else{
            c--;
        }
    }
    cout<<"The longest common subsequence is: "<<LCS;


    return 0;
}
*/
///------------------------------------------------------------------------------------
///------------------------------------------------------------------------------------
///Fractional Knapsack
/*
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
*/
