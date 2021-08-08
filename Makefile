CFLAGS = -O2 -I. -I/usr/include/tcl -I/usr/include/tk
OBJ = main.o

T = VPNetwork

all: 	$T 
$T:	$(OBJ)
	$(CC) -o $@ $(OBJ)

install:  $(shell sh requirements.sh)

clean:
	rm -f $T $(OBJ)
