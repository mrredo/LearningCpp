/* */
#include <windows.h>
#include <ws2tcpip.h>
#include <winsock2.h>
#include <wincrypt.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/utime.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <io.h>
#include <locale.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <process.h>
#include <stddef.h>
#include <malloc.h>
#include <memory.h>

int main(int argc, char** argv)
{
  (void)argv;
#ifndef getprotobyname
  return ((int*)(&getprotobyname))[argc];
#else
  (void)argc;
  return 0;
#endif
}