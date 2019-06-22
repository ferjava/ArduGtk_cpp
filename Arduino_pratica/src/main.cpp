#include <Arduino.h>

const int  LED=11 ;
char data ;
char alto  = 'H';
char bajo = 'L';

void setup() {
	Serial.begin(9600);//Inicializa la comunicacion con el puerto en serie
	pinMode(LED,OUTPUT);
	Serial.println("Programa de prueba ");
}

void loop() {

	if(Serial.available()>0 )
	{
		data = Serial.read();//lee el byte de dat




		//enciende el led
		if(data == alto)
		{
		digitalWrite(LED,HIGH);
		Serial.println("Alto");
		}
		//apaga  el led
		else if(data == bajo)
		{
		digitalWrite(LED,LOW);
		Serial.println("Bajo");
		}


	}

}