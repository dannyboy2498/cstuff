#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPtrBasics()
{
	double x; // declare a variable x of type ’double’
	double *p_x; // declare a variable p_x of type ’pointer to a double’
	p_x = &x; // in variable ’p_x’, store the memory address where the
	// content of ’x’ is kept
	*p_x = 10.; // at the location in memory that we stored in p_x
	// write 10.0.
	printf("x = %e\n", x); //*p_x = x = 10.0

	printf("p_x, the pointer to x, is %p\n", p_x);
	printf("address of x in memory = %p\n", &x);
	printf("address of p_x in memory = %p\n", &p_x);
}

void printVarSizes()
{
	printf("size of integer is %zu\n", sizeof(int));
	printf("size of char is %zu\n", sizeof(char));
	printf("size of double is %zu\n", sizeof(double));
	printf("size of float is %zu\n", sizeof(float));
	printf("size of long is %zu\n", sizeof(long));
	
	int var1;
	char var2;
	printf("size of the pointer to an int %zu\n", sizeof(&var1));
	printf("size of the pointer to an char %zu\n", sizeof(&var2)); // notice how they are the same

}

void printPtrArithmetic()
{
	char *p_x;
	int *p_y;
	char my_array[9] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
	p_x = my_array;
	p_y = my_array;
	printf("first location in memory, according to p_x: %p\n", p_x);
	printf("first location in memory, according to p_y: %p\n", p_y);

	printf("Before overwriting:\n");

	int i;
	for (i = 0; i < 9; i++)
	{
		printf("at memory location %p is stored: %hd\n", &my_array[i], my_array[i]);
	}
	printf("\n");
	p_y++;
	*p_y = 0;

	printf("After writing data:\n");
	for (i = 0; i < 9; i++)
	{
		printf("at memory location %p is stored: %hd\n", &my_array[i], my_array[i]);
	}
	printf("\n");
}

void printPtrStrings()
{
	char my_string[] = "Hello this is a string.";
	int i = 0;
	printf("my_string points at %p\n", my_string);
	do
	{
		printf("at address %p, character %c, stored as %hd\n", &my_string[i], my_string[i], my_string[i]);
		i++;
	}
	while (my_string[i] != '\0');
}

void printMemoryAlloc()
{
	char *str; //pointer to string to store undefined string length

	/* Initial memory allocation */
	str = (char *) malloc(15);
	if (str != NULL)
	{
	strcpy(str, "I am a pretty ");
   	printf("String = %s,  Address = %p \n", str, &str);
	} else {
		printf("Not enough memory to allocate");
	}

	/* Reallocating memory */
	str = (char *) realloc(str, 23);
	if (str != NULL)
	{
		strcat(str, "princess");
		printf("String = %s,  Address = %p \n", str, &str);
	} else {
		printf("Not enough memory to allocate");
	}
	free(str);
}

typedef struct 
{
	double x;
	double y;
		
} Particle;

void printPtrsinFunctions()
{
	void moveParticle(Particle *ptr_p, double x, double y)
	{
		(*ptr_p).x = x;
		(*ptr_p).y = y;
	}

	Particle p1;
	p1.x = 0.;
	p1.y = 0.;
	printf("Pointer = %p, x = %f, y = %f \n", &p1, p1.x, p1.y);
	moveParticle(&p1, 10.,10.);
	printf("Pointer = %p, x = %f, y = %f \n", &p1, p1.x, p1.y);
}

void printFuntionPtrs()
{

	double G(double x, double y)
	{
		//test function - note that it defined in printFunctionPtrs but it is not nested it defined here for organisation
		return x*x - y;
	}

	void explore(double (*p_func)(double)(double), double x0, double x1)
	{
		// This function prints 101 values of the function pointed at
		// by p_func. The values lie evenly spaced within the range
		// x0 ... x1, boundaries inclusive
		int i;
		double x;
		for (i = 0; i <= 100; i++)
		{
			// set x to current position within the interval
			x = x0 + i * (x1 - x0) / 100;
			printf("%e, %e\n", x, (*p_func)(x,5.));
		}
	}

	double (*p_G)(double)(double); 
	p_G = &G; // set pointer to address of function specification
	explore(p_G, 0., 10.);
}

int main()
{
	//printPtrBasics(); //Pick a function any function
	//printVarSizes();
	//printPtrArithmetic();
	//printPtrStrings();
	//printMemoryAlloc();
	//printPtrsinFunctions();
	printFuntionPtrs();

	return 0;
}
