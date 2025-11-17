#include <iostream>
#include <queue>

using namespace std;


///다익스라 알고리즘
//
// int n , m, s , u ,v, w ;
// vector<int> dist(20004,1e9 );
// vector<pair<int, int>> adj[20004];
//
// void dijkstra(int s)
// {
//     dist[s] = 0;
//     priority_queue<pair<int, int>,vector<pair<int, int>>> pq;
//     pq.push({0, s});
//     while (!pq.empty())
//     {
//         auto p = pq.top();
//         pq.pop();
//         int here_cost = p.first;
//         int u = p.second;
//         if (dist[u] != here_cost) continue;
//         for (auto &p : adj[u])
//         {
//             int new_cost = here_cost + p.second;
//             if (new_cost < dist[p.first])
//             {
//                 dist[p.first] = new_cost;
//                 pq.push({new_cost, p.first});
//             }
//         }
//     }
// }

///플로이드 워셜

// const int INF = 1e9;
// const int MAX_N = 204;
//
// int dist[MAX_N][MAX_N];
//         출발  도착
//
// int main()
// {
//     int n, m;
//     cin>>n >>m;
//     for (int i=1; i<= n; i++)
//     {
//         for (int j=1; j<= n; j++)
//         {
//             if (i == j) dist[i][j] = 0;
//             else dist[i][j] = INF;
//         }
//     }
//     for (int i=0; i<m; i++)
//     {
//         int u,v,w;
//         cin>>u >>v >>w;
//         dist[u][v] = min(dist[u][v],w);
//         
//     }
//     for (int k=1; k<=n; k++)
//     {
//         for (int i=1; i<=n; i++)
//         {
//             for (int j=1; j<=n; j++)
//             {
//                 if (dist[i][k] != INF && dist[k][j] != INF)
//                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//             }
//         }
//     }
// }

//벨만 포드
long long t, n, m, a, b, c, dist[1004], INF = 987654321;

int main()
{
    cin>>n>>m;
    fill(dist,dist+1004, INF); // 초기화
    vector <pair<int,int>> adj[1004]; //인접 리스트
    for (int i=0; i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    dist[1] = 0; // 시작점
    queue<int>q;
    for (int i=0; i<n; i++)
    {
        for(int here = 1; here <= n; here++)
        {
            for ( auto there: adj[i])
            {
                int d = there.second;
                int to = there.first;
                if(dist[here] != INF && dist[here] + d < dist[to])
                    {
                        if(i == n - 1)q.push(to);
                            dist[to] = dist[here] + d; cout << here << " : " << to << "\n"; }
            }

            
        }
       
    }
}
