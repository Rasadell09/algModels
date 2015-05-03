#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf ~(1<<31)
using namespace std;
/**���ڵ���*/
const int N=100000;
struct Prim_Prioriy_queue {
    /**
     *��������˼�ֱ��ǣ�
	 *�ڵ�����������MSTȨֵ�͡��ڽӱ������MST������������ڽӱ�ͷ���顢MST������
	 *�ڵ���ʿ��Ʒ�
	 */
    int n,m,res,cnt,index,head[N],minTree[N];
    bool visit[N];
    /**�����ṹ��ֱ�����ڽӱ�洢�ṹ�塢���ȼ����д洢�ṹ��*/
    struct node {int to,next,val;}edge[N];
    struct qNode {
        int id,val;
        qNode(int v=0,int w=0):id(v),val(w) {}
        bool operator < (const qNode& a) const {return val>a.val;}
    };
    /**��ʼ�����б���*/
    void init() {
        res=index=cnt=0;
        memset(head,-1,sizeof(head));
        memset(minTree,0,sizeof(minTree));
        memset(visit,false,sizeof(visit));
    }
    /**���ڽӱ����һ����*/
    void addedge(int from,int to,int val) {
        edge[cnt].to=to;edge[cnt].val=val;
        edge[cnt].next=head[from];head[from]=cnt++;
    }
    /**����Prim�㷨������*/
    void prim_pq() {
        struct qNode tmp;           //�洢���ȼ��������ֵ
        priority_queue<qNode> que;              //���ȼ����ж���
        visit[0]=true;              //����0��Ϊ����������0����ر߼������
        for(int i=head[0];~i;i=edge[i].next)
            que.push(qNode(i,edge[i].val));
        /**
        *ÿ��ѭ����������Ȩֵ��С�ı��ó���
        *����res��ֵ������minTree����ֵ
        *���ñߵ��յ����ر߼�����С�
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
