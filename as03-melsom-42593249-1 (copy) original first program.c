//phys3071 melsom 42593249 assignment 3

/*
Inputs: The program asks the user for x, and n. x can be any real number and n
can be any positive integer. My program does not check the validity of the 
numbers and will complete calculations even if the correct types aren't 
entered. It is up to the user to follow the instructions.

Calculations: The program solves for the nth order Legendre polynomial solved
at x. The program solves the polynomials using a recursive function. This 
minimises memory and storage requirements.

Outputs: The program outputs the answer in scientific notation, as the 
poynomials can produce very large numbers outside the range of x =  (1,1).

compiled as gcc as03-melsom-42593249-1.c -o as03-1 -lm
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to solve the polynomials recursively.
double Pn(double x,int n) {
  double P;
  
  if (n==0) {
    P=1.0;
    }
  else if (n==1) {
    P=x; 
    }
  else {
    P=((2.0*n-1.0)*x*Pn(x, n-1)-(n-1.0)*Pn(x, n-2))/(1.0*n);
  }
  return P;  
}

int main () {
  int n,i;
  double x, P;
  
  printf("This program will calculate the Legendre polynomial P_n(x) evaluated \n"
          "at x. Please follow the instructions carefully.");
  printf("please enter any real number x and a positive integer n\n"
         "(in the form x, n)\n");
  scanf("%lf%*[ ,;\t:]%i",&x, &n);

  P = Pn(x,n);
  printf("P_n = %10.5le\n",P);
  printf("\n");
}
