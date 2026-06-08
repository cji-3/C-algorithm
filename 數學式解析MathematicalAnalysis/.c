/*一元二次方程式*/
int solveQuadraticEquation(double a, double b, double c) {
    if (a == 0) {
        solveLinearEquation(b, c);
        return 0;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("兩個實根: %.2f, %.2f\n", x1, x2);
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        printf("一個重根: %.2f\n", x);
    } else {
        printf("無實根\n");
    }
    return 0;
}
