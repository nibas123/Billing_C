#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
int read();
void write();
void update();
void billing();
void leave();
typedef struct
{
    int id;
    char item[30];
    int price,qty;

}stock;

typedef struct
{
    int idd;
    char itemm[40];
    int qtyy, pricee;

}bill;

stock st,*rst;
bill *b;
int bsize=0;

main()
{

	printf("\------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t+-------------------------------------------------------------------------------------------------------+\n");
	printf("\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("\t|\t\t\t\t==================================\t\t\t\t\t|\n");
	printf("\t|\t\t\t\t|\t     WELCOME TO \t |\t\t\t\t\t|\n");
	printf("\t|\t\t\t\t|\t UC  SUPERMARKET \t |\t\t\t\t\t|\n");
	printf("\t|\t\t\t\t==================================\t\t\t\t\t|\n");
    printf("\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("\t+-------------------------------------------------------------------------------------------------------+\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
	int ch;

    while(1)
    {
        printf("\t\t\t\t\tx=====================================x\t\t\t\t\t");
        printf("\n\t\t\t\t\t|\tPress <1>  Write Records      |");
        printf("\n\t\t\t\t\t|\tPress <2>  Read Records       |");
        printf("\n\t\t\t\t\t|\tPress <3>  Update Records     |");
        printf("\n\t\t\t\t\t|\tPress <4>  Generate a Bill    |");
        printf("\n\t\t\t\t\t|\tPress <5>  Exit               |");
        printf("\n\t\t\t\t\tx=====================================x");
        printf("\n\t\t\t\t\t  Enter Your Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:write();
					break;
            case 2:read();
            		break;
            case 3:update();
            		break;
            case 4:billing();
                   break;
            case 5:leave();
                   break;
            default:printf("\n\tOption not Available\n");
        }
    }
	getch();
}
void write()
{

	int i,n=0,f;
	FILE *fp=fopen("stu.txt","a+");
    int l=read();
    f=l;
    if(fp==NULL)
    {
        printf("can't create file");
        getch();
        exit(1);
    }

    printf("\n\tHow Many Records You Want to Enter:=");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n\tPlease Enter Item for ID : %d \n",f+1);
        st.id=++f;
        fflush(stdin);
        printf("\n\tEnter Item Name := ");
        gets(st.item);
        printf("\n\tEnter the Quantity := ");
        scanf("%d",&st.qty);
        printf("\n\tEnter the Price := ");
        scanf("%d",&st.price);
        printf("\n\t**********Item %s Added Successfully!!**********",st.item);
        printf("\n\tx#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-x\n");
        fwrite(&st,sizeof(stock),1,fp);

         }
    fclose(fp);
}
int read()
{
	int len,i;
	FILE *fp=fopen("stu.txt","r");
	  if(fp==NULL)
    {
        printf("can't create file");
        getch();
        exit(1);
    }

	fseek(fp,0,SEEK_END);
	len=ftell(fp);
	len=len/sizeof(stock);
	rewind(fp);

	//printf("len = %d",len);
	rst=(stock *)malloc(len*sizeof(stock));

	fread(rst,sizeof(stock),len,fp);

    puts("\n\t\t\t\t\t+=======================================+");
    printf("\t\t\t\t\t|%s\t%s\t\t%s\t%s\t\n", "ID","ITEM", "QTY", "PRICE\t|");
    puts("\t\t\t\t\t+=======================================+");
	for(i=0;i<len;i++)
	{
		printf("\t\t\t\t\t|%d\t%s\t\t%d\t %d\t|\n",rst[i].id,rst[i].item,rst[i].qty,rst[i].price);
	}
	puts("\t\t\t\t\t+---------------------------------------+");
    printf("\n\n");
	fclose(fp);
//	free(rst);
    //printf("\t\t\t\t\t|%d   %-8s %16d\t%12d |\n",rst[i].id,rst[i].item,rst[i].qty,rst[i].price);
	return(len);
}
void update()
{

	int len,i,q,n;
	len=read();
	FILE *fp=fopen("stu.txt","r");

	//rst=(stock *)malloc(len*sizeof(stock));

	fread(rst,sizeof(stock),len,fp);

	fclose(fp);

    printf("Product ID of the stock you want to chanage: ");
    scanf("%d",&n);

	for(i=0;i<len;i++)
	{
	    if(rst[i].id==n)
        {
            puts("\n+============================================+");
            printf("|%s\t%s\t\t%s\t%s\t\n", "ID","Item", "Qty", "Price |");
            puts("+============================================+");
        	printf("|\t\t\t\t\t|%d\t%s\t\t%d\t %d\t|\n",rst[i].id,rst[i].item,rst[i].qty,rst[i].price);
        	puts("---------------------------------------------+");
            printf("\n\tPress <1> :Change Name");
        	printf("\n\tPress <2> :Change Quantity");
        	printf("\n\tPress <3> :Change Price");
        	printf("\n\tPress <4> :Exit");
        	printf("\n\tEnter Your Choice:- ");
        	scanf("%d",&q);
        	switch(q)
        	{
            	case 1:
       				fflush(stdin);
					printf("Enter the New Name: ");
           			gets(rst[i].item);
            		break;
            	case 2:
                	printf("\nEnter the new quantity:=");
                	scanf("%d",&rst[i].qty);
                	break;

				case 3:
                	printf("\nEnter the  new price:=");
                	scanf("%d",&rst[i].price);
                	break;

            	case 4:
					exit(1);

            	default:printf("\n\tOption not Available\n");
        	}
        	printf("\n\t**********Item %s Updated successfully!!**********\n",rst[i].item);
        	break;
        }

	}

    fopen("stu.txt","w");
    fwrite(rst,sizeof(stock),len,fp);
    fclose(fp);

}
void billing()
{
	FILE *fr=fopen("stu.txt","r");
	int len,i,q,n,c;
    char ch;
    int amt=0;
    int total=0;
    int j=0;

    len=read();
    fread(rst,sizeof(stock),len,fr);
    fclose(fr);

	//printf("len = %d",len);

	b=(bill *)malloc(bsize*sizeof(bill));

	do
    {
    	b=(bill *)realloc(b,sizeof(bill)*++bsize);

        printf("\nProduct ID of the Item You want: ");
        scanf("%d",&n);

        for(i=0;i<len;i++)
        {
        	if(rst[i].id==n)
        	{
        		//b[j]=rst[i];
        		st=rst[i];
        		c=i;
        		break;
  			}
		}
        printf("\nQuantity of %s out of %d  : ",st.item,st.qty);
        scanf("%d",&q);
		//printf("%d",q);
        if(st.qty>=q)
        {

            b[j].idd=st.id;
            strcpy(b[j].itemm,st.item);
            b[j].qtyy=q;
            rst[c].qty=rst[c].qty-q;
            b[j].pricee=st.price;

           printf("\n**********You Brought %d %s/s of Rs.%d each**********\n",b[j].qtyy,b[j].itemm,b[j].pricee);
        }
        else if(st.qty==0 && st.qty<q)
        {
           printf("\n**********Stock of %s empty,Please Stock Up**********\n",b[j].itemm);
        }
        else
        {
            printf("\n**********enter a value between 0 and %d in the stock**********\n",st.qty);
        }
        if(st.qty<=2 && st.qty !=0)
        {
        	printf("\n**********Stock is low,Don't forgot To Stock Up**********\n");
        }
        j++;
        printf("\nAdd More Items [y/n]?");
        fflush(stdin);
        scanf("%c",&ch);
        puts("x-o-x-o-x-o-x-o-x-o-x-o-x-o-x-o-x-o-x-o-x-o-x-o");
    }while(ch=='y'||ch=='Y');
    //printf("%d",i);

	fopen("stu.txt","w");
	fwrite(rst,sizeof(stock),len,fr);
 	fclose(fr);
    puts("\t\t\t\t+---------------------------------------------------------------+");
	printf("\t\t\t\t\t\t\tUC SUPER MARKET\n");
    puts("\t\t\t\t+===============================================================+");
    printf("\t\t\t\t%s   %11s%15s%15s%15s\n", "No.","Item", "Qty", "Price", "Amount");
    puts("\t\t\t\t+---------------------------------------------------------------+");
    for(i=0; i<j; i++)
    {
        amt=(b[i].qtyy*b[i].pricee);
        total=total+amt;
        printf("\t\t\t\t%d %16s\t%8d\t%6d%14d\n",b[i].idd,b[i].itemm, b[i].qtyy,b[i].pricee, amt);
    }
    puts("\t\t\t\t+----------------------------------------------------------------+");


    printf("\t\t\t\tTotal Amount :\t\t\t\t\t\tRs.%d\n",total);
	puts("\t\t\t\tHappy Shopping\n");
    puts("\t\t\t\t\t\t\tVisit US Again\n");
}


void leave()
{
    char ch;
printf("\n\t\t\t\t\t\tAre You Sure [y/n]?");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y'||ch=='Y')
    {
     exit(1);
    }


}
