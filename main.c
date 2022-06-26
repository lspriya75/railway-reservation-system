#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "const.h"
#include "extras.h"
#include "user.h"
#include "admin.h"
#include "screens.h"

int main (int argc, char *argv[])
{
  topScreen();
  mainOptionsView();
  return 0;
}
