int main()
{
	char code;
	struct part inventory[MAX_PARTS];
	int num_parts=0;
	for(;;)
	{
		printf("Enter operation code: ");
		scanf(" %c",&code);
		while (getchar()!='\n') ;
		switch (code) {
			case 'i': insert(inventory,&num_parts);break;
			case 's': search(inventory,num_parts);break;
			case 'u': update(inventory,num_parts);break;
			case 'p': print(inventory,num_parts);break;
			case 'q': return 0;
			default: printf("Illegal code\n");
		}
		printf("\n");
	}
}

void insert(struct part inv[],int* np)
{
	int pn;
	if (*np==pn) {
		printf("Database is full; can't add more parts.\n");return ;
	}
	printf("Enter part number: ");
	scanf("%d",&pn);
	if (find_part(pn)>=0) {printf("Part already exists.\n";return ;}
	inv[*np].number=pn;
	printf("Enter part name: ");
	read_line(inv[*np].name,NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d",&inv[*np].on_hand);
	*np++;
}
