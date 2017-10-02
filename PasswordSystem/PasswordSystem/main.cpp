
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string>

using namespace std;

string file_path = "/Users/aleksanenkova/Desktop/Inform_Sec/PasswordSystem/";
string system_cmd = "Open ";

FILE *fptr, *fSec;
char approvedUsrnames[3][7];
char approvedPassword[3][7];

int login();
void openFile();
void closeFile();

int main() {
    login();
    return 0;
}
 
int login() {
    
    char userPassword[7] = "", usrname[7], inputChar;
    char fileSec[20]="";
    int i, loginOrClose = 1;;
    openFile();
    
    int numofLogins = 3;
    
    
    if (fptr != NULL)
    {
        while (!feof(fptr))
        {
            for (i = 0; i < 3; i++) {
                fscanf(fptr, "%s", approvedUsrnames[i]);
                fscanf(fptr, "%s", approvedPassword[i]);
            }
            
        }
        closeFile();
    }
    printf("\nХотите зайти в систему?\n 1. Да\n 0. Нет\n");
    scanf("%d", &loginOrClose);
    
    if (loginOrClose == 0) {
        exit(69);
    }
    else {
        printf("Имя: ");
        scanf("%s", usrname);
        printf("Пароль <не менее 6 символов>: ");
        
        cin >> userPassword;
        for (i = 0; i < 3; i++) {
            
            if (strcmp(approvedUsrnames[i], usrname) == 0) {
                
                if (strcmp(userPassword, approvedPassword[i]) == 0) {
                    printf("\nВы успешно зашли! Какой файл вы хотите открыть?\n");
                    scanf("%s", fileSec);
                    string cmd = string("Open ") + fileSec;
                    system(cmd.c_str());
                    cin.get();
                    return 1;
                    break;
                }
                
            }
            
        }
        printf("\nНе верный логин или пароль\n");
        cin.get();
        return 0;
    }
    
    
}

void openFile()
{
    fptr = fopen("Logins.txt", "r");
    if (fptr == NULL)
    {
        printf("Файл с паролями не был создан. Я его создам \n");
        fptr = fopen("Logins.txt", "w");
        closeFile();
        openFile();
    }
    else {

        printf("Доступ запрещён! \n");
    }
}

void closeFile()
{
    fclose(fptr);
}
