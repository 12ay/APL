#include<iostream>
#include "project2.hxx"
using namespace std;

int main(){
    Bitcoin btc;
    btc.set_values(5000, 3800);
    cout << "Bitcoin's all time high is: $" << btc.ath << endl
        << "The current value is: $" << btc.currVal << endl
        << "The difference is: $" << btc.diff();
    return 0;
}

