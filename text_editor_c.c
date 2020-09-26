#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int main(){

	char c;

	while(read(STDIN_FILENO, &c, 1) == 1 && c!='q');

}