#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"comuns.h"

#define TEMPO 60  // executará por 60s

int main()
{
  unsigned long int i = 0;
  int now, start;
  FILE *fd;
  pid_t pid;

  pid = getpid();
  fd = fopen("loop.txt", "w");
  printf("PID=%u\n", pid);
  now = start = (int)segundo_atual();
  while(now < start+TEMPO) {
    i++;
    if ((int)segundo_atual() != now) {
      fprintf(fd, "%lu\n", i);
      now = (int)segundo_atual();
      i = 0;
    }
  }
  fclose(fd);
  return 0;
}
