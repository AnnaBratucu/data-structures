#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <iostream>
/* http://www.cplusplus.com/reference/queue/queue/   */

template<typename TnodeInfo, typename TedgeInfo>
class Graph {
    public:
        int N;
        char **A;
        TnodeInfo *nodeInfo;
        TedgeInfo **edgeInfo;
Graph(int numNodes) {
            int i, j;

            N = numNodes;

            // allocate the adjacency matrix
            A = new char*[N];
            for (i = 0; i < N; i++)
                A[i] = new char[N];
	    for (i = 0; i < N; i++)
                for (j = 0; j < N; j++) A[i][j] = 0;

            // allocate the array with node information
            nodeInfo = new TnodeInfo[N];

            // allocate the matrix of edge information
            edgeInfo = new TedgeInfo*[N];
            for (i = 0; i < N; i++)
                edgeInfo[i] = new TedgeInfo[N];
        }
void setNodeInfo(int i, TnodeInfo info) {
            nodeInfo[i] = info;
        }

        TnodeInfo getNodeInfo(int i) {
            return nodeInfo[i];
        }

        void addEdge(int i, int j) {
            A[i][j] = 1;
        }
        void removeEdge(int i, int j) {
            A[i][j] = 0; }

        void setEdgeInfo(int i, int j, TedgeInfo info) {
            edgeInfo[i][j] = info; }

        TedgeInfo getEdgeInfo(int i, int j) {
            return edgeInfo[i][j]; }
~Graph() {
            int i;
            for (i = 0; i < N; i++) {
                delete A[i];
                delete edgeInfo[i];
            }
            delete A;
            delete edgeInfo;
            delete nodeInfo;
        }
};
Graph<int, int> g(12);
char* visited;

void dfs(int x) {
    int y;
    printf("%d\n", x);
    visited[x] = 1;

    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs(y);
}
void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
		Q.pop();
        printf("%d\n", x);
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
               Q.push(y);
            }
    }
}
int main() {
    using namespace std;
    int i,n,j,a,b,c;
    cin>>n;
   // g.addEdge(0, 1);    g.addEdge(1, 3);
   // g.addEdge(0, 3);    g.addEdge(5, 3);
   // g.addEdge(3, 6);    g.addEdge(6, 10);
   // g.addEdge(6, 11);    g.addEdge(10, 11);
   // g.addEdge(6, 4);    g.addEdge(2, 6);
    //g.addEdge(7, 2);    g.addEdge(9, 2);
    //g.addEdge(9, 8);    g.addEdge(8, 2);
   // g.addEdge(7, 4);

   // visited = new char[g.N];
   // for (i = 0; i < g.N; i++)
   //     visited[i] = 0;
   // printf("DFS:\n");
   // dfs(7);

   // for (i = 0; i < g.N; i++)
    //    visited[i] = 0;
   //printf("BFS:\n");
   // bfs(3);
   //return 0;
   for(i=0;i<n;i++)


    {cout<<"first street:";
   cin>>a;
   cout<<"second street:";
   cin>>b;
   cout<<"distance:";
   cin>>c;
   g.addEdge(a,b);
   }

}
