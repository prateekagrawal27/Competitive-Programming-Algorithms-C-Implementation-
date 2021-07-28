#include<bits/stdc++.h>
using namespace std;


class Graph
{
  public:
  	int size;
  	vector<pair<int,int>>*adj;
  	Graph(int sz){
  			size=sz;
  			adj= new vector<pair<int,int>>[sz];
  	}
  	void add_edge(const int &u,const int &v,const int &cost)
  	{
  		adj[u].push_back(make_pair(v,cost));
  	}
  	vector<int> djiktra(int src)
  	{ int MAX=1e9;
  		vector<int>cost;cost.assign(size,MAX);
  		cost[src]=0;
  		set<pair<int,int>>s;
  		vector<bool>vis(size,0);
  		s.emplace(make_pair(0,src));
  		while(s.size()>0)
  		{
  			pair<int,int> cur= *s.begin();s.erase(s.begin());
  			vis[cur.second];
  			for(pair<int,int> &x:adj[cur.second])
  			{
  				if(!vis[x.first] && cost[x.first]>cur.first+x.second)
  				{   //x.first- neighbor x.second- edge weight
  					set<pair<int,int>>::iterator it=s.find(make_pair(cost[x.first],x.first));
  					if(it!=s.end()){s.erase(it);}
  					cost[x.first]=cur.first+x.second;
  					s.insert(make_pair(cost[x.first],x.first));
  				}
  			}
  		}
  		return cost;
  	}
};


int main()
{
   Graph G(9);
   int a[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
   for(int i=0;i<9;i++)
   	for(int j=0;j<9;j++)
   	{
   		if(a[i][j]>0){G.add_edge(i,j,a[i][j]);}
   	}
   	vector<int>ans=G.djiktra(0);
   	for(int &x:ans)cout<<x<<" ";cout<<endl;
}