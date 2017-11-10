#include <unist.h>
#include <stdio.h>
#include <string.h>

char ** parse_args(char * line){
  char ** args = malloc(sizeof(char*)*8);
  char * arg;
  int counter = 0;
  while(arg=strsep(line, " ")){
    args[counter] = arg;
  }
  return args;
}

int main(){

}
