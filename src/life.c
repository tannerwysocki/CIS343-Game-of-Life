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

int main(int argc, char** argv){

  if(argc > 3 || argc < 3){

    printf("Invalid command.");
    return 1;

  }
  int r = atoi(argv[1]), c = atoi(argv[2]);
  char option;
  char** board = (char**)malloc(r*c*sizeof(char*));
  int i,j;
  for(i = 0; i < r; i++){
   
    board[i] = (char*)malloc(r*c*sizeof(char));
    for(j = 0; j < c; j++){
      
      board[i][j] = '-';
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
        fclose(save);
        break;
      case('q'):
        exit(0);
    
    }
    printf("\n");

  }
  return 0;

}



