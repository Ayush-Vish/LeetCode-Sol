#include <stdio.h>
#include <unistd.h>
int main () {
      printf("Hello World\n");
      int a  = fork();
      if (a == 0) {
            printf("Child Process\n");
            for (int i = 0; i < 10; i++) {
                  printf("  i ->  %d\n", i);
            }
      } else {
            for (int i = 0; i < 10; i++) {
                  printf("%d\n", i);
            }
            printf("Parent Process\n");
      }


      return 0 ;
      
}
