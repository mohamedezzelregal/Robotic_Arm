#include <Servo.h>
// #include <LiquidCrystal.h>

// //Start point angels for each servo
#define BASE_ROTATION_START 110
#define JOINT1_START 0
#define JOINT2_START 0
#define JOINT3_START 200

#define ARM_ROTATION_START 35
#define HAND_OPEN 0
#define HAND_CLOSED 60

//pins for each servo
#define BASE_ROTATION_PIN 3
#define JOINT1_PIN 5
#define JOINT2_PIN 6
#define JOINT3_PIN 9
#define ARM_ROTATION_PIN 10
#define HAND_PIN 11

Servo base_rotation;
Servo joint1;
Servo joint2;
Servo joint3;
Servo arm_rotation;
Servo hand;




// // poses
///////////////////////////////////////////////
void pick_down_action() {

  int JOINT3_DOWN = 75;
  int JOINT1_DOWN = 45;
  int JOINT2_DOWN = 135;

  joint1.write(JOINT1_DOWN);
  delay(2000);
  joint2.write(JOINT2_DOWN);
  delay(2000);
  joint1.write(JOINT1_DOWN+45);
  delay(2000);
   joint2.write(JOINT2_DOWN +35);
   delay(2000);
  joint3.write(JOINT3_DOWN);
  delay(2000);
  hand.write(HAND_CLOSED);
}

//////////////////////////////////////////////////
void pick_up_action() {

int JOINT1_PICKUP = 80;
int JOINT2_PICKUP = 100;
int JOINT3_PICKUP = 30;

  joint2.write(JOINT2_PICKUP);
  delay(2000);
  joint1.write(JOINT1_PICKUP);
  delay(2000);
  joint3.write(JOINT3_PICKUP);
  delay(2000);
  hand.write(HAND_CLOSED);
  delay(1000);
  
}
////////////////////////////////////////////////////
void rotate_to_right() {
  int ARM_ROTATION_RIGHT = 45;
  base_rotation.write(ARM_ROTATION_RIGHT);
  delay(1000);
  hand.write(HAND_OPEN);
}
//////////////////////////////////////////////////
void LastPos(){
  int JOINT1_PICKUP = 135;
  int JOINT1_f = 135;
  int JOINT1_l = 0;
  int JOINT2_f = 110;
  int JOINT2_l = 0;
  int JOINT3_PICKUP = 200;
  
  base_rotation.write(BASE_ROTATION_START);
  delay(2000);

  joint3.write(JOINT3_START);
  delay(2000);
  
  joint2.write(JOINT2_f);
  delay(3000);
  
  joint1.write(JOINT1_l);
  delay(2000);
//  joint1.write(JOINT1_f);
//  delay(2000);
  
  joint2.write(JOINT2_l);
  delay(2000);
  
  joint1.write(JOINT1_l);
  delay(2000);

  joint3.write(JOINT3_START);
  arm_rotation.write(ARM_ROTATION_START);
  hand.write(HAND_OPEN);
  }
//////////////////////////////////////////////////////////
void defaultPose() {
  base_rotation.write(BASE_ROTATION_START);
  delay(1000);
  joint1.write(JOINT1_START);
  delay(1000);
  joint2.write(JOINT2_START);
  delay(1000);
  joint3.write(JOINT3_START);
  arm_rotation.write(ARM_ROTATION_START);
  hand.write(HAND_OPEN);
}

//////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);

  defaultPose();

  delay(2000);
  base_rotation.attach(BASE_ROTATION_PIN);
  delay(500);
  joint1.attach(JOINT1_PIN);
  delay(500);
  joint2.attach(JOINT2_PIN);
  delay(500);
  joint3.attach(JOINT3_PIN);
  delay(500);
  arm_rotation.attach(ARM_ROTATION_PIN);
  delay(500);
  hand.attach(HAND_PIN);

  delay(3000);

  // Testing Poses
  pick_down_action();
  delay(2000);
  pick_up_action();
  delay(2000);
  rotate_to_right();
}

void loop() {
  // if(Serial.available() > 0){
  //   String massege = "";
  //   while(Serial.available() > 0){
  //     char data = Serial.read();
  //     if(data != '\n'){
  //       massege += data;
  //     }else{
  //       if(massege.equals("Send Ack")){
  //         Serial.println("Arduino Ack");
  //         // lcd.clear();
  //         printf("Arduino connected");
  //       }else if(massege.equals("First")){
  //         int angle_data = 0;
  //         while (Serial.available() <= 0);
  //         while(Serial.available() > 0){
  //           char data = Serial.read();
  //           if(data != '\n' && data <= '9' && data >= '0'){
  //             angle_data = angle_data * 10 + (data - '0');
  //           }else{
  //             // joint1.write(Joint1Rotation(angle_data));
  //             // lcd.clear();
  //             // lcd.print(Joint1Rotation(angle_data));
  //             // lcd.print(",");
  //             break;
  //           }
  //           delay(10);
  //         }
  //       }else if(massege.equals("Second")){
  //         int angle_data = 0;
  //         while (Serial.available() <= 0);
  //         while(Serial.available() > 0){
  //           char data = Serial.read();
  //           if(data != '\n' && data <= '9' && data >= '0'){
  //             angle_data = angle_data * 10 + (data - '0');
  //           }else{
  //             // joint2.write(Joint2Rotation(angle_data));
  //             // lcd.print(Joint2Rotation(angle_data));
  //             // lcd.print(",");
  //             break;
  //           }
  //           delay(10);
  //         }
  //       }else if(massege.equals("Third")){
  //         int angle_data = 0;
  //         while (Serial.available() <= 0);
  //         while(Serial.available() > 0){
  //           char data = Serial.read();
  //           if(data != '\n' && data <= '9' && data >= '0'){
  //             angle_data = angle_data * 10 + (data - '0');
  //           }else{
  //             // joint3.write(Joint3Rotation(angle_data));
  //             // lcd.print(Joint3Rotation(angle_data));
  //             // lcd.print(",");
  //             break;
  //           }
  //           delay(10);
  //         }
  //       }else if(massege.equals("Base")){
  //         int angle_data = 0;
  //         while (Serial.available() <= 0);
  //         while(Serial.available() > 0){
  //           char data = Serial.read();
  //           if(data != '\n' && data <= '9' && data >= '0'){
  //             angle_data = angle_data * 10 + (data - '0');
  //           }else{
  //             // base_rotation.write(BaseRotation(angle_data));
  //             // lcd.print(BaseRotation(angle_data));
  //             break;
  //           }
  //           delay(10);
  //         }
  //       }else if(massege.equals("Reset")){
  //         // base_rotation.write(BASE_ROTATION_START);
  //         // joint1.write(JOINT1_START);
  //         // joint2.write(JOINT2_START);
  //         // joint3.write(JOINT3_START);
  //         delay(10);
  //       }else if(massege.equals("Open Hand")){
  //         // Hand.write(HAND_OPEN);
  //         delay(10);
  //       }else if(massege.equals("Close Hand")){
  //         // Hand.write(HAND_CLOSED);
  //         delay(10);
  //       }
  //     }
  //     delay(20);
  // }
  // }
}
