#include <CapacitiveSensor.h>
CapacitiveSensor c32 = CapacitiveSensor(3,2);
CapacitiveSensor c45 = CapacitiveSensor(4,5);
 
#define THRESHOLD 100
#define o1 7
#define o2 8
#define FREQ 50
 
void setup() {
  // put your setup code here, to run once:
  c32.set_CS_AutocaL_Millis(0xFFFFFFFF);
  c45.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  
  pinMode(o1, OUTPUT);
  pinMode(o2, OUTPUT);
}
 
int s1 = 0;
int s2 = 0;
 
int i1 = 0; // state of instrument 1
int i2 = 0; // state of instrument 2
 
inline void swap(int *x) {
  *x = (*x == 1) ? 0 : 1;
}
 
void printState() {
  Serial.print("INST1 ");
  if (i1 == 0) Serial.print("OFF");
  else Serial.print("ON");
  
  Serial.print("\t");
  
  Serial.print("INST2 ");
  if (i2 == 0) Serial.print("OFF");
  else Serial.print("ON");
  
  Serial.print("\n");
}
 
void controlEquipments() {
  if (i1 == 1) digitalWrite(o1, HIGH);
  else digitalWrite(o1, LOW);
  
  if (i2 == 1) digitalWrite(o2, HIGH);
  else digitalWrite(o2, LOW);
}
 
void loop() {
 controlEquipments();
  
  // put your main code here, to run repeatedly:
  long start = millis();
  long total1 = c32.capacitiveSensor(30);
  long total2 = c45.capacitiveSensor(30);
 
  
  Serial.print(millis() - start);
  Serial.print("\t");
  Serial.print(total1);
  Serial.print("\t");
  Serial.print(total2);
  Serial.print("\n");
  
  if (total2 > THRESHOLD) {
    if (s2 == 0) {
      s2 = 1;
      swap(&i2);
      printState();
    }
  } else {
    if (s2 == 1) {
      s2 = 0;
    }
  }
  
  if (total1 > THRESHOLD) {
    if (s1 == 0) {
      s1 = 1;
      swap(&i1);
      printState();
    }
  } else {
    if (s1 == 1) {
      s1 = 0;
    }
  }
  
  delay(FREQ);
}