// Aluno = Pedro Felipe Gonçalves de Arruda efeito de 1 até 9
//Nicolas T. Cuerbas efeito de 10 até 19
//Yuri Roque 20 até 22

#define INIC 2
#define FIN 11
#define SIZE abs(FIN-INIC)+1
#define MAX 2

void setup() {
  // put your setup code here, to run once:
  int i;
  for (i = INIC; i <= FIN; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  size_t LED[SIZE];
  int i, n;
  int j = 0;
  for (i = INIC; i <= FIN; i++, j++) {
    LED[j] = i;
  }
    //---------------------------------------------------------
    //Efeito 1
    j = MAX;
    while (j--) {
    //Linear
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, HIGH);
      delay(100);
    }
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
      delay(100);
    }
    }


    //---------------------------------------------------------
    //Efeito 2
    j = MAX;
    while (j--) {
    //Linear
    for (i = 0; i < (5); i++) {
      digitalWrite(LED[i], HIGH);
      delay(100);
    }
    for (i = 0; i < 5; i++) {
      digitalWrite(LED[i], LOW);
      delay(100);
    } delay(300);
    for (i = 5; i <= 9; i++) {
      digitalWrite(LED[i], HIGH);
      delay(100);
    }
    for (i = 5; i <= 9; i++) {
      digitalWrite(LED[i], LOW);
      delay(100);
    } delay(300);

    }


    //---------------------------------------------------------
    // Efeito 3
    j = MAX;
    while (j--) {
    //Wave
    for (i = 0; i <= (SIZE / 2); i++) {
      digitalWrite(LED[i], HIGH);
      digitalWrite(LED[((SIZE - 1) - i)], HIGH);
      delay(100);
    }
    int l = ((SIZE - 1) / 2);
    int r = ((SIZE - 1) / 2) + 1;
    for (i = 0; i <= (SIZE / 2); i++) {
      digitalWrite(LED[(l - i)], LOW);
      digitalWrite(LED[(r + i)], LOW);
      delay(100);
    }
    }

    //---------------------------------------------------------
    //Efeito 4
    j = MAX;
    while (j--) {
    for (i = 0; i <= (SIZE - 1); i++) {
      if (i % 2 == 0)
        digitalWrite(LED[i], HIGH);
    }
    delay(500);
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
    }

    for (i = 0; i <= (SIZE - 1); i++) {
      if (i % 2 == 1)
        digitalWrite(LED[i], HIGH);
    }
    delay(500);
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
    }
    }

    //---------------------------------------------------------
    //Efeito 5
    j = MAX;
    while (j--) {
    for (i = 0; i <= (SIZE - 1); i++) {
      if (i % 3 == 0)
        digitalWrite(LED[i], HIGH);
    }
    delay(500);
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
    }

    for (i = 0; i <= (SIZE - 1); i++) {
      if (i % 3 == 1)
        digitalWrite(LED[i], HIGH);
    }
    delay(500);
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
    }
    }

    //---------------------------------------------------------
    //Efeito 6
    j = MAX;
    while (j--) {
    for (i = 0; i <= (SIZE - 1); i++) {
      if (i % 4 == 0)
        digitalWrite(LED[i], HIGH);
    }
    delay(500);
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
    }

    for (i = 0; i <= (SIZE - 1); i++) {
      if (i % 4 == 1)
        digitalWrite(LED[i], HIGH);
    }
    delay(500);
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
    }
    }

    //---------------------------------------------------------
    //Efeito 7
    j = MAX;
    while (j--) {
    for (n = 0; n <= 9; n++) {
      for (i = 2; i <= 11 - n; i++) {
        digitalWrite(i, HIGH);
        digitalWrite(i - 1, LOW);
        delay(100);
      }
    }

    for (n = 0; n <= 9; n++) {
      for (i = 11 - n; i <= 11; i++) {
        digitalWrite(i, LOW);
        digitalWrite(i + 1, HIGH);
        delay(100);
      }
    }
    }

    delay(100);

    //---------------------------------------------------------

    //Efeito 8
    j = MAX;
    while (j--) {
    for (i = 0; i < SIZE; i++)
      digitalWrite(LED[i], HIGH);
    delay(200);
    for (i = 0; i < SIZE; i++)
      digitalWrite(LED[i], LOW);
    delay(200);
    }

    //---------------------------------------------------------
    //Efeito 9
    j = MAX;
    while (j--) {
    for (i = 0; i < SIZE; i++) {
      if (i % 2 == 0)
        digitalWrite(LED[i], HIGH);
    }
    delay(200);
    for (i = 0; i < SIZE; i++)
      digitalWrite(LED[i], LOW);
    delay(200);
    }
    //Efeito 10
    j = MAX;
    while (j--) {
    for (i = 0; i < SIZE; i++) {
      if (i % 3 == 0)
        digitalWrite(LED[i], HIGH);
    }
    delay(200);
    for (i = 0; i < SIZE; i++)
      digitalWrite(LED[i], LOW);
    delay(200);
    }

    //---------------------------------------------------------
    //Efeito 11
    j = MAX;
    while (j--) {
    for (i = 3; i <= 11; i++) {
      digitalWrite(i, HIGH);
      digitalWrite(i - 1, LOW);
      delay(150);
    }
    delay(200);
    for (i = 10; i >= 2; i--) {
      digitalWrite(i, HIGH);
      digitalWrite(i + 1, LOW);
      delay(150);
    }
    delay(200);
    for (n = 0; n <= 9; n++) {
      for (i = 2; i <= 11; i++) {
        digitalWrite(i, HIGH);
      }
      for (i = 2; i <= 11; i++) {
        digitalWrite(i, LOW);
        digitalWrite(i - 1, HIGH);
        delay(100);
      }
    }
    }


    //---------------------------------------------------------
    //Efeito 12
    j = MAX;
    while (j--) {
    //Linear
    for (i = 0; i < (5); i++) {
      digitalWrite(LED[i], HIGH);
      delay(100);
    }
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
    } delay(300);
    for (i = 11; i >= 7; i--) {
      digitalWrite(i, HIGH);
      delay(100);
    }
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);

    } delay(300);

    }

    //---------------------------------------------------------
    //Efeito 13

    j = MAX;
    while (j--) {
    //Linear
    for (i = 0; i <= 9; i++) {
      digitalWrite(LED[i], HIGH);
      digitalWrite(LED[i - 1], LOW);
      delay(100);
    }
    delay(300);
    for (i = 9; i >= 0; i--) {
      digitalWrite(LED[i], HIGH);
      digitalWrite(LED[i + 1], LOW);
      delay(100);
    } delay(300);
    }

    //---------------------------------------------------------

    //Efeito 14
    j = MAX;
    while (j--) {
    //Linear
    for (i = 0; i <= 9; i++) {
      digitalWrite(LED[i], HIGH);
      digitalWrite(LED[i + 1], HIGH);
      digitalWrite(LED[i - 2], LOW);
      delay(100);
    }
    delay(300);
    for (i = 9; i >= 0; i--) {
      digitalWrite(LED[i], HIGH);
      digitalWrite(LED[i - 2], HIGH);
      digitalWrite(LED[i + 2], LOW);
      delay(100);
    } delay(300);
    }
    //---------------------------------------------------------
    //Efeito 15
    j = MAX * 2;
    while (j--) {
    for (i = 0; i <= (SIZE * 2); i++) {
      digitalWrite(LED[random(10 * random()) % 9], HIGH);
      digitalWrite(LED[random(10 * random()) % 9], LOW);
      digitalWrite(LED[random(10 * random()) % 9], HIGH);
      digitalWrite(LED[random(10 * random()) % 9], LOW);
      delay(60);
    }
    }
    //Efeito 16
    j = MAX;
    while (j--) {
    //Linear
    for (i = 0; i <= 9; i++) {
      if (i % 2 == 0) {
        digitalWrite(LED[i], HIGH);
        digitalWrite(LED[i - 1], LOW);
        delay(100);
      }
    }
    delay(300);
    for (i = 9; i >= 0; i--) {
      if (i % 2 == 1) {
        digitalWrite(LED[i + 1], LOW);
        digitalWrite(LED[i], HIGH);
        delay(100);
      }
    } delay(300);
    }


    //---------------------------------------------------------
    //Efeito 17
    j = MAX;
    while (j--) {
    int l = ((SIZE - 1) / 2);
    int r = ((SIZE - 1) / 2) + 1;

    for (i = 0; i <= (SIZE / 2); i++) {
      digitalWrite(LED[(l - i)], HIGH);
      digitalWrite(LED[(r + i)], HIGH);
      delay(100);
    }

    for (i = 0; i <= (SIZE / 2); i++) {
      digitalWrite(LED[(l - i) + 1], LOW);
      digitalWrite(LED[(r + i)], LOW);
      delay(100);

    }
    }
    //---------------------------------------------------------
    //Efeito 18

    j = MAX;
    while (j--) {
    for (i = 0; i <= (SIZE / 2); i++) {
      digitalWrite(LED[i], LOW);
      digitalWrite(LED[((SIZE - 1) - i)], LOW);
      delay(100);
    }
    int l = ((SIZE - 1) / 2);
    int r = ((SIZE - 1) / 2) + 1;
    for (i = 0; i <= (SIZE / 2); i++) {
      digitalWrite(LED[(l - i)], HIGH);
      digitalWrite(LED[(r + i)], HIGH);
      delay(100);
    }
    }

    //------------------------------------------------------
    //Efeito 19
    j = MAX;
    while (j--) {

    for (n = 0; n <= (SIZE - 1); n++) {
      for (i = n; i <= (SIZE - 1 - n); i++) {
        digitalWrite(LED[i], HIGH);
        digitalWrite(LED[i - 1], LOW);
        delay(100);
      }
      for (i = (SIZE - 1 - n); i >= n; i--) {
        digitalWrite(LED[i], HIGH);
        digitalWrite(LED[i + 1], LOW);
        delay(100);
      }
    }
    }

    //----------------------------------------------------------
    //Efeito 20
    j = MAX;
    while (j--) {
    for (i = 0; i <= pow(2, SIZE); i++) {
      if (i % 2 == 1)
        digitalWrite(LED[i], HIGH);
      delay(100);
      if (i % 2 == 0)
        digitalWrite(LED[i], HIGH);
      delay(100);

    }
    }
    //------------------------------------------------------------
    //efeito 21
    j = MAX;
    while (j--) {
    for (i = 0; i <= (SIZE - 1) / 2; i++) {
      digitalWrite(LED[i], HIGH);
      digitalWrite(LED[i + ((SIZE) / 2)], HIGH);
      delay(50);
      digitalWrite(LED[i], LOW);
      digitalWrite(LED[i + ((SIZE) / 2)], LOW);
    }
    }
  //---------------------------------------------------------------
  //efeito 22
  j = MAX;
  while (j--) {
    for (i = 0; i <= (SIZE-1)/2 ; i++) {
      digitalWrite(LED[i*2], HIGH);
      digitalWrite(LED[(i+1)*2], HIGH);
      delay(50);
      digitalWrite(LED[i*2], LOW);
      digitalWrite(LED[(i+1)*2], LOW);
      delay(50);
    }
  }
}
