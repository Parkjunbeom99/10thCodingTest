#include<iostream>
#include <vector>
#include <queue>

using namespace std;


int visited[101][101];
int adj[101][101];

int n, m;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main()
{
    cin>>n>>m;
    
    queue<pair<int, int>> q; // q 이번엔 y,x좌표로

    int sx,sy ,ex,ey; // 시작지점과 끝지점 
    cin>>sx>>sy;

    cin>>ex>>ey;


    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin>> adj[i][j];
        }
    }
    q.push({sy, sx});
    visited[sy][sx] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        int cy = cur.first;
        int cx = cur.second;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (visited[ny][nx]) continue;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (adj[ny][nx] == 0) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny, nx});
        }
        
    }

    cout<< visited[ey][ex]<<'\n';
    
    
}