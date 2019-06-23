#include <PID_v1.h>//libreria del pid
#define ventilador 9// se define el pin del ventilador
double Setpoint, Input, Output;// se define las variables  donde se conectaran



//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,1.5,0.1,1.5,P_ON_E, REVERSE); //P_ON_M se especifica la proporcion de la medida
                                                            //P_ON_E (Proporcional en error) es el comportamiento predeterminado

void SetupPid()
{
  Input = t ;//se define como entrada la temperatura
  Setpoint = 30;// grados de la temperatura
  
    myPID.SetTunings(10,3,1); //medidas proporcionales
    myPID.SetControllerDirection(REVERSE);//control de la direccion
    myPID.SetSampleTime(10000);//tiempo que responde el sensor
    myPID.SetOutputLimits(-255,255);//la velcidad del motor
    myPID.SetMode(AUTOMATIC);//el pid se lo programa como automatico

}

void TareaPID()
{
  Input = t;//define como entrada la temperatura
  myPID.Compute();//calculos que ase el computador
 analogWrite (ventilador ,Output);//el ventilador se lo declara como salida

 
          }

   
