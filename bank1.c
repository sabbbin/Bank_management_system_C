#include <stdio.h>
#include<conio.h>
#include <string.h>
struct pas{
char d[15];
};
struct account               // declaring structure to store various data types
{  char name [30];
    int acno;
    float deposit;
    char actype   ;
    struct pas da;
} ac;
void create ()            // to create a new account
    {
    int i=0,j,a;float b;
    char c;
    char xx[15];
    FILE*fp;// using pointer to opening a file
    fp=fopen ("record.dat","ab") ;  // opening a record data file in binary mode
// enter the personal record of customer
//printf ("enter you name");
// scanf ("%s",ac.name);
t: printf ("enter your account number");
 scanf ("%d",&j); if  (a=avlacno(j)==1){
      printf ("account no already exist ");
      goto t;}
      else {
            ac.acno=j;
      }                printf ("enter your account type");
    scanf ("%s",ac.actype)  ;
			    printf ("enter your name ");
			    scanf ("%s",ac.name);
up:
   printf ("enter your deposit number ");
  scanf ("%f",&b);
    if (b<=500)
	{printf ("enter amount greater than 500");
    goto up;}
       else
	    {ac.deposit=b;}
//intf (" enter your account type:");
 // scanf ("%s",ac.actype);   fflush (stdin);
    printf ("enter your password \n you password length is 15\t");     ac.da.d[15]= ('\0') ;
   while ((c=getch())!=13){
if (i>=14)
    {
	break;// loop break after it max value become 15
}
else {
ac.da.d[i++]=c;
printf ("%c",'*');
}}
fwrite (&ac,sizeof(ac),1,fp);// writing in a file
    fclose (fp); // closing file
       getch ();
}






void display ()// display the record of whole customer  without their password only for manager
{
char a[15];
char c;
int i=0; int x;
     FILE*fp1;// pointing a file
      printf ("enter your password \n you password length is 15\t");// you have to enter password "kkhwopa " to view the record  and password is know  to only manager
   while ((c=getch())!=13){
		     a[i++]=c;
			    printf ("%c",'*');}
			    x=strcmp(a,"khwopa");// comparing the password
			    if (x==0){


     fp1=fopen ("record.dat","rb");// opening file in read  binary mode
     printf ("\n account name\taccout no\tdeposit number\taccount type\t password  ");
     while (fread(&ac,sizeof (ac),1,fp1))// displaying the data tile the end of file
     printf ("\n%s\t\t%d\t\t%.2f\t%s\t%s",ac.name,ac.acno,ac.deposit,ac.actype,ac.da.d);
     fclose (fp1);}
     else
     { printf ("enter the correct password");// if password is wrong then display
     }  getch ();
}
void search ()// for user  to view their data
    {
      FILE*fp2;// pointing the file
      int b,r,s,avl;
      printf ("\n enter your account no ");// asked your to enter your account number
      scanf ("%d",&r);
      b=r;
      avl=avlacno(r);// calling the function name avlacno to check your account number
      if (avl==0)
	 {
	 printf ("\nthe account has no been created");

	 }
      else// account nu match then open file
	{
	fp2=fopen ("record.dat","rb");// opening file in read binary mode
	while (fread(&ac,sizeof (ac),1,fp2))// reading file till the end of file
		   {
	   s=ac.acno;
	   if (s==b)// if account no get match your account is deleted
	   {
	   printf ("\n name=%s",ac.name);
	   printf ("\n account no= %d" ,ac.acno);
	   printf ("\n deposit amount=%f",ac.deposit);
	   printf ("\n account type=%c",ac.actype); printf ("\n password %c ",'*');
	  }
	  }
     fclose(fp2);// closing file
     }
     getch ();
  }
   void delet ()// if your want to delete file
   {
    FILE*fpo;// pointing file
    FILE*fpt;// pointing file
    int b, r,s;
char ch[15];
int y;
    printf ("\nenter your accout number");
    scanf ("%d",&r);
    b=r;
    s=avlacno(r);
	  if (s==0)

	 {
	   printf ( "\nyou have not create your account yet");
	 }

  else

{ printf ("enter your password ");
 scanf ("%s",ch);
 y=password (ch);
if ( y==0)
{printf ("your entered wrong password");}
else {
fpo=fopen ("record.dat","rb");// opening file in read mode
fpt=fopen ("tempfile.dat","wb");// opening file in write mode
while (fread(&ac,sizeof (ac),1,fpo))// reading file till end of file
   {
   //=ac.da.d;
   if (strcmp (ch,ac.da.d)!=0){
   fwrite (&ac,sizeof (ac),1,fpt);// coping the file in temp file in account doesn't match
   }   }

   fclose(fpo);// closing the file
   fclose (fpt); // closing the file

    fpo=fopen ("record.dat","wb");// opening record.dat fie in write mode
    fpt= fopen("tempfile.dat","rb");// opening temp file inf read mode
    while (fread(&ac,sizeof (ac),1,fpt)) {
    fwrite (&ac,sizeof (ac),1,fpo); } // copying the data from temp file to record file }
    printf ("\n record deleted");
    fclose (fpo);
    fclose (fpt);}}// closing file
	 getch ();
  }

   void withdraw ()// to withdraw the amount
       {

		   FILE*fpt;// pointing the file
		  FILE*fpo;// pointing the file
		     int avl,s,r,c,y;
		 char ch [15];
		 float f;
		 printf ("enter your account number");
		  scanf ("%d",&r);
		  c=r;
		   avl=avlacno(r);// checking the account present or not
       if (avl==0)
	       {
		 printf ("your account no doest no exist");// if not present display this
		 }
       else
	       {
		   printf ("enter your password ");
		   scanf ("%s", ch );
	       y=password(ch);// calling user defined function to check the password match or not
		  if (y==0){
		  printf ("your have entered wrong password");}
		  else {
		 fpo=fopen("record.dat","rb");// opening file in read mode
		 fpt=fopen("tempfile.dat","wb");// opening fie in write mode
		  while (fread(&ac,sizeof (ac),1,fpo))// read record file till the end of file
		 {

			  if (strcmp (ch,ac.da.d)!=0)  {
// if account no doesn't match then copy file
				  fwrite (&ac,sizeof (ac),1,fpt);// copying the file
				       }

	     else
	      {

	      printf ("enter your withdraw  amount");// amount to withdraw
	      scanf ("%f",&f);
	if (ac.deposit<=100+f){// checking whether the amount is greater than 100 or not
	      printf ("you don't have suffcient balance ");}
	      else {
	    ac.deposit=ac.deposit-f;// subtracting the amount
	     printf ("your have succesfully withdraw\t%f\n and your balance is\t %f",f,ac.deposit);  }
	     fwrite (&ac,sizeof (ac),1,fpt);// updating the user amount



		      }}

       fclose (fpo);// closing the file
       fclose (fpt);
// copying the file  from temp to record file
       fpo=fopen ("record.dat","wb");// opening in write mode
       fpt=fopen ("tempfile.dat","rb");// opening in read mode
       while (fread (&ac,sizeof (ac),1,fpt))
	 {//copying all the file in record file
		 fwrite (&ac,sizeof (ac),1,fpo)   ;//copying dill the end
	 }
		 fclose (fpo);// closing the file
		 fclose (fpt);}}//closing the file

 getch (); }



  void deposit ()// for deposit
       {

		   FILE*fpt;// pointing file
		  FILE*fpo;// pointing file
		 int s,r,c,y,avl;
		 float f; char ch[15];
		 printf ("enter your account number");
		  scanf ("%d",&r);
		  c=r;
		   avl=avlacno(r);// calling the avlacno  to check account number
       if (avl==0)
	       {
		 printf ("your account no doest no exist")    ;
		 }
       else
	       {
		   printf ("enter your password ");
	      scanf ("%s",ch);
	      y=password(ch);// calling password function to check password
	      if (y==0){
	      printf (" you have entered wrong password");
	      } else { // now opening two file
		 fpo=fopen("record.dat","rb");// opening in read mode
		 fpt=fopen("tempfile.dat","wb");// opening in write mode
		  while (fread(&ac,sizeof (ac),1,fpo))//  read till the end of file
		 {

			  if (strcmp (ch,ac.da.d)!=0)
			  {// if condition get wrong the copy file to  temp file
				  fwrite (&ac,sizeof(ac),1,fpt);
			   }

	      else
	      {
	      printf ("enter your deposit amount");
	      scanf ("%f",&f);
	      ac.deposit=ac.deposit+f;// updating the deposit amount
            fwrite (&ac,sizeof (ac),1,fpt);// copying the file after updating
	     printf ("You have deposit \t%f\n and your final amount is \t%f",f,ac.deposit);

  }

   }


       fclose (fpo);// closing the file
       fclose (fpt); // closing the file


       fpo=fopen ("record.dat","wb");
       fpt=fopen ("tempfile.dat","rb");
       while (fread (&ac,sizeof (ac),1,fpt))
	 {
		 fwrite (&ac,sizeof (ac),1,fpo);// copying the file in record file
	 }
		 fclose (fpo);// closing the file
		 fclose (fpt);// closing the file
		 printf ("your amount is successful deposited");}}
 getch (); }

  void update ()// calling the file to update
       {
		 int avl;
		   FILE*fpt;// pointing the  file
		  FILE*fpo;// pointing file
		 int i,j,s,r,d,y   ;
		 char c;
		 char xx[15],ch[15];
		 printf ("enter your account number");
		  scanf ("%d",&r);

		   avl=avlacno(r);// calling the userdefined function to check account number
       if (avl==0)
	       {
		 printf ("your account no doest no exist")    ;
		 }
       else
	       {printf ("enter you password ");
	       scanf ("%s",ch );


    y=password(ch);// calling password function to check if password match correctly or not
    if (y==0)
	       {
		 printf("invaild password");
		 }
		    else

		    {
		 fpo=fopen("record.dat","rb");// opening file in read mode
		 fpt=fopen("tempfile.dat","wb");// opening file in write mode
		  while (fread(&ac,sizeof (ac),1,fpo))// reading the file till the end of file
		 {

			  if (strcmp (ch,ac.da.d)!=0)
			  {//checking the condition if true copy file
				  fwrite (&ac,sizeof (ac),1,fpt);
			   }
	     else
	      {// updating name ,account numbe ,deposit amount account type ,password
		  printf ("press \n 1 to change name\n 2 to change account number \n3to change account type \n4to change password");
		  scanf ("%d",&d);
		  switch (d){
		      case 1:{
	      printf ("enter you name");
	      scanf ("%s",ac.name);
	      break;}
	      case 2:{                 r:
	      printf ("enter your account number");
	      scanf ("%d",&i); if (j=avlacno(i)==1){ printf ("already exist "); goto r;}else {ac.acno=i ;break;}
	      }
	//    case 3:{
	//printf ("enter your deposit amount");
	 //   scanf ("%f",&ac.deposit);break;}
	      case 3: {
	      printf ("enter your account type");
	      scanf ("%s",ac.actype);     break;}
	case 4 :        {


			  while ((c=getch())!=13){
					   xx[i++]=c;
					  printf ("%c",'*');
					  }

				     strcpy(ac.da.d,xx);
	   break;   }

	      }
	     fwrite (&ac,sizeof (ac),1,fpt);//copying the file in tempt file

 }}



       fclose (fpo);// closing the  file
       fclose (fpt);

// copying the file int record for temp file
     fpo=fopen ("record.dat","wb");
       fpt=fopen ("tempfile.dat","rb");
       while (fread (&ac,sizeof (ac),1,fpt))// read the file till the end of file
	 {
		 fwrite (&ac,sizeof (ac),1,fpo);// writing in record file
	 }
		 fclose (fpo);
		 fclose (fpt); //remove ("tempfile.dat");
		 printf ("record updated");} }
 getch (); }

int avlacno(int acno)//function to check your account no
{


		 FILE*fp;

		 fp=fopen ("record.dat","rb");// opening the file in read mode
      while (!feof(fp)) // opening the file till end of file
	  {
	       fread (&ac,sizeof(ac),1,fp);// reading the file till end of file
			 if (acno==ac.acno)
		       {
		       fclose (fp);// closing the file
		       return 1;// if condition get match return 1

	    }		}


			fclose (fp);// closing the file
			 return 0;// if doesn't found return 0
		}

    int password(char *ch)// to check password
      {
	 FILE*fp;// pointing the file
     int z=0,x,chek;
     char c;
     char pass[15];
    fp=fopen ("record.dat","rb");// opening the file in read mode
/*  printf ("ente your password");
			while ((c=getch())!=13)
   {
    pass[z++]=c;
     printf ("%c",'*');
     }
       pass[z]='\0';   */
   while (!feof(fp))// opening the file till end of file
		      {
			     fread (&ac,sizeof(ac),1,fp);
				chek=strcmp(ch ,ac.da.d);// comparing the password

			    if(chek==0)
			      {
				    fclose(fp);// closing file
				return 1;// condition get true return 1
					 }
				    } fclose(fp);// closing file
					return 0;// condition get false return 0
					  }







void   intro()// for introduction of group
{
		printf ("\n\n\n\n\t\tFAILURE DOESN'T MEANS FAIL\n\n\t\t\t\tBUT GIVING UP IS ");// quatation
		printf ("\n\n\nTHIS APPLICATION IS CREATED BY:");
		printf ("\n\n\n\n\t\t\t\tSABIN SUWAL\n\t\t\t\tAMAR SHRESTHA\n\t\t\t\tSACHIT KUMAR SHRESTHA\n\t\t\t\tROJESH SHAHI");
		printf("\n\n\n\n\t\t\tESPECIALLY THANK TO OUR RESPECTED SIR\n\t\t\t\t ER.SHIVA KUMAR SHRESTHA");
		printf ("\n\n\t\t\t KHWOPA COLLEGE OF ENGINEERING");
		getch ();
		clrscr ();
		}

int test ();
 void intro();
void main ()// main function
	   {
		 int c;
		 clrscr ();
	intro ();// calling introduction function
		   do
		   {
		   printf ("\n enter your choice\n\n\n");
		   printf ("\n1. to create account\n2.display\n3. search \n4.delete\n 5.update\n6.deposit.\n7 withdraw\n8.exit");

		   scanf ("%d",&c);
		   printf ("\n");
		   switch (c)
		{
		  case 1:
		  {   clrscr ();
		  create();
		  break; }
		  case 2: {  clrscr ();
		  display();
		  break;   }
		  case 3:   {  clrscr ();
		  search ();
		  break ;    }
		  case 4:     {   clrscr ();
		  delet ();
		  break;       }
		  case 5 :      { clrscr ();
		  update ();
		  break;         }
		  case 8:         {
		  exit ();
		  break;           }
		  case 7:{ clrscr ();
		  withdraw ();
		  break;}
		  case 6:{
		  clrscr ();
		  deposit();
		  break;}
		  default:          {
		  printf ("enter the correct choice");
		  break;             }
		  }
		  }
		  while(c!=8);// running the program till use press exit
		  }


