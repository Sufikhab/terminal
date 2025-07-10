#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "uses.h"

int main()
{
    while (1)
    {
        char input[100], command[10], arg[100];
        
        char cwd[1024];
        printf(getcwd(cwd, sizeof(cwd)));
        printf(">>>");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        int count = sscanf(input, "%s %s", command, arg);

        int flag = 0;
        for (int i = 0; captian[i].command != NULL; i++)
        {
            if (strcmp(command, captian[i].command) == 0)
            {
                captian[i].sfunc(count >= 2 ? arg : NULL);
                flag = 1;
                break;
            }
        }
          if (!flag)
            {
                printf("Unknown command\n");
            }
    }
}
