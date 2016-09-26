void lcd_setup()
{       
  //啟動LCD
  lcd.begin(16, 2);
  int lcd_load;

//LCD閃爍一次
  lcd.backlight(); // 開啟背光
  delay(500);
  lcd.noBacklight(); // 關閉背光
  delay(500);
  lcd.backlight();
  delay(500);

//LCD初始化第一段顯示
  lcd.clear();
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("- PIR  Counter -");
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("- Version 1.10 -");
  delay(1000);

//LCD初始化第二段顯示
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("By Randian Sive");
  lcd.setCursor(0, 1);
  lcd.print("ChingFeng Co.LTD");
  delay(1000);

//PIR Sensor開機緩衝時間
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Now Setting Up..");
  lcd.setCursor(0, 1);
  lcd.print("Process... ");

for(lcd_load=0;lcd_load<=100;lcd_load++)
{
  lcd.setCursor(11, 1);
  lcd.print(lcd_load*1);
  lcd.print("%");
  delay(10);
}

//啟動完成顯示
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("      DONE      ");
  lcd.setCursor(0, 1);
  lcd.print(" SENSOR  ACTIVE ");
  delay(1000);


//進入常駐狀態畫面
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   Stand By...  ");
  lcd.setCursor(0, 1);
  lcd.print("Total User:");
  lcd.setCursor(11, 1);
  lcd.print(customer_count);
}
