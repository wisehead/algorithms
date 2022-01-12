/*******************************************************************************
 *      file name: split.strtok.c                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/12-14:48:10                              
 *  modified time: 2022/01/12-14:48:10                              
 *******************************************************************************/
//借助strtok实现split
#include <string.h>
#include <stdio.h>
 
int main()
{
    char s[] = "Golden Global   View,disk * desk";
    const char *d = " ,*";
    char *p;
    p = strtok(s,d);
    while(p)
    {
        printf("%s\n",p);
        p=strtok(NULL,d);
    }
 
    return 0;
}
