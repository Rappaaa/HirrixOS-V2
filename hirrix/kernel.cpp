/** LCPP Compiler - (c) Litikz 2018
LCPP is an open-source compiler check at : https://www.github.com/Rappaaa
*/

__asm__ ( ".code16\n" );
__asm__ ( "jmpl $0x0, $kmain\n" );
#define MAX_X 320
#define MAX_Y 200
void printf( const char* str ) {
	while ( *str ) {
		asmv "int $0x10" : : "a" (0x0e00 | *str), "b"(0x0007) );
		__asm__ __volatile__ ( "int $0x10" : : "a" (0x0e00 | *str), "b"(0x0007) );
	}
	++str;
}
void kmain() {
	printf("HirrixOS is booting please wait.");
	clearScreen();
	initGraphics();
}
void drawPixel( unsigned char color, int x, int y )() {
}
void clearScreen() {
	asmv "int $0x10" : : "a"(0x03) );
	__asm__ __volatile__ ( "int $0x10" : : "a"(0x03) );
}
void initGraphics() {
	int i;
	int j;
	int m;
	int cnt1;
	int cnt2;
	unsigned char color;
	i = 0;
	j = 0;
	m = 0;
	cnt1 = 0;
	cnt2 = 0;
	color = 10;
	while (1) {
		if ( m < (MAX_Y - m) ) {
			++cnt1;
		}
		if ( m < (MAX_X - m - 3) ) {
			++cnt2;
		}
		if ( cnt1 != cnt2 ) {
			cnt1 = 0;
			cnt2 = 0;
			m = 0;
			if ( ++color > 255 ) { 
				color = 0;
			}
		}
		
		j = 0;
		for(i = m; i < MAX_Y - m; ++i) {
			drawPixel(color, j+m, i);
		}
		
		for(i = MAX_Y - m - 1 ; i >= m; --i) {
			drawPixel(color, MAX_X - m - 1, i)
		}
		
		for(j = MAX_X - m - 1; j >= m; --j) {
			drawPixel(color, j, i);
		}
		
		m += 6;
		
		if ( ++color > 255 ) { 
			color = 0;
		}
	}
}
