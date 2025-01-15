#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin>> a>>b;

    int temp1  = a %10;
    int temp2 = b %10;

    if(temp1 > temp2){
        cout<< b<< " < "<< a<< "\n";
    }else if(temp2 > temp1){
        cout<< a << " < "<< b<<"\n";
    }else{
        temp1 = a % 100;
        temp2 = b % 100;
        if(temp1 > temp2){
            cout<< b<< " < "<< a<< "\n";
        }else if(temp2 > temp1){
            cout<< a << " < "<< b<<"\n";
        } else{
            temp1 = a % 1000;
            temp2 = b % 1000;
            if(temp1 > temp2){
                cout<< b<< " < "<< a<< "\n";

            }else if(temp2 > temp1){
                cout<< a << " < "<< b<<"\n";
            } else{
                cout<< a << " = "<< b<<"\n";
            }
        }

    }
    return 0;
}
