#include<stdio.h>
#include"main.h"
#include<string.h>
#include<ctype.h>
/* Function to search a data */
int search_data(M_node **d_base,char *data)
{
    int index = tolower(data[0]) % 97;         // Defining index value with first letter of the word..
    M_node *m_temp = NULL;
    S_node *s_temp = NULL;
    if(d_base[index] != NULL)                  // If the index is not empty..
    {
	m_temp = d_base[index];         

	/* Traversing all Main node to search the data */
	while(m_temp != NULL)
	{
	    /* If the data matched */
	    if(strcmp(m_temp->word,data) == 0)
	    {	 
		printf("The word is searching for: %s\n",m_temp->word);
		printf("File Count\n%d\n",m_temp->file_count);
		s_temp = m_temp->s_link;

		/* To get file name and how many times the data present in the file */
		while(s_temp)
		{
		    printf("File Name\n%s\n",s_temp->file_name);
		    printf("Word Count\n%d\n",s_temp->word_count);
		    s_temp = s_temp->link;
		}
		return SUCCESS;
	    }
	    /* Traversing the temp to net Main Node */
	    m_temp = m_temp->m_link;
	}
    }
    else
    {
       return FAILURE;
    }


}

