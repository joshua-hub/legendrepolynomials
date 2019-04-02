//phys3071 melsom 42593249 assignment 3

/*
Inputs: 

Calculations:

Outputs:

compiled as gcc as03-melsom-42593249-2.c -o as03-2 -lm
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to solve the Legendre polynomials recursively.
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
  //variables:  n is for the maximum polynomial to calculate, i and j are used
  //for matrix dimension counting. x is array elements for calculations, 
  //divisor is used for setting values within x, fname is the filename used for
  //output. P is also created after the user inputs n is it's dimensions are
  //dependant on n.
  int n,i,j;
  double x[101], divisor = -1.0;
  char fname[128];
  FILE *fp;
  
  printf("\nThis program will solve the first n Legendre polynomials between "
          "-1 and 1 and store \nthe values in a *.dat file before plotting all"
          " curves on the one plot.\n");
  printf("Please enter a positive integer n: ");
  scanf("%d", &n);
  
  //can create a 2-dimensional array after n is known.
  double P[101][n];

  //populating the x array with 101 evenly spaced numbers from -1 to 1.  
  for (i=0;i<101;i++) {
    x[i] = divisor;
    divisor = divisor + 0.02; 
  }
  
  printf("A data file  will be created in the current directory. Please type"
         " the file name.\n");
  scanf("%s",fname); 
  fp = fopen("fname.dat", "w");
  
  //fills the P array by calling the function Pn and parsing elements of 
  //x and values of n from 1 to n.
  for(i = 0; i < n; i++) {
    for(j = 0; j < 101; j++) {
        P[j][i] = Pn(x[j], i);
        fprintf(fp,"%lf, ",P[j][i]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
}
