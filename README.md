# ระบบแจ้งเตือนการถูกบุกรุกผ่าน LINE Notify(SMART TRAP)
  ระบบแจ้งเตือนการถูกบุกรุกผ่าน LINE Notify(SMART TRAP) ใช้สำหรับการตรวจจับบุคคลที่เข้ามาในพื้นที่ที่ไม่ได้รับอนุญาต โดยจะแจ้งเตือนให้กับเจ้าของสถานที่หรือบุคคลที่มีหน้าที่รับผิดชอบสถานที่หรือพื้นที่ให้ได้ทราบ

## คุณสมบัติ
  - มีการประมวลผลแบบเรียลไทม์
  - มีเเสดงผลแบบเรียลไทม์ผ่าน LINE Notify
## ส่วนประกอบ
  - Node Micro-Controller Unit: MCU node ESP8266 เป็นอุปกรณ์สำหรับการประมวลผล
  - Passive infrared sensor (PIR sensor) เป็นอุปกรณ์สำหรับตรวจจับการเคลื่อนไหว 
  - Active Buzzer Module เป็นอุปกรณ์สำหรับการแจ้งเตือนภายในพื้นที่ที่ถูกบุกรุก
## ไลบรารี่
  - C-Sketch เป็นภาษาที่ใช้พัฒนาระบบ
  - Blynk Library สำหรับการเชื่อมต่อไปยัง Application ของ Blynk เพื่อใช้ในการเปิดปิดระบบ
  - ESP8266WiFi library ใช้สำหรับการเชื่อมต่อ Internet เพื่อให้ตัวระบบสามารถส่งข้อมูลไปยัง Line Notify 
  - LINE Notify ใช้สำหรับการแจ้งเตือนผู้ใช้งานระบบ เมื่อระบบพบเจอผู้บุกรุก
# ผลลัพธ์
## Blynk app
![image](https://i.imgur.com/fP6v533.jpg)
## Line Notify
![image](https://i.imgur.com/VCvhRwp.jpg)
## Wired Circuit
![image](https://i.imgur.com/qtLsjDP.jpg)
## System Architecture
![image](https://i.imgur.com/NUnAQQZ.png)
## สมาชิกในกลุ่ม
    63103949 นายทีปกร สินธุ์อ่อน               
    63112379 นายอลงกต ธุระวงศ์   
    63110282 นายศักดิ์ดา เอี่ยมพงศ์ษา  
    63110068 นายศรัณย์ภัทร พรหมทอง 
