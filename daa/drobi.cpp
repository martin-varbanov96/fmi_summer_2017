#include <iostream>

struct fract{
	int chisl;
	int znam;
	double val;
};

template<typename T>
void sort_drobs(T arr_inp[], int len_arr){
	int pos=0;
	while(pos < len_arr){
		if(pos == 0 || arr_inp[pos] >= arr_inp[pos-1]){
			pos+=1;
		}
		else{
			T tmp=arr_inp[ pos ];
			arr_inp[pos]=arr[pos+1];
			arr_inp[pos+1]=tmp;
		}
	}
}

int main(){
	int n=4;
	fract* arr=new fract[1];
	arr[0].chisl=0;
	arr[0].znam=0;
	arr[0].val=0;
	int size_arr=1;
	fract tmp;
	for(int i =2; i <= n; i++ ){
		for(int j=1;j<i;j++){
			tmp.chisl=j;
			tmp.znam=i;
			tmp.val=j/i;			
			for(int k = 0; k < size_arr; k++){
				if(arr[k].val == tmp.val ){
					break;
				
				}
			}
				size_arr++;
				fract*  temp_arr= new fract[size_arr];
				for(int l=0;l<size_arr-1;l++){
					temp_arr[l]=arr[l];
				}
				delete [] arr;
				arr= temp_arr;
				arr[size_arr-1]=tmp;
			
		}
	}
	for(int i =0; i< 5;i++){
		std::cout << arr[i].chisl << "/" << arr[i].znam << "  ";
	}
	sort_drobs(arr,4);
for(int i =0; i< 5;i++){
		std::cout << arr[i].chisl << "/" << arr[i].znam << "  ";
	}
}	
