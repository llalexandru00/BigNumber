#pragma once  

#ifdef BIGNUMBER_EXPORTS  
#define BIGNUMBER_API __declspec(dllexport)   
#else  
#define BIGNUMBER_API __declspec(dllimport)   
#endif  

class BigNumber
{
	int V[200], lng;
		BIGNUMBER_API void clear(int l, int r);
	public:
		BIGNUMBER_API BigNumber();
		BIGNUMBER_API BigNumber(int x);
		BIGNUMBER_API BigNumber(int* V, int x);

		BIGNUMBER_API int size();
		BIGNUMBER_API int get(int x);


		BIGNUMBER_API void append(int x);

		friend BIGNUMBER_API BigNumber operator+ (BigNumber A, BigNumber B);
		friend BIGNUMBER_API BigNumber operator+ (BigNumber A, int b);
		friend BIGNUMBER_API BigNumber operator+ (int a, BigNumber B);

		BIGNUMBER_API bool isInt();
		BIGNUMBER_API operator int() const;
};