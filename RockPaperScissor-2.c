//Rock,Paper and Scissor Game:-

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Checking The Options. To Choose The Winner.
int RockPaperScissor(char user,char comp,int* ptr4){
    //CONDITION-1:- DRAW
    // RR PP SS 
    if(user == comp){
        return 1;
    }

    // CONDITION-2:
    // RP RS PS  
    if((user == 'R' && comp == 'P') || (user == 'r' && comp == 'p')){
        return -1;
    }
    else if((user == 'P' && comp == 'R') || (user == 'p' && comp == 'r')){
        return 0;
    }
    else if((user == 'R' && comp == 'S') || (user == 'r' && comp == 's')){
        return 0;
    }
    else if((user == 'S' && comp == 'R') || (user == 's' && comp == 'r')){
        return -1;
    }
    else if((user == 'P' && comp == 'S') || (user == 'p' && comp == 's')){
        return -1;
    }
    else if((user == 'S' && comp == 'P') || (user == 's' && comp == 'p')){
        return 0;
    }
    else{
        printf("***INVALID-USER-INPUT***\n"); //INVALID-USER-INPUT
        *ptr4=*ptr4+1;
        return 2;
    }
   
}

//Function To Declare The Winner.
int Result(int reply,int *ptr1,int *ptr2,int *ptr3){
    
    printf("\n");
    if(reply == 0){
        printf("***CONGRULATIONS YOU WON THIS ROUND***\n");
        *ptr1=*ptr1+1;
    }
    else if(reply == 1){
        printf("***IT'S-A-DRAW***\n");
        *ptr3=*ptr3+1;

    }
    else{
        printf("***TRY AGAIN YOU LOST THIS ROUND***\n");
        *ptr2=*ptr2+1;

    }
}

//Function For Computers Choice.
void cmp(int number,char *ptr,char user){

    //For Upper case 0-11
    if(user == 'R' || user == 'P' || user == 'S'){

    if(number>=0 && number<=11 || number>=40 && number<=51 || number>=80 && number<=91){
            *ptr='P';
    }
    else if(number>=12 && number<=27 || number>=52 && number<=63 || number>=92 && number<=100){

        *ptr='R';
    }
    else{
        *ptr='S';
    }
    }
    //For lower case
    if(user == 'r' || user == 'p' || user == 's'){
       
        if(number>=0 && number<=11 || number>=40 && number<=51 || number>=80 && number<=91){
            *ptr='s';
    }
        else if(number>=12 && number<=27 || number>=52 && number<=63 || number>=92 && number<=100){
            *ptr='p';
    }
        else{
            *ptr='r';
    }
    }
}

//Function To Print The Final Result.
void FinalResult(int won,int lost,int draw){
    if(won>lost){
        printf("\n---------------------------------------------------------------->>>YOU ARE THE WINNER.\n");
    }
    if(lost>won){
        printf("\n---------------------------------------------------------------->>>YOU LOST THE GAME.\n");
    }
    if(won == lost){
        printf("\n---------------------------------------------------------------->>>IT'S A DRAW.\n");
    }
}

//Function To Print The Voilations Message.
//If voilation is 3 then it will print the message and terminate the game.
void RuleVoilation(int voilation){
    if(voilation == 3){
        printf("\n--------------------------------YOU-VOILATED-THE-RULES-------------------------------\n");
        printf("\n------------------------------------SEE-YAAAA----------------------------------------\n");
        printf("\n------------------------------------THANKYOU!----------------------------------------\n");

        exit(0);
    }
    
}

//Main Function
int main(){
        //Variable Declaration
        int won=0,lost=0,draw=0,round = 1,voilation = 0,number;
        int* ptr1 = &won;
        int* ptr2 = &lost;
        int* ptr3 = &draw;
        char user,comp;
        char* ptr = &comp;
        int* ptr4 = &voilation;

        //Printing The Welcome Message
        printf("\n*************************************************************************************\n");
        printf("\t\t\tWelcome To The Game Player\n\t\tThis Game Will Be Between You And The Computer\n\t\t\t\tEnjoy The Game\t\t\t\t\t-A7\n");
        printf("*************************************************************************************\n");
        printf("\nRULES:-\nTo Play This Game Player Should Choose One Option:\n1.[R/r]-->ROCK\n2.[P/p]-->PAPER\n3.[S/s]-->SCISSOR\nWARNING: DO NOT USE OTHER CHARACTERS,SYMBOLS AND NUMBERS.\n");
        printf("\n*************************************************************************************\n");

        //Loop To Play The Game + Round + Function Calling + Ending Condition
        while(1){

                    printf("\n------------------------------------------------------------------->ROUND [%d]<-------\n",round++);

                    printf("\nThe Computer Has Choosen It's Option.\n");        

                    printf("\nEnter your chooice from ['R']['P']['S']:- ");
                    scanf(" %c",&user);
                    srand(time(0));         //Generates nuw no after 0sec.
                    number=rand()%100+1;    //Generated a random number between 1 to 100.
                    cmp(number,ptr,user);
                    int reply = RockPaperScissor(user,comp,ptr4);
                    RuleVoilation(voilation);
                    
                    //If Reply Is Not 2 Then Below Code Will Execute.
                    //If Reply Is 2 Then The Below Code Will Not Execute.
                    if(reply!=2){
                                    printf("\nYou Choose -->[%c] and The Computer Choose -->[%c]\n",user,comp);
                                    //Function To Print The Result + Update The Scores.
                                    Result(reply,ptr1,ptr2,ptr3);

                                    printf("\n*************************************************************************************\n");
                                    char option;
                                    printf("Do you want to continue the game??[Y/N]: ");
                                    scanf(" %c",&option);
                                    if(option!='Y' && option!='y'){
                                        break;
                                    }

                                }
                }

        printf("\nYOU WON FOR [%d] ROUNDS.\nYOU LOST FOR [%d] ROUNDS.\nDRAW FOR [%d] ROUNDS.\nTOTAL ROUNDS [%d].",won,lost,draw,won+lost+draw);
        //Function To Check Number of Winning,Loosing and Draw.
        FinalResult(won,lost,draw);
        printf("\n\t\t\tThankyou! For Playing With Me........\n");
        printf("\n*************************************************************************************\n");
        printf("\n*************************************************************************************\n");
        printf("\n*************************************************************************************\n");

    return 0; 


}


