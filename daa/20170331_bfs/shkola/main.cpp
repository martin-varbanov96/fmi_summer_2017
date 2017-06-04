#include <iostream>
#include <queue>

template<typename T, typename F>
class matrix{
private:
	F size;
	T** data;
public:
	matrix(T inputSize){
		size=inputSize;
		data = new T*[size];
		for(int i=0; i < size; i++ ){
			data[i]=new T[size]; 
			for(int j = 0; j < size;j++){
				data[i][j]=0;
			}
		}
	}
	/*
	matrix(F tmpSize=0,T** tmpArr=NULL){
		for( int i=0; i < tmpSize; i++ ){
			delete data[i];
			data[i]=new T[tmpSize];
			for(int j =0;i<tmpSize;j++){
				if(tmpArr[i][j]){
					data[i][j]=tmpArr[i][j];
				}
			}
		}
	}

	*/
	~matrix(){

		for(int i =0; i < size; i++){
			delete data[i];
		}
		delete[] data;
	
	}
	void bfs(){
		return;	
	}
	void print(){
		for(int i =0; i < size;i++){
			for(int j=0;j < size; j++){
				std::cout << data[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}


};

int main(){
	int n=5;
	int** arr=new int*[n];
	for(int i =0 ; i < n; i++){
		arr[i]=new int[n];
		for(int j=0; j<n;j++ ){
			arr[i][j]=j;
		}
	}
	matrix< int, int > a(n);
	a.print();
	return 0;
}
