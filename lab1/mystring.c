#include <stdio.h>
#include <stdlib.h>

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
  }
  return str1;
}

int getLength(char *str){
  int i = 0;
  while (str[i] != '\0')
    i++;
  return i;
}
