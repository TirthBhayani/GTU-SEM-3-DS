#include<stdio.h>
int top= -1;

int push(int a[10],int top,int num){
    if(top==9)
    {
        printf("stack is full");
    }
    else{
        top++;
        printf("enter num:");
        scanf("%d",&num);
        a[top]=num;
        for(int i=0;i<6;i++){
            printf("%d ",a[i]);
        }
        }
}
void pop(int a[10],int top){
    if(top==-1)
    {
        printf("stack is empty");
    }
    else{
        printf("poped element is %d",a[top]);
        top--;
    }
}
void peep(int a[10],int top){
    if(top==-1){
        printf("stack is empty");
    }
    else{
        printf("%d ",a[top]);
    }
}
void change(int a[10],int top,int x,int y){
    int temp,temp1;
    int n;
    printf("enter x for change");
    scanf("%d",&x);
    printf("enter y(index):");
    scanf("%d",&y);
    if(top==-1){
        printf("stack is empty");
    }
    else{
        if(y==4 || y==0){
            a[y]=x;
        }
        else{
            for(int i=y;i<top;i++){
                temp=a[y];
                a[y]= a[y+1];
                a[y+1]=temp;}
                a[top]=x;
                n=top;
                for(int i=top;i>y;i--){
                    if(top==-1)
                    {
                        printf("stack is empty");
                    }
                    else{
                        temp1=a[top-1];
                        a[top-1]=a[top];
                        a[top]=temp1;
                        top--;
                    }
                }
                            }
        }
        for(int i=0;i<5;i++){
            printf("%d ",a[i]);
        }
    }
    void display(int a[10],int top)
    {
        for(int i=0;i<5;i++)
        {
            printf("%d ",a[i]);
        }
    }
void main(){
int a[10];
int x,y,number;
for(int i=0;i<5;i++)
{
    top++;
    scanf("%d",&a[i]);
}
printf("1.push 2.pop 3.peep 4.change 5.display\n");
scanf("%d",&number);
         switch(number){
            case 1 : push(a,top,x);
            break;
            case 2 : pop(a,top);
            break;
            case 3 : peep(a,top);
            break;
            case 4 : change(a,top,x,y);
            break;
            case 5 : display(a,top);
            break;
            default : printf("invaild number");
         }
}