#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf ~(1<<31)
using namespace std;
/**最大边数，最大点数*/
const int E=500000;
const int V=50000;
struct SPFA_Stack {
	/**变量的意思分别是：邻接表头数组、第i点到起点的最短距离、节点访问控制符、邻接表计数*/
	int head[V],dist[V],visit[V],m;
	/**邻接表存储结构体*/
    struct node {int to,next,val;}edge[E];
    /**初始化所有变量*/
    void init() {
        m=1;
        memset(head,-1,sizeof(head));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=V;i++) dist[i]=inf;
    }
	/**给邻接表添加一条边*/
    void addedge(int from,int to, nt val) {
        edge[m].to=to;edge[m].val=val;
        edge[m].next=head[from];head[from]=m++;
    }
	/**对u到v的边进行松弛操作，成功返回1，失败返回0*/
    int relax(int u,int v,int val) {
        if(dist[v]-dist[u]>val) {
            dist[v]=dist[u]+val;
            return 1;
        }
        return 0;
    }
	/**处理SPFA的主函数*/
    int spfa_sta(int src,int n) {
        int sta[E],top=1;			//定义栈和栈顶指针
        sta[0]=src;visit[src]=1;dist[src]=0;			//起点入栈，并设置相关信息
        /**
		 *当栈不为空时（即栈顶指针不为0），将栈顶元素取出，设置相关信息
		 *对该元素节点的相关边均尝试进行松弛，若成功且边终点未被访问，则将该终点入栈，设置相关信息
		 *当栈空时退出，返回终点的dist值
		 */
		while(top) {
            int u=sta[--top];visit[u]=0;
            for(int i=head[u];~i;i=edge[i].next)
                if((relax(u,edge[i].to,edge[i].val)==1)&&(!visit[edge[i].to])) {
                    sta[top++]=edge[i].to;
                    visit[edge[i].to]=1;
                }
        }
        return dist[n];
    }
}
int main() {return 0;}
