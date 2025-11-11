#include <iostream>
#include <vector>

using namespace std;

 
bool visited[101][101];
int adj[101][101];
int n,m;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
void DFS(int sy, int sx)
{
    visited[sy][sx] = 1;

    //4 방향 탐색
    for (int i=0; i<4; i++)
    {
        int ny = sy + dy[i];
        int nx = sx + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (adj[ny][nx] == 0) continue;
        if (visited[ny][nx]) continue;
        DFS(ny, nx);
    }
}

int main()
{
    memset(visited, false, sizeof(visited));
    memset(adj, 0, sizeof(adj));
    
    cin>>n>>m;    

    for (int i =0; i< n;i++)
    {
        for (int j =0; j<m;j++)
        {
            cin>> adj[i][j];
        }
    }

    // Component사용 해야할꺼 같다
    // 그리고 조밀해서 인접 행렬

    int cnt =0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (adj[i][j] == 0) continue;
            if (visited[i][j]) continue;
            DFS(i, j);
            cnt ++; 
        }
    }
    cout<<cnt<<'\n';

    
}
