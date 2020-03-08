#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];


int
main(int argc, char *argv[])
{
  printf(1,"Haz reiniciado, felicidades, ya eres un ingeniero en sistemas\n");
  reboot();
  exit();
}
