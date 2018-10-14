#include<iostream>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number


/***** Complete this program. *****/

void do_spiral(const int n, const int start);
void make_spiral( int matrix_size, int start);
void print_spiral( int matrix_size) ; //function to print values in spiral
void print_error(int matrix_size); //function to print error if size is even
void display_message(int matrix_size, int start_from); //function to print message for easy understanding
int matrix[MAX_SIZE][MAX_SIZE] = {0}; //initialising a 2 dimensional matrix for storing values which is then printed in spiral form
/**
 * The main: Generate and print spirals of various sizes.
 */

int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);

}

//@param n is the size of matrix which is number of elements in each row
//@param start is the number from where the spiral has to start
void do_spiral(const int n, const int start)
{

    while( n<MAX_SIZE && start<MAX_START )                         //MAX_SIZE and MAX_START value check
    {
        display_message(n,start);

        if(n%2 == 0)  //check if n is odd

        {
            print_error(n); //print error if n is even

        }
        else
        {
            cout<<endl;
            make_spiral(n,start); //if n is odd, call make spiral function

        }
        cout<<"\n";
        break;
    }

}



void display_message(int matrix_size,int start) //function  for display message
{
    cout<<"Spiral of size "<<matrix_size<<" "<<"starting at"<<" "<<start<<"\n";
}



void print_error(int matrix_size) //function for printing error
{
    cout<<"***** Error: Size"<<" "<< matrix_size<<" "<<"must be odd."<<"\n";
}



void make_spiral(int matrix_size, int start) //function that creates the spiral
{

    int last_cell=(matrix_size*matrix_size)+(start-1); //final value of integer when spiral stops
    int left=0, right= matrix_size-1, top=0, bottom= matrix_size-1; //initislising variables for spiral formation
    int p=0,q=0,r=0,s=0;

    while( last_cell >= start) //the last value should be more than start value from where the spiral begins
    {

        p = bottom; //initialising pqrs to different indexes in the 2 dimensional array for creating spiral
        q = right-1;
        r = top+1;
        s = left+1;

//loops to form a spiral which is then printed using print_spiral function

        while(p >=top)

        {

            matrix[right][p]= last_cell;
            last_cell = last_cell-1;
		    p--;
        }

        while(q>=left)

        {

            matrix[q][top]= last_cell;
            last_cell = last_cell-1;
		    q--;

        }

        while(r<=bottom)

        {

            matrix[left][r]= last_cell;
            last_cell = last_cell-1;
		    r++;

        }

        while(s <= right-1)

        {

            matrix[s][bottom]= last_cell;
            last_cell = last_cell-1;
		    s++;

        }
//creation of spiral ends here
//2 dimensional array is filled with values to be printed

        top++;
        bottom--;
        left++;
        right--;


    }
    print_spiral(matrix_size); //call the function print spiral to display the spiral to the user
}

void print_spiral( int matrix_size)       //function for spiral print
{

    int x = matrix_size-1; //initialising variable x for comparision in while loop
    for(int index_row=0; index_row<matrix_size; index_row++)
    {
        int index_col = 0;
        while( index_col< matrix_size)
        {
            cout << matrix[index_row][index_col]; //printing the numbers in the corresponding index which forms a spiral
            cout << "\t";
            if (index_col == x)
            {
                cout<< endl; //new line when index reaches maximum value
            }
            index_col++;
        }
    }
}
