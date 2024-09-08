#include <stdio.h>

double scaleBetween(double unscaledNum, double minAllowed, double maxAllowed, double min, double max) 
{
	return (maxAllowed - minAllowed) * (unscaledNum - min) / (max - min) + minAllowed;
}

int	main()
{
	for(int i = 0; i < 10; i++)
		printf("%d -> %f\n", i, scaleBetween((double)i, 0, 20, 0, 10));
}
