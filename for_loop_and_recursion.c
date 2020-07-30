#include <stdio.h>

int factorial(int n)
{
	int sum = 1;

	while (n != 0)
	{
		sum *= n;
		n--;
	}

	return sum;
}

int factorial2(int n)
{
	// Demonstrating recursion.

	if (n == 0) return 1;
	return n * factorial2(n - 1);
}

int fib[100] = { 0,1,1 };

int fibo(int n)
{
	// Demonstrating recursion.

	// if (n == 1 || n == 2) return 1;
	if (fib[n] != 0) return fib[n];
	fib[n] = fibo(n - 1) + fibo(n - 2);
	return fib[n];
}

int fibo2(int n)
{
	int a = 1;
	int b = 1;
	int c;
	int sum = 0;

	for (int i = 0; i < n - 2; i++)
	{
		c = a + b;
		sum = sum + c;
		a = b;
		b = c;
	}

	return c;
}

int main()
{	
	int num, fact, fact2;

	printf("Enter a number: ");
	scanf("%d: ", &num);

	fact = factorial(num);
	fact2 = factorial2(num);

	printf("\n%d! = %d\n", num, fact);
	printf("%d! = %d\n", num, fact2);
	printf("\n10th Fibonacci Number: %d\n", fibo(10));
	

	return 0;
}
