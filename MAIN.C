   /*A program to calculate the individual expenses of group of friends
   * who go on a trip
   */

   #include<stdio.h>
   #include<conio.h>

   struct people
   {
     char name[20];
     long int amountSpent;
     long int amountToReceive;
     long int amountToPay;
   }a[100]={"noname",0,0,0};

   int n,i,d,j;
   long int totalExpense=0,dividedAmount=0,pay=0;

   void design(char a){

      for(d=0;d<70;d++){
	printf("%c",a);
      }

   }

   void inputPeople(){
      printf("Enter the number of People in the trip: ");
      scanf("%d",&n);
      printf("\n\nEnter the people names\n\n");
      for(i=0;i<n;i++){
	printf("%d ",i+1);
	fflush(stdin);
	gets(a[i].name);
	printf("\n");
	}
   }

   void inputExpense(){
      printf("Enter the expense of each of the Person in the group in Rupees\n");
      printf("If no expenditure by the person the just hit Enter, to go to the next person\n\n");
      design('-');
      printf("\nName\tExpense\n");
      for(i=0;i<n;i++){
       design('-');
	 printf("\n");
	 printf("%s \t ",a[i].name);
	 scanf("%ld", &a[i].amountSpent);
	 totalExpense+=a[i].amountSpent;
      }

   }

   void outputExpense(){
      printf("The Individual expenses are : \n\n");
     design('-');
      printf("\nName\t Expense\t Amount To Receive\t Amount To Pay\n");
      for(i=0;i<n;i++){
	design('-');
	 printf("\n");
	 printf("%s        %ld     \t\t    %ld   \t\t %ld  \n",a[i].name,a[i].amountSpent,a[i].amountToReceive,a[i].amountToPay);
      }
      design('-');
      printf("\n\tTotal Trip Expense:Rs %ld\n",totalExpense);

   }

   void share(){
       dividedAmount=totalExpense/n;
       for(i=0;i<n;i++){
	 if(a[i].amountSpent>dividedAmount){
	   a[i].amountToReceive=a[i].amountSpent-dividedAmount;
	 }
	 else{
	    a[i].amountToPay=dividedAmount-a[i].amountSpent;
	 }
       }
   }

   void payTo(){
   printf("\n");
    for(i=0;i<n;i++){
       if(a[i].amountToPay>0){
	  for(j=0;j<n;j++){
	     if(a[j].amountToReceive>0){
		  if(a[i].amountToPay>=a[j].amountToReceive&&a[i].amountToPay!=0){
		    pay=a[j].amountToReceive;
		    a[i].amountToPay-=a[j].amountToReceive;
		    a[j].amountToReceive=0;
		     printf("%d> %s must pay Rs %ld to %s\n",i+1,a[i].name,pay,a[j].name);
		  if(a[i].amountToPay==0)
		     break;
		  }
		  else{
		    pay=a[i].amountToPay;
		    a[j].amountToReceive-=a[i].amountToPay;
		     a[i].amountToPay=0;
		     printf("%d> %s must pay Rs %ld to %s\n",i+1,a[i].name,pay,a[j].name);
		    break;
		  }


	      }

	  }
       }
    }
}

   void main(){
      int ch;
      clrscr();

    design('*');
      printf("\n\n\n\n\n\n\t\tW E L C O M E   T O  TravelFRIEND A P P\n\n\n\n\n");

	while(1){
	 design('*');
	 printf("\nThe Available Options are:\n1>Add New Members \t2>Add Expenses\t3>Show Table Of Expense\n\n4>Show Who must pay to Whom\t5>Exit\n");
	 printf("\n\nEnter your Choice here : ");
	 scanf("%d",&ch);
	 clrscr();
	 switch(ch)
	 {
	   case 1:

	     inputPeople();
	     break;
	   case 2:

	     inputExpense();
	     break;
	   case 3:
	     share();
	     outputExpense();
	     break;
	   case 4:
	     payTo();
	     break;
	   case 5:

	     exit(0);
	   default:
	     printf("\nEnter the correct option\n");
	 }
      }
      /*
      printf("\nEnter the number of People on the trip\n\n\n");
      scanf("%d",&n);

      inputPeople();
      clrscr();


      inputExpense();
      clrscr();

      outputExpense();

      printf("\n\nEnter any 'Alphabet' to proceed further:\t");
      scanf("%d",&d);

      share();
      clrscr();


      printf("The UPDATED table \n");
      outputExpense();

       printf("\n\nEnter any Number to proceed further:\t");
      scanf("%d",&d);
      clrscr();
      payTo();

      printf("\nT H A N K    Y O U ! ! ! ! \n");
      printf("a coding by tharun\n");
      design('^');
       printf("\n\nEnter any Number to proceed QUIT:\t");
      scanf("%d",&d);
      */


      }
