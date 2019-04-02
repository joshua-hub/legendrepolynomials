//phys3071 melsom 42593249 assignment 3

/*
Inputs: The program asks the user for a positive integer n. My program does not
check the validity of the numbers and will complete calculations even if the 
correct types aren't entered. It is up to the user to follow the instructions.

Calculations: The program solves for the nth order Legendre polynomial solved
for x = -1 to 1 in 101 steps (100 divisions). The program solves the 
polynomials using a recursive function. This minimises memory and storage 
requirements.

Outputs: The program outputs the solutions to a file, where the user is asked
to specify the filename. The structure of the data is a column of x values and
a column of P(x) values, separated by a tab and each line is separated with a
line break.

compiled as gcc as03-melsom-42593249-1.c -o as03-1 -lm
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to solve the Legendre polynomials recursively.
//x and n are the same variables as is passed to the function and P is the 
//internal variable that is returned.
double Pn(double x,int n,int l) {
  double P;
  if (l==0) {
    if (n==0) {
      P=1.0;
    }
    else if (n==1) {
      P=x; 
    }
    else {
      P=((2.0*n-1.0)*x*Pn(x, n-1,l) - (n-1.0)*Pn(x, n-2,l)) / (1.0*n);
    }
  }
  else {
    P = ((n-l)*Pn(x,n,l-1) - (n+l)*Pn(x,n-1,l-1)) / sqrt(1-pow(x,2.0));
  }
  return P;
}

int main () {
  //n and l are ineger values for calculating the degree of polynomial. Both 
  //are entered by the user. Both will accept any value and it is up to the 
  //user to follow instructions and warnings. P is the stored solution and x is
  //a user provided number on where to evaluate the polynomial.
  int n,l; 
  double x, P;
    
  //Asking the user for n, j, x. The warning about valid values are explicit.
  printf("\nThis program will solve the nth jth polynomial at a given x. All "
         "values are etered by the user. Warning: It is up to the user to "
         "enter a valid valude.\n");
  printf("Please enter a positive integer n: ");
  scanf("%i", &n);
  printf("Please enter a positive integer less than n: ");
  scanf("%i", &l);
  printf("Please enter a real number x between -1 and 1: ");
  scanf("%lf", &x);
  
  //fills the P array by calling the function Pn and parsing elements of x 
  //and the value of n.
  P = Pn(x,n,l);
  printf("Pn = %lf\n", P);
}
