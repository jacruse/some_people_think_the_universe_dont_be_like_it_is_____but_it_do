#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** parse_args(char * line){
  char ** args = (char **)calloc(6, sizeof(char*));//allocate space for the 5 possible args + ending null for execvp
  if(!args){//check if memory was allocated
    printf("Memory Allocation Failed\n");
    exit(1);
  }
  char * arg;
  int counter = 0;
  while(arg=strsep(&line, " ")){//while you can remove spaces, do so
    args[counter] = arg;//move over the 2d char array and set it equal to the next divided arg
    counter++;
  }
  args[counter] = NULL;//set last to null for execvp
  return args;
}

int main(){
  char str[256] = "ls -a -l";//allocate mem for string since we are editing it using strsep
  printf("Parsing and executing '%s'\n\n", str);
  char ** args = parse_args(str);
  execvp(args[0], args);
  free(args);
}