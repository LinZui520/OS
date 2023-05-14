#include <stdio.h>

void hello(int argc, char** argv){
    printf("Hello, World!\n");
    for(int i=1;i<argc;i++){
        printf("Hello, %s!\n", argv[i]);
    }
}