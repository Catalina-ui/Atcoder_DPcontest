#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    vector<long long> v(N);
    vector<long long> dp(N + K, 1e9);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    dp[0] = 0;
    

    for (int i = 1; i < N; i++)
    {
        int t = min(i,K);
        for (int j = 0; j < t;j++){
            dp[i] = min(dp[i], dp[i - j - 1] + abs(v[i] - v[i - j - 1]));
        }
    }
    cout << dp[N - 1] << endl;
    return 0;
}
