/* Macros to define return type */
#define SUCCESS 0
#define FAILURE -1

/* Structure for Sub_node */ 
typedef struct sub_node
{
    int word_count;
    char file_name[20];
    struct sub_node *link;
}S_node;

/* Structure For Main Node */
typedef struct main_node
{
    int file_count;
    char word[20];
    struct sub_node *s_link;
    struct main_node *m_link;
}M_node;
/* Structure for list Where all file name will be saved */
typedef struct D_list
{
 struct D_list *prev;
 struct D_list *next;
 char file_name[20];
}Dlist;
/*
typedef struct Hash
{
 struct M_node *link;

}hash_t;
*/

/* Function Prototypes */

/* To new add Data to the Data Base */ 
int add_data(Dlist **head,Dlist **tail,M_node **d_base);

/* To create New Main Node And Sub Node */
int create_main_sub_node(M_node *m_temp, char *temp, char *buff);

/* To search any Data In Data Base */
int search_data(M_node **d_base,char *data);

/* To Update Data Base from Backup File */
int update_database(M_node **d_base);

/* To Save The Data Base in a file */
int save_data(M_node **d_base);

/* To Display the Data Base */
int display_data(M_node **d_base);

/* To Create Data Base */
int create_database(Dlist *head,M_node **d_base);

/* To Print the List where Files Are Saved */
int print_dlist(Dlist *head);

/* To Save the Files in a Linked List */
int store_filename(char *file,Dlist **head,Dlist **tail);
