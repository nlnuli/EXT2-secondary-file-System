#include <stdio.h>
#include <string.h>
#include "main.h"
#include "init.h"

int main(int argc,char **argv)
{
    char command[10],temp[9];
    initialize_memory();
    while(1)
    {

        printf("%s]#",current_path);
        scanf("%s",command);
        //printf("%s h\n",command);
        if(!strcmp(command,"cd")) //���뵱ǰĿ¼��
        {
            scanf("%s",temp);
            cd(temp);
        }
        else if(!strcmp(command,"mkdir"))  //����Ŀ¼
        {
            scanf("%s",temp);
            mkdir(temp,2);
        }
        else if(!strcmp(command,"touch"))    //�����ļ�
        {
            scanf("%s",temp);
            cat(temp,1);
        }

        else if(!strcmp(command,"rmdir"))  //ɾ����Ŀ¼
        {
            scanf("%s",temp);
            rmdir(temp);
        }
        else if(!strcmp(command,"rm"))     //ɾ���ļ���Ŀ¼������ʾ
        {
            scanf("%s",temp);
            del(temp);
        }
        else if(!strcmp(command,"open"))    //��һ���ļ�
        {
            scanf("%s",temp);
            open_file(temp);
        }
        else if(!strcmp(command,"close"))   //�ر�һ���ļ�
        {
            scanf("%s",temp);
            close_file(temp);
        }
        else if(!strcmp(command,"read"))    //��һ���ļ�
        {
            scanf("%s",temp);
            read_file(temp);
        }
        else if(!strcmp(command,"write"))   //дһ���ļ�
        {
            scanf("%s\n",temp);
            write_file(temp);
        }
        else if(!strcmp(command,"ls"))      //��ʾ��ǰĿ¼
        {
        	ls();
        }
        else if(!strcmp(command,"format"))  //��ʽ��Ӳ��
        {
            char tempch;
            printf("Format will erase all the data in the Disk\n");
            printf("Are you sure?y/n:\n");
            fflush(stdin);
            scanf(" %c",&tempch);
            if(tempch=='Y'||tempch=='y')
            {
                format();
            }
            else
            {
            	printf("Format Disk canceled\n");
            }
        }
        else if(!strcmp(command,"ckdisk"))  //���Ӳ��
        {
        	check_disk();
        }
        else if(!strcmp(command,"quit"))    //�˳�ϵͳ
        {
        	break;
        }
        else printf("No this Command,Please check!\n");
        getchar();
        //while((getchar())!='\n');
    }
    return 0;
}


/*
#include<stdio.h>
#include<string.h>
#include "simulator.h"

int main(int argc ,char *argv[])
{
    char buf[100];
    initialize_memory();
    while(1)
    {
        printf("%s]#",current_path);
        fgets(buf,100,stdin);
        char *command=strtok(buf,"\t\n\r ");
        if(!strcmp(command,"cd"))
        {
            while(1)
            {
                char *tmp=strtok(NULL,"\t\n\r ");

                if(tmp==NULL)
                    break;
                printf("%s h\n",tmp);
                cd(tmp);
            }
        }
        else if(!strcmp(command,"mkdir")) //����һ��Ŀ¼
        {
            while(1)
            {
                char *tmp=strtok(NULL,"\t\n\r ");

                if(tmp==NULL)
                    break;
                printf("%s h\n",tmp);
                mkdir(tmp,2);
            }
        }
        else if(!strcmp(command,"cat"))   //����һ���ļ�
        {
            while(1)
            {
                char *tmp=strtok(NULL,"\t\n\r ");
                if(tmp==NULL)
                    break;
                cat(tmp,1);
            }
        }
        else if(!strcmp(command,"rmdir")) //ɾ��һ����Ŀ¼
        {
            while(1)
            {
                char *tmp=strtok(NULL,"\t\n\r ");
                if(tmp==NULL)
                    break;
                rmdir(tmp);
            }
        }
        else if(!strcmp(command,"rm"))   //ɾ��һ���ļ�
        {

            while(1)
            {
                char *tmp=strtok(NULL,"\t\n\r ");
                if(tmp==NULL)
                    break;
                del(tmp);
            }
        }
        else if(!strcmp(command,"open"))  //��һ���ļ�
        {
            while(1)
            {
                char *tmp=strtok(NULL,"\t\n\r ");
                if(tmp==NULL)
                    break;
                open_file(tmp);
            }
        }
        else if(!strcmp(command,"close")) //�ر�һ���ļ�
        {
            while(1)
            {
                char *tmp=strtok(NULL,"\t\n\r ");
                if(tmp==NULL)
                    break;
                open_file(tmp);
            }
        }
        else if(!strcmp(command,"read")) //���ļ�
        {
            while(1)
            {
                char *tmp=strtok(NULL,"\t\n\r ");
                if(tmp==NULL)
                    break;
                read_file(tmp);
            }
        }
        else if(!strcmp(command,"write")) //д�ļ�
        {
            while(1)
            {
                char *tmp=strtok(NULL,"\t\n\r ");
                if(tmp==NULL)
                    break;
                write_file(tmp);
            }
        }
        else if(!strcmp(command,"ls"))    //��ʾ��ǰĿ¼
        {
            ls();
        }
        else if(!strcmp(command,"format"))  //��ʽ��Ӳ��
        {
            char tempch;
            printf("Format will erase all the data in the Disk\n");
            printf("Are you sure?y/n:\n");
            fflush(stdin);
            scanf(" %c",&tempch);
            if(tempch=='Y'||tempch=='y')
            {
                format();
            }
            else
            {
            	printf("Format Disk canceled\n");
            }
        }
        else if(!strcmp(command,"help")||!strcmp(command,"h"))  //�鿴������Ϣ
        {
        	help();
        }
        else if(!strcmp(command,"ckdisk"))  //���Ӳ��
        {
            check_disk();
        }
        else if(!strcmp(command,"quit"))    //�˳�ϵͳ
        {
            break;
        }
        else
            printf("No this Command,Please check!\n");
    }
    return 0;
}
*/
