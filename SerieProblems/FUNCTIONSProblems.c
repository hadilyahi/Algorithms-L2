// FUNCTIONS 
#include<stdio.h>
// problem 1 : Write a function to find the GCD of two numbers 
// int GCD(int a , int b){
//     printf("a = %d b = %d\n",a,b);
//     if(b==0){
//         return a;
//     }
//     return GCD(b,a%b);
// }
// problem 2 : Write a function to calculate the power of a number.
//  int power(int a , int b){
//         int p=1;
//         for(int i=0;i<b;i++){
//             p=p*a;
//         }
//         return p;
//  }
// problem 3 : . Write a recursive function to calculate the factorial of a number.
//  int fact(int n){
//         if(n==0){
//             return 1;
//         }
//         return n*fact(n-1);
//  }
// problem 4 : Write a function to check if a number is prime or not.
//   int isPrime(int n){
//         if(n<=1){
//             return 0;
//         }
//         for(int i=2;i*i<=n;i++){
//             if(n%i==0){
//                 return 0;
//             }
//         }
//         return 1;
// }
// problem 5 :Write a function to find the sum of digits of a number.
//  int sumOfDigits(int n){
//     printf("n = %d\n",n);
//         if(n==0){
//             return 0;
//         }
//         return n%10 + sumOfDigits(n/10);
        
//  }

int main(){
    // int a,b;
    // printf("Enter the two numbers : ");
    // scanf("%d %d",&a,&b);
    // printf("The GCD of %d and %d is %d",a,b,GCD(a,b));
    // problem 2 :Write a function to calculate the power of a number.
    // int a,b;
    // printf("Enter the number and its power : ");
    // scanf("%d %d",&a,&b);
    // printf("The power of %d raised to %d is %d",a,b,power(a,b));
    // problem 3 : Write a recursive function to calculate the factorial of a number.
    // int n;
    // printf("Enter the number : ");
    // scanf("%d",&n);
    // printf("The factorial of %d is %d",n,fact(n));
    // problem 4 : Write a function to check if a number is prime or not.
    // int n;
    // printf("Enter the number : ");
    // scanf("%d",&n);
    // if(isPrime(n)){
    //     printf("The number is prime");
    // }
    // else{
    //     printf("The number is not prime");
    // }
    // problem 5 :Write a function to find the sum of digits of a number.
    // int n;
    // printf("Enter the number : ");
    // scanf("%d",&n);
    // printf("The sum of digits of %d is %d",n,sumOfDigits(n));




    return 0;
}