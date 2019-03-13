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
      if (c == EOF){
        comm.argNumb = -1;
        return comm;
      }
      buf = addChar(buf,c);
    }
    buf = addChar(buf,' ');
    int beg = 0;
    int end = 0;
    int frstCMD = 1;
    int frstWord = 0;
    comm = initStruct(comm);


    for (int i=0; i<getLength(buf); i++){
      if ( (buf[i] != ' ') && (frstWord == 1) ){
        beg = i;
        frstWord = 0;
        continue;
      }
      if (buf[i] == ' '){
        end = i;
        frstWord = 1;
        if (frstCMD == 0) {
            comm.argv[comm.argNumb] = initStr(comm.argv[comm.argNumb]);
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
    comm.argv[comm.argNumb] = NULL;
    return comm;
}

int main(){
  command c1;
  //c1 = initCMD(c1);
  pid_t pid;
  int rv;
  int status;
  while (1){
    pid = fork();
    switch(pid){
      case -1: // ошибка
        exit(1);
        break;
      case 0: // процесс потомок
        printf("exec:\t");
        c1 = initCMD(c1);
    //    printf("argNumb:%d\n", c1.argNumb);
//        printf("args:\t");
        for(int i=0; i < c1.argNumb; i++)
          puts(c1.argv[i]);
        if (c1.argNumb == -1)
          return -1;
        if (c1.argNumb == 0)
          rv = execlp(c1.cmd,c1.cmd,NULL);
        else
          rv = execvp(c1.cmd,c1.argv);
        if (rv == -1) {
          perror("execvp");
          return EXIT_FAILURE;
        }
        break;
      default: // родитель
        waitpid(0,&status,0);
      //  printf("status:%d\n", status);
        if (WEXITSTATUS(status) == -1){
          printf("EXIT\n");
          return 0;
        }
        if (WEXITSTATUS(status) == EXIT_FAILURE){
          printf("EXEC ERROR\nEXIT\n");
          return -1;
        }

    }
  }
}
