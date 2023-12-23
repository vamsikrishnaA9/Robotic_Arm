#include "gp_drive.h"
#include "stm32f10x.h"
#include "Delay.h"
#include "stdint.h"
#include "math.h"



#define DIR1 8
#define STEP1 9
#define DIR2 0
#define STEP2 1
#define DIR3 3
#define STEP3 4

#define PI 3.141592625
#define RAD_TO_DEG 180/PI
#define DEG_TO_RAD PI/180

//double X3,Y3,Z3;
 
static double angle_1 = 0;
static double angle_2 = 0;
static double angle_3 =0;

/*
float init_Angle1 = 0;
float	init_Angle2 = 0;  
float	init_Angle3 = 0;
*/

static double link1= 122;
static double link2 = 120;
static double  link3 = 120;
static double X1_3, Y1_3, Z1_3;
//static double r1,r2,r3;
//double theta1,theta2,theta3;
//double phi1,phi2,phi3;

 int num_steps = 50;
	
static double targ_Theta[3];
static double *Out;
static double present[3];
static double previous[3];
//static double offset[3];
void Robot_pos(void);	
double *inv_KE(double X3, double Y3, double Z3);
void lower_Motor(double angle);
void left_Motor(double angle);
void right_Motor(double angle);
void Robot_move(double angle, int type);
void Robot_target(double* Out);

//Point Linear_interpolation(Point p1, Point p2, double t);


typedef struct {
    double x;
    double y;
} Point;


Point linear_interpolation(Point p1, Point p2, double t) {
    Point interpolated_point;
    interpolated_point.x = p1.x + (p2.x - p1.x) * t;
    interpolated_point.y = p1.y + (p2.y - p1.y) * t;
    return interpolated_point;
}

void Robot_pos(void){
	
	angle_1 = present[0]- previous[0];
	angle_2 = present[1]-previous[1];
	angle_3 = present[2]-previous[2];
		
}



double *inv_KE( double X3,  double Y3, double Z3){
	
	double theta1 =0; double theta2=0; double theta3 =0; double phi1=0; double phi2=0; double phi3=0;
	X1_3 = X3;
	Y1_3 = Y3;
	Z1_3 = Z3;
	double r1,r2,r3;
	theta1 = atan2(Y3,X3);
	r1 = sqrt((X3*X3) + (Y3*Y3));
	r2 = Z3 - link1;
	phi2 = atan2(r2,r1);
	r3 = sqrt((r1*r1) + (r2*r2));
	phi1 = acos(((link3*link3)-(link2*link2)-(r3*r3))/(-2*link2*r3));
	phi3 = acos(((r3*r3)-(link2*link2)-(link3*link3))/(-2*link2*link3));
	theta3 = phi3-(180*DEG_TO_RAD);
	theta2 = phi2+phi1;
	targ_Theta[0] = theta1* RAD_TO_DEG;
	targ_Theta[1] = theta2* RAD_TO_DEG;
	targ_Theta[2] = theta3* RAD_TO_DEG;
	
	return targ_Theta;
}


int main(void)
{
	
	init_gpio(PA, DIR1, OP_50, O_GP_PP);
	init_gpio(PB, STEP1, OP_50, O_GP_PP);
	init_gpio (PB, DIR2, OP_50, O_GP_PP);
	init_gpio(PB, STEP2, OP_50, O_GP_PP);
	init_gpio(PA, STEP3, OP_50, O_GP_PP);
	init_gpio(PA, DIR3, OP_50, O_GP_PP);
	
	
	Write_gp(PA,DIR1,LOW);
	Write_gp(PB,DIR2, LOW);
	Write_gp(PA,DIR3, HIGH);
	DelayInit();
	

Point point_A = {previous[1], previous[2]};
Point point_B = {present[1], present[2]};


Out = inv_KE(120,70, 80);
Robot_target(Out);
Robot_pos();

Robot_move(angle_1,1);
Robot_move(angle_2,2);
Robot_move(angle_3,3);

DelayMs(4000);

Out = inv_KE(60, -70, 240); //119.57, -113.05 //119.5, -96.52
Robot_target(Out);
Robot_pos();

Robot_move(angle_1,1);
Robot_move(angle_2,2);
Robot_move(angle_3,3);

DelayMs(3000);

Out = inv_KE(120, 0, 80);
Robot_target(Out);
Robot_pos();

Robot_move(angle_1,1);
Robot_move(angle_3, 3);
Robot_move(angle_2,2);




//Robot_move(angle_2,2);  //-90   +ve in angle makes the right motor up wards i.e gear turns backwards, theta 2
// Robot_move(angle_3,3);  //90  -ve in angle makes the left motor downwards i.e gear turns forward. theta 3
 DelayMs(500);


 
	while(1){
		
}
}

void lower_Motor(double angle){
	int total = 11377;
	float small_ang = 360/angle;
	int value =(int)(total/small_ang) ;
		for(int i=0; i<value; i++){
		Write_gp(PB,STEP1,HIGH);
		//DelayMs(5);
		DelayUs(500);
		Write_gp(PB,STEP1,LOW);
		DelayUs(500); }
	
}

void left_Motor(double angle){	
int total = 11377;
float small_ang = 360/angle;
int value =(int)(total/small_ang);
for(int i=0; i<value; i++){
		Write_gp(PB,STEP2,HIGH);
		//DelayMs(5);
		DelayUs(500);
		Write_gp(PB,STEP2,LOW);
		DelayUs(500); }
	
}

void right_Motor(double angle){	
int total = 11377;
float small_ang = 360/angle;
int value =(int)(total/small_ang);
for(int i=0; i<value; i++){
		Write_gp(PA,STEP3,HIGH);
		//DelayMs(5);
		DelayUs(500);
		Write_gp(PA,STEP3,LOW);
		DelayUs(500); 
}
	
}

void Robot_move(double angle, int type){
	switch (type){
		case 1:
			if(angle <0 ){
		Write_gp(PA, DIR1, LOW);
		angle = -angle;
    lower_Motor(angle);}
	   else {
		Write_gp(PA, DIR1, HIGH);
		lower_Motor(angle);
	   }
	break;
		case 2:
		if(angle <0 ){
		Write_gp(PA, DIR3, LOW);
		angle = -angle;
    right_Motor(angle);}
	   else {
			 Write_gp(PA, DIR3, HIGH);
		right_Motor(angle);
	   }
	break;
		case 3:
		if(angle <0 ){
		angle = -angle;
	   Write_gp(PB, DIR2, HIGH);
     left_Motor(angle);}
	   else {
			 Write_gp(PB, DIR2, LOW);
		 left_Motor(angle);
	    }
		 break;
				
		default : break;
   			
					
}
	}

	void Robot_target(double* out){
	
	double temp[3];
	
	temp[0]= 0;
	temp[1]=0;
	temp[2]=0;
	
	previous[0] = present[0];
	previous[1] = present[1];
	previous[2] = present[2];
	
	if(X1_3>=120 | Z1_3>=120){
		//*(Out+2) =  fabs(90.00-fabs(*(Out+2)));
		*(Out+2) = fabs(*(Out+1)-fabs(90 - fabs(*(Out+2))));
		*(Out+2) = -(*(Out+2));
	}

   else if(X1_3 <120 & Z1_3 <120){
   *(Out+2) = fabs(90 - fabs(*(Out+2)));

   }
	temp[0] = *out;
	temp[1] = *(out+1);
	temp[2] = *(out+2);
	
	present[0]= temp[0];
	present[1]= temp[1];
	present[2] = temp[2];
 }	 










