#include <SPI.h>
#include <Ethernet.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"
int temp= 0;
int hum = 0;
Adafruit_AM2320 am2320 = Adafruit_AM2320();
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = {192, 168, 1, 18 }; //Enter the IP of ethernet shield
byte serv[] = {192, 168, 1, 10} ; //Enter the IPv4 address
EthernetClient cliente;

void setup() {
Serial.begin(9600); //setting the baud rate at 9600
Ethernet.begin(mac, ip);
am2320.begin();
}

void loop() {
float hum = am2320.readHumidity();
float temp = am2320.readTemperature();

 if (cliente.connect(serv, 80)) { //Connecting at the IP address and port we saved before
Serial.println("connected");
cliente.print("GET /ethernet/data.php?"); //Connecting and Sending values to database
cliente.print("temperature=");
cliente.print(temp);
cliente.print("&humidity=");
cliente.println(hum);


//Printing the values on the serial monitor
Serial.print("Temperature= ");
Serial.println(temp);
Serial.print("Humidity= ");
Serial.println(hum);
cliente.stop(); //Closing the connection
}
else {
// if you didn't get a connection to the server:
Serial.println("connection failed");
}
delay(5000);
}
