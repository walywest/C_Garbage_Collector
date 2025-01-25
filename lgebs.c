#include "stdlib.h"
#include "stdio.h"

typedef struct  lol
{
    int         type;
    void        *address;
    char        *file;
    int         line;
}alist;

void    ft_add_address(int counter, alist **list, alist new)
{
    alist *temp;
    int i;

    i = 0;
    temp = malloc(sizeof(alist) * (counter + 2));
    temp[counter + 1].line = 0;
    while (i < counter)
    {
        if (counter)
            temp[i] = (*list)[i];
        i++;
    }
    temp[i] = new;
    free(*list);
    *list = temp;
}

alist *add_to_list(void *ptr, int line, char *file, int type)
{
    static int  counter = 0;
    static alist  *list = NULL;
    alist         new;

    new.address = ptr;
    new.line = line;
    new.file = file;
    new.type = type;
    ft_add_address(counter, &list, new);
    counter++;
    return (list);
}

int ft_scan(alist *list)
{
    int a;
    int b;
    int check;

    a = 0;
    while (list[a].line)
    {
        while (list[a].type == 2)
        {
            if (list[a + 1].line)
                a++;
            else
                return(0);
        }
        check = 0;
        b = a + 1;
        while (list[b].line)
        {
            if (list[a].address == list[b].address)
                check = 1;
            b++;
        }
        if (!check)
            printf("%p L9TRA at %s:%d\n",list[a].address, list[a].file, list[a].line);
        a++;
    }
    return (0);
}

void     *lgebs(void *ptr, char *file, int line, int option, size_t size)
{
    static alist  *list = NULL;
    int     i;
    void    *nptr;

    i = 0;
    if (option == 1)
    {
        nptr = malloc(size);
        //printf("this is the adderess %p\n", nptr);
        list = add_to_list(nptr, line, file, 1);
        return(nptr);
    }
    if (option == 2)
    {
        //printf("this is the adderess %p\n", ptr);
        free(ptr);
        list = add_to_list(ptr, line, file, 2);
        return (0);
    }
    if (option == 3)
    {
		if (list)
	        ft_scan(list);
        // if (list)
        //     free(list);
        return (0);
    }
    return (0);
}
