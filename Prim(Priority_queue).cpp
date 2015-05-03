#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf ~(1<<31)
using namespace std;
/**最大节点数*/
const int N=100000;
struct Prim_Prioriy_queue {
    /**
     *变量的意思分别是：
	 *节点数、边数、MST权值和、邻接表计数、MST边数组计数、邻接表头数组、MST边数组
	 *节点访问控制符
	 */
    int n,m,res,cnt,index,head[N],minTree[N];
    bool visit[N];
    /**两个结构体分别代表：邻接表存储结构体、优先级队列存储结构体*/
    struct node {int to,next,val;}edge[N];
    struct qNode {
        int id,val;
        qNode(int v=0,int w=0):id(v),val(w) {}
        bool operator < (const qNode& a) const {return val>a.val;}
    };
    /**初始化所有变量*/
    void init() {
        res=index=cnt=0;
        memset(head,-1,sizeof(head));
        memset(minTree,0,sizeof(minTree));
        memset(visit,false,sizeof(visit));
    }
    /**给邻接表添加一条边*/
    void addedge(int from,int to,int val) {
        edge[cnt].to=to;edge[cnt].val=val;
        edge[cnt].next=head[from];head[from]=cnt++;
    }
    /**处理Prim算法主函数*/
    void prim_pq() {
        struct qNode tmp;           //存储优先级队列最高值
        priority_queue<qNode> que;              //优先级队列定义
        visit[0]=true;              //设置0点为树根，并将0的相关边加入队列
        for(int i=head[0];~i;i=edge[i].next)
            que.push(qNode(i,edge[i].val));
        /**
        *每次循环将队列中权值最小的边拿出，
        *更新res的值，更新minTree数组值
        *将该边的终点的相关边加入队列。
        */
        while(!que.empty()) {
            tmp=que.top();que.pop();
            res+=tmp.val;minTree[index++]=tmp.id;
            visit[edge[tmp.id].to]=true;
            for(int i=head[edge[tmp.id].to];~i;i=edge[i].next)
                if(!visit[edge[i].to])
                    que.push(qNode(i,edge[i].val));
        }
        for(int i=0;i<n;i++)
            if(false==visit[i]) res=-1;
    }
}prim;
int main() {return 0;}
