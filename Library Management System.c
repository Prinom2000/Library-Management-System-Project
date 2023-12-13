#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void admin_pass();
void student_pass();
void amain_menu();
void smain_menu();
void welcome();
void add_book();
void add_student();
void avew_book();
void svew_book();
void view_student();
void asearch_book();
void ssearch_book();
void edit_book();
void delete_book();
void delete_student();
void ahelp();
void shelp();
void borrow_book();
void isbook();
void rebook();
int s,a,n,bw=0,g;
int arr=0;
struct book
{
    int id;
    char name[50];
    char au[50];
    char cat[50];
    int qu;
    int r;
};
struct student
{
    int roll;
    char name[50];
    char num[15];
    int isd,ism,isy;
    int red,rem,rey;
    int fine;
};
FILE *file,*file2,*filest,*filest2;
struct book b;
struct student st;
int main()
{
    welcome();
}
void welcome()
{
    s=a=1;
    system("cls");
    printf("\n\n\t\t\t******************** Welcome To Library Project ********************\n");
    printf("\n\n\t\t\t(1) Admin Panel.\n\n\t\t\t(2) Student Panel.\n\n");
    printf("\n\n\t\t\tEnter Your Choice: ");
    scanf("%d",&n);
    while(1)
    {
        if(n==1)
        {
            admin_pass();
            break;
        }
        if(n==2)
        {
            student_pass();
            break;
        }
        else
        {
            printf("\n\t\t\tYou Entered a Wrong Choice. Please Enter Your Choice Again\n\t\t\t");
            scanf("%d",&n);
        }
    }
}
void admin_pass()
{
    if(a==1)
    {
        system("cls");
        printf("\n\n\t\t\t******************** Welcome to Admin Panel ********************");
    }
    char apass[10]= {"admin"};
    char apass1[10];
    printf("\n\n\t\t\tEnter Password: (You cannot enter wrong password more than 3 times)\n\t\t\t");
    scanf("%s",apass1);
    if(strcmp(apass,apass1)==0)
    {
        printf("\n\n\t\t\tPassword Matched.");
        printf("\n\t\t\tPress any key.....");
    }
    else
    {
        if(a==3)
        {
            printf("\n\t\t\tSorry, you have entered wrong password 3 times\n");
            welcome();
        }
        printf("\n\n\t\t\tWrong Password! %d Time to 3",a);
        printf("\n\t\t\tTry again.....");
        a++;
        admin_pass();
    }
    amain_menu();
}
void student_pass()
{
    if(s==1)
    {
        system("cls");
        printf("\n\n\t\t\t********************Welcome to Student Panel ********************");
    }
    char apass[10]= {"student"};
    char apass1[10];
    printf("\n\n\t\t\tEnter Password: (You cannot enter wrong password more than 3 times)\n\t\t\t");
    scanf("%s",apass1);
    if(strcmp(apass,apass1)==0)
    {
        printf("\n\n\t\t\tPassword Matched.");
        printf("\n\t\t\tPress any key.....");
    }
    else
    {
        if(s==3)
        {
            printf("\n\t\t\tSorry, you have entered wrong password 3 times\n");
            welcome();
        }
        printf("\n\n\t\t\tWrong Password! %d Time to 3",s);
        printf("\n\t\t\tTry again.....");
        s++;
        student_pass();
    }
    smain_menu();

}
void amain_menu()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Admin Panel <=\n\t\t\t******************** Main Menu ********************\n");
    printf("\n\n\t\t\t1.Add Book");
    printf("\n\t\t\t2.View Book List");
    printf("\n\t\t\t3.Search Book");
    printf("\n\t\t\t4.Edit Book");
    printf("\n\t\t\t5.Delete Book");
    printf("\n\t\t\t6.Add Student");
    printf("\n\t\t\t7.View Student List");
    printf("\n\t\t\t8.Delete Student");
    printf("\n\t\t\t9.Help");
    printf("\n\t\t\t10.Exit");
    printf("\n\n\t\t\t=> Enter Your choice: ");
    int ac=0;
    scanf("%d",&ac);
    if(ac==1)
    {
        add_book();
    }
    if(ac==2)
    {
        avew_book();
    }
    if(ac==3)
    {
        asearch_book();
    }
    if(ac==4)
    {
        edit_book();
    }
    if(ac==5)
    {
        delete_book();
    }
    if(ac==6)
    {
        add_student();
    }
    if(ac==7)
    {
        view_student();
    }
    if(ac==8)
    {
        delete_student();
    }
    if(ac==9)
    {
        ahelp();
    }
    if(ac==10)
    {
        welcome();
    }
    else
    {
        printf("\n\n\t\t\tYou Entered a Wrong choice. Press Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        amain_menu();
    }

}
void smain_menu()
{
    system("cls");
    printf("\n\n\t\t\t\t\t =>Student Panel <=\n\t\t\t******************** Main Menu ********************\n");
    printf("\n\n\t\t\t1.View Book");
    printf("\n\t\t\t2.Search Book");
    printf("\n\t\t\t3.Borrow Book");
    printf("\n\t\t\t4.Help");
    printf("\n\t\t\t5.Exit");
    printf("\n\n\t\t\t=> Enter Your choice: ");
    int sc=0;
    scanf("%d",&sc);
    if(sc==1)
    {
        svew_book();
    }
    if(sc==2)
    {
        ssearch_book();
    }
    if(sc==3)
    {
        borrow_book();
    }
    if(sc==4)
    {
        shelp();
    }
    if(sc==5)
    {
        welcome();
    }
    else
    {
        printf("\n\n\t\t\tYou Entered a Wrong choice. Press Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        smain_menu();
    }
}
void add_book()
{
    system("cls");
    int c=0,d=0;
    printf("\n\n\t\t\t\t\t  => Admin Panel <=");
    printf("\n\n\t\t\t******************** Add Book ********************\n");
    file=fopen("book.txt","ab+");
    printf("\n\n\t\t\tEnter Book ID: ");
    fflush(stdin);
    scanf("%d",&d);
    rewind(file);
    while(fread(&b,sizeof(b),1,file)==1)
    {
        if(d==b.id)
        {
            printf("\n\n\t\t\tThis book is already in Library...");
            c=1;
        }
    }
    if(c==1)
    {
        printf("\n\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        amain_menu();
    }
    else
    {
        b.id=d;
    }
    printf("\n\t\t\tEnter Book Name: ");
    fflush(stdin);
    gets(b.name);
    printf("\n\t\t\tEnter Author Name: ");
    fflush(stdin);
    gets(b.au);
    printf("\n\t\t\tEnter Quantity: ");
    fflush(stdin);
    scanf("%d",&b.qu);
    printf("\n\t\t\tEnter Book Category: ");
    fflush(stdin);
    gets(b.cat);
    printf("\n\t\t\tEnter Rack: ");
    fflush(stdin);
    scanf("%d",&b.r);
    fseek(file,0,SEEK_END);
    fwrite(&b,sizeof(b),1,file);
    fclose(file);
    printf("\n\n\t\t\tBook Added Successfully!");
    printf("\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    amain_menu();

}
void avew_book()
{
    system("cls");
    int c=0;
    printf("\n\n\t\t\t\t\t  => Admin Panel <=");
    printf("\n\n\t\t\t******************** View Book List ********************\n\n");
    printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
    file=fopen("book.txt","rb");
    while(fread(&b,sizeof(b),1,file)==1)
    {
        printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
        c=c+b.qu;
    }
    printf("\n\t\t\tTotal Books: %d\n",c);
    fclose(file);
    printf("\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    amain_menu();

}
void svew_book()
{
    system("cls");
    int c=0;
    printf("\n\n\t\t\t\t\t  => Student Panel <=");
    printf("\n\n\t\t\t******************** View Book List ********************\n");
    printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
    file=fopen("book.txt","rb");
    while(fread(&b,sizeof(b),1,file)==1)
    {
        printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
        c=c+b.qu;
    }
    fclose(file);
    printf("\n\t\t\tTotal Books: %d\n",c);
    printf("\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    smain_menu();
}
void asearch_book()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Admin Panel <=");
    printf("\n\n\t\t\t******************** Search Book ********************\n\n");
    printf("\t\t\t1. Search by Book ID\n");
    printf("\t\t\t2. Search by Book Name\n");
    printf("\t\t\t3. Search by Author Name\n");
    printf("\t\t\t4. Search by Book Category\n");
    printf("\t\t\t5. Main Menu\n");
    printf("\n\n\t\t\t=> Enter Your choice: ");
    int ac=0,d,c=0;
    scanf("%d",&ac);
    if(ac==1)
    {
        system("cls");
        file=fopen("book.txt","rb");
        printf("\n\n\t\t\t Enter Book Id: ");
        scanf("%d",&d);
        while(fread(&b,sizeof(b),1,file)==1)
        {
            if(d==b.id)
            {
                printf("\n\t\t\tBook is found!...\n\n");
                printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                c=1;
            }
            fclose(file);
        }
        if(c==0)
        {
            printf("\n\t\t\tSorry book is not found!...\n");
        }
        fclose(file);
        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        amain_menu();
    }
    if(ac==2)
    {
        system("cls");
        file=fopen("book.txt","rb");
        printf("\n\n\t\t\t Enter Book Name: ");
        char st[50];
        fflush(stdin);
        gets(st);
        while(fread(&b,sizeof(b),1,file)==1)
        {
            if(strcmp(st,b.name)==0)
            {
                if(c==0)
                {
                    printf("\n\t\t\tBook is found!...\n\n");
                    printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                }
                printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                c=1;
            }
        }
        if(c==0)
        {
            printf("\n\t\t\tSorry book is not found!...\n");
        }
        fclose(file);
        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        amain_menu();
    }
    if(ac==3)
    {
        system("cls");
        file=fopen("book.txt","rb");
        printf("\n\n\t\t\t Enter Author Name: ");
        char st[50];
        fflush(stdin);
        gets(st);
        while(fread(&b,sizeof(b),1,file)==1)
        {
            if(strcmp(st,b.au)==0)
            {
                if(c==0)
                {
                    printf("\n\t\t\tBook is found!...\n\n");
                    printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                }
                printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                c=1;
            }
        }
        if(c==0)
        {
            printf("\n\t\t\tSorry book is not found!...\n");
        }
        fclose(file);
        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        amain_menu();
    }
    if(ac==4)
    {
        system("cls");
        file=fopen("book.txt","rb");
        printf("\n\n\t\t\t Enter Book Category: ");
        char st[50];
        fflush(stdin);
        gets(st);
        while(fread(&b,sizeof(b),1,file)==1)
        {
            if(strcmp(st,b.cat)==0)
            {
                if(c==0)
                {
                    printf("\n\t\t\tBook is found!...\n\n");
                    printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                }
                printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                c=1;
            }
        }
        if(c==0)
        {
            printf("\n\t\t\tSorry book is not found!...\n");
        }
        fclose(file);
        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        amain_menu();
    }
    if(ac==5)
    {
        amain_menu();
    }
}
void ssearch_book()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Student Panel <=");
    printf("\n\n\t\t\t******************** Search Book ********************\n\n");
    printf("\t\t\t1. Search by Book ID\n");
    printf("\t\t\t2. Search by Book Name\n");
    printf("\t\t\t3. Search by Author Name\n");
    printf("\t\t\t4. Search by Book Category\n");
    printf("\t\t\t5. Main Menu\n");
    printf("\n\n\t\t\t=> Enter Your choice: ");
    int ac=0,d,c=0;
    scanf("%d",&ac);
    if(ac==1)
    {
        system("cls");
        file=fopen("book.txt","rb");
        printf("\n\n\t\t\t Enter Book Id: ");
        scanf("%d",&d);
        while(fread(&b,sizeof(b),1,file)==1)
        {
            if(d==b.id)
            {
                printf("\n\t\t\tBook is found!...\n\n");
                printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                c=1;
            }
        }
        if(c==0)
        {
            printf("\n\t\t\tSorry book is not found!...\n");
        }
        fclose(file);
        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        smain_menu();
    }
    if(ac==2)
    {
        system("cls");
        file=fopen("book.txt","rb");
        printf("\n\n\t\t\t Enter Book Name: ");
        char st[50];
        fflush(stdin);
        gets(st);
        while(fread(&b,sizeof(b),1,file)==1)
        {
            if(strcmp(st,b.name)==0)
            {
                if(c==0)
                {
                    printf("\n\t\t\tBook is found!...\n\n");
                    printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                }
                printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                c=1;
            }
        }
        if(c==0)
        {
            printf("\n\t\t\tSorry book is not found!...\n");
        }
        fclose(file);
        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        smain_menu();
    }
    if(ac==3)
    {
        system("cls");
        file=fopen("book.txt","rb");
        printf("\n\n\t\t\t Enter Author Name: ");
        char st[50];
        fflush(stdin);
        gets(st);
        while(fread(&b,sizeof(b),1,file)==1)
        {
            if(strcmp(st,b.au)==0)
            {
                if(c==0)
                {
                    printf("\n\t\t\tBook is found!...\n\n");
                    printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                }
                printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                c=1;
            }
        }
        if(c==0)
        {
            printf("\n\t\t\tSorry book is not found!...\n");
        }
        fclose(file);
        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        smain_menu();
    }
    if(ac==4)
    {
        system("cls");
        file=fopen("book.txt","rb");
        printf("\n\n\n\t\t\t Enter Book Category: ");
        char st[50];
        fflush(stdin);
        gets(st);
        while(fread(&b,sizeof(b),1,file)==1)
        {
            if(strcmp(st,b.cat)==0)
            {
                if(c==0)
                {
                    printf("\n\t\t\tBook is found!...\n\n");
                    printf("\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                }
                printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                c=1;
            }
        }
        if(c==0)
        {
            printf("\n\t\t\tSorry book is not found!...\n");
        }
        fclose(file);
        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        smain_menu();
    }
    if(ac==5)
    {
        smain_menu();
    }
}
void edit_book()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Admin Panel <=");
    printf("\n\n\t\t\t******************** Edit Book ********************\n\n");
    file=fopen("book.txt","rb+");
    int d,c=0;
    printf("\n\t\t\tEnter Book ID to Edit: ");
    scanf("%d",&d);
    while(fread(&b,sizeof(b),1,file)==1)
    {
        if(d==b.id)
        {
            printf("\n\n\t\t\tBook is Available!...");
            printf("\n\n\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
            printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
            printf("\n\n\t\t\tEnter New Book Name: ");
            fflush(stdin);
            gets(b.name);
            printf("\n\t\t\tEnter New Author Name: ");
            gets(b.au);
            printf("\n\t\t\tEnter New Quantity: ");
            scanf("%d",&b.qu);
            printf("\n\t\t\tEnter New Book Category: ");
            fflush(stdin);
            gets(b.cat);
            printf("\n\t\t\tEnter New Rack: ");
            scanf("%d",&b.r);
            fseek(file,ftell(file)-sizeof(b),0);
            fwrite(&b,sizeof(b),1,file);
            fclose(file);
            printf("\n\n\t\t\tBook Edited Successfully!...");
            c=1;
        }
    }
    if(c==0)
    {
        printf("\n\n\t\t\tBook is not found!...");
    }
    printf("\n\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    amain_menu();
}
void delete_book()
{
    system("cls");

    printf("\n\n\t\t\t\t\t  => Admin Panel <=");
    printf("\n\n\t\t\t******************** Delete Book ********************\n");
    printf("\n\n\t\t\t1. Delete Manually.");
    printf("\n\t\t\t2. Delete All Books.");
    printf("\n\n\t\t\t=> Enter Your choice: ");
    int x;
    scanf("%d",&x);

    if(x==1)
    {
        system("cls");
        printf("\n\n\t\t\t\t\t  => Admin Panel <=");
        printf("\n\n\t\t\t******************** Delete Book ********************\n");

        int d,c=0;
        printf("\n\t\t\tEnter Book ID to Delete: ");
        scanf("%d",&d);
        file=fopen("book.txt","rb+");
        rewind(file);
        while(fread(&b,sizeof(b),1,file)==1)
        {
            if(d==b.id)
            {
                printf("\a\n\n\t\t\tBook is Available!...");
                printf("\n\n\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                c=1;
            }
        }
        if(c==0)
        {
            printf("\n\n\t\t\tBook is not found!...");
        }
        else
        {
            file2=fopen("delete.txt","ab+");

            rewind(file);
            while(fread(&b,sizeof(b),1,file)==1)
            {
                if(d!=b.id)
                {
                    fseek(file2,ftell(file2)-sizeof(b),0);
                    ///  rewind(file2);
                    fwrite(&b,sizeof(b),1,file2);
                }
            }
            fclose(file);
            fclose(file2);

            remove("book.txt");
            rename("delete.txt","book.txt");

            file=fopen("book.txt","rb");
            fclose(file);
            printf("\n\n\t\t\tThe book (ID = %d) has been successfully deleted\n",d);
        }

        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        amain_menu();
    }
    if(x==2)
    {
        system("cls");
        printf("\n\n\t\t\t\t\t  => Admin Panel <=");
        printf("\n\n\t\t\t******************** Delete Book ********************\n");
        printf("\a\n\n\t\t\tWarning!!!...");
        printf("\n\t\t\tDo you really want to delete all the books?");
        int y;
        printf("\n\n\t\t\t1. Yes I Want");
        printf("\n\n\t\t\t2. No");
        printf("\n\n\t\t\t=> Enter Your choice: ");
        scanf("%d",&y);
        if(y==1)
        {
            file=fopen("book.txt","rb+");
            file2=fopen("delete.txt","ab+");
            fclose(file);
            fclose(file2);
            remove("book.txt");
            rename("delete.txt","book.txt");
            file=fopen("book.txt","rb");
            fclose(file);
            printf("\n\n\t\t\tAll books have been successfully deleted\n");
            printf("\n\t\t\tPress Enter key to open main menu again.");
            fflush(stdin);
            getchar();
            amain_menu();
        }
        if(y==2)
        {

            printf("\n\n\t\t\tPress Enter key to open main menu again.");
            fflush(stdin);
            getchar();
            amain_menu();
        }
    }

}
void ahelp()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Admin Panel <=");
    printf("\n\n\t\t\t******************** Help Desk ********************\n");
    printf("\n\t\t\t-> Password is: admin.");
    printf("\n\t\t\t-> From 'Main menu' You can see all feature.");
    printf("\n\t\t\t-> From 'Main menu' You can Add Books.");
    printf("\n\t\t\t-> From 'Main menu' You can View Books.");
    printf("\n\t\t\t-> From 'Main menu' You can Edit Books.");
    printf("\n\t\t\t-> From 'Main menu' You can Search Books.");
    printf("\n\t\t\t-> From 'Main menu' You can Delete Books.");
    printf("\n\t\t\t-> From 'Main menu' You can Add Student.");
    printf("\n\t\t\t-> From 'Main menu' You can View Student.");
    printf("\n\t\t\t-> From 'Main menu' You can Delete Student.");
    printf("\n\n\t\t\t\t\t-> Thank You <-");
    printf("\n\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    amain_menu();

}
void shelp()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Student Panel <=");
    printf("\n\n\t\t\t******************** Help Desk ********************\n");
    printf("\n\t\t\t-> Password is: student.");
    printf("\n\t\t\t-> From 'Main menu' You can see all feature.");
    printf("\n\t\t\t-> From 'Main menu' You can View Books.");
    printf("\n\t\t\t-> From 'Main menu' You can Search Books.");
    printf("\n\t\t\t-> From 'Main menu' You can Borrow Books.");
    printf("\n\n\t\t\t\t\t-> Thank You <-");
    printf("\n\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    smain_menu();

}
void borrow_book()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Student Panel <=");
    printf("\n\n\t\t\t******************** Borrow Book ********************\n");
    printf("\n\n\t\t\t1. Issue Book");
    printf("\n\n\t\t\t2. Return Book");
    printf("\n\n\t\t\t=> Enter Your choice: ");
    int m;
    scanf("%d",&m);

    if(m==1)
    {
        isbook();
    }
    if(m==2)
    {
        rebook();
    }
    else
    {
        printf("\n\n\t\t\tYou Entered a Wrong choice. Press Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        smain_menu();
    }

}

void add_student()
{
    system("cls");
    int c=0,d=0;
    printf("\n\n\t\t\t\t\t  => Admin Panel <=");
    printf("\n\n\t\t\t******************** Add Student ********************\n");
    filest=fopen("st.txt","ab+");
    printf("\n\n\t\t\tEnter Roll No: ");
    fflush(stdin);
    scanf("%d",&d);
    rewind(file);
    while(fread(&st,sizeof(st),1,filest)==1)
    {
        if(d==st.roll)
        {
            printf("\n\n\t\t\tThis student is already in Library...");
            c=1;
        }
    }
    if(c==1)
    {
        printf("\n\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        amain_menu();
    }
    else
    {
        st.roll=d;
    }
    printf("\n\t\t\tEnter Student Name: ");
    fflush(stdin);
    gets(st.name);
    printf("\n\t\t\tEnter Student Contact Number: ");
    fflush(stdin);
    gets(st.num);
    st.isd=st.ism=st.isy=st.red=st.rem=st.rey=st.fine=0;

    fseek(filest,0,SEEK_END);
    fwrite(&st,sizeof(st),1,filest);
    fclose(filest);
    printf("\n\n\t\t\tStudent Added Successfully!");
    printf("\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    amain_menu();

}
void delete_student()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Admin Panel <=");
    printf("\n\n\t\t\t******************** Delete Student ********************\n");
    printf("\n\n\t\t\t1. Delete Manually.");
    printf("\n\t\t\t2. Delete All Students.");
    printf("\n\n\t\t\t=> Enter Your choice: ");
    int x;
    scanf("%d",&x);
    if(x==1)
    {
        system("cls");
        printf("\n\n\t\t\t\t\t  => Admin Panel <=");
        printf("\n\n\t\t\t******************** Delete Student ********************\n");
        int d,c=0;
        printf("\n\t\t\tEnter Student Roll to Delete: ");
        scanf("%d",&d);
        filest=fopen("st.txt","rb+");
        rewind(filest);
        while(fread(&st,sizeof(st),1,filest)==1)
        {
            if(d==st.roll)
            {
                printf("\n\n\t\t\tThe Student is Available!...\n\n");
                printf("\t\t\tRoll\t\tName\t\t\tC.Number\t\tIssue Date\t    Return Date         Fine\n\n");
                printf("\t\t\t%-12d\t%-20s\t%-24s%-2d-%-2d-%-16d%-2d-%-2d-%-16d%d\n",st.roll,st.name,st.num,st.isd,st.ism,st.isy,st.red,st.rem,st.rey,st.fine);
                c=1;
            }
        }
        if(c==0)
        {
            printf("\n\n\t\t\tThe Student is not found!...");
        }
        else
        {
            filest2=fopen("del.txt","ab+");

            rewind(filest);
            while(fread(&st,sizeof(st),1,filest)==1)
            {
                if(d!=st.roll)
                {
                    fseek(filest2,ftell(filest2)-sizeof(st),0);
                    ///rewind(filest2);
                    fwrite(&st,sizeof(st),1,filest2);
                }
            }
            fclose(filest);
            fclose(filest2);

            remove("st.txt");
            rename("del.txt","st.txt");

            filest=fopen("st.txt","rb");
            fclose(filest);
            printf("\n\n\t\t\tThe Student (Roll = %d) has been successfully deleted\n",d);
        }

        printf("\n\t\t\tPress Enter key to open main menu again.");
        fflush(stdin);
        getchar();
        amain_menu();
    }
    if(x==2)
    {
        system("cls");
        printf("\n\n\t\t\t\t\t  => Admin Panel <=");
        printf("\n\n\t\t\t******************** Delete student ********************\n");
        printf("\n\n\t\t\tWarning!!!...");
        printf("\n\t\t\tDo you really want to delete all the students?");
        int y;
        printf("\n\n\t\t\t1. Yes I Want");
        printf("\n\n\t\t\t2. No");
        printf("\n\n\t\t\t=> Enter Your choice: ");
        scanf("%d",&y);
        if(y==1)
        {
            filest=fopen("st.txt","rb+");
            filest2=fopen("del.txt","ab+");
            fclose(filest);
            fclose(filest2);
            remove("st.txt");
            rename("del.txt","st.txt");
            filest=fopen("st.txt","rb");
            fclose(filest);
            printf("\n\n\t\t\tAll Students have been successfully deleted\n");
            printf("\n\t\t\tPress Enter key to open main menu again.");
            fflush(stdin);
            getchar();
            amain_menu();
        }
        if(y==2)
        {

            printf("\n\n\t\t\tPress Enter key to open main menu again.");
            fflush(stdin);
            getchar();
            amain_menu();
        }
    }


}
void view_student()
{
    system("cls");
    int c=0;
    printf("\n\n\t\t\t\t\t  => Admin Panel <=");
    printf("\n\n\t\t\t******************** View Student List ********************\n\n");
    printf("\t\t\tRoll\t\tName\t\t\tC.Number\t\tIssue Date\t    Return Date         Fine\n\n");
    filest=fopen("st.txt","rb");
    while(fread(&st,sizeof(st),1,filest)==1)
    {
        printf("\t\t\t%-12d\t%-20s\t%-24s%2d-%2d-%-16d%2d-%2d-%-12d%d\n",st.roll,st.name,st.num,st.isd,st.ism,st.isy,st.red,st.rem,st.rey,st.fine);
        c++;
    }
    printf("\n\t\t\tTotal Student is: %d\n",c);
    fclose(filest);
    printf("\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    amain_menu();
}

void isbook()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Student Panel <=");
    printf("\n\n\t\t\t******************** Borrow Book ********************\n");
    printf("\n\t\t\t******************** Issue Book ********************\n");
    printf("\n\n\t\t\tEnter Your Roll: ");
    int r,t,l=0,p=0;
    scanf("%d",&r);
    filest=fopen("st.txt","rb+");
    while(fread(&st,sizeof(st),1,filest)==1)
    {
        if(r==st.roll)
        {
            g=1;
            if(st.isd!=0)
            {
                printf("\n\n\t\t\tYou borrowed a book before. Now you can't borrow books again.\n\t\t\t\tYou have to return the previous book.\n");
            }
            if(st.isd==0)
            {
                printf("\n\n\t\t\tYou Available in Library!...\n\n");
                printf("\t\t\tRoll\t\tName\t\t\tC.Number\t\tIssue Date\t    Return Date         Fine\n\n");
                printf("\t\t\t%-12d\t%-20s\t%-24s%d-%d-%-16d%d-%d-%-16d%d\n",st.roll,st.name,st.num,st.isd,st.ism,st.isy,st.red,st.rem,st.rey,st.fine);
                l=1;


                int isd,ism,isy;
                printf("\n\t\t\tEnter Issue Date:\n");
                printf("\t\t\tdd: ");
                scanf("%d",&isd);
                printf("\t\t\tmm: ");
                scanf("%d",&ism);
                printf("\t\t\tyy: ");
                scanf("%d",&isy);
                st.isd=isd;
                st.ism=ism;
                st.isy=isy;
                st.red=0;
                st.rem=0;
                st.rey=0;
                fseek(filest,ftell(filest)-sizeof(st),0);
                fwrite(&st,sizeof(st),1,filest);
                fclose(filest);
                printf("\n\t\t\tYour issue date is: %d-%d-%d",st.isd,st.ism,st.isy);
                printf("\n\n\t\t\tEnter Book Id: ");

                file=fopen("book.txt","rb+");
                scanf("%d",&t);
                while(fread(&b,sizeof(b),1,file)==1)
                {
                    if(t==b.id)
                    {
                        p=1;
                        printf("\n\n\t\t\tBook is Available!...");
                        printf("\n\n\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                        printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);
                        if(b.qu>9)
                        {
                            printf("\n\n\t\t\tYou borrowed this book.\n");
                            b.qu=b.qu-1;
                            fseek(file,ftell(file)-sizeof(b),0);
                            fwrite(&b,sizeof(b),1,file);
                            fclose(file);
                        }
                        else
                        {
                            printf("\n\n\t\t\tNot Enough Book. \n\t\t\tThere are less than ten books in the library. You can not borrow this book.\n");
                        }
                    }
                }
            }
        }
    }
    if(l==0 && g==0)
    {
        printf("\n\n\t\t\tYou Are Not Available in Library!...");
    }
    if(p==0 && g==0)
    {
        printf("\n\n\t\t\tBook is not found!...");
    }
    printf("\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    smain_menu();
}
void rebook()
{
    system("cls");
    printf("\n\n\t\t\t\t\t  => Student Panel <=");
    printf("\n\n\t\t\t******************** Borrow Book ********************\n");
    printf("\n\t\t\t******************** Return Book ********************\n");
    printf("\n\n\t\t\tEnter Your Roll: ");
    int r,t,l=0,p=0,s=0;
    scanf("%d",&r);
    filest=fopen("st.txt","rb+");
    while(fread(&st,sizeof(st),1,filest)==1)
    {
        if(r==st.roll)
        {

            printf("\n\n\t\t\tYou Available in Library!...\n\n");
            printf("\t\t\tRoll\t\tName\t\t\tC.Number\t\tIssue Date\t    Return Date         Fine\n\n");
            printf("\t\t\t%-12d\t%-20s\t%-24s%d-%d-%-16d%d-%d-%-16d%d\n",st.roll,st.name,st.num,st.isd,st.ism,st.isy,st.red,st.rem,st.rey,st.fine);
            l=1;
            bw=0;
            int red,rem,rey;
            printf("\n\t\t\tEnter Return Date:\n");
            printf("\t\t\tdd: ");
            scanf("%d",&red);
            printf("\t\t\tmm: ");
            scanf("%d",&rem);
            printf("\t\t\tyy: ");
            scanf("%d",&rey);
            st.red=red;
            st.rem=rem;
            st.rey=rey;
            int bad=st.rem-st.ism;

            int arr[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
            int lp=st.rey%4;
            if(lp==0)
            {
                arr[2]=29;
            }
            int m=st.ism;
            int din=arr[m];
            int con;
            if(din==29)
            {
                con=22;
            }
            if(din==30)
            {
                con=23;
            }
            if(din==28)
            {
                con=21;
            }
            if(din==31)
            {
                con=24;
            }
            if(st.isd>con && st.ism!=st.rem)
            {
                int a1=din-st.isd;
                int a2=a1+st.red;
                if(a2>7)
                {
                    int a3=a2-7;
                    st.fine=30*a3;
                }
                else
                {
                    st.fine=0;
                }
            }
            if(st.isd<=con && st.ism!=st.rem)
            {
                int a1=din-st.isd;
                int a2=a1+st.red;
                if(a2>7)
                {
                    int a3=a2-7;
                    st.fine=30*a3;
                }
                else
                {
                    st.fine=0;
                }

            }
            if(st.isd<=con && st.ism==st.rem)
            {

                int a2=st.red-st.isd;
                if(a2>7)
                {
                    int a3=a2-7;
                    st.fine=30*a3;
                }
                else
                {
                    st.fine=0;
                }
            }
            fseek(filest,ftell(filest)-sizeof(st),0);
            fwrite(&st,sizeof(st),1,filest);
            fclose(filest);
            printf("\n\t\t\tYour return date is: %d-%d-%d",st.red,st.rem,st.rey);
            printf("\n\n\t\t\tEnter Book Id: ");

            file=fopen("book.txt","rb+");
            scanf("%d",&t);
            while(fread(&b,sizeof(b),1,file)==1)
            {
                if(t==b.id)
                {
                    p=1;
                    printf("\n\n\t\t\tYou are returning this book...");
                    printf("\n\n\t\t\tID\t\tName\t\t\tAuthor\t\t\tQuantity\tCategory\t Rack\n\n");
                    printf("\t\t\t%-12d\t%-20s\t%-24s%-16d%-16s%d\n",b.id,b.name,b.au,b.qu,b.cat,b.r);

                    b.qu=b.qu+1;
                    fseek(file,ftell(file)-sizeof(b),0);
                    fwrite(&b,sizeof(b),1,file);
                    fclose(file);
                }
            }
        }
    }
    if(p==0)
    {
        printf("\n\n\t\t\tBook is not found!...");
    }
    if(l==0)
    {
        printf("\n\n\t\t\tYou Are Not Available in Library!...");
    }
    printf("\n\t\t\tPress Enter key to open main menu again.");
    fflush(stdin);
    getchar();
    smain_menu();
}

