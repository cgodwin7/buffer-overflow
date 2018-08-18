/*
  This program is designed to show how stack buffer overflow vulnerabilities work.
  By Creating an admin menu that can only be accessed by a correct password and accepting
  a user input of undefined length, we can overflow the buffer and gain access without the correct password.
*/

#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void adminMenu(void)
{
    cout << "\nWelcome Administrator! \n\nWhat would you like to do?";
    cout << "\n\nEdit Grades \nExit\n";
}

char *getPass(void){
    return "bestpass";
}

//pre-condition: a single string is passed to the program's arguments
int main(int argc, char* argv[])
{
    //set up our validated variable that will be checking for a correct password
    int validated = 0;
    //output the address of "validated" before the strcpy function
    printf("Address of 'validated' pre-input = %p\n", validated);
    char userPass[10];
    //this check is used to make sure that the precondition of a single password is used for the program argument
    if (argc != 2)
    {
        cout << "There must be a single password used as an argument";
        return 0;
    }
    //this is the vulnerable strcpy function that is not defining the buffer size
    strcpy(userPass, argv[1]);
    //we check for a correct password, which is "bestpass"
    if (strcmp(userPass, getPass()) == 0)
        validated = 1;
    //redisplay the address of "validated" again to show the buffer being overrun
    printf("Address of 'validated' post-input = %p\n", validated);
    if (validated)
    {
        //grant access to the admin menu if validated is "true"
        adminMenu();
    }
    else
        printf("The password is incorrect please try again.\n");
    return 0;
}
//post-condition: the admin menu will be displayed, or "The password is incorrect please try again." will be displayed