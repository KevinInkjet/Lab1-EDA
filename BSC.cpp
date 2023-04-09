//Input:
//- Two integers x,y in the range [-128,127].

//Output:
//- Binary strings representing x and y in 8-bit 2's Complement format.
//- Result of the binary sum between x and y in both 8-bit binary Complement to 2 and decimal format. The addition operations must be performed by directly manipulating the values in their binary version and with binary/logical operators.
//- In case the sum overflows, the error must be reported. The validation of the overflow should also be performed using directly the values in their binary version and with binary/logical operators.


#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	int x, y, centenas, decenas, unidades, unidadesy, decenasy, centenasy, cadenax[8], i, cadenay[8], acarreo[8], resultado[8], res, binx[8], biny[8];
	bool reversion = false, negativox = false, negativoy = false, desborde = false;
	
	do
	{
		cout << "Dame un numero en el rango [-128, 127]" << endl;
		cin>>x;
	}while(x < -128 || x > 127);
	do
	{
		cout << "Dame otro numero en el rango [-128, 127]" << endl;
		cin>>y;
	}while(y < -128 || y > 127);
	
	//Convertir x a binario
	if(x<0)
	{
		x = x*-1;
		negativox = true;
	}
	centenas = x / 100;
	decenas = (x - (centenas*100))/10;
	unidades = x - ((centenas*100)+(decenas*10));
	
	//cout << "Centenas de x: " << centenas << endl;
	//cout << "Decenas de x: " << decenas << endl; //VALIDACION
	//cout << "Unidades de x: " << unidades << endl;
	
	//Convertir y a binario
	if(y<0)
	{
		y = y*-1;
		negativoy = true;
	}
	centenasy = y / 100;
	decenasy = (y - (centenasy*100))/10;
	unidadesy = y - ((centenasy*100)+(decenasy*10));
	
	//cout << "Centenas de y: " << centenasy << endl;
	//cout << "Decenas de y: " << decenasy << endl; //VALIDACION
	//cout << "Unidades de y: " << unidadesy << endl;
	
	//CONVIERTE X A BINARIO Y LO GUARDA EN CADENAX
	for(i=0; i<8; i++)
	{
		cadenax[i] = 0;
		acarreo[i] = 0;
	}
	
	if(x/128 == 1)
	{
		x = x-128;
		cadenax[0]=1;
	}
	if(x/64 == 1)
	{
		x = x-64;
		cadenax[1]=1;
	}
	if(x/32 == 1)
	{
		x = x-32;
		cadenax[2]=1;
	}
	if(x/16 == 1)
	{
		x = x-16;
		cadenax[3]=1;
	}
	if(x/8 == 1)
	{
		x = x-8;
		cadenax[4]=1;
	}
	if(x/4 == 1)
	{
		x = x-4;
		cadenax[5]=1;
	}
	if(x/2 == 1)
	{
		x = x-2;
		cadenax[6]=1;
	}
	if(x/1 == 1)
	{
		x = x-1;
		cadenax[7]=1;
	}
	
	/*
	cout << "X en Binario: ";
	for(i=0; i<8; i++)
	{
		cout << cadenax[i]; //VALIDACIÓN DE QUE X ESTÁ EN BINARIO
	}
	*/
	
	//Guardar el valor binario en binx para posteriormente utilizarlo en la suma
	for(i=0; i<8; i++)
	{
		binx[i] = cadenax[i];
	}
	
	//CONVIERTE Y A BINARIO Y LO GUARDA EN CADENAY
	for(i=0; i<8; i++)
	{
		cadenay[i] = 0;
		resultado[i] = 0;
	}
	
	if(y/128 == 1)
	{
		y = y-128;
		cadenay[0]=1;
	}
	if(y/64 == 1)
	{
		y = y-64;
		cadenay[1]=1;
	}
	if(y/32 == 1)
	{
		y = y-32;
		cadenay[2]=1;
	}
	if(y/16 == 1)
	{
		y = y-16;
		cadenay[3]=1;
	}
	if(y/8 == 1)
	{
		y = y-8;
		cadenay[4]=1;
	}
	if(y/4 == 1)
	{
		y = y-4;
		cadenay[5]=1;
	}
	if(y/2 == 1)
	{
		y = y-2;
		cadenay[6]=1;
	}
	if(y/1 == 1)
	{
		y = y-1;
		cadenay[7]=1;
	}
	
	/*
	cout << endl;
	cout << "Y en Binario: ";
	for(i=0; i<8; i++)
	{
		cout << cadenay[i]; //VALIDACIÓN DE QUE Y ESTÁ EN BINARIO
	}
	*/
	
	//Guardar el valor binario en biny para posteriormente utilizarlo en la suma
	for(i=0; i<8; i++)
	{
		biny[i] = cadenay[i];
	}
	
	//VOLVER A X BINARIO COMPLEMENTO A 2
	if(negativox == true)
	{
		for(i=7; i>=0; i--)
		{
			if(cadenax[i] == 1 && reversion == true)
			{
				cadenax[i] = 0;
			}
			else if(cadenax[i] == 0 && reversion == true)
			{
				cadenax[i] = 1;
			}
			if(cadenax[i] == 1 && reversion == false)
			{
				reversion = true;
			}
		}
	}
	
	// VALIDACIÓN DE INVERSIÓN DE BITS
	cout << endl;
	cout << "Complemento a2 de X: ";
	for(i=0; i<8; i++)
	{
		cout << cadenax[i];
	}
	
	reversion = false;
	//VOLVER A Y BINARIO COMPLEMENTO A 2
	if(negativoy == true)
	{
		for(i=7; i>=0; i--)
		{
			if(cadenay[i] == 1 && reversion == true)
			{
				cadenay[i] = 0;
			}
			else if(cadenay[i] == 0 && reversion == true)
			{
				cadenay[i] = 1;
			}
			if(cadenay[i] == 1 && reversion == false)
			{
				reversion = true;
			}
		}
	}
	reversion = false;

	// VALIDACIÓN DE INVERSIÓN DE BITS
	cout << endl;
	cout << "Complemento a2 de Y: ";
	for(i=0; i<8; i++)
	{
		cout << cadenay[i];
	}
	
	//SUMA BINARIA
	for(i=7; i>=0; i--)
	{
		if(cadenax[i] == 0 && cadenay[i] == 0 && acarreo[i] == 0)
		{
			resultado[i] = 0;
		}
		if(cadenax[i] == 0 && cadenay[i] == 0 && acarreo[i] == 1)
		{
			resultado[i] = 1;
		}
		if(cadenax[i] == 1 && cadenay[i] == 1 && acarreo[i] == 0)
		{
			acarreo[i-1] = 1;
			resultado[i] = 0;
		}
		if(cadenax[i] == 1 && cadenay[i] == 1 && acarreo[i] == 1)
		{
			acarreo[i-1] = 1;
			resultado[i] = 1;
		}
		if(cadenax[i] == 1 && cadenay[i] == 0 && acarreo[i] == 0)
		{
			resultado[i] = 1;
		}
		if(cadenax[i] == 1 && cadenay[i] == 0 && acarreo[i] == 1)
		{
			resultado[i] = 0;
			acarreo[i-1] = 1;
		}
		if(cadenax[i] == 0 && cadenay[i] == 1 && acarreo[i] == 0)
		{
			resultado[i] = 1;
		}
		if(cadenax[i] == 0 && cadenay[i] == 1 && acarreo[i] == 1)
		{
			resultado[i] = 0;
			acarreo[i-1] = 1;
		}
	}
	
	//VER SI DESBORDA(BORRAR SI NO FUNCIONA)
	if(cadenax[0] == 0 && cadenay[0] == 0 && resultado[0] == 1)
	{
		cout << endl;
		cout << "Cuidado, hubo un desborde en la suma" << endl;
		desborde = true;
	}
	if(cadenax[0] == 1 && cadenay[0] == 1 && resultado[0] == 0)
	{
		cout << endl;
		cout << "Cuidado, hubo un desborde en la suma" << endl;
		desborde = true;
	}
	//VER SI DESBORDA ^
	
	if(desborde == false)
	{
		cout << endl;
		cout << "Resultado de suma del complemento a 2 de x con el complemento a 2 de y: ";
		for(i=0; i<8; i++)
		{
			cout << resultado[i];
		}
		
		res = resultado[7] + 2*resultado[6] + 4*resultado[5] + 8*resultado[4] + 16*resultado[3] + 32*resultado[2] + 64*resultado[1] + 128*resultado[0];
		
		if(resultado[0] == 0)
		{
			cout << endl;
			cout << "Resultado de la suma en decimal: " << res << endl;
		}
		else
		{
		
			res = pow(2,8) - sqrt(res*res);	
			if(resultado[0] == 1)
			{
				res = res*-1;
			}
			cout << endl;
			cout << "Resultado de la suma en decimal: " << res << endl;
		}	
	}
}
