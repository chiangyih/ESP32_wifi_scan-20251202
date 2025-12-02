#include <Arduino.h>
#include <WiFi.h>

void setup() {
  Serial.begin(9600);
  delay(1000);
  
  // 設定 WiFi 模式為站點模式
  WiFi.mode(WIFI_STA); // 設定為 Station 模式
  WiFi.disconnect(true); // 斷開任何現有的連接並清除配置
  
  Serial.println("\nESP32 WiFi SSID 掃描\n");
}

void loop() {
  // 開始掃描 WiFi 網路
  int networksFound = WiFi.scanNetworks();
  
  if (networksFound == 0) {
    Serial.println("未找到 WiFi 網路");
  } else {
    Serial.printf("找到 %d 個 WiFi 網路:\n", networksFound);
    for (int i = 0; i < networksFound; i++) {
      Serial.printf("%d. %s\n", i + 1, WiFi.SSID(i).c_str());
    }
  }
  
  WiFi.scanDelete();
  Serial.println();
  delay(5000); // 5 秒後重新掃描
}
