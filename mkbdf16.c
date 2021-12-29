/*
* ROM to BDF fontfile (KANJI) / Original Source File
* 1998.10	Tetsuo.Mitsuda
* 2021.12	leiqunni@gmail.com
*
* Compile:
*	gcc -liocs -o mkbdf16.x mkbdf16.c
*
* Usage:
*	mkbdf16.x > fontrom_x68k.bdf
*/

#include <stdio.h>
#include <iocslib.h>
#include <unistd.h>

void get_font16_h(int, unsigned char*);
void scan_code_h(int startcode, int endcode);
void code_inc_h(int*);
void get_font16_z(int, unsigned char*);
void scan_code_z(int startcode, int endcode);
void code_inc_z(int*);
void print_header(void);
void hankaku(void);
void zenkaku(void);

void main(int argc, char *argv[]) {
	int opt;

	while ((opt = getopt(argc, argv, "c")) != -1) {
		switch (opt) {
		case 'c':
			hankaku();
			zenkaku();
			exit();
			break;
		}
	}

	print_header();
	hankaku();
	zenkaku();
	printf("ENDFONT\n");
}

/* Hankaku Ascii */

void hankaku() {
	scan_code_h(0x20, 0x7F);
	scan_code_h(0xA0, 0xDF);
}

void scan_code_h(int startcode, int endcode) {
	int i, code;
	char raster[16 + 1];
	
	for (code = startcode; code <= endcode; code++) {
		get_font16_h(code, raster);

		printf("STARTCHAR %x\n", code);
		printf("ENCODING %5d\n", code);
		printf("SWIDTH 512 0\n");
		printf("DWIDTH 8 0\n");
		printf("BBX 8 16 0 -2\n");
		printf("BITMAP\n");

		for (i = 0; i < 16; i++) {
			printf("%02x\n", (raster[i] & 0xff));
		}

		printf("ENDCHAR\n");
	}
}

/* get font data from X68k ROM */

void get_font16_h(int char_code, unsigned char* raster) {
	char char_buf[16 + 2];
	char temp_buf[16 + 4];
	int i;

	FNTGET(8, char_code, temp_buf);

	for (i = 0; i < 16; i++) {
		*raster++ = temp_buf[i + 4];
	}
}

/* Zenkaku Kanji */

void zenkaku() {
	scan_code_z(0x2121, 0x222e);
	scan_code_z(0x223a, 0x2241);
	scan_code_z(0x224a, 0x2250);
	scan_code_z(0x225c, 0x226a);
	scan_code_z(0x2272, 0x2279);
	scan_code_z(0x227e, 0x227e);
	scan_code_z(0x2330, 0x2339);
	scan_code_z(0x2341, 0x235a);
	scan_code_z(0x2361, 0x237a);
	scan_code_z(0x2421, 0x2473);
	scan_code_z(0x2521, 0x2576);
	scan_code_z(0x2621, 0x2638);
	scan_code_z(0x2641, 0x2658);
	scan_code_z(0x2721, 0x2741);
	scan_code_z(0x2751, 0x2771);
	scan_code_z(0x2821, 0x2840);
	scan_code_z(0x3021, 0x4f53);
	scan_code_z(0x5021, 0x737e);
	scan_code_z(0x7421, 0x7424);
}

void scan_code_z(int startcode, int endcode) {
	int i, code, c;
	char raster[32 + 1];

	for (code = startcode; code <= endcode; code_inc_z(&code)) {
		get_font16_z(code, raster);

		printf("STARTCHAR %x\n", code);
		printf("ENCODING %5d\n", code);
		printf("SWIDTH 1024 0\n");
		printf("DWIDTH 16 0\n");
		printf("BBX 16 16 0 -2\n");
		printf("BITMAP\n");

		for (i = 0; i < 32; i += 2) {
			c = ((raster[i] & 0xff) << 8) + (raster[i + 1] & 0xff);
			printf("%04x\n", c);
		}

		printf("ENDCHAR\n");
	}
}

void get_font16_z(int char_code, unsigned char* raster) {
	char temp_buf[32 + 4];
	int i;

	FNTGET(8, char_code, temp_buf);

	for (i = 0; i < 32; i++) {
		*raster++ = temp_buf[i + 4];
	}
}

void code_inc_z(int* i) {
	if ((*i & 0xff) == 0x7e) {
		*i = (*i & 0xff00) + 0x121;
	} else {
		(*i)++;
	}
}

void print_header() {
	printf("STARTFONT 2.1\n");
	printf("COMMENT from SHARP X680x0 ROMFONT\n");
	printf("FONT -PEKE-Fixed-Medium-R-Normal--16-150-75-75-C-160-JISX0208.1983-0\n");
	printf("SIZE 16 75 75\n");
	printf("FONTBOUNDINGBOX 16 16 0 -2\n");
	printf("STARTPROPERTIES 19\n");
	printf("FONT_ASCENT 14\n");
	printf("FONT_DESCENT 2\n");
	printf("DEFAULT_CHAR 8481\n");
	printf("COPYRIGHT \"from SHARP X680x0 ROMFONT\"\n");
	printf("FONTNAME_REGISTRY \"\"\n");
	printf("FOUNDRY \"PEKE\"\n");
	printf("FAMILY_NAME \"Fixed\"\n");
	printf("WEIGHT_NAME \"Medium\"\n");
	printf("SLANT \"R\"\n");
	printf("SETWIDTH_NAME \"Normal\"\n");
	printf("ADD_STYLE_NAME \"\"\n");
	printf("PIXEL_SIZE 16\n");
	printf("POINT_SIZE 150\n");
	printf("RESOLUTION_X 75\n");
	printf("RESOLUTION_Y 75\n");
	printf("SPACING \"C\"\n");
	printf("AVERAGE_WIDTH 160\n");
	printf("CHARSET_REGISTRY \"JISX0208.1983\"\n");
	printf("CHARSET_ENCODING \"0\"\n");
	printf("ENDPROPERTIES\n");
	printf("CHARS 7037\n");
}
