#include <iostream>



//input arr and size output int which is the razdelena razlika thing
/*
double razd_razl(double arr_x[],  int size_x, double arr_f[], int size_f){
	double bigger[size_x-1];
	double  smaller[size_x-1];

	double bigger_f[size_f-1];
	double  smaller_f[size_f-1];
	
	if(size_x==1){
		return arr_f[0];
	}	
	for(int i =0;i<size_x-1;i++){
		smaller[i]=arr_x[i];
		bigger[i]=arr_x[i+1];
	
		smaller_f[i]=arr_f[i];
		bigger_f[i]=arr_f[i+1];
	}

	
	
	
	return (   , ,( razd_razl(bigger, size_x-1, bigger_f, size_f-1 ) -  razd_razl( smaller, size_x-1, smaller_f, size_f-1 )  )/(arr_x[size_x]-arr_x[0]));
}
*/



//input arr and size of array and should return int- value of razd razl
template <typename F, typename G>
F razd_razl2( F arr_f[],F arr_x[]  ,G n){
	F result = 0;
	for( int k=0; k <n; k++ ){
		F prod=1;
		for(int i=0;i<n;i++){
			if(i != k){
				prod *= ( arr_x[k] - arr_x[i] );		
			}
		}

		result+= arr_f[k]/prod;		
	}
	return result;
}


int main(){
	int xn[7]= { 2,4,6,8,10,12,14};
	int fxn[7]={2,3,1,2,4,5,2};


	int result = razd_razl2(fxn,xn, 7);	

	std::cout << "result is  = " << result << std::endl;
	return 0;
}
