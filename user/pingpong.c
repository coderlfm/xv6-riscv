#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// 创建两个pipe,一个用来给父进程读和写，一个从来子进程读和写
void main(int argc, char *argv[])
{

  int p1[2]; // 父元素
  int p2[2];
  char *buf[1];

  pipe(p1);
  pipe(p2);

  int pid = fork(); // 调用子进程

  // 说明是子进程
  if (pid == 0)
  {
    close(p2[0]);
    close(p1[1]);
    read(p1[1], buf, 1);
    printf("%d received ping\n", getpid());
    write(p2[0], buf, 1);
    exit(0);
  }
  else
  {
    close(p1[0]);
    write(p1[0], buf, 1);
    wait(0);
    read(p2[1], buf, 1);
    printf("%d received pong\n", getpid());
    close(p1[0]);
    exit(0);
  }
}
