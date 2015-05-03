#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/**������*/
const int N=100000;
struct Kruskal_CS_PQ {
    /**
     *��������˼�ֱ��ǣ�
     *���鼯���飬��С�������߼����飬�������߼�����
     *�Ѿ��ҵ��ı߼�����MST���������MST��Ȩ
     */
    int father[N],minTree[N],n,cnt,count,index,minV;
    /**�ߴ洢�ṹ��*/
    struct node {
        int id,to,from,val;
        bool operator < (const node& a) const {return val>a.val;}
    }edge[N];
    /**���ȼ�����*/
    priority_queue<node> que;
    /**��ʼ�����б���*/
    void init() {
        n=index=minV=cnt=0;
        memset(minTree,0,sizeof(minTree));
    }
    /**������ʼ���鼯*/
    void make_set(int n) {
        for(int i=0;i<N;i++) father[i]=i;
    }
    /**���������Ϻϲ�*/
    void union_set(int x,int y) {
        x=find_set(x);y=find_set(y);
        if(x==y) return;
        father[y]=x;
    }
    /**����һ���㵽ĳ������*/
    int find_set(int x) {
        if(father[x]!=x) father[x]=find_set(father[x]);
        return father[x];
    }
    /**����һ���ߣ������뵽���ȼ�������*/
    void addedge(int from,int to,int val) {
        edge[cnt].to=to;edge[cnt].val=val;
        edge[cnt].from=from;edge[cnt].id=cnt++;
        que.push(edge[cnt-1]);
    }
    /**
     *Kruskal�㷨��������ÿ��ѡȡ���ȼ������м�����ߵıߣ�
     *�ж��Ƿ�ɻ�����ɻ����������������ɻ������MST�У��ϲ����鼯
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
