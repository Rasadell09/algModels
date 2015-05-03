#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf ~(1<<31)
using namespace std;
/**最大边数*/
const int N=50000;
struct Dijkstra {
	/**
	 *变量的意思分别是：
	 *邻接表头数组、第i点到起点的距离、前驱节点数组、邻接表计数、边数、点数
	 */
    int head[N],dist[N],visit[N],pre[N],cnt,ne,nv;
	/**两个结构体分别代表：邻接表存储结构体、优先级队列存储结构体*/
    struct node {int to,next,val;}edge[N];
    struct qNode {
        int v,d;
        qNode(int vv=0,int dd=0):v(vv),d(dd) {}
        bool operator < (const qNode& r) const {return d>r.d;}
    };
	/**初始化所有变量*/
    void init() {
        cnt=1;
        memset(head,-1,sizeof(head));
        memset(visit,0,sizeof(visit));
        memset(pre,-1,sizeof(pre));
        for(int i=1;i<=N;i++) dist[i]=inf;
    }
	/**给邻接表添加一条边*/
    void addedge(int from,int to,int val) {
        edge[cnt].to=to;edge[cnt].val=val;
        edge[cnt].next=head[from];head[from]=cnt++;
    }
	/**处理Dijkstra算法主函数*/
    void dijkstra_prique(int n,const int src) {
        struct qNode mv;int prev=src;priority_queue<qNode> que;			//变量分别是：存储队列最高级节点、已经访问到的点、优先级队列
        visit[src]=1;dist[src]=0;que.push(qNode(src, 0));			//对起点的信息进行设置并加入到优先级队列中
        /**
		 *遍历图中的每一个节点，对其相关边进行判断是否要松弛
		 *如果需要松弛，则进行松弛，将这条边的信息加入队列，并设置前驱节点
		 *for循环结束后，判断队列为空则推出算法，不为空继续将最高级节点取出，并设置其信息
		 */
		for(int i=1;i<n;i++) {
            for(int j=head[prev];~j;j=edge[j].next)
                if((visit[edge[j].to]==0)&&(edge[j].val<dist[edge[j].to]-dist[prev])) {
                    dist[edge[j].to]=dist[prev]+edge[j].val;
                    que.push(qNode(edge[j].to, dist[edge[j].to]));
                    pre[edge[j].to]=prev;
                }
            //while(!que.empty() && (visit[que.top().v]==1)) que.pop();
            if(que.empty()) break;
            mv=que.top();que.pop();visit[prev=mv.v]=1;
        }
    }
}
int main() {return 0;}
