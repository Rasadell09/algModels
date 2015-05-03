#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/**最大边数*/
const int N=100000;
/**默认起点*/
const int src=1;
struct Tarjan_direct {
    /**变量的意思分别是：
     *邻接表头数组，第i点属于哪个强连通分量，深搜时间戳，最远祖先时间戳，栈，第i个分量出度
     *栈顶指针，邻接表计数，分量个数，时间戳计数
     *第i个数是否在栈内
     */
    int head[N],id[N],dfn[N],low[N],s[N],out[N],top,cnt,scnt,index;
    bool visit[N];
    /**邻接表存储节点*/
    struct node {int to,next,val;}edge[N];
    /**初始化所有变量*/
    void init() {
        index=top=cnt=scnt=0;
        memset(visit,false,sizeof(visit));
        memset(head,-1,sizeof(head));
        memset(dfn,-1,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(s,0,sizeof(s));
    }
    /**给邻接表添加一条边*/
    void addedge(int from,int to,int val) {
        edge[cnt].to=to;edge[cnt].val=val;
        edge[cnt].next=head[from];head[from]=cnt++;
    }
    /**处理tarjan算法的主函数（递归）
     *对一个u点的所有邻接点v处理
     *1.如果v未被访问，则深搜这个点
     *2.当一个点没有邻接点处理时，判断其两个时间戳是否相等，
     *  相等就将栈退到栈顶上一个元素等于v，否则直接返回
     *3.判断low[u]和low[v]的大小关系，并更新low[u]=min{low[u],low[v]}
     *4.如果v被访问且位于栈内
     *5.判断low[u]与dfn[v]的大小关系，并更新low[u]=min{low[u],dfn[v]}
     */
    void tarjan(int i) {
        low[i]=dfn[i]=++index;
        s[top++]=i;visit[i]=true;
        for(int j=head[i];~j;j=edge[j].next) {
            if(-1==dfn[edge[j].to]) {
                tarjan(edge[j].to);
                low[i]=low[i]<low[edge[j].to]?low[i]:low[edge[j].to];
            }
            else if(visit[edge[j].to])
                low[i]=low[i]<dfn[edge[j].to]?low[i]:dfn[edge[j].to];
        }
        if(low[i]==dfn[i]) {
            ++scnt;
            do {
                id[s[--top]]=scnt;
                visit[s[top]]=false;
            }while(s[top]!=i);
        }
    }
    /**处理强连通分量缩点问题
     *对本图上面的每一个点都进行一次循环，
     *判断其每一个邻接点是否跟他不在一个连通分量之内（id数组值）
     *若不在，则对该分量的visit设为true代表有出边，同时out数组值加1
     */
    void constract_point(int n) {
        memset(visit,false,sizeof(visit));
        for(int i=src;i<=n;i++)
            for(int j=head[i];~j;j=edge[j].next)
                if(id[i]!=id[edge[j].to]) {
                    visit[id[i]]=true;
                    //out[id[i]]++;
                }
    }
}tar;
int main() {return 0;}
