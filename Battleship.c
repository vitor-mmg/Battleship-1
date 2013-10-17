#include <stdio.h>
#include <string.h>

static int col=0;
static int row=0;
static char field[10][10];
static int switch3=0;

void fieldfill(char x[10][10])
{
    int count1=0;
    col=0;
    row=0;
    while(row<10)
    {
        col=0;
        while(col<10)
        {
            x[row][col]='O';
            col++;
        }
        row++;
    }
}
void guess()
{
    int switch1=0;
    int switch2=0;
    char grow;
    int growint;
    int gcol;
    printf("Input your row guess (a,b,c,d,e,f,g,h,i,j)\n");
    while(switch1==0){
        scanf("%c",&grow);
        getchar();
        if(grow>='a' && grow<='j' || grow>='A' && grow<='J'){
            growint=grow-'a';
            switch1=1;
        }
        else{
            printf("Enter an available value\n");
        }
    }
    printf("Input you colum guess (1-10)\n");
    while(switch2==0){
        scanf("%d",&gcol);
        getchar();
        if(gcol>=1 && gcol<=10){
            gcol=gcol-1;
            switch2=1;
        }
        else{printf("Enter an available value\n");}
    }
    if(field[growint][gcol]=='S'){
            printf("Hit!\n");
            field[growint][gcol]='O';
            scan();
    }
    else{
        printf("Try again!\n");
    }
    switch1=0;
    switch2=0;
}
void reset()
{

}
void shipplace()
{
    int choice = rand() % 2;
    if(choice==0){
        int rrow2 = rand() % 10;
        int rcol2 = rand() % 7;
        field[rrow2][rcol2] = 'S';
        field[rrow2][rcol2+1] = 'S';
        field[rrow2][rcol2+2] = 'S';
        field[rrow2][rcol2+3] = 'S';
    }
    else{
        int rrow2 = rand() % 3;
        int rcol2 = rand() % 5;
        field[rrow2][rcol2] = 'S';
        field[rrow2+1][rcol2] = 'S';
        field[rrow2+2][rcol2] = 'S';
        field[rrow2+3][rcol2] = 'S';
    }
}
void scan()
{
  int count1=0;
  int srow=0;
  int scol=0;
  while(srow<10){
        scol=0;
        while(scol<10){
            if(field[srow][scol]=='S'){
                count1++;
            }
            scol++;
        }
        srow++;
  }
  if(count1==0){
        printf("You sunk my battleship!");
        switch3=1;
  }
}
int main()
{
    fieldfill(field); //Can be used to reset
    srand(time(NULL));
    int rrow=rand() % 10+1;
    int rcol=rand() % 10+1;
    shipplace();
    while(switch3==0){
        guess();
    }
    printf("\n\n ***Thanks for playing!***");
    return 0;
}
