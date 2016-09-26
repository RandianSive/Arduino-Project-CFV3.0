//計時器函式庫
#include <Timer.h>
//I2C用函式庫
#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

//設定I2C LCD
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

//宣告外側紅外線感測器PIN、狀態、LED PIN之變數
unsigned int PIRout_pin = 11;
unsigned int PIRout_state = 0;
unsigned int ledout_pin = 10;
 
//宣告內側紅外線感測器PIN、狀態、LED PIN之變數
unsigned int PIRin_pin = 12;
unsigned int PIRin_state = 0;
unsigned int ledin_pin = 13; 

//宣告取用人數、計數器延遲時間之變數
unsigned long customer_count = 0;
unsigned int customer_count_pre = 0;


//--以下Timer參數放置區--//

//宣告外側紅外線感測器現在計時、上次計時、延遲時間
unsigned long PIRout_timer_now = 0;
unsigned long PIRout_timer_pre = 0;
unsigned int PIRout_timer_delay = 2500; 

//宣告內側紅外線感測器現在計時、上次計時、延遲時間
unsigned long PIRin_timer_now = 0;
unsigned long PIRin_timer_pre = 0;
unsigned int PIRin_timer_delay = 2500; 


//--以上Timer參數放置區--//


void setup() {

//電腦Serial Port監控、Debug用
  Serial.begin(9600);

//外內部紅外線感測器和LED的PIN MODE
  pinMode (PIRout_pin,INPUT);
  pinMode (ledout_pin,OUTPUT);
  pinMode (PIRin_pin,INPUT);
  pinMode (ledin_pin,OUTPUT);

//啟動LCD
lcd_setup();
}

void loop() {

//外部紅外線感測器運作
PIRout_run();

//內部紅外線感測器運作
PIRin_run();

//Serial Port 回饋指令
//Serial.println(customer_count_pre);
}
