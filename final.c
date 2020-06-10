#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

char * caps(char * temp) {
  char * name;
  name = strtok(temp,":");

  // Convert to upper case
  char *s = name;
  while (*s) {
    *s = toupper((unsigned char) *s);
    s++;
  }
  return s;

}


void writeToFile(int tmp, char *word, char *searchWord, char *replaceWord) {
    
        write(tmp, caps(word), strlen(word));
    
}

int main(int arg, char **argv) {
    char *searchWord = argv[1];
    char *replaceWord = argv[1];
    char *fileName = argv[1];
    char *tmpFilename = "/tmp/replace.txt";
    char word[100];
    int i = 0;
    char character;
    char whitespace;

    int fd = open(fileName, O_RDONLY);
    int tmp = open(tmpFilename, O_WRONLY | O_CREAT, 0600);
    if (fd < 0) {
        printf("The file cannot be opened\n");
        exit(1);
    }

    while(read(fd, &character, 1)) {
        if (character == ' ' || character == '\n' || character == EOF) {
            if (whitespace == 0) {
                whitespace = 1;
                word[i] = '\0';
                i = 0;
                writeToFile(tmp, word, searchWord, replaceWord);
                char c[1];
                c[0] = character;
                write(tmp, c, 1);
            } else {
                char c[1];
                c[0] = character;
                write(tmp, c, 1);
            }
        } else if (character != ' ' && character != '\n' && character != EOF) {
            whitespace = 0;
            word[i++] = character;
        }
    }
    word[i] = '\0';
    writeToFile(tmp, word, searchWord, replaceWord);
    close(fd);
    unlink(fileName);
    link(tmpFilename, "/tmp/file.txt");
    unlink(tmpFilename);
    exit(0);
}