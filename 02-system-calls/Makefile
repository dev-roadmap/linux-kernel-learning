CC = gcc

DEBUG_LEVEL     = -g
EXTRA_CCFLAGS   = -Wall
CCFLAGS         = $(DEBUG_LEVEL) $(EXTRA_CCFLAGS)

%: %.c
	$(CC) $(CCFLAGS) $< -o $@

all: system-calls