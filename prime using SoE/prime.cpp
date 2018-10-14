#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing
const int initial_prime_number = 2; //set initial prime number to 2


int compute_primes(int MAX_NUMBER, bool input_array[]);
void print_primes(int MAX_NUMBER, bool input_array[]);

/***** Complete this program. *****/

/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{

	bool input_array[MAX_NUMBER]; //input_array is an array of boolean values of size MAX_NUMBER upto which the prime numbers are printed

	for(int i=initial_prime_number; i<MAX_NUMBER; i++)
	{
		input_array[i] = 1; //As per Sieve of Eratosthenes algorithm set all the values in array to true
	}

	compute_primes(MAX_NUMBER, input_array); //call the function compute_primes which computes the prime numbers upto MAX_NUMBER
	print_primes(MAX_NUMBER, input_array); //print the values calculated by compute_primes

}

int compute_primes(int MAX_NUMBER, bool input_array[])
{
	int j = initial_prime_number;

	while(j < sqrt(MAX_NUMBER)) //As per Sieve of Eratosthenes algorithm j should not exceed square root of MAX_NUMBER
	{
		if(input_array[j] == 1)
		{
			for(int k = j*j; k< MAX_NUMBER; k = k+j)
			{
				input_array[k] = 0; //eliminating multiples of numbers by marking them as false and hence remaining indexes are prime
			}
		}
		j++;
	}
	return 0;
}

void print_primes(int MAX_NUMBER, bool input_array[])
{
	int counter = 0; //initialise a counter which is used for printing specific number of elements on each row
	for(int i = initial_prime_number; i< MAX_NUMBER; i++)
	{

		while(input_array[i])  //only indexes which are 'true' are printed out and these are prime numbers
		{

			cout << i<<"\t";

			counter++;
			if(counter%ROW_SIZE == 0) //sets specific number of elements in each row
			{
				cout << endl;
			}
			break;
		}
	}

	cout << "\n \n Done!";

}

