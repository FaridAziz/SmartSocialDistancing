#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");
  lcd.init(); // initialize the lcd
  lcd.backlight();

  lcd.home();
  mlx.begin();
}

void loop() {
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  lcd.home();
  lcd.print("SUHU : ");lcd.print(mlx.readObjectTempC());

  Serial.println();
  delay(1000);
}
