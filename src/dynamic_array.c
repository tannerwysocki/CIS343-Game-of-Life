#include "../include/dynamic_array.h"
#include <stdlib.h>

void increase(char** board,int* r, int* c){

   char** temp  = (char**)malloc(2*(*r)*(*c)sizeof(char));
   int i,j;
   for(i = 0; i < *r; i++){

     for(j = 0; j < *c; j++){

       temp[i][j] = board[i][j]; 

     }

   }
   board = temp;
   free(temp);

}
