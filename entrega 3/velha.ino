char jogador = 'v';
int jogada = 1, i, j;

char vermelho[3][3] = {13, 11,  9,
                        7,  5,  3,
                       A5, A3, A1};

char azul[3][3]= {12, 10,  8,
                   6,  4,  2,
                  A4, A2, A0};

char velha[3][3]; // matriz de controle

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

void setup()
{
  pinMode(0, INPUT); // botão "confirma"
  pinMode(1, INPUT); // botão "seleciona"
  
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
  if(velha[i][j] == ' ') // se a posição estiver livre pisca
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
  
  // complete o código.
}
