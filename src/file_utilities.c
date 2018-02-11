/**********************************************************************
 * The source implementation file for file_utilities.h. These
 * functions simply manage storing the state of the board in a text
 * file and writing them.
 *
 * @author:      Tanner Wysocki
 * @date:        2018-02-04 13:18 
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../include/file_utilities.h"

int read_file( char* filename, char **buffer ){

  int size = 0;
  FILE* in = fopen(filename,"r");
  if(in == NULL){
    //Returns a -1 to the main function to signify no file exists.
    return -1;
  }
  printf("Read file.\n");
  fclose(in);
  return 0;

}

int write_file( char* filename, char *buffer, int size){
  
  FILE* out = fopen(filename,"a");
  int i;
  for(i = 0; i < size; i++){

    fprintf(out,"%c  ",buffer[i]);
    
  }
  fprintf(out,"\n");
  fclose(out);
  return 0;

}
