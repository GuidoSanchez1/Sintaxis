#include <stdio.h> /* incluye biblioteca donde se define E/S */
#include "scanner.h"
#include <ctype.h>

int get_token(char buffer[])
{

    enum tokens token;
    char c;
    int contador = 0;

    while ((c = getchar()) != EOF)
    {
        if (isspace(c))
        {
            if (contador != 0)
            {
                buffer[contador] = '\0';
                return CAD;
            }
        }
        else if (c == ',')
        {
            if (contador != 0)
            {
                buffer[contador] = '\0';
                ungetc(c, stdin);
                return CAD;
            }
            return SEP;
        }
        else
        {
            buffer[contador] = c;
            contador++;
        }
    }

    if(contador != 0){
        buffer[contador] = '\0';
        ungetc(c, stdin);
        return CAD;
    }

    return FDT;
}
