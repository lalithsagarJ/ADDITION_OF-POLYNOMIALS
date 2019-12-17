#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
struct node{
	int coeff;
	int pow;
	struct node *link;
};
typedef struct node* NODE;
NODE poly=NULL,poly1=NULL,poly2=NULL;
NODE getnode(){
	NODE x=(NODE)malloc(sizeof(struct node));
	return x;
}

NODE create_poly(){
	int c,p,i;
	NODE ptr=getnode();
	NODE e=ptr;
	ptr->link=e;
	do{
		NODE temp=getnode();
		ptr->link=temp;
		printf("\nenter the coefficient:");
		scanf("%d",&c);
		temp->coeff=c;
		printf("enter the power:");
		scanf("%d",&p);
		temp->pow=p;
		temp->link=e;
		ptr=temp;
		printf("\n0:exit\t1:continue:");
		scanf("%d",&i);
	}while(i!=0);
	return e;
}

NODE addition(){
	NODE ptr=getnode();
	NODE e=ptr;
	ptr->link=e;
	NODE ptr1=poly1->link;
	NODE ptr2=poly2->link;
	while(ptr1!=poly1&&ptr2!=poly2){
		NODE temp=getnode();
		ptr->link=temp;
		ptr=temp;
		if(ptr1->pow>ptr2->pow){
			ptr->pow=ptr1->pow;
			ptr->coeff=ptr1->coeff;
			ptr1=ptr1->link;
		}
		else if(ptr1->pow<ptr2->pow){
			ptr->pow=ptr2->pow;
			ptr->coeff=ptr2->coeff;
			ptr2=ptr2->link;
		}
		else{
			ptr->pow=ptr1->pow;
			ptr->coeff=ptr1->coeff+ptr2->coeff;
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
	}
	while(ptr1!=poly1||ptr2!=poly2){
		while(ptr1!=poly1){
			NODE temp=getnode();
			ptr->link=temp;
			ptr=temp;
			ptr->pow=ptr1->pow;
			ptr->coeff=ptr1->coeff;
			ptr1=ptr1->link;
		}
		while(ptr2!=poly2){
			NODE temp=getnode();
			ptr->link=temp;
			ptr=temp;
			ptr->pow=ptr2->pow;
			ptr->coeff=ptr2->coeff;
			ptr2=ptr2->link;
		}
	}
	ptr->link=e;
	return e;
}

void display(NODE p){
	NODE ptr=p->link;
	printf("\nRESULT\n");
	while(ptr!=p){
		printf("%dx^%d",ptr->coeff,ptr->pow);
		printf("+");
		ptr=ptr->link;
	}
}

int main(){
	printf("\nenter the 1st polynomial:");
	poly1=create_poly();
	display(poly1);

	printf("\nenter the 2nd polynoial:");
	poly2=create_poly();
	display(poly2);
	
	printf("\nAddition of polynomials is:");
	poly=addition();
	display(poly);
	
	return 0;
}
