#include<bits/stdc++.h>
using namespace std ;
#define MAX 205
inline int readInt()
{
    int ip = getchar_unlocked(), ret = 0, flag = 1;

    for(; ip < 48 || ip > 57; ip = getchar_unlocked())
    {
        if(ip == 45)
        {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }

    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}

// Edmond-karp dont work. Dinic code from from stanford library
const int INF = 1<<30;

struct Edge {
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap) {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail) {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0) {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if (!e) {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

int main(){

    int cases , caseno =1 ;
    scanf("%d",&cases );

    while( cases -- ){

        int N , M ;
        scanf("%d%d",&N,&M ) ;
        int w ;
        int source = 0 ;
        int sink = 204 ;

        Dinic F(205);
        int UP[205] ;
        int DOWN[205] ;
        for( int i = 0 ; i < N ; i++ ){
            UP[i+1] = readInt();
        }
        for( int i = 0 ; i < N ; i++ ){
            DOWN[i+1] = readInt();
        }
        for( int i = 0 ; i < N ; i++ ){
            w = readInt();
            if( w == 1 ){
                F.AddEdge(source,i+1,UP[i+1]);
                F.AddEdge(i+1,sink,1<<30);
            }else if( w == -1 ){
                F.AddEdge(source,i+1,1<<30);
               F.AddEdge(i+1,sink,DOWN[i+1]);
            }else {
                F.AddEdge(source,i+1,UP[i+1]);
                F.AddEdge(i+1,sink,DOWN[i+1]);
            }
        }
        int a , b , c ;
        for( int i = 0 ; i < M ; i++ ){
            a = readInt() ;
            b = readInt() ;
            c = readInt() ;
            F.AddEdge(a,b,c) ;
            F.AddEdge(b,a,c) ;
        }
        cout << "Case " << caseno++ << ": " << F.GetMaxFlow(source,sink) << "\n" ;
    }
    return 0 ;
}

