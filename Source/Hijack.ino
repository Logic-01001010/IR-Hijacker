#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

void LCD_main(); // LCD 메인

int RECV_PIN = 11; // 적외선 수신 센서

unsigned long int PreBitType=0; // 사전 비트 변수
unsigned long int PreIRType=0; // 사전 신호 변수
unsigned long int PreDecodeType=0; // 사전 디코드 변수


IRrecv irrecv(RECV_PIN);
IRsend irsend;


decode_results results;

void ShowAnt(); // LCD 안테나
void ShowMos(); // LCD 모기

void dump(decode_results *results);

void IR_Attack();


static int First = 0;
static int Second = 0;
static int Third = 0;
static int Fourth = 0;
static int Fifth = 0;
static int Sixth = 0;
static int Seventh = 0;
static int Eighth = 0;
static int Ninth =0 ;




void setup()
{
  lcd.init(); // initialize the lcd 
  lcd.backlight(); // LCD 백라이트
  
  Serial.begin(9600);


  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");


  LCD_main(); // LCD 메인
  
}

void loop() {
  
  if (irrecv.decode(&results)) {
    // LCD의 모든 내용을 삭제합니다.
    lcd.clear();


   if (results.value == 0xFF906F) // 리모콘 EQ 버튼 클릭시 조건 실행
    {
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("[IR] HIJACKER II");
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print("<>Code: 01001010");
      irrecv.resume(); // Receive the next value
    }

    else if (results.value == 0xFF629D) // 리모콘 CH 버튼 클릭시 조건 실행
    {
      LCD_main(); // LCD 메인
      irrecv.resume(); // Receive the next value
    }



    // 리셋 영역
    else if(results.value == 0xFF6897) // 리모콘 0 버튼 클릭시 조건 실행
    {

      lcd.init(); // initialize the lcd 
     
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("[RESET ALL]");
    
      First = 0;
      Second = 0;
      Third = 0;
      Fourth = 0;
      Fifth = 0;
      Sixth = 0;
      Seventh = 0;
      Eighth = 0;
      Ninth = 0;

      irrecv.resume();
      
    }


    // 1번
    else if(results.value == 0xFF30CF) // 리모콘 1 버튼 클릭시 조건 실행
    {
     static unsigned long First_BitType = PreBitType; // 사전 비트 변수
     static unsigned long First_IRType = PreIRType; // 사전 신호 변수
     static unsigned long First_DecodeType = PreDecodeType; // 사전 디코드 변수

     
     if(First==0)
     {
      lcd.init(); // initialize the lcd 
     
      
      
    lcd.setCursor(0,0); // 1행에서 시작
    Serial.println("Save #1: ");
    lcd.print("Save #1: ");
    
    lcd.setCursor(0,1); // 2행에서 시작
    lcd.print(PreIRType,HEX);
    Serial.println(PreIRType,HEX);
    First_BitType = PreBitType; // 사전 비트 변수
    First_IRType = PreIRType; // 사전 신호 변수
    First_DecodeType = PreDecodeType; // 사전 디코드 변수

      

      First++;
     }
     else
     {
      lcd.init(); // initialize the lcd 

      irsend.sendNEC(First_IRType, First_BitType);
      irrecv.resume(); // Receive the next value
      irrecv.enableIRIn(); // Start the receiver
      
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("Load 1#: ");
      Serial.println("Load 1#: ");
      
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print(First_IRType,HEX);
      Serial.println(First_IRType,HEX);
      
      PreBitType = First_BitType;
      PreIRType = First_IRType;
      PreDecodeType = First_DecodeType;
     }
     

        
      irrecv.resume(); // Receive the next value
    }



    // 2번
    else if(results.value == 0xFF18E7) // 리모콘 2 버튼 클릭시 조건 실행
    {
     static unsigned long Second_BitType = PreBitType; // 사전 비트 변수
     static unsigned long Second_IRType = PreIRType; // 사전 신호 변수
     static unsigned long Second_DecodeType = PreDecodeType; // 사전 디코드 변수

     
     if(Second==0)
     {
      lcd.init(); // initialize the lcd 
     
      
      
    lcd.setCursor(0,0); // 1행에서 시작
    Serial.println("Save #2: ");
    lcd.print("Save #2: ");
    
    lcd.setCursor(0,1); // 2행에서 시작
    lcd.print(PreIRType,HEX);
    Serial.println(PreIRType,HEX);
    Second_BitType = PreBitType; // 사전 비트 변수
    Second_IRType = PreIRType; // 사전 신호 변수
    Second_DecodeType = PreDecodeType; // 사전 디코드 변수

      

      Second++;
     }
     else
     {
      lcd.init(); // initialize the lcd 

      irsend.sendNEC(Second_IRType, Second_BitType);
      irrecv.resume(); // Receive the next value
      irrecv.enableIRIn(); // Start the receiver
      
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("Load 2#: ");
      Serial.println("Load 2#: ");
      
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print(Second_IRType,HEX);
      Serial.println(Second_IRType,HEX);
      
      PreBitType = Second_BitType;
      PreIRType = Second_IRType;
      PreDecodeType = Second_DecodeType;
     }
     

        
      irrecv.resume(); // Receive the next value
    }


    // 3번
    else if(results.value == 0xFF7A85) // 리모콘 3 버튼 클릭시 조건 실행
    {
     static unsigned long Third_BitType = PreBitType; // 사전 비트 변수
     static unsigned long Third_IRType = PreIRType; // 사전 신호 변수
     static unsigned long Third_DecodeType = PreDecodeType; // 사전 디코드 변수

     
     if(Third==0)
     {
      lcd.init(); // initialize the lcd 

      irsend.sendNEC(Third_IRType, Third_BitType);
      irrecv.resume(); // Receive the next value
      irrecv.enableIRIn(); // Start the receiver
     
      
    lcd.setCursor(0,0); // 1행에서 시작
    Serial.println("Save #3: ");
    lcd.print("Save #3: ");
    
    lcd.setCursor(0,1); // 2행에서 시작
    lcd.print(PreIRType,HEX);
    Serial.println(PreIRType,HEX);
    Third_BitType = PreBitType; // 사전 비트 변수
    Third_IRType = PreIRType; // 사전 신호 변수
    Third_DecodeType = PreDecodeType; // 사전 디코드 변수

      

      Third++;
     }
     else
     {
      lcd.init(); // initialize the lcd 
      
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("Load 3#: ");
      Serial.println("Load 3#: ");
      
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print(Third_IRType,HEX);
      Serial.println(Third_IRType,HEX);
      
      PreBitType = Third_BitType;
      PreIRType = Third_IRType;
      PreDecodeType = Third_DecodeType;
     }

      irrecv.resume(); // Receive the next value
    }


    // 4번
    else if(results.value == 0xFF10EF) // 리모콘 4 버튼 클릭시 조건 실행
    {
     static unsigned long Fourth_BitType = PreBitType; // 사전 비트 변수
     static unsigned long Fourth_IRType = PreIRType; // 사전 신호 변수
     static unsigned long Fourth_DecodeType = PreDecodeType; // 사전 디코드 변수

     
     if(Fourth==0)
     {
      lcd.init(); // initialize the lcd 
     
      
      
    lcd.setCursor(0,0); // 1행에서 시작
    Serial.println("Save #4: ");
    lcd.print("Save #4: ");
    
    lcd.setCursor(0,1); // 2행에서 시작
    lcd.print(PreIRType,HEX);
    Serial.println(PreIRType,HEX);
    Fourth_BitType = PreBitType; // 사전 비트 변수
    Fourth_IRType = PreIRType; // 사전 신호 변수
    Fourth_DecodeType = PreDecodeType; // 사전 디코드 변수

      

      Fourth++;
     }
     else
     {
      lcd.init(); // initialize the lcd 

      irsend.sendNEC(Fourth_IRType, Fourth_BitType);
      irrecv.resume(); // Receive the next value
      irrecv.enableIRIn(); // Start the receiver
      
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("Load 4#: ");
      Serial.println("Load 4#: ");
      
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print(Fourth_IRType,HEX);
      Serial.println(Fourth_IRType,HEX);
      
      PreBitType = Fourth_BitType;
      PreIRType = Fourth_IRType;
      PreDecodeType = Fourth_DecodeType;
     }
     

        
      irrecv.resume(); // Receive the next value
    }




    

    // 5번
    else if(results.value == 0xFF38C7) // 리모콘 5 버튼 클릭시 조건 실행
    {
     static unsigned long Fifth_BitType = PreBitType; // 사전 비트 변수
     static unsigned long Fifth_IRType = PreIRType; // 사전 신호 변수
     static unsigned long Fifth_DecodeType = PreDecodeType; // 사전 디코드 변수

     
     if(Fifth==0)
     {
      lcd.init(); // initialize the lcd 


      irsend.sendNEC(Fifth_IRType, Fifth_BitType);
      irrecv.resume(); // Receive the next value
      irrecv.enableIRIn(); // Start the receiver
      
      
    lcd.setCursor(0,0); // 1행에서 시작
    Serial.println("Save #5: ");
    lcd.print("Save #5: ");
    
    lcd.setCursor(0,1); // 2행에서 시작
    lcd.print(PreIRType,HEX);
    Serial.println(PreIRType,HEX);
    Fifth_BitType = PreBitType; // 사전 비트 변수
    Fifth_IRType = PreIRType; // 사전 신호 변수
    Fifth_DecodeType = PreDecodeType; // 사전 디코드 변수

      

      Fifth++;
     }
     else
     {
      lcd.init(); // initialize the lcd 
      
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("Load 5#: ");
      Serial.println("Load 5#: ");
      
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print(Fifth_IRType,HEX);
      Serial.println(Fifth_IRType,HEX);
      
      PreBitType = Fifth_BitType;
      PreIRType = Fifth_IRType;
      PreDecodeType = Fifth_DecodeType;
     }
     

        
      irrecv.resume(); // Receive the next value
    }



    // 6번
    else if(results.value == 0xFF5AA5) // 리모콘 6 버튼 클릭시 조건 실행
    {
     static unsigned long Sixth_BitType = PreBitType; // 사전 비트 변수
     static unsigned long Sixth_IRType = PreIRType; // 사전 신호 변수
     static unsigned long Sixth_DecodeType = PreDecodeType; // 사전 디코드 변수

     
     if(Sixth==0)
     {
      lcd.init(); // initialize the lcd 
     
      
      
    lcd.setCursor(0,0); // 1행에서 시작
    Serial.println("Save #6: ");
    lcd.print("Save #6: ");
    
    lcd.setCursor(0,1); // 2행에서 시작
    lcd.print(PreIRType,HEX);
    Serial.println(PreIRType,HEX);
    Sixth_BitType = PreBitType; // 사전 비트 변수
    Sixth_IRType = PreIRType; // 사전 신호 변수
    Sixth_DecodeType = PreDecodeType; // 사전 디코드 변수

      

      Sixth++;
     }
     else
     {
      lcd.init(); // initialize the lcd 

      irsend.sendNEC(Sixth_IRType, Sixth_BitType);
      irrecv.resume(); // Receive the next value
      irrecv.enableIRIn(); // Start the receiver
      
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("Load 6#: ");
      Serial.println("Load 6#: ");
      
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print(Sixth_IRType,HEX);
      Serial.println(Sixth_IRType,HEX);
      
      PreBitType = Sixth_BitType;
      PreIRType = Sixth_IRType;
      PreDecodeType = Sixth_DecodeType;
     }
     

        
      irrecv.resume(); // Receive the next value
    }

    // 7번
    else if(results.value == 0xFF42BD) // 리모콘 7 버튼 클릭시 조건 실행
    {
     static unsigned long Seventh_BitType = PreBitType; // 사전 비트 변수
     static unsigned long Seventh_IRType = PreIRType; // 사전 신호 변수
     static unsigned long Seventh_DecodeType = PreDecodeType; // 사전 디코드 변수

     
     if(Seventh==0)
     {
      lcd.init(); // initialize the lcd 
     
      
      
    lcd.setCursor(0,0); // 1행에서 시작
    Serial.println("Save #7: ");
    lcd.print("Save #7: ");
    
    lcd.setCursor(0,1); // 2행에서 시작
    lcd.print(PreIRType,HEX);
    Serial.println(PreIRType,HEX);
    Seventh_BitType = PreBitType; // 사전 비트 변수
    Seventh_IRType = PreIRType; // 사전 신호 변수
    Seventh_DecodeType = PreDecodeType; // 사전 디코드 변수

      

     Seventh++;
     }
     else
     {
      lcd.init(); // initialize the lcd 


      irsend.sendNEC(Seventh_IRType, Seventh_BitType);
      irrecv.resume(); // Receive the next value
      irrecv.enableIRIn(); // Start the receiver
      
      
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("Load 7#: ");
      Serial.println("Load 7#: ");
      
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print(Seventh_IRType,HEX);
      Serial.println(Seventh_IRType,HEX);
      
      PreBitType = Seventh_BitType;
      PreIRType = Seventh_IRType;
      PreDecodeType = Seventh_DecodeType;
     }
     

        
      irrecv.resume(); // Receive the next value
    }


    // 8번
    else if(results.value == 0xFF4AB5) // 리모콘 8 버튼 클릭시 조건 실행
    {
     static unsigned long Eighth_BitType = PreBitType; // 사전 비트 변수
     static unsigned long Eighth_IRType = PreIRType; // 사전 신호 변수
     static unsigned long Eighth_DecodeType = PreDecodeType; // 사전 디코드 변수

     
     if(Eighth==0)
     {
      lcd.init(); // initialize the lcd 
     
      irsend.sendNEC(Eighth_IRType, Eighth_BitType);
      irrecv.resume(); // Receive the next value
      irrecv.enableIRIn(); // Start the receiver
      
      
    lcd.setCursor(0,0); // 1행에서 시작
    Serial.println("Save #8: ");
    lcd.print("Save #8: ");
    
    lcd.setCursor(0,1); // 2행에서 시작
    lcd.print(PreIRType,HEX);
    Serial.println(PreIRType,HEX);
    Eighth_BitType = PreBitType; // 사전 비트 변수
    Eighth_IRType = PreIRType; // 사전 신호 변수
    Eighth_DecodeType = PreDecodeType; // 사전 디코드 변수

      

     Eighth++;
     }
     else
     {
      lcd.init(); // initialize the lcd 
      
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("Load 8#: ");
      Serial.println("Load 8#: ");
      
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print(Eighth_IRType,HEX);
      Serial.println(Eighth_IRType,HEX);
      
      PreBitType = Eighth_BitType;
      PreIRType = Eighth_IRType;
      PreDecodeType = Eighth_DecodeType;
     }
     

        
      irrecv.resume(); // Receive the next value
    }


    // 9번
    else if(results.value == 0xFF52AD) // 리모콘 8 버튼 클릭시 조건 실행
    {
     static unsigned long Ninth_BitType = PreBitType; // 사전 비트 변수
     static unsigned long Ninth_IRType = PreIRType; // 사전 신호 변수
     static unsigned long Ninth_DecodeType = PreDecodeType; // 사전 디코드 변수

     
     if(Ninth==0)
     {
      lcd.init(); // initialize the lcd 
     
      irsend.sendNEC(Ninth_IRType, Ninth_BitType);
      irrecv.resume(); // Receive the next value
      irrecv.enableIRIn(); // Start the receiver
      
    lcd.setCursor(0,0); // 1행에서 시작
    Serial.println("Save #9: ");
    lcd.print("Save #9: ");
    
    lcd.setCursor(0,1); // 2행에서 시작
    lcd.print(PreIRType,HEX);
    Serial.println(PreIRType,HEX);
    Ninth_BitType = PreBitType; // 사전 비트 변수
    Ninth_IRType = PreIRType; // 사전 신호 변수
    Ninth_DecodeType = PreDecodeType; // 사전 디코드 변수

      

     Ninth++;
     }
     else
     {
      lcd.init(); // initialize the lcd 
      
      lcd.setCursor(0,0); // 1행에서 시작
      lcd.print("Load 9#: ");
      Serial.println("Load 9#: ");
      
      lcd.setCursor(0,1); // 2행에서 시작
      lcd.print(Ninth_IRType,HEX);
      Serial.println(Ninth_IRType,HEX);
      
      PreBitType = Ninth_BitType;
      PreIRType = Ninth_IRType;
      PreDecodeType = Ninth_DecodeType;
     }
     

        
      irrecv.resume(); // Receive the next value
    }

    

    
    else if(results.value == 0xFFC23D) // 리모콘 PLAY 버튼 클릭시 조건 실행
    {

    ShowAnt();

    lcd.setCursor(4,0); // 1행에서 시작
    lcd.print("#>");
    lcd.print(PreIRType,HEX);
    
    lcd.setCursor(4,1); // 2행에서 시작
    lcd.print("Attacking...");
    
    IR_Attack();

    lcd.setCursor(4,1); // 2행에서 시작
    lcd.print("Attack Done.");
    

    delay(40);
    irrecv.resume(); // Receive the next value
    irrecv.enableIRIn(); // Start the receiver
    }

    
    else if(results.value == 0xFF9867) // 리모콘 100+ 버튼 클릭시 조건 실행
    {

    ShowAnt();
    lcd.setCursor(4,0); // 1행에서 시작
    lcd.print("Attacking...");

    int count=0;
    while(count!=100)
    {
    IR_Attack();
    count++;
    lcd.setCursor(4,1); // 1행에서 시작
    lcd.print(count);
    lcd.print("/100");
    delay(40);
    irrecv.resume(); // Receive the next value
    irrecv.enableIRIn(); // Start the receiver
    }

    }


    else if(results.value == 0xFFB04F) // 리모콘 200+ 버튼 클릭시 조건 실행
    {

    ShowAnt();
    lcd.setCursor(4,0); // 1행에서 시작
    lcd.print("Attacking...");

    int count=0;
    while(count!=200)
    {
    IR_Attack();
    count++;
    lcd.setCursor(4,1); // 1행에서 시작
    lcd.print(count);
    lcd.print("/200");
    delay(40);
    irrecv.resume(); // Receive the next value
    irrecv.enableIRIn(); // Start the receiver
    }

    }
    
    else
    {
    dump(&results);
    Serial.println(results.value, HEX); // 시리얼에 수신 값 출력

    ShowAnt();


    lcd.setCursor(4,0); // 1행에서 시작
    lcd.print("[Recv SIG]"); // LCD에 수신 값 출력
    
    lcd.setCursor(4,1); // 1행에서 시작
    lcd.print(results.value, HEX); // LCD에 수신 값 출력
    
    irrecv.resume(); // Receive the next value
    }
  }
  delay(100);

  
  
}

void dump(decode_results *results) {
  // Dumps out the decode_results structure.
  // Call this after IRrecv::decode()
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  }
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");

  }
  else if (results->decode_type == SONY) { 
    Serial.print("Decoded SONY: ");
  }
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  }
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results->decode_type == PANASONIC) {
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results->address, HEX);
    Serial.print(" Value: ");
  }
  else if (results->decode_type == LG) {
    Serial.print("Decoded LG: ");
  }
  else if (results->decode_type == JVC) {
    Serial.print("Decoded JVC: ");
  }
  else if (results->decode_type == AIWA_RC_T501) {
    Serial.print("Decoded AIWA RC T501: ");
  }
  else if (results->decode_type == WHYNTER) {
    Serial.print("Decoded Whynter: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  PreBitType = results->bits; // 사전 비트 저장
  PreIRType = results->value; // 사전 신호 저장
  PreDecodeType = results->decode_type; // 사전 디코드 저장
  

  for (int i = 1; i < count; i++) {
    if (i & 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    }
    else {
      Serial.write('-');
      Serial.print((unsigned long) results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println();
}


void ShowMos()
{ 
  byte Mos_One[8] = {
        B00010,
        B00001,
        B00001,
        B00000,
        B11000,
        B11111,
        B00111,
        B00000
};

byte Mos_Two[8] = {
        B00100,
        B00100,
        B10101,
        B10101,
        B01110,
        B11111,
        B11111,
        B01110
};

byte Mos_Three[8] = {
        B01000,
        B10000,
        B10000,
        B00000,
        B00011,
        B11111,
        B11100,
        B00000
};

byte Mos_Four[8] = {
        B00001,
        B00001,
        B00001,
        B00010,
        B00100,
        B01001,
        B01001,
        B00001
};

byte Mos_Five[8] = {
        B01110,
        B01110,
        B01110,
        B10101,
        B10101,
        B00000,
        B00000,
        B00000
};
byte Mos_Six[8] = {
        B10000,
        B10000,
        B10000,
        B01000,
        B00100,
        B10010,
        B10010,
        B10000
};



    // 모기
    lcd.createChar(0, Mos_One);
    lcd.createChar(1, Mos_Two);
    lcd.createChar(2, Mos_Three);
    lcd.createChar(3, Mos_Four);
    lcd.createChar(4, Mos_Five);
    lcd.createChar(5, Mos_Six);
    lcd.begin(16, 2);
    delay(50);

    
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    delay(50);
    lcd.write(byte(1));
    delay(50);
    lcd.write(byte(2));
    delay(50);

    lcd.setCursor(0, 1);
    lcd.write(byte(3));
    delay(50);
    lcd.write(byte(4));
    delay(50);
    lcd.write(byte(5));
    delay(50);


}

void ShowAnt()
{
  
  byte Ant_One[8] = {
        B00000,
        B00000,
        B00000,
        B00111,
        B01100,
        B01000,
        B10000,
        B10000
};

byte Ant_Two[8] = {
        B00000,
        B00000,
        B00000,
        B11000,
        B00100,
        B00000,
        B00011,
        B00110
};

byte Ant_Three[8] = {
        B00000,
        B00000,
        B00100,
        B01000,
        B10000,
        B00000,
        B00000,
        B00000
};

byte Ant_Four[8] = {
        B10000,
        B10000,
        B11000,
        B01000,
        B00100,
        B00011,
        B00111,
        B11111
};

byte Ant_Five[8] = {
        B01100,
        B00000,
        B00000,
        B00000,
        B00001,
        B11110,
        B11100,
        B11111
};


byte Ant_Six[8] = {
        B10000,
        B10000,
        B10000,
        B10000,
        B00000,
        B00000,
        B00000,
        B00000
};

 // 안테나
    lcd.createChar(0, Ant_One);
    lcd.createChar(1, Ant_Two);
    lcd.createChar(2, Ant_Three);
    lcd.createChar(3, Ant_Four);
    lcd.createChar(4, Ant_Five);
    lcd.createChar(5, Ant_Six);

    
    lcd.begin(16, 2);
    //delay(50);

    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    //delay(50);
    lcd.write(byte(1));
    //delay(50);
    lcd.write(byte(2));
    //delay(50);
    
    lcd.setCursor(0, 1);
    lcd.write(byte(3));
    //delay(50);
    lcd.write(byte(4));
    //delay(50);
    lcd.write(byte(5));
    //delay(50);
}





void LCD_main()
{


  ShowAnt();
  delay(50);
  
  lcd.setCursor(5,0); // 1행에서 시작
  lcd.print("Complete");
  delay(50);

  lcd.setCursor(5,1); // 2행에서 시작
  lcd.print("LCD!");
  delay(3000);

  lcd.setCursor(5,0); // 2행에서 시작
  lcd.print("Co");
  delay(100);
  lcd.print("mp");
  delay(100);
  lcd.print("le");
  delay(100);
  lcd.print("te");
  delay(100);
  lcd.print(" ");

  //ShowMos();
  lcd.setCursor(5,1); // 2행에서 시작
  delay(100);
  lcd.print("On");
  delay(100);
  lcd.print("li");
  delay(100);
  lcd.print("ne!");
  delay(3000);
  lcd.init();


  ShowMos();
  delay(50);
  lcd.setCursor(4,0); // 2행에서 시작
  lcd.print("[IR]");

  lcd.setCursor(4,1); // 2행에서 시작
  lcd.print("HIJACKER 2.0");
  delay(100);





}

void IR_Attack()
{
  
  if(PreDecodeType == NEC)
  {
    irsend.sendNEC(PreIRType, PreBitType);
  }

  else if(PreDecodeType == SONY)
  {
    irsend.sendSony(PreIRType, PreBitType);
  }

  else if(PreDecodeType == RC5)
  {
    irsend.sendRC5(PreIRType, PreBitType);
  }
  
  else if(PreDecodeType == RC6)
  {
    irsend.sendRC6(PreIRType, PreBitType);
  }

  else if(PreDecodeType == LG)
  {
    irsend.sendLG(PreIRType, PreBitType);
  }
 
}
