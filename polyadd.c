#include<stdio.h>
#include<stdlib.h>
struct node{
        int co;
        int ex;
        struct node *next;
}*newnode,*temp;
struct node *head=NULL,*tail=NULL;
void create_poly(struct node **);
void display(struct node *);
void poly_add(struct node *,struct node *);
void multi(struct node *,struct node *);
void main()
{
        struct node *head1=NULL,*head2=NULL;
        //creating 1st polynomial
        printf("Creating first polynomial..Please enter coefficients along with exponents \n");
        create_poly(&head1);
        printf("Creating second polynomial..please enter coefficients along with exponents\n");
        create_poly(&head2);
        printf("enter 1 to display 1st polynomial \n enter 2 to dispaly 2nd polynomial\n enter 3 to add the two polynomials\nenter 4 to multiply two polynomials");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
                display(head1);
        }
        else if(ch==2)
          {
                display(head2);
        }
        else if(ch==3)
        {
                poly_add(head1,head2);
        }
        else
        {
                multi(head1,head2);
        }

}
void create_poly(struct node **head)
{
        int c,e;
        char ch;
        do
        {
                newnode=(struct node *)malloc(sizeof(struct node));
                printf("enter coefficient and exponent: ");
                scanf("%d",&c);
                scanf("%d",&e);
                newnode->co=c;
                newnode->ex=e;
                if(*head==NULL)
                {
                        *head=newnode;
                        tail=newnode;
}
                else
                {
                        tail->next=newnode;
                        tail=newnode;
                }
                fflush(stdin);
                printf("Do you want to continue?:");
                scanf(" %c",&ch);
        }while(ch=='y');
}
void display(struct node *head)
{
        temp=head;
        while(temp->next!=NULL)
        {
                if(temp->next->next==NULL)
                {
                        printf("%dX^%d ",temp->co,temp->ex);
                }
                else
                {
                        printf("%dX^%d+",temp->co,temp->ex);
                }
        temp=temp->next;
        }
}
void poly_add(struct node *head1,struct node *head2)
{
struct node *newnode;
        while(1)
        {
                if(head1==NULL||head2==NULL)
                {
                        break;
                }
                else if(head1->ex==head2->ex)
                {
                        if(head1->next==NULL)
                        {
                                printf("%dX^%d",head1->co+head2->co,head1->ex);
                        }
                        else
                        {
                                printf("%dx^%d+",head1->co+head2->co,head1->ex);
                        }
                        head1=head1->next;
                        head2=head2->next;
                }
                else
                {
                if(head1->ex > head2->ex)
                {
                        if(head1->next==NULL)
                        {
                                printf("%dX^%d",head1->co,head1->ex);
                        }
                        else
                          {
                                printf("%dX^%d+",head1->co,head1->ex);
                        }
                        head1=head1->next;
                }
                else
                {
                        if(head2->next==NULL)
                        {
                                printf("%dX^%d",head2->co,head2->ex);
                        }
                        else
                        {
                                printf("%dX^%d+",head2->co,head2->ex);
                        }
                        head2=head2->next;
                }
                }
        }
}
void multi(struct node *head1,struct node *head2)
{
        struct node *ptr1=head1;
        struct node *ptr2=head2;
        newnode=(struct node*)malloc(sizeof(struct node));
        while(ptr1!=NULL)
        {
                while(ptr2!=NULL)
                {int coe,exp;
                        coe=ptr1->co*(ptr2->co);
                        exp=ptr1->ex+(ptr2->ex);
                        newnode->co=coe;
                        newnode->ex=exp;
                }
        }
        temp=newnode;
        while(temp!=NULL && temp->next!=NULL)


}
}
}
