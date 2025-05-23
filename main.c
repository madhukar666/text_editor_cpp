
#include <termios.h>
#include <unistd.h>
#include <stdio.h>


/*To go from canonical mode to raw mode : program outputs the user input as he enters*/
void enableRawMode(){

    struct termios raw;

    tcgetattr(STDIN_FILENO,&raw);
    raw.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);

}
int main(){

    enableRawMode();

    char c;

    /* It stops reading after it encounyters the delimiter '~'*/
    while(read(STDIN_FILENO,&c,1) == 1 && c!='~');
    return 0;

}