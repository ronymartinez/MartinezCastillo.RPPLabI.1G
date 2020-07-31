#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn.h"
#include <ctype.h>
#include "lib.h"



#define TAMCLIENTE 100
#define TAMALQUILER 100


int main()
{
    char seguir = 's';
    eCliente cliente[TAMCLIENTE];
    inicializarClientes(cliente, TAMCLIENTE);
    hardcodearcliente(cliente, TAMCLIENTE);
    eAlquiler alquiler[TAMALQUILER];
    inicializarAlquileres(alquiler, TAMALQUILER);
    hardcodearAlquileres(alquiler);

    do{

       switch (menuPrincipal())
       {
            case 1:
                altaCliente(cliente, TAMCLIENTE);
                break;

            case 2:
                modificarCliente(cliente, TAMCLIENTE);
                break;

            case 3:
                bajaCliente(cliente, TAMCLIENTE);
                break;

            case 4:
                altaAlquiler(alquiler, TAMALQUILER, cliente, TAMCLIENTE);
                break;

            case 5:

                break;

            case 6:
                informes(cliente, TAMCLIENTE, alquiler, TAMALQUILER);
                //listarClientes(cliente, TAMCLIENTE);
                break;

            case 7:
                break;
            case 8:
                altaAlquiler(alquiler, TAMALQUILER, cliente, TAMCLIENTE);
                break;
            case 12:
            default:
                seguir = 'n';
                printf("\n\nHa finalizado el programa.\n\n");
                break;
       }
    getchar();

    }while(seguir == 's');
    return 0;
}

