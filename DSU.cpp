#include<bits/stdc++.h>
using namespace std;

class DSU
  {
  private:
    int size;
    vector<int>parent;
    vector<int>rank;
  public:
    DSU(int n):size(n)
    {rank.resize(size+1);parent.resize(size+1);
      for(int i=1;i<=size;i++)parent[i]=i;
    }
    
    int get_parent(int x)  
    {// Path compression;
      
      if(parent[x]==x)return x;
      else parent[x]=get_parent(parent[x]);
    }
    void make_union(int a,int b)
    {
      int parent_a=get_parent(a);
      int parent_b=get_parent(b);
      if(rank[parent_a]==rank[parent_b])rank[parent_a]++;
      // Small to large merging
      if(rank[parent_b]>rank[parent_a])parent[parent_a]=parent_b;
      else parent[parent_b]=parent_a;
    }

  };

int main()
{
  DSU obj= DSU(10);
return 0;
}