/*************************************************************************************//**
 *  @brief      The header file for file_utilities.c
 *  @author     Tanner Wysocki
 *  @date       2018-02-02 14:14
 *         
 **************************************************************************************/


#ifndef FILE_UTILITIES_H
#define FILE_UTILITIES_H

/*
 * Reads a file and populates an array with the data from the file.
 * @param filename the name of the file
 * @param buffer A 2D array of text
 */
int read_file( char* filename, char **buffer );
/*
 * Writes the data from an array to a file
 * @param filename the name of the file
 * @param buffer an array of text
 * @param size the size in bytes of the file
 */
int write_file( char* filename, char *buffer, int size);

#endif /* !FILE_UTILITIES_H */

