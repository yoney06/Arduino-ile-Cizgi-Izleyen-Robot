boolean b_sol_cizgi;
boolean b_orta_cizgi;
boolean b_sag_cizgi;
int l298n_ena=10;
int l298n_in1=9;
int l298n_in2=8;
int l298n_in3=7;
int l298n_in4=6;
int l298n_enb=5;

void ilerle() {
	digitalWrite(l298n_in1,LOW);
	digitalWrite(l298n_in2,HIGH);
	analogWrite(l298n_ena,(250));
	digitalWrite(l298n_in3,LOW);
	digitalWrite(l298n_in4,HIGH);
	analogWrite(l298n_enb,(250));
}
void stop2() {
	digitalWrite(l298n_in1,LOW);
	digitalWrite(l298n_in2,HIGH);
	analogWrite(l298n_ena,(0));
	digitalWrite(l298n_in3,LOW);
	digitalWrite(l298n_in4,HIGH);
	analogWrite(l298n_enb,(0));
}
void sol_don() {
	digitalWrite(l298n_in1,LOW);
	digitalWrite(l298n_in2,HIGH);
	analogWrite(l298n_ena,(0));
	digitalWrite(l298n_in3,LOW);
	digitalWrite(l298n_in4,HIGH);
	analogWrite(l298n_enb,(250));
}
void sag_don() {
	digitalWrite(l298n_in1,LOW);
	digitalWrite(l298n_in2,HIGH);
	analogWrite(l298n_ena,(250));
	digitalWrite(l298n_in3,LOW);
	digitalWrite(l298n_in4,HIGH);
	analogWrite(l298n_enb,(0));
}

void setup()
{
  	pinMode(10, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);

	stop2();

}


void loop()
{

  	b_sol_cizgi = digitalRead(2);
  	b_orta_cizgi = digitalRead(3);
  	b_sag_cizgi = digitalRead(4);
  	if (b_sag_cizgi) {
  		sag_don();
  	}
  	else if (b_orta_cizgi) {
  		ilerle();
  	}
  	else if (b_sol_cizgi) {
  		sol_don();
  	}

}