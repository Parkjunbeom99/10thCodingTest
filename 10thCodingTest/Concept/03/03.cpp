#include <iostream>
#include <string>
#include <vector>

using namespace std;

//while
int Ralo(int n , const string& s )
{
    int i =2400;
    int cnt =0;
    while (true)
    {
        string a = to_string(i);
        if (s.find("2400") != string::npos)
        {
            if (n == cnt)
            {
                cout<<a<<endl;
                break;
            }
        }
        cnt++;
        i++;
    }
    return cnt;
    
}

//재귀
bool PrimeNumber(int n)
{
    if (n<=1)return false;
    if (n == 2) return true;
    if (n%2 == 0) return false;

    for (int i= 3; i* i <= n; i+=2)
    {
        if (n % i == 0) return false;
    }
    return true;
    
}
int Solution(const vector<int>& v, int d, int sum)
{
    int token =1;
   
    if (!PrimeNumber(sum))
    {
   
        int s = sum + v[d];  
        token += Solution(v, d+1, s);
        token += Solution(v, d+1, sum); 
        
    }
    else
    {
        return token;
    }
    return token;
    
}

//가지치기

int ret, n , cnt;
vector<int> v;
 void go(int idx, int sum, int mod)
{
    if (ret == 10) return; // 가지치기 차피 모드가 11이면 최대는 10이여서 
     if (idx == n)
     {
         ret = max(ret, sum % mod);
         cnt++;
         return;
         
     }
     go(idx+1,sum+v[idx],mod);
     go(idx+1,sum,mod);
     
}


//원복

int map[3][3] =
 {
  {10,20,21},
     {70,90,12},
     {80,110,120}
 };

int visited[3][3];
const int dy[] = {-1, 0, 1, 0}; 
const int dx[] = {0, 1, 0, -1};

 void Print()
 {
     for(int i : v) cout << i << " ";
     cout << '\n';
 }

void DFS(int sy, int sx)
{
    if (sy == 2 && sx ==2)
    {
        Print();
        return;
    }
     for (int i=0; i<4; i++)
     {
         int ny = sy + dy[i];
         int nx = sx + dx[i];
         if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3) continue;
         if (visited[ny][nx]) continue;
         //완복 과정 -> 넣고
         visited[ny][nx] = 1;
         v.push_back(map[ny][nx]);
         DFS(ny, nx);
         //완복 과정 -> 빼고
         visited[ny][nx] = 0;
         v.pop_back();
     }
}