/*----------------------------------------
MUDA COR RGB DE ACORDO COM O POTENCIOMETRO
----------------------------------------*/
int verde = 11, azul = 12, vermelho = 13;

void setup() {
  // put your setup code here, to run once:
pinMode(azul, OUTPUT);
pinMode(verde, OUTPUT);
pinMode(vermelho, OUTPUT);
pinMode(A0, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float pot = analogRead(A0);
  Serial.println(pot);
  if(pot <= 300)
    {
       digitalWrite(12, HIGH);
    }
   else
   { 
       digitalWrite(12, LOW);
   }
   if(pot > 300 && pot < 600)
   {
    
      digitalWrite(11, HIGH);
 
   }
   else
   {
       digitalWrite(11, LOW); 
   }
   if(pot >= 600)
   {
    
      digitalWrite(13, HIGH);
 
   }
   else
   {
       digitalWrite(13, LOW); 
   }

}
