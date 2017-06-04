#include <iostream>

template<typename T>
void gnome_sort(T arr[]){
	int pos =0;
	while(pos ==0 || arr[pos]>=a[pos-1]){
		pos=pos+1;
	}
	else{
		int tmp=arr[pos];
		arr[pos]=arr[pos-1];
		arr[pos-1]=pos;
		pos-=1;
	}

}

int main(){
	int arr[5]={ 2,1,3,5,2 };
	snome_sort(arr);
	for(int i =0; i < 5;i++){
		std::cout << arr[i] << std::endl;
	}

}
