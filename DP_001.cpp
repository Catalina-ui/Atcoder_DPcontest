#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> v(N);
    vector<long long> dp(N + 2,1e9);
    for (int i = 0; i < N;i++)
        cin >> v[i];

    dp[0] = 0;
    dp[1] = abs(v[0] - v[1]);

    for (int i = 2;i < N;i++){
            dp[i] = min(dp[i], dp[i - 1] + abs(v[i] - v[i - 1]));
            dp[i] = min(dp[i], dp[i - 2] + abs(v[i] - v[i - 2]));
    }
    cout << dp[N-1] << endl;
    return 0;
}
