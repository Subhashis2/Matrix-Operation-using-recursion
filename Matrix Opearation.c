//...Subhashis PAUL

#include<stdio.h>
#include<stdlib.h>
typedef struct Array{
	int **arr, **arr2, **finalArr, row, columns, row2, columns2;
}array;

int do_transpose(int, int, array *elements);
int do_tran(int, int, array *elements);
int Transpose();
int do_addition(int, int, array *elements);
int do_add(int, int, array *elements);
int do_multiplication(int, int, int, array *elements);
int do_multiply(int, int, int, array *elements);
int Operation(int);
int printMatrix(array *elements);
int printResultMatrix(array *elements);

int do_tran(int row, int column, array *elements){
	*(*(elements->finalArr + column) + row) = *(*(elements->arr + row) + column);
}

int do_transpose(int row,int column,array *elements){
	if(row == elements->row)
		return;
	if(column < elements->columns){
		do_tran(row, column, elements);
		column++;
		do_transpose(row, column, elements);
	}
	else{
		row++;
		column=0;
		do_transpose(row, column, elements);	
	}
}

int Transpose(){
	array elements;
	int i,j;
	system("cls");
	printf("Enter the number of rows in the matrix: ");
	scanf("%d",&elements.row);
	printf("\nEnter the number columns in the matrix: ");
	scanf("%d",&elements.columns);
	printf("\n");
	elements.arr = (int**)malloc(elements.row*sizeof(int*));
	for(i=0; i<elements.row; i++)
		*(elements.arr+i) = (int*)malloc(elements.columns*sizeof(int));
	for(i=0; i<elements.row; i++)
		for(j=0; j<elements.columns; j++){
			printf("Enter value for matrix[%d][%d] :  ",i,j);
			scanf("%d", (*(elements.arr+i)+j));
		}
	system("Cls");
	printf("\n    -: Matrix :-\n\n");
	for(i=0; i<elements.row; i++){
		for(j=0; j<elements.columns; j++)
			printf("\t%d",*(*(elements.arr + i) + j));
		printf("\n");
		}
	elements.finalArr = (int**)malloc(elements.columns*sizeof(int*));
	for(i=0; i<elements.columns; i++)
		*(elements.finalArr+i) = (int*)malloc(elements.row*sizeof(int));
	do_transpose(0, 0, &elements);
	printf("\n    -: Transpose of the matrix :-\n\n");
	for(i=0; i<elements.columns; i++){
		for(j=0; j<elements.row; j++)
			printf("\t%d",*(*(elements.finalArr + i) + j));
		printf("\n");
		}
	free(elements.arr);
	free(elements.finalArr);
	getch();
}

int do_add(int row, int column, array *elements){
	*(*(elements->finalArr + row) + column) = (*(*(elements->arr + row) + column)) + (*(*(elements->arr2 + row) + column));
}

int do_addition(int row, int column, array *elements){
	if(row == elements->row){
		return;
	}
	if(column < elements->columns){ 
		do_add(row, column, elements);
		column++;
		do_addition(row, column, elements);
	}
	else{
		row++;
		column=0;
		do_addition(row, column, elements);	
	}
}

int do_multiply(int row, int column, int column2, array *elements){
	*(*(elements->finalArr + row) + column2) = *(*(elements->finalArr + row) + column2) + ((*(*(elements->arr + row) + column)) * (*(*(elements->arr2 + column) + column2)));
//	printf("row: %d , column: %d,  column2: %d, sum: %d\n",row,column,column2,*(*(elements->finalArr + row) + column2));
}

int do_multiplication(int row, int column, int column2, array *elements){
	if(row == elements->row){
		return;
	}
//	printf("%d\n",elements->columns2);
	if(column2 == elements->columns2){
		row++;
		column2 = 0;
		column=0;
		do_multiplication(row, column, column2, elements);
	}
	else{
		if(column < elements->columns){ 
			do_multiply(row, column, column2, elements);
			column++;
			do_multiplication(row, column, column2, elements);
		}
		else{
			column2++;
			column=0;
			do_multiplication(row, column, column2, elements);	
		}
	}
}

int printMatrix(array *elements){
	int i,j;
	system("Cls");
	printf("\n    -: Matrix_1 :-\n\n");
	for(i=0; i<elements->row; i++){
		for(j=0; j<elements->columns; j++)
			printf("\t%d",*(*(elements->arr + i) + j));
		printf("\n");
	}
	printf("\n    -: Matrix_2 :-\n\n");
	for(i=0; i<elements->row2; i++){
		for(j=0; j<elements->columns2; j++)
			printf("\t%d",*(*(elements->arr2 + i) + j));
		printf("\n");
	}
}
int printResultMatrix(array *elements){
	int i,j;
	for(i=0; i<elements->row; i++){
		for(j=0; j<elements->row; j++)
			printf("\t%d",*(*(elements->finalArr + i) + j));
		printf("\n");
		}
}

int Operation(int choice){
	array elements;
	int i,j;
	system("cls");
	printf("   -: For the first matrix :-\n\n");
	printf("Enter the number of rows in the matrix: ");
	scanf("%d",&elements.row);
	printf("\nEnter the number columns in the matrix: ");
	scanf("%d",&elements.columns);
	printf("\n");
	elements.arr = (int**)malloc(elements.row*sizeof(int*));
	for(i=0; i<elements.row; i++)
		*(elements.arr+i) = (int*)malloc(elements.columns*sizeof(int));
	for(i=0; i<elements.row; i++)
		for(j=0; j<elements.columns; j++){
			printf("Enter value for matrix[%d][%d] :  ",i,j);
			scanf("%d", (*(elements.arr+i)+j));
		}
	system("Cls");
	printf("\n    -: Matrix :-\n\n");
	for(i=0; i<elements.row; i++){
		for(j=0; j<elements.columns; j++)
			printf("\t%d",*(*(elements.arr + i) + j));
		printf("\n");
	}
	system("cls");
	printf("   -: For the second matrix :-\n\n");
	printf("Enter the number of rows in the matrix: ");
	scanf("%d",&elements.row2);
	printf("\nEnter the number columns in the matrix: ");
	scanf("%d",&elements.columns2);
	printf("\n");
	elements.arr2 = (int**)malloc(elements.row2*sizeof(int*));
	for(i=0; i<elements.row2; i++)
		*(elements.arr2+i) = (int*)malloc(elements.columns2*sizeof(int));
	for(i=0; i<elements.row2; i++)
		for(j=0; j<elements.columns2; j++){
			printf("Enter value for matrix[%d][%d] :  ",i,j);
			scanf("%d", (*(elements.arr2+i)+j));
		}
	printMatrix(&elements);
	elements.finalArr = (int**)malloc(elements.row*sizeof(int*));
	for(i=0; i<elements.row; i++)
		*(elements.finalArr+i) = (int*)malloc(elements.row*sizeof(int));
	if(choice == 1){
		if(elements.row == elements.row2 && elements.columns ==  elements.columns2){
				do_addition(0, 0, &elements);
				printf("\n    -: Addition of the matrix :-\n\n");
				printResultMatrix(&elements);
			}
			else
				printf("\n\nAddition not possible!!...Wrong row/columns....");
	}
	else{
		if((elements.row == elements.columns2) && (elements.columns == elements.row2)){
			for(i=0; i<elements.row; i++){
				for(j=0; j<elements.row; j++)
					*(*(elements.finalArr + i) + j) = 0;
			}
			do_multiplication(0, 0, 0, &elements);
			printf("\n    -: Multiplication of the matrix :-\n\n");
			printResultMatrix(&elements);		
		}
		else
			printf("\n\nMultiplication not possible!!...Wrong row/columns....");
	}
	free(elements.arr);
	free(elements.arr2);
	free(elements.finalArr);
	getch();
}

int main(){
	int choice;
	while(1){
	system("CLS");
	printf("\n *********************************************************************************");
	printf("\n *                                                                               *");
	printf("\n *                                                                               *");
	printf("\n *                       /---> Addition (Type 1)                                 *");
	printf("\n *                      /                                                        *");
	printf("\n *  Matrix operation ---|----> Multiplication (Type 2)                           *");
	printf("\n *                      \\                                                        *");
	printf("\n *                       \\---> Transpose (Type 3)                                *");
	printf("\n *                                                                               *");
	printf("\n *            Type (0) to exit.....                                              *");
	printf("\n *                                                                               *");
	printf("\n *********************************************************************************");
	printf("\n\n Please enter your choice : ");
	scanf("%d",&choice);
	switch(choice){
		case 0:
			exit(0);
			break;
		case 1:
			Operation(1);
			break;
		case 2:
			Operation(2);
			break;
		case 3:
			Transpose();
			break;
		default:
			printf("\n Enter correct choice !!!!");
			sleep(2);
			break;
		}
	}
	return 0;
}

