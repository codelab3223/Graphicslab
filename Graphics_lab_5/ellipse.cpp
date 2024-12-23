#include <iostream>
#include <graphics.h>
using namespace std;

int main() {
    int a, b, r, x, y, p1, p2, m, n;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    cout << "Enter center of ellipse: ";
    cin >> m >> n;
    cout << "Enter x-radius and y-radius: ";
    cin >> a >> b;
    setbkcolor(15);
    cleardevice();
    setcolor(0);
    p1 = b * b - a * a * b + (a * a) / 4;
    x = 0;
    y = b;
    putpixel(x + m, y + n, 1);
    do {
        if (p1 < 0) {
            x++;
            p1 = p1 + 2 * b * b * x + b * b;
        } else {
            x++;
            y--;
            p1 = p1 + 2 * b * b * x - 2 * a * a * y + b * b;
        }
        putpixel(x + m, y + n, 0);
        putpixel(-x + m, y + n, 0);
        putpixel(x + m, -y + n, 0);
        putpixel(-x + m, -y + n, 0);
//        putpixel(y + m, x + n, 0);
//        putpixel(-y + m, x + n, 0);
//        putpixel(y + m, -x + n, 0);
//        putpixel(-y + m, -x + n, 0);
    } while (2 * b * b * x < 2 * a * a * y);

    p2 = b * b * (x + 1) * (x + 1) + a * a * (y - 1) * (y - 1) - a * a * b * b;
    do {
        if (p2 <= 0) {
            x++;
            y--;
            p2 = p2 + 2 * b * b * x - 2 * a * a * y + a * a;
        } else {
            y--;
            p2 = p2 - 2 * a * a * y + a * a;
        }
        putpixel(x + m, y + n, 0);
        putpixel(-x + m, y + n, 0);
        putpixel(x + m, -y + n, 0);
        putpixel(-x + m, -y + n, 0);
//        putpixel(y + m, x + n, 0);
//        putpixel(-y + m, x + n, 0);
//        putpixel(y + m, -x + n, 0);
//        putpixel(-y + m, -x + n, 0);
    } while (y > 0);
    getch();
    closegraph();
    return 0;
}

