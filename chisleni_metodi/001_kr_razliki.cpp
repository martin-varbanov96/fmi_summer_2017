#include <iostream>


/*
 *Input:
 f[]-array with f values;
 size_f-length of f array
 x[]=array with x values
 size_x- length of x array
 k-current row
 i-current index for selecting elements from the f or x arrays
OUtPUT:
value with T value
 * */
template<typename T, typename G>
T kr_razl(T f[],G size_f, int k,int i){
	if(k==1){
		return f[i+1]-f[i];
	}
	return kr_razl(f,size_f, k-1,i+1)-kr_razl(f, size_f, k-1,i);
}



/*
 INPUT:
 f- array with the values
 fize_f-length of the f array
 i-index for the f array elemnt 
 k-row for the kr_razl
 h-gap between x points

OUTPUT:
return value of razd_razl from xi->xk
 * */

template<typename T,typename G, typename H, typename J, typename K>
T razd_razl_lema(T f[], G size_f, H i , J  k, K  h){
	int factorial=1;
	for(int j=2;j<=k;j++){
		factorial*=j;
	}
	return ( kr_razl(f, size_f ,k,i)/factorial*( h^k  ) );
}

int main(){
	int f[7]={1,3,2,4,2,3,4};
	int result = razd_razl_lema(f, 7,0,6,2);
	std::cout << result << std::endl;
}
