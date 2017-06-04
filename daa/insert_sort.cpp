#include <iostream>

int main(){
	int size=5;
	int arr[]= {1,4,2,5,3};
	size=sizeof(arr)/sizeof(arr[0]);

	for(int i=1;i<=size;i++){
		temp=arr[i];
		for(int j=i-1;j>0;--j){
			if(arr[j]>temp){
				arr[j+1]=arr[j];
			}
			else{
				break;
			}
			arr[j+1]=temp;
		}
	}
	
}
