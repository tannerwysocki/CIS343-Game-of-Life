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

/*
 * Function to read text from a text file and place it into an array
 *
 * @param filename the name of the text file
 * @param buffer a two dimensional array of text
 * @return -1 if the file cannot be read. 0 if successful
 */
int read_file(char* filename, char **buffer){

  int i, j, row = 0, col = 0;
  FILE* in = fopen(filename,"r");
  char c;
  if(in == NULL){
    //Returns a -1 to the main function to signify no file exists.
    return -1;
  }
  //Source: https://www.geeksforgeeks.org/c-program-count-number-lines-file/
  //Counts the number of rows in the text file
  for(c = getc(in); c != EOF; c = getc(in)){

    if(c == '\n')
      row++;

  }
  //Moves the file pointer back to the beginning of the file
  rewind(in);
  //Counts columns in the text file
  for(c = getc(in); c != '\n'; c = getc(in)){

    col++;

  }
  rewind(in);
  char temp;
  //Populates the array with text from the file
  for(i = 0; i < row; i++){

    for(j = 0; j < col; j++){
   
      temp = getc(in);
      //Trims newline characters from the file
      if(temp == '\n')
       temp = getc(in);
      buffer[i][j] = temp; 

    }

  }
  fclose(in);
  return 0;

}

/*
 * Function to write data from array to file
 *
 * @param filename the name of the file
 * @param buffer the array we are saving to a text file
 * @param size the size in bytes of the file
 * @return whether the write was successful
 */
int write_file( char* filename, char *buffer, int size){
  
  FILE* out = fopen(filename,"a");
  int i;
  for(i = 0; i < size; i++){

    fprintf(out,"%c",buffer[i]);
    
  }
  fprintf(out,"\n");
  fclose(out);
  return 0;

}
