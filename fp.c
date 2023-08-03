
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct bookinginfo{
	char areaname[50];
	int price;
};
struct booking{
	char username[50];
	int bookinginfoid;
};
int rendermenu();
void info(struct bookinginfo []);
void reservation(struct booking [],int *ptr );
void details(struct booking [],int);
void resetscreen();
int rendermenu()
{
	system("cls");
	printf("\t\t**************************************\n");
	printf(" \t\t  WELCOME TO BUS RESERVATION SYSTEM\n");
	printf("\t\t**************************************");
	printf("\n\nPRESS [1] FOR TICKETS INFORMATION\n");
	printf("PRESS [2] FOR TICKET RESERVATION\n");
	printf("PRESS [3] FOR BOOKING DETAILS\n");
	printf("PRESS [4] TO EXIT\n");
}
void info(struct bookinginfo inf[])
{
	system ("cls");
	int i;
    printf("=================AREA INFORMATION================\n\n");
	for(i=0;i<6;i++)
	printf("Area id: %d, LOCATION: %s, PRICE: %d\n",i+1,inf[i].areaname,inf[i].price);
}

void reservation(struct booking ptr[],int *currentbooking)
{
	if(*currentbooking==10){
		printf("\nSORRY, ALL SEATS HAVE BEEN RESERVED");
		resetscreen();
		return;
	}

	char username[50];
	int areaid;
	printf("\n\n============INFO FOR SEAT RESERVATION============\n");
	printf("\nENTER USERNAME: ");
	scanf("%s",&username);
	printf("Enter AREA ID: ");
	scanf("%d",&areaid);
	strcpy(ptr[*currentbooking].username,username);
	ptr[*currentbooking].bookinginfoid=areaid;
	*currentbooking+=1;
	system("cls");
	printf("CONGRATULATIONS! YOUR RIDE WITH NAME: %s HAS BEEN BOOKED SUCCESSFULLY",username);
	resetscreen();
	
}
void details(struct booking bk[],int currentbookings)
{	int i;
system("cls");
if(currentbookings==0)
{
	printf("NO BOOKINGS FOUND...");
}
	for(i=0;i<currentbookings;i++){
		printf("USERNAME: %s, AREA ID: %d\n",bk[i].username,bk[i].bookinginfoid);
	}
	resetscreen();
}
void resetscreen(){
	printf("\n\nPRESS ANY KEY TO CONTINUE...");
	getch();
	system("cls");
}
int main()
{	
	int opt;
	int currentbooking=0;
	
	struct bookinginfo s1[6];
	struct booking b1[10];
	strcpy(s1[0].areaname,"DHA");
	s1[0].price=600;
	strcpy(s1[1].areaname,"SADDAR");
	s1[1].price=500;
	strcpy(s1[2].areaname,"KARSAZ");
	s1[2].price=400;
	strcpy(s1[3].areaname,"BAHADURABAD");
	s1[3].price=450;
	strcpy(s1[4].areaname,"BUFFERZONE");
	s1[4].price=200;
	strcpy(s1[5].areaname,"JOHAR");
	s1[5].price=300;
	strcpy(s1[6].areaname,"GULSHAN");
	s1[6].price=150;
	while(1){
		rendermenu();
		scanf("%d",&opt);
		switch (opt)
		{
			case 1:
			info(s1);
			resetscreen();
			break;
			
			case 2:
			
				info(s1);
				reservation(b1,&currentbooking);
			
			break;
			
			case 3:
			details(b1,currentbooking);
			break;
			
			case 4:
			exit (0);
			
			default:
			printf("INVALID OPTION");	
		}
	}
	
	
}



