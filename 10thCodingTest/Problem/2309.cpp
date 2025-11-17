
// 2309  일곱 난쟁이 문제 
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

///9명의 입력값을 받는다
///그중 7명의 합이 100이 되는 경우를 찾는다.
/// 9C7 조합 확인하면 될듯

int n = 9;

vector<int> v(n);
vector<int> selected;

void combination(int start, int depth) {
    if (depth == 7) {
        int sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += selected[i];
        }
        if (sum == 100) {
            for (int i = 0; i < 7; i++) {
                cout << selected[i] << '\n';
            }
            exit(0);
        }
        return;
    }
    
    for (int i = start; i < n; i++) {
        selected.push_back(v[i]);
        combination(i + 1, depth + 1);
        selected.pop_back();
    }
}

// 순열을 이용해서 푸는 방법
int main()
{
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    do
    {
        int sum =0;
        for (int i=0; i<7; i++)
        {
            sum += v[i];
        }
        if (sum == 100)
        {
            for (int i=0; i<7; i++)
            {
                cout << v[i] << '\n';
            }
            return 0;
        }
        
    }while (next_permutation(v.begin(), v.end()));


    // //=조합 
    // sort(v.begin(), v.end());
    //
    // combination(0, 0);
}