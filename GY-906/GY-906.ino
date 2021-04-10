#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo myservo;
int echoPin = 3;
int trigPin = 2;
long duration, distance;
int data = 0, measurements_history = 0;
float last_measurements = 0.00;
String result;
int pos = 0;
float suhuAkhir = 0.00;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
String datamcu = "";

void setup() {
  myservo.attach(8);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //  Serial.println("Adafruit MLX90614 test");
  lcd.init(); // initialize the lcd
  lcd.backlight();
  delay(1000);
  mlx.begin();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Menghitung jarak (dalam cm) berdasarkan kecepatan gelombang
  distance = duration / 58.2;
  //  Serial.println(distance);

  // Selama data serial ada
  while (Serial.available() > 0) {
    // Ambil data serial kemudian masukkan ke variabel data
    datamcu = datamcu + char(Serial.read()); // menggabungkan data yang dikirim dari serial yang sifatnya 1 per 1 maka memakai char
  }
  Serial.println(datamcu);
  delay(100);


  if (distance < 10 && data == 0) {
    data = 1;
    int var = 0;
    while (var < 5) {
      display_measurements();
      delay(500);
      var++;
    }
    measurements_history = 1;
    data = 0;
    delay(2000);
  }

  if (measurements_history == 1) {
    display_last_measurements();
    bukaPintu();
    measurements_history = 0;
  } else {
    delay(5000);
    myservo.write(90);
    display_first();
    Serial.println("Dekatkan Kepala Anda");
  }
  delay(100);

}

void bukaPintu() {
  if (last_measurements <= 38) {
    myservo.write(180);
  }
}

void display_first() {
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("Dekatkan Kepala");
  lcd.setCursor (0, 1);
  lcd.print("Anda");
}

void display_last_measurements() {
  lcd.clear();

  if (last_measurements >= 38) {
    result = "Suhu Bahaya";
  } else {
    result = "Suhu Aman";
  }

  lcd.setCursor (0, 0);
  lcd.print("Suhu : ");
  lcd.print(last_measurements);
  lcd.print((char)223);
  lcd.print("C    ");
  lcd.setCursor (0, 1);
  lcd.print(result);
  delay(1000);
}

void display_measurements() {
  lcd.clear();
  //  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("Object = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  lcd.home();
  lcd.print("Suhu : ");
  lcd.print(mlx.readObjectTempC());
  lcd.print((char)223);
  lcd.print("C    ");

  last_measurements = mlx.readObjectTempC();
}
