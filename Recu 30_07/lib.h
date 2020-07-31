#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int id;
    int dni;
    char nombre[20];
    char apellido[20];
    int isEmpty;
} eCliente;


typedef struct
{
    int id;
    int idCliente;
    char equipo[20];
    int tiempo;
    int tiempoReal;
    char operador[20];
    int isEmpty;
    char estado[20];
} eAlquiler;


#endif // LIB_H_INCLUDED


int menuInformes();
int informes(eCliente *cliente, int tamCliente, eAlquiler *alquiler, int tamAlquiler);
int inicializarAlquileres(eAlquiler *alquiler, int tamAlquiler);
void listarAlquileres(eAlquiler *alquiler, int tamAlquiler);
void listarAlquiler(eAlquiler alquiler);
int altaAlquiler(eAlquiler *alquiler, int tamAlquiler, eCliente *cliente, int tamCliente);
int altaCliente(eCliente *cliente, int tamCliente);
int modificarCliente(eCliente *cliente, int tamCliente);

int bajaCliente(eCliente *cliente, int tamCliente);
int menuPrincipal();
int inicializarClientes(eCliente *cliente, int tamCliente);
void hardcodearcliente(eCliente *cliente, int tamCliente);
void listarCliente(eCliente cliente);
void listarClientes(eCliente *cliente, int tamCliente);

int buscarClienteporID(eCliente *cliente, int id, int tamCliente);
int buscarClienteLibre(eCliente *cliente, int tamCliente);
int buscarAlquilerLibre(eAlquiler *alquiler, int tamAlquiler);
int buscarAlquilerPorId(eCliente *cliente, int id, int tamCliente);
void hardcodearAlquileres(eAlquiler *alquiler);



