#include<stdio.h>
#include "main.h"
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/* Function for update Data Base from backup file */
int update_database(M_node **d_base)
{
    /* Declaring array and variables */
    char file[20];
    char ch[1];
    char data[50];
    char word[10];
    int file_count;
    char file_name[20];
    int word_count;
    printf("Enter the saved file name: ");
    scanf("%s",file);
    if(strstr(file,".txt"))          // Validating given input is .txt or not..
    {
	FILE *fptr = fopen(file,"r"); // Opening the file..
	fread(ch,1,1,fptr);           // Reading first character..
	fseek(fptr,0,SEEK_SET);       // Again Setting the pointer to first character..

	if(ch[0] == '#')              // Check the first character is # or not to confirm is the input file is the backup file..
	{
	    while(fscanf(fptr,"%s",data) != EOF)    // To get all the data..
	    {
		int index = atoi(strtok(&data[1],";"));    // Getting first character hich is index ..
		if(d_base[index] == NULL)
		{
		    /* Creating new Main Node and updating details */
		    M_node *m_new = malloc(sizeof(M_node));  
		    strcpy(word,strtok(NULL,";"));          // All the data separated with ';' delimeter..
		    strcpy(m_new->word,word);
		    file_count = atoi(strtok(NULL,";"));
		    m_new->file_count = file_count;
		    d_base[index] = m_new;
		    S_node *s_new = malloc(sizeof(S_node));
		    strcpy(file_name,strtok(NULL,";"));
		    strcpy(s_new->file_name,file_name);
		    word_count = atoi(strtok(NULL,";"));
		    s_new->word_count = word_count;
		    m_new->s_link = s_new;
		    file_count--;
		    S_node *s_temp = s_new;

		    /* If the Data is present in multiple file */
		    while(file_count)
		    {
			/* Create subnode and store */
			S_node *new = malloc(sizeof(S_node));
			strcpy(file_name,strtok(NULL,";"));
			strcpy(new->file_name,file_name);
			word_count = atoi(strtok(NULL,";"));
			new->word_count = word_count;
			new->link = NULL;
			s_temp->link = new;
			s_temp = new;
			file_count--;
		    }
		}

		/* If the main node having any main node previously */
		else
		{
		    M_node *m_temp = d_base[index];
		    /* Traversing to last Main Node and Updating by creating new Main Node*/
		    while(m_temp->m_link)
		    {
			m_temp = m_temp->m_link;

		    }
		    M_node *m_new = malloc(sizeof(M_node));
		    strcpy(word,strtok(NULL,";"));
		    strcpy(m_new->word,word);
		    file_count = atoi(strtok(NULL,";"));
		    m_new->file_count = file_count;
		    m_temp->m_link = m_new;
		    S_node *s_new = malloc(sizeof(S_node));
		    strcpy(file_name,strtok(NULL,";"));
		    strcpy(s_new->file_name,file_name);
		    word_count = atoi(strtok(NULL,";"));
		    s_new->word_count = word_count;
		    m_new->s_link = s_new;
		    file_count--;
		    S_node *s_temp = s_new;
		    while(file_count)
		    {
			S_node *new = malloc(sizeof(S_node));
			strcpy(file_name,strtok(NULL,";"));
			strcpy(new->file_name,file_name);
			word_count = atoi(strtok(NULL,";"));
			new->word_count = word_count;
			new->link = NULL;
			s_temp->link = new;
			s_temp = new;
			file_count--;
		    }

		}
		strtok(NULL,"\n");
	    }
	    return SUCCESS;

	}
	else
	    return FAILURE;	
    }
}

