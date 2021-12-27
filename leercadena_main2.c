 /*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: Wilson Paniquita - Diana Giron
 * Fecha: 2021-12-27
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
//#include <sys/wait.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {

  	int i=0; //variable que maneja el indice del vector resultado
	int j=1; //variable que maneja el indice del vector argv

  	char **resultado; //se define un vector de cadena de caracteres

 	resultado = (char**)malloc(sizeof(char*)); //se reserva el espacio en memoria para el vector de caracteres

	if(argc==1)// se evalua el tamaño del vector de parámetros, si es 1 indica que no se han pasado valores
		printf("Indique el programa que desea se ejecute \n");
	else{//pasa al else cuando el tamaño del vector de parámetros es mayor a 1, que indica que almenos se ha ingresado 1 parámetro
   
	    	if (strcmp(argv[1],"salir") == 0) { // se evalua que el comando ingresado sea salir
	      		return 0;
	    	} else 
			if (strcmp(argv[1], "exit") == 0) { // se evalua que el comando ingresado sea exit
	      			return 1;
	    		}
	

		while(j < argc){//while que itera hasta que ya no hayan elementos en el vector de parémetros
			resultado[i]= argv[j]; //se almacenan los elementos del vector de parámetros, en un vector que se definió y creó al inicio
			i++;//se incrementa indice del vector resultado
			j++;//se incrementa indice del vector argv	
		}

		resultado[argc-1]= NULL;//se asigna NULL a la última posición del vector resultado, para pasarlo a la función execvp() y sepa cuando termina
			
		execvp(resultado[0],resultado);//se pasa el vector resultado, que contiene el comando a ejecutar con sus modificadores.
	}

  return 0;
}


