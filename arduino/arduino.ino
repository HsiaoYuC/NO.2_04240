int APIN = A0;    //類比訊號腳位
int DPIN = 3;   //數位訊號腳位
int val;               // 用于存储LM35读到的值
double data;          //用于存储已转换的温度值
unsigned long tepTimer ;   
void setup()
{
  Serial.begin(9600);
  pinMode(APIN , INPUT);
  pinMode(DPIN , INPUT);
  pinMode(8, OUTPUT);        // 蜂鸣器引脚设置
}

void loop()
{
    
    val=analogRead(0);   //LM35连到模拟口，并从模拟口读值
    data = (double) val * (5/10.24);  // 得到电压值，通过公式换成温度
    
  int AVal = analogRead(APIN);    //讀取類比串口的資料
  int DVal = digitalRead(DPIN);   //讀取數位串口的資料

  if(millis() - tepTimer > 10000){     // 每10s，串口输出一次温度值
             tepTimer = millis();
             Serial.print("temperature: ");     // 串口输出“温度”
             Serial.print(data);               // 串口输出温度值
             Serial.println("C");              // 串口输出温度单位
             Serial.print("humidity: ");     // 串口输出“濕度”
             Serial.println(AVal);
             Serial.print("water: ");     // 串口输出“水”
             Serial.println(DPIN);
  } 
  
}

