#include <bits/stdc++.h>
using namespace std;

const int size = 50;
string myLeaderBoard [1000][3];
int indexBoader = 0;
char myboradShow[10][20];
char myboradDate[10][20];
char unKnow = '?';
char empty = '-';
char myman = 'F';
int row = 10;
int col = 20;


void gameFinish (){
    for(int i = 0; i < row ; i++ ){
        for(int j = 0; j < col; j++){
            if(myboradDate[i][j] == 'M')
                myboradShow[i][j] = myboradDate[i][j];
        }
    }
}

bool check(int i, int j, char flag){

    if(flag == 'F'){
        myboradShow[i][j] = 'F';
        return false;
    }else{
        if(myboradDate[i][j] == 'M'){
            gameFinish();
            return true;
        }else if (myboradShow[i][j] == '?'){
            myboradShow[i][j] = myboradDate[i][j];
            return false;
        }
    }
}

void funTime(){
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);

    char hour[4];
    char mim[4];
    char sec[4];
    char AMorPM;

    char myTime[4];

    char myDate[50];

    strftime(hour, 50, "%I:%M:%S %p", &datetime);
    strftime(mim, 50, "%I:%M:%S %p", &datetime);
    strftime(sec, 50, "%I:%M:%S %p", &datetime);
//    strftime(AMorPM, 50, "%I:%M:%S %p", &datetime);
    cout << myTime << "\n";

    strftime(myDate, 50, "%Y/%m/%d", &datetime);
    cout << myDate << "\n";
}

void showborad(){

    cout<<"\u250c ";
    for(int i=1; i< col; i++){
        cout<<"\u2500 "<<"\u2530 ";
//        cout<<i<<", ";
    }
    cout<<"\u2500 "<<"\u2510\n";

    for(int j = 0; j<row-1; j++){
        cout<<"\u2502 ";
        for(int i=0; i< col; i++) cout<<myboradShow[j][i]<<" "<<"\u2506 ";
        cout<<"\n"<<"\u2523 ";
        for(int i=1; i< col; i++) cout<<"\u2500 "<<"\u254C ";
        cout<<"\u2500 \u2528\n";
    }

    cout<<"\u2502 ";
    for(int i=0; i< col; i++) cout<<myboradShow[row-1][i]<<" "<<"\u2506 ";
    cout<<"\n"<<"\u2514 ";
    for(int i=1; i< col; i++) cout<<"\u2500 "<<"\u2537 ";
    cout<<"\u2500 \u2519\n";

}


void inishowboarder(){
    for(int i = 0; i < row ; i++ ){
        for(int j = 0; j < col; j++){
            myboradShow[i][j] = unKnow;
        }
    }
}


void iniMein(){

    for(int i=0; i< col; i++){
        int x = rand() % col;
        int y = rand() % col;
        if(myboradDate[x][y] != 'M'){
            myboradDate[x][y] = 'M';
        }
    }

    for(int i= 0; i< row; i++){
        if(i> 0){
            if( i <row-1) {
                for(int j=0; j<col; j++){
                    if(myboradDate[i][j] != 'M'){
                        if(j==0){
                            int counter = 0;
                            if(myboradDate[i+1][j] == 'M') counter ++;
                            if(myboradDate[i][j+1] == 'M') counter ++;
                            if(myboradDate[i+1][j+1] == 'M') counter ++;
                            if(counter > 0)
                                myboradDate[i][j] = char(counter+'0');
                            else
                                myboradDate[i][j] = '-';

                        }else if(j==col-1){
                            int counter = 0;
                            if(myboradDate[i][j-1] == 'M') counter ++;
                            if(myboradDate[i+1][j] == 'M') counter ++;
                            if(myboradDate[i-1][j-1] == 'M') counter ++;
                            if(counter > 0)
                                myboradDate[i][j] = char(counter+'0');
                            else
                                myboradDate[i][j] = '-';
                        }else{
                            int counter = 0;
                            if(myboradDate[i][j-1] == 'M') counter ++;
                            if(myboradDate[i+1][j] == 'M') counter ++;
                            if(myboradDate[i-1][j-1] == 'M') counter ++;

                            if(myboradDate[i][j+1] == 'M') counter ++;
                            if(myboradDate[i+1][j+1] == 'M') counter ++;

                            if(counter > 0)
                                myboradDate[i][j] = char(counter+'0');
                            else
                                myboradDate[i][j] = '-';
                        }
                    }
                }
            }
            else{
                for(int j=0; j<col; j++){
                    if(myboradDate[i][j] != 'M'){
                        if(j==0){
                            int counter = 0;
                            if(myboradDate[i-1][j] == 'M') counter ++;
                            if(myboradDate[i-1][j+1] == 'M') counter ++;
                            if(myboradDate[i][j+1] == 'M') counter ++;
                            if(counter > 0)
                                myboradDate[i][j] = char(counter+'0');
                            else
                                myboradDate[i][j] = '-';

                        }else if(j==col-1){
                            int counter = 0;
                            if(myboradDate[i-1][j] == 'M') counter ++;
                            if(myboradDate[i-1][j-1] == 'M') counter ++;
                            if(myboradDate[i][j-1] == 'M') counter ++;
                            if(counter > 0)
                                myboradDate[i][j] = char(counter+'0');
                            else
                                myboradDate[i][j] = '-';
                        }else{
                            int counter = 0;
                            if(myboradDate[i][j-1] == 'M') counter ++;
                            if(myboradDate[i][j+1] == 'M') counter ++;
                            if(myboradDate[i-1][j-1] == 'M') counter ++;
                            if(myboradDate[i-1][j] == 'M') counter ++;
                            if(myboradDate[i-1][j+1] == 'M') counter ++;

                            if(counter > 0)
                                myboradDate[i][j] = char(counter+'0');
                            else
                                myboradDate[i][j] = '-';
                        }
                    }
                }
            }
        }

        else{
            for(int j=0; j<col; j++){
                if(myboradDate[i][j] != 'M'){
                    if(j==0){
                        int counter = 0;
                        if(myboradDate[i-1][j] == 'M') counter ++;
                        if(myboradDate[i+1][j] == 'M') counter ++;
                        if(myboradDate[i][j+1] == 'M') counter ++;
                        if(myboradDate[i+1][j+1] == 'M') counter ++;
                        if(myboradDate[i-1][j-1] == 'M') counter ++;
                        if(counter > 0)
                            myboradDate[i][j] = char(counter+'0');
                        else
                            myboradDate[i][j] = '-';

                    }else if(j==col-1){
                        int counter = 0;
                        if(myboradDate[i][j-1] == 'M') counter ++;
                        if(myboradDate[i+1][j] == 'M') counter ++;
                        if(myboradDate[i-1][j-1] == 'M') counter ++;
                        if(myboradDate[i-1][j] == 'M') counter ++;
                        if(myboradDate[i+1][j-1] == 'M') counter ++;

                        if(counter > 0)
                            myboradDate[i][j] = char(counter+'0');
                        else
                            myboradDate[i][j] = '-';
                    }else{
                        int counter = 0;
                        if(myboradDate[i][j-1] == 'M') counter ++;
                        if(myboradDate[i][j+1] == 'M') counter ++;

                        if(myboradDate[i+1][j] == 'M') counter ++;
                        if(myboradDate[i-1][j] == 'M') counter ++;

                        if(myboradDate[i-1][j-1] == 'M') counter ++;
                        if(myboradDate[i+1][j-1] == 'M') counter ++;

                        if(myboradDate[i-1][j+1] == 'M') counter ++;
                        if(myboradDate[i+1][j+1] == 'M') counter ++;
                        if(counter > 0)
                            myboradDate[i][j] = char(counter+'0');
                        else
                            myboradDate[i][j] = '-';
                    }
                }
            }
        }
    }
}

void leaderBoard(){
    cout<<"===================================================\n";
    cout<<"|             My Leader Board                     |\n";
    cout<<"|=================================================|\n";

}

void NewGame(){
    cout<<"---->> Welcom to New Game <-------\n";
    cout<< "Plase entre your name: ";
    string name;
    cin>> name;
    myLeaderBoard[indexBoader][0] = name;
    indexBoader++;
    inishowboarder();
    iniMein();

    bool gameLive = false;

    while(!gameLive){
        showborad();
        cout<<"\nPlease enter row and col:";
        int r, c;
        char test;
        cin>>r>>c;
        cout<<"Please choose Flag: [F] or Test: [T]?";
        cin>> test;

        if((r< row && r> -1) && (c < col && c > -1) && check(r,c,test)){
            gameLive = true;
        }
    }
}

void menu(){
    bool exit = true;

    while (exit){
        cout<<"\n===============>> Welcome To My Game <<===============\n";
        cout<<"New Game    -> [1]\n";
        cout<<"Leaderboard -> [2]\n";
        cout<< "Exit       -> [3]\n";
        cout<<"=====================================================\n";


        cout<<"Please Choose a Menu: ";
        int chooseMenu;
        cin>>chooseMenu;
        switch (chooseMenu){
            case 1:
                NewGame();
                break;
            case 2:
                leaderBoard();
                break;
            case 3:
                exit = false;
                break;
        }
    }

}


int main(){
    srand(static_cast<unsigned>(time(nullptr)));
    menu();
//    leaderBoard();
    return 0;
}