#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
/**������*/
const int N=100000;
/**Ĭ�����*/
const int src=1;
struct Tarjan_direct {
    /**��������˼�ֱ��ǣ�
     *�ڽӱ�ͷ���飬��i�������ĸ�ǿ��ͨ����������ʱ�������Զ����ʱ�����ջ����i����������
     *ջ��ָ�룬�ڽӱ����������������ʱ�������
     *��i�����Ƿ���ջ��
     */
    int head[N],id[N],dfn[N],low[N],s[N],out[N],top,cnt,scnt,index;
    bool visit[N];
    /**�ڽӱ�洢�ڵ�*/
    struct node {int to,next,val;}edge[N];
    /**��ʼ�����б���*/
    void init() {
        index=top=cnt=scnt=0;
        memset(visit,false,sizeof(visit));
        memset(head,-1,sizeof(head));
        memset(dfn,-1,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(s,0,sizeof(s));
    }
    /**���ڽӱ����һ����*/
    void addedge(int from,int to,int val) {
        edge[cnt].to=to;edge[cnt].val=val;
        edge[cnt].next=head[from];head[from]=cnt++;
    }
    /**����tarjan�㷨�����������ݹ飩
     *��һ��u��������ڽӵ�v����
     *1.���vδ�����ʣ������������
     *2.��һ����û���ڽӵ㴦��ʱ���ж�������ʱ����Ƿ���ȣ�
     *  ��Ⱦͽ�ջ�˵�ջ����һ��Ԫ�ص���v������ֱ�ӷ���
     *3.�ж�low[u]��low[v]�Ĵ�С��ϵ��������low[u]=min{low[u],low[v]}
     *4.���v��������λ��ջ��
     *5.�ж�low[u]��dfn[v]�Ĵ�С��ϵ��������low[u]=min{low[u],dfn[v]}
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
    /**����ǿ��ͨ������������
     *�Ա�ͼ�����ÿһ���㶼����һ��ѭ����
     *�ж���ÿһ���ڽӵ��Ƿ��������һ����ͨ����֮�ڣ�id����ֵ��
     *�����ڣ���Ը÷�����visit��Ϊtrue�����г��ߣ�ͬʱout����ֵ��1
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
