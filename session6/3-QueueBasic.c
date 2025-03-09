
  #include <stdio.h>
  #include <stdlib.h>
 
  #define MAX 5

  /* global variables */

  int queue[MAX] , front=-1,rear=-1;

  void enqueue( int value ) {
  
     if( rear == MAX - 1 ) {
       printf("\n queue full ");
       return;	 
     }

     rear++;
     queue[rear] = value ;

     // for the first case i.e. empty case
     if( front == -1 )
       front = 0; 
  }

  void dequeue() {
    if( front == -1 )
       printf("\n queue empty");
    else {
       int value = queue[front];

       // if only one element is present in the queue
       if( front == rear )
         front = rear = -1;
       else
         front++;
       printf("\n removed value %d", value );
    }  
  }

  int menu() {
    int choice;
    
    printf("\n");
    printf("\n 1: enqueue ");
    printf("\n 2: dequeue ");
    printf("\n 3: exit ");
    printf("\n Enter your choice ");
    scanf("%d",&choice);
 
    return choice; 
  }

  int main() {
    int value;
    int choice;

    // 1 or any non zero value is considered true in c language
    // hence this is an infinite loop, choosing choice 3 will break the loop.
    while( 1 ) {
       choice = menu();
       switch( choice ) {
       case 1 : 
          printf("Enter a value to insert  ");
          scanf("%d",&value);
          enqueue( value );
          break;
       case 2 :
          dequeue(); 
          break;
       case 3:
          exit(0);
       }
    }

    return 0;
  }
 