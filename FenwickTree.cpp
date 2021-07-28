#include<bits/stdc++.h>
using namespace std;


class fenwick
{ 
  public:
   int size;
  	vector<int>BIT,BIT2;
   fenwick(int n):size(n)
   {BIT.assign(n,0);BIT2.assign(n,0);}
   void point_update(int ind,int val,bool type)
   {
      if(type==0)for(;ind<size;ind+=(ind&-ind))BIT[ind]+=val;
      else {
         for(;ind<size;ind+=(ind&-ind))BIT2[ind]+=val;
      }
   }
   void range_update(int l,int r,int val)
   {
      point_update(l,val,0);
      point_update(r+1,-val,0);
      point_update(l,(l-1)*val,1);
      point_update(r+1,-r*(val),1);
   }
   int point_query(int ind,int type)
   { // 0 for first BIT, 1 for second
      int ans=0;
      if(type==0)
      {for(;ind>0;ind-=(ind&-ind))ans+=BIT[ind];}
      else
      {for(;ind>0;ind-=(ind&-ind))ans+=BIT2[ind];}
       return ans;
   }
   int prefix_sum(int ind)
   {
      return point_query(ind,0)*ind-point_query(ind,1);
   }
   int range_sum(int l,int r)
   {
      return prefix_sum(r)-prefix_sum(l-1);
   }
   void print(){for(int i=1;i<size;i++)cout<<point_query(i,0)<<" ";cout<<endl;}
};


int main()
{
   fenwick f(10);
   f.range_update(1,5,2);
   f.range_update(3,4,-1);
   f.range_update(8,9,5);
   f.print();
   cout<<f.range_sum(4,9)<<endl;
}