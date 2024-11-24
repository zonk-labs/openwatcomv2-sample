CC = wcc386
LD = wlink

CFLAGS = -bt=nt -3r -d2 -fo=.obj -i="$(%WATCOM)/h/nt"
LFLAGS = system win95 libpath $(%WATCOM)/lib386/nt/ option stack=64k

TARGET = helloworld.exe

SRCS = main.c
OBJS = $(SRCS:.c=.obj)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) name $@ file { $(OBJS) }

# Compiling
.c.obj:
	$(CC) $(CFLAGS) $<

clean: .SYMBOLIC
	rm *.obj
	rm $(TARGET)
