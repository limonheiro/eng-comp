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
  int i;
  int j = 0;
  for (i = INIC; i <= FIN; i++, j++) {
    LED[j] = i;
  }
  //Linear
  for (i = INIC; i <= FIN; i++) {
    digitalWrite(i, HIGH);
    delay(100);
  }
  for (i = INIC; i <= FIN; i++) {
    digitalWrite(i, LOW);
    delay(100);
  }
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
  //alternado
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
  

}
