//內部紅外線感測器觸發

void PIRin_run(){

PIRin_timer_now = millis();

//讀取內部紅外線感測器的狀態
PIRin_state = digitalRead(PIRin_pin);

//如果紅外線感測到則點亮LED
  if(HIGH==PIRin_state)
     digitalWrite(ledin_pin,HIGH);
//如果紅外線沒感測到就熄滅LED
  else digitalWrite(ledin_pin,LOW);


//檢查上次之觸發時間，如已超過設定之延遲時間，且當紅外線感測到時執行命令一，否則執行命令二
 if(PIRin_timer_now - PIRin_timer_pre >= PIRin_timer_delay  &&  HIGH==PIRin_state)
   {
//命令一：使LCD自第一行第一字起顯示Welcome!!
      lcd.setCursor(0, 0);
      lcd.print("   Welcome !!  ");

//檢查是否仍於同一感測週期內，如不是則執行命令三並標記週期開始，是則跳過執行
      if(customer_count_pre == 0)
      {
//命令三：增加人數計算一位，並使LCD第二行第十二字起顯示目前人數，格數限制最多顯示99999人
      customer_count++;
      lcd.setCursor(11, 1);
      lcd.print(customer_count);
//標記週期開始
      customer_count_pre = 1;
      }
//觸發時間更新，使延遲時間重新計算  
      PIRin_timer_pre = PIRin_timer_now;
   }

//命令二，檢查上次之觸發時間，如已超過設定之延遲時間，則執行命令四，否則跳過執行
 else 
 {
 if(PIRin_timer_now - PIRin_timer_pre >= PIRin_timer_delay)
 {
 //命令四，使LCD自第一行第一字起顯示Stand By...，並標記週期結束
      lcd.setCursor(0, 0);
      lcd.print("   Stand By...  ");
 //標記週期結束
      customer_count_pre = 0;
 }
 }
 
}

