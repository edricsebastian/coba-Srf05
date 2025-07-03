//Definisi Sensor TCRT5000
#define ir0 A5
#define ir1 A4
#define ir2 A3
#define ir3 A2
#define ir4 A1
#define ir5 A0

#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define ena 10
#define enb 5

int counterHitam = 0;
const int targetBerhenti = 3; //Ganti sesuai keinginan
bool sudahBerhenti = false;

void setup() {
  //Set pin sensor sebagai OUTPUT
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  //Set pin sensor sebagai INPUT
  pinMode(ir0, INPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

}

void loop() {
  //Membaca nilai sensor
  int s1 = analogRead(ir0);
  int s2 = analogRead(ir1);
  int s3 = analogRead(ir2);
  int s4 = analogRead(ir3);
  int s5 = analogRead(ir4);
  int s6 = analogRead(ir5);

  //Treshold garis hitam dan putih
  int threshold = 200;
    // Jika sensor s3 dan s4 mendeteksi garis hitam
  if ((s1 < threshold)&&(s2 < threshold)&&(s3 > threshold)&&(s4 < threshold)&&(s5 < threshold)&&(s6 < threshold)) {
    // Bergerak lurus
    analogWrite(ena, 50);  //Kecepataan motor kanan
    analogWrite(enb, 55);  //Kecepataan motor kiri

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  // Jika sensor s3 dan s4 mendeteksi garis hitam
  if ((s1 < threshold)&&(s2 < threshold)&&(s3 < threshold)&&(s4 > threshold)&&(s5 < threshold)&&(s6 < threshold)) {
    // Bergerak lurus
    analogWrite(ena, 50);  //Kecepataan motor kanan
    analogWrite(enb, 55);  //Kecepataan motor kiri

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  // Jika sensor s2 mendeteksi garis hitam
  else if ((s1 < threshold) && (s2 < threshold) && (s3 < threshold) && (s4 > threshold) && (s5 > threshold) && (s6 < threshold)) {
    // Kanan
    analogWrite(ena, 10);   //Kecepataan motor kanan
    analogWrite(enb, 50);  //Kecepataan motor kiri

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  // Jika sensor s1 mendeteksi garis hitam
  else if ((s1 < threshold) && (s2 < threshold) && (s3 < threshold) && (s4 < threshold) && (s5 < threshold) && (s6 > threshold)) {
    // Kanan tajam
    analogWrite(ena, 0);    //Kecepataan motor kanan
    analogWrite(enb, 70);  //Kecepataan motor kiri

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  // Jika sensor s2 mendeteksi garis hitam
  else if ((s1 < threshold) && (s2 > threshold) && (s3 > threshold) && (s4 < threshold) && (s5 < threshold) && (s6 < threshold)) {
    // Kiri
    analogWrite(ena, 50);  //Kecepataan motor kanan
    analogWrite(enb, 20);   //Kecepataan motor kiri

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  // Jika sensor s1 mendeteksi garis hitam
  else if ((s1 > threshold) && (s2 < threshold) && (s3 < threshold) && (s4 < threshold) && (s5 < threshold) && (s6 < threshold)) {
    // Kiri tajam
    analogWrite(ena, 70);  //Kecepataan motor kanan
    analogWrite(enb, 0);    //Kecepataan motor kiri

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  // Jika sensor mendeteksi garis hitam
  else if ((s1 > threshold) && (s2 > threshold) && (s3 > threshold) && (s4 > threshold) && (s5 > threshold) && (s6 > threshold)) {
    counterHitam++;
    delay(300); //Delay untuk mencegah counting terlalu cepat
    }
    else if (counterHitam >= targetBerhenti && !sudahBerhenti) {
    analogWrite(ena, 0);  //Kecepataan motor kanan
    analogWrite(enb, 0);    //Kecepataan motor kiri

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    sudahBerhenti = true;
    while (true); //berhenti total, tidak lanjut loop
  }
}