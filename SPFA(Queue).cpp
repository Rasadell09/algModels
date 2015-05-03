#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf ~(1<<31)
using namespace std;
/**最大边数、最大点数*/
const int E=500000;
const int V=50000;
struct SPFA_Queue {
	/**
	 *变量的意思分别是：
	 *邻接表头数组、第i点到起点的最小距离、节点访问控制符、节点入队列次数数组、邻接表计数
	 */
	int head[V],dist[V],visit[V],cnt[V],m;
	/**邻接表存储结构体*/
    struct node {int to,next,val;}edge[E];
    /**初始化所有变量*/
    void init() {
        m=1;
        memset(cnt,0,sizeof(cnt));
        memset(head,-1,sizeof(head));
        memset(visit,0,sizeof(visit));
        for(int i=1; i<=V; i++) dist[i]=inf;
    }
	/**给邻接表添加一条边*/
    void addedge(int from,int to,int val) {
        edge[m].to=to;edge[m].val=val;
        edge[m].next=head[from];head[from]=m++;
    }
	/**对u到v的边进行松弛操作，成功返回1，失败返回0*/
    int relax(int u,int v,int val) {
        if(dist[v]-dist[u] > val) {
            dist[v]=dist[u]+val;
            return 1;
        }
        return 0;
    }
	/**处理SPFA算法的主函数*/
    int spfa_que(int src,int n) {
        queue<int> que;			//定义存储队列
        que.push(src);visit[src]=1;++cnt[src];			//起点入队列，并设置起点相关信息
        /**
		 *当队列不为空时，取出队头元素，设置其相关信息
		 *对该元素节点相关边逐一进行松弛操作，若成功则将该边终点加入队列并设置相关信息
		 *当某一个点入队列次数超过n时，说明存在负环，返回-1，推出算法
		 *否则返回终点的dist值
		 */
		while(!que.empty()) {
            int u=que.front();que.pop();visit[u]=0;
            for(int i=head[u];~i;i=edge[i].next)
                if((relax(u,edge[i].to,edge[i].val)==1)&&(!visit[edge[i].to])) {
                    que.push(edge[i].to); visit[edge[i].to]=1;
                    if((++cnt[edge[i].to])>n) return -1;
                }
        }
		//if(dist[n]==inf) return -2
        return dist[n];
    }
}
int main() {return 0;}
