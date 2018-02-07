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
  char** board = (char**)malloc(r*c*sizeof(char));
  printf("Welcome to Conway's Game of Life!\n");
  while(1){
    
    printf("Would you like to (c)ontinue, (s)ave, (l)oad, or (q)uit?");
    scanf("%c",&option);
    int status;
    switch(option){

      case('s'):
        write_file("File",*board,5);
        break;
      case('l'):
        status = read_file("File",board);
        printf("%d\n",status);
        break;
      case('q'):
        exit(0);
        break;
    
    }

  }
  return 0;

}



