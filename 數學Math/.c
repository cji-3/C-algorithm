#include<stdlib.h>
#include<math.h>

//solveQE之回傳值
typedef struct{
	double x1;	/**< 根1 */
	double x2;	/**< 根2 */
	int solveQuantity;	/**< 解的數量 */
}QE_return;

/**
 * \brief 一元二次方程式(QE)
 * \param a x^2項
 * \param b x^1項
 * \param c 常數項
 * \return 專用的QE_return結構
 */
QE_return* solveQE(double a, double b, double c) {
	QE_return* out=(QE_return*)malloc(sizeof(QE_return));

	if (a == 0) {
		out->x1=-(c/b);
		out->x2=out->x1;
		out->solveQuantity=1;
		return out;
	}

	double discriminant = b * b - 4 * a * c;
	if (discriminant > 0) {
		out->x1 = (-b + sqrt(discriminant)) / (2 * a);
		out->x2 = (-b - sqrt(discriminant)) / (2 * a);
		out->solveQuantity=2;
	} else if (discriminant == 0) {
		out->x1 = -b / (2 * a);
		out->x2=out->x1;
		out->solveQuantity=1;
	} else {
		out->solveQuantity=0;
	}
	return out;
}
/**
 * \brief 費氏數列(Fibonacci sequence)
 * \param n 要計算的費氏數列項數
 * \return 第n項的費氏數列值
 */
// 迭代版本
long long fib_iter(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// 遞迴版本
long long fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}