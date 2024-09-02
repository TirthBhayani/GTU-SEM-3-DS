#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL, *ptr;

void insert_begin(int value)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
}
void insert_end(int value)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;

	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->next = NULL;
	}
}
void delete_begin()
{
	if (head == NULL)
	{
		printf("List if Empty, Deletion is not Possible");
	}
	else
	{
		ptr = head;
		head = head->next;
		// ptr->next=NULL;
		free(ptr);
	}
}
void delete_end()
{
	if (head == NULL)
	{
		printf("List if Empty, Deletion is not Possible");
	}
	else
	{
		struct node *p;
		ptr = head;
		while (ptr->next != NULL)
		{
			p = ptr;
			ptr = ptr->next;
		}
		p->next = NULL;
		free(ptr);
	}
}
void deleteafter(int ele)
{
	struct node *temp;
	struct node *temp1;
	temp = head;
	for (int i = 1; i < ele + 1; i++)
	{
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = temp->next;
	free(temp);
}
void deletebefore(int ele)
{
	struct node *temp1;
	struct node *temp = head;
	for (int i = 1; i < ele - 1; i++)
	{
		temp1 = temp;
		temp = temp->next;
	}
	temp1->next = temp->next;
	free(temp);
}
void display()
{
	if (head == NULL)
	{
		printf("List if Empty");
	}
	else
	{
		ptr = head;
		while (ptr != NULL)
		{
			printf("%d ->", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}
void shorting()
{
	struct node *i, *j;
	int temp;
	for (i = head; i->next != NULL; i = i->next)
	{
		for (j = i->next; j != NULL; j = j->next)
		{
			if (i->data > j->data)
			{
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}
void accending(int ele)
{
	struct node *new;
	struct node *first = head, *back;
	new->data = ele;
	while (first->data < ele)
	{
		back = first;
		first = first->next;
	}
	new->next = back->next;
	back->next = new;
}
void main()
{
	int value, ele, ch;
	printf("1.insert node at the start\n");
	printf("2.insert node at the end\n");
	printf("3.shorting\n");
	printf("4.insert node such that list is in acccending order\n");
	printf("5.delete a first node\n");
	printf("6.delete a node before specific position\n");
	printf("7.delete a node after specific positon\n");
	while (1)
	{
		printf("Enter the Choice \n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
		{
			printf("Enter the value");
			scanf("%d", &value);
			insert_begin(value);
			display();
			break;
		}
		case 2:
		{
			printf("Enter the value");
			scanf("%d", &value);
			insert_end(value);
			display();
			break;
		}
		case 3:
		{
			shorting();
			display();
			break;
		}
		case 4:
		{
			printf("enter value:");
			scanf("%d", &ele);
			accending(ele);
			display();
			break;
		}
		case 5:
		{
			delete_begin();
			display();
			break;
		}
		case 6:
		{
			printf("enter position:");
			scanf("%d", &ele);
			deletebefore(ele);
			display();
			break;
		}
		case 7:
		{
			printf("enter position:");
			scanf("%d", &ele);
			deleteafter(ele);
			display();
			break;
		}
		}
	}
}
