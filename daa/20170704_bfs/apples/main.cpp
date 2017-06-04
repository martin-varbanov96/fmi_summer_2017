#include <iostream>


int main(){
	int N=8;
	int M=10;
	int T=2;
	int** arr=new int*[N];
	for(int i=0; i < N; i++){
		arr[i]=new int[M];
		for(int j=0; j < M; j++){
			arr[i][j]=0;
		}
	}
	
	int inputX=4;
	int inputY=8;
	int n=40;


	int izgX[n];
       	int izgY[n];
	izgX[0]=inputX;
	izgY[0]=inputY;


	inputX=2;
	inputY=7;
	
	izgX[1]=inputX;
	izgY[1]=inputY;
	
	int countIzg=2;


	if(inputX > 0 && inputY > 0 && inputX < N && inputY < M){
		izgX[1]=inputX;
		izgY[1]=inputY;
	}

	int tmpX[4];
	int tmpY[4];
	for(int j = 0; j < T;j++){
		for( int i =0;i <= countIzg; i++ ){
			if( izgX[i]-1 >=0 ){
			//	arr[izgX[i]-1][izgY[i]]=1;
				tmpX[0]=izgX[i]-1;
				tmpY[0]=izgY[i];
			}
			if( izgX[i]+1 < N ){
				//arr[izgX[i]+1][izgY[i]]=1;
				tmpX[1]=izgX[i]+1;
				tmpY[1]=izgY[i];
			}
			if(izgY[i]-1 >=  0 ){
				//arr[izgX[i]][izgY[i]-1]=1;      
				tmpX[2]=izgX[i];
				tmpY[2]=izgY[i]-1;
			}
			if(izgY[i]+1 < M ){
				//arr[izgX][izgY[i]+1]=1;
				tmpX[3]=izgX[i];
				tmpY[3]=izgY[i]+1;
			}
		}
			
		for(int i = 0; i < 4; i++){
			if( tmpX[i] >= 0 && tmpY[i] >= 0 && tmpX[i] < N && tmpY[i] <M ){
				izgX[countIzg]=tmpX[i];
				izgY[countIzg]=tmpY[i];
				countIzg++;
			}
		}
	
		for(int i =0; i < 4; i++){
			tmpX[i] = -1;
			tmpY[i] = -1;
		}
	}

	for(int i = 0; i <= countIzg;i++){
		std::cout << izgX[i] << " " << izgY[i] << std::endl;
		//arr[izgX[i]][izgY[i]]=1;
	}

	for(int i =0; i < N; i++){
		for(int j=0; j < M; j++){
			std::cout << arr[i][j] << " " ;
		}std::cout << std::endl;
	}


	return 0;
}
