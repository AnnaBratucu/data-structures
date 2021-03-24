#include <iostream>
#include <queue>
using namespace std;

class Graph {
public:
int N;
int **A;
Graph(int numNodes) {
int i, j;
N = numNodes;
// allocate the adjacency matrix
A = new int*[N];
for (i = 0; i < N; i++)
A[i] = new int[N];
for (i = 0; i < N; i++)
for (j = 0; j < N; j++) A[i][j] = 0;
}
void addEdge(int i, int j) {
A[i][j] = A[j][i] = 1;
}
void removeEdge(int i, int j) {
A[i][j] = A[j][i] = 0; }
~Graph() {
int i;
for (i = 0; i < N; i++) {
delete A[i];
}
delete A;
}
};
int visited[50];
int v1[50],v2[50], k1=0, k2=0;
int bfs(Graph g, int S) {
    std::queue<int> Q;
    int x, y;
    Q.push(S);
    visited[S] = 1;
    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        if(visited[x]%2==0){
            v1[k1]=x;
            k1++;
        }
        else { v2[k2]=x;
               k2++;
        }
        for (y = 0; y < g.N; y++)
            if (g.A[x][y])
                if(visited[y]==0) {
                    visited[y] = visited[x]+1;
                    Q.push(y);
                }
                else if((visited[x]-visited[y])%2==0) return 0;
    }
    for(int i=0; i<g.N; i++)
        if(visited[i]==0)
            return 0;
    return 1;
}

int main()
{
    int nr_nodes, nr_edges, a, b;
    cin>>nr_nodes>>nr_edges;
    Graph g=Graph(nr_nodes);
    for(int i=0; i<nr_edges; i++)
    {
        cin>>a>>b;
        g.addEdge(a-1,b-1);
    }

    if(bfs(g,0)==0)
        cout<<"not bipartite";
    else {
            cout<<"bipartite"<<endl;
            for(int i=0; i<k1; i++)
                cout<<v1[i]+1<<" ";
            cout<<endl;
            for(int i=0; i<k2; i++)
                cout<<v2[i]+1<<" ";
          }

}
