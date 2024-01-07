int redC = 10;
int yellowC = 9;
int greenC = 8;

int redB = 7;
int yellowB = 6;
int greenB = 5;

int redA = 4;
int yellowA = 3;
int greenA = 2;

int yellowD1 = 13;
int yellowD2 = 12;
int redD = 11;
int pResistor = A1;
int value;
void setup()
{
  
  pinMode(redA, OUTPUT);
  pinMode(yellowA, OUTPUT);
  pinMode(greenA, OUTPUT);
  
  pinMode(redB, OUTPUT);
  pinMode(yellowB, OUTPUT);
  pinMode(greenB, OUTPUT);
  
  pinMode(redC, OUTPUT);
  pinMode(yellowC, OUTPUT);
  pinMode(greenC, OUTPUT);
  
  pinMode(redD, OUTPUT);
  pinMode(yellowD1, OUTPUT);
  pinMode(yellowD2, OUTPUT);
  pinMode(pResistor, INPUT);
  Serial.begin(9600); 

}

void loop()
{	value = analogRead(pResistor);
   Serial.println(value);
   if (value > 500)  
     dayMode();
  else
  {
    nightMode();
        
  }
}
void dayMode(){
    // green off, yellow on for 3 seconds
    digitalWrite(greenA, HIGH);
  	digitalWrite(redB, HIGH);
  	digitalWrite(redC, HIGH);
    digitalWrite(redD, HIGH);
  	delay(7000);
      //7sec
    digitalWrite(greenA, LOW);
    digitalWrite(yellowA, HIGH);
    digitalWrite(redB, LOW);
  	digitalWrite(redC, LOW);
    delay(1000);
  //
    digitalWrite(yellowA, LOW);
  	digitalWrite(redA, HIGH);
  	
  //
    digitalWrite(greenB, HIGH);
    digitalWrite(greenC, HIGH);
	  delay(15000);
      //
    digitalWrite(greenB, LOW);
    digitalWrite(yellowB, HIGH);
	  delay(1000);
      //
    digitalWrite(yellowB, LOW);
    digitalWrite(redB, HIGH);
//
    for (int i=0;i<5;i++){
      digitalWrite( redD, LOW); 
      digitalWrite( yellowD1, HIGH);
      digitalWrite( yellowD2, HIGH); 
  
      delay(500);                       
      digitalWrite( yellowD1, LOW);
      digitalWrite(yellowD2, LOW);
      delay(500);
    }
  //
  	delay(1000);
    digitalWrite(greenC, LOW);
	  digitalWrite(yellowC, HIGH);
    digitalWrite(redD, HIGH);
  	delay(1000);
    digitalWrite(yellowC, LOW);
    digitalWrite(redC, HIGH);
    digitalWrite(redA, LOW);
}

void nightMode()
  {
    digitalWrite(redB, LOW);
    digitalWrite(redC, LOW);
    digitalWrite(redD, LOW);
    digitalWrite(redA, LOW);
    
    digitalWrite( yellowD1, HIGH);
    digitalWrite( yellowD2, HIGH); 
    digitalWrite( yellowA, HIGH); 

    delay(500);                       
    digitalWrite( yellowD1, LOW);
    digitalWrite(yellowD2, LOW);
    digitalWrite( yellowA, LOW); 
     delay(500);     
  }
