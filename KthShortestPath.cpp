#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf ~(1<<31)
using namespace std;
/**节点最大值*/
const int N=100100;
/**点i到终点的最短路长度*/
int dist[N];
struct KthShortestPath {
    /**
     *这些变量的意义分别是：
     *点数，边数，第x短路，起点，终点，正图邻接表计数，反图邻接表计数，
     *正图head数组，反图head数组，点i进入队列次数
     *点i访问控制符
     */
    int n,m,x,src,tar,cntNor,cntNeg,norHead[N],negHead[N],cnt[N];
    bool visit[N];
    /**该结构体用来存储加入到优先级队列的节点，分别存有节点号和总的路径长度值*/
    struct qNode {
        int id,val;
        qNode(int v,int w):id(v),val(w) {}
        qNode() {}
        bool operator < (const qNode& a) const {
            return val+dist[id]>a.val+dist[a.id];
        }
    };
    /**该结构体用来存储邻接表信息*/
    struct node {int to,next,val;}norEdge[N],negEdge[N];
    /**该方法用来在正图上添加一条边*/
    void addNormalEdge(int from,int to,int val) {
        norEdge[cntNor].to=to;norEdge[cntNor].val=val;
        norEdge[cntNor].next=norHead[from];norHead[from]=cntNor++;
    }
    /**该方法用来在反图上添加一条边*/
    void addNagetiveEdge(int from,int to,int val) {
        negEdge[cntNeg].to=to;negEdge[cntNeg].val=val;
        negEdge[cntNeg].next=negHead[from];negHead[from]=cntNeg++;
    }
    /**该方法初始化所有变量*/
    void init() {
        cntNor=cntNeg=0;
        //src=0;tar=n-1;
        memset(norHead,-1,sizeof(norHead));
        memset(negHead,-1,sizeof(negHead));
        memset(visit,false,sizeof(visit));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<N;i++) dist[i]=inf;
    }
    /**该方法用来进行松弛操作*/
    int relax(int u,int v,int val) {
        if(dist[v]-dist[u]>val) {
            dist[v]=dist[u]+val;
            return 1;
        }
        return 0;
    }
    /**该方法对反图进行一次SPFA求出每个点的dist值*/
    void preHandler() {
        queue<int> que;
        que.push(tar);
        visit[tar]=true;
        dist[tar]=0;
        while(!que.empty()) {
            int tmp=que.front();que.pop();visit[tmp]=false;
            for(int i=negHead[tmp];~i;i=negEdge[i].next)
                if((1==relax(tmp,negEdge[i].to,negEdge[i].val))&&!visit[negEdge[i].to]) {
                    que.push(negEdge[i].to);
                    visit[negEdge[i].to]=true;
                }
        }
    }
    /**该方法用来求出第x短路的权值*/
    int solve() {
        struct qNode tmp;			//用来存储优先级队列最高优先级节点
        priority_queue<qNode> que;			//定义优先级队列
        que.push(qNode(src,0));			//起点和dist[src]加入队列
	/**
	 *队列不为空时，取出队列中最高优先级节点，如果其入队列次数超过x则丢弃进入下一轮
	 *如果目标点的入队列次数等于x则返回此时临时节点变量中的权值
	 *如果都不满足，则对该元素节点的所有相关边终点和该边权值与临时节点变量的权值和初始化一个节点加入队列
	 */
        while(!que.empty()) {
            tmp=que.top();que.pop();
            if(++cnt[tmp.id]>x) continue;
            if(cnt[tar]==x) return tmp.val;
            for(int i=norHead[tmp.id];~i;i=norEdge[i].next)
                que.push(qNode(norEdge[i].to,tmp.val+norEdge[i].val));
        }
        return -1;
    }
}ksp;
int main(){return 0;}
