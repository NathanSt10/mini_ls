/*******************************************************************

* Description: 
* This C program implements modified versions of the 'ls' command commonly found in Unix-like operating systems. 
* The 'ls' command is used to view files and directories within the current or specified directory

Usage:
* Compile it using a C compiler and run the executable from the command line with appropriate arguments.
*    - ./minils <file> [-a] 
*    - ./minils [-a] <file>
*    - optional arguments are specified in [ ]
*******************************************************************/

#include "file.h"

#define MAX_PATH_SIZE 128

/*
* Display files and directories
* input:
*   argc - number of arguments passed
*   *argv - array containing possible flag and/or file name
*/
void ls(int argc, char *argv[]) {
   struct dirent *ENTRY;
   DIR *dir;
   char path[MAX_PATH_SIZE] = "./";

   int foundFlag = 0;
   // Two argument case
   if (argc == 2){
      for (int i = 1; i < argc; ++i) {
         if (strcmp(argv[i], "-a") == 0) {
            foundFlag = 1;
         }
      }

      if (!foundFlag) {
         strncpy(path, argv[1], MAX_PATH_SIZE - 1);
         path[MAX_PATH_SIZE - 1] = '\0';
      }
   }
   // Three argument case
   else if (argc == 3) {
      // For loop to validate the flag exists
      for (int i = 1; i < argc; ++i) {
         if (strcmp(argv[i], "-a") == 0) {
            foundFlag = 1;
         }
      }
      // If no flag thats an error
      if (!foundFlag) {
         puts("Error invalid flag");
         return;
      }
      strncpy(path, (strcmp(argv[1], "-a") == 0) ? argv[2] : argv[1], MAX_PATH_SIZE - 1);
      path[MAX_PATH_SIZE - 1] = '\0';
   }
   // Catch if there are an invalid amount of arguments
   else if (argc != 1) {
      puts("Invalid amount of arguments. Can only take 1, 2, or 3 arguments");
      return;
   }

   dir = opendir(path);
   if (dir == NULL) { 
      perror(path);
      return;
   }

   while ((ENTRY = readdir(dir)) != NULL) { 
      char *cur_entry = ENTRY->d_name; 
      // if -a is not included, skip hidden files and directories
      if (!foundFlag && cur_entry[0] == '.') continue;
      puts(cur_entry);
   }    
   closedir(dir);
}