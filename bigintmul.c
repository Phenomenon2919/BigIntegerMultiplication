#include<stdio.h>
#include<time.h>
#include<math.h>
/**
Function to return the number of digits in the largest integer passed as arguement

*/
int findL(long int x)
{
	int i=1;
	while(x/(long int)pow(10,i)!=0)
	{
		i++;
	}

	return i;
}

//Function defnition
long int Mul(long int a, long int b)
{
	
	int n;
	//Condition to find the largest integer of the two
	if(a>b)
		n=findL(a); 
	else
		n=findL(b);
	
	//fflush(NULL);
	if(n==1)
		return a*b;
	else
	{
		long int aR = a%(long int)pow(10,n/2);					//Storing the Least Significant Half of the first number
		long int aL = a/(long int)pow(10,n/2);					//Storing the Most Significant Half of the first number
		long int bR = b%(long int)pow(10,n/2);					//Storing the Least Significant Half of the second number
		long int bL = b/(long int)pow(10,n/2);					//Storing the Most Significant Half of the second number
		
		long int x1 = Mul(aL, bL);								//Calling the Big Int Multiplication on the Most significant Half of both the numbers
		long int x2 = Mul(aR, bR);								//Calling the Big Int Multiplication on the Least significant Half of both the numbers
		long int x3 = Mul((aL+aR),(bL+bR));						//Calling the Big Int Multiplication in cross of both the numbers 
		

		//Checking whether number of digits of Bigger Integer is odd or even
		if(n%2==0)
			return (x1*(long int)pow(10,n)+(x3-x1-x2)*(long int)pow(10,n/2)+x2);  // returning the answer as x1*10^n + (x3-x1-x2)*10^(n/2) + x2
		else
			return (x1*(long int)pow(10,n-1)+(x3-x1-x2)*(long int)pow(10,n/2)+x2); 	// returning the answer as x1*10^(n-1) + (x3-x1-x2)*10^(n/2) + x2
	}
}

int main()
{	/**
	Taking Input
	*/
	long int a,b,c;
	printf("\nEnter a: ");
	scanf("%ld",&a);
	printf("\nEnter b: ");
	scanf("%ld",&b);
	
	/**
	Start timing
	*/
	clock_t tStart = clock();
	c = Mul(a,b);		//Call function
	printf("Product = %ld",c);
	printf("\nTime taken: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC); //Stop Timer
	
}

