//created by islam atef nagy.
//this project needs sum additions such as
/*
 1-colors
 2-clear what was before in the prainting
 3-use symbols instead letters
 4-choose the location with easier way.
 */
#include <iostream>
using namespace std;
class chess
{
private:
    bool succed, killed_the_king = false, white = true,first_white[8]={1,1,1,1,1,1,1,1},first_black[8]={1,1,1,1,1,1,1,1};
    char chess__[8][8];
    
public:
    chess();
    void print();
    void change()
    {
        if (white)
            white = false;
        else
            white = true;
    }
    bool T_or_t(int x, int y, int xx, int yy);
    bool E_or_e(int x, int y, int xx, int yy);
    bool H_or_h(int x, int y, int xx, int yy);
    bool K_or_k(int x, int y, int xx, int yy);
    bool ifpositive(int x);
    bool correct_path_for_white(int x, int y, int xx, int yy);
    bool correct_path_for_black(int x, int y, int xx, int yy);
    void play();
    bool if_ended();
    bool is_empty_field(int x, int y);
};
chess::chess()
{
    chess__[0][0] = 'T';
    chess__[0][1] = 'H';
    chess__[0][2] = 'E';
    chess__[0][3] = 'M';
    chess__[0][4] = 'K';
    chess__[0][5] = 'E';
    chess__[0][6] = 'H';
    chess__[0][7] = 'T';
    for (int i = 0; i < 8; i++)
    chess__[1][i] = 'S';
    for (int i = 2; i < 6; i++)
    {
        for (int t = 0; t < 8; t++)
        {
            chess__[i][t] = ' ';
        }
    }
    chess__[7][0] = 't';
    chess__[7][1] = 'h';
    chess__[7][2] = 'e';
    chess__[7][3] = 'm';
    chess__[7][4] = 'k';
    chess__[7][5] = 'e';
    chess__[7][6] = 'h';
    chess__[7][7] = 't';
    for (int i = 0; i < 8; i++)
    chess__[6][i] = 's';
}
bool chess::ifpositive(int x)
{
    if (x > 0)
        return x;
    else
        return -x;
}
void chess::print()
{
    if (white)
    {
        cout << "\n                 Player White\n\n";
        cout << "        1    2    3    4    5    6    7    8\n";
        cout << "  ::::::::::::::::::::::::::::::::::::::::::::::::\n";
        for (int i = 0; i < 8; i++)
        {
            cout << i + 1 << " ::: ";
            for (int t = 0; t < 8; t++)
            cout << "| " << chess__[i][t] << "  ";
            cout << " :::\n";
            cout << "  .............................................:::\n";
        }
    }
    else
    {
        cout << "\n                 Player Black\n\n";
        cout << "        8    7    6    5    4    3    2    1\n";
        cout << "  ::::::::::::::::::::::::::::::::::::::::::::::::\n";
        for (int i = 7; i >= 0; i--)
        {
            cout << i + 1 << " ::: ";
            for (int t = 7; t >= 0; t--)
            cout << "| " << chess__[i][t] << "  ";
            cout << " :::\n";
            cout << "  .............................................:::\n";
        }
    }
    cout << "  ::::::::::::::::::::::::::::::::::::::::::::::::\n";
}
bool chess::if_ended() //i dont need it;
{
    if (killed_the_king)
    {
        if (!white)
            cout << "Gongratulations\nWhite player win\n";
        else
            cout << "Black player win\n";
        return true;
    }
    return false;
}
bool chess::T_or_t(int x, int y, int xx, int yy)
{
    if (x == xx)
    {
        if (y > yy)
        {
            for (int i = y - 1; i > yy; i--)
            {
                if (chess__[x][i] != ' ')
                {
                    cout << "1\n";
                    return false;
                }
            }
        }
        else
        {
            for (int i = y + 1; i < yy; i++)
            {
                if (chess__[x][i] != ' ')
                {
                    cout << "2\n";
                    return false;
                }
            }
        }
    }
    else if (y == yy)
    {
        if (x > xx)
        {
            for (int i = x - 1; i > xx; i--)
            {
                if (chess__[i][y] != ' ')
                {
                    cout << "1\n";
                    return false;
                }
            }
        }
        else
        {
            for (int i = x + 1; i < xx; i++)
            {
                if (chess__[i][y] != ' ')
                {
                    cout << "2\n";
                    return false;
                }
            }
        }
    }
    return true;
}
bool chess::E_or_e(int x, int y, int xx, int yy)
{
    int x2, y2, x3 = x, y3 = y;
    x2 = ifpositive(x - xx);
    y2 = ifpositive(y - yy);
    if (y2 != x2)
    {
        cout << "y2!=x2 in line 183:\n";
        return false;
    } //?
    else
    {
        if (x > xx && y < yy)
        {
            while (x3 > xx + 1)
            {
                if (chess__[--x3][++y3] != ' ')
                {
                    cout << "1\n";
                    return false;
                }
            }
            return true;
        }
        else if (x > xx && y > yy)
        {
            while (x3 > xx + 1)
            {
                if (chess__[--x3][--y3] != ' ')
                {
                    cout << "2\n";
                    return false;
                }
            }
            return true;
        }
        else if (x < xx && y > yy)
        {
            while (x3 < xx + 1)
            {
                if (chess__[++x3][++y3] != ' ')
                {
                    cout << "3\n";
                    return false;
                }
            }
            return true;
        }
        else if (x < xx && y < yy)
        {
            while (x3 < xx + 1)
            {
                if (chess__[++x3][++y3] != ' ')
                {
                    cout << "4\n";
                    return false;
                }
            }
            return true;
        }
    }
    cout << "5555\n";
    return false;
}
bool chess::H_or_h(int x, int y, int xx, int yy)
{
    if ((x == xx + 1 && y == yy - 2) || (x == xx - 1 && y == yy - 2) || (x == xx - 2 && y == yy + 1) || (x - 2 == xx && y == yy - 1) || (x == xx + 1 && y == yy + 2) || (x == xx - 1 && y == yy + 2) || (x == xx + 1 && y == yy - 2) || (x == xx + 2 && y == yy + 1))
        return true;
    return false;
}
bool chess::K_or_k(int x, int y, int xx, int yy)
{
    if ((((x == xx && y == yy - 1) || (x == xx && y == yy + 1)) || ((y == yy && x == xx - 1) || (y == yy && x == xx + 1))) || (x == xx - 1 && y == yy + 1) || (x == xx - 1 && y == yy - 1) || (x == xx + 1 && y == yy - 1) || (x == xx + 1 && y == yy + 1))
        return true;
    return false;
}
bool chess::correct_path_for_white(int x, int y, int xx, int yy)
{
    // cout<<chess__[x][y]<<endl;
    if (int(chess__[x][y] < 97) || chess__[x][y] == ' ')
        cout << "unavilable place\n";
    else if (chess__[x][y] == 's')
    {
        if(x==xx+2&&y==yy&&first_white[y]&&chess__[x-1][y]&&chess__[x-2][y]==' ')
        {
            first_white[y]=false;
            return true;
        }
        else  if (x == xx + 1 && chess__[xx][yy] == ' ' && y == yy) //note that i cant play solider 2 stebs now i will dp it later
            return true;
        else if ((x == xx + 1 && (y == yy - 1 || y == yy + 1) && chess__[xx][yy] != ' ' && int(chess__[xx][yy]) < 97))
            return true;
        return false;
    }
    else if (chess__[x][y] == 't')
    {
        return T_or_t(x, y, xx, yy);
    }
    else if (chess__[x][y] == 'h')
    {
        return H_or_h(x, y, xx, yy);
    }
    else if (chess__[x][y] == 'k')
    {
        return K_or_k(x, y, xx, yy);
    }
    else if (chess__[x][y] == 'e') //not yet.
    {
        return E_or_e(x, y, xx, yy);
    }
    else if (chess__[x][y] == 'm')
    {
        if (x == xx || y == yy)
            return T_or_t(x, y, xx, yy);
        else
            return E_or_e(x, y, xx, yy);
    }
    return false;
}
bool chess::correct_path_for_black(int x, int y, int xx, int yy)
{
    if (int(chess__[x][y] > 96) || chess__[x][y] == ' ')
        cout << "unavilable place\n";
    else if (chess__[x][y] == 'S') //the same code of white.
    {
        if(x==xx-2&&y==yy&&first_black[y]&&chess__[x+1][y]==' '&&chess__[x+2][y]==' ')
        {
            first_black[y]=false;
            return true;
        }
        else if (x == xx - 1 && chess__[xx][yy] == ' ' && y == yy) //note that i cant play solider 2 stebs now i will dp it later
            return true;
        else if ((x == xx - 1 && (y == yy - 1 || y == yy + 1) && chess__[xx][yy] != ' ' && int(chess__[xx][yy]) > 96))
            return true;
        return false;
    }
    else if (chess__[x][y] == 'T') //the same code of white.
    {
        return T_or_t(x, y, xx, yy);
    }
    else if (chess__[x][y] == 'H') //the same code of white.
    {
        return H_or_h(x, y, xx, yy);
    }
    else if (chess__[x][y] == 'K') //the same code of white.
    {
        return K_or_k(x, y, xx, yy);
    }
    else if (chess__[x][y] == 'E') //the same code of white.
    {
        return E_or_e(x, y, xx, yy);
    }
    else if (chess__[x][y] == 'M') //not yet.
    {
        if (x == xx || y == yy)
            return T_or_t(x, y, xx, yy);
        else
            return E_or_e(x, y, xx, yy);
    }
    return false;
}
void chess::play()
{
zz:
    int pos_x, pos_y;
    //cout<<"Enter The Current Positiont\n";
    cout << "enter current:\n";
    cin >> pos_x >> pos_y;
    pos_x--;
    pos_y--;
    if (chess__[pos_x][pos_y] == ' ' || pos_x > 7 || pos_x < 0 || pos_y > 7 || pos_y < 0)
    {
        cout << "Error=>unvalid possition\n";
        chess::play();
    }
z:
    int new_x, new_y;
    cout << "Enter Your Move\n";
    cin >> new_x >> new_y;
    new_x--;
    new_y--;
    if (new_x > 7 || new_x < 0 || new_y > 7 || new_y < 0)
    {
        cout << "= " << chess__[new_x][new_y] << endl;
        cout << "enter correct position\n";
        goto z;
    }
    if (white)
    {
        
        if (correct_path_for_white(pos_x, pos_y, new_x, new_y))
        {
            if (int(chess__[new_x][new_y]) > 96)
            {
                cout << "you cant kill your self\n";
                goto zz;
            }
            else
            {
                if (chess__[new_x][new_y] == 'K')
                    killed_the_king = true;
                chess__[new_x][new_y] = chess__[pos_x][pos_y];
                chess__[pos_x][pos_y] = ' ';
            }
        }
        else
        {
            cout << "Error=>your move is uncorrect in white\n";
            ;
            goto z;
        }
    }
    else
    {
        if (correct_path_for_black(pos_x, pos_y, new_x, new_y))
        {
            if (int(chess__[new_x][new_y]) < 97 && int(chess__[new_x][new_y]) != 32)
            {
                cout << "you cant kill your self\n";
                goto zz;
            }
            else
            {
                if (chess__[new_x][new_y] == 'k')
                    killed_the_king = true;
                chess__[new_x][new_y] = chess__[pos_x][pos_y];
                chess__[pos_x][pos_y] = ' ';
            }
        }
        else
        {
            cout << "Error=>your move is uncorrect in black\n";
            ;
            goto z;
        }
    }
}
int main()
{
    chess i;
    while (!i.if_ended())
    {
        i.print();
        i.play();
        i.change();
    }
}
//problem in tT
