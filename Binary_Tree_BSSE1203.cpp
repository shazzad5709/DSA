#include <iostream>
#include <vector>
using namespace std;

vector<int> inorder;
vector<int> preorder;
vector<int> postorder;
int tree[101];

// func for preorder
void get_preorder(int c,int n)
{
	if(c>=n) return;
	if(tree[c] == -1) return;
	
	preorder.push_back(tree[c]);
	
	//Recursive call to left child
	get_preorder(2*c, n);
	//Recursive call to right child
	get_preorder(2*c+1, n);
}

// func for postorder
void get_postorder(int c, int n)
{
	if (c >= n) return;
	if (tree[c] == -1) return;
	
	get_postorder(2*c,n);
	get_postorder(2*c+1,n);
		
	postorder.push_back(tree[c]);
}

// fucn for in order
void get_inorder(int c, int n)
{
	if (c >= n) return;
	if (tree[c] == -1) return;
	
	get_inorder(2*c, n);
	
	inorder.push_back(tree[c]);
	
	get_inorder(2*c+1,n);
}

int main()
{
    int n;
    cin>>n;

    int withspace=1;
    int node=0;

    //Iput loop
    //Tree stored in array
    //where if i-th element is the parent
    //2i-th element is left child and
    //(2i+1)-th element is right child
    //input -1 if no child

    while(node!=n)
    {
        int x;
        cin>>x;
        tree[withspace++]=x;
        if(x!=-1)
            node++;
    }

    cout<<"Tree: ";
    for (int i=1; i<withspace; i++)
            printf("%4d", tree[i]); //tree elements
    puts("");
    cout<<"Index:";
    for (int i=1; i<withspace; i++)
        printf("%4d", i);   //position of elements in the tree
    puts("");

    get_preorder(1, withspace);

    cout<<"Preorder: ";
    for(int i : preorder)
        printf("%4d", i);
    puts("");

    get_postorder(1, withspace);

    cout<<"Postorder: ";
    for(int i : postorder)
        printf("%4d", i);
    puts("");

    get_inorder(1, withspace);

    cout<<"Inorder: ";
    for(int i : inorder)
        printf("%4d", i);
    puts("");
}