int releAzul = 2;
int releVermelho = 3;

int botaoAzul =4;
int botaoVermelho = 5;
int botaoBranco = 6;

bool bAzul = false;
bool bVermelho = false;

void resetGame( int vezes = 3)
{

  for (int i = 0; i < vezes; i++)
  {
    digitalWrite(releAzul, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(100);                   // wait for a second
    digitalWrite(releAzul, LOW);  // turn the LED off by making the voltage LOW
    delay(100);

    digitalWrite(releVermelho, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(releVermelho, LOW);  // turn the LED off by making the voltage LOW
    delay(100);
  }
  delay(500);
  digitalWrite(releAzul, HIGH);
  digitalWrite(releVermelho, HIGH);
  bAzul == false;
  bVermelho == false;

}

void checaVencedor()
{

  if (bAzul == true)
  {

    digitalWrite(releAzul, LOW);

    digitalWrite(releVermelho, HIGH);



  }
  if (bVermelho == true)
  {

    digitalWrite(releVermelho, LOW);

     digitalWrite(releAzul, HIGH);



  }
    delay(6000);
    resetGame(6);

}

void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(releAzul, OUTPUT);
  pinMode(releVermelho, OUTPUT);
  pinMode(botaoAzul, INPUT_PULLUP);
  pinMode(botaoVermelho, INPUT_PULLUP);
  pinMode(botaoBranco, INPUT_PULLUP);
  resetGame(6);

  Serial.begin(9600);

}

// the loop function runs over and over again forever
void loop()
{

  if(digitalRead(botaoBranco) == LOW)
  {
     resetGame(6);
      Serial.println("reset");
   }
  
  if (digitalRead(botaoVermelho) == LOW )
  {
    bVermelho = true;
    checaVencedor();
      Serial.println("vermelho");


  }
  if (digitalRead(botaoAzul) == LOW  )
  {
    bAzul = true;
    checaVencedor();
      Serial.println("azul");
  }
}
