const int sensorPinT = A0;
float roT = 10;
float gasT, v1T = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("Iniciando calibracion");
  do{
    gasT = analogRead(sensorPinT);
    float resistanceT = (((float)5*(1023-gasT)/gasT));
    int i=1;
    for(i=1; i<51; i++){
      v1T = resistanceT * i;
      Serial.println(v1T);
      delay(50);
    }
  }while(v1T < 12500);
  v1T =((v1T/50)/9.83);
  roT = v1T;                        
  Serial.println("Calibracion finalizada");
}

void loop(){
  float resistanceT, gasT2 = 0;
  gasT2 = analogRead(sensorPinT);
  for(int i=1; i<6; i++){
    resistanceT = (((float)5*(1023-gasT2)/gasT2))*i;
    delay(50);
  }
  resistanceT = resistanceT/5; 
  int finalvalT = (pow(10,(((log(resistanceT/roT)-0.21)/-0.47) + 2.3)));
  Serial.print(finalvalT);
  Serial.println(" ppm");
  delay(250);
}
