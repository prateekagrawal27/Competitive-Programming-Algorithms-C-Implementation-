#include<bits/stdc++.h>
using namespace std;

class segtree
  {
  private:
   vector<int>tree,lazytree;
   int n;
  public:
   segtree(vector<int> a){n=a.size();tree.resize(4*n);lazytree.resize(4*n);
                          build(0,n-1,1,a);
                        }

    int build(int ss,int se,int cur,vector<int>a)
    {
      if(ss==se){tree[cur]=a[ss];}
      else
      {
        int mid=ss+se;mid>>=1;
        build(ss,mid,2*cur,a);
        build(mid+1,se,2*cur+1,a);
        tree[cur]=(tree[2*cur]+tree[2*cur+1]);
      }
      return tree[cur];
    }
    void update(int ul,int ur,int val){return update(ul,ur,0,n-1,1,val);}
    void update(int ul,int ur,int l,int r,int cur,int val)
    { 
      if(ul>r || ur<l)return;
      else if(l>=ul && r<=ur){tree[cur]+=(r-l+1)*(val);lazytree[cur]+=val;}
      else
      {
        int mid=l+r;mid>>=1;
        update(ul,ur,l,mid,2*cur,val);
        update(ul,ur,mid+1,r,2*cur+1,val);
      }
    }
    int query(int ql,int qr){return query(ql,qr,0,n-1,1);}
    int query(int ql,int qr,int l,int r,int cur)
    {
      if(qr<l || ql>r)return 0;
      else if(l>=ql && r<=qr)return tree[cur];
      else
      {
        push(cur,l,r);
        int mid=l+r;mid>>=1;
        int lq=query(ql,qr,l,mid,2*cur);
        int rq=query(ql,qr,mid+1,r,2*cur+1);
        return lq+rq;
      }
    }

    void push(int cur,int ss,int se)
    { 
      int mid=(ss+se)/2;
      lazytree[2*cur]+=lazytree[cur];
      tree[2*cur]+=(se-mid+1)*lazytree[2*cur];
      lazytree[2*cur+1]+=lazytree[cur];
      tree[2*cur+1]+=(se-mid)*lazytree[2*cur];
      lazytree[cur]=0;
    }
  };

int main()
{  vector<int>a={1,5,6,4,1,2,3,4,10,12};
  segtree* obj= new segtree(a);
   obj->update(1,7,4);
   cout<<obj->query(2,6)<<'\n';
  
return 0;
}