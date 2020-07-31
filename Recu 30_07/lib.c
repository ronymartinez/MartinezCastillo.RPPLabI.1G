#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn.h"
#include <ctype.h>
#include "lib.h"



#define TAMCLIENTE 100
#define TAMALQUILER 100

int menuInformes()
{

    int retorno = 0;
    int opcion;

    system("clear");
    printf("**** MENU DE INFORMES ***\n\n");
    printf("\n1. Nombre y apellido del asociado con más alquileres");
    printf("\n2. Equipos/s más alquilado/s y su cantidad");
    printf("\n3  Tiempo promedio real de alquiler de los equipos");
    printf("\n4. Todos los alquileres.");

    if(utn_getNumero(&opcion, "\n\nIngrese la opcion indicada: ", "\nError. No ingreso una opcion valida.",1, 4, 2) == 0)
    {
        retorno = opcion;
    }
    return retorno;
}

int informes(eCliente *cliente, int tamCliente, eAlquiler *alquiler, int tamAlquiler)
{
    char seguir = 's';
    int retorno = 0;
    int opcionMenu = menuInformes();
    //eCliente cliente[TAMCLIENTE];
    //inicializarClientes(cliente, TAMCLIENTE);
    //hardcodearcliente(cliente, TAMCLIENTE);
    //eAlquiler alquiler[TAMALQUILER];
    //inicializarAlquileres(alquiler, TAMALQUILER);
    //hardcodearAlquileres(alquiler);

    do{

       switch (opcionMenu)
       {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                listarAlquileres(alquiler, TAMALQUILER);
                break;

                break;
            case 5:
            default:
                seguir = 'n';
                printf("\n\nHa finalizado el programa.\n\n");
                break;
       }
    getchar();

    }while(seguir == 's');

    return retorno;

}



int inicializarAlquileres(eAlquiler *alquiler, int tamAlquiler)
{
    int retorno = 0;
    for (int i = 0; i < tamAlquiler; i++)
    {
        alquiler[i].isEmpty = 0;
        retorno = 1;
    }

    return retorno;
}

void listarAlquileres(eAlquiler *alquiler, int tamAlquiler)
{
    int retorno = 0;
//    printf("Hola\n");
  //  getchar();

    system("clear");
    printf("**** LISTADO DE ALQUILERES\n\n");
    printf("   ID         ID                         HORAS       HORAS\n");
    printf("ALQUILER    CLIENTE        EQUIPO     ALQUILADAS    REALES    ESTADO\n\n");

    for (int i = 0; i < tamAlquiler; i++)
    {
        if(alquiler[i].isEmpty == 1)
        {
            listarAlquiler(alquiler[i]);
        }
        retorno = 1;
    }

    return retorno;

}


void listarAlquiler(eAlquiler alquiler)
{

    printf("  %4d       %4d   %14s      %4d        %4d      %8s\n",alquiler.id, alquiler.idCliente, alquiler.equipo, alquiler.tiempo, alquiler.tiempoReal, alquiler.estado);

}


int altaAlquiler(eAlquiler *alquiler, int tamAlquiler, eCliente *cliente, int tamCliente)
{
    int retorno = 0;
    int indiceLibre;
    int nuevoID;
    int idEquipo;
    int idCliente;
    int tiempo;
    int dni;

    indiceLibre = buscarAlquilerLibre(alquiler, tamAlquiler);
    nuevoID = indiceLibre + 501;
    getchar();
    system("clear");
    printf("*** ALTA DE ALQUILER ***\n\n");

    listarClientes(cliente, tamCliente);

    if (utn_getNumero(&idCliente, "\n\nIngrese el ID del cliente que contratara el alquiler: ", "Error. Ingreso datos invalidos.", 100, 200, 2) == 0)
    {
        system("clear");
        printf("*** ALTA DE ALQUILER - EQUIPO ***\n\n");
        printf("\nID   EQUIPO\n\n");
        printf("\n1. AMOLADORA.\n2. MEZCLADORA.\n3. TALADRO.\n\n");
        if(utn_getNumero(&idEquipo,"\n\n-Ingrese el ID del equipo: ", "Error. Ingreso un nombre invalido",1,3, 2) == 0)
        {
            system("clear");
            printf("*** ALTA DE ALQUILER - TIEMPO***\n\n");
            if(utn_getNumero(&tiempo,"\n\n-Ingrese las horas de alquiler: ", "Error. Ingreso un nombre invalido",1,999, 2) == 0)
            {
                if(idEquipo == 1)
                {
                    strcpy(alquiler[indiceLibre].equipo, "Amoladora");
                }
                if(idEquipo == 2)
                {
                    strcpy(alquiler[indiceLibre].equipo, "Mezcladora");
                }
                if(idEquipo == 3)
                {
                    strcpy(alquiler[indiceLibre].equipo, "Taladro");
                }

                alquiler[indiceLibre].idCliente = idCliente;
                alquiler[indiceLibre].id = nuevoID;
                alquiler[indiceLibre].tiempo = tiempo;
                strcpy(alquiler[indiceLibre].estado, "Alquilado");
                alquiler[indiceLibre].tiempoReal = 0;
                alquiler[indiceLibre].isEmpty = 1;

                printf("\n\nSe ha agregado correctamente el alquiler.\n\n");
                retorno = 1;
            }
        }
    }

    if(retorno == 0)
    {
        printf("\n\nSe ha cancelado el alta del cliente.\n\n");
    }

    return retorno;

}

int altaCliente(eCliente *cliente, int tamCliente)
{
    int retorno = 0;
    int indiceLibre;
    int nuevoID;
    char nombre[20];
    char apellido[20];
    int dni;

    indiceLibre = buscarClienteLibre(cliente, tamCliente);
    nuevoID = indiceLibre + 101;

    system("clear");
    printf("*** ALTA DE CLIENTE ***\n\n");
    //listarClientes(cliente, tamCliente);

    if (utn_getNumero(&dni, "\n\nIngrese el DNI del cliente (8 digitos): ", "Error. Ingreso datos invalidos.", 10000000, 99999999, 2) == 0)
    {
        system("clear");
        printf("*** ALTA DE CLIENTE ***\n\n");
        if(utn_getNombre(&nombre, 20, "\n\n-Ingrese el nombre: ", "Error. Ingreso un nombre invalido", 2) == 0)
        {
            system("clear");
            printf("*** ALTA DE CLIENTE ***\n\n");
            if(utn_getNombre(&apellido, 20, "\n\n-Ingrese el apellido: ", "Error. Ingreso un nombre invalido", 2) == 0)
            {
                cliente[indiceLibre].id = nuevoID;
                cliente[indiceLibre].dni = dni;
                strcpy(cliente[indiceLibre].nombre, nombre);
                strcpy(cliente[indiceLibre].apellido, apellido);
                cliente[indiceLibre].isEmpty = 1;
                printf("\n\nSe ha agregado correctamente al cliente.\n\n");
                retorno = 1;
            }
        }


    }

    if(retorno == 0)
    {
        printf("\n\nSe ha cancelado el alta del cliente.\n\n");
    }

    return retorno;
}

int modificarCliente(eCliente *cliente, int tamCliente)
{
    int id;
    int modificar;
    char nuevoNombre[20];
    char nuevoApellido[20];
    int indice;
    int retorno = 0;

    system("clear");
    printf("\n*** MODIFICAR CLIENTE ***\n\n");
    listarClientes(cliente, tamCliente);
    utn_getNumero(&id, "\nIngrese el ID del cliente a modificar: ", "\nError. Ingreso un dato invalido.", 100, 999, 2);

    system("clear");
    printf("\n*** MODIFICAR CLIENTE ***\n\n");
    indice = buscarClienteporID(cliente, id, tamCliente);
    printf(" ID         DNI     NOMBRE    APELLIDO\n\n");
    listarCliente(cliente[indice]);
    utn_getNumero(&modificar, "\n\n1. MODIFICAR NOMBRE.\n2. MODIFICAR APELLIDO.\n\n\nIngrese la opcion indicada:", "Error. Ingreso un dato invalido.", 1, 2, 2);

    if(modificar == 1)
    {
        system("clear");
        printf("\n*** MODIFICAR NOMBRE ***\n\n");
        printf(" ID         DNI     NOMBRE    APELLIDO\n\n");
        listarCliente(cliente[indice]);

        if(utn_getNombre(&nuevoNombre, 20, "\n\n-Ingrese el nuevo nombre: ", "Error. Ingreso un nombre invalido", 2) == 0)
         {
            strcpy(cliente[indice].nombre, nuevoNombre);
            printf("\n\nSe ha modificado el nombre correctamente.\n\n");
            retorno = 1;
         }else
         {
         printf("\n\nNo se pudo realizar la modificacion.\n");
         }

        if(modificar == 2)
        {
        system("clear");
        printf("\n*** MODIFICAR APELLIDO ***\n\n");
        printf(" ID         DNI     NOMBRE    APELLIDO\n\n");
        listarCliente(cliente[indice]);

        if(utn_getNombre(&nuevoApellido, 20, "\n\n-Ingrese el nuevo apellido: ", "Error. Ingreso un nombre invalido", 2) == 0)
         {
            strcpy(cliente[indice].apellido, nuevoApellido);
            printf("\n\nSe ha modificado el nombre correctamente.\n\n");
            retorno = 1;
         }
         else
         {
         printf("\n\nNo se pudo realizar la modificacion.\n");
         }
        }
    }
    return retorno;
}


int bajaCliente(eCliente *cliente, int tamCliente)
{
    int retorno = 0;
    int id;
    int confirma;
    int indice;

    system("clear");
    printf("\n*** DAR DE BAJA CLIENTE ***\n\n");
    listarClientes(cliente, tamCliente);
    if(utn_getNumero(&id, "\nIngrese el ID de la cliente a dar de baja: ", "\nError. Ingreso un dato invalido.", 100, 200, 2) == 0)
    {
        system("clear");
        printf("\n*** DAR DE BAJA CLIENTE ***\n\n");
        indice = buscarClienteporID(cliente, id, tamCliente);
        printf(" ID         DNI     NOMBRE    APELLIDO\n\n");
        listarCliente(cliente[indice]);

        if(utn_getNumero(&confirma, "\n\nIngrese 1 para confirmar la baja o 2 para cancelar: ", "Error. Ingreso un dato invalido.", 1, 2, 2) == 0)
        {
            if(confirma == 1)
            {
              cliente[indice].isEmpty = 0;
              printf("\n\nSe ha dado de baja al cliente.\n\n");
              retorno = 1;
            }
        }
    }
    if (retorno == 0)
    {
        printf("\n\nSe ha cancelado la operacion.\n\n");
    }

   return retorno;
}


int menuPrincipal()
{
    int opcion;
    int retorno = 0;

    system("clear");
    printf("*** MENU DE OPCIONES ***\n\n");
    printf("1. ALTA DE CLIENTE.\n2. MODIFICAR DATOS DE CLIENTE.\n3. BAJA DE CLIENTE.\n4. NUEVO ALQUILER.\n5. FIN DE ALQUILER\n6. INFORMAR.\n7. SALIR\n\n");


    if(utn_getNumero(&opcion, "\nIngrese la opcion indicada: ", "\nError. No ingreso una opcion valida.",1, 7, 2) == 0)
    {
        __fpurge(stdin);
        return opcion;
    }
        else
        {
            return retorno;
        }
}

int inicializarClientes(eCliente *cliente, int tamCliente)
{
    int retorno = 0;
    for (int i = 0; i < tamCliente; i++)
    {
        cliente[i].isEmpty = 0;
        retorno = 1;
    }

    return retorno;
}

void hardcodearcliente(eCliente *cliente, int tamCliente)
{
    eCliente aux1 = {101, 23428594, "Juan", "Perez", 1};
    eCliente aux2 = {102, 23491844, "Ana", "Martinez", 1};
    eCliente aux3 = {103, 49295244, "Silvia", "Sanchez", 1};
    eCliente aux4 = {104, 10948453, "Pedro", "Ramirez", 1};
    eCliente aux5 = {105, 19432845, "Carla", "Lopez", 1};


    cliente[0] = aux1;
    cliente[1] = aux2;
    cliente[2] = aux3;
    cliente[3] = aux4;
    cliente[4] = aux5;
}

void listarCliente(eCliente cliente)
{

    printf("%d   %9d   %8s    %8s\n", cliente.id, cliente.dni, cliente.nombre, cliente.apellido);
}

void listarClientes(eCliente *cliente, int tamCliente)
{
    system("clear");
    printf("**** LISTADO DE CLIENTES ****\n\n");
    printf(" ID         DNI     NOMBRE    APELLIDO\n\n");

    for (int i = 0; i < tamCliente; i++)
    {
        if(cliente[i].isEmpty == 1)
        {
            listarCliente(cliente[i]);
        }
    }
}



int buscarClienteporID(eCliente *cliente, int id, int tamCliente)
{
    int retorno = 0;

    for(int i = 0; i < tamCliente; i++)
    {
        if(cliente[i].id == id && cliente[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}



int buscarClienteLibre(eCliente *cliente, int tamCliente)
{
    int indiceLibre;

    for(int i = 0; i < tamCliente; i++)
    {
        if(cliente[i].isEmpty == 0)
        {
            indiceLibre = i;
            break;
        }
    }

    return indiceLibre;
}


int buscarAlquilerLibre(eAlquiler *alquiler, int tamAlquiler)
{
    int indiceLibre;

    for(int i = 0; i < tamAlquiler; i++)
    {
        if(alquiler[i].isEmpty == 0)
        {
            indiceLibre = i;
            break;
        }
    }

    return indiceLibre;
}

int buscarAlquilerPorId(eCliente *cliente, int id, int tamCliente)
{
    int retorno = 0;

    for(int i = 0; i < tamCliente; i++)
    {
        if(cliente[i].id == id && cliente[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


void hardcodearAlquileres(eAlquiler *alquiler)
{
    eAlquiler aux1 = { 501, 102, "Amoladora" ,  5, 10, "Sergio", 1, "Finalizado"};
    eAlquiler aux2 = { 502, 104, "Mezcladora", 10,  0, "Yanina", 1, "Alquilado" };
    eAlquiler aux3 = { 503, 103, "Taladro"   , 15,  0, "Lara"  , 1, "Alquilado" };
    eAlquiler aux4 = { 504, 105, "Taladro"   , 25, 20,  "Daiana", 1, "Finalizado"};
    eAlquiler aux5 = { 505, 101, "Amoladora" ,  3,  5, "Diego" , 1, "Finalizado"};


    alquiler[0] = aux1;
    alquiler[1] = aux2;
    alquiler[2] = aux3;
    alquiler[3] = aux4;
    alquiler[4] = aux5;

}

