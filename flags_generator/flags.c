#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/stat.h>
#include <time.h>

#define PATH_MAX 1024
#define BOX_NAME 50
#define FLAG_SIZE 60

// User options
void print_help_message(char *executable);
int create_new_flag();
int check_flag(char *user_flag);

// Generate flag
char _random_char(int index);
char *_flag();
int _write_flag_file(char *path, char *flag);

int main(int argc, char *argv[argc + 1])
{
    int ret = 0;

    if (argc == 1)
    {
        fprintf(stderr, "[X] Missing arguments, run %s -h\n", argv[0]);
        goto exit_failure;
    }
    if (argc > 3)
    {
        fprintf(stderr, "[X] Too many arguments, run %s -h\n", argv[0]);
        goto exit_failure;
    }

    int c;
    while (1)
    {
        static struct option long_options[] = {
            {"help", no_argument, NULL, 'h'},
            {"new-flag", required_argument, NULL, 'n'},
            {"check", required_argument, NULL, 'c'}
        };

        int option_index = 0;

        c = getopt_long(argc, argv, "hn:c:", long_options, &option_index);

        if (c == 1)
            break;

        switch (c)
        {
            case 0:
                if (long_options[option_index].flag != 0)
                    break;
            // Show help
            case 'h':
                print_help_message(argv[0]);
                goto exit_prog;
            // Create new flag
            case 'n':
                fprintf(stdout, "New flag\n");
                ret = create_new_flag(optarg);
                goto exit_prog;
            // Check flag
            case 'c':
                fprintf(stdout, "Check flag\n");
                ret = check_flag(optarg);
                goto exit_prog;
            case '?':
                break;
            default:
                abort();

        }
    }

exit_prog:
    exit(ret);
exit_failure:
    ret = 1;
    goto exit_prog;
}

/*
 * print_help
 *
 * Shows help message
 * Arguments:
 * - executable (char*): executable name
 */
void print_help_message(char *executable)
{
    fprintf(stdout, "%s usage\n"
            "-h              show help\n"
            "-n <box_name>   create new flag\n"
            "-c <flag>       check flag\n",
            executable);
}

/*
 * check_flag
 *
 * Check user found flag against generated one
 * Argumetns:
 * - user_flag (char*): user provided flag
 * Returns:
 * - ret (int): success value
 */
int check_flag(char *user_flag)
{
    int ret = 0;
    
    char *flag = (char*)calloc(FLAG_SIZE, sizeof(char));
    flag[0] = '\0';

    FILE *fptr;

    if (! (fptr = fopen("/usr/src/.flag/.secret", "r")))
    {
        fprintf(stderr, "[X] Failed to read flag file\n");
        goto return_failure;
    }
    else
    {
        char ch = fgetc(fptr);
        while (ch != EOF)
        {
            strncat(flag, &ch, 1);
            ch = (char)fgetc(fptr);
        }
        
        fclose(fptr);
    }

    if (! strcmp(user_flag, flag))
        fprintf(stdout, "[+] Flag matches!\n");
    else
    {
        fprintf(stderr, "[X] Wrong flag: %s\n", user_flag);
        goto return_failure;
    }

exit_func:
    free(flag);
    return ret;
return_failure:
    ret = 1;
    goto exit_func;
}

/*
 * create_new_flag
 *
 * Creates a dir with dynamic flag value
 * Arguments:
 * - box_name (char*): box name
 * Returns:
 * - ret (int): sucess value
 */
int create_new_flag(char *box_name)
{
    int ret = 0;
    
    char *path = NULL;
    char *flag = NULL;
    
    path = (char*)calloc(PATH_MAX, sizeof(char));
    path[0] = '\0';

    strncat(path, "/usr/src/.flag", strlen("/usr/src/.flag") + 1);
 
    if (mkdir(path, S_IRWXU | S_IRWXG | S_IRWXO))
    {
        fprintf(stderr, "[X] Failed to create .flag\n");
        goto return_failure;
    }

    strncat(path, "/", 2);
    strncat(path, ".secret", strlen(".secret") + 1);

    flag = _flag(box_name);

    // secret
    if (_write_flag_file(path, flag))
    {
        fprintf(stderr, "[X] Failed to write flag file\n");
        goto return_failure;
    }

    path[0] = '\0';
    strncat(path, "/root/flag", strlen("/root/flag") + 1);
    // for user
    if (_write_flag_file(path, flag))
    {
        fprintf(stderr, "[X] Failed to write flag file at root\n");
        goto return_failure;
    }

exit_func:
    if (path)
        free(path);
    if (flag)
        free(flag);
    return ret;
return_failure:
    ret = 1;
    goto exit_func;
}

/*
 * _random_char
 *
 * Selects a random char from charset
 * Arguments:
 * - index (int): char n
 * Returns:
 * - charset[index] (char): single char
 */
char _random_char(int index)
{
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    return charset[index];
}

/*
 * _flag
 *
 * Generates a random flag
 * Arguments:
 * - box_name (char*): box name
 * Returns:
 * - flag (char): randomly generated flag
 */
char *_flag(char *box_name)
{
    char *flag = (char*)calloc(FLAG_SIZE, sizeof(char));
    flag[0] = '\0';
    strncat(flag, box_name, strlen(box_name));
    strncat(flag, "_", 2);

    srand(time(NULL));
    int index, i;
    char temp[2];

    for (i = strlen(flag); i < FLAG_SIZE - 1; i++)
    {
        index = rand() % 62;
        temp[0] = _random_char(index);
        temp[1] = '\0';
        strncat(flag, temp, 3);
    }
    flag[FLAG_SIZE - 1] = '\0';

    return flag;
}

/*
 * _write_flag_file
 *
 * Writes flag into secret file to further compare
 * Arguments:
 * - path (char*): file full path
 * - flag (char*): flag
 * Returns:
 * - ret (int): success value
 */
 int _write_flag_file(char *path, char *flag)
{
    int ret = 0;
    FILE *fptr;

    if (! (fptr = fopen(path, "w")))
        goto return_failure;
    else
    {
        fprintf(fptr, "%s", flag);
        fclose(fptr);
    }

exit_func:
    return ret;
return_failure:
    ret = 1;
    goto exit_func;
}

