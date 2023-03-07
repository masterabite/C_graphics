#include "graphics.h"
#pragma comment(lib,"graphics.lib")

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
}

void draw_casper(int x, int y, int body_rad, colors color1, colors color2) {
	int cx = x + body_rad;
	int cy = y + body_rad;
	int eye_rad = body_rad / 8;
	int mouth_rad = body_rad / 18;

	setcolor(color1);
	setfillstyle(SOLID_FILL, color1);
	pieslice(cx, cy, 0, 0, body_rad);

	setcolor(color2);
	setfillstyle(SOLID_FILL, color2);
	setlinestyle(SOLID_LINE, 2, NORM_WIDTH);
	draw_triangle(cx - 24, cy - 22, cx - 24, cy - 32, cx - 16, cy - 28);
	draw_triangle(cx + 24, cy - 22, cx + 24, cy - 32, cx + 16, cy - 28);

	circle(cx, cy, body_rad);
	pieslice(cx - body_rad / 3, cy - body_rad / 2, 0, 0, eye_rad);
	pieslice(cx + body_rad / 3, cy - body_rad / 2, 0, 0, eye_rad);
	pieslice(cx, cy, 0, 0, mouth_rad);
}

void draw_row(int x, int y, int body_rad, colors color1, colors color2) {
	while(x < getwindowwidth()) {
		draw_casper(x, y, body_rad, color1, color2);
		x += body_rad * 2;
	}
}

void draw_pic() {
	int rad = 32;
	int x = 0;
	int y = -rad;

	const int clrs_len = 4;
	colors clrs[clrs_len] = {WHITE, CYAN, LIGHTBLUE, BLUE};
	int i = 0;

	while (y < getwindowheight()) {
		x = -rad * (i % 2);
		draw_row(x, y, rad, clrs[i], clrs[(i + 1) % clrs_len]);
		y += rad;
		i = (i + 1) % clrs_len;
	}
}

int main() {
	initwindow(820, 640);// èíèöèàëèçèðóåì ãðàôè÷åñêîå îêíî
	draw_pic();
	getch(); // æäåì íàæàòèÿ êíîïêè
	closegraph();  // âûõîä èç ãðàôè÷åñêîãî ðåæèìà
	return 0;
}
