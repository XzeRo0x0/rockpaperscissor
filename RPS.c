//Rock,Paper and Scissor Game:-

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Funtion To Check The Options. To Choose The Winner.
int RockPaperScissor(char user,char comp){
    //CONDITION-1:
    // RR PP SS 
    if(user == comp){
        return 1;
    }

    // CONDITION-2:
    // RP RS PS  
    if(user == 'R' && comp == 'P'){
        return -1;
    }
    else if(user == 'P' && comp == 'R'){
        return 0;
    }
    else if(user == 'R' && comp == 'S'){
        return 0;
    }
    else if(user == 'S' && comp == 'R'){
        return -1;
    }
    else if(user == 'P' && comp == 'S'){
        return -1;
    }
    else if(user == 'S' && comp == 'P'){
        return 0;
    }
    else{
        printf("***INVALID-USER-INPUT***\n");
        return 2;
    }
   
}

//Function To Print The OutPut Of The Result;
void Result(int reply){
    if(reply == 0){
        printf("***CONGRULATIONS YOU WON THE MATCH***\n");
    }
    else if(reply == 1){
        printf("***IT'S-A-DRAW***\n");
    }
    else{
        printf("***TRY AGAIN YOU LOST THE MATCH***\n");
    }
}

//Function To Choose For Tho Computer;
void cmp(int number,char *ptr){
    if(number>0 && number<=33){
            *ptr='S';
    }
    else if(number>=34 && number<=66){

        *ptr='R';
    }
    else{
        *ptr='S';
    }
}


int main(){
        
        char user,comp;
        char option;
        int number;
        char* ptr = &comp;

        printf("\n*************************************************************************************\n");
        printf("\t\t\tWelcome To The Game Player\n\t\tThis Game Will Be Between You And The Computer\n\t\t\t\tEnjoy The Game\t\t\t\t-A7\n");
        printf("*************************************************************************************\n");
        printf("\nTo Play This Game Choose:\n'R'-->ROCK\n'P'-->PAPER\n'S'-->SCISSOR\n");
        printf("\n*************************************************************************************\n");


        while(1){

                    printf("The Computer Has Choosen It's Option\n");        
                    printf("Enter your chooice from['R'|'P'|'S']:- ");
                    scanf(" %c",&user);
                   
                    srand(time(0));         //Generates nuw no after 0sec.
                    number=rand()%100+1;    //Generated a random number between 1 to 100.
                    cmp(number,ptr);
                    int reply = RockPaperScissor(user,comp);

                    if(reply!=2){
                    printf("You Choose -->'%c' and The Computer Choose -->'%c'\n",user,comp);
                    Result(reply);
                    printf("Do you want to continue the game??[Y/N]: ");
                    scanf(" %c",&option);
                    if(option!='Y' && option!='y'){
                    break;
                    }
                    }
                }

        printf("\nThankyou! For Playing The Game.....\n");

    return 0;

}
