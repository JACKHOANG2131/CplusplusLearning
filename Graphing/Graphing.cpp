#define _WIN32_WINNT 0x601
#include <windows.h>
#include <stdio.h>
#include <math.h>
double rad(double x1)
{
    double pi = 3.14159265359;
    return(x1 * (pi / 180));
}
double ctan(double x1)
{
    return(sin(x1) / cos(x1));
}
void DrawSinGraph()
{
    for (int i = -360; i < 360; i++)
    {
        double x1 = i - 1;
        double y1 = sin(rad(x1));
        LineTo(0, x1, y1);
    }
}
int main() {
    // Get window handle to console, and device context
    HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //Here's a 5 pixels wide RED line [from initial 0,0] to 300,300
    HPEN pen0 = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    SelectObject(device_context, pen0);
    for (int i = -360; i < 360; i++)
    {
        double x1 = i;
        double y1 = sin(rad(x1));
        LineTo(device_context, x1, y1 * 100);
    }
    HPEN pen1 = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
    SelectObject(device_context, pen1);
    for (int i = -360; i < 360; i++)
    {
        double x1 = i;
        double y1 = cos(rad(x1));
        LineTo(device_context, x1, y1 * 100);
    }
    HPEN pen2 = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
    SelectObject(device_context, pen2);
    for (int i = -360; i < 360; i++)
    {
        if (i != -270 and i != -90 and i != 90 and i != 270);
        {
            double x1 = i;
            double y1 = tan(rad(x1));
            LineTo(device_context, x1, y1 * 100);
        }
        else;
        {
            double x1 = i + 1;
            double y1 = tan(rad(x1));
            LineTo(device_context, x1, y1 * 100);
        }
    }
    HPEN pen3 = CreatePen(PS_SOLID, 1, RGB(0, 128, 0));
    SelectObject(device_context, pen3);
    for (int i = -360; i < 360; i++)
    {
        double x1 = i;
        double y1 = ctan(rad(x1));
        LineTo(device_context, x1, y1 * 100);
    }
    ReleaseDC(console_handle, device_context);

    getchar();

    return 0;
}