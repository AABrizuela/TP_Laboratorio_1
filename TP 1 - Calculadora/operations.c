//Bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

//Funcion suma.
float fSum(float firstNumber, float secondNumber){

	float result;

	result = firstNumber + secondNumber;

	return result;

}

//Funcion multiplicacion.
float fMultiplication(float firstNumber, float secondNumber){

	float result;

	result = firstNumber * secondNumber;

	return result;
}

//Funcion division.
float fDivision(float firstNumber, float secondNumber){

	float result;

	result = firstNumber / secondNumber;

	return result;
}

//Funcion resta.
float fSubtraction(float firstNumber, float secondNumber){

	float result;

	result = firstNumber - secondNumber;

	return result;
}

//Funcion factorial.
float fFactorial(float firstNumber){

	int i;
    long result = 1;

    while (firstNumber < 0)
    {
        printf("No se puede calcular el factorial de numeros negativos.\n");
        scanf("%f", &firstNumber);
    }

    for (i = 1; i <= firstNumber; i++)
    {

        result = result * i;

    }

	return result;

}
