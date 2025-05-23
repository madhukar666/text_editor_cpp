#include <ctype.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct termios orig_termios;

void disableRawMode(){

    tcsetattr(STDIN_FILENO,TCSAFLUSH,&orig_termios);
}


/*To go from canonical mode to raw mode : program outputs the user input as he enters*/
void enableRawMode(){

    
    /*reads the attributes input to terminal to termios structure*/
    tcgetattr(STDIN_FILENO,&orig_termios);
    atexit(disableRawMode);


    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO  |  ICANON); // ICANON  flag diables canonical mode


    /* flushes the content stored in termios struct to the terminal as output*/
    tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);

}
int main(){

    enableRawMode();

    char c;

    /* It stops reading after it encounyters the delimiter '~'*/
    while(read(STDIN_FILENO,&c,1) == 1 && c!='~');
    return 0;

}