#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__

bit OneWire_Init();
void OneWire_WriteBit(bit Bit);
bit OneWire_ReadBit();
void OneWire_WriteByte(unsigned char byte);
unsigned char OneWire_ReadByte();

#endif