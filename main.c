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
  while( (arg=strsep(&line, " ")) ){//while you can remove spaces, do so
    args[counter] = arg;//move over the 2d char array and set it equal to the next divided arg
    printf("arg[%d]: %s\n", counter, args[counter]);
    counter++;
  }
  args[counter] = 0;//set last to null for execvp
  printf("arg[%d]: %s\n", counter, args[counter]);
  return args;
}

int main(int argc, char * argv[]){
  printf("hardcoded input:\n");

  char str[256] = "ls -a -l";//allocate mem for string since we are editing it using strsep
  printf("Parsing and executing '%s' from string\n\n", str);
  char ** args = parse_args(str);
  //execvp(args[0], args);

  char command[15] = "ls -a -l";
  printf("Parsing and executing '%s' from pointer\n\n", command);
  char * line = command;
  args = parse_args( line );
  //execvp(args[0], args);
  printf(":::::::::::::::::::::::::::::::::::::::::\n\nuser input:\n");

  printf("first arg: %s\n", argv[1]);
  //pass "ls -l -a" after file
  printf("Parsing and executing '%s' from argv[1] \n\n", argv[1]);
  args = parse_args(argv[1]);
  //execvp(args[0], args);
  printf("\n\n");

  printf("second arg: %s\n", argv[2]);
  //pass "ls -l -a -h -i" after file
  printf("Parsing and executing '%s' from argv[2] \n\n", argv[2]);
  args = parse_args(argv[2]);
  execvp(args[0], args);
  
  free(args);
}
