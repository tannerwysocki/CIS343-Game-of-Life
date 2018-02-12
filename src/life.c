/***********************************************************************
 *  An implementation of Conway's Game of Life using double pointers to 
 *  manage the board. 
 *
 *  @author:    Tanner Wysocki
 *  @date       2018-02-03 22:32
 **********************************************************************/

#include "../include/file_utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void play_move(char**,int,int);

int main(int argc, char** argv){

  //Checks for valid argument count
  if(argc > 3 || argc < 3){

    printf("Invalid command.");
    return 1;

  }
  //The user input amount of rows and columns
  int r = atoi(argv[1]), c = atoi(argv[2]);
  //Holds the menu option for the game
  char option;
  //2D array for our game world
  char** board = (char**)malloc(r*c*sizeof(char*));
  int i,j,placeCell;
  srand(time(NULL));
  //Initializes the board with some random cell placements
  //Each index has a 25% chance of getting a cell.
  for(i = 0; i < r; i++){
   
    board[i] = (char*)malloc(r*c*sizeof(char));
    for(j = 0; j < c; j++){
      
      placeCell = rand()%4+1;
      if(placeCell == 4){

        board[i][j] = '*';

      }
      else{  
       
        board[i][j] = '-';
      
      }  
      printf("%c  ",board[i][j]);
   
    }
    printf("\n");

  }
  //Loops until the user decides to quit
  printf("Welcome to Conway's Game of Life!\n");
  while(1){
    
    printf("Would you like to (c)ontinue, (s)ave, (l)oad, or (q)uit? ");
    scanf(" %c",&option);
    //The text file to be written to
    FILE* save;
    int status;
    //Our "menu"
    switch(option){
    
	//Plays one turn if chosen and prints the board
	case('c'):
        play_move(board,r,c);
        for(i = 0; i < r; i++){
          for(j = 0; j < c; j++){
            printf("%c  ",board[i][j]);
          }
          printf("\n");
        }
        break;
      //Saves the game. Opens the save file and overwrites it with 
      //the current game world.
      case('s'):
        save = fopen("File","w");
        fclose(save);
        for(i = 0; i < r; i++){
         write_file("File",board[i],c);
        }
        break;
      //Loads the game and populates the board based upon the text
      //file.
      case('l'):
        if((save = fopen("File","r")) == (FILE*)NULL){
          printf("Save file not found!\n");
        }
        else{
          status = read_file("File", board);
        }
        for(i = 0; i < r; i++){

          for(j = 0; j < c; j++){
          
            printf("%c  ",board[i][j]);

          }

          printf("\n");

        }
        fclose(save);
        break;
    //Quits the game  
    case('q'):
        remove("File");
        free(board);
        exit(0);
    
    }
    printf("\n");

  }
  return 0;

}

/*
 * Method to handle the cellular evolution
 *
 * @param board A double pointer for our
 * current board
 * @param r the amount of rows
 * @param c the amount of columns
 */
void play_move(char** board, int r, int c){

  int i,j,k,l;
  //Temporary board which dupicates our currrent
  //board.
  char** temp = (char**)malloc(r*c*sizeof(char*));
  for(i = 0; i < r; i++){

    temp[i] = (char*)malloc(r*c*sizeof(char));
    for(j = 0; j < c; j++){
    
      temp[i][j] = board[i][j];
    
    }

  } 
  //This starts at 1 to prevent segfaulting by
  //checking indices that are out of the array
  //bounds. 
  //Source: https://www.geeksforgeeks.org/program-for-conways-game-of-life/
  for(i = 1; i < r - 1; i++){

    for(j = 1; j < c -1; j++){
        
      //Number of adjacent living cells
      int neighbors = 0;
      //Checks all adjacent cells and 
      //increments the neighbor counter
      //if there are living cells
      for(k = -1; k <= 1; k++){
        for(l = -1; l <= 1; l++){
            if(board[i+k][j+l] == '*')
              neighbors++;
        } 
      } 
      //Offsets the counter because we counted
      //the current cell as a neighbor
      neighbors--;
      //If the cell is living and has less than
      //2 neighbors, the cell dies.	
      if(board[i][j] == '*' && neighbors < 2){
        temp[i][j] = '-';
      }
      //If the cell is living and has 2-3 neighbors
      //, it survives.
      else if(board[i][j] == '*' && neighbors >= 2 && neighbors < 4){
        temp[i][j] = '*';
      }
      //If the cell has more than 3 neighbors, it
      //dies.
      else if(board[i][j] == '*' && neighbors >= 4){
        temp[i][j] = '-';
      }
      //If the cell is dead or empty and has three neighbors
      //, they breed and form a new cell. 
      else if(board[i][j] == '-' && neighbors == 3){
        temp[i][j] = '*';
      } 
      //Defaults to empty.
      else{
        temp[i][j] = '-';
      } 
    }
  }
  //Populates the original board with the updated cells
  for(i = 0; i < r; i++){
    
    for(j = 0; j < c; j++){

      board[i][j] = temp[i][j];

    }
     
  } 
  //Deallocates our temporary board.
  free(temp);

}


