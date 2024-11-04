/*******************************************************************
* Description: 
* This C program implements UNIX command such as ls with limited features named as minils.  

Usage:
* Compile it using a C compiler and run the executable from the command line with appropriate arguments.
*    - To list files/directories: ./minils [-a] [path]
*    - optional arguments are specified in [ ]
*    - If no path is mentioned explicitly in ls command, it by default reads the path "." :the current direcotry.
*******************************************************************/

#include "file.h" 

int main(int argc, char *argv[]) {
    ls(argc, argv);

    return 0;
}
