//Aluno= Nicolas Timoteu Cuerbas
#define INIC 2
#define FIN 11
#define SIZE abs(FIN-INIC)+1
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
  /*
    j = 5;
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
    }*/
  //
  j = 5;
  while (j--) {
    //Linear
    for (i = 0; i < (5); i++) {
      digitalWrite(LED[i], HIGH);
      delay(100);
    }
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
    }delay(500);
    for (i = 5; i <= 11; i++) {
      digitalWrite(i, HIGH);
      delay(100);
    }
    for (i = INIC; i <= FIN; i++) {
      digitalWrite(i, LOW);
      delay(100);
    }

  }/*
  //
  j = 5;
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
  //alternado 01
  j = 5;
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

  //alternado 02
  j = 5;
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

  //alternado 03
  j = 5;
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

  //fica ligado 1
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

  delay(100);
  //
  j = 10;
  while (j--) {
    for (i = 0; i < SIZE; i++)
      digitalWrite(LED[i], HIGH);
    delay(200);
    for (i = 0; i < SIZE; i++)
      digitalWrite(LED[i], LOW);
    delay(200);
  }
  //
  j = 10;
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
  //
  j = 10;
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
  //andadinha
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
*/
}
