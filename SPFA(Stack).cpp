#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define inf ~(1<<31)
using namespace std;
/**��������������*/
const int E=500000;
const int V=50000;
struct SPFA_Stack {
	/**��������˼�ֱ��ǣ��ڽӱ�ͷ���顢��i�㵽������̾��롢�ڵ���ʿ��Ʒ����ڽӱ����*/
	int head[V],dist[V],visit[V],m;
	/**�ڽӱ�洢�ṹ��*/
    struct node {int to,next,val;}edge[E];
    /**��ʼ�����б���*/
    void init() {
        m=1;
        memset(head,-1,sizeof(head));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=V;i++) dist[i]=inf;
    }
	/**���ڽӱ����һ����*/
    void addedge(int from,int to, nt val) {
        edge[m].to=to;edge[m].val=val;
        edge[m].next=head[from];head[from]=m++;
    }
	/**��u��v�ı߽����ɳڲ������ɹ�����1��ʧ�ܷ���0*/
    int relax(int u,int v,int val) {
        if(dist[v]-dist[u]>val) {
            dist[v]=dist[u]+val;
            return 1;
        }
        return 0;
    }
	/**����SPFA��������*/
    int spfa_sta(int src,int n) {
        int sta[E],top=1;			//����ջ��ջ��ָ��
        sta[0]=src;visit[src]=1;dist[src]=0;			//�����ջ�������������Ϣ
        /**
		 *��ջ��Ϊ��ʱ����ջ��ָ�벻Ϊ0������ջ��Ԫ��ȡ�������������Ϣ
		 *�Ը�Ԫ�ؽڵ����ر߾����Խ����ɳڣ����ɹ��ұ��յ�δ�����ʣ��򽫸��յ���ջ�����������Ϣ
		 *��ջ��ʱ�˳��������յ��distֵ
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
