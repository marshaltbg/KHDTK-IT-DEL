#include "display.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup_display() {
    // begin I2C for OLED
    Wire.begin(SCREEN_SDA, SCREEN_SCL);
    // begin OLED display
    // Address 0x3C for 128x64
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDR, false, false)) {
        Serial.println(F("SSD1306 allocation failed"));
        Serial.println("Restarting...");
        ESP.restart();
    }
}

void display_splash_screen() {
    // display splash screen
    display.clearDisplay();    
    display.setCursor(25, 15);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println(" NPK Sensor");
    display.setCursor(25, 35);
    display.setTextSize(1);
    display.print("Initializing");
    display.display();
}


void display_data(const SoilData& soilData) {
    const int DISPLAY_DELAY = 2000;

    const int& nitrogen = soilData.nitrogen;
    const int& phosphorus = soilData.phosphorus;
    const int& kalium = soilData.kalium;
    const float& pH = soilData.pH;
    const float& temperature = soilData.temperature;
    const float& humidity = soilData.humidity;
    const int& EC = soilData.EC;

    // display NPK
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(0, 5);
    display.print("N: ");
    display.print(nitrogen);
    display.setTextSize(1);
    display.print(" mg/kg");

    display.setTextSize(2);
    display.setCursor(0, 25);
    display.print("P: ");
    display.print(phosphorus);
    display.setTextSize(1);
    display.print(" mg/kg");

    display.setTextSize(2);
    display.setCursor(0, 45);
    display.print("K: ");
    display.print(kalium);
    display.setTextSize(1);
    display.print(" mg/kg");

    display.display();

    delay(DISPLAY_DELAY);

    // display pH, Temp, Hum
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(0, 5);
    display.print("pH:   ");
    display.print(pH);
    display.setTextSize(1);
    display.print("");

    display.setTextSize(2);
    display.setCursor(0, 25);
    display.print("Tem: ");
    display.print(temperature);
    display.setTextSize(1);
    display.print(" C");

    display.setTextSize(2);
    display.setCursor(0, 45);
    display.print("Hum: ");
    display.print(humidity);
    display.setTextSize(1);
    display.print(" %");

    display.display();

    delay(DISPLAY_DELAY);

    // display EC
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(0, 5);
    display.print("EC: ");
    display.print(EC);
    display.setTextSize(1);
    display.print(" us/cm");

    display.display();

    delay(DISPLAY_DELAY);
}

void clear_display() {
    display.clearDisplay();
    display.display();
}