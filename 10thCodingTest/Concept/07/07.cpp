#include <iostream>
#include <vector>
using namespace std;

int dp[104][2][34], n, m, b[104];

int go (int idx, int tree, int cnt)
{
    if ( cnt< 0) return -1e9;
    if (idx == n) return 0;
    
    int &ret = dp[idx][tree][cnt];
    if (ret != -1) return ret;
    return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}
int main()
{
    memset(dp, -1, sizeof(dp)); cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    // 두 가지 초기 상태(1번 나무에 시작, 2번 나무에 시작) 중 최대 값 출력
    cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
    
}


//경우의 수를 푸는 DP
//그냥 다 더한다고 생각을 하자


int t, n;
int dp[10001];

int main()
{
    dp[0] = 1;  // 이 부분이 빠져있었어요!
    
    cin >> t;
    
    // 1, 2, 3을 순서대로 사용
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 10000; j++) {
            if(j - i >= 0) {
                dp[j] += dp[j - i];
            }
        }
    }
    
    // 결과 출력
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}