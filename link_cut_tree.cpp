#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
map<pair<int,int>,int> idx;
int p[100005],ch[2][100005];
bool flip[100005],del[300005];
int sz[100005],ans[300005];
void push(int node)
{
    if (flip[node])
    {
        flip[node]=0;
        swap(ch[0][node],ch[1][node]);
        if (ch[0][node])
        flip[ch[0][node]]^=1;
        if (ch[1][node])
        flip[ch[1][node]]^=1;
    }
}
void recalc(int node)
{
    push(ch[0][node]);
    push(ch[1][node]);
    sz[node]=1+sz[ch[0][node]]+sz[ch[1][node]];
}
int side(int node)
{
    if (!p[node])
    return -2;
    if (ch[0][p[node]]==node)
    return 0;
    if (ch[1][p[node]]==node)
    return 1;
    return -1;
}
void attach(int par,int node,int s)
{
    if (node)
    p[node]=par;
    if (s>=0)
    ch[s][par]=node;
}
void rotate(int node)
{
    int s=side(node),par=p[node];
    attach(p[par],node,side(par));
    attach(par,ch[!s][node],s);
    attach(node,par,!s);
    recalc(par);
    recalc(node);
}
void splay(int node)
{
    while (side(node)>=0 && side(p[node])>=0)
    {
        push(p[p[node]]);
        push(p[node]);
        push(node);
        rotate((side(node)==side(p[node]))? p[node]:node);
        rotate(node);
    }
    if (side(node)>=0)
    {
        push(p[node]);
        push(node);
        rotate(node);
    }
    push(node);
}
void access(int node)
{
    int o=node,cur=0;
    while (node)
    {
        splay(node);
        ch[1][node]=cur;
        recalc(node);
        cur=node;
        node=p[node];
    }
    splay(o);
}
void reroot(int node)
{
    access(node);
    flip[node]^=1;
    access(node);
}
int dep(int node)
{
    access(node);
    return sz[ch[0][node]];
}
int find(int node)
{
    access(node);
    while (ch[0][node])
    {
        node=ch[0][node];
        push(node);
    }
    access(node);
    return node;
}
void link(int x,int y)
{
    reroot(x);
    access(y);
    attach(x,y,0);
    recalc(x);
}
void cut(int x,int y)
{
    reroot(x);
    access(y);
    p[ch[0][y]]=0;
    ch[0][y]=0;
    recalc(y);
}
int parent(int node)
{
    access(node);
    node=ch[0][node];
    push(node);
    while (ch[1][node])
    {
        node=ch[1][node];
        push(node);
    }
    access(node);
    return node;
}
int go(int a,int b,int c2)
{
    int c1=1,d1=dep(a),d2=dep(b);
    vector<pair<int,int> > c;
    while (a!=b)
    {
        if (d1<d2)
        {
            swap(a,b);
            swap(c1,c2);
            swap(d1,d2);
        }
        int p=parent(a);
        ans[idx[{p,a}]]=c1;
        c1*=-1;
        c.push_back({a,p});
        a=p;
        d1--;
    }
    for (auto e:c)
    cut(e.first,e.second);
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        idx.clear();
        for (int i=1;i<=n;i++)
        {
            v[i].clear();
            p[i]=0;
            ch[0][i]=ch[1][i]=0;
            flip[i]=0;
            sz[i]=1;
        }
        for (int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            idx[{a,b}]=i;
            idx[{b,a}]=i;
            ans[i]=0;
            del[i]=0;
        }
        for (int a=1;a<=n;a++)
        {
            int b=-1;
            for (int c:v[a])
            {
                int i=idx[{a,c}];
                if (!del[i] && !ans[i])
                {
                    if (find(a)!=find(c))
                    {
                        link(a,c);
                        del[i]=1;
                    }
                    else if (dep(a)%2!=dep(c)%2)
                    {
                        ans[i]=-1;
                        go(a,c,1);
                        if (b!=-1 && find(a)!=find(b))
                        {
                            link(a,b);
                            del[idx[{a,b}]]=1;
                            b=-1;
                        }
                    }
                    else if (b==-1)
                    b=c;
                    else
                    {
                        ans[idx[{a,b}]]=-1;
                        ans[i]=1;
                        go(b,c,-1);
                        b=-1;
                    }
                }
            }
        }
        for (int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    }
} 