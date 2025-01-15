#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareInterval(long first, long second){
    return (first > second);
}
int main(){
    long n, k;
    long myMax = 0;

    cin>>n >>k;
    vector<long> myData(k+1,0);

    long index, input;
    for (long i = 0; i < k ; ++i) {
        cin>>index>>input;
        myData[index] = input + myData[index];
    }

    sort(myData.begin(), myData.end(), compareInterval);

    int i=0;
    for(auto x: myData){
        myMax += x;
        i++;
        if(i >= n) break;
    }

    cout<<myMax<<endl;
    return 0;
}