#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

void sfunc_ls(char *args)
{

    struct dirent *de;
    DIR *dr = opendir(".");

    if (!dr)
    {
        perror("Error opening directory");
        return;
    }

    while ((de = readdir(dr)) != NULL)
    {
        printf("%s\n", de->d_name);
    }
    printf("\n");

    closedir(dr);
}

void sfunc_rmdir(char *args)
{
    if (rmdir(args) == 0)
    {
        printf("Folder '%s' Deleted Successfully\n", args);
    }
    else
    {
        printf("Please select appropriate directory name\n");
        return;
    }
}

void sfunc_rmfile(char *args)
{
    if (remove(args) == 0)
    {
        printf("File '%s' removed successfully\n", args);
    }
}

void sfunc_show(char *args)
{
    FILE *f = fopen(args, "r");
    if (f == NULL)
    {
        perror("Error opening the file\n");
        return;
    }

    char ch;
    while ((ch = fgetc(f)) != EOF)
    {
        putchar(ch);
    }
    printf("\n\n");
    fclose(f);
}

void sfunc_mkfile(char *args)
{
    if (!args)
    {
        printf("error:enter file name");
        return;
    }
    FILE *f = fopen(args, "w");
    if (f == NULL)
    {
        perror("error creating a file");
        return;
    }
    char text[500];
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;
    fwrite(text, sizeof(char), strlen(text), f);
    fclose(f);
    printf("file has been created", args);
}

void sfunc_mkdir(char *args)
{
    if (!args)
    {
        printf("error:enter direntory name");
        return;
    }
    if (mkdir(args) == 0)
    {
        printf("directory '%s'created successfully\n", args);
    }
    else
    {
        perror("error creating directory");
    }
}

void sfunc_cd(char *args)
{
    if (!args)
    {
        printf("error:enter directory name");
        return;
    }
    if (chdir(args) != 0)
    {
        perror("error changing directory");
        return;
    }
}

void sfunc_whereami(char *args)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != 0)
    {
        printf("current directory: %s\n", cwd);
    }
    else
    {
        perror("error getting current directory");
    }
}

void sfunc_exit(char *args) {
    int running = 1;
}

typedef struct
{
    char *command;
    void (*sfunc)(char *args);
} Command;

Command captian[] = {
    {"mkfile", sfunc_mkfile},
    {"mkdir", sfunc_mkdir},
    {"rmfile", sfunc_rmfile},
    {"rmdir", sfunc_rmdir},
    {"cd", sfunc_cd},
    {"show", sfunc_show},
    {"ls", sfunc_ls},
    {"whereami", sfunc_whereami},
    {NULL, NULL}};


