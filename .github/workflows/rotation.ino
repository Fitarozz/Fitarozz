int pin1Moteur1=12; //pin de commande moteur 1

int pin2Moteur1=8; // pin de commande moteur 1

int pinPMoteur1=11;// pin PWM moteur 1

void setup() {

  // put your setup code here, to run once:

  Serial.begin(9600); //initialise la communication série

  pinMode(pin1Moteur1,OUTPUT);

  pinMode(pin2Moteur1,OUTPUT);

  pinMode(pinPMoteur1,OUTPUT);


}


void loop() {
  // départ a 45 degres
    delay(10000); // delay de 10s
  
  // rotation vers l'angle 0

  actionMoteur(1,1,100); //moteur 1 100% puissance sens 1

  delay(135); //attente de 0.135 secondes
  
  actionMoteur(1,0,0); //arrêt moteur 1
  
  delay(10000); // delay de 10s
  
  
   // rotation vers l'angle 45

  actionMoteur(1,1,100); //moteur 1 100% puissance sens 1

  delay(135); //attente de 0.135 secondes
  
  actionMoteur(1,0,0); //arrêt moteur 1
  
  delay(10000); // delay de 10s
  
  
  // rotation vers l'angle 135

  actionMoteur(1,1,100); //moteur 1 100% puissance sens 1

  delay(270); //attente de 0.27 secondes
  
  actionMoteur(1,0,0); //arrêt moteur 1
  
  delay(10000); // delay de 10s
  
  
   // rotation vers l'angle 180

  actionMoteur(1,1,100); //moteur 1 100% puissance sens 1

  delay(135); //attente de 0.135 secondes
  
  actionMoteur(1,0,0); //arrêt moteur 1
  
  delay(10000); // delay de 10s
  
  
  // rotation vers l'angle 225

  actionMoteur(1,1,100); //moteur 1 100% puissance sens 1

  delay(135); //attente de 0.135 secondes
  
  actionMoteur(1,0,0); //arrêt moteur 1
  
  delay(10000); // delay de 10s
  
  
  // rotation vers l'angle -45

  actionMoteur(1,-1,100); //moteur 1 100% puissance sens -1

  delay(720); //attente de 0.72 secondes
  
  actionMoteur(1,0,0); //arrêt moteur 1
  

  
  

}


void actionMoteur(int moteur,int sens,int pourcentage){

  int pin1,etat1,pin2,etat2,pinP,puissance; //variable de la fonction

  //test numéro du moteur

  if (moteur==1){

    pin1=pin1Moteur1;

    pin2=pin2Moteur1;

    pinP=pinPMoteur1;

  }



  //test sens du moteur 1,-1 (sens contrainre) ou tout autre valeur (stoppe le moteur)

  if (sens==1){

    etat1=1;

    etat2=0;

  }

  else if (sens==-1){

    etat1=0;

    etat2=1;

  }

  else {

    etat1=0;

    etat2=0;

  }

  puissance=map(pourcentage,0,100,0,255);

  analogWrite(pinP,puissance);

  digitalWrite(pin1,etat1);

  digitalWrite(pin2,etat2);

  //affichage sur le moniteur série (facultatif)

  Serial.print("Moteur : ");

  Serial.print(moteur);

  if (sens==-1 || sens==1){

    Serial.print(" sens : ");

    Serial.print(sens);

  }

  else {

    Serial.print(" ! stop ! ");

  }

  Serial.print(" puissance : ");

  Serial.println(pourcentage);

}
