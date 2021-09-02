#include <stdio.h> /* incluye biblioteca donde se define E/S */
#include "scanner.h"

int main()
{

  enum tokens token;
  char buffer[256] = {'\0'};

  while ((token = get_token(buffer)) != FDT)
  {
    switch (token)
    {
    case SEP:
      printf("Separador: , \n");
      break;

    case CAD:
      printf("Cadena: %s\n", buffer);
      break;
    }
  }

  printf("Fin De Texto: ");

  return 0;
}