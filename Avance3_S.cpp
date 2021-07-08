/*
    Universidad Popular Autónoma del Estado de Puebla.
    Estructura de Datos.
    Proyecto Avance 3.
    Juan Carlos Hurtado Andrade / A01025193.
    ------------------------------------------------------------------------------------------------------------------------
   |                                                                  							    |
   | 	Sistema que administra el padron electoral de un grupo de 10 personas.                                              |
   |    Se puede cargar toda la información de la credencial del INE de una persona de manera individual.                   |
   |    Se puede editar toda la información de la credencial del INE de una persona de manera individual.                   |
   |    Se puede imprimir toda la información de la credencial del INE de una persona de manera individual.                 |
   |    Se puede borrar toda la información de la credencial del INE de una persona de manera individual.                   |
   |  	El programa hace varias verificaciones para asegurarse hasta cierto punto que el usuario desea llevar a cabo	    |
   |    las operaciones seleccionadas.											    |
   |                                          										    |
    ------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ine
{
	char nombre[20];
	char apellido_pat[20];
	char apellido_mat[20];
	char domicilio[30];
	char clave_de_elector[19];
	char curp[19];
	int anio_de_registro;
	int estado;
	int municipio;
	int seccion;
	int emision;
	int vigencia;
	int estaLleno;
}
baseDatos[10];

void inicializa()
{
	for	(int i = 0; i < 10 ; i++)
	{
		fflush(stdin);
		baseDatos[i].nombre[20] = '0';
		baseDatos[i].apellido_pat[20] = '0';
		baseDatos[i].apellido_mat[20] = '0';
		baseDatos[i].domicilio[30] = '0';
		baseDatos[i].clave_de_elector[19] = '0';
		baseDatos[i].curp[19] = '0';
		baseDatos[i].anio_de_registro = 0;
		baseDatos[i].estado = 0;
		baseDatos[i].municipio = 0;
		baseDatos[i].seccion = 0;
		baseDatos[i].emision = 0;
		baseDatos[i].vigencia = 0;
		baseDatos[i].estaLleno = 0;
	}
}

void bajasRegistro(int posicion)
{
	int eliminarRegistro;

	do
	{
		printf("\nEsta seguro de eliminar el registro? [1 = Si, 2 = No]\n");
		scanf("%d", &eliminarRegistro);

		if(eliminarRegistro == 1)
		{
			if (baseDatos[posicion].estaLleno == 0)
			{
				printf( "\nEl registro ya estaba vacio. No hay nada que borrar.\n");
				eliminarRegistro = 2;
			}
			else 
			{
				baseDatos[posicion].nombre[20] = '0';
				baseDatos[posicion].apellido_pat[20] = '0';
				baseDatos[posicion].apellido_mat[20] = '0';
				baseDatos[posicion].domicilio[30] = '0';
				baseDatos[posicion].clave_de_elector[19] = '0';
				baseDatos[posicion].curp[19] = '0';
				baseDatos[posicion].anio_de_registro = 0;
				baseDatos[posicion].estado = 0;
				baseDatos[posicion].municipio = 0;
				baseDatos[posicion].seccion = 0;
				baseDatos[posicion].emision = 0;
				baseDatos[posicion].vigencia = 0;
				baseDatos[posicion].estaLleno = 0;

				printf("\nSe ha borrado el registro con exito.\n");
				eliminarRegistro = 2;
			}
		}
		else if(eliminarRegistro == 2)
		{
			printf("\nCancelando operacion... Regresando al Menu Principal.\n");
		}
		else
		{
			printf("\nIngrese una opcion valida...(1 o 2)\n");
		}
	} while (eliminarRegistro != 2);
}

void altaRegistro(int posicion)
{
	int deseaBorrar;
	
	if(baseDatos[posicion].estaLleno == 0)
	{
		fflush(stdin);
		printf("Inserta tu nombre: ");
		gets(baseDatos[posicion].nombre);
		printf("Inserta tu apellido paterno: ");
		gets(baseDatos[posicion].apellido_pat);
		printf("Inserta tu apellido materno: ");
		gets(baseDatos[posicion].apellido_mat);
		printf("Inserta tu domicilio: ");
		gets(baseDatos[posicion].domicilio);
		printf("Inserta tu clave de elector: ");
		gets(baseDatos[posicion].clave_de_elector);
		printf("Inserta tu curp:");
		gets(baseDatos[posicion].curp);
		printf("Inserta el anio de registro : ");
		scanf("%d", &baseDatos[posicion].anio_de_registro);
		printf("Inserta tu estado: ");
		scanf("%d", &baseDatos[posicion].estado);
		printf("Inserta el numero de tu municipio: ");
		scanf("%d", &baseDatos[posicion].municipio);
		printf("Inserta la seccion: ");
		scanf("%d", &baseDatos[posicion].seccion);
		printf("Inserta la emision: ");
		scanf("%d", &baseDatos[posicion].emision);
		printf("Inserta la vigencia: ");
		scanf("%d", &baseDatos[posicion].vigencia);
		baseDatos[posicion].estaLleno = 1;
	}
	else if(baseDatos[posicion].estaLleno == 1)
	{
		printf("El archivo ya contiene informacion, Desea cambiarla? [1 = Si, 2 = No] ");
		scanf("%d", &deseaBorrar);

		if (deseaBorrar == 1)
		{
			baseDatos[posicion].estaLleno = 0;
			altaRegistro(posicion);
		}
		else if (deseaBorrar == 2)
		{
			printf("\nCancelando operacion... Regresando al Menu Principal.\n");
		}
	}
}

void imprimeRegistro(int posicion)
{
	if (baseDatos[posicion].estaLleno == 0)
	{
		printf("\nRegistro vacio. No hay informacion que imprimir.\n");
	}
	else 
	{
		// printf("El nombre es: %s \n", baseDatos[posicion].nombre);
		// printf("El apellido paterno es: %s \n", baseDatos[posicion].apellido_pat);
		// printf("El apellido materno es: %s \n", baseDatos[posicion].apellido_mat);
		// printf("El domicilio es: %s \n", baseDatos[posicion].domicilio);
		// printf("La clave de elector es: %s \n", baseDatos[posicion].clave_de_elector);
		// printf("El CURP es: %s \n", baseDatos[posicion].curp);
		// printf("El ano de registro es: %d \n", baseDatos[posicion].anio_de_registro);
		// printf("El num de estado es: %d \n", baseDatos[posicion].estado);
		// printf("El num de municipio es: %d \n", baseDatos[posicion].municipio);
		// printf("El num de la seccion es: %d \n", baseDatos[posicion].seccion);
		// printf("El ano de emision  es: %d \n", baseDatos[posicion].emision);
		// printf("El ano de vigencia: %d \n", baseDatos[posicion].vigencia);	
		printf(" ________________________________________________________________________________ \n");
		printf("| INSTITUTO NACIONAL ELECTORAL	     	                                         |\n");
		printf("| CREDENCIAL PARA VOTAR     	       	                                         |\n");
		printf("|                           	                                                 |\n");
		printf("|          _____________	Nombre: %10s                                         |\n", baseDatos[posicion].nombre);
		printf("|         |             |	Apellido Paterno: %10s                               |\n", baseDatos[posicion].apellido_pat);
		printf("|         |             |	Apellido Materno: %10s                               |\n", baseDatos[posicion].apellido_mat);
		printf("|         |      F      |	domicilio: %10s                                      |\n", baseDatos[posicion].domicilio);
		printf("|         |             |	clave de elector: %10s                               |\n", baseDatos[posicion].clave_de_elector);
		printf("|         |      O      |	La CURP es: %10s                                     |\n", baseDatos[posicion].curp);
		printf("|         |             |	Anio de registro: %4d                                |\n", baseDatos[posicion].anio_de_registro);
		printf("|         |      T      |	Estado: %5d                                          |\n", baseDatos[posicion].estado);
		printf("|         |             |	Municipio: %5d                                       |\n", baseDatos[posicion].municipio);
		printf("|         |      O      |	Seccion: %5d                                         |\n", baseDatos[posicion].seccion);
		printf("|         |             |	Emision: %5d                                         |\n", baseDatos[posicion].emision);
		printf("|         |             |	Vigencia: %5d                                        |\n", baseDatos[posicion].vigencia);
		printf("|         |_____________|   	                                                 |\n");
		printf("|                           	                                                 |\n");
		printf("|________________________________________________________________________________|\n");
	}
}

int main() {
	int opcion;
	int posicion;
	inicializa();

	do {
		
		printf("\n\t\tMenu Principal\n");
		printf("\n\t1.-Alta del registro\n");
		printf("\t2.-Baja del registro\n");
		printf("\t5.-Imprimir registro\n");
		printf("\t9.-Terminar programa\n");
		printf("\n\t opcion: ");
		scanf("%d", &opcion);
		
        switch (opcion) {

		case 1:
			printf("\nIndique la pocicion para cargar los datos: \n");
	 		scanf("%d", &posicion);
			altaRegistro(posicion);
			break;
		
		case 2:
			printf("\nIndique la pocicion para borrar los datos: \n");
	    	scanf("%d", &posicion);
			bajasRegistro(posicion);
			break;

		case 5:
			printf("\nIndique la pocicion para imprimir los datos: \n");
	    	scanf("%d", &posicion);
			imprimeRegistro(posicion);
			break;

		case 9:

			break;

		default:
			printf("\tIngrese una opcion valida\n");
		}
	} while (opcion != 9);

	system("pause");
	return 0;
}
