
#include <unistd.h>
#include <stdio.h>

int main(){

    char c;
    /* currently terminal is in canonical mode i.e., it reads the characters and only takes the read content after the
    user clicks enter i mean it doesn't act the way text editors do
    It stops reading after it encounyters the delimiter '~'*/
    while(read(STDIN_FILENO,&c,1) == 1 && c!='~');
    return 0;

}