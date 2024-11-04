#include "file.h"

#define MAX_PATH_SIZE 128

void ls(int argc, char *argv[]) {
   struct dirent *ENTRY;
   DIR *dir;
   char path[MAX_PATH_SIZE] = "./";

   int foundFlag = 0;
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
   else if (argc == 3) {
      for (int i = 1; i < argc; ++i) {
         if (strcmp(argv[i], "-a") == 0) {
            foundFlag = 1;
         }
      }
      if (!foundFlag) {
         puts("Error invalid flag");
         return;
      }
      strncpy(path, (strcmp(argv[1], "-a") == 0) ? argv[2] : argv[1], MAX_PATH_SIZE - 1);
      path[MAX_PATH_SIZE - 1] = '\0';
   }

   dir = opendir(path);
   if (dir == NULL) { 
      perror(path);
      return;
   }

   while ((ENTRY = readdir(dir)) != NULL) { 
      char *cur_entry = ENTRY->d_name; 
      if (!foundFlag && cur_entry[0] == '.') continue;
      puts(cur_entry);
   }    
   closedir(path);
}