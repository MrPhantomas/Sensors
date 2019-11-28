// библиотека для работы с протоколом 1-Wire
#include <OneWire.h>
// библиотека для работы с датчиком DS18B20
#include <DallasTemperature.h>
// сигнальный провод датчика
#define ONE_WIRE_BUS 5
// создаём объект для работы с библиотекой OneWire
OneWire oneWire(ONE_WIRE_BUS);
// создадим объект для работы с библиотекой DallasTemperature
DallasTemperature sensor(&oneWire);
#include <BaseMQ.h>
#include <MQ2.h>
#include <TroykaMQ.h>
#define MQ2PIN   A0
// создаём объект для работы с датчиком
MQ2 mq2(MQ2PIN);
//#define smokePin A0    // определяем аналоговый выход к которому подключен датчик
void setup() {
	Serial.begin(9600);   // Устанавливаем скорость порта 9600 бод
	sensor.begin();
	sensor.setResolution(12);

	mq2.calibrate();
	mq2.getRo();
}
void loop() {
	//int analogSensor = analogRead(smokePin);    // считываем значения АЦП с аналогового входа
	//Serial.print(analogSensor);
	//Serial.print(" ");

	float temperature;
	// отправляем запрос на измерение температуры
	sensor.requestTemperatures();
	// считываем данные из регистра датчика
	temperature = sensor.getTempCByIndex(0);
	// выводим температуру в Serial-порт


	// ждём одну секунду*/
	float  propan = get_data_ppmpropan();
	float  methan = get_data_ppmmethan();
	float  smoke = get_data_ppmsmoke();
	// выводим значения газа в ppm
	//Serial.print("propan=");
	Serial.print(methan);
	//Serial.println(" ppm ");
	Serial.print(" ");
	// выводим значения газа в ppm
	//Serial.print("methan=");
	Serial.print(propan);
	//Serial.println(" ppm ");
	Serial.print(" ");
	// выводим значения газа в ppm
	//Serial.print("smoke=");
	Serial.print(smoke);
	//Serial.println(" ppm ");
	Serial.print(" ");
	Serial.print(temperature);
	Serial.println(" ");
	delay(1000);
}
// получение данных содержания пропана с датчика MQ2
float get_data_ppmpropan() {

	//Serial.println(mq2.readRatio());
	// получение значения 
	float value = mq2.readLPG();

	return value;
}
// получение данных содержания метана с датчика MQ2
float get_data_ppmmethan() {

	// Serial.println(mq2.readRatio());
	 // получение значения 
	float value = mq2.readMethane();

	return value;
}
// получение данных содержания дыма с датчика MQ2
float get_data_ppmsmoke() {

	//Serial.println(mq2.readRatio());
	// получение значения 
	float value = mq2.readSmoke();
	return value;
}
