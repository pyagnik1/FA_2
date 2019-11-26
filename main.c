#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>

struct string_node{
	char *name;
	struct string_node *right;
	struct string_node *left;
}string_node;



int main(void) {

	int N,S,D;

	struct string_node *inputString,*searchString,*deletString,*root = NULL;

	FILE *Fileinput, *Fileoutput;

	Fileinput = fopen("in.txt", "r");

  if (Fileinput != NULL) {

    printf("\nReading the data....\n");

    fscanf(Fileinput, "%d %d %d", &N,&S,&D);

		inputString = malloc(N*sizeof(string_node));
		searchString = malloc(S*sizeof(string_node));
		deletString = malloc(D*sizeof(string_node));

		printf("\n");
		for(int i =0; i<N;i++){
			inputString[i].name = (char*)malloc(10*sizeof(char*));
			fscanf(Fileinput, "%s",inputString[i].name);
			printf("input string is %s \n", inputString[i].name);

			if(i ==0){

				

			}
		}

		int offset1=0;

		printf("\n");
		for(int j=N; j<S+N;j++){
			searchString[offset1].name =(char*)malloc(10*sizeof(char*));
			fscanf(Fileinput, "%s",searchString[offset1].name);
			printf("search strings are %s \n", searchString[offset1].name);
			offset1++;
		}



		int offset2=0;
		printf("\n");
		for(int k=N+S; k<N+S+D;k++){
			deletString[offset2].name = (char*)malloc(10* sizeof(char*));
			fscanf(Fileinput, "%s", deletString[offset2].name); 
			printf("delet string is %s\n", deletString[offset2].name);
			offset2++;
		}

  }

	else{

		printf("Provide a file....\n");
	
	}

  return 0;
}

struct tree_node* insert(struct string_node *root,struct string_node *element) {

  // Inserting into an empty tree.
  if (root == NULL) {
    printf("Element data %s -> address: %p\n", element->name, &(element->name));
    return element;
  }
  else {

    // element should be inserted to the right.
    if (element->name > root->name) {

      // There is a right subtree to insert the node.
      if (root->right != NULL)
        root->right = insert(root->right, element);

      // Place the node directly to the right of root.
      else
        root->right = element;
    }

    // element should be inserted to the left.
    else {

      // There is a left subtree to insert the node.
      if (root->left != NULL)
        root->left = insert(root->left, element);

      // Place the node directly to the left of root.
      else
        root->left = element;
    }

    //this print will help you to understand what nodes where visited during insertion and see the recursion stack
    printf("Root data: %s -> address: %p\n", root->name, &(root->name));
    // Return the root pointer of the updated tree.
    return root;
  }
}
