/*
 ============================================================================
 Name        : Recu.c
 Author      : Sebastian Migliorisi
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char marca[20];
	int tipo;
	float peso;
}eVehiculo;

//Funciones constructoras
eVehiculo* vehiculo_new();
eVehiculo* vehiculo_newParametros(char* idStr,char* marcaStr,char* tipoStr, char* peso);

// Setters
int vehiculo_setId(eVehiculo* this,int id);

int vehiculo_setMarca(eVehiculo* this,char* marca);

int vehiculo_setTipo(eVehiculo* this,int tipo);

int vehiculo_setPeso(eVehiculo* this,int peso);

int main()
{



}

eVehiculo* vehiculo_new()
{
    eVehiculo* newVehiculo;
    newVehiculo= (eVehiculo*) malloc(sizeof(eVehiculo));

    if(newVehiculo!=NULL)
    {
            newVehiculo->id =0;
            strcpy(newVehiculo->marca, "");
            newVehiculo->tipo=0;
            newVehiculo->peso=0;
    }

    return newVehiculo;
}


eVehiculo* vehiculo_newParametros(char* idStr,char* marcaStr,char* tipoStr, char* pesoStr)
{
    int id;
    int tipo;
    float peso;
    eVehiculo* newVehiculo;
    newVehiculo = vehiculo_new();


    if(newVehiculo!=NULL)
    {
        id = atoi(idStr);
        tipo = atoi(tipoStr);
        peso = atof(pesoStr);

        if(    vehiculo_setId(newVehiculo,id)
            || vehiculo_setMarca(newVehiculo, marcaStr)
            || vehiculo_setTipo(newVehiculo, tipo)
			|| vehiculo_setPeso(newVehiculo, peso)
           )
        {
            free(newVehiculo);
            newVehiculo=NULL;
        }
    }

    return newVehiculo;
}

int eVehiculo_setId(eVehiculo* this,int id)
{
    int retorno=1;

    if(this!=NULL && id>0 && id<2000)
    {
    	this->id=id;
        retorno=0;
    }
    return retorno;
}

int eVehiculo_setMarca(eVehiculo* this,char* marca)
{
    int retorno=1;

    if(this!=NULL && strlen(marca)>=3 && strlen(marca)<=20)
    {
        strcpy(this->marca,marca);
        retorno=0;
    }
    return retorno;
}

int eVehiculo_settipo(eVehiculo* this,int tipo)
{
    int retorno=1;

    if(this!=NULL && tipo>0)
    {
    	this->tipo=tipo;
        retorno=0;
    }
    return retorno;
}

int eVehiculo_setpeso(eVehiculo* this,int peso)
{
    int retorno=1;

    if(this!=NULL && peso>0 && peso<1000000)
    {
    	this->peso=peso;
        retorno=0;
    }
    return retorno;
}



