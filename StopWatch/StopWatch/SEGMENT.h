


#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "DIO_Interface.h"
#include "StdTypes.h"

#define SEGMANT_PORT PA
#define EN1 PINC6
#define EN2 PINC7

void SEGMENT_Display(u8 num);
void SEGMENT_Display_BCD(u8 n);
void SEGMENT_Display_MX2(u8 n);





#endif /* SEGMENT_H_ */