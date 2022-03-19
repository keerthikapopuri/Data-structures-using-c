#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <stdbool.h>   
   
//Represents the node of list.  
struct node{  
    int data;  
    struct node *next;  
};  
   
//Declaring head and tail pointer as null.  
struct node *head = NULL;  
struct node *tail = NULL;  
   
//This function will add the new node at the end of the list.  
void add(int data){  
    //Create new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    //Checks if the list is empty.  
    if(head == NULL){  
        //If list is empty, both head and tail would point to new node.  
        head = newNode;  
        tail = newNode;  
        newNode->next = head;  
    }else {  
        //tail will point to new node.  
        tail->next = newNode;  
        //New node will become new tail.  
        tail = newNode;  
        //Since, it is circular linked list tail will point to head.  
        tail->next = head;  
    }  
}  
   
//Searches for a node in the list  
void search(int element) {  
    struct node *current = head;  
    int i = 1;  
    bool flag = false;  
    //Checks whether list is empty  
    if(head == NULL) {  
        printf("List is empty");  
    }  
    else {  
         do{  
             //Compares element to be found with each node present in the list  
            if(current->data ==  element) {  
                flag = true;  
                break;  
            }  
            current = current->next;  
            i++;  
        }while(current != head);  
         if(flag)  
            printf("Element is present in the list at the position : %d", i);  
        else  
            printf("\nElement is not present in the list");  
    }  
}  
      
int main()  
{  
    //Adds data to the list  
   add(1);  
   add(2);  
   add(3);  
   add(4);  
   //Search for node 2 in the list  
   search(2);  
   //Search for node in the list  
   search(7);  
     
   return 0;  
}  
