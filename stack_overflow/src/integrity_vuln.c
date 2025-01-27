#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAG_SIZE 60

int main (void)
{
    int ret = 0;
    char secret_content[20] = "important_token_12";
    secret_content[19] = '\0';
    char user_input[20];

    fprintf(stdout, "user_input > ");
    scanf("%[^\n]", user_input);
    
    fprintf(stdout, "user_input: %s\n", user_input);
    fprintf(stdout, "secret_content: %s\n", secret_content);

    if (! strcmp(secret_content, "important_token_12"))
        fprintf(stdout, "Your info is safe here\n");
    else
    {
        char *flag = (char*)calloc(FLAG_SIZE, sizeof(char));
        FILE *fptr;

        if (! (fptr = fopen("/root/flag", "r")))
        {
            fprintf(stderr, "[X] Failed to read flag file\n");
            ret = 1;
        }
        else
        {
            char ch = fgetc(fptr);
            while(ch != EOF)
            {
                strncat(flag, &ch, 1);
                ch = (char)fgetc(fptr);
            }

            fclose(fptr);

            fprintf(stdout, "%s\n", flag);

            free(flag);

            ret = 0;
        }
    }

    return ret;
}


