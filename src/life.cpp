#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include "life.h"

#define ALIVE true
#define DEAD false
#define T 100

const int GRIDSIZE = 50;

using namespace std;


Grid::Grid() {
    for( int i=0; i < GRIDSIZE; i++)
        for( int j=0; j < GRIDSIZE; j++){
                grid[i][j] = DEAD;
    }
    stable = false;
    generation = 1;


   // grid[24][20] = ALIVE;
    grid[2][2] = ALIVE;
    grid[3][3] = ALIVE;
    grid[3][6] = ALIVE;
    grid[4][4] = ALIVE;
    grid[2][6] = ALIVE;
    //grid[4][8] = ALIVE;
    //grid[4][9] = ALIVE;
    //grid[4][7] = ALIVE;
    //grid[5][6] = ALIVE;

}

void Grid::printFrame() {
    printf("\n **  GENERATION : %d  ** \n\n", this -> generation);
    for( int i = 0; i < GRIDSIZE; i++) {
        for( int j = 0; j < GRIDSIZE; j++) {
            if( this -> grid[i][j]){
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


void Grid::nextFrame() {

	int numSurrounding = 0, tmpcounter=0;
	bool tempGrid [GRIDSIZE][GRIDSIZE];

	for ( int i = 0; i < GRIDSIZE ; i++) {
		for ( int j = 0; j < GRIDSIZE ; j++) {
			if ( ( i + 1) < GRIDSIZE && this -> grid[i + 1][j] == true ) {
				numSurrounding++;
			}
			if ( (i-1) >= 0 && this -> grid[i - 1][j] == true ) {
				numSurrounding++;
			}
			if ( (j+1) < GRIDSIZE && this -> grid[i][j+1] == true ) {
				numSurrounding++;
			}
			if ( (j-1) >= 0 && this -> grid[i][j-1] == true ) {
				numSurrounding++;
			}
			if ( (i+1) < GRIDSIZE && (j+1) < GRIDSIZE && this -> grid[i+1][j+1] == true ) {
				numSurrounding++;
			}
			if ( (i+1) < GRIDSIZE && (j-1) >= 0 && this -> grid[i+1][j-1] == true ) {
				numSurrounding++;
			}
			if ( (i-1) >= 0 && (j+1) < GRIDSIZE && this -> grid[i-1][j+1] == true ) {
				numSurrounding++;
			}
			if ( (i-1) >= 0 && (j-1) >= 0 && this -> grid[i-1][j-1] == true ) {
				numSurrounding++;
			}

			if (numSurrounding < 2 || numSurrounding > 3) {
				tempGrid[i][j] = false;
			}
			else if ( numSurrounding == 2) {
				tempGrid[i][j] = this -> grid[i][j];
			}
			else if ( numSurrounding == 3) {
				tempGrid[i][j] = true;
			}

			numSurrounding = 0;

		}
	}

	for ( int i = 0 ; i < GRIDSIZE ; i++ ) {
		for ( int j = 0 ; j < GRIDSIZE ; j++ ) {
            if (this -> grid[i][j] != tempGrid[i][j]) {
                tmpcounter = 1;
            }

			this -> grid[i][j] = tempGrid[i][j];
		}
	}
	this -> generation++;
	if(tmpcounter == 0)
        this -> stable = true;
}
bool Grid::isExtinct() {
    for(int i = 0; i < GRIDSIZE; i++)
        for( int j = 0; j < GRIDSIZE; j++)
            if( this -> grid[i][j])
                return false;
    return true;
}
bool Grid::isStable() { return this->stable; }


void Grid::play(){
    int generation;
    printf( " \n\n  FIRST GENERATIOM :- (Press ENTER to let the life begin)\n\n");
    this -> printFrame();
    getch();

    while(1) {
        system("CLS");
        this -> printFrame();
        Sleep(T);
        this -> nextFrame();
        if( this -> isExtinct()) {
            system("CLS");
            printf("\n\n\n\n                           *******************\n                 ALL THINGS CREATED MUST END SOMEDAY!\n                       *******************\n\n\n\n\n\n");
            printf("\n\n\n      Total generations till extinction : %d \n\n\n\n\n\n", (this -> generation)-1);

            break;
        }
        if(this -> isStable()) {
            system("CLS");
            printf("\n\n\n\n                   *******************\n                 AND THE LIFE IS STAGNANT AFTER %d GENERATIONS!  \n                   *******************\n\n\n\n\n\n", this -> generation);
            this -> printFrame();
            getch();
            break;
        }

    }
}


int main() {
    Grid life;
    life.play();
    return 0;
}
