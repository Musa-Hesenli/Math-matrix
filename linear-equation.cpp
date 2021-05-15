#include<iostream>
using namespace std;
int main() {
   int i,j,k,n; // declare variables and matrixes as
   float a[10][10],b,x[10];
   cout << "Enter the size of matrix: ";
   cin >> n;
   for(i=1; i<=n; i++) {
    //   cout << "Enter " << n << " elements for " << i << ".row, and result of this line:" << endl;
      for(j=1; j<=(n+1); j++) {
         cin >> a[i][j];
      }
   }
   //to find the elements of diagonal matrix
   for(j=1; j<=n; j++) {
      for(i=1; i<=n; i++) {
         if(i!=j) {
            b=a[i][j]/a[j][j];
            for(k=1; k<=n+1; k++) { 
               a[i][k]=a[i][k]-b*a[j][k];
            }
         }
      }
   }
   cout<<"The solution is:\n";
   char letters[] = {'x', 'y', 'z', 'n', 'm', 'a'};
   for(i=1; i<=n; i++) {
      x[i]=a[i][n+1]/a[i][i];
      cout<< letters[i - 1] << " = "<<x[i]<<" ";
   }
   //test1
   // 1 1 -1 6
   // 3 -2 1 -5
   // 1 3 -2 14

   //test2
   // 1 -2 1 0
   // 2 1 -3 5
   // 4 7 1 -1

   // test3 
   // 3 2 1 1
   // 5 3 4 2
   // 1 1 -1 1
   return(0);
}