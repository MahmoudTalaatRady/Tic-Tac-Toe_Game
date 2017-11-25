#include <GL/glut.h>
#include "stdfix.h"

#include <math.h>
#define PI 3.14159

int W ;
bool Q ;
int PlayMode ;           //IF=>0 then chose ,=>1 one player , => two players
int matrix[10];         //this Grid stores the x and o and blank box of the game, a value of 0 is blank, 1 is x and 2 is o
int playerturn=0;      //playerTurn if it is 1, then 1st players turn, else if it is 2 then, its second players turn
int result;           //result of the game if it is 0 then draw if it is 1 then player 1 wins if it is 2 then player 2 wins
bool GameOver;       //GameOver if it is 0 then its not game over else if it is 1 then its game over
int A , B ;
int cont=0 ;
///////////////
GLfloat mousex , mousey ;
int circle_points = 100;



//For Only One Player
    int CheckTOWin()
    {
        if(matrix[0]==2 && matrix[1]==2 && matrix[2]!=1)
            return 2 ;
        else if(matrix[1]==2 && matrix[2]==2 && matrix[0]!=1)
            return 0 ;
        else if(matrix[0]==2 && matrix[2]==2 && matrix[1]!=1)
            return 1 ;

        else if(matrix[3]==2 && matrix[4]==2 && matrix[5]!=1)
            return 5 ;
        else if(matrix[4]==2 && matrix[5]==2 && matrix[3]!=1)
            return 3 ;
        else if(matrix[3]==2 && matrix[5]==2 && matrix[4]!=1)
            return 4 ;

        else if(matrix[6]==2 && matrix[7]==2 && matrix[8]!=1)
            return 8 ;
        else if(matrix[7]==2 && matrix[8]==2 && matrix[6]!=1)
            return 6 ;
        else if(matrix[6]==2 && matrix[8]==2 && matrix[7]!=1)
            return 7 ;

        else if(matrix[0]==2 && matrix[3]==2 && matrix[6]!=1)
            return 6 ;
        else if(matrix[3]==2 && matrix[6]==2 && matrix[0]!=1)
            return 0 ;
        else if(matrix[0]==2 && matrix[6]==2 && matrix[3]!=1)
            return 3 ;

        else if(matrix[1]==2 && matrix[4]==2 && matrix[7]!=1)
            return 7 ;
        else if(matrix[4]==2 && matrix[7]==2 && matrix[1]!=1)
            return 1 ;
        else if(matrix[1]==2 && matrix[7]==2 && matrix[4]!=1)
            return 4 ;

        else if(matrix[2]==2 && matrix[5]==2 && matrix[8]!=1)
            return 8 ;
        else if(matrix[5]==2 && matrix[8]==2 && matrix[2]!=1)
            return 2 ;
        else if(matrix[2]==2 && matrix[8]==2 && matrix[5]!=1)
            return 5 ;

        else if(matrix[0]==2 && matrix[4]==2 && matrix[8]!=1)
            return 8 ;
        else if(matrix[4]==2 && matrix[8]==2 && matrix[0]!=1)
            return 0 ;
        else if(matrix[0]==2 && matrix[8]==2 && matrix[4]!=1)
            return 4 ;

        else if(matrix[2]==2 && matrix[4]==2 && matrix[6]!=1)
            return 6 ;
        else if(matrix[4]==2 && matrix[6]==2 && matrix[2]!=1)
            return 2 ;
        else if(matrix[2]==2 && matrix[6]==2 && matrix[4]!=1)
            return 4 ;

        else
        return 10 ;
    }

    int CheckToBlockWin()
    {
        if(matrix[0]==1 && matrix[1]==1 && matrix[2]!=2)
            return 2 ;
        else if(matrix[1]==1 && matrix[2]==1 && matrix[0]!=2)
            return 0 ;
        else if(matrix[0]==1 && matrix[2]==1 && matrix[1]!=2)
            return 1 ;

        else if(matrix[3]==1 && matrix[4]==1 && matrix[5]!=2)
            return 5 ;
        else if(matrix[4]==1 && matrix[5]==1 && matrix[3]!=2)
            return 3 ;
        else if(matrix[3]==1 && matrix[5]==1 && matrix[4]!=2)
            return 4 ;

        else if(matrix[6]==1 && matrix[7]==1 && matrix[8]!=2)
            return 8 ;
        else if(matrix[7]==1 && matrix[8]==1 && matrix[6]!=2)
            return 6 ;
        else if(matrix[6]==1 && matrix[8]==1 && matrix[7]!=2)
            return 7 ;

        else if(matrix[0]==1 && matrix[3]==1 && matrix[6]!=2)
            return 6 ;
        else if(matrix[3]==1 && matrix[6]==1 && matrix[0]!=2)
            return 0 ;
        else if(matrix[0]==1 && matrix[6]==1 && matrix[3]!=2)
            return 3 ;

        else if(matrix[1]==1 && matrix[4]==1 && matrix[7]!=2)
            return 7 ;
        else if(matrix[4]==1 && matrix[7]==1 && matrix[1]!=2)
            return 1 ;
        else if(matrix[1]==1 && matrix[7]==1 && matrix[4]!=2)
            return 4 ;

        else if(matrix[2]==1 && matrix[5]==1 && matrix[8]!=2)
            return 8 ;
        else if(matrix[5]==1 && matrix[8]==1 && matrix[2]!=2)
            return 2 ;
        else if(matrix[2]==1 && matrix[8]==1 && matrix[5]!=2)
            return 5 ;

        else if(matrix[0]==1 && matrix[4]==1 && matrix[8]!=2)
            return 8 ;
        else if(matrix[4]==1 && matrix[8]==1 && matrix[0]!=2)
            return 0 ;
        else if(matrix[0]==1 && matrix[8]==1 && matrix[4]!=2)
            return 4 ;

        else if(matrix[2]==1 && matrix[4]==1 && matrix[6]!=2)
            return 6 ;
        else if(matrix[4]==1 && matrix[6]==1 && matrix[2]!=2)
            return 2 ;
        else if(matrix[2]==1 && matrix[6]==1 && matrix[4]!=2)
            return 4 ;

        else
            return 10 ;
    }


    int CheckMiddlePoint()
    {
        if(matrix[4]==0)
            return 4 ;
        else
            return 10 ;
    }


    int CheckCorners()
    {
        if(matrix[0]==0)
            return 0 ;

        else if(matrix[2]==0)
            return 2 ;

        else if(matrix[6]==0)
            return 6 ;

        else if(matrix[8]==0)
            return 8 ;

        else
            return 10 ;
    }

    int CheckRest()
    {
        if(matrix[7]==0)
            return 7 ;

        else if(matrix[3]==0)
            return 3 ;

        else if(matrix[5]==0)
            return 5 ;

        else if(matrix[1]==0)
            return 1 ;

        else
            return 10 ;
    }


//To Start A New Game
void initgame()
{
        W=0 ;
        playerturn = 1;                     //x starts first
        GameOver=false ;
        PlayMode==0 ;
        cont=0 ;
        //clear the matrix
        for(int i = 0; i <= 8; i++)
        {
            matrix[i] = 0;
        }
}



void GetAB (int i)
{
    //To Draw in the Center of each Grid
            if(i==0)
            {
                    A=27;
                    B=20 ;
            }
            if(i==3)
            {
                    A=27;
                    B=60 ;
            }
            if(i==6)
            {
                    A=27;
                    B=100 ;
            }
            if(i==1)
            {
                    A=81;
                    B=20 ;
            }
            if(i==4)
            {
                    A=81;
                    B=60 ;
            }
            if(i==7)
            {
                    A=81;
                    B=100 ;
            }
            if(i==2)
            {
                    A=135;
                    B=20 ;
            }
            if(i==5)
            {
                    A=135;
                    B=60 ;
            }
            if(i==8)
            {
                     A=135;
                     B=100 ;
            }
}

//Know which position in the matrix
int WhichPosition (GLfloat a , GLfloat b)
{
    if(a>=0 && a<54)
        {
            if(b>=0 && b<40)
                return 0 ;
            if(b>=40 && b<80)
                return 3 ;
            if(b>=80 && b<120)
                return 6 ;
        }

    if(a>=54 && a<108)
        {
            if(b>=0 && b<40)
                return 1 ;
            if(b>=40 && b<80)
                return 4 ;
            if(b>=80 && b<120)
                return 7 ;
        }

        if(a>=108 && a<162)
        {
            if(b>=0 && b<40)
                return 2 ;
            if(b>=40 && b<80)
                return 5 ;
            if(b>=80 && b<120)
                return 8 ;
        }
        if(a>=0 && a<162)
            if(b>=120 && b<=140)
            return 9 ;
}



//BackGround
void BackGround()
{
    glColor3f(0.1961, 0.0 ,0.29411);
    glBegin(GL_POLYGON);
    {
        glVertex2f(0, 0);
        glVertex2f(162, 0);
        glVertex2f(162, 140);
        glVertex2f(0, 140);
    }
        glEnd();
}

//Used to write text in the OpenGL window
void drawString (void * font, char *s, float x, float y){
     glRasterPos2f(x, y);
     for (int i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}


void draw_circle(GLfloat centerx , GLfloat centery , GLfloat radius)
{
    GLdouble theta;
    GLint i;
    glColor3f(0.529411, 0.921568, 0.0);
    glBegin(GL_POLYGON);

    for (i = 0 ; i < circle_points ; ++i)
    {
        theta = 2 * PI * i / circle_points ;
        glVertex2f(centerx + radius * cos(theta), centery + radius * sin(theta));
    }
    glEnd();

}

void  DrawX(int a , int b)
{
    glColor3f(1.0, 1.0, 1.0);
                                glBegin(GL_POLYGON);
                                {
                                    glVertex2f(a-8, b-10);
                                    glVertex2f(a-15, b-10);
                                    glVertex2f(a+8, b+10);
                                    glVertex2f(a+15, b+10);
                                }
                                glEnd();

                                glBegin(GL_LINES);
                                glBegin(GL_POLYGON);
                                {
                                    glVertex2f(a-8, b+10);
                                    glVertex2f(a-15, b+10);
                                    glVertex2f(a+8, b-10);
                                    glVertex2f(a+15, b-10);
                                }
                                glEnd();
}

//DrawGrids
void DrawGrids()
    {

        glColor3f(.772549, .317647, 1.0);
        glBegin(GL_LINES);
        {
            glVertex2f(5, 40);
            glVertex2f(157, 40);

            glVertex2f(5, 80);
            glVertex2f(157, 80);

            glVertex2f(54, 5);
            glVertex2f(54, 119);

            glVertex2f(108, 5);
            glVertex2f(108, 119);


        }
        glEnd();
    }

//Draw the x and o's
void drawxo()
{
        for(int i = 0; i <= 9; i++)
        {
            //To Draw in the Center of each Grid
            GetAB(i) ;
                        if(matrix[i] == 1) //if it is 1 then draw x
                        {
                            DrawX(A,B) ;
                        }
                        else if(matrix[i] == 2) //if it is 2 then draw o
                        {
                                draw_circle(A , B , 15) ;
                        }
        }
}

//To Know Who Is The Winner
bool checkifwin()
{
    if(matrix[0] != 0 && matrix[0] == matrix[3] && matrix[3] == matrix[6])
    {
        W=matrix[0] ;
        return true;
    }
    if(matrix[1] != 0 && matrix[1] == matrix[4] && matrix[4] == matrix[7])
    {
        W=matrix[1] ;
        return true;
    }
    if(matrix[2] != 0 && matrix[2] == matrix[5] && matrix[5] == matrix[8])
    {
        W=matrix[2] ;
        return true;
    }
    if(matrix[0] != 0 && matrix[0] == matrix[1] && matrix[1] == matrix[2])
    {
        W=matrix[0] ;
        return true;
    }
    if(matrix[3] != 0 && matrix[3] == matrix[4] && matrix[4] == matrix[5])
    {
        W=matrix[3] ;
        return true;
    }
    if(matrix[6] != 0 && matrix[6] == matrix[7] && matrix[7] == matrix[8])
    {
        W=matrix[6] ;
        return true;
    }
    if(matrix[0] != 0 && matrix[0] == matrix[4] && matrix[4] == matrix[8])
    {
        W=matrix[0] ;
        return true;
    }
    if(matrix[2] != 0 && matrix[2] == matrix[4] && matrix[4] == matrix[6])
    {
        W=matrix[2] ;
        return true;
    }
    else
        return false;
}

//To Know IF IS Draw
bool checkifdraw()
{
    int draw=0 ;
    for(int i=0 ; i<9 ; i++)
        if(matrix[i]!=0)
        draw ++ ;
        if (draw==9)
            return true ;
    else
        return false ;
}


//The Keyboard Function
void MyKeyboard(unsigned char key, int x, int y ){
    switch(key){

                case '1':
                        if(PlayMode==0)
                        {
                            PlayMode=2 ;
                            glutPostRedisplay();
                        }

                case '2':
                        if(PlayMode==0)
                        {
                            PlayMode=1 ;
                            glutPostRedisplay();
                        }

                case 'r':
                        if(GameOver == false)
                        {
                                initgame();
                                glutPostRedisplay();
                        }
                        break;

                case 'y':
                        if(GameOver == true)
                        {
                                GameOver = false;
                                initgame();
                                glutPostRedisplay();
                        }
                        break;

                case 'n':
                        if(GameOver == true)
                                exit(0);
                        break;

                case 'Y':
                        if(GameOver == true)
                        {
                                GameOver = false;
                                initgame();
                                glutPostRedisplay();
                        }
                        break;

                case 'N':
                        if(GameOver == true)
                                exit(0);
                        break;

                case 27:
                        exit(0);

        }
}

//MouseHandler
void MyMouse(int button, int state , int x, int y)
{
    if(GameOver)
        return;

    if(PlayMode == 2)     //Computer Mode
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
        //to Chang from OpenGL Coordinates to XY Coordinates
        mousex=x*162/800 ;
        mousey=(600-y)*140/600 ;
        int pos ;
        if (mousey>120)
            return ;
        pos=WhichPosition(mousex , mousey);
                        if(matrix[pos] == 0)
                        {
                                matrix[pos] = 1;

                                Q = checkifwin() ;
                                if(cont<4 && Q==false)
                                {
                                //ComputerPlay
                                cont++ ;
                                int P ;
                                while(true)
                                {
                                //ToWin
                                P=CheckTOWin() ;
                                if(P!=10)
                                {
                                    matrix[P]=2 ;
                                    break ;
                                }

                                //ToBlock
                                P=CheckToBlockWin() ;
                                if(P!=10)
                                {
                                    matrix[P]=2 ;
                                    break ;
                                }

                                //TOMid
                                P=CheckMiddlePoint() ;
                                if(P!=10)
                                {
                                    matrix[P]=2 ;
                                    break ;
                                }

                                //ToCorner
                                P=CheckCorners();
                                if(P!=10)
                                {
                                    matrix[P]=2 ;
                                    break ;
                                }

                                //ToRest
                                P=CheckRest() ;
                                if(P!=10)
                                {
                                    matrix[P]=2 ;
                                    break ;
                                }
                            }
                            }
                        }
        }
    }

    if(PlayMode==1)      //Two Players Mode
    {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
        //to Chang from OpenGL Coordinates to XY Coordinates
        mousex=x*162/800 ;
        mousey=(600-y)*140/600 ;
        int pos ;
        if (mousey>120)
            return ;
        pos=WhichPosition(mousex , mousey);

        if(playerturn == 1)
                {
                        if(matrix[pos] == 0)
                        {
                                matrix[pos] = 1;
                                playerturn = 2;
                        }
                }
                else
                {
                        if(matrix[pos] == 0)
                        {
                                matrix[pos] = 2;
                                playerturn = 1;
                        }
                }
        }
    }
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    BackGround() ;

    if(PlayMode == 0)
    {
    glColor3f(0.529411, 0.921568, 0.0);
        drawString(GLUT_BITMAP_HELVETICA_18, "X-O Game", 75, 120);

    glColor3f(1, 0.9490196, 0);
        drawString(GLUT_BITMAP_HELVETICA_18, "Developed By:", 72, 110);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "1-", 10, 85);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Mahmoud Talaat Rady", 17, 85);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "2-", 10, 75);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Amr Ahmed El-Shinawy", 17, 75);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "3-", 10, 65);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Anas Hassan El-Medany", 17, 65);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "4-", 10, 55);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Omar Ahmed El-Deraa", 17, 55);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "5-", 100, 85);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Fedaa Abd El-Hafeiz Ghanim", 105, 85);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "6-", 100, 75);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Mohamed Fawzy Zekr Allah", 105, 75);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "7-", 100, 65);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Tuqa Magdy Yousry", 105, 65);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "8-", 100, 55);

        glColor3f(1,1,1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Aya Adel Nassif", 105, 55);


        glColor3f(1, 0.9490196, 0);
        drawString(GLUT_BITMAP_HELVETICA_18, "Press        To Play One Player", 59, 20);

        glColor3f(0.529411, 0.921568, 0.0);
        drawString(GLUT_BITMAP_HELVETICA_18, "(1)", 70, 20);

        glColor3f(1, 0.9490196, 0);
        drawString(GLUT_BITMAP_HELVETICA_18, "Press        To Play Two Players", 59, 10);

        glColor3f(0.529411, 0.921568, 0.0);
        drawString(GLUT_BITMAP_HELVETICA_18, "(2)", 70, 10);
    }



        if(PlayMode == 1)

        {

        //DrawGrids
        DrawGrids();

        glColor3f(1, 1, 1);
        drawString(GLUT_BITMAP_HELVETICA_18, "To Replay", 4, 130);

        glColor3f(1, 0.9490196, 0);
        drawString(GLUT_BITMAP_HELVETICA_18, "Click R", 6, 125);

        glColor3f(1, 1, 1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Press         To Quit", 125, 130);

        glColor3f(1, 0.9490196, 0);
        drawString(GLUT_BITMAP_HELVETICA_18, "ESC", 135, 130);



        glColor3f(1, 1, 1);
            if(playerturn == 1)
                    drawString(GLUT_BITMAP_HELVETICA_18, "Player1's turn", 70, 130);
            else
                    drawString(GLUT_BITMAP_HELVETICA_18, "Player2's turn", 70, 130);

        // DrawXO
        drawxo();

        if(checkifwin() == true)
        {
                //the player who made the previous move is the winner
                if(playerturn == 1)
                {
                        GameOver = true;
                        result = 2;       //player2 wins
                }
                else
                {
                        GameOver = true;
                        result = 1;      //player1 wins
                }
        }
        else if(checkifdraw() == true)
        {
                GameOver = true;
                result = 0;
        }

        if(GameOver == true)
        {

            glColor4f(0.7843137255, 0.0 ,0.0,.90);
            glBegin(GL_POLYGON);
            {
            glVertex2f(45, 35);
            glVertex2f(115, 35);
            glVertex2f(115, 85);
            glVertex2f(45, 85);
            }
            glEnd();

            glColor3f(1,1,1);
                drawString(GLUT_BITMAP_HELVETICA_18, "X-O Game", 73,70);

            glColor3f(0.529411, 0.921568, 0.0);
                if(result == 0)
                        drawString(GLUT_BITMAP_HELVETICA_18, "Its a draw", 72, 58);

            glColor3f(0.529411, 0.921568, 0.0);
                if(result == 1)
                        drawString(GLUT_BITMAP_HELVETICA_18, "Player1 wins", 72, 58);

            glColor3f(0.529411, 0.921568, 0.0);
                if(result == 2)
                        drawString(GLUT_BITMAP_HELVETICA_18, "Player2 wins", 72, 58);

            glColor3f(1,1,1);
                drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to continue (y/n)", 56, 50);
        }
        }



        if(PlayMode == 2)
        {
            //DrawGrids
        DrawGrids();

        glColor3f(1, 1, 1);
        drawString(GLUT_BITMAP_HELVETICA_18, "To Replay", 4, 130);

        glColor3f(1, 0.9490196, 0);
        drawString(GLUT_BITMAP_HELVETICA_18, "Click R", 6, 125);

        glColor3f(1, 1, 1);
        drawString(GLUT_BITMAP_HELVETICA_18, "Press         To Quit", 125, 130);

        glColor3f(1, 0.9490196, 0);
        drawString(GLUT_BITMAP_HELVETICA_18, "ESC", 135, 130);

        glColor3f(1, 1, 1);
            if(playerturn == 1)
                    drawString(GLUT_BITMAP_HELVETICA_18, "Your Turn", 70, 130);


        drawxo() ;

        if(checkifwin() == true)
        {
                //the player who made the previous move is the winner
                if(W == 1)
                {
                        GameOver = true;
                        result = 1;          //You Win
                }
                else
                {
                        GameOver = true;
                        result = 2;         //You Loss
                }
        }
        else if(checkifdraw() == true)
        {
                GameOver = true;
                result = 0;
        }

        if(GameOver == true)
        {

            glColor4f(0.7843137255, 0.0 ,0.0,.90);
            glBegin(GL_POLYGON);
            {
            glVertex2f(45, 35);
            glVertex2f(115, 35);
            glVertex2f(115, 85);
            glVertex2f(45, 85);
            }
            glEnd();

            glColor3f(1,1,1);
                drawString(GLUT_BITMAP_HELVETICA_18, "X-O Game", 73,70);

            glColor3f(0.529411, 0.921568, 0.0);
                if(result == 0)
                        drawString(GLUT_BITMAP_HELVETICA_18, "Its a draw", 72, 58);

            glColor3f(0.529411, 0.921568, 0.0);
                if(result == 1)
                        drawString(GLUT_BITMAP_HELVETICA_18, "You Win", 72, 58);

            glColor3f(0.529411, 0.921568, 0.0);
                if(result == 2)
                        drawString(GLUT_BITMAP_HELVETICA_18, "You Loss", 72, 58);

            glColor3f(1,1,1);
                drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to continue (y/n)", 56, 50);
        }

        }

    glFlush() ;

}


void init(void)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glViewport(0, 0, 320, 240);

    gluOrtho2D(0.0, 162.0, 0.0, 140.0);
}


int main(int argc, char* argv[])
{

    initgame() ;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("X-O Game");
    init();
    glutKeyboardFunc(MyKeyboard);
    glutMouseFunc(MyMouse);
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
