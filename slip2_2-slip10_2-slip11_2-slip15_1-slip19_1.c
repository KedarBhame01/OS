// Slip2_2/Slip10_2/Slip11_2/Slip12_2/Slip15_1/Slip19_1: Write a program to implement the 
// shell. It should display the command prompt “myshell$”. Tokenize the command line and 
// execute the given command by creating the child process. Additionally it should interpret the 
// following ‘list’ commands as 
// myshell$ list f dirname:- To print names of all the files in current directory. 
// myshell$ list n dirname :- To print the number of all entries in the current directory
// error
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>

void make_toks(char * s, char * tok[]) {
    int i = 0;
    char * p;
    p = strtok(s, " ");
    while (p != NULL) {
        tok[i++] = p;
        p = strtok(NULL, " ");
    }
    tok[i] = NULL;
}
void list(char * dn, char op) {
    DIR * dp;
    struct dirent * entry;
    int dc = 0, fc = 0;
    dp = opendir(dn);
    if (dp == NULL) {
        printf("Dir %s not found.\n", dn);
        return;
    }
   // For BCS / BCA Classes Call on 9730381255 / www.nrclassespune.com / www.bcsbca.com
    switch (op) {
    case 'f':
        while (entry = readdir(dp)) {
            if (entry -> d_type == DT_REG)
                printf("%s\n", entry -> d_name);
        }
        break;
    case 'n':
        while (entry = readdir(dp)) {
            if (entry -> d_type == DT_DIR) dc++;
            if (entry -> d_type == DT_REG) fc++;
        }
        printf("%d Dir(s)\t%d File(s)\n", dc, fc);
        break;
    case 'i':
        while (entry = readdir(dp)) {
            if (entry -> d_type == DT_REG)
                printf("%s\t%lu\n", entry -> d_name, entry -> d_fileno);
        }
    }
    closedir(dp);
}
int main() {
    char buff[80], * args[10];
    int pid;
    while (1) {
        printf("myshell$");
        fflush(stdin);
        fgets(buff, 80, stdin);
        buff[strlen(buff) - 1] = '\0';
        make_toks(buff, args);
        if (strcmp(args[0], "list") == 0)
            list(args[2], args[1][0]);
        else {
            pid = fork();
            if (pid > 0)
                wait();
            else {
                //For BCS / BCA Classes Call on 9730381255 / www.nrclassespune.com / www.bcsbca.com
                if (execvp(args[0], args) == -1)
                    printf("Bad command.\n");
            }
        }
    }
    return 0;
}