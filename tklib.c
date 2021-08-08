#include "tklib.h"

FILE * tk;

void reset(void){
    tk = fopen("Tk.tcl","w+");
    fputs("",tk);
    fclose(tk);
}

void exec(char system[256]){
    tk = fopen("Tk.tcl","a+");
    fputs("exec ",tk);
    fputs(system,tk);
    fputs("\n",tk);
    fclose(tk);
}

void proc(char function[20],char commands[256]){
    tk = fopen("Tk.tcl","a+");
    fputs("proc ",tk);
    fputs(function,tk);
    fputs(" {} {\n",tk);
    fputs(commands,tk);
    fputs("\n} \n",tk);
    fclose(tk);
}
int title(char system[256]){
    tk = fopen("Tk.tcl","a+");
    fputs("wm title . \"",tk);
    fputs(system,tk);
    fputs("\"\n",tk);
    fclose(tk);
    return 0;
}

int icon(char system[256]){
    tk = fopen("Tk.tcl","a+");
    fputs("wm iconbitmap . ",tk);
    fputs(system,tk);
    fputs("\n",tk);
    fclose(tk);
    return 0;
}

int closewindow(char system[256]){
    tk = fopen("Tk.tcl","a+");
    fputs("wm protocol . WM_DELETE_WINDOW ",tk);
    fputs(system,tk);
    fputs("\n",tk);
    fclose(tk);
    return 0;
}

int canvas(char id[256],char width[100],char height[100]){
    tk = fopen("Tk.tcl","a+");
    fputs("canvas ",tk);
    fputs(id,tk);
    fputs(" -width ",tk);
    fputs(width,tk);
    fputs(" -height ",tk);
    fputs(height,tk);
    fputs(" \npack ",tk);
    fputs(id,tk);
    fputs("\n",tk);
    fclose(tk);
    return 0;
}

int id(char id[256],char system[1024]){
    tk = fopen("Tk.tcl","a+");
    fputs(id,tk);
    fputs(" ",tk);
    fputs(system,tk);
    fputs("\n",tk);
    fclose(tk);
    return 0;
}

int button(char id[256],char command[128],char padx[10],char pady[10],char text[256]){
    tk = fopen("Tk.tcl","a+");
    fputs("button ",tk);
    fputs(id,tk);
    fputs(" -command {",tk);
    fputs(command,tk);
    fputs("} -padx ",tk);
    fputs(padx,tk);
    fputs(" -pady ",tk);
    fputs(pady,tk);
    fputs(" -text \"",tk);
    fputs(text,tk);
    fputs("\" \npack ",tk);
    fputs(id,tk);
    fputs("\n",tk);
    fclose(tk);
    return 0;
}

int messageBox(char type[10],char icon[10],char title[100],char message[256]){
    tk = fopen("Tk.tcl","a+");
    fputs("tk_messageBox -type ",tk);
    fputs(type,tk);
    fputs(" -icon ",tk);
    fputs(icon,tk);
    fputs(" -title ",tk);
    fputs(title,tk);
    fputs(" -message \"",tk);
    fputs(message,tk);
    fputs("\" \n",tk);
    fclose(tk);
    return 0;
}

void run(void){
    system("wish Tk.tcl");
    remove("Tk.tcl");
}

