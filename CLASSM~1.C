#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>


//extern no = 2;

void login()
{
	int ch,no;	      //switch
	int u,p;          //login username,password
	int c,d;          //read from file
	char x[20];
	char username[20],us[20];     //username
	char password[20],ps[20];     //password
	FILE *user;
	FILE *pass;
	do
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
				case 1:
						user = fopen("u.txt","w");

						if(user==NULL)
						{
							printf("*");
						}
						else
						{
							printf("\nEnter username: ");
							scanf("%s",&username);
							fprintf(user,"%s",username);
							printf("\nUsername saved succesfully \n");
						}

						fclose(user);

						pass=fopen("p.txt","w");

						if(pass==NULL)
						{
							printf("*");
						}
						else
						{
							printf("\nEnter the password: ");
							scanf("%s",&password);

							fprintf(pass,"%s",password);
							printf("\nPassword saved succesfully \n");
						}

						fclose(pass);
						break;

				start:

				case 2:
						printf("\nEnter your username: ");
						scanf("%s",&us);
						printf("\nEnter your password: ");
						scanf("%s",&ps);

						user=fopen("u.txt","r");

						fscanf(user,"%s",username);
						fclose(user);

						pass=fopen("p.txt","r");

						fscanf(pass,"%s",password);
						fclose(pass);

						fflush(stdin);

						if(strcmp(username,us)==0 && strcmp(password,ps)==0)
						{
							printf("\nLOGIN SUCCESSFULL\n");
							sleep(2);
							clrscr();
							printf("\nRedirecting To Main Content....");
							sleep(2);

							goto s1;
						}
						else
						{
							printf("\nUsername Or Password Is Wrong...!");
							goto start;
						}
						break;

				default:
							printf("\n\nEXITING....");
							sleep(2);
							clrscr();
							printf("================================================================================");

							printf("\n \t\t\t\t THANK YOU  \n");

							printf("\n================================================================================\n");

							sleep(3);

							clrscr();

							printf("\n PRESS ANY KEY TO EXIT...");
							sleep(2);

							exit(1);
		}
	}while(ch<=2);

	s1:
		control();

}

struct student
{
	int srno;
	char name[20];
	char fees[20];

}s[5];

void insert()
{
	FILE *insert;
	FILE *fp;
	int i,no,num;
	char option[1];

	insert = fopen("record.txt","w");

	if(insert==NULL)
	{
		printf("\nRecords Not Inserted");
	}
	else
	{
		printf("\nHow many records you want?  ");
		scanf("%d",&no);
		printf("\nEnter the %d records: \n",no);

		for(i=1;i<=no;i++)
		{
			printf("\nEnter the serial no: ");
			scanf("%d",&s[i].srno);
			printf("\nEnter the %d student name:  ",i);
			scanf("%s",&s[i].name);
			printf("\nEnter the fees status: ");
			scanf("%s",&s[i].fees);
		}

	   //	fwrite(s,sizeof(struct student),5,insert);

	   for(i=1;i<=no;i++)
	   {
		 fprintf(insert,"%d  %s     %s\n",s[i].srno,s[i].name,s[i].fees);
	   }

		fclose(insert);

		clrscr();

		printf("\nRecords Inserted Successfully...! \n");

		printf("\nDo you want to add more students? [Y/N] ");
		scanf("%s",&option);

		if(option[0]=='Y' || option[0]=='y')
		{
			FILE *insert;
			insert = fopen("record.txt","a");

			printf("\nHow many new students you want to add? ");
			scanf("%d",&num);

			printf("\nEnter the new %d records: \n",num);

		/*	 for(i=1;i<=1;i++)
			{
				printf("\nLast Student Number Was: ",s.srno);
			} */

			for(i=1;i<=num;i++)
			{
				printf("\nEnter the serial no: ");
				scanf("%d",&s[i].srno);
				printf("\nEnter the %d student name:  ",i);
				scanf("%s",&s[i].name);
				printf("\nEnter the fees status: ");
				scanf("%s",&s[i].fees);
			}

		   for(i=1;i<=num;i++)
		   {
			 fprintf(insert,"%d  %s     %s\n",s[i].srno,s[i].name,s[i].fees);
		   }

			clrscr();

		   printf("\nNew Records Added Successfully...!");
		}
		else
		{
			  printf("\nTHANK YOU \n");

			  printf("\nWAIT");
			  sleep(2);
			  clrscr();
		}


	}
}

void display()
{
	FILE *insert;
	int i,c,no;

	printf("\nHow many records you want to display? ");
	scanf("%d",&no);

	printf("\n");

	insert = fopen("record.txt","r");

//	fread(s,sizeof(struct student),5,insert);

	printf("SR  NAME      FEES\n");
	printf("====================== \n");

	for(i=1;i<=no;i++)
	{
		while((c=getc(insert))!=EOF)
		{
			putchar(c);
		}
		printf("\n");
	}

	fclose(insert);
}

void search()
{
	struct student s;
	FILE *insert;
	int sn,i,ch;
	char nm[20],fee[20];

	insert = fopen("record.txt","r+");


	printf("\nHow do you want search?\n");
	printf("1.SERIAL NO\n2.NAME\n3.FEES STATUS\n");

	do
	{
		printf("\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					printf("\nEnter the serial no you want to search: ");
					scanf("%d",&sn);

					printf("\nSearching... \n");
					sleep(3);

					printf("\nSRNO NAME\t  FEES");
					printf("\n=======================");

					while(fscanf(insert,"%d %s %s",&s.srno,&s.name,&s.fees)!=EOF)
					{
						if(s.srno==sn)
						{
							printf("\n%d    %s\t %s \n",s.srno,s.name,s.fees);
						}
					}
					break;

			case 2:
						printf("\nEnter the student name you want to search: ");
						scanf("%s",&nm);

						printf("\nSearching... \n");
						sleep(3);

						printf("\nSRNO NAME\t  FEES");
						printf("\n=======================");

						while(fscanf(insert,"%d %s %s",&s.srno,&s.name,&s.fees)!=EOF)
						{
							if(s.name==nm)
							{
								printf("\n%d    %s\t %s \n",s.srno,s.name,s.fees);
							}
						}
						break;

			case 3:
					printf("\nEnter the student fees status to search: ");
					scanf("%s",&fee);

					printf("\nSearching... \n");
					sleep(3);

					printf("\nSRNO NAME\t  FEES");
					printf("\n=======================");

					while(fscanf(insert,"%d %s %s",&s.srno,&s.name,&s.fees)!=EOF)
					{
						if(s.fees==fee)
						{
							printf("\n%d    %s\t %s \n",s.srno,s.name,s.fees);
						}
					}
					break;

			default:
					printf("\nWrong Search Method...\n");
		}
	}while(ch<=3);

	fclose(insert);
}

void delet()
{
	struct student s;
	FILE *insert;   //file with existing records
	FILE *remov;	//new file
	int r;

	insert=fopen("record.txt","r");
	remov=fopen("record1.txt","w");

	printf("\nEnter the student serial no you want delete: ");
	scanf("%d",&r);

	while(!feof(insert))
	{
		fscanf(insert,"%d %s %s",&s.srno,&s.name,&s.fees);

		if(s.srno!=r)
		{
			fprintf(remov,"%d %s %s \n",s.srno,s.name,s.fees);
		}
	}

	fflush(stdin);

	printf("\nStudent Record Deleted Successfully \n");

	fclose(insert);
	fclose(remov);

	remove("record.txt");
	rename("record1.txt","record.txt");
}



int control()
{
	int ch;
	clrscr();

	printf("================================================================================");

	printf("\n \t\t\t\t MAYUR-i-TECHNOLOGIES \n");

	printf("\n================================================================================\n");

	do
	{
		printf("\n1.INSERT\n2.DISPLAY\n3.SEARCH\n4.DELETE\n5.EXIT");

		printf("\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					insert();
					break;

			case 2:
					display();
					break;

			case 3:
					search();
					break;

			case 4:
					delet();
					break;

			default:
					printf("\nEXITING...\n");
					sleep(2);

					clrscr();
					printf("\nPRESS ANY KEY TO EXIT...");

		}
	}while(ch<=4);

	return 0;
}


void main()
{
	struct date d;
	clrscr();

	printf("================================================================================");

	printf("\n \t\t\tWELCOME TO MAYUR-i-TECHNOLOGIES \n");

	printf("\n================================================================================\n");

	getdate(&d);
	printf("\t\t\t\t\t\t\t\tDATE: %d-%d-%d \n",d.da_day,d.da_mon,d.da_year);


	printf("  ____________________\n");

	printf(" |\t       \t     |\n");
	printf(" |\t1.REGISTER   |\n ");
	printf("|\t2.LOGIN\t     |\n" );
	printf(" |\t3.EXIT\t     |\n");
	printf(" |\t       \t     |\n" );
	printf("  ____________________ \n");

	login();

	getch();
}