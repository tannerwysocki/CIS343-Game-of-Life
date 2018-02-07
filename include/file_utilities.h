/*************************************************************************************//**
 *  @file       file_utilities.h
 *
 *  @brief      Brief description of file_utilities.h
 *
 *  @date       2018-02-02 14:14
 *         
 **************************************************************************************/


#ifndef FILE_UTILITIES_H
#define FILE_UTILITIES_H

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

#endif /* !FILE_UTILITIES_H */

