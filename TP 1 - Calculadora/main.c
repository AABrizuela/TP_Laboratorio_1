/*******************************************************************
*Programa: Calculadora
*
*Objetivo:
    Ingreso numeros para realizar 5 tipos de operaciones.
    Suma, resta, multiplicacion, division y factorial.
*
*Version del 3 de abril de 2019
*Autor: Adrian Brizuela
*
********************************************************************/

//Bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

//Funcion main.
int main()
{

    int option = 0;
    int firstNumberValidation = 1;
    int secondNumberValidation = 1;
    int operationsDone = 1;
    float firstNumber = 0;
    float secondNumber = 0;
    float sum = 0;
    float multiplication = 0;
    float division = 0;
    float subtraction = 0;
    float factorial = 0;

    do{
		system("cls");
		printf("\t\t**CALCULADORA**\n\n");
		printf("1.- Ingresar 1er operando. (A = %.2f)\n", firstNumber);
		printf("2.- Ingresar 2do operando. (B = %.2f)\n", secondNumber);
		printf("3.- Calcular todas las operaciones.\n");
		printf("\ta) Calcular la suma. (A+B)\n");
		printf("\tb) Calcular la resta. (A-B)\n");
		printf("\tc) Calcular la division. (A/B)\n");
		printf("\td) Calcular la multiplicacion. (A*B)\n");
		printf("\te) Calcular el factorial. (A!)\n");
		printf("4.- Informar resultados.\n");
		printf("5.- Salir.\n");
		printf("\n");

		printf("Ingrese opcion: ");
		scanf("%d", &option);

		switch(option){

			case 1:
				printf("Ingrese numero: ");
				scanf("%f", &firstNumber);
				firstNumberValidation = 0;
				break;

			case 2:
				if(firstNumberValidation == 0){

				printf("Ingrese numero: ");
				scanf("%f", &secondNumber);
				secondNumberValidation = 0;

				}else{

					printf("Debe ingresar el primer Operando");

				}
				break;

			case 3:
				if(firstNumberValidation == 0 && secondNumberValidation == 0){
					printf("Calculando...");
					sum = fSum(firstNumber, secondNumber);
					multiplication = fMultiplication(firstNumber, secondNumber);

					if(secondNumber != 0){
						division = fDivision(firstNumber, secondNumber);
					}

					subtraction = fSubtraction(firstNumber, secondNumber);

					if(firstNumber > 0){
						factorial = fFactorial(firstNumber);
					}
					operationsDone = 0;
					printf("resuleto. ");
				}else{
					printf("Primero debe ingresar los numeros. ");
				}
				system("pause");
				break;

			case 4:
				if(operationsDone == 0){
					printf("\ta) ''El resultado de A+B es: %.2f''\n", sum);
					printf("\tb) ''El resultado de A-B es: %.2f''\n", subtraction);
					if(secondNumber == 0){
						printf("\tc) ''No se puede dividir por 0''\n");
					}else{
						printf("\tc) ''El resultado de A/B es %.2f''\n", division);
					}
					printf("\td) ''El resultado de A*B es: %.2f''\n", multiplication);
					if(firstNumber < 0){
						printf("\te) No se puede calcular el factorial de numeros negativos. ");
					}else{
						printf("\te) ''El resultado de A! es: %.2f''\n", factorial);
					}
					system("pause");
				}else{
					printf("Ninguna operacion fue realizada. No hay resultados para mostrar. ");
					system("pause");
				}

				break;

			case 5:
				break;

			default:
				printf("Las opciones van del 1 al 5.");

		}

    }while(option != 5);

    return 0;
}
