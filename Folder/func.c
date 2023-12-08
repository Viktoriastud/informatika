#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include <wchar.h>

int errorString(int *m){
	if(scanf("%u", m)==1) {
		return 0;
	}
	else {
		printf("ошибка\n");
		while(getchar()!='\n');
		return 1;
	}
}

void write(struct Cinema*arr, int n){
	if (n <= 0) {
		return;
	}
	FILE *f=fopen("file.txt", "w");
	if(!f) {
		return;
	}
	fprintf(f, "%d\n",n);
	for (int i = 0; i < n; i++) {
		fprintf(f, "%s %f %s\n", arr[i].name, arr[i].price, arr[i].day);
	}
	fclose(f);
}
void read(struct Cinema **arr, int *n){
	FILE *f=fopen("file.txt", "r");
	if(!f)
		return;
	if(fscanf(f,"%d", n)!=1)
		return;
	if(*n<=0)
		return;
	*arr=(struct Cinema *)calloc(*n, sizeof(struct Cinema));
	for (int i=0; i<*n; i++)
		fscanf(f, "%s %f %s", (*arr)[i].name, &(*arr)[i].price, (*arr)[i].day);
	fclose(f);
}
void create(struct Cinema **arr, int *n){
	printf("Введите количество фильмов - ");
	if(errorString(n)) {
		return;
	}
	if (*n <= 0) {
		return;
	}
	*arr=(struct Cinema*)calloc(*n, sizeof(struct Cinema));
	for (int i=0;i<*n;i++){
		printf("Название фильма (без пробелов. можете использовать символ _) - \n");
		scanf("%s",(*arr)[i].name);
		printf("Цена сеанса - \n");
		scanf("%f",&(*arr)[i].price);
		printf("День сеанса (в формате дд.мм.гггг) - \n");
		scanf("%s",(*arr)[i].day);
	}
}
void search(struct Cinema*arr, int n, int searchS){
	switch(searchS){
		case 1: {
			char nameMovie[40];
			int counter1 = 0;
			printf("Название кино -\n");
			scanf("%40s", nameMovie);
			while(getchar()!='\n');
			for (int i = 0; i < n; i++){
				if(!strcasecmp(arr[i].name,nameMovie)){
					printf("%s %f %s\n", arr[i].name, arr[i].price, arr[i].day);
					counter1 = 1;
				}
			}
			if (counter1 == 0){
				printf("Ничего не найдено\n");
			}
			break;
		}
		case 2:{
			float priceMovie;
			int counter2 = 0;
                        printf("Цена сеанса -\n");
                  	scanf("%f",&priceMovie);
                        while(getchar()!='\n');
                        for (int i = 0; i < n; i++){
                                if(priceMovie == arr[i].price){
                                        printf("%s %f %s\n", arr[i].name, arr[i].price, arr[i].day);
                                        counter2 = 1;
                                }
                        }
                        if (counter2 == 0) {
                        	printf("Ничего не найдено\n");
                        }
			break;
		}
		case 3: {
			char dayS[15];
			int counter3 = 0;
			printf("День сеанса -\n");
			scanf("%s",dayS);
			for(int i = 0; i < n; i++){
				if(!strcmp(arr[i].day, dayS)){
					printf("%s %f %s\n", arr[i].name, arr[i].price, arr[i].day);
					counter3 = 1;
                                }
			}
			if (counter3 == 0) {
				printf("Ничего не найдено\n");
			}
			break;
		}
		default:
			break;
	}
}
