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
		out->solveQuantity=0;
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