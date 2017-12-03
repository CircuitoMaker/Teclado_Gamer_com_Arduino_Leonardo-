#include "Keyboard.h" // Esta biblioteca só funciona com o Arduino Leonardo
#define KEY_SPACE 32

int pinos[]={6,7,8,14,16,10,3,4,5,9,21,20,15}; // Pinos 20 e 21 são os pinos analócos A2 e A3
int teclas[]={'A','B','C','D','E','F','G','H','I','J','L','M', KEY_SPACE};  //definição das teclas (Ajuste como desejar)

int tempoDeResposta = 1; // Aqui você ajusta o tempo de resposta do teclado

void setup(){
  
  for (int x=0; x<=13; x++)
    {
       pinMode(pinos[x],INPUT_PULLUP); //Declata todos os pinos como entradas
    }        
      Keyboard.begin();
    
}// Fim do Setup



void loop() {

if (analogRead(0)>800){Keyboard.press(KEY_RIGHT_ARROW); delay(tempoDeResposta); Keyboard.releaseAll();}
if (analogRead(0)<200){Keyboard.press(KEY_LEFT_ARROW);  delay(tempoDeResposta); Keyboard.releaseAll();}
if (analogRead(1)>800){Keyboard.press(KEY_UP_ARROW);    delay(tempoDeResposta); Keyboard.releaseAll();}
if (analogRead(1)<200){Keyboard.press(KEY_DOWN_ARROW);  delay(tempoDeResposta); Keyboard.releaseAll();}

for(int x=0; x<=13; x++)
{
  if(digitalRead(pinos[x])==LOW)
  {
     Keyboard.press(teclas[x]);
     delay(tempoDeResposta); 
     Keyboard.releaseAll();
  }
 } 

 
}// Fim do loop
