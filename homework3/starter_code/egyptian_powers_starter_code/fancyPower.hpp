#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

int fancyPower(int n, int m)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return m;
	else if (n == 2)
		return m * m;
	else if (n % 2 == 0)
		return fancyPower(n / 2, fancyPower(2, m));
	else
		return m * fancyPower((n - 1) / 2, fancyPower(2, m));
}

#endif
