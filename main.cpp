
#include <iostream>
using namespace std;

class Board{
private:
    char table[3][3]{' ',' ',' ',  ' ',' ',' ' ,  ' ',' ',' '};
    int x,y;
    char player;
    
public:
    Board(){
        player = 'X';
    }
    void draw();
    void player1();
    char winner();
    void Toggle();
};

void Board:: draw(){
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;
    cout << "\t\t\t  0     1     2   " << endl;
    cout << "\t\t  +-----+-----+-----+   " << endl;
    cout << "\t\t0 |" << "  " << table[0][0] << "  |  " << table[0][1] << "  |  " << table[0][2] << "  |  " << endl;
    cout << "\t\t  +-----+-----+-----+   " << endl;
    cout << "\t\t1 |" <<"  " << table[1][0] << "  |  " << table[1][1] << "  |  " << table[1][2] << "  |  " << endl;
    cout << "\t\t  +-----+-----+-----+   " << endl;
    cout << "\t\t2 |" << "  " << table[2][0] << "  |  " << table[2][1] << "  |  " << table[2][2] << "  |  " << endl;
    cout << "\t\t  +-----+-----+-----+   " << endl<<endl;
    }

void Board:: player1(){
    cout<<"Position: " << endl;
    cin >> x >> y ;
    
    while (x<0 || x>3 || y<0 || y>3){
        cout<< "INVALID ENTRY. Enter  coordinates from # 0-2:"<< endl;
        cin >> x >> y;
    }
    
    if (x==0 && y==0 ) {
        if(table[0][0] != (' ')){
            cout<<"Spot taken! Try again "<< endl;
            player1();
        }
        else  table[0][0] = player;
    }
    
    if( x==0 && y==1 ){
        if (table[0][1] != (' ')){
            cout<<"Spot taken! Try again "<< endl;
            player1();
        }
        else table[0][1] = player;
    }
    
    
    if (x==0 && y==2) {
        if(table[0][2] != (' ')){
            cout<<"Spot taken! Try again "<< endl;
            player1();
        }
        else table[0][2] = player;
    }
    
    
    if((x==1 && y==0)) {
        
        if(table[1][0] != (' ')){
            cout<<"Spot taken! Try again "<< endl;
            player1();
        }
        else  table[1][0] = player;
    }
    
    
    if (x==1 && y==1) {
        
        if(table[1][1] != (' ')){
            cout<<"Spot taken! Try again "<< endl;
            player1();
        }
        else table[1][1] = player;
    }
    
    
    if (x==1 && y==2) {
        
        if(table[1][2] != (' ')){
            cout<<"Spot taken! Try again "<< endl;
            player1();
        }
        else table[1][2] = player;
    }
    
    
    if(x==2 && y==0){
        if(table[2][0] != (' ')){
            cout<<"Spot taken! Try again "<< endl;
            player1();
        }
        else table[2][0] = player;
    }
    
    
    if(x==2 && y==1){
        
        if(table[2][1] != (' ')){
            cout<<"Spot taken! Try again "<< endl;
            player1();
        }
        else table[2][1] = player;
    }
    
    
    if (x==2 && y==2) {
        
        if(table[2][2] != (' ')){
            cout<<"Spot taken! Try again "<< endl;
            player1();
        }
        else table[2][2] = player;
        
    }
}

void Board::Toggle(){
    if(player==('X'))
        player = ('O');
    else player =('X');
    
}

char Board:: winner(){
    char draw = ('d') ;

    if(table[0][0]== 'X' && table[0][1]== 'X' && table[0][2]== 'X'){return 'X';}
    if(table[1][0]== 'X' && table[1][1]== 'X' && table[1][2]== 'X'){return 'X';}
    if(table[2][0]== 'X' && table[2][1]== 'X' && table[2][2]== 'X'){return 'X';}

    if(table[0][0]== 'X' && table[1][0]== 'X' && table[2][0]== 'X'){return 'X';}
    if(table[0][1]== 'X' && table[1][1]== 'X' && table[2][1]== 'X'){return 'X';}
    if(table[0][2]== 'X' && table[1][2]== 'X' && table[2][2]== 'X'){return 'X';}

    if(table[0][0]== 'X' && table[1][1]== 'X' && table[2][2]== 'X'){return 'X';}
    if(table[0][2]== 'X' && table[1][1]== 'X' && table[2][0]== 'X'){return 'X';}

    if(table[0][0]== 'O' && table[0][1]== 'O' && table[0][2]== 'O'){ return 'O';}
    if(table[1][0]== 'O' && table[1][1]== 'O' && table[1][2]== 'O'){return 'O';}
    if(table[2][0]== 'O' && table[2][1]== 'O' && table[2][2]== 'O'){return 'O';}

    if(table[0][0]== 'O'&& table[1][0]== 'O' && table[2][0]== 'O'){return 'O';}
    if(table[0][1]== 'O' && table[1][1]== 'O' && table[2][1]== 'O'){return 'O';}
    if(table[0][2]== 'O' && table[1][2]== 'O' && table[2][2]== 'O'){return 'O';}

    if(table[0][0]== 'O' && table[1][1]== 'O' && table[2][2]== 'O'){return 'O';}
    if(table[0][2]== 'O' && table[1][1]== 'O' && table[2][0]== 'O'){return 'O';}
    
    else  return draw;
}


int main(){
    
    cout<<"\t\t Моршки шах"<< endl;
    Board board;
    int counter = 0;
    while(true){
        counter++;
        board.draw();
        board.player1();
        board.Toggle();
        if(board.winner() == 'X'){
            board.draw();
            cout<<"Player 1 Wins! Congratulations !!" << endl; break;
        }
        else if(board.winner()== ('d') && counter == 9){
            cout<<"It's a TIE! Good Game!! " << endl; break;
        }
        if (board.winner() == 'O' ){
            board.draw();
            cout<< "Player 2 Wins! Congratulations !!" << endl; break;
        }
    }
}

