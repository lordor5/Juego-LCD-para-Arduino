#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal
LiquidCrystal lcd(12, 11, 2, 3, 4, 5); // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)

byte coche[8] = { 
  B00000, 
  B00000, 
  B01100, 
  B01110, 
  B11111, 
  B10101, 
  B01010, 
  B00000
}; 
byte obstaculo[8] = { 
  B00000, 
  B00000, 
  B01110, 
  B10101, 
  B11111, 
  B10101, 
  B01110, 
  B00000 
};

int Mejorscore;

int lec1;
int lec2;
int lec3;

int pos = 14;
int pos1 = 1;

int a = 0;
int a1;

int b = 2;
int b1;

int c = 4;
int c1;

int d = 6;
int d1;

int e = 8;
int e1;

int f = 10;
int f1;

int g = 12;
int g1;

int h = 14;
int h1;

int fps;
int score;
int subir;
int rapi = 600;

bool reset = true;
bool pausa = true;
bool soltado;
bool soltado1;

int especial;

void asignarVariables() {

pos = 14;
pos1 = 0;

a = 0;
a1 = 0;

b = 2;
b1 = 0;

c = 4;
c1 = 0;

d = 6;
d1 = 0;

e = 8;
e1 = 0;

f = 10;
f1 = 0;

g = 12;
g1 = 0;

h = 14;
h1 = 0;

rapi = 600;
fps = 599;

reset = true;
pausa = true;

score = 0;

especial = 0;
}
void setup() {   
  lcd.begin(16,2); // Inicializa la interface para el LCD screen, and determina sus dimensiones (ancho y alto) del display
  lcd.createChar(1, coche);
  lcd.createChar(2, obstaculo);
}
void loop() { 
  
  while(true){
    
    juego1();
  }
 }
 void juego1() {

  lec1 = digitalRead(10);
  lec2 = digitalRead(9);
  lec3 = digitalRead(8);

  fps = fps +1;
  
  if ((lec2 == 1)and(soltado == true)){
    pintar(pos,pos1,3);
    soltado = false;
    if (pos1 == 1){
      pos1 = 0;
      }
    else if (pos1 == 0){
      pos1 = 1;
      }
    pintar(pos,pos1,1);
    }
    
  if (lec2 == 0){
    soltado = true;
    }
  if (lec1 == 0){
    soltado1 = true;
    }    
    
  if ((lec1 == 1)and(soltado1 == true)){
    pintar(pos,pos1,3);
    soltado1 = false;
    if (pos1 == 1){
      pos1 = 0;
      }
    else if (pos1 == 0){
      pos1 = 1;
      }
      pintar(pos,pos1,1);
    }
    
    if (lec3 == 1){
    pausa = true;
    while(pausa == true){
        lec1 = digitalRead(10);
        lec2 = digitalRead(9);

        if ((lec1 == 1)or(lec2 == 1)){
          
          pausa = false;
          }
      }
  }

  if (((pos == a)and(pos1 == a1))or((pos == b)and(pos == b1))or((pos == c)and(pos1 == c1))or((pos == d)and(pos1 == d1))or((pos == e)and(pos1 == e1))or((pos == f)and(pos1 == f1))or((pos == g)and(pos1 == g1))or((pos == h)and(pos1 == h1))){
    pintar(pos,pos1,3);
    pos = pos +1;
    pintar(pos,pos1,3);
    if ((pos == 16)or(pos == 0)){
      gameOver();
      }
    }
  
  if (fps >= rapi){
    fps =0;
    score = score +1;

  subir = subir +1;

  if (score > 10){
      if (rapi > 3){
        rapi = rapi - 2;
        }
      }

    
    if (subir == 10){
      pos = pos -1;
      subir = 0;
      }

    a = a+1;
    b = b+1;
    c = c+1;
    d = d+1;
    e = e+1;
    f = f+1;
    g = g+1;
    h = h+1;
    
    
    lcd.clear();
    pintar(a,a1,2);
    pintar(b,b1,2);
    pintar(c,c1,2);
    pintar(d,d1,2);
    pintar(e,e1,2);
    pintar(f,f1,2);
    pintar(g,g1,2);
    pintar(h,h1,2);
    pintar(pos,pos1,1);

    
   
    if (a == 16){
      a = 0;
      a1 = random(0,2);
      }
    if (b == 16){
      b = 0;
      b1 = random(0,2);
      }
    if (c == 16){
      c = 0;
      c1 = random(0,2);
      }
    if (d == 16){
      d = 0;
      d1 = random(0,2);
      }
    if (e == 16){
      e = 0;
      e1 = random(0,2);
      }
    if (f == 16){
      f = 0;
      f1 = random(0,2);
      }
    if (g == 16){
      g = 0;
      g1 = random(0,2);
      }
    if (h == 16){
      h = 0;
      h1 = random(0,2);
      }
    }
    delay(1);
}
void pintar(int pos,int pos1,int dibujo){
    
    lcd.setCursor(pos,pos1);

    if (dibujo == 3){
      
      
      }
      else{
        lcd.write(dibujo);
      }

}
void gameOver(){
  reset = true;
  lcd.clear();
  
  if (score > Mejorscore){

    Mejorscore = score;
    }
  while (reset==true){
    
    lec3 = digitalRead(8);
  
    lcd.setCursor(3,0);
    if (score < 500){
    lcd.print("Game Over");
      }
    if (score < 500){
      especial = random(0,500);
      if (especial == 500){
        lcd.print("Good Game");
        }
      }
    lcd.setCursor(1,1);
    lcd.print("score ");
    lcd.setCursor(7,1);
    lcd.print(score);
    lcd.setCursor(12,1);
    lcd.print(Mejorscore);

    if (lec3 == 1){
      
     lcd.setCursor(15,0);
     lcd.print("o");
        
     asignarVariables();
     reset = false;
     juego1();
      }
    }
  }
