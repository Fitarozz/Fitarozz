#define Capteur_Avant_1 1
#define Capteur_Avant_2 2
#define Capteur_Avant_3 3
#define Capteur_Gauche 4
#define Capteur_Droite 5
#define Capteur_Arriere 6
#define Capteur_Sol 7
#define Moteur_1 8
#define Moteur_2 9

#define TRIG 12 //pin 12 carte UNO pour envoyer pulse de 10µs 
#define ECHO 11 // pin 11 carte UNO pour recevoir pulse Echo 
const long TIMEOUT = 30000UL; // 30ms soit mesure à moins de 6m25 
unsigned long distance; //  
void setup() { 
  //Moteur_1 en sortit 0 au demarrage
 pinMode(Moteur_1, OUTPUT);
 digitalWrite(Moteur_1, LOW);
  //Moteur_2 en sortit 0 au demarrage
 pinMode(Moteur_2, OUTPUT);
 digitalWrite(Moteur_2, LOW);
 
 pinMode(TRIG,OUTPUT); // configuration pin TRIG en sortie, elle sera raccordée à l'entrée Trig du capteur HC-SR04  pinMode(ECHO,INPUT); // configuration pin ECHO en entrée, elle sera raccordée à la sortie Echo du capteur HC SR04 
 digitalWrite(TRIG, LOW); //Elle doit être à 0 au démarrage 
 Serial.begin(115200); 
} 
void loop() { 
 digitalWrite(Moteur_1, HIGH);
 digitalWrite(Moteur_2, HIGH);

 //capteur avant 1 
 if (digitalRead(Capteur_Avant_1) == HIGH){
 digitalWrite(Moteur_1, LOW);
 digitalWrite(Moteur_2, LOW);
 }
 else {
  digitalWrite(Moteur_1, HIGH);
  digitalWrite(Moteur_2, HIGH); 
 }
 
//capteur avant 2
 if (digitalRead(Capteur_Avant_2) == HIGH){
 digitalWrite(Moteur_1, LOW);
 digitalWrite(Moteur_2, LOW);
 }
 else {
  digitalWrite(Moteur_1, HIGH);
  digitalWrite(Moteur_2, HIGH); 
 }

//capteur avant 3
if (digitalRead(Capteur_Avant_3) == HIGH){
 digitalWrite(Moteur_1, LOW);
 digitalWrite(Moteur_2, LOW);
 }
 else {
  digitalWrite(Moteur_1, HIGH);
  digitalWrite(Moteur_2, HIGH); 
 }

 //création impulsion trigger de 10µs 
 digitalWrite(TRIG,HIGH);  
 delayMicroseconds(10); 
 digitalWrite(TRIG, LOW); 
 //mesure de la distance en cm capteur / cible 
 distance = pulseIn(ECHO, HIGH, TIMEOUT)/48; 
 //Affichage mesure toutes les 0.5 seconde 
 Serial.print("Distance = "); 
 Serial.print(distance); 
 Serial.println(" cm"); 
 delay(500); 
}
