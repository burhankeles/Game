#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
char position[20][30] = { };
int a = 0, b = 0;
int i_tree = 0;
int i_enemy = 0;
char move;
int i_ctr = 0;
void prepareDisplayMatrix(char displayMatrix[20][30]){
	int row,col;
	for(row =0 ; row<20; row++){
		for(col = 0; col<30; col++){
			displayMatrix[row][col] = -78;
		}
	}
	for(row =0 ; row<2; row++){
		for(col = 0; col<2; col++){
			displayMatrix[row][col] = -80;
		}
	}
	displayMatrix[0][0] = 'P';
}
void preparePlacementMatrix(char placementMatrix[20][30]){
	int row,col,i_rand_1,i_rand_2,i_rand_3,i_rand_4,i1 = 0,i2 = 0;	
	for(row =0 ; row<20; row++){
		for(col = 0; col<30; col++){
			placementMatrix[row][col] = ' ';
		}
	}
	srand(time(0));
	i_tree = (rand()%4)+1;
	srand(time(0));
	i_enemy = (rand()%4)+1;
	i_ctr = i_enemy;
	do{
		i_rand_1 = rand()%20;
		i_rand_2 = rand()%30;
		placementMatrix[i_rand_1][i_rand_2] = 'T';
		i1++;
	}while(i_rand_1 != 0 && i_rand_1 != 1 && i_rand_2 != 0 && i_rand_2 != 1 && i_tree);
	do{
		i_rand_1 = rand()%20;
		i_rand_2 = rand()%30;
		i2++;
		placementMatrix[i_rand_1][i_rand_2] = 'E';
	}while(i_rand_1 != 0 && i_rand_1 != 1 && i_rand_2 != 0 && i_rand_2 != 1 && placementMatrix[i_rand_1][i_rand_2] != 'T' && i2<=i_tree);		
}
void prepareTheGame(char displayMatrix[20][30],char placementMatrix[20][30]){
	prepareDisplayMatrix(displayMatrix);
	preparePlacementMatrix(placementMatrix);
}
void fightWithTheEnemy(char placementMatrix[20][30],char displayMatrix[20][30]){
	if(move == 'h'){
		int r,c,i_ctr = 0;;
		for(r = -1; r<2; r++){
			for(c=-1;c<2;c++){
				if(placementMatrix[a+r][b+c] == 'E' && i_ctr!=1){
					placementMatrix[a+r][b+c] = ' ';
					displayMatrix[a+r][b+c]= -80;
					i_ctr--;
					system("CLS");
				}
			}
		}
	}
}
void updateDisplayMatrix(char displayMatrix[20][30],char placementMatrix[20][30]){
	int r,c;
	if(move == 'w'){
		if(placementMatrix[a-1][b] == ' ' && 0 <= a-1 < 20){
			for(r = -3; r<4; r++){
				for(c=-3;c<4;c++){
						if(0 <= a+r && a+r < 20 && 0 <= b+c && b+c<30 && displayMatrix[a+r][b+c] != 'E' && displayMatrix[a+r][b+c] != 'T')
							displayMatrix[a+r][b+c] = -80;
					}
			}
			a--;
			displayMatrix[a][b] = 'P';
			system("CLS");
		}
		else
				system("CLS");
	}
	else if(move == 'a'){
		if(placementMatrix[a][b-1] == ' '&& 0 <= b-1  && b-1< 30){
			for(r = -3; r<4; r++){
				for(c=-3;c<4;c++){
					if(0 <= a+r && a+r < 20 && 0 <= b+c && b+c<30 && displayMatrix[a+r][b+c] != 'E' && displayMatrix[a+r][b+c] != 'T')
						displayMatrix[a+r][b+c] = -80;	
				}
			}
				b--;
				displayMatrix[a][b] = 'P';
				system("CLS");
			
		}
		else
				system("CLS");
	}
	else if(move == 'd'){
		if(placementMatrix[a][b+1] == ' '  && 0 <= b+1  && b+1< 30){
			for(r = -3; r<4; r++){
				for(c=-3;c<4;c++){
						if(0 <= a+r && a+r < 20 && 0 <= b+c && b+c<30 && displayMatrix[a+r][b+c] != 'E' && displayMatrix[a+r][b+c] != 'T')
							displayMatrix[a+r][b+c] = -80;
					}
			}
				b++;
				displayMatrix[a][b] = 'P';
				system("CLS");
		}
		else
				system("CLS");
	}
	else if(move == 's'){
			if(placementMatrix[a+1][b] == ' '  &&0 <= a+1 < 20){
			for(r = -3; r<4; r++){
				for(c=-3;c<4;c++){
					if(0 <= a+r && a+r < 20 && 0 <= b+c && b+c<30 && displayMatrix[a+r][b+c] != 'E' && displayMatrix[a+r][b+c] != 'T')	
						displayMatrix[a+r][b+c] = -80;		
				}
			}
				a++;
				displayMatrix[a][b] = 'P';
				system("CLS");
			}
			else
				system("CLS");
	}
	else
		system("CLS");
}
void display(char displayMatrix[20][30],char placementMatrix[20][30]){
	int row,col;
	for(row =0 ; row<20; row++){
		for(col = 0; col<30; col++){
			printf("%c",displayMatrix[row][col]);
			if(displayMatrix[row][col] != -78){
					if(placementMatrix[row][col] != ' '){
						displayMatrix[row][col] = placementMatrix[row][col];
				}
			}
		}
		printf("\n");
	}
}
void displayGodMode(char displayMatrix[20][30],char placementMatrix[20][30]){
	int row,col;
	for(row =0 ; row<20; row++){
		for(col = 0; col<30; col++){
					if(placementMatrix[row][col] != ' '){
						displayMatrix[row][col] = ' ';
						printf("%c",placementMatrix[row][col]);
				}
					else{
						displayMatrix[row][col] = -80;
						printf("%c",displayMatrix[row][col]);
					}
			}
			printf("\n");
		}
		
}
void update(char displayMatrix[20][30],char placementMatrix[20][30]){
	display(displayMatrix,placementMatrix);
	move = getch();
	while(move != 'q'){
		move = getch();
		fightWithTheEnemy(placementMatrix,displayMatrix);
		updateDisplayMatrix(displayMatrix,placementMatrix);
		if(move == 'c'){
			displayGodMode(displayMatrix,placementMatrix);
			
		}
		else{
			display(displayMatrix,placementMatrix);
		}
	}
}
int main(){
	char placementMatrix[20][30],displayMatrix[20][30];
	prepareTheGame(displayMatrix,placementMatrix);
	update(displayMatrix,placementMatrix);
	return 0;
}
