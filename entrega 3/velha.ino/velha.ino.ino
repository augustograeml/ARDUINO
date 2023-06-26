char jogador = 'v';
int jogada = 1, i, j;
char deutrinca = 'n';
char *px, *py;
px = &deutrinca;
py = &jogador;

char vermelho[3][3] = {13, 11,  9,
                        7,  5,  3,
                       A0, A2, A4};

char azul[3][3]= {12, 10,  8,
                   6,  4,  2,
                  A1, A3, A5};

char velha[3][3]= {'e', 'e', 'e',
                   'e', 'e', 'e',
                   'e', 'e', 'e'}; // matriz de controle

char pisca(char porta)
{
   digitalWrite(porta, HIGH);
   delay(500);
   digitalWrite(porta, LOW);
   delay(500);  
}

int avanca()
{
   if(j < 2)
   {
      j++; // avança uma coluna
   }
   else
   {
      if(i < 2)
      {
         i++; // avança uma linha
         j = 0;
      }
      else
      {
         i = 0; // volta para a primeira linha, primeira coluna
         j = 0;
      }
    }
}

char inicializa() // função para inicializar a matriz "velha"
{
  for(i = 0; i <= 2; i++)
  {           
    for(j = 0; j <= 2; j++)
    {
      velha[i][j] = ' ';
    }
  }
}
void trinca (int i, int j, char velha, char* px, char* py )
{
  //verifica a linha jogada
  if(velha[i][0] == velha[i][1] && velha[i][1] == velha[i][2])
  {
    *px = 's';
    if(*py == 'v')
      {
        for(i=0; i < 5; i++)
        {
           digitalWrite(vermelho[i][0], HIGH);
           delay(100);
           digitalWrite(vermelho[i][0], LOW);
           digitalWrite(vermelho[i][1], HIGH);
           delay(100);
           digitalWrite(vermelho[i][1], LOW);
           digitalWrite(vermelho[i][2], HIGH);
           delay(100);
           digitalWrite(vermelho[i][2], LOW);
       }
      }
    else if (*py == 'a')
    {
       for(i=0; i < 5; i++)
        {
           digitalWrite(azul[i][0], HIGH);
           delay(100);
           digitalWrite(azul[i][0], LOW);
           digitalWrite(azul[i][1], HIGH);
           delay(100);
           digitalWrite(azul[i][1], LOW);
           digitalWrite(azul[i][2], HIGH);
           delay(100);
           digitalWrite(azul[i][2], LOW);
       }
    }
  }
  //verifica coluna jogada
  if(velha[0][j] == velha[1][j] && velha[1][j] == velha[2][j])
  {
    *px = 's';
    if(*py == 'v')
      {
        for(i=0; i < 5; i++)
        {
           digitalWrite(vermelho[0][0], HIGH);
           delay(100);
           digitalWrite(vermelho[0][0], LOW);
           digitalWrite(vermelho[1][1], HIGH);
           delay(100);
           digitalWrite(vermelho[1][1], LOW);
           digitalWrite(vermelho[2][2], HIGH);
           delay(100);
           digitalWrite(vermelho[2][2], LOW);
       }
    }
    else if (*py == 'a')
    {
       for(i=0; i < 5; i++)
        {
           digitalWrite(azul[0][j], HIGH);
           delay(100);
           digitalWrite(azul[0][j], LOW);
           digitalWrite(azul[1][j], HIGH);
           delay(100);
           digitalWrite(azul[1][j], LOW);
           digitalWrite(azul[2][j], HIGH);
           delay(100);
           digitalWrite(azul[2][j], LOW);
       }
    }
  }
  if(velha[1][1] == 'e')
  {
    if(velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2])
    {
      *px = 's';
      if(*py == 'v')
      {
        for(i=0; i < 5; i++)
        {
           digitalWrite(vermelho[0][0], HIGH);
           delay(100);
           digitalWrite(vermelho[0][0], LOW);
           digitalWrite(vermelho[1][1], HIGH);
           delay(100);
           digitalWrite(vermelho[1][1], LOW);
           digitalWrite(vermelho[2][2], HIGH);
           delay(100);
           digitalWrite(vermelho[2][2], LOW);
       }
    }
    else if (*py == 'a')
    {
       for(i=0; i < 5; i++)
        {
           digitalWrite(azul[0][0], HIGH);
           delay(100);
           digitalWrite(azul[0][0], LOW);
           digitalWrite(azul[1][1], HIGH);
           delay(100);
           digitalWrite(azul[1][1], LOW);
           digitalWrite(azul[2][2], HIGH);
           delay(100);
           digitalWrite(azul[2][2], LOW);
       }
    }
    
    if(velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0])
    {
      *px = 's';
      if(*py == 'v')
      {
        for(i=0; i < 5; i++)
        {
           digitalWrite(vermelho[0][0], HIGH);
           delay(100);
           digitalWrite(vermelho[0][0], LOW);
           digitalWrite(vermelho[1][1], HIGH);
           delay(100);
           digitalWrite(vermelho[1][1], LOW);
           digitalWrite(vermelho[2][2], HIGH);
           delay(100);
           digitalWrite(vermelho[2][2], LOW);
       }
    }
    else if (*py == 'a')
    {
       for(i=0; i < 5; i++)
        {
           digitalWrite(azul[0][2], HIGH);
           delay(100);
           digitalWrite(azul[0][2], LOW);
           digitalWrite(azul[1][1], HIGH);
           delay(100);
           digitalWrite(azul[1][1], LOW);
           digitalWrite(azul[2][0], HIGH);
           delay(100);
           digitalWrite(azul[2][0], LOW);
       }
    }
    }
 
   if(deutrinca == 's')
   {
     Serial.println("jogador %c ganhou", jogador)
   }
}

void setup()
{
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  
  for(i = 2; i <= 13; i++) // inicializa as portas de 2 a 13
  {                        // como OUTPUT
    pinMode(i, OUTPUT);
  }
  
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  
  Serial.begin(9600);
  
  inicializa();
  i = 0;
  j = 0;
}

void loop()
{
  do
  {if(velha[i][j] == ' ') // se a posição estiver livre pisca
  {   
    if(jogador == 'v')
    {
      pisca(vermelho[i][j]);
    }
    else
    {
      pisca(azul[i][j]);
    }
  }  
  else // senão avança para a próxima
  {
    j--;
    avanca();
  }
  
  Serial.println("i = ");
  Serial.println(i);
  Serial.println("j = ");
  Serial.println(j);
  
  if(digitalRead(1) == LOW) // seleciona a posição sequencialmente
  {
     Serial.println("apertou o botao");    
     avanca(); // chama a função para avançar para a próxima posição
  }
  
  if(digitalRead(0) == LOW) // confirma a posição efetuando a jogada
  {
    if(velha[i][j] == ' ') // a posição está livre?
  {
     velha[i][j] = jogador;
       if(jogador == 'v') // jogador é o vermelho?
       {
          digitalWrite(vermelho[i][j], HIGH);
          jogador = 'a';
       } 
       else
       {
          digitalWrite(azul[i][j], HIGH);
          jogador = 'v';
       }
       jogada++;
       trinca(i, j, velha, px, py);
       delay(2000);
    }
  }
  }while(jogada <=9 && deutrinca == 'n');
}
