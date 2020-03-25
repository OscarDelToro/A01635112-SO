#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  pid_t fork_pid = fork();
  if (fork_pid == 0) {
    printf("Hello from the child! my pid is: %d \n",fork_pid);
  } else {
    printf("Hello from the parent! my pid is: %d \n",fork_pid);
  }
  return 0;
}