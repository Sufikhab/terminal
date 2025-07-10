#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int running = 1;

void handle_mkfile(char *filename)
{
    if (!filename)
    {
        printf("Error: Please provide a filename\n");
        return;
    }

    FILE *f = fopen(filename, "w");
    if (!f)
    {
        perror("Error creating file");
        return;
    }

    char text[500];
    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    fwrite(text, sizeof(char), strlen(text), f);
    fclose(f);
    printf("File '%s' has been created\n", filename);
}

void handle_ls(char *unused)
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
        printf("%s\t", de->d_name);
    }
    printf("\n");

    closedir(dr);
}

void handle_mkdir(char *dirname)
{
    if (!dirname)
    {
        printf("Please provide a directory name\n");
        return;
    }

    if (mkdir(dirname, 0755) == 0)
    {
        printf("Folder '%s' created successfully\n", dirname);
    }
    else
    {
        perror("Error creating folder");
    }
}

void handle_rmdir(char *dirname)
{
    if (!dirname)
    {
        printf("Please provide a directory name\n");
        return;
    }

    if (rmdir(dirname) == 0)
    {
        printf("Folder '%s' removed\n", dirname);
    }
    else
    {
        perror("Error removing folder");
    }
}

void handle_rmfile(char *filename)
{
    if (!filename)
    {
        printf("Please provide a filename\n");
        return;
    }

    if (remove(filename) == 0)
    {
        printf("File '%s' removed\n", filename);
    }
    else
    {
        perror("Error removing file");
    }
}

void handle_show(char *filename)
{
    if (!filename)
    {
        printf("Please provide a filename\n");
        return;
    }

    FILE *f = fopen(filename, "r");
    if (!f)
    {
        perror("Error opening file");
        return;
    }

    char ch;
    while ((ch = fgetc(f)) != EOF)
    {
        putchar(ch);
    }
    printf("\n");

    fclose(f);
}

void handle_cd(char *path)
{
    if (!path)
    {
        printf("Please provide a valid directory\n");
        return;
    }

    if (chdir(path) != 0)
    {
        perror("Error changing directory");
    }
}

void handle_whereami(char *unused)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)))
    {
        printf("%s\n", cwd);
    }
    else
    {
        perror("getcwd() error");
    }
}

void handle_exit(char *unused)
{
    running = 0;
}

typedef struct
{
    char *command;
    void (*handler)(char *arg);
} Command;

Command commands[] = {
    {"mkfile", handle_mkfile},
    {"ls", handle_ls},
    {"mkdir", handle_mkdir},
    {"rmdir", handle_rmdir},
    {"rmfile", handle_rmfile},
    {"show", handle_show},
    {"cd", handle_cd},
    {"whereami", handle_whereami},
    {"exit", handle_exit},
    {NULL, NULL}};

int main()
{
    char input[100];
    char command[20], arg[80];

    while (running)
    {
        printf(">>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        int count = sscanf(input, "%s %s", command, arg);
        for (int i = 0; command[i]; i++)
            command[i] = tolower(command[i]);

        int found = 0;
        for (int i = 0; commands[i].command != NULL; i++)
        {
            if (strcmp(command, commands[i].command) == 0)
            {
                commands[i].handler(count >= 2 ? arg : NULL);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
