
#include <iostream>
#include <graphics.h> 
using namespace std;

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float x1, y1, x2, y2;
    float xmin, ymin, xmax, ymax;

    cout << "Enter coordinates of the line segment (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Enter the clipping window coordinates (xmin, ymin, xmax, ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;


    rectangle(xmin, ymin, xmax, ymax);

    float t0 = 0.0, t1 = 1.0;
    float dx = x2 - x1;
    float dy = y2 - y1;

    float p[] = {-dx, dx, -dy, dy};
    float q[] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    bool isInside = true;
    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) {
            isInside = false;
            break;
        }

        float t = q[i] / p[i];
        if (p[i] < 0) {
            if (t > t1) {
                isInside = false;
                break;
            }
            if (t > t0) t0 = t;
        } else if (p[i] > 0) {
            if (t < t0) {
                isInside = false;
                break;
            }
            if (t < t1) t1 = t;
        }
    }

    if (isInside) {
        float nx1 = x1 + t0 * dx;
        float ny1 = y1 + t0 * dy;
        float nx2 = x1 + t1 * dx;
        float ny2 = y1 + t1 * dy;

    
        line(nx1, ny1, nx2, ny2);
        cout << "Clipped line coordinates: (" << nx1 << ", " << ny1 << ") to (" << nx2 << ", " << ny2 << ")\n";
        cout << "Line clipped successfully.\n";
    } else {
        cout << "Line is outside the clipping window.\n";
    }

getch();
closegraph();

return 0;
}
