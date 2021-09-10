#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#ifdef _WIN32
#pragma warning(disable: 4996)
#include <io.h>
#include <conio.h>
#include <direct.h>
#include "sys/time.h"
#else
#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#endif

typedef uint64_t qword;
typedef uint32_t dword;
typedef uint16_t word;
typedef uint8_t byte;

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
LINK byte liveUpdate;
#ifndef _WIN32
LINK struct termios original;
#endif
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


