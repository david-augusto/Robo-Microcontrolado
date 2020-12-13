#define IN1  RC0_bit
#define IN2  RC3_bit


#define SEE  RB4_bit
#define SCE  RB5_bit
#define SCD  RB6_bit
#define SED  RB7_bit

#define IN3  RC4_bit
#define IN4  RC5_bit


#define LED RA0_bit

 void frenteRobo(){
      IN1 = 1;
      IN2 = 0;
      IN3 = 0;
      IN4 = 1;

 }
  void trasRobo(){
      IN1 = 0;
      IN2 = 1;
      IN3 = 1;
      IN4 = 0;
 }
 void meiaVoltaDireita(){
      IN1 = 1;
      IN2 = 0;
      IN3 = 1;
      IN4 = 0;
 
 }

  void meiaVoltaEsquerda(){
      IN1 = 0;
      IN2 = 1;
      IN3 = 0;
      IN4 = 1;
 }
 void paraRobo(){
      IN1 = 0;
      IN2 = 0;
      IN3 = 0;
      IN4 = 0;
 }
void main() {
unsigned short duty1 = 0;
unsigned short duty2 = 0;
TrisA = 0xFE;
TrisB = 0xFF;
TrisC = 0x00;
PortA = 0xFE;
PortB = 0xFF;
PortC = 0x00;
CMCON = 7;
ADCON1 = 7;
NOT_RBPU_bit = 0;
delay_ms(1000);
LED = 1;
 PWM1_Init(5000);
 PWM1_Start();

  PWM2_Init(5000);
  PWM2_Start();
  duty1=255;
  duty2=255;
  PWM1_Set_Duty(duty1);
  PWM2_Set_Duty(duty2);
    
      while(1){
      
      if(((SEE == 0) && (SCE == 0)) && ((SCD == 0) && (SED == 0))){
             paraRobo();
      }
      if(((SEE == 1) && (SCE == 1)) && ((SCD == 1) && (SED == 1))){
             paraRobo();
      }
      if(((SEE == 0) && (SCE == 1)) && ((SCD == 1) && (SED == 0))){
          duty1=255;
          duty2=255;
          PWM1_Set_Duty(duty1);
          PWM2_Set_Duty(duty2);
          frenteRobo();
      }else{
        if(((SEE == 0) && (SCE == 0)) && ((SCD == 0) && (SED == 1))){
          duty1=210;
          duty2=255;
          PWM1_Set_Duty(duty1);
          PWM2_Set_Duty(duty2);
          meiaVoltaDireita();
        }else if(((SEE == 0) && (SCE == 0)) && ((SCD == 1) && (SED == 0))){
          duty1=255;
          duty2=255;
          PWM1_Set_Duty(duty1);
          PWM2_Set_Duty(duty2);
          meiaVoltaDireita();
        }else if(((SEE == 0) && (SCE == 0)) && ((SCD == 1) && (SED == 1))){
          duty1=255;
          duty2=255;
          PWM1_Set_Duty(duty1);
          PWM2_Set_Duty(duty2);
          meiaVoltaDireita();
        }else if(((SEE == 0) && (SCE == 1)) && ((SCD == 1) && (SED == 1))){
          duty1=255;
          duty2=255;
          PWM1_Set_Duty(duty1);
          PWM2_Set_Duty(duty2);
          meiaVoltaDireita();
        } else{
          duty1=255;
          duty2=255;
          PWM1_Set_Duty(duty1);
          PWM2_Set_Duty(duty2);
          meiaVoltaEsquerda();
        }
        }
  }
}
