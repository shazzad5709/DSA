#include<iostream>
#include<string.h>
using namespace std;
char pre[100],post[100],in[100],tree[100];
int z,j,n;

void input()
{
        printf("Enter inorder array\n");
        scanf(" %[^\n]",&in);
        printf("Enter 1 for preorder or 2 for postorder\n");
        scanf("%d",&z);
        if(z==1)
        {
            printf("Enter preorder array\n");
            scanf(" %[^\n]",&pre);
            n=strlen(pre);
            j=0;
        }
        else if(z==2)
        {
            printf("Enter postorder array\n");
            scanf(" %[^\n]",&post);
            n=strlen(post);
            j=n-1;
        }
}

void inPreTree(int index,int start,int end)
{
     if(start>end){return;}
     else
     {
        int temp;
        temp = start;
        j++;
        while(in[temp]!=pre[j]){temp++;}
        if(in[temp]==pre[j])
        {
            tree[index]=in[temp];
            inPreTree(index*2+1,start,temp-1);
            inPreTree(index*2+2,temp+1,end);
        }
    }
}

void inPostTree(int index,int start,int end)
{
     if(start>end){return;}
     else
     {
        int temp;
        temp = start;
        j--;
        while(in[temp]!=post[j]){temp++;}
        if(in[temp]==post[j])
        {
            tree[index]=in[temp];
            inPostTree(index*2+2,temp+1,end);
            inPostTree(index*2+1,start,temp-1);
        }
    }
}

void sub1(char root)
{
    int i=0,index=0;
    while(in[i]!=root){i++;}
    inPreTree(index*2+1,0,i-1);
    inPreTree(index*2+2,i+1,n-1);
}

void sub2(char root)
{
    int i=0,index=0;
    while(in[i]!=root){i++;}
    inPostTree(index*2+2,i+1,n-1);
    inPostTree(index*2+1,0,i-1);
}

int main()
{
    input();
    char root;
    int i;
    if(z==1)
    {
        root = pre[0];
        tree[0] = pre[0];
        sub1(root);
    }
    if(z==2)
    {
        root = post[n-1];
        tree[0] = post[n-1];
        sub2(root);
    }
    for(i=0;i<100;i++)
        {
            printf("%c ",tree[i]);
        }
}