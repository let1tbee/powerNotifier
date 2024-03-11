#include <ESP8266WiFi.h>
#define WIFI_SSID "xxx"                                          // Wi-Fi network's name
#define WIFI_PASS "xxx"                                        // Wi-Fi network's pss
#define BOT_TOKEN "xxx"  // Bot token
#define MY_PERIOD 150000                                             //time in milliseconds delay between notification

#include <FastBot.h>
FastBot bot(BOT_TOKEN);
bool flag = 1;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  connectWiFi();
  bot.setChatID("xxx");  // tour Telegram ID
  bot.attach(newMsg);
}
void loop() {
  bot.tick();
  if (flag) pingBot();
}

void pingBot() {  //notification
  static uint32_t tmr1;
  if (millis() - tmr1 >= MY_PERIOD) {
    tmr1 = millis();
    bot.sendMessage("Power On");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void newMsg(FB_msg& msg) {  // commands handler
  if (msg.text == "/turn_on") {
    bot.sendMessage("Turned ON");
    flag = 1;
  }
  if (msg.text == "/turn_off") {
    bot.sendMessage("Turned OFF");
    flag = 0;
  }
}

void connectWiFi() {  // wi-fi connection setup
  delay(2000);
  Serial.begin(115200);
  Serial.println();
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() > 15000) ESP.restart();
  }
  Serial.println("Connected");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}