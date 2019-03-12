#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "mystring.h"

typedef struct command{
  char* cmd;
  char** argv;
  int argNumb;
}command;

command initStruct(command c){
  c.argNumb = 0;
  c.argv = (char**)malloc(sizeof(char*));
  return c;
}

command initCMD(command comm){
    char* buf = initStr(buf);
    char c;

    while ((c = getchar()) != '\n'){
      buf = addChar(buf,c);
    }
    buf = addChar(buf,' ');
    int beg = 0;
    int end = 0;
    int frstCMD = 1;
    comm = initStruct(comm);


    for (int i=0; i<getLength(buf); i++){
      if (buf[i] == '-'){
        beg = i;
        continue;
      }
      if (buf[i] == ' '){
        end = i;
        if (frstCMD == 0) {
            printf("argNumb=%d\n", comm.argNumb);
            comm.argv[comm.argNumb] = initStr(comm.argv[comm.argNumb]);
            printf("beg=%d\n", beg);
            comm.argv[comm.argNumb] = cpyStr(comm.argv[comm.argNumb],buf,beg,end);
            comm.argNumb++;
            beg = i;
        }
        else {
          comm.cmd = initStr(comm.cmd);
          comm.cmd = cpyStr(comm.cmd,buf,beg,end);
          frstCMD = 0;
        }
        continue;
      }
    }
    return comm;
}

int main(){
  command c1;
  c1 = initCMD(c1);
  puts(c1.cmd);
  printf("%d\n", c1.argNumb);
  for (int i = 0; i < c1.argNumb; i++)
    puts(c1.argv[i]);
//  puts(c1.cmd);
//  puts(c1.argv[0]);
  /*pid_t pid = fork();
  int rv;
  switch(pid){
    case -1: // ошибка
      perror = ("fork");
      exit(1);
    case 0: // процесс потомок
      printf("bash$\t");
      ///.......
      exit(rv);
    default: // родитель
      wait();
      ///.....
  }*/
}
