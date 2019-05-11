#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "utn.h"

void menu()
{

    int optionMainMenu;
    eEmployee employeeList[EMPLOYEES];
    int flag = 0;

    do
    {
        system("cls");
        printf("*** Bienvenido al ABM ***\n\n");

        printf("1.- Alta de empleado.\n");
        printf("2.- Modificar empleado.\n");
        printf("3.- Baja de empleado.\n");
        printf("4.- Informes.\n");
        printf("5.- Salir.\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &optionMainMenu);
        printf("\n");

        switch(optionMainMenu)
        {
        case 1:
            addEmployee(employeeList, LENGTH);
            flag = 1;
            system("pause");
            break;

        case 2:
            if(flag == 0)
            {

                printf("Primero debe cargar algo en sistema. ");
            }
            else
            {

                editEmployee(employeeList, LENGTH);
            }
            system("pause");
            break;

        case 3:
            if(flag == 0)
            {

                printf("Primero debe cargar algo en sistema. ");
            }
            else
            {
                removeEmployee(employeeList, LENGTH);
            }
            system("pause");
            break;

        case 4:
            if(flag == 0)
            {

                printf("Primero debe cargar algo en sistema. ");
                system("pause");
            }
            else
            {
                subMenu(employeeList, LENGTH);
            }
            break;

        case 5:
            printf("Gracias por usar el ABM.\n");
            break;
        }
    }
    while(optionMainMenu !=5);
}

void subMenu(eEmployee employeeList[], int len)
{
    int optionSubMenu;
    int i;
    float sumaSueldos = 0;
    int contadorSueldos = 0;
    float promedioSueldos = 0;
    int contadorSobrePromedio = 0;
    int promedioFlag = 0;
    int sumaFlag = 0;

    do
    {
        system("cls");
        printf("1.- Listar empleados ordenados alfabeticamente por Apellido y Sector.\n");
        printf("2.- Total y promedio de salarios, y cuantos empleados superan el promedio.\n");
        printf("3.- Volver.\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &optionSubMenu);

        switch(optionSubMenu)
        {
        case 1:
            sortByAlphaAndSector(employeeList, len);
            printEmployees(employeeList, len);
            system("pause");
            break;
        case 2:
            for(i = 0; i<len; i++)
            {

                if(employeeList[i].isEmpty == 1 && sumaFlag == 0)
                {

                    sumaSueldos = sumaSueldos + employeeList[i].salary;
                    contadorSueldos++;
                }
                else
                {
                    sumaFlag = 1;
                }
            }


            promedioSueldos = sumaSueldos / contadorSueldos;
            printf("El total de los sueldos es %.2f\n", sumaSueldos);
            printf("El promedio de todos los sueldos es %.2f\n", promedioSueldos);
            for(i = 0; i < len; i++)
            {

                if(promedioSueldos < employeeList[i].salary && promedioFlag == 0)
                {

                    contadorSobrePromedio++;
                }
                else
                {
                    promedioFlag = 1;
                }
            }

            printf("La cantidad de empleados cuyo suedo supera el promedio es: %d\n", contadorSobrePromedio);
            system("pause");
            break;

        case 3:
            break;
        }
    }
    while(optionSubMenu != 3);
}

int initEmployees(eEmployee employeeList[], int len)
{
    int i=0;
    int ret = -1;

    for(i=0; i < len; i++)
    {
        employeeList[i].isEmpty = 0;
        ret = 0;
    }

    return ret;
}

int getFreeSpot(eEmployee employeeList[], int len)
{
    int index = -1, i=0;

    for(i=0; i<len; i++)
    {

        if( employeeList[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int addEmployee(eEmployee employeeList[], int len)
{
    eEmployee newEmployee;
    int index;
    int ret = -1;
    int isValid = 0;
    char isFloatAux[50];
    char isIntAux[50];


    index = getFreeSpot(employeeList, len);

    if(index == -1)
    {
        printf("No hay lugar.\n");

    }
    else
    {
        do
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            fgets(newEmployee.name, 51, stdin);
            quitarSaltoDeLinea(newEmployee.name);
            corregirNombreCompuesto(newEmployee.name);
            isValid = areCharacters(newEmployee.name);
            if(isValid == 1)
            {

                strncpy(employeeList[index].name, newEmployee.name, 51);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese apellido: ");
            fflush(stdin);
            fgets(newEmployee.lastName, 51, stdin);
            quitarSaltoDeLinea(newEmployee.lastName);
            corregirNombreCompuesto(newEmployee.lastName);
            isValid = areCharacters(newEmployee.lastName);
            if(isValid == 1)
            {

                strncpy(employeeList[index].lastName, newEmployee.lastName, 51);

            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese salario (con punto): ");
            scanf("%f", &newEmployee.salary);
            quitarSaltoDeLinea(gcvt(newEmployee.salary, 50, isFloatAux));
            isValid = isFloat(isFloatAux);
            if(isValid == 1)
            {

                employeeList[index].salary = newEmployee.salary;
            }
        }
        while(isValid != 1);

        do
        {
            printf("Ingrese sector: ");
            fflush(stdin);
            scanf("%d", &newEmployee.sector);
            quitarSaltoDeLinea(itoa(newEmployee.sector, isIntAux, 10));
            isValid = isInteger(isIntAux);
            if(isValid == 1)
            {

                employeeList[index].sector = newEmployee.sector;
            }
        }
        while(isValid != 1);

        if(isValid == 1)
        {
            employeeList[index].id = index + 1;
            employeeList[index].isEmpty = 1;
        }
    }

    return ret;
}

int removeEmployee(eEmployee employeeList[], int len)
{
    int ret = -1;
    int id;
    int index;
    char deleteEmployee;
    eEmployee employee;

    printf("Ingrese legajo: ");
    scanf("%d", &id);

    index = findEmployeeById(employeeList, len, id);

    if( index == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", id);
    }
    else
    {
        employee = employeeList[index];
        printEmployee(employee);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &deleteEmployee);
        if(deleteEmployee != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            employeeList[index].isEmpty = 0;
            printf("Se ha eliminado el empleado\n\n");
            ret = 0;
        }
        system("pause");
    }
    return ret;
}

int sortByAlphaAndSector(eEmployee employeeList[], int len)
{
    eEmployee auxEmp;
    int i, j;
    int ret = -1;
    if(employeeList!=NULL && len > 0)
    {
        for(i=0; i < len; i++)
        {
            for(j=0; j < len; j++)
            {
                if(strcmp(employeeList[j].lastName, employeeList[i].lastName) < 0)
                {
                    auxEmp = employeeList[i];
                    employeeList[i] = employeeList[j];
                    employeeList[j] = auxEmp;
                }
                else if(strcmp(employeeList[j].lastName, employeeList[i].lastName) == 0 && employeeList[j].sector < employeeList[i].sector)
                {
                    auxEmp = employeeList[i];
                    employeeList[i] = employeeList[j];
                    employeeList[j] = auxEmp;
                }
            }
        }
        ret = 0;
    }
    return ret;
}

void printEmployee(eEmployee employee)
{
    printf("%d\t%s\t%s\t%.2f\t%d", employee.id, employee.lastName, employee.name, employee.salary, employee.sector);
}

int printEmployees(eEmployee employeeList[], int len)
{
    int i;
    int ret = -1;

    for(i=0; i< len; i++)
    {
        if(employeeList[i].isEmpty == 1)
        {
            printEmployee(employeeList[i]);
            printf("\n");
            ret = 0;
        }
    }

    return ret;
}

int findEmployeeById(eEmployee employeeList[], int len, int id)
{
    int index=-1, i=0;

    for(i=0; i < len; i++)
    {
        if( employeeList[i].id == id && employeeList[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int editEmployee(eEmployee employeeList[], int len)
{

    int index;
    int idAux;
    int isValid;
    char isFloatAux[50];
    char isIntAux[50];
    int ret = -1;
    int optionEdit = 0;
    char idAuxChar[10];
    eEmployee employee;

    do
    {
        printf("Ingrese legajo a modificar: ");
        scanf("%d", &idAux);
        isValid = isInteger(itoa(idAux, idAuxChar, 10));
    }
    while(isValid != 1);

    index = findEmployeeById(employeeList, len, idAux);

    if(index == -1)
    {

        printf("No hay ningun empleado con el legajo %d\n", idAux);
    }
    else
    {
        do
        {
            employee = employeeList[index];

            system("cls");

            printEmployee(employee);

            printf("\nQue desea modificar?\n\n");

            printf("1.- Nombre.\n");
            printf("2.- Apellido.\n");
            printf("3.- Salario.\n");
            printf("4.- Sector.\n");
            printf("5.- Salir.\n");
            fflush(stdin);
            scanf("%d", &optionEdit);

            switch(optionEdit)
            {

            case 1:
                do
                {
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    fgets(employee.name, 51, stdin);
                    quitarSaltoDeLinea(employee.name);
                    corregirNombreCompuesto(employee.name);
                    isValid = areCharacters(employee.name);

                    if(isValid == 1)
                    {

                        strncpy(employeeList[index].name, employee.name, 51);
                        ret = 0;
                    }
                }
                while(isValid != 1);
                break;

            case 2:
                do
                {
                    printf("Ingrese apellido: ");
                    fflush(stdin);
                    fgets(employee.lastName, 51, stdin);
                    quitarSaltoDeLinea(employee.lastName);
                    corregirNombreCompuesto(employee.lastName);
                    isValid = areCharacters(employee.lastName);
                    if(isValid == 1)
                    {

                        strncpy(employeeList[index].lastName, employee.lastName, 51);
                        ret = 0;
                    }
                }
                while(isValid != 1);
                break;

            case 3:
                do
                {
                    printf("Ingrese salario (con punto): ");
                    scanf("%f", &employee.salary);
                    quitarSaltoDeLinea(gcvt(employee.salary, 50, isFloatAux));
                    isValid = isFloat(isFloatAux);
                    if(isValid == 1)
                    {

                        employeeList[index].salary = employee.salary;
                        ret = 0;
                    }
                }
                while(isValid != 1);
                break;

            case 4:
                do
                {
                    printf("Ingrese sector: ");
                    fflush(stdin);
                    scanf("%d", &employee.sector);
                    quitarSaltoDeLinea(itoa(employee.sector, isIntAux, 10));
                    isValid = isInteger(isIntAux);
                    if(isValid == 1)
                    {

                        employeeList[index].sector = employee.sector;
                        ret = 0;
                    }
                }
                while(isValid != 1);
                break;

            case 5:
                break;

            }

        }
        while(optionEdit != 5);
    }

    return ret;
}
