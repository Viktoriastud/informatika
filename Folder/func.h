struct Cinema{
	char name[40];
	float price;
	char day[40];
};
void write(struct Cinema *arr, int n);
void read(struct Cinema **arr, int *n);
void create(struct Cinema **arr, int *n);
void search(struct Cinema *arr, int n, int searchS);
int errorString(int *m);
