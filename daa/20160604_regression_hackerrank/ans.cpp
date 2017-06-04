#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double reg(vector<int> x, vector<int> y){    
    //XY
    long xy=0;
    for(int i=0; i<x.size(); i++)
        xy += x[i]*y[i];
    
    // square sum
    long xsq = 0;
    for(int i=0; i<x.size(); i++)
        xsq += x[i]*x[i];
    
    //mean
    long sum1=0;
    for(int i=0; i<x.size(); i++)
        sum1 += x[i];
    double mean1 = double(sum1)/x.size();
    
    long sum2=0;
    for(int i=0; i<y.size(); i++)
        sum2 += y[i];
    double mean2 = double(sum2)/y.size();
    
    // b and a
    double b = (5.0*xy-sum1*sum2)/(5.0*xsq-sum1*sum1);
    double a = mean2 - b*mean1;
    return a+b*80;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> v1;
    vector<int> v2;
    int x,y;
    for (int i=0; i<5; i++){
        cin >> x;
        v1.push_back(x);
        cin >> y;
        v2.push_back(y);
    }
    cout.precision(3);
    double ans=reg(v1,v2);
    cout << fixed << ans; 
    return 0;
}

