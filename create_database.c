#include<stdio.h>
#include "main.h"
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

/* To Create Data Base */
int create_database(Dlist *head,M_node **d_base)
{
    /* Declaring array and variable to store file data ,file name, index number */
    char temp[20];
    char buff[20]; 
    int index = 0;
    int flag = 0;
    /* Temporary pointer to store head value */
    Dlist *h_temp = head;
    while(h_temp != NULL)
    {
	strcpy(temp,h_temp->file_name);                // Copy File Name..
	FILE *fptr = fopen(h_temp->file_name,"r");     // Opening The file..
	while(fscanf(fptr,"%s",buff) != EOF)           // Loop To Get each word from file till reach to the EOF..
	{
	    index = tolower(buff[0]) % 97;             // Defining index alue by the first letter of the word for lower or upper both case..
	    if(index > 25)                             // 0 to 25th index is for alphabets.. 
	    {
		index = 26;                            // If the character is not an alphabet then it will store in 26th index..
	    }

	    /* If the Perticuler Index is Empty */
	    if(d_base[index] == NULL)                  
	    {   
		M_node *m_new = malloc(sizeof(M_node)); 
		S_node *s_new = malloc(sizeof(S_node));
		// Subnode updating..
		s_new->word_count = 1;
		strcpy(s_new->file_name,temp);
		s_new->link = NULL;
		// Main node updating..
		m_new->file_count = 1;
		strcpy(m_new->word,buff);
		m_new->s_link = s_new;
		m_new->m_link = NULL;
		// Updating index with new main Node address..
		d_base[index] = m_new; 
	    }

	    /* If the Index is not empty */
	    else
	    {
		M_node *m_temp = d_base[index];
		M_node *m_prev = NULL;

		/* Traverse through all data in the hash table */
		while(m_temp != NULL)
		{
		    /* If the word already present in the hash table */
		    if(strcmp(m_temp->word,buff) == 0)
		    {
			S_node *s_temp = m_temp->s_link;
			S_node *s_prev = NULL;

			/* Now If the file name of the word is already present in the Table */
			while(s_temp != NULL)
			{
			    if(strcmp(s_temp->file_name,temp) == 0)
			    {
				s_temp->word_count++;
				flag = 1;
				break;
			    }
			    s_prev = s_temp;
			    s_temp = s_temp->link;
			}

			/* If Word is present But the File Name is Not present */
			if(flag == 0)
			{
			    /* Createting new Subnode And Store Data */
			    S_node *new  = malloc(sizeof(S_node));
			    new->word_count = 1;
			    m_temp->file_count++;
			    strcpy(new->file_name,temp);
			    s_prev->link = new;
			    break;
			}
			else
			{
			    flag = 0;   // This flag is used to declare whether the word or file names is present or not..
			    break;
			}
		    }
		    /* Traversing the pointers to next nodes */
		    m_prev = m_temp;
		    m_temp = m_temp->m_link;
		}

		/* If the word is not present in the table then creating new main node and subnode and store */
		if(m_prev->m_link == NULL)
		{ 
		    create_main_sub_node(m_prev,temp,buff);   

		}

	    }
	}
	/* Traversing the pointer to next node of the Dlist */
	h_temp = h_temp->next;
    } 
    return SUCCESS;
}

