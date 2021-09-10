#include "header.h"

extern void output(char*);

void trace(char* message) {
  if (useVisual) output(message);
    else printf("%s\n",message);
  }

