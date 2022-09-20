#include <stdio.h>
#include <math.h>
double f1(double x, double y)
{
    return pow(x, 2) + pow(y, 2) - 5;
}

double f2(double x, double y)
{
    return pow(x, 2) + x*pow(y, 3) - 3;
}

double f1x(double x, double y)
{
    return 2 * x;
}

double f1y(double x, double y)
{
    return 2 * y;
}

double f2x(double x, double y)
{
    return 2 * x + pow(y,3);
}

double f2y(double x, double y)
{
    return 3 * pow(y,2)*x;
}
int main()
{
    // exemplo

    int n = 19;
    double x0 = -1.8694;
    double y0 = 0.8562;
    int iterations[] = {1, 2, 3, 4, 5};
    FILE *fp = fopen("out.txt","w+");
    int i2 = 0;
    // newton
    for (int i = 0; i < n; i++)
    {
        // jacobiano
        //[f1x f1y]
        //[f2x f2y]
        // inversa, antes de 1 / det
        // [f2y -f1y] [f1]
        // [-f2x f1x] [f2]
        double a = f1x(x0, y0);
        double b = f1y(x0, y0);
        double c = f2x(x0, y0);
        double d = f2y(x0, y0);
        double det = a * d - b * c;
        double xk = x0 - (f2y(x0, y0) * f1(x0, y0) - f1y(x0, y0) * f2(x0, y0)) / det;
        double yk = y0 - (-f2x(x0, y0) * f1(x0, y0) + f1x(x0, y0) * f2(x0, y0)) / det;
        x0 = xk;
        y0 = yk;
        if(i+1 == iterations[i2])
        {
            fprintf(fp,"%.12f, %.12f,",x0,y0);
            i2 += 1;

        }
        printf("x^(%d) = %.12f\ty^(%d) = %.12f\n", i + 1, x0, i + 1, y0);
    }
}
