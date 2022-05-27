boolean b_LeftWhite;
boolean b_CenterWhite;
boolean b_RightWhite;
int l298n_ena=10;
int l298n_in1=9;
int l298n_in2=8;
int l298n_in3=7;
int l298n_in4=6;
int l298n_enb=5;

void GoRight() {
	digitalWrite(l298n_in1,LOW);
	digitalWrite(l298n_in2,HIGH);
	analogWrite(l298n_ena,(255));
	digitalWrite(l298n_in3,LOW);
	digitalWrite(l298n_in4,HIGH);
	analogWrite(l298n_enb,(0));
}
void GoLeft() {
	digitalWrite(l298n_in1,LOW);
	digitalWrite(l298n_in2,HIGH);
	analogWrite(l298n_ena,(0));
	digitalWrite(l298n_in3,LOW);
	digitalWrite(l298n_in4,HIGH);
	analogWrite(l298n_enb,(255));
}
void Stop() {
	digitalWrite(l298n_in1,LOW);
	digitalWrite(l298n_in2,HIGH);
	analogWrite(l298n_ena,(0));
	digitalWrite(l298n_in3,LOW);
	digitalWrite(l298n_in4,HIGH);
	analogWrite(l298n_enb,(0));
}
void GoForward() {
	digitalWrite(l298n_in1,LOW);
	digitalWrite(l298n_in2,HIGH);
	analogWrite(l298n_ena,(255));
	digitalWrite(l298n_in3,LOW);
	digitalWrite(l298n_in4,HIGH);
	analogWrite(l298n_enb,(255));
}

void setup()
{
  	pinMode(10, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(13, INPUT);
	pinMode(12, INPUT);
	pinMode(11, INPUT);

	Stop();

}


void loop()
{

  	b_LeftWhite = digitalRead(13);
  	b_CenterWhite = digitalRead(12);
  	b_RightWhite = digitalRead(11);
  	if (b_LeftWhite) {
  		GoLeft();
  	}
  	else if (b_RightWhite) {
  		GoRight();
  	}
  	else if (b_CenterWhite) {
  		GoForward();
  	}

}