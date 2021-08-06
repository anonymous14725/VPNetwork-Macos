CFLAGS = -O2 -I. -I/usr/include/tcl -I/usr/include/tk
OBJ = tklib.o main.o

T = VPNetwork
all: $T
$T:	$(OBJ)
	$(CC) -o $@ $(OBJ)

clean:
	rm -f $T $(OBJ)
