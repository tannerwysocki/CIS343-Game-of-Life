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

void play_move(char***,int,int);

int main(int argc, char** argv){

  if(argc > 3 || argc < 3){

    printf("Invalid command.");
    return 1;

  }
  int r = atoi(argv[1]), c = atoi(argv[2]);
  char option;
  char** board = (char**)malloc(r*c*sizeof(char*));
  int i,j,placeCell;
  srand(time(NULL));
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
  printf("Welcome to Conway's Game of Life!\n");
  while(1){
    
    printf("Would you like to (c)ontinue, (s)ave, (l)oad, or (q)uit? ");
    scanf(" %c",&option);
    int status;
    FILE* save;
    switch(option){

      case('c'):
        play_move(&board,r,c);
        for(i = 0; i < r; i++){
          for(j = 0; j < c; j++){
            printf("%c  ",board[i][j]);
          }
          printf("\n");
        }
        break;
      case('s'):
        save = fopen("File","w");
        fclose(save);
        for(i = 0; i < r; i++){
         write_file("File",board[i],c);
        }
        break;
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
      case('q'):
        remove("File");
        exit(0);
    
    }
    printf("\n");

  }
  return 0;

}

void play_move(char*** board, int r, int c){

  int i,j,k,l;
  char** temp = (char**)malloc(r*c*sizeof(char*));
  for(i = 0; i < r; i++){

    temp[i] = (char*)malloc(r*c*sizeof(char));
    for(j = 0; j < c; j++){
    
      temp[i][j] = *(board[i][j]);
    
    }

  } 
  for(i = 1; i < r - 1; i++){

    for(j = 1; j < c -1; j++){
        
      int neighbors = 0;
      for(k = -1; k <= 1; k++){
        for(l = -1; l <= 1; l++){
            if(*(board[i+k][j+l]) == '*')
              neighbors++;
        } 
      } 
      neighbors--;
      if(*(board[i][j]) == '*' && neighbors < 2){
        temp[i][j] = '-';
      }
      else if(*board[i][j] == '*' && neighbors >= 2 && neighbors < 4){
        temp[i][j] = '*';
      }
      else if(*board[i][j] == '*' && neighbors >= 4){
        temp[i][j] = '-';
      }
      else if(*board[i][j] == '-' && neighbors == 3){
        temp[i][j] = '*';
      } 
      else{
        temp[i][j] = '-';
      } 
    }
  }
  *board = temp;
  free(temp);

}


