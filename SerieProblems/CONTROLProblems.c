// CONTROL STATEMENTS 


    int main(){
        // problem 1 : Write a program to find the largest of three numbers using if-else.
            int a,b,c ;
            printf ("Enter The 3 Numbers : ");
            scanf("%d %d %d",&a,&b,&c);
            if(a>b && a>c )
            {
                printf("The Largest is : %d",a);
            }
            else if(b>c)
            {
                printf("The Largest is : %d",b);
            }
            else{
                printf("The Largest is : %d",c);
            }
        /////////////////////////////////////////////////////////
        //problem 2 : Write a program to check if a number is positive, negative, or zero
        int x ;
        printf("Enter Number : ");
        scanf("%d",&x);
        if(x>0){
            printf("The number %d is Positive",x);
        }
        else if(x<0){
             printf("The number %d is Negative",x);
        }
        else {
             printf("The number %d is Zero",x);
        }
        //////////////////////////////////////////////////
        // problem 3 : Write a program to calculate the factorial of a number using a for loop.
        int n ,F=1;
        printf("Enter Number : ");
        scanf("%d",&n);
        for(int i =1 ;i<=n; i++){
            F=F*i;
        }
        printf("The factorial of %d is %d",n,F);
        
        /////////////////////////////////////////////////
        //problem 4 : Write a program to print the first n natural numbers using a while loop.
        int n , i=1;
        printf("Enter Number : ");
        scanf("%d",&n);
        while (i<=n)
        {
            printf("%d",i);
            printf("\n");
            i++ ;
        }
        ////////////////////////////////////////////////////////////
        // problem 5 : Write a program to display the multiplication table of a given number
        int a ,i ,s=1;
        printf("Enter The number : ");
        scanf("%d",&a);
        for(i=1 ;i<=10 ; i++){
            s=a*i;
            printf("%d * %d = %d \n",a,i,s);
        }
        return 0;
    }