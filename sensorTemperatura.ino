// C++ code
//
int PinTemperatura = 0;
int PinMotor = 11;
int PinBuzina = 8;
int PinLed = 7;


void setup()
{

  pinMode(PinLed, OUTPUT); 
  pinMode(PinBuzina, OUTPUT);
  pinMode(PinMotor, OUTPUT);
  pinMode(PinTemperatura, INPUT);
  
  Serial.begin(9600);
  

}

void loop()
{
  
  //para fazer a leitura do sensor sem usar biblioteca, é possível usar o seguinte algoritmo
  // https://www.tinkercad.com/things/5uF26oelLJF-copy-of-sensor-de-temperatura-tmp36/editel
  int tmp = analogRead(A0); //faz a leitura do pino de temperatura
  float voltage = (tmp * 5.0)/1024; // transforma o valor em voltagem
  float milliVolt = voltage * 1000; //transforma o falor em milivolts
  float temperatura = (milliVolt-500)/10; //transforma a voltagem em temperatura
  Serial.println(temperatura);
  
  
  if (temperatura <= 30) {

  digitalWrite(PinMotor, LOW);
  digitalWrite(PinLed, LOW);
  digitalWrite(PinBuzina, LOW);

  }   
  
  if (temperatura > 30 and temperatura <= 50) {

  digitalWrite(PinMotor, HIGH);
  digitalWrite(PinLed, LOW);
  digitalWrite(PinBuzina, LOW);
   
  }
  
  if (temperatura > 50) {

  digitalWrite(PinMotor, HIGH);
  digitalWrite(PinLed, HIGH);
  tone(PinBuzina, 440);
   
  }
  
  
  
    delay(1000); // Esperar 1 segundo
}