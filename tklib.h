#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define red       "\x1B[31m"
#define cyan      "\x1B[36m"
#define set       "\x1B[0m"

void reset(void);

void exec(char system[256]);
void proc(char function[20],char commands[256]);

int title(char system[256]);
int icon(char system[256]);
int closewindow(char system[256]);
int canvas(char id[256],char width[100],char height[100]);
int id(char id[256],char system[1024]);
int button(char id[256],char coommand[128],char padx[10],char pady[10],char text[256]);
int messageBox(char type[10],char icon[10],char title[100],char message[256]);

void run();
