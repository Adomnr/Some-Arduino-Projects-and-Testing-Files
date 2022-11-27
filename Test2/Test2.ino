 #include <Keypad.h>  
 #include<LiquidCrystal.h>  
 #include<EEPROM.h>  
 #define led A3  
 #define buzzer A4  
LiquidCrystal lcd(13,12,8,7,4,2); 
 char password[4];  
 char pass[4]; 
 int i=0;  
 char customKey=0;  
 const byte ROWS = 4; //four rows  
 const byte COLS = 3; //three columns  
 char hexaKeys[ROWS][COLS] = {  
  {'1','2','3'},  
  {'4','5','6'},  
  {'7','8','9'},  
  {'*','0','#'}  
 };  
 byte rowPins[ROWS] = {A0,10,9,A1}; //connect to the row pinouts of the keypad  
 byte colPins[COLS] = {A2,5,A5}; //connect to the column pinouts of the keypad  
 //initialize an instance of class NewKeypad  
 Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);   
 void setup()  
 {  
  lcd.begin(16,2);  
  pinMode(led, OUTPUT);  
  pinMode(buzzer, OUTPUT);  
  pinMode(1, OUTPUT);  
  //  pinMode(m12, OUTPUT);  
  lcd.print(" DOOR LOCK");  
  lcd.setCursor(0,1);  
  lcd.print(" --Project-- ");  
  delay(2000);  
  lcd.clear();  
  lcd.print("Enter Password:");  
  lcd.setCursor(0,1);  
  EEPROM.write(0, 41); 
  EEPROM.write(1, 49); 
  EEPROM.write(2, 50);   
  EEPROM.write(3, 51);  
  for(int j=0;j<4;j++)  
  pass[j]=EEPROM.read(j);  
 }  
 void loop()  
 {  
  customKey = customKeypad.getKey();  

  if (customKey)  
  {  
    password[i++]=customKey;  
    lcd.print(customKey);
    beep();  
  }  
  if(i==4)  
  {  
   delay(200);  
   for(int j=0;j<4;j++)  
   pass[j]=EEPROM.read(j);  
   if(!(strncmp(password, pass,4)))  
   {  
     digitalWrite(1, HIGH  
     );  
    digitalWrite(led, HIGH);  
    beep();  
    lcd.clear();  
    lcd.print("Door Opened");  
    delay(2000);  
    lcd.setCursor(0,1);  
    //lcd.print("#.Change Passkey");  
    delay(2000);  
    lcd.clear();  
    lcd.print("Enter Password:");  
    lcd.setCursor(0,1);  
    i=0;  
    digitalWrite(led, LOW);  
     digitalWrite(1, LOW);  
   }  
   else  
   {  
    digitalWrite(buzzer, HIGH);  
    lcd.clear();  
    lcd.print("Access Denied...");  
    lcd.setCursor(0,1);  
    //lcd.print("#.Change Passkey");  
    delay(2000);  
    lcd.clear();  
    lcd.print("Enter Password:");  
    lcd.setCursor(0,1);  
    i=0;  
    digitalWrite(buzzer, LOW);  
   }  
  }  
 }  
 
 void beep()  
 {  
  digitalWrite(buzzer, HIGH);  
  delay(20);  
  digitalWrite(buzzer, LOW);  
 }  
