//Laboratorio 1
//Kevin Samuel Cárdenas Muñoz
//Compilador: Dev-C++

//Entrada:
//- Dos números enteros x,y en el rango [-128,127]

//Salida:
//- Cadenas binarias que representen x e y en formato Complemento a 2 de 8 bits.
//- Resultado de la suma binaria entre x e y tanto en formato binario Complemento a 2 de 8 bits como en decimal. Las operaciones de la suma deben realizarse manipulando directamente los valores en su versión binaria y con operadores binarios/lógicos.
//- En caso de que la suma se desborde deberán reportan el error. La validación del desbordamiento también deberá realizarse utilizando directamente los valores en su versión binaria y con operadores binarios/lógicos.
//

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	int x, y, centenas, decenas, unidades, unidadesy, decenasy, centenasy, cadenax[8], i, cadenay[8], acarreo[8], resultado[8], res, binx[8], biny[8];
	bool reversion = false, negativox = false, negativoy = false;
	
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
	
	cout << "X en Binario: ";
	for(i=0; i<8; i++)
	{
		cout << cadenax[i]; //VALIDACIÓN DE QUE X ESTÁ EN BINARIO
	}
	
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
	
	cout << endl;
	cout << "Y en Binario: ";
	for(i=0; i<8; i++)
	{
		cout << cadenay[i]; //VALIDACIÓN DE QUE Y ESTÁ EN BINARIO
	}
	
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
	
	
	cout << endl;
	cout << "Resultado de suma del complemento de x con el de y: ";
	for(i=0; i<8; i++)
	{
		cout << resultado[i];
	}
	
	//CONVERTIR A DECIMAL EL RESULTADO DE LA SUMA BINARIA COMPLEMENTO A 2
	res = resultado[7] + 2*resultado[6] + 4*resultado[5] + 8*resultado[4] + 16*resultado[3] + 32*resultado[2] + 64*resultado[1] + 128*resultado[0];
	
	/*
	//CONVERTIR EL RESULTADO DE LA SUMA EN COMPLEMENTO A 2
	for(i=7; i>=0; i--)
		{
			if(resultado[i] == 1 && reversion == true)
			{
				resultado[i] = 0;
			}
			else if(resultado[i] == 0 && reversion == true)
			{
				resultado[i] = 1;
			}
			if(resultado[i] == 1 && reversion == false)
			{
				reversion = true;
			}
		}
	 reversion = false;
	/*
	res = 2^(8)-res;
	if()
	*/
	//CONVERTIR A DECIMAL EL RESULTADO DE LA SUMA BINARIA COMPLEMENTO A 2 2.0 borrar si no sirve
	
	res = pow(2,8) - sqrt(res*res);
	
	//res = resultado[7] + 2*resultado[6] + 4*resultado[5] + 8*resultado[4] + 16*resultado[3] + 32*resultado[2] + 64*resultado[1] + 128*resultado[0];
	
	cout << endl;
	cout << "Resultado de la suma en decimal: " << res << endl;
	
}
