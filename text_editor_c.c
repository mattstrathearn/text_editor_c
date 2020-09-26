#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

struct termios original_settings;

void enableRawMode(){

	tcgetattr(STDIN_FILENO, &original_settings);

	struct termios raw = original_settings;

	raw.c_lflag &= ~(ECHO | ICANON);

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

}

void disableRawMode(){

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_settings);

}

int main(){

	atexit(disableRawMode);

	enableRawMode();

	char c;

	while(read(STDIN_FILENO, &c, 1) == 1 && c!='q'){

		if(iscntrl(c)){
			printf("%d\n", c);
		} else {
     		printf("%d ('%c')\n", c, c);
		}
	}

}