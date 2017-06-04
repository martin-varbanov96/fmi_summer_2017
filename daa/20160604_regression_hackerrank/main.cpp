#include <iostream>


template<typename T>
T get_reg_eq(T x[], T y[], int n, T x_test){
    T mu_x=0;
    T mu_y=0;
    for(int i =0; i < n; i++){
        mu_x+=x[i];
        mu_y+=y[i];
    }
    mu_x /= n;
    mu_y /= n;
    
    T comp_chisl = 0;
    T comp_znam =0;
    
    for(int i=0; i < n; i++){
       comp_chisl = (x[i]-mu_x)*(x[i]-mu_x);
       comp_znam =(y[i]-mu_y)*(x[i]-mu_x);
    }
    T b_1=comp_chisl/comp_znam;
    T b_0=mu_y-(b_1*mu_y);
    return b_0+(b_1*mu_x);
}

int main() {
    double x_test=80;
    int n=5;
    
    double x[n];
    double y[n];
    
    for(int i =0; i < n; i++) std::cin >> x[i]; 
    for(int i =0; i < n; i++) std::cin >> y[i]; 
    
    
    std::cout << get_reg_eq(x, y, n , x_test) << std::endl;
   
    return 0;
}

