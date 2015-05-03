#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/**最大边数*/
const int N=100000;
struct Kruskal_CS_PQ {
    /**
     *变量的意思分别是：
     *并查集数组，最小生成树边集数组，点数，边计数，
     *已经找到的边计数，MST数组计数，MST边权
     */
    int father[N],minTree[N],n,cnt,count,index,minV;
    /**边存储结构体*/
    struct node {
        int id,to,from,val;
        bool operator < (const node& a) const {return val>a.val;}
    }edge[N];
    /**优先级队列*/
    priority_queue<node> que;
    /**初始化所有变量*/
    void init() {
        n=index=minV=cnt=0;
        memset(minTree,0,sizeof(minTree));
    }
    /**构建初始并查集*/
    void make_set(int n) {
        for(int i=0;i<N;i++) father[i]=i;
    }
    /**将两个集合合并*/
    void union_set(int x,int y) {
        x=find_set(x);y=find_set(y);
        if(x==y) return;
        father[y]=x;
    }
    /**加入一个点到某个集合*/
    int find_set(int x) {
        if(father[x]!=x) father[x]=find_set(father[x]);
        return father[x];
    }
    /**加入一条边，并加入到优先级队列中*/
    void addedge(int from,int to,int val) {
        edge[cnt].to=to;edge[cnt].val=val;
        edge[cnt].from=from;edge[cnt].id=cnt++;
        que.push(edge[cnt-1]);
    }
    /**
     *Kruskal算法主函数，每次选取优先级队列中级别最高的边，
     *判断是否成环，如成环则丢弃，继续，不成环则加入MST中，合并并查集
     */
    void kruskal() {
        make_set(n);count=0;
        while(count!=n-1) {
            node t=que.top();que.pop();
            if(find_set(t.from)!=find_set(t.to)) {
                count++;minV+=t.val;minTree[index++]=t.id;
                union_set(t.from,t.to);
            }
        }
    }
}krk;
int main(){return 0;}
