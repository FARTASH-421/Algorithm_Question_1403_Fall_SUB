#include <bits/stdc++.h>
using namespace std;

int checkLtoR(vector<int>& mydata, int index_R, int index_L){
    int countF = 0;
    if (mydata[index_L] == mydata[index_L + 1]) countF++;
    if (mydata[index_R] == mydata[index_R - 1]) countF++;

    int countS = 0;
    if (mydata[index_L] == mydata[index_R - 1]) countS++;
    if (mydata[index_R] == mydata[index_L + 1]) countS++;

    return min(countF, countS);
}

int myFound(vector<int>& mydata, int n) {
    int result = 0;
    int index_L = 0, index_R = n - 1;

    while (index_L < index_R) {
        if (index_L + 1 == index_R) {
            if (mydata[index_L] == mydata[index_R]) {
                result++;
                break;
            }
        } else {
            result += checkLtoR(mydata, index_R, index_L);
        }

        index_L++;
        index_R--;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i= 0; i< t; i++){
        int n;
        cin >> n;
        vector<int> mydata(n);
        int counter = 0;
        cin>> mydata[0];
        for (int j = 1; j< n; j++) {
            cin >> mydata[j];
            if (mydata[j] == mydata[j-1]) counter++;
        }

        if(counter==0){
            cout<<"0\n";
        }else{

            int result = myFound(mydata, n);
            cout << result << endl;
        }
    }
    return 0;
}
