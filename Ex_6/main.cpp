#include <bits/stdc++.h>
using namespace std;
int calculateSwaps(vector<int>& mydata, int n) {

    int result = 0;
    int index_L = 0, index_R = n - 1;

    while (index_L < index_R) {
        if (index_L + 1 == index_R) {
            if (mydata[index_L] == mydata[index_R]) {
                result++;
                break;
            }
        } else {

            int v1 = 0;
            if (mydata[index_L] == mydata[index_L + 1]) v1++;
            if (mydata[index_R] == mydata[index_R - 1]) v1++;

            int v2 = 0;
            if (mydata[index_L] == mydata[index_R - 1]) v2++;
            if (mydata[index_R] == mydata[index_L + 1]) v2++;

            result += min(v1, v2);
        }

        index_L++;
        index_R--;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ifstream inputFile("D:\\Private\\Class Term 8\\Algorithm\\EX6\\input13.txt");
    ofstream outputFile("D:\\Private\\Class Term 8\\Algorithm\\EX6\\output.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }


    int t;
    inputFile >> t;
//    cout<<t<<endl;
    //cin>>t;
    while (t--) {
        int n;
        inputFile >> n;
        //cin>>n;
//        cout<<n<<endl;
        vector<int> a(n);
        int counter = 0;
        inputFile >> a[0];
        for (int i = 1; i < n; ++i) {
            inputFile >> a[i];
            if (a[i] == a[i-1]) counter++;
//            cout<<a[i]<<", ";
        }

        if (counter == 0) {
            outputFile << "0\n";
        } else {

            outputFile <<calculateSwaps(a, n)<<"\n";
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
