#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct command{
  char* cmd;
  char** argv;
  int agrNumb;
}command;

char* initStr(char* str){
  str = (char *)malloc(sizeof(char));
  str[0] = '\0';
  return str;
}

char* addChar(char* str, char chr){
  int i = 0;
  while(str[i] != '\0')
    i++;
  str = (char *)realloc(str,(i+2) * sizeof(char));
  str[i] = chr;
  str[i+1] = '\0';
  return str;
}

char* cpyStr(char* str1, char* str2, int beg, int end){
  for(int i = 0; i < end - beg; i++){
    str1 = addChar(str1,str2[beg+i]);
    printf("i=%d\tchr=%c\n",i,str2[beg+i]);
  }
  return str1;
}

int getLength(char *str){
  int i = 0;
  while (str[i] != '\0')
    i++;
  return i;
}

void initCMD(command comm){
    char* buf = initStr(buf);
    char c;

    while ((c = getchar()) != '\n'){
      buf = addChar(buf,c);
    }
    puts(buf);
    int beg = 0;
    int end = 0;
    for (int i=0; i<getLength(buf); i++){
      if (buf[i] == ' '){ // ввод команды
        end = i;
        i++;
        continue;
      }
      

    }

    comm.cmd = initStr(comm.cmd);
    comm.cmd = cpyStr(comm.cmd,buf,beg,end);
    puts(comm.cmd);
}

int main(){
  command c1;
  initCMD(c1);
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
