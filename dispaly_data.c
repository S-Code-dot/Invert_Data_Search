#include<stdio.h>
#include "main.h"
/*
Name:Soleman Mollick
Date:
Title:
Sample I/P:
Sample O/P:
 */

int display_data(M_node **d_base)
{
    M_node *m_temp = NULL;
    S_node *s_temp = NULL;
    printf("\n-----My Data Base-----\n");
    printf("Index\tWORD\tFile-Count\tFilename\tWord Count\n");
    for(int i = 0;i < 27;i++)
    {
	if(d_base[i] != NULL)
	{
	    m_temp = d_base[i];
	    while(m_temp != NULL)
	    {
	        printf("[%d]\t",i);
		printf("%s",m_temp->word);
		printf("\t%d",m_temp->file_count);
		s_temp = m_temp->s_link;
		while(s_temp != NULL)
		{
		    printf("\t\t%s",s_temp->file_name);
		    printf("\t%d",s_temp->word_count);
		    //printf("\t\t");
		    s_temp = s_temp->link;
		} 
		printf("\n");
		m_temp = m_temp->m_link;
	    }
	}
    }
    printf("\n");
    return SUCCESS;
}

