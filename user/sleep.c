#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{

  // 命令参数
  if (argc < 2)
  {
    printf("argument count error");
    exit(1);
  }
  else
  {
    int result =  atoi(argv[1]);
    sleep(result);
    exit(0);
  }

  return 0;
}
