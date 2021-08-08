#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run(void);

int main(){
   	printf("\x1B[31m" "This application requires root access" "\x1B[0m");
    	printf("\x1B[0m" "\x1B[36m" "\nPlease use the sudo ./VPNetwork command" "\x1B[0m" "\n");
	run();
	return 0; 
}


void run(void){
    system("wish Tk.tcl");
}
