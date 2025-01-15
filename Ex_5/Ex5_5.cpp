#include <bits/stdc++.h>
#define ll 1e6
using namespace std;

int main(){
    int n, m;
    string prString, finalString;

    cin>>n>>m;
    cin>>prString>>finalString;

    vector<char> arrF(m);
    vector<char> arrS(m);
    vector<int>  cost(m);

    for(int i=0; i< m; i++) cin>> arrF[i];
    for(int i=0; i< m; i++) cin>> arrS[i];
    for(int i=0; i< m; i++) cin>> cost[i];

    vector<vector<int>> dist(26, vector<int>(26, ll));

    for(int i=0; i<m; i++){
        int indexF = int(arrF[i] - 'a');
        int indexS = int(arrS[i] - 'a');
        dist[indexF][indexS] = cost[i];
    }

    for (int i = 0; i < 26; i++) dist[i][i] = 0;

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][k] < ll && dist[k][j] < ll) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }


    int myCost = 0;
    bool check = true;

    for(int i=0; i< n; i++){
        int indexF = prString[i] - 'a';
        int indexS = finalString[i] - 'a';

        int cst = dist[indexF][indexS];

        if(cst >= ll){
            cout<< -1<<endl;
            check = false;
            break;
        }
        else myCost += cst;

    }

    if(check) cout<<myCost<<endl;

    return 0;
}
