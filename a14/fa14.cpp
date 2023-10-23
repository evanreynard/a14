#include<math.h>

double dLm(double dR1, double dR2, double dC)
{
	return -(dR1 + dR2) / (dR1 * dR2 * dC);

}

double Storm0(double dR1, double dR2, double dU)
{
	return dU / (dR1 + dR2);
}

double dK(double dR1, double dR2, double dU)
{
	return(dU * dR2) / (dR1 * (dR1 + dR2));
}