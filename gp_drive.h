#define RCC_APB2ENR    (*((volatile unsigned long *) 0x40021018))  //pointers for these address. memory address from RF manu
																																	 // manual i.e from memory map topic.
	
#define GPIO_A    (*((volatile unsigned long *) 0x40010800))
#define GPIO_B    (*((volatile unsigned long *) 0x40010C00))
#define GPIO_C    (*((volatile unsigned long *) 0x40011000))
#define GPIO_D    (*((volatile unsigned long *) 0x40011400))

// CRL and CRH registers in the GPIO selection
#define PA 1     // port selection
#define PB 2
#define PC 3

#define IN 0				// input mode
#define OP_10 1			//output with 10kHz ,2kHz,50Khz
#define OP_2 2
#define OP_50 3

#define I_AN 0     //input selection with analog mode, float mode, push pull
#define I_F 1
#define I_PP 2


#define O_GP_PP 0     //output selection with general purpose push pull, open drain
#define O_GP_OD 1			
#define O_AF_PP 2			// alaternative function with push pull, open drain
#define O_AF_OD 3

// write state of GPIO
#define LOW 0
#define HIGH 1

//port = PA, pin = 1 to.., dir = gpio speed = 10 or 20 or 50Mhz, opt = pull pup or pull down.
void init_gpio(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt); //dir = gp speed 50mhz or?


int Read_gp (unsigned short port, unsigned short pin);
void Write_gp(unsigned short port, unsigned short pin, unsigned state);

