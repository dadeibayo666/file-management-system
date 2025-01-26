#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<unistd.h>

#define MAX_PATH 1024

//复制文件
void copyfile()
{
    char command[10];
    char f1[MAX_PATH], f2[MAX_PATH];     //源文件与目标文件的路径
    printf("请输入指令(cp <source flie> <target file>):\n");
    scanf("%s %s %s", command, f1, f2);
    if(strcmp(command, "cp") != 0)
        printf("Error!\n");
    else{
        //调用cp
        char p[MAX_PATH * 2];
        strcpy(p, "cp "); strcat(p, f1); strcat(p, " "); strcat(p, f2);
        if (system(p) == 0){
            printf("文件复制成功！\n");
        }else{
            printf("文件复制失败！\n");
        }
    }
}

//删除文件
void deletefile()
{
    char command[10];
    char f1[MAX_PATH];
    printf("请输入指令(rm <flie name>):\n");
    scanf("%s%s", command, f1);
    if(strcmp(command, "rm") != 0)
        printf("Error!\n");
    else{
        //调用rm
        char p[MAX_PATH];
        strcpy(p, "rm "); strcat(p, f1);
        if(system(p) == 0){
            printf("文件删除成功！\n");
        }else{
            printf("文件删除失败！\n");
        }
    }
}

//压缩文件
void zipfile(){
    char command[20];
    char f1[MAX_PATH], f2[MAX_PATH];
    printf("请输入指令(compress <file name> <compressed package name>):\n");
    scanf("%s%s%s", command, f1, f2);
    if(strcmp(command, "compress") != 0)
        printf("Error!\n");
    else{
        //调用tar -czf
        char p[MAX_PATH * 2];
        strcpy(p, "tar -czf "); strcat(p, f2); strcat(p, ".tar.gz "); strcat(p, f1);
        if(system(p) == 0){
            printf("文件压缩成功！\n");
        }else{
            printf("文件压缩失败！\n");
        }
    }
}

//解压文件
void unzipfile()
{
    char command[20];
    char f1[MAX_PATH], path[MAX_PATH];
    printf("请输入指令(decompress <compressed package name> <target directory>):\n");
    scanf("%s%s%s", command, f1, path);
    if(strcmp(command, "decompress")!= 0)
        printf("Error!\n");
    else{
        //调用tar -zxvf
        char p[MAX_PATH * 2];
        strcpy(p, "tar -zxvf "); strcat(p, f1); strcat(p, ".tar.gz "); strcat(p, "-c "); strcat(p, path);
            if(system(p) == 0){
            printf("文件压缩成功！\n");
        }else{
            printf("文件压缩失败！\n");
        }
    }
}

//清空缓冲区，避免进入死循环
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//菜单界面
void menu(){
    printf("***************************************************************\n");
    printf("**                       文件管理系统                        **\n");
    printf("***************************************************************\n");
    printf("**                   请选择功能并输入指令                    **\n");
    printf("***************************************************************\n");
    printf("                           1.复制                              \n");
    printf("                           2.删除                              \n");
    printf("                           3.压缩                              \n");
    printf("                           4.解压                              \n");
    printf("                           5.退出                              \n");
    printf("***************************************************************\n");
    printf("请输入(1~5):");
}

//按键交互
void keydown(){
    int key = 0;
    scanf("%d",&key);
    printf("\n");
    switch (key)
    {
    case 1:
        /* 复制文件 */
        copyfile();
        break;
    case 2:
        /*删除文件*/
        deletefile();
        break;
    case 3:
        /*压缩文件*/
        zipfile();
        break;
    case 4:
        /*解压压缩包*/
        unzipfile();
        break;
    case 5:
        /*退出系统*/
        printf("Program has exit!");
        exit(0);
    default:
        printf("Error!请重新输入\n");
        clearBuffer();
        break;
    }
}


int main(int argc, char* argv[]){
    while (1)
    {
        menu();
        keydown();
        system("pause");
        system("cls");
    }
    return 0;
}