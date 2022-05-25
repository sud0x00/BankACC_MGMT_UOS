#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();
struct {

    char name[60];
    int acc_no,age;
    double phone;
    float amt;
    
    }add,upd,check,rem,transaction;

void new_acc()

{
    FILE *ptr;
    ptr=fopen("record.dat","a+");
    system("cls");
    printf("\t\t\t ADD RECORD  ");
    printf("\nEnter the account number:");
    scanf("%d",&add.acc_no);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    fprintf(ptr,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt);
    fclose(ptr);
    printf("\nAccount created successfully!");
    menu();
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d %s %f",&add.acc_no,add.name,&add.age,&add.phone,&add.amt)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}   
}
void edit(void)
{
    int x,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d %s %lf %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
                printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt);
                system("cls");
                printf("Changes saved!");
                }

        else
           fprintf(newrec,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

}

void transact(void)
{   int test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
}
void delete_acc(void)
{
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt);

        else
            {
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
}

void see(void)
{
    FILE *ptr;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Enter acc no \n:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d %s %f \n",add.acc_no,add.name,add.age,add.phone,add.amt)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                printf("\nAccount NO.:%d\nName:%s \nAge:%d \nPhone number:%.0lf \nAmount deposited:$ %.2f \n\n",add.acc_no,add.name,add.age,add.phone,add.amt);               
            }
        }
    }
    fclose(ptr);
}

void menu(void)
{   int choice;
    system("cls");
    printf("\n\n\t\t\tBANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t        MAIN MENU ");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:delete_acc();
        break;
        case 6:view_list();
        break;
        default:
        break;
    }
}
int main()
{
        menu();
        return 0;
}
