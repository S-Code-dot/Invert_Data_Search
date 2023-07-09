#include<stdio.h>
#include"main.h"
#include<string.h>
/* Function To Store New Data to the Data Base */
int add_data(Dlist **head,Dlist **tail,M_node **d_base)
{
    char file[20];   // Array to store file name..
    /* Asking for input */
    printf("Enter your file name: ");
    scanf("%s",file);

    /* Validating the file is .txt , presence , Non emptyfile */
    if(strstr(file,".txt"))
    {
	FILE *fp = fopen(file,"r");  
	if(fp)
	{
	    fseek(fp,0,SEEK_END);
	    if(ftell(fp))              // If all the alidation successfull..
	    {
              if(store_filename(file,head,tail) == SUCCESS)    // Storing in Dlist ..
	      {
	        if(create_database(*tail,d_base) == SUCCESS)   // Updating the Data Base with new file data..
		{
		  return SUCCESS;
		
		}

	      }

	    }
	}	
    }
    return FAILURE;

}

