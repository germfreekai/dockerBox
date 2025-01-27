#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAG_SIZE 60

int main (void)
{
    char stored_password[8] = "1234567";
    stored_password[8] = '\0';
    char username[8];
    char password[8];

    fprintf(stdout, "username > ");
    scanf("%s", username);
    
    fprintf(stdout, "password > ");
    scanf("%s", password);

    // Uncomment following lines and observe how it works
    fprintf(stdout, "username : %s\n", username);
    fprintf(stdout, "stored_password : %s\n", stored_password);
    fprintf(stdout, "password : %s\n", password);

    if (!strcmp(stored_password, password))
    {
        char *flag = (char*)calloc(FLAG_SIZE, sizeof(char));
        FILE *fptr;

        if (! (fptr = fopen("/root/flag", "r")))
        {
            fprintf(stderr, "[X] Failed to read flag file\n");
            goto exit_failure;
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

            goto exit_success;
        }
    }
    else
    {
        fprintf(stderr, "[X] Wrong password, do not try again\n");
        goto exit_failure;
    }

exit_success:
    return EXIT_SUCCESS;
exit_failure:
    return EXIT_FAILURE;
}
