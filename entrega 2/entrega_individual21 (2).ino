/**------------------------------------------------------------------------------------------------------------------------
Augusto César Graeml - Antonio Galvão - Caique Ferraz - 15/06/2023

LedSortido com música de vitória e derrota - CSX10 - Prof. Pelisson

https://www.tinkercad.com/things/1gYS4haV2mC-entregaindividual2/editel?sharecode=UK5LognYh0rFIzYGc4fKVPMOmEJPUfX0g_ueqt7PPso
-------------------------------------------------------------------------------------------------------------------------**/

int button1 = 5, button2 = 4, button3 = 3;
int led1 = 13, led2 = 12, led3 = 11;
int buzzer = 2;
int i, led;
char* vitoria[] = {"Do","Pausa", "Do","Pausa" ,"Re",     "Pausa", "Do", "Pausa", "Fa", "Pausa" , "Mi",  "Pausa", "Do", "Pausa", "Do","Pausa", "Re","Pausa", "Do", "Pausa", "Sol", "Pausa", "Fa", "Fim"};
int duracao[] =   {400,  10,      400,  10   , 1000,      10 ,   400,    100,    400,    100  ,  1000,    400,    400,   10,     400,   10  , 800,   100 ,  400,    100,   400,    100 ,   800};   
char* derrota[] = {"Si","Pausa","La","Pausa","Mi","Pausa","La","Pausa", "Do#","Pausa", "Note"  ,"Pausa",  "La",  "Fim"}; 
int dur[] = {       400,  10,   400,   10,   1000, 300,   300,  10,    300,   100  ,   800,      200 ,   1000};

void tocar(char* mus[], int tempo[]){
  int tom = 0;
  for(int i = 0; mus[i]!="Fim";i++){
    if(mus[i] == "Do") tom = 262;
    if(mus[i] == "Re") tom = 294;
    if(mus[i] == "Mi") tom = 330;
    if(mus[i] == "Fa") tom = 349;
    if(mus[i] == "Sol") tom = 392;
    if(mus[i] == "La") tom = 440;
    if(mus[i] == "Si") tom = 494;
    if(mus[i] == "Do#") tom = 528;
    if(mus[i] == "Re#") tom = 622;
    if(mus[i] == "Fa#") tom = 370;
    if(mus[i] == "Sol#") tom = 415;
    if(mus[i] == "La#") tom = 466;
    if(mus[i] == "Pausa") tom = 0;
    if(mus[i] == "Note") tom = 587;
    if(mus[i] == "Teste") tom = 627;
    tone(buzzer, tom, tempo[i]);
    delay(tempo[i]);
  }
}

int sorteio()
{
  randomSeed(analogRead(0)); // inicializa a sequência randômica
  led = random(1, 4); // sorteia um led entre 1 e 3
  Serial.println("led sorteado = ");
  Serial.println(led);
  return led;
}

void setup()
{
 pinMode(buzzer, OUTPUT);
 pinMode(button1, INPUT);
 pinMode(button2, INPUT);
 pinMode(button3, INPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 Serial.begin(9600);
  
 //tocar(vitoria, duracao);
 //tocar(derrota, dur);
}
void ganhou()
{
  Serial.println("Parabens! Voce ganhou!");
  for(i=0; i < 5; i++)
  {
   digitalWrite(led1, HIGH);
   delay(100);
   digitalWrite(led1, LOW);
   digitalWrite(led2, HIGH);
   delay(100);
   digitalWrite(led2, LOW);
   digitalWrite(led3, HIGH);
   delay(100);
   digitalWrite(led3, LOW);
    
  }
  tocar(vitoria, duracao);
  
}

void perdeu()
{
  Serial.println("VOCÊ PERDEU");
  tocar(derrota, dur);  
}

void loop()
{
 int apertou_um = 0, apertou_dois = 0, apertou_tres = 0, clicou = 0;
 int led_sorteado = sorteio();
 
  if(led_sorteado == 1)
    led_sorteado = led1;
  else if(led_sorteado == 2)
    led_sorteado = led2;
  else if(led_sorteado == 3)
    led_sorteado = led3;
  
  delay(1000);
  
  do
  {
    if(digitalRead(button1) == HIGH && led_sorteado == led1)
    {
      
      digitalWrite(led_sorteado, HIGH);
      delay(2000);
      digitalWrite(led_sorteado, LOW);
      ganhou();
      clicou = 1;
    }
    if(digitalRead(button1) == HIGH && led_sorteado != led1)
    {
      digitalWrite(led_sorteado, HIGH);
      delay(2000);
      digitalWrite(led_sorteado, LOW);
      perdeu();
      Serial.println("NAO ERA O LED 1");
      clicou = 1;
    }
    
    if(led_sorteado == led2 && digitalRead(button2) == HIGH)
    {
      
      digitalWrite(led_sorteado, HIGH);
      delay(2000);
      digitalWrite(led_sorteado, LOW);
      ganhou();
      clicou = 1;
    }
    if(led_sorteado != led2 && digitalRead(button2) == HIGH)
    {
      digitalWrite(led_sorteado, HIGH);
      delay(2000);
      digitalWrite(led_sorteado, LOW);
      perdeu();
      Serial.println("NAO ERA O LED 2");
      clicou = 1;
    }
    if(led_sorteado == led3 && digitalRead(button3) == HIGH)
    {
      digitalWrite(led_sorteado, HIGH);
      delay(2000);
      digitalWrite(led_sorteado, LOW);
      ganhou();
      clicou = 1;
    }
    if(led_sorteado != led3 && digitalRead(button3) == HIGH)
    {
      digitalWrite(led_sorteado, HIGH);
      delay(2000);
      digitalWrite(led_sorteado, LOW);
      perdeu();
      Serial.println("NAO ERA O LED 3");
      clicou = 1;
    }
    
  Serial.println("Clicou");
  Serial.println(clicou);
    
  }while(clicou == 0);
  
  delay(10000);
}
