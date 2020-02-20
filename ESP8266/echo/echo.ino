#include <ESP8266WiFi.h>

const char ssid[] = "espServer";
const char password[] = "11111111";

IPAddress local_IP(192,168,4,1);
IPAddress gateway(192,168,4,0);
IPAddress subnet(255,255,255,0);
WiFiServer server(80);
WiFiClient client;

void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting soft-AP ... ");
  boolean result = WiFi.softAP(ssid, password);
  if(result == true){
    Serial.println("Ready");
  }else{
    Serial.println("Failed!");
  }

  WiFi.softAPConfig(local_IP, gateway, subnet);
  server.begin();
}

void loop()
{
//  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
//  Serial.println(ESP.getCpuFreqMHz());
//  delay(3000);
  if (!client.connected()){
    client = server.available();
    return;
  }

  if(client.available()){
    char c =  client.read();
    Serial.print(c);
    client.write(c);
  }

}
