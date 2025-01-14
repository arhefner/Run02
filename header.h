#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

typedef u_int64_t qword;
typedef u_int32_t dword;
typedef u_int16_t word;
typedef u_int8_t byte;

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

typedef struct {
  byte p;
  byte x;
  word r[16];
  byte d;
  byte df;
  byte i;
  byte n;
  byte ie;
  byte q;
  byte t;
  byte ef[4];
  byte idle;
  byte ram[65536];
  byte ci;
  byte xi;
  byte cie;
  byte xie;
  byte cmode;
  byte crunning;
  byte cntr;
  byte ch;
  byte etq;
  byte cpre;
  } CPU;

LINK CPU  cpu;
LINK int  cycles;
LINK long long icount;
LINK byte runFlag;
LINK byte use1805;
LINK byte useBios;
LINK byte useElfos;
LINK byte useVisual;
LINK byte elfos4;
LINK byte runDebugger;
LINK byte showMap;
LINK byte showTrace;
LINK word ramStart;
LINK word ramEnd;
LINK int  imap[256];
LINK char mmap[256];
LINK double freq;
LINK struct termios original;
LINK byte liveUpdate;
LINK char **conditions;
LINK int    numConditions;
LINK byte useConditions;

extern void cpuCycle(CPU *cpu);
extern void cpuDmaIn(CPU* cpu, byte v);
extern byte cpuDmaOut(CPU* cpu);
extern void cpuIntr(CPU* cpu, char typ);
extern void cpuReset(CPU *cpu);

extern void debugger(CPU* cpu);
extern int loader(char* filename);
extern void trace(char* message);

#endif


