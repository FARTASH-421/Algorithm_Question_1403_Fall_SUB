#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> data(n,0);
    vector<long long > dp(n,0);
    for(int i=0; i<n; i++) cin>>data[i];

    dp[n-1] = data[n-1];
    for(int i=n-2; i>-1; i--){
        if(data[i] < data[i+1]){
            dp[i] = data[i] + (dp[i+1]-data[i]) + 1;
        }else{
            long long temp = data[i]-dp[i+1];
            if(temp>0){
                dp[i] = dp[i+1] + temp;
            }else if(temp<0){
                dp[i] = dp[i+1]+1;
            }else{
                dp[i] = dp[i+1];
            }
        }
    }

    cout<<dp[0]<<endl;
    return 0;
}
