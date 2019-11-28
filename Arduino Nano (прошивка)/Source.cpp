// ���������� ��� ������ � ���������� 1-Wire
#include <OneWire.h>
// ���������� ��� ������ � �������� DS18B20
#include <DallasTemperature.h>
// ���������� ������ �������
#define ONE_WIRE_BUS 5
// ������ ������ ��� ������ � ����������� OneWire
OneWire oneWire(ONE_WIRE_BUS);
// �������� ������ ��� ������ � ����������� DallasTemperature
DallasTemperature sensor(&oneWire);
#include <BaseMQ.h>
#include <MQ2.h>
#include <TroykaMQ.h>
#define MQ2PIN   A0
// ������ ������ ��� ������ � ��������
MQ2 mq2(MQ2PIN);
//#define smokePin A0    // ���������� ���������� ����� � �������� ��������� ������
void setup() {
	Serial.begin(9600);   // ������������� �������� ����� 9600 ���
	sensor.begin();
	sensor.setResolution(12);

	mq2.calibrate();
	mq2.getRo();
}
void loop() {
	//int analogSensor = analogRead(smokePin);    // ��������� �������� ��� � ����������� �����
	//Serial.print(analogSensor);
	//Serial.print(" ");

	float temperature;
	// ���������� ������ �� ��������� �����������
	sensor.requestTemperatures();
	// ��������� ������ �� �������� �������
	temperature = sensor.getTempCByIndex(0);
	// ������� ����������� � Serial-����


	// ��� ���� �������*/
	float  propan = get_data_ppmpropan();
	float  methan = get_data_ppmmethan();
	float  smoke = get_data_ppmsmoke();
	// ������� �������� ���� � ppm
	//Serial.print("propan=");
	Serial.print(methan);
	//Serial.println(" ppm ");
	Serial.print(" ");
	// ������� �������� ���� � ppm
	//Serial.print("methan=");
	Serial.print(propan);
	//Serial.println(" ppm ");
	Serial.print(" ");
	// ������� �������� ���� � ppm
	//Serial.print("smoke=");
	Serial.print(smoke);
	//Serial.println(" ppm ");
	Serial.print(" ");
	Serial.print(temperature);
	Serial.println(" ");
	delay(1000);
}
// ��������� ������ ���������� ������� � ������� MQ2
float get_data_ppmpropan() {

	//Serial.println(mq2.readRatio());
	// ��������� �������� 
	float value = mq2.readLPG();

	return value;
}
// ��������� ������ ���������� ������ � ������� MQ2
float get_data_ppmmethan() {

	// Serial.println(mq2.readRatio());
	 // ��������� �������� 
	float value = mq2.readMethane();

	return value;
}
// ��������� ������ ���������� ���� � ������� MQ2
float get_data_ppmsmoke() {

	//Serial.println(mq2.readRatio());
	// ��������� �������� 
	float value = mq2.readSmoke();
	return value;
}
