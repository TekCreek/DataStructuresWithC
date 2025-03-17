
  #include <stdio.h>
  #include <stdlib.h>

  /* global variables */
  #define MAX 5
  int stack[MAX] , top = -1;

  void push( int value ) {

     if( top == MAX - 1 ) {
       printf("\n stack overflow error");
       exit(1);
     }

     top++;
     stack[top] = value ;
  }

  int pop() {
    
    int value;

    if( top == -1 ) {
       printf("\n stack underflow error");
       exit(1);
    } 
    
    value = stack[top];
    top--;
    return value;
  }

  int menu() {
    int choice;

    printf("\n");
    printf("\n 1: push ");
    printf("\n 2: pop ");
    printf("\n 3: exit ");
    printf("\n Enter your choice ");
    scanf("%d",&choice);

    return choice;
  }

  void main() {
    int value;
    int choice;

    while( 1 ) {
       choice = menu();
       switch( choice ) {
       case 1 :
          printf("Enter a value to push ");
          scanf("%d",&value);
          push( value );
          break;
       case 2 :
          value = pop();
          printf(" Popped value %d ", value);
          break;
       case 3:
          exit(0);
       }
    }
  }
