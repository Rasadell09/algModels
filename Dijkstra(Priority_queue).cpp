#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf ~(1<<31)
using namespace std;
/**������*/
const int N=50000;
struct Dijkstra {
	/**
	 *��������˼�ֱ��ǣ�
	 *�ڽӱ�ͷ���顢��i�㵽���ľ��롢ǰ���ڵ����顢�ڽӱ����������������
	 */
    int head[N],dist[N],visit[N],pre[N],cnt,ne,nv;
	/**�����ṹ��ֱ�����ڽӱ�洢�ṹ�塢���ȼ����д洢�ṹ��*/
    struct node {int to,next,val;}edge[N];
    struct qNode {
        int v,d;
        qNode(int vv=0,int dd=0):v(vv),d(dd) {}
        bool operator < (const qNode& r) const {return d>r.d;}
    };
	/**��ʼ�����б���*/
    void init() {
        cnt=1;
        memset(head,-1,sizeof(head));
        memset(visit,0,sizeof(visit));
        memset(pre,-1,sizeof(pre));
        for(int i=1;i<=N;i++) dist[i]=inf;
    }
	/**���ڽӱ����һ����*/
    void addedge(int from,int to,int val) {
        edge[cnt].to=to;edge[cnt].val=val;
        edge[cnt].next=head[from];head[from]=cnt++;
    }
	/**����Dijkstra�㷨������*/
    void dijkstra_prique(int n,const int src) {
        struct qNode mv;int prev=src;priority_queue<qNode> que;			//�����ֱ��ǣ��洢������߼��ڵ㡢�Ѿ����ʵ��ĵ㡢���ȼ�����
        visit[src]=1;dist[src]=0;que.push(qNode(src, 0));			//��������Ϣ�������ò����뵽���ȼ�������
        /**
		 *����ͼ�е�ÿһ���ڵ㣬������ر߽����ж��Ƿ�Ҫ�ɳ�
		 *�����Ҫ�ɳڣ�������ɳڣ��������ߵ���Ϣ������У�������ǰ���ڵ�
		 *forѭ���������ж϶���Ϊ�����Ƴ��㷨����Ϊ�ռ�������߼��ڵ�ȡ��������������Ϣ
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
