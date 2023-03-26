#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user
{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

void takeinput(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;    //removes the /n from the end of the file
    //and adds 0 to the end of the file
}


void generateUsername(char email[50], char username[50])
{
    //abc123@gmail.com
    //username: abc123

    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        else
        {
            username[i] = email[i];
        }
    }
}

void takepassword(char pwd[50])
{
    int i;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == BCKSPC)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b"); //abc -> ab
            }
        }
        else 
        {
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}



int main()
{
    system("color 0b");  //0: black, b: forground/text color

	FILE *fp;

    int opt, usrFound = 0;
    struct user user;
    char password2[50];
    
    

    printf("\n\t\t\t\t----------Welcome to authentication system--------");

    printf("\nPlease choose your operation");

    printf("\n1.SignUp");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\n\nYour Choice: \t");
    scanf("%d", &opt); //scanf will also generate the \n while taking the input
    fgetc(stdin);   //so we use the fgetc and it will consume the \n

    switch (opt)
    {
	    case 1:
	    	
	    	system("cls");  //clears the console before asking for the data
	    	
	        printf("\nEnter your full name:\t");
	        takeinput(user.fullName);
	
	        printf("Enter your email:\t");
	        takeinput(user.email);
	        
	        printf("Enter your phone No.:\t");
	        takeinput(user.phone);
	
	        printf("Enter your password:\t");
	        takepassword(user.password);
	
	        printf("\nConfirm your password:\t");   
	        takepassword(password2);
	
	        if (!strcmp(user.password, password2))
	        {
	            generateUsername(user.email, user.username);
	            fp = fopen("Users.dat", "a+");
	            fwrite(&user, sizeof(struct user), 1, fp);  //stores our info in the file
	            if (fwrite != 0)
	            {
	            	printf("\n\nUser registration successful, Your username is %s", user.username);	
				}
				else
				{
					printf("\n\nSorry! Something went wrong :( ");
				}
				fclose(fp);
	        }
	        else 
	        {
	            printf("\n\nPassword did not match");
	            Beep(750, 300); //produces sound --  windows.h
	        }
	        break;
        
        case 2:
        	char username[50], pword[50];
        	struct user usr;
        	
        	printf("\nEnter your username:\t");
        	takeinput(username);
        	
        	printf("Enter your password:\t");
        	takepassword(pword);
        	
        	system("cls");   //clears the screen before presenting the user data
        	
        	
        	fp = fopen("Users.dat", "r");
        	while (fread(&usr, sizeof(struct user), 1, fp))
        	{
        		if (!strcmp(usr.username, username))
        		{
        			if (!strcmp(usr.password, pword))
        			{
        				printf("\n\t\t\t\t\t\tWelcome %s", usr.fullName);
        				printf("\n\n|Full Name:\t%s", usr.fullName);
        				printf("\n|Email:\t\t%s", usr.email);
        				printf("\n|Username:\t%s", usr.username);
        				printf("\n|Contact no.:\t%s", usr.phone);
					}
					else
					{
						printf("\n\nInvalid Password!");
						Beep(750, 300);
					}
					usrFound = 1;
				}
			}
			if (!usrFound)
			{
				printf("\n\nUser is not registered!");
				Beep(750, 300);
			}
			fclose(fp);
			break;
			
		case 3:
			
			exit(0);
    }
    return 0;
}
