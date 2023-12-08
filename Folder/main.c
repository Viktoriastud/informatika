#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main(){
	struct Cinema *arr=NULL;
	int n = 0;
	int stop = 0;
	while (stop!=1){
		int chislo = 0;
		printf("1 - создать\n2 - прочитать\n3 - вывести\n4 - найти\n");
		errorString(&chislo);
		switch(chislo){
			case 1:
				create(&arr, &n);
				if(arr)
					write(arr, n);
				break;
			case 2:
				read(&arr, &n);
				if(!arr)
					printf("Ошибка чтения..\n");
				else
					printf("Загружено %d значений\n", n);
				break;
			case 3:
				for(int i = 0; i < n; i++)
					printf("%s %f %s\n", arr[i].name, arr[i].price, arr[i].day);
				break;
			case 4:
				printf("1 - имя фильма\n2 - цена сеанса\n3 - день сеанса\n");
				int searchS;
				scanf("%d",&searchS);
				search(arr, n, searchS);
				break;
			default:
				stop = 1;
				break;
			}
		}
	if(arr)
		free(arr);
	return 0;
}
