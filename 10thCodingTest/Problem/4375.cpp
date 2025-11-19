#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)  
    {
        int remainder = 0;  
        int cnt = 0;        
        
        while (true)
        {
            remainder = (remainder * 10 + 1) % n;
            cnt++;
            
            if (remainder == 0)  
            {
                cout << cnt << endl;
                break;
            }
        }
    }
    return 0;
}