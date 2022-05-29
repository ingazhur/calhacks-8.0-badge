#define A 3 // pin 10 = PA3
#define B 2 // pin 11 = PA2
#define C 1 // pin 12 = PA1
#define D 0 // pin 13 = PA0

#define PIN_CONFIG 0
#define PIN_STATE 1

#define LED_Num 12

int led = 1;

int matrix[LED_Num][2][4] = {
  //           PIN_CONFIG                  PIN_STATE
  //    A       B       C      D         A     B    C    D
  { { OUTPUT, INPUT, INPUT, OUTPUT }, { HIGH, LOW, LOW, LOW } }, // 12
  { { INPUT, INPUT, OUTPUT, OUTPUT }, { LOW, LOW, LOW, HIGH } }, // 1
  { { INPUT, INPUT, OUTPUT, OUTPUT }, { LOW, LOW, HIGH, LOW } }, // 2
  { { INPUT, OUTPUT, OUTPUT, INPUT }, { LOW, LOW, HIGH, LOW } }, // ...
  { { INPUT, OUTPUT, OUTPUT, INPUT }, { LOW, HIGH, LOW, LOW } },
  { { OUTPUT, OUTPUT, INPUT, INPUT }, { LOW, HIGH, LOW, LOW } }, 
  { { OUTPUT, OUTPUT, INPUT, INPUT }, { HIGH, LOW, LOW, LOW } }, 
  { { INPUT, OUTPUT, INPUT, OUTPUT }, { LOW, LOW, LOW, HIGH } }, 
  { { INPUT, OUTPUT, INPUT, OUTPUT }, { LOW, HIGH, LOW, LOW } }, 
  { { OUTPUT, INPUT, OUTPUT, INPUT }, { LOW, LOW, HIGH, LOW } }, 
  { { OUTPUT, INPUT, OUTPUT, INPUT }, { HIGH, LOW, LOW, LOW } }, 
  { { OUTPUT, INPUT, INPUT, OUTPUT }, { LOW, LOW, LOW, HIGH } }  // 11
};

volatile byte state = LOW;

void setup() {
}

void loop() {
  random_blink();
}

void lightOn(int led) {
  pinMode( A, matrix[led][PIN_CONFIG][0] );
  pinMode( B, matrix[led][PIN_CONFIG][1] );
  pinMode( C, matrix[led][PIN_CONFIG][2] );
  pinMode( D, matrix[led][PIN_CONFIG][3] );
  digitalWrite( A, matrix[led][PIN_STATE][0] );
  digitalWrite( B, matrix[led][PIN_STATE][1] );
  digitalWrite( C, matrix[led][PIN_STATE][2] );
  digitalWrite( D, matrix[led][PIN_STATE][3] );
}

void random_blink() {
  while(1) {
    int led = random(0, LED_Num);
    lightOn(led);
    delay(10);
  }
}
