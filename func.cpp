#include "func.h"
using namespace std;



void printmmat(int mat[3][3]){
	system("cls");
	printf("\n");
	for(int i=0;i<3;i++){
		printf(" ");
		for(int j=0;j<3;j++){
			printf(" ");
			if(mat[i][j] == 1){printf("X");}
			else if(mat[i][j] == 2){printf("O");}
			else{printf(" ");}
			if(j != 2){printf(" %c",179);}
		}
		printf("\n");
		if(i != 2){printf(" %c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,197,196,196,196,197,196,196,196);}
		else{printf("\n\n");}
	}
}

bool checkwin1(int mat[3][3]){
	for(int i=0;i<3;i++){
		if((mat[i][0] == 1)and(mat[i][1] == 1)and(mat[i][2] == 1)){
			return true;
		}
	}
	for(int j=0;j<3;j++){
		if((mat[0][j] == 1)and(mat[1][j] == 1)and(mat[2][j] == 1)){
			return true;
		}
	}
	if((mat[0][0] == 1)and(mat[1][1] == 1)and(mat[2][2] == 1)){
		return true;
	}
	if((mat[2][0] == 1)and(mat[1][1] == 1)and(mat[0][2] == 1)){
		return true;
	}
	return false;
}

bool checkwin2(int mat[3][3]){
	for(int i=0;i<3;i++){
		if((mat[i][0] == 2)and(mat[i][1] == 2)and(mat[i][2] == 2)){
			return true;
		}
	}
	for(int j=0;j<3;j++){
		if((mat[0][j] == 2)and(mat[1][j] == 2)and(mat[2][j] == 2)){
			return true;
		}
	}
	if((mat[0][0] == 2)and(mat[1][1] == 2)and(mat[2][2] == 2)){
		return true;
	}
	if((mat[2][0] == 2)and(mat[1][1] == 2)and(mat[0][2] == 2)){
		return true;
	}
	return false;
}

void decideX(int mat[3][3],const int &i,int &r,int &c){
	srand(time(NULL));
	if(i == 1){r=1;c=1;return;}
	else if(i == 5){
		for(int a=0;a<3;a++){
			for(int b=0;b<3;b++){
				if(mat[a][b] == 0){
					r=a;c=b;
					return;
				} 
			}
		}
	}
	else if(i==2){
		//diagonal
		if((mat[0][0]==2)or(mat[2][2]==2)){
			int p = rand()%2;
			if(p==0){r=0;c=2;return;}
			else{r=2;c=0;return;}
		}
		else if((mat[0][2]==2)or(mat[2][0]==2)){
			int p = rand()%2;
			if(p==0){r=0;c=0;return;}
			else{r=2;c=2;return;}
		}
		//adjacent
		else if((mat[0][1]==2)or(mat[2][1])){
			int p = rand()%2;
			if(p==0){r=1;c=0;return;}
			else{r=1;c=2;return;}
		}
		else if((mat[1][0]==2)or(mat[1][2])){
			int p = rand()%2;
			if(p==0){r=0;c=1;return;}
			else{r=2;c=1;return;}
		}
	}
	else if(i==3){
		//diagonal free win
		if((mat[0][2]==1)and(mat[2][0]==0)){r=2;c=0;return;}
		else if((mat[0][2]==0)and(mat[2][0]==1)){r=0;c=2;return;}
		else if((mat[0][0]==1)and(mat[2][2]==0)){r=2;c=2;return;}
		else if((mat[0][0]==0)and(mat[2][2]==1)){r=0;c=0;return;}
		//centre adjacent free win
		else if((mat[1][2]==1)and(mat[1][0]==0)){r=1;c=0;return;}
		else if((mat[1][0]==1)and(mat[1][2]==0)){r=1;c=2;return;}
		else if((mat[0][1]==1)and(mat[2][1]==0)){r=2;c=1;return;}
		else if((mat[2][1]==1)and(mat[0][1]==0)){r=0;c=1;return;}
		//between 2 O's
		else if((mat[0][0]==2)and(mat[0][2]==2)){r=0;c=1;return;}
		else if((mat[0][2]==2)and(mat[2][2]==2)){r=1;c=2;return;}
		else if((mat[2][2]==2)and(mat[2][0]==2)){r=2;c=1;return;}
		else if((mat[2][0]==2)and(mat[0][0]==2)){r=1;c=0;return;}
		//far corner diagonal to 2 O's
		else if((mat[1][0]==2)and(mat[0][1]==2)){r=2;c=2;return;}
		else if((mat[0][1]==2)and(mat[1][2]==2)){r=2;c=0;return;}
		else if((mat[1][2]==2)and(mat[2][1]==2)){r=0;c=0;return;}
		else if((mat[2][1]==2)and(mat[1][0]==2)){r=0;c=2;return;}
	}
	else if(i==4){
		//centre adjacent free win
		if((mat[1][2]==1)and(mat[1][0]==0)){r=1;c=0;return;}
		else if((mat[1][0]==1)and(mat[1][2]==0)){r=1;c=2;return;}
		else if((mat[0][1]==1)and(mat[2][1]==0)){r=2;c=1;return;}
		else if((mat[2][1]==1)and(mat[0][1]==0)){r=0;c=1;return;}
		//diagonal/adjacent guarantee win(diagonal)
		else if((mat[0][2]==1)and(mat[2][0]==0)){r=2;c=0;return;}
		else if((mat[0][2]==0)and(mat[2][0]==1)){r=0;c=2;return;}
		else if((mat[0][0]==1)and(mat[2][2]==0)){r=2;c=2;return;}
		else if((mat[0][0]==0)and(mat[2][2]==1)){r=0;c=0;return;}
		//diagonal/adjacent guarantee win(adjacent)
		else if((((mat[0][0]==1)and(mat[0][1]==1))or((mat[2][2]==1)and(mat[1][2]==1)))and(mat[0][2]==0)){r=0;c=2;return;}
		else if((((mat[0][0]==1)and(mat[1][0]==1))or((mat[2][2]==1)and(mat[2][1]==1)))and(mat[2][0]==0)){r=2;c=0;return;}
		else if((((mat[0][2]==1)and(mat[0][1]==1))or((mat[2][0]==1)and(mat[1][0]==1)))and(mat[0][0]==0)){r=0;c=0;return;}
		else if((((mat[0][2]==1)and(mat[1][2]==1))or((mat[2][0]==1)and(mat[2][1]==1)))and(mat[2][2]==0)){r=2;c=2;return;}
		//centre adjacent win/draw
		else if((mat[0][1]==2)or(mat[2][1])){
			int p = rand()%2;
			if(p==0){r=1;c=0;return;}
			else{r=1;c=2;return;}
		}
		else if((mat[1][0]==2)or(mat[1][2])){
			int p = rand()%2;
			if(p==0){r=0;c=1;return;}
			else{r=2;c=1;return;}
		}
	}
}





