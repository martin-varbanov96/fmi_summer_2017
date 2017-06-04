#include <iostream>
#include <memory>

int main(){
   //std::unique_ptr<int> u_ptr(new int);
   std::unique_ptr<double>   p1(new double(3.14));
   std::shared_ptr<double> s_ptr{std::move(p1)};
   std::unique_ptr<double> p2(s_ptr);
}

