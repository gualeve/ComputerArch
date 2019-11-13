#include <stdio.h>
#include "comuns.h"
#include "ilp.h"
#include "cache.h"

int main()
{
  int op = 0;
  char *opcoes[2] = {
    "1: Cache",
    "2: ILP"
  };
  while ((op = menu(2, opcoes)) != 0) {
      switch (op) {
        case 1:
          cache();
          break;
        case 2:
          ilp();
          break;
        }

    }
  return 1;
}
