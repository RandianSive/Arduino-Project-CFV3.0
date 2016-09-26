//外部紅外線感測器觸發

void PIRout_run(){

//讀取外部紅外線感測器的狀態
PIRout_state = digitalRead(PIRout_pin);

  if(HIGH==PIRout_state)
     digitalWrite(ledout_pin,HIGH);
  else digitalWrite(ledout_pin,LOW);
}

