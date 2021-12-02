proc connect {} {
	if { [catch { exec macosvpn create --l2tp Connection --endpoint public-vpn-55.opengw.net --username vpn --password vpn --sharedsecret vpn } msg] } {
		puts "Connecting.."
	}
	exec networksetup -connectpppoeservice Connection
} 

proc disconnect {} {
	exec networksetup -disconnectpppoeservice Connection
	puts "Disconnected!"
} 

proc close {} {
	if { [catch { exec macosvpn delete --name Connection } msg] } {
		puts "Closed!"
	}
	exit
} 

wm title . "VPNetwork"
wm iconbitmap . /tcl/examples/tk8.4.5/win/rc/wish.ico
wm protocol . WM_DELETE_WINDOW close

canvas .canVas -width 280 -height 215 
pack .canVas
.canVas create text 30 20 -text "Design by \n Cunknown" -font { Helvetica -10 }
.canVas create text 140 110 -text "VPNetwork" -font { Helvetica -25 bold }

button .b -command {connect} -padx 10 -pady 10 -text "Connect to VPN" 
pack .b

button .b2 -command {disconnect} -padx 5 -pady 5 -text "Disconnect" 
pack .b2

