#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <arduinoFFT.h>

#define SAMPLES 512
#define SAMPLING_FREQUENCY 5600 // Hz, laskettiin plotista, oli 8000
#define MIC_PIN 34
#define OLED_RESET 4


Adafruit_SSD1306 display(OLED_RESET);
arduinoFFT FFT = arduinoFFT();

double vReal[SAMPLES];
double vImag[SAMPLES];
int bar1[10];


unsigned long sampling_period_us;

void setup() {
  Serial.begin(115200);
  
  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQUENCY));
}

void loop() {
  // Lue äänidata mikrofonilta
  analogRead(MIC_PIN);
  for (int i = 0; i < SAMPLES; i++) {
    vReal[i] = analogRead(MIC_PIN)-2000;
    //delayMicroseconds(sampling_period_us);
  }

  for (int i = 0; i < SAMPLES; i++) {
    vImag[i] = 0;
  } 

  /*
  for (int i = 0; i < SAMPLES; i++) {
    Serial.println(vReal[i]);  
  }
  */
  
  // Suorita FFT
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
  

  vReal[6]=-10000;

  for (int i = 6; i < 256; i++) {
    Serial.println(vReal[i]);  
  }

  for (int i = 0; i < 10; i++) {
    //bars[i]=i*100;  
  }

  for (int i = 0; i < 10; i++) {
    bar1[i]=0;
    for (int j = 0; j < 25; j++) {
      if (bar1[i]<vReal[6+j+(i*25)]) {
          bar1[i]=(int)vReal[6+j+(i*25)];
        }  
    }
  }
  
  // Näytä palkit OLED-näytöllä
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  int barWidth = display.width() / 10; // 10 taajuuspalkkia
  for (int i = 0; i < 10; i++) {
    int barHeight = map((int)bar1[i], 0, 50000, 0, display.height());
    display.fillRect(i * barWidth, display.height() - barHeight, barWidth - 1, barHeight, SSD1306_WHITE);
  }
  display.display();
}