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
