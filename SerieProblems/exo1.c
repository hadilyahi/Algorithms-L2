// BASICS OF C PROGRAMMING
#include <stdio.h>

int main(){
    //problem 1 : Write a program to print "Hello, World!".
    printf("Hello World \n");
    ///////////////////////////////////////////////////
    //problem 2 : Write a program to take two integers as input and print their sum.
    int x , y , S=0 ;
    printf("Enter Number 1 : ");
    scanf("%d",&x);
    printf("Enter Number 2 : ");
    scanf("%d",&y);
    S=x+y;
    printf("The Sum Of %d and %d is %d \n",x,y,S);
    ///////////////////////////////////////////////////////
     // problem 3 : Write a program to find the area of a rectangle using its length and breadth.
    int a,b,c=0;
    printf("Enter the length and breadth ");
    scanf("%d %d",&a,&b);
    c=a*b;
    printf("The area is : %d",c);
    ///////////////////////////////////////////////////////
    // problem 4: Write a program to swap two numbers without using a temporary variable.
    int a , b ;
    printf("Enter the value of A :");
    scanf("%d",&a);
    printf("Enter the value of B :");
    scanf("%d",&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("The Swap :\n A = %d \n B = %d",a,b);
    /////////////////////////////////////////////////////
    // problem 5 : Write a program to check if a given number is even or odd.
    int  N ;
    printf ("Enter The number : ");
    scanf("%d",&N);
    if(N % 2 == 0){
        printf("The Number is Even");
    }
    else{
        printf("The Number is Odd");
    }
    /////////////////////////////////////////////
    return 0;
}