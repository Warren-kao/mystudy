#ifndef __XPT2406_H__
#define __XPT2406_H__

#define XPT2046_XP		0xBC
#define XPT2046_YP		0xDC
#define XPT2046_VBAT	0xAC
#define XPT2046_AUX		0xEC

unsigned int XPT2046_ReadAD(unsigned char Command);


#endif