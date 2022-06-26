#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "const.h"
#include "handles.h"
#include "screens.h"

int main (int argc, char *argv[])
{
  topScreen();
  mainOptionsView();
  return 0;
}
