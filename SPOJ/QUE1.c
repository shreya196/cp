#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *next;
};

struct node *insertAtPos(struct node *start, int data, int pos){
	struct node *temp = start, *p = start;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->info = data;
	int i = 1;

	if(pos == 0){
		new->next = start;
		start = new;
		return start;
	}

	while(i < pos && temp != NULL){
		temp = temp->next;
		i++;
	}

	if(temp == NULL)
		return start;

	new->next = temp->next;
	temp->next = new;
	return start;
}

void display(struct node *start){
	while(start != NULL){
		printf("%d ", start->info);
		start = start->next;
	}
	printf("\n");
}

int main(){
	int n, i = 0, num, j, k, temp;
	scanf("%d", &n);
	while(i < n){
		scanf("%d", &num);
		int arrHeight[num], arrPos[num];
		struct node * start  = NULL;
		
		for(j = 0; j < num; j++){
			scanf("%d", &arrHeight[j]);
		}

		for(j = 0; j < num; j++){
			scanf("%d", &arrPos[j]);
		}

		for(j = 0; j < num; j++){
			for(k = j+1; k < num; k++){
				if(arrHeight[j] < arrHeight[k]){
					temp = arrHeight[j];
					arrHeight[j] = arrHeight[k];
					arrHeight[k] = temp;
					temp = arrPos[j];
					arrPos[j] = arrPos[k];
					arrPos[k] = temp;
				}
			}
		}

		for(j = 0; j < num; j++){
			start = insertAtPos(start, arrHeight[j], arrPos[j]);
		}
		display(start);
		i++;
	}
	return 0;
}