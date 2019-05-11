/*******************************************************************
*Programa: ABM
*
*Objetivo:
    Alta, Baja y Modificacion de empleados en un array de 1000 campos.
    Informa el istado de los empleados ordenados alfabéticamente por Apellido y Sector.
    Informa el total y promedio de los salarios, y cuántos empleados superan el salario promedio.
*
*Version del 10 de abril de 2019
*Autor: Adrian Brizuela
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"


int main()
{
    eEmployee employeeList[EMPLOYEES];

    menu(employeeList);

    return 0;
}
