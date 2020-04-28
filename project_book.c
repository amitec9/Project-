
// Book magement
//Author :- Amit kumar
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insert(FILE *fp);
void del(FILE *fp);
void modify(FILE *fp);
void booksold(FILE *fp);
void display(FILE *fp);
void list(FILE *fp);
int search(FILE *fp,char *name);
struct{
char name[50];
int ncopy;
float price;
}book;
int main(){
int choice;
FILE *fp;
fp=fopen("book.txt","rb+");

if(fp==NULL)
{
    fp=fopen("book.txt","wb+");
    if(fp==NULL)
    {
        printf("Error in opening file\n");
        exit(1);
    }
}
while(1)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);// This function used in colour in text in console| BACKGROUND_BLUE);
    printf(" __________________________\n");
    printf("|.........WELCOME..........|\n");
    printf("|Manage a Database of Books|\n");
    printf("|1.Insert a new record     |\n");
    printf("|2.Delete a record         |\n");
    printf("|3.Display a record        |\n");
    printf("|4.Modify a record         |\n");
    printf("|5.List a record           |\n");
    printf("|6.Book sold               |\n");
    printf("|7.Exit                    |\n");
    printf("|__________________________|\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        insert(fp);
        break;
    case 2:
        del(fp);
        break;
    case 3:
        display(fp);
        break;
    case 4:
        modify(fp);
        break;
    case 5:
        list(fp);
        break;

    case 6:
        booksold(fp);
        break;
    case 7:
        fclose(fp);
        exit(1);




    }
}
}

void insert(FILE *fp)
{
    fseek(fp,0,2);
    printf("Enter the Book name : ");
    scanf("%s",&book.name);
    printf("Enter number of Book copies : ");
    scanf("%d",&book.ncopy);
    printf("Enter the Book Price : ");
    scanf("%f",&book.price);
    fwrite(&book,sizeof(book),1,fp);
}


void del(FILE *fp)
{
    FILE *fptemp;
    char name[20];
    printf("Enter the of book to be deleted : ");
    scanf("%s",name);
    if(search(fp,name)==0)
        return;
    fptemp=fopen("tempfile","wb");
    rewind(fp);
    while(fread(&book,sizeof(book),1,fp)==1)
    {

        if(strcmp(name,book.name)!=0)
        {
         fwrite(&book,sizeof(book),1,fptemp);
        }


    }

    fclose(fp);
    fclose(fptemp);
    remove("book.txt");
    rename("tempfile","book.txt");
    printf("\n Record Deleted ...\n");
    fp=fopen("book.txt","rb+");


}

int search(FILE *fp,char *name){
    unsigned flag=0;
    rewind(fp);
    while(fread(&book,sizeof(book),1,fp)==1)
    {

        if(strcmp(name,book.name)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
    printf("name not found in file\n\n");

    }



return flag;




}


void list(FILE *fp)
{
    rewind(fp);
    printf("\n name \t copies \tcost \n\n");
    while(fread(&book,sizeof(book),1,fp)==1)
    {
        printf("%s\t ",book.name);
        printf("%d\t ",book.ncopy);
        printf("%f\t ",book.price);
printf("\n");
    }

}

void display(FILE *fp)
{
    char name[50];
    printf("Enter the book name :");
    scanf("%s",name);
    if(search(fp,name)==1)
    {
      printf("\n Name\t%s\n ",book.name);
        printf("Copies %d\n ",book.ncopy);
        printf("Cost %f\n\n ",book.price);
    }

}

void modify(FILE *fp)
{
  char name[50];
  long size=sizeof(book);
  printf("Enter the name the book to be modified :");
  scanf("%s",name);
  if(search(fp,name)==1)
  {
      printf("Enter new data -->\n");
      printf("Enter book name :\n");
      scanf("%s",book.name);
      printf("Enter book number of copies :\n");
      scanf("%d",&book.ncopy);
      printf("Enter book price :\n");
      scanf("%f",&book.price);
      fseek(fp,-size,1);
      fwrite(&book,sizeof(book),1,fp);
      printf("\n Record Successfuly \n\n");

  }
}


void booksold(FILE *fp)
{

    char name[50];
    long size=sizeof(book);
    printf("Enter the name the book to be Sold :");
  scanf("%s",name);
  if(search(fp,name)==1)
  {
      if(book.ncopy > 0)
      {
          book.ncopy--;
          fseek(fp,-size,1);
          fwrite(&book,sizeof(book),1,fp);
          printf("one book sold\n");
          printf("now Number of copies =%d\n",book.ncopy);

      }
      else{
        printf("Book is out of stock \n\n");
      }
  }

}



