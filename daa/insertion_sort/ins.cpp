#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void insertionSort(vector <int>  ar) {
    int curr = ar[ar.size()-1];
    for(int i=ar.size()-2;i >=0;i--){
        if(ar[i]>curr){
            if(i == 0){

		ar[i+1]=ar[i];
                ar[i] = curr;
		for(int j =0; j < ar.size();j++){ cout << ar[j] << " ";}
            	cout << "" << endl;
		return;	
		cout << "adasd" << endl;
            }
            ar[i+1]=ar[i];
            for(int j =0; j < ar.size();j++){ cout << ar[j] << " ";}
            cout << "" << endl;
        }
        else{
            ar[i+1]=curr;
            for(int j =0; j < ar.size();j++){ cout << ar[j] << " ";}
            cout << "" << endl;
            return;
        } 
    }

}
int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }
    insertionSort(_ar);
    return 0;
}
