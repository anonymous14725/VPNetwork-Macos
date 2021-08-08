#include "tklib.h"

int main(){
	reset();

    	char c[256];
    	strcpy(c,"if { [catch { exec macosvpn create --l2tp Connection --endpoint public-vpn-74.opengw.net --username vpn --password vpn --sharedsecret vpn } msg] } {\n");
    	strcat(c,"puts \"Connecting..\"\n");
    	strcat(c,"}\n");
    	strcat(c,"exec networksetup -connectpppoeservice Connection\n");
    	proc("connect",c);

    	char d[256];
    	strcpy(d,"exec networksetup -disconnectpppoeservice Connection\n");
    	strcat(d,"puts \"Disconnected!\"");
    	proc("disconnect",d);

    	char w[256];
    	strcpy(w,"if { [catch { exec macosvpn delete --name Connection } msg] } {\n");
    	strcat(w,"puts \"Closed!\"\n");
    	strcat(w,"}\n");
    	strcat(w,"exit");
    	proc("close",w);

    	title("VPNetwork");
    	icon("/tcl/examples/tk8.4.5/win/rc/wish.ico");
    	closewindow("close");

	canvas(".canVas","280","215");
	id(".canVas","create text 30 20 -text \"Design by \\n Cunknown\" -font { Helvetica -10 }");
	id(".canVas","create text 140 110 -text \"VPNetwork\" -font { Helvetica -25 bold }");

	button(".b","connect","10","10","Connect to VPN");
	button(".b2","disconnect","5","5","Disconnect");

   	printf(red "This application requires root access" set);
    	printf(set cyan "\nPlease use the sudo -s or su command" set "\n");
	run();
	return 0;
}
