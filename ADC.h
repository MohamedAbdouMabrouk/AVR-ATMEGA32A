#ifndef ADC_H
#define	ADC_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define Channel0 0
#define Channel1 1
#define Channel2 2
#define Channel3 3
#define Channel4 4
#define Channel5 5
#define Channel6 6
#define Channel7 7

#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define Verf_AREF 0
#define Verf_AVCC 1
#define Verf_INTERNAL 3

#define PS_2 1
#define PS_4 2
#define PS_8 3
#define PS_16 4
#define PS_32 5
#define PS_64 6
#define PS_128 7

#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

void ADC_selectVref(int Vref);
void ADC_selectChannel(int ChannelNumber);
void ADC_selectPrescalar(int Prescalar);
void ADC_ENABLE();
void ADC_DISABLE();
void ADC_START();
void ADC_INIT(int ChannelNumber, int Verf, int Prescalar);
int ADC_READ_R();
int ADC_READ_L();

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

