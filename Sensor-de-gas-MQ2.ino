/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB http://bit.ly/1UvumG9
*/

const int sensorPinT = A0;

float roT = 10;
float gasT, vT = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando calibracion");
  do {
    gasT = analogRead(sensorPinT);
    float resistanceT = (((float)5 * (1023 - gasT) / gasT));
    int i = 1;
    for (i = 1; i < 51; i++) {
      vT = resistanceT * i;
      Serial.println(vT);
      delay(50);
    }
  } while (vT < 12500);
  vT = ((vT / 50) / 9.83);
  roT = vT;
  Serial.println("Calibracion finalizada");
}

void loop() {
  float resistanceT, gasT2 = 0;
  gasT2 = analogRead(sensorPinT);
  for (int i = 1; i < 6; i++) {
    resistanceT = (((float)5 * (1023 - gasT2) / gasT2)) * i;
    delay(50);
  }
  resistanceT = resistanceT / 5;
  int finalvalT = (pow(10, (((log(resistanceT / roT) - 0.21) / -0.47) + 2.3)));
  Serial.print(finalvalT);
  Serial.println(" ppm");
  delay(250);
}
