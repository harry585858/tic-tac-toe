//
//  main.cpp
//  tictactoe
//
//  Created by 양재민 on 12/22/23.
//
#include <iostream>
char state[4][4] = {
    {'*','*','*'}
    ,{'*','*','*'}
    ,{'*','*','*'}
};
using namespace std;
void printstate(){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout << state[i][j];
            cout << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
void change(){
    
}
int ifend(){
    int i;
    if(state[0][0] == state[1][1] && state[1][1] == state[2][2] && (state[0][0] == '1' || state[0][0] == '0')){
        return 1;
    }
    if(state[2][0] == state[1][1] && state[1][1] == state[0][2]  && (state[2][0] == '1' || state[2][0] == '0')){
        return 1;
    }
    for(i = 0; i < 3; i++){
        if(state[i][0] == state[i][1] && state[i][1] == state[i][2]  && (state[i][0] == '1' || state[i][0] == '0')){
            return 1;
        }
        if(state[0][i] == state[1][i] && state[1][i] == state[2][i]  && (state[0][i] == '1' || state[0][i] == '0')){
            return 1;
        }
    }
    return 0;
}
void nextcom(){
    int i;
    if(state[0][0] == state[1][1] || state[1][1] == state[2][2]){
        if(state[1][1] == 0){
            if(state[0][0] == '*'){
                state[0][0] = '0';
                return;
            }
            if(state[2][2] == '*'){
                state[2][2] = '0';
                return;
            }
        }
    }
    if(state[2][0] == state[1][1] || state[1][1] == state[0][2]){
        if(state[1][1] == 0){
            if(state[2][0] == '*'){
                state[2][0] = '0';
                return;
            }
            if(state[0][2] == '*'){
                state[0][2] = '0';
                return;
            }
        }
    }
    for(i = 0; i < 3; i++){
        if(state[i][0] == state[i][1] || state[i][1] == state[i][2]){
            if(state[i][0] == '*'){
                state[i][0] = '0';
                return;
            }
            if(state[i][2] == '*'){
                state[i][2] = '0';
                return;
            }
        }
        if(state[0][i] == state[1][i] && state[1][i] == state[2][i]){
            if(state[0][i] == '*'){
                state[0][i] = '0';
                return;
            }
            if(state[2][i] == '*'){
                state[2][i] = '0';
                return;
            }
        }
        
    }
    if(state[0][0] == state[2][0] && state[1][0] == '*'){
        state[1][0] = '0';
        return;
    }
    if(state[0][0] == state[0][2] && state[0][1] == '*'){
        state[0][1] = '0';
        return;
    }
    if(state[2][2] == state[2][0] && state[1][0] == '*'){
        state[1][0] = '0';
        return;
    }
    if(state[2][2] == state[0][2] && state[0][1] == '*'){
        state[0][1] = '0';
        return;
    }
    
    
    cout << "error" << endl;
}

int main(int argc, const char * argv[]) {
    int turn = 1, count = 1; // 0 is first
    int a, b;
    printstate();
    cout << '0' << " : computer, " <<'1' << " : you, " << '*' << " : blank" << ", input is two integer"<< endl;
    cout << "computer first" << endl;
    state[1][1]= '0';
    printstate();
    while(1){
        if(count == 9){
            break;
        }
        if(turn == 0){
            nextcom();
            if(ifend() == 1) break;
            turn = 1;
            count++;
        }
        else{
            cout << "your turn : ";
            cin >> a >> b;
            if(state[a][b] != '*') cout << "error it's not '*'" << endl;
            state[a][b] = '1';
            if(ifend() == 1) break;
            turn = 0;
            count++;
        }
        printstate();
    }
    if(turn == 0 &&count != 9){
        printstate();
        cout << "computer is win";
    }
    else if(count != 9){
        printstate();
        cout << "you win";
    }
    else{
        cout << "tide";
    }
    return 0;
}
