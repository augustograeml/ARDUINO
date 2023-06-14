/*-------------
Dó – 262 Hz
Ré – 294 Hz
Mi – 330 Hz
Fá – 349 Hz
Sol – 392 Hz
Lá – 440 Hz
Si – 494 Hz
#Dó – 528 Hz
 -------------*/
 #define DO 262
 #define RE 294
 #define MI 330
 #define FA 349
 #define SOL 392
 #define LA 440
 #define SI 494
 #define DO2 528

int buzzer = 2;
int pausa = 1400;
int i;
 
void tocaAyrtonSenna()
{
 for(i=0; i < 2; i++)
 {
  delay(1400);
  tone(buzzer, MI);
  delay(1400);
  tone(buzzer, MI);
  delay(1400);
  tone(buzzer, RE);
  delay(1400);
  tone(buzzer, RE);
  delay(1400);
  tone(buzzer, RE);
  delay(1400);
  tone(buzzer, DO);
  delay(1400);
 }
 tone(buzzer, MI);
 delay(1400);


  
}
void setup()
{
  pinMode(buzzer, OUTPUT);
}
void loop()
{

 tocaAyrtonSenna();

  
}
