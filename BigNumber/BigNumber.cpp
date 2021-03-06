#include "stdafx.h"  
#include <stdlib.h>
#include <climits>
#include "Bignumber.h"  

BIGNUMBER_API BigNumber::BigNumber()
{
	lng = 0, V[0] = 0;
}

BIGNUMBER_API BigNumber::BigNumber(int x)
{
	lng = 0;
	if (x == 0)
		lng = 1, V[0] = 0;
	else
		while (x)
			V[lng++] = x % 10, x /= 10;
}

BIGNUMBER_API BigNumber::BigNumber(int * V, int sz)
{
	for (int i = 0; i < sz; i++)
		this->V[i] = V[i];
	lng = sz;
}

BIGNUMBER_API int BigNumber::size()
{
	return lng;
}

BIGNUMBER_API int BigNumber::get(int x)
{
	if (0<=x && x<=lng-1)
		return V[x];
	return 0;
}

BIGNUMBER_API void BigNumber::append(int x)
{
	lng++;
	V[lng-1] = x;
}

BIGNUMBER_API bool BigNumber::isInt()
{
	BigNumber m = INT_MIN;
	BigNumber M = INT_MAX;
	if (m <= *this && *this <= M)
		return true;
	return false;
}

BigNumber::operator int() const
{
	int ans = 0;
	for (int i = lng-1; i >= 0; i--)
		ans *= 10, ans += V[i];
	return ans;
}

BIGNUMBER_API BigNumber operator+(BigNumber a, BigNumber b)
{
	int sz = max(a.size(), b.size());
	BigNumber C;
	int t = 0;
	for (int i = 0; i < sz; i++)
	{
		int x = a.get(i) + b.get(i) + t;
		C.append(x%10);
		t = x / 10;
	}
	if (t)
		C.append(1);
	return C;
}

BIGNUMBER_API BigNumber operator+(BigNumber A, int b)
{
	BigNumber B = b;
	return A + B;
}

BIGNUMBER_API BigNumber operator+(int a, BigNumber B)
{
	return B + a;
}
