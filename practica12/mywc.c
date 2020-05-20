#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argn, char **argv){
    char *fileName = argv[1];
    char buffer;
    int fd = open(fileName,O_RDONLY);
    uint numChar = 0,
         numLines = 0,
         numWords = 0;
    char isWord = 0;
    if(fd<0){
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read(fd, &buffer, 1)){
        numChar++;
        if (buffer == '\n') 
            numLines++;
        if(numWords==0 && buffer!=' ' && buffer!='\n'|| (isWord && (buffer==' ' || buffer=='\n')))
            numWords++;
        
        if(buffer == ' ' || buffer == '\n') isWord=0;
        else isWord=1;
    }
    printf("Número de lineas: %d \nNúmero de palabras: %d \nNúmero de caracteres: %d\n",numLines,numWords,numChar);
    close(fd);
    exit(0);
}