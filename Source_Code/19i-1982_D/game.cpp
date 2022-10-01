//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<sstream>
using namespace std;

//variables that are globlly declared

float x_1=380;        // x-variale  of the opponent car  
float y_1=30;         // y-varialbe of the opponent car 
float x_2=450;        // x-variale  of the 2-opponent car  
float y_2=700;         // y-varialbe of the 2-opponent car 
float t= 420;       //x- variable of the player car                                
float u= 30;        //y- variable of the player car
int array1[150];    //array that is used to store the food
int z=0;
 
int s=1,v=0,w=4,pau=0,l=1; 
  
string scores,lives,levels;       //strings that are used to display the scores and the lives of the player  


//=============================================================================================================================
//float y1

     void GameMenu(){
                                x_1=380;
                                 y_1=30;
                                 t=350;
                                 u=30;                                //form the first level to  second level 
                                 s=1;
                                 w=3;
                                 v=0;
                                 x_2=450 ;
                                 y_2=700  ; 
         glClearColor(1/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	 glClear (GL_COLOR_BUFFER_BIT); //Update the colors
         DrawSquare( 333, 700 ,180,colors[WHITE]);    
         DrawString( 340, 800,"DODGE GAME", colors[BLUE]);
         DrawString( 360, 750,"MADE BY", colors[BLUE]);
         DrawString( 340, 700,"ABID HUSSAIN", colors[BLUE]);
         DrawString( 340, 500, "NEW GAME ", colors[BLUE]);
         DrawString( 340, 400, "CONTROLS", colors[BLUE]);
         DrawString( 340, 300, "HELP", colors[BLUE]);
         DrawString( 340, 200, "EXIT", colors[BLUE]);
     
     glutSwapBuffers();
}


void message(){
         glClearColor(1/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	 glClear (GL_COLOR_BUFFER_BIT); //Update the colors
DrawString( 240, 450, "You Won!!!!!", colors[BROWN]);
glutSwapBuffers();
}



                                               //function that is made for displaying the menu 
//====================================================================================================================================



// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

//function used to adjust the size of the screen

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

//=====================================================================================================================
                                         //IT IS THE FUNCTION THAT IS USED TO DISPLAY ARENA ,CARS ,FOOD ON THE SCREEN
//=====================================================================================================================
/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0.0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 


//==================================================================================================================
                                             //IT IS FUNCTION USED TO DISPLAY THE SCORE, LIVES, LEVELS ON THE SCREEN
//==================================================================================================================
	//Display Score
	DrawString( 50, 800, "Score=", colors[BROWN]);
        DrawString( 120, 800,scores, colors[GREEN]);
	DrawString( 200, 800, "Lives=", colors[BROWN]);
        DrawString( 270, 800,lives, colors[GREEN]);
	DrawString( 350, 800, "Level=", colors[BROWN]);
        DrawString( 420, 800, levels, colors[GREEN]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	 //Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	

//==================================================================================================
                                                //IT IS THE FUNCYION THAT IS USED TO DISPLAY THE CAR 
                                                //ADJUST ITS ITS POSITION 

//==================================================================================================

                                //IT IS THE FUNCTION THAT IS USEC TO CONVERT THE STRING INTO THE INTEGER 
     
                                ostringstream convert;        //for the conversion of the scores
	                        convert<< v;
                              	scores=convert.str();
                                ostringstream stem;
	                        stem<< w;
	                        lives=stem.str();             //for the conversion of the lives 
                                ostringstream root;
	                        root<< l;                   
	                        levels=root.str();             //for the conversion of the levels
//****************************************************************************************************
                                 if(l==1&&v==140)
                                 {l=2;
                                 x_1=380;
                                 y_1=30;
                                 t=350;
                                 u=30;                                //form the first level to  second level 
                                 s=1;
                                 w=3;
                                 v=0;
                                 x_2=450 ;
                                 y_2=700  ; 
                                  }                                      

                                 if(l==2&&v==140)
                                  {l=3;
                                  x_1=380;
                                  y_1=30;
                                  t=350;                              //form the second level to the third level  
                                  u=30;
                                  s=1;
                                  
                                  w=3;
                                  x_2=450 ;
                                  y_2=700  ;
                                     } 

                                    if(l==3&&v==140)
                                  {l=4;
                                  x_1=380;
                                  y_1=30;
                                  t=350;                              //form the third level to the fourth level  
                                  u=30;
                                  s=1;
                                  v=0;                                 
                                  w=3;
                                 x_2=450 ;
                                 y_2=700  ;
                                   } 




                                     if(l==1&&v==140)
                                  {l=4;
                                  x_1=380;
                                  y_1=30;
                                  t=350;                              //form the third level to the fourth level  
                                  u=30;
                                  s=1;
                                  v=0;
                                  w=3;
                                 x_2=450 ;
                                 y_2=700  ;
                                  }
                                                 //********for displaying the message  **********
                                                       
if(l==4&&v==140)
{glutDisplayFunc(message);
}
//****************************************************************************************************************
//                                                                               for again initializing the value 

//---------------------------------------------------------------------------------------------------------------------------------- 
if (v==140&&z==0)
{
  z=z+1;
  x_1=380;
  y_1=30;
  x_2=450 ;
  y_2=700  ;
  t=350;
  u=30;
for (int i=0;i<140;i++)
 {
   array1[i]=1;
 }
s=0;
}
                                                 
                          //=============================================================================
                               //IT IS THE FUNCTION THAT IS USED TO REDRAW THE FOOD AFTER THE COLLISION
                          //===============================================================================      

                             if ((x_1==t)&&(y_1==u))
                             {
                                 x_1=380;
                                 y_1=30;
                                 t=350;
                                 x_2=450 ;
                                 y_2=700  ;
                                 u=30;
                                 s=1;
                                 w--;
                                 v=0;
                             }  

                       
                             
                              //==========================================================           
                              //if the lives are equal to the zero then display the menu                            
                              //==========================================================

                             if(w==0)
                             {
                               glClearColor(0.0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			       0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	                       glClear (GL_COLOR_BUFFER_BIT); //Update the colors
                               glutDisplayFunc(GameMenu);
                             }
                                                 
//--------------------------------------------------------------------------------------------------------------------------------------

                                       //**********opponent for checking************* 

           
	 float width = 9; 
	 float height = 7;
	 float* color = colors[GREEN]; 
	 float radius = 5.0;
	DrawRoundRect(t,u,width,height,color,radius); // bottom left tyre
	DrawRoundRect(t+width*3,u,width,height,color,radius); // bottom right tyre
	DrawRoundRect(t+width*3,u+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(t,u+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(t, u+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(t+width, u+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(t+width*3, u+height*2, width, height, color, radius/2); // body right rect
       
//---------------------------------------------------------------------------------------------------------------------------------------


                                  //********* PLAYER CAR SIZE CODE*************** 
     
	 width = 9; 
	 height = 7;
	float* clour = colors[BLUE_VIOLET]; 
	 radius = 5.0;
	DrawRoundRect(x_1,y_1,width,height,clour,radius); // bottom left tyre
	DrawRoundRect(x_1+width*3,y_1,width,height,clour,radius); // bottom right tyre
	DrawRoundRect(x_1+width*3,y_1+height*4,width,height,clour,radius); // top right tyre
	DrawRoundRect(x_1,y_1+height*4,width,height,clour,radius); // top left tyre
	DrawRoundRect(x_1, y_1+height*2, width, height, clour, radius/2); // body left rect
	DrawRoundRect(x_1+width, y_1+height, width*2, height*3, clour, radius/2); // body center rect
	DrawRoundRect(x_1+width*3, y_1+height*2, width, height, clour, radius/2); // body right rect

//============================================================================================================
//                                                     level no4
//=============================================================================================================
    
     if (l==4)                                             // Drawing  the 2 opponent car
       { width = 9; 
	 height = 7;
	float* colr = colors[YELLOW]; 
	 radius = 5.0;
	DrawRoundRect(x_2,y_2,width,height,colr,radius); // bottom left tyre
	DrawRoundRect(x_2+width*3,y_2,width,height,colr,radius); // bottom right tyre
	DrawRoundRect(x_2+width*3,y_2+height*4,width,height,colr,radius); // top right tyre
	DrawRoundRect(x_2,y_2+height*4,width,height,colr,radius); // top left tyre
	DrawRoundRect(x_2, y_2+height*2, width, height, colr, radius/2); // body left rect
	DrawRoundRect(x_2+width, y_2+height, width*2, height*3, colr, radius/2); // body center rect
	DrawRoundRect(x_2+width*3, y_2+height*2, width, height, colr, radius/2);}// body right rect    

//=================================================================================================================
                                                          // Drawing Arena
//=================================================================================================================

	int gap_turn = 60;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[ORANGE];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth-50, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight-20+swidth+gap_turn, sheight*2, swidth-50, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+740, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+740, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight-20+swidth+gap_turn, sheight*2, swidth-50, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth-50, scolor); // left down
  
DrawRectangle(sx+50, sy+70, swidth-50, sheight, scolor); // bottom left
DrawRectangle(sx+100, sy+140, swidth-100, sheight, scolor); // bottom left
DrawRectangle(sx+150, sy+210, swidth-150, sheight, scolor); // bottom left
DrawRectangle(sx+200, sy+280, swidth-180, sheight, scolor); // bottom left
DrawRectangle(sx + swidth+ gap_turn, sy+70, swidth-50, sheight, scolor); // bottom right
DrawRectangle(sx + swidth + gap_turn, sy+140, swidth-100, sheight, scolor); // bottom right
DrawRectangle(sx + swidth + gap_turn, sy+210, swidth-150, sheight, scolor); // bottom right
DrawRectangle(sx + swidth-40 + gap_turn, sy+280, swidth-150, sheight, scolor); // bottom right
DrawRectangle(sx+swidth*2-50+gap_turn, sy+sheight+60, sheight, swidth-110, scolor); // right down
DrawRectangle(sx+swidth*2-100+gap_turn, sy+sheight+130, sheight, swidth-180, scolor); // right down
DrawRectangle(sx+swidth*2-150+gap_turn, sy+sheight+200, sheight, swidth-250, scolor); // right down
DrawRectangle(sx+swidth*2-200+gap_turn, sy+sheight+270, sheight, swidth-270, scolor); // right down
DrawRectangle(sx+60-sheight*2, sy+sheight+60, sheight, swidth-110, scolor); // left down
DrawRectangle(sx+110-sheight*2, sy+sheight+130, sheight, swidth-180, scolor); // left down
DrawRectangle(sx+160-sheight*2, sy+sheight+200, sheight, swidth-250, scolor); // left down
DrawRectangle(sx+210-sheight*2, sy+sheight+270, sheight, swidth-270, scolor); // left down

DrawRectangle(sx + swidth + gap_turn, sy+670, swidth-50, sheight, scolor); // top left
DrawRectangle(sx + swidth + gap_turn, sy+600, swidth-100, sheight, scolor); // top left
DrawRectangle(sx + swidth + gap_turn, sy+530, swidth-150, sheight, scolor); // top left
DrawRectangle(sx + swidth-40 + gap_turn, sy+460, swidth-150, sheight, scolor); // top left
DrawRectangle(sx+50, sy+670, swidth-50, sheight, scolor); // top right
DrawRectangle(sx+100, sy+600, swidth-100, sheight, scolor); // top right
DrawRectangle(sx+150, sy+530, swidth-150, sheight, scolor); // top right
DrawRectangle(sx+200, sy+460, swidth-180, sheight, scolor); // top right
DrawRectangle(sx+swidth*2-50+gap_turn, sy+sheight-20+swidth+gap_turn, sheight, swidth-110, scolor); // right up
DrawRectangle(sx+swidth*2-100+gap_turn, sy+sheight-20+swidth+gap_turn, sheight, swidth-180, scolor); // right up
DrawRectangle(sx+swidth*2-150+gap_turn, sy+sheight-20+swidth+gap_turn, sheight, swidth-250, scolor); // right up
DrawRectangle(sx+swidth*2-200+gap_turn, sy+sheight-20+swidth-40+gap_turn, sheight, swidth-280, scolor); // right up
DrawRectangle(sx+60-sheight*2, sy+sheight-20+swidth+gap_turn, sheight, swidth-110, scolor); // left up
DrawRectangle(sx+110-sheight*2, sy+sheight-20+swidth+gap_turn, sheight, swidth-180, scolor); // left up
DrawRectangle(sx+160-sheight*2, sy+sheight-20+swidth+gap_turn, sheight, swidth-250, scolor); // left up
DrawRectangle(sx+210-sheight*2, sy+sheight-20+swidth-40+gap_turn, sheight, swidth-280, scolor); // left up

//=============================================================================
                                        //THIS  IS USED TO REFIILL THE FOOD  
//=============================================================================

                                                          if(s)
                                                          {
                                                            for (int i=0;i<140;i++)
                                                              {
                                                                array1[i]=1;
                                                              }
                                                           s=0;
                                                          }






//==============================================================================

                     //THESE ARRAY ARE USED TO STORES THE FOOD LOCATIONS   
                     //IT IS ALSO USED TO DRAW THE FOOD 
//==============================================================================


                   // 1 line
if (array1[0]){DrawSquare(35,720,10,colors[RED]);}
if (array1[1]){DrawSquare(90,720,10,colors[RED]);
}if (array1[2]){DrawSquare(140,720,10,colors[RED]);
}if (array1[3]){DrawSquare(190,720,10,colors[RED]);
}if (array1[4]){DrawSquare(240,720,10,colors[RED]);
}if (array1[5]){DrawSquare(290,720,10,colors[RED]);
}if (array1[6]){DrawSquare(340,720,10,colors[RED]);
}if (array1[7]){DrawSquare(390,720,10,colors[RED]);
}if (array1[8]){DrawSquare(440,720,10,colors[RED]);
}if (array1[9]){DrawSquare(490,720,10,colors[RED]);
}if (array1[10]){DrawSquare(540,720,10,colors[RED]);
}if (array1[11]){DrawSquare(590,720,10,colors[RED]);
}if (array1[12]){DrawSquare(640,720,10,colors[RED]);
}if (array1[13]){DrawSquare(690,720,10,colors[RED]);
}if (array1[14]){DrawSquare(740,720,10,colors[RED]);
}if (array1[15]){DrawSquare(795,720,10,colors[RED]);

                 //2 line
}if (array1[16]){DrawSquare(35,655,10,colors[RED]);
}if (array1[17]){DrawSquare(90,655,10,colors[RED]);
}if (array1[18]){DrawSquare(140,655,10,colors[RED]);
}if (array1[19]){DrawSquare(190,655,10,colors[RED]);
}if (array1[20]){DrawSquare(240,655,10,colors[RED]);
}if (array1[21]){DrawSquare(290,655,10,colors[RED]);
}if (array1[22]){DrawSquare(340,655,10,colors[RED]);
}if (array1[23]){DrawSquare(390,655,10,colors[RED]);
}if (array1[24]){DrawSquare(440,655,10,colors[RED]);
}if (array1[25]){DrawSquare(490,655,10,colors[RED]);
}if (array1[26]){DrawSquare(540,655,10,colors[RED]);
}if (array1[27]){DrawSquare(590,655,10,colors[RED]);
}if (array1[28]){DrawSquare(640,655,10,colors[RED]);
}if (array1[29]){DrawSquare(690,655,10,colors[RED]);
}if (array1[30]){DrawSquare(740,655,10,colors[RED]);
}if (array1[31]){DrawSquare(795,655,10,colors[RED]);

                 //3 line
}if (array1[32]){DrawSquare(35,580,10,colors[RED]);
}if (array1[33]){DrawSquare(90,580,10,colors[RED]);
}if (array1[34]){DrawSquare(140,580,10,colors[RED]);
}if (array1[35]){DrawSquare(190,580,10,colors[RED]);
}if (array1[36]){DrawSquare(240,580,10,colors[RED]);
}if (array1[37]){DrawSquare(290,580,10,colors[RED]);
}if (array1[38]){DrawSquare(340,580,10,colors[RED]);
}if (array1[39]){DrawSquare(390,580,10,colors[RED]);
}if (array1[40]){DrawSquare(440,580,10,colors[RED]);
}if (array1[41]){DrawSquare(490,580,10,colors[RED]);
}if (array1[42]){DrawSquare(540,580,10,colors[RED]);
}if (array1[43]){DrawSquare(590,580,10,colors[RED]);
}if (array1[44]){DrawSquare(640,580,10,colors[RED]);
}if (array1[45]){DrawSquare(690,580,10,colors[RED]);
}if (array1[46]){DrawSquare(740,580,10,colors[RED]);
}if (array1[47]){DrawSquare(795,580,10,colors[RED]);
 
                 //4 line
}if (array1[48]){DrawSquare(35,500,10,colors[RED]);
}if (array1[49]){DrawSquare(90,500,10,colors[RED]);
}if (array1[50]){DrawSquare(140,500,10,colors[RED]);
}if (array1[51]){DrawSquare(190,500,10,colors[RED]);
}if (array1[52]){DrawSquare(240,500,10,colors[RED]);
}if (array1[53]){DrawSquare(290,500,10,colors[RED]);
}if (array1[54]){DrawSquare(340,500,10,colors[RED]);
}if (array1[55]){DrawSquare(390,500,10,colors[RED]);
}if (array1[56]){DrawSquare(440,500,10,colors[RED]);
}if (array1[57]){DrawSquare(490,500,10,colors[RED]);
}if (array1[58]){DrawSquare(540,500,10,colors[RED]);
}if (array1[59]){DrawSquare(590,500,10,colors[RED]);
}if (array1[60]){DrawSquare(640,500,10,colors[RED]);
}if (array1[61]){DrawSquare(690,500,10,colors[RED]);
}if (array1[62]){DrawSquare(740,500,10,colors[RED]);
}if (array1[63]){DrawSquare(795,500,10,colors[RED]);

              //below 4rt line
}if (array1[64]){DrawSquare(35,430,10,colors[RED]);
}if (array1[65]){DrawSquare(90,430,10,colors[RED]);
}if (array1[66]){DrawSquare(140,430,10,colors[RED]);
}if (array1[67]){DrawSquare(690,430,10,colors[RED]);
}if (array1[68]){DrawSquare(740,430,10,colors[RED]);
}if (array1[69]){DrawSquare(795,430,10,colors[RED]);

              //last line
}if (array1[70]){DrawSquare(35,40,10,colors[RED]);
}if (array1[71]){DrawSquare(90,40,10,colors[RED]);
}if (array1[72]){DrawSquare(140,40,10,colors[RED]);
}if (array1[73]){DrawSquare(190,40,10,colors[RED]);
}if (array1[74]){ DrawSquare(240,40,10,colors[RED]);
}if (array1[75]){DrawSquare(290,40,10,colors[RED]);
}if (array1[76]){DrawSquare(340,40,10,colors[RED]);
}if (array1[77]){DrawSquare(390,40,10,colors[RED]);
}if (array1[78]){DrawSquare(440,40,10,colors[RED]);
}if (array1[79]){DrawSquare(490,40,10,colors[RED]);
}if (array1[80]){DrawSquare(540,40,10,colors[RED]);
}if (array1[81]){DrawSquare(590,40,10,colors[RED]);
}if (array1[82]){DrawSquare(640,40,10,colors[RED]);
}if (array1[83]){DrawSquare(690,40,10,colors[RED]);
}if (array1[84]){DrawSquare(740,40,10,colors[RED]);
}if (array1[85]){DrawSquare(795,40,10,colors[RED]);

                //2 last line
}if (array1[86]){DrawSquare(35,110,10,colors[RED]);
}if (array1[87]){DrawSquare(90,110,10,colors[RED]);
}if (array1[88]){DrawSquare(140,110,10,colors[RED]);
}if (array1[89]){DrawSquare(190,110,10,colors[RED]);
}if (array1[90]){DrawSquare(240,110,10,colors[RED]);
}if (array1[91]){DrawSquare(290,110,10,colors[RED]);
}if (array1[92]){DrawSquare(340,110,10,colors[RED]);
}if (array1[93]){DrawSquare(390,110,10,colors[RED]);
}if (array1[94]){DrawSquare(440,110,10,colors[RED]);
}if (array1[95]){DrawSquare(490,110,10,colors[RED]);
}if (array1[96]){DrawSquare(540,110,10,colors[RED]);
}if (array1[97]){DrawSquare(590,110,10,colors[RED]);
}if (array1[98]){DrawSquare(640,110,10,colors[RED]);
}if (array1[99]){DrawSquare(690,110,10,colors[RED]);
}if (array1[100]){DrawSquare(740,110,10,colors[RED]);
}if (array1[101]){DrawSquare(795,110,10,colors[RED]);

                 //3rd last
}if (array1[102]){DrawSquare(35,190,10,colors[RED]);
}if (array1[103]){DrawSquare(90,190,10,colors[RED]);
}if (array1[104]){DrawSquare(140,190,10,colors[RED]);
}if (array1[105]){DrawSquare(190,190,10,colors[RED]);
}if (array1[106]){DrawSquare(240,190,10,colors[RED]);
}if (array1[107]){DrawSquare(290,190,10,colors[RED]);
}if (array1[108]){DrawSquare(340,190,10,colors[RED]);
}if (array1[109]){DrawSquare(390,190,10,colors[RED]);
}if (array1[110]){DrawSquare(440,190,10,colors[RED]);
}if (array1[111]){DrawSquare(490,190,10,colors[RED]);
}if (array1[112]){DrawSquare(540,190,10,colors[RED]);
}if (array1[113]){DrawSquare(590,190,10,colors[RED]);
}if (array1[114]){DrawSquare(640,190,10,colors[RED]);
}if (array1[115]){DrawSquare(690,190,10,colors[RED]);
}if (array1[116]){DrawSquare(740,190,10,colors[RED]);
}if (array1[117]){DrawSquare(795,190,10,colors[RED]);

                // last 4 line
}if (array1[118]){DrawSquare(35,260,10,colors[RED]);
}if (array1[119]){DrawSquare(90,260,10,colors[RED]);
}if (array1[120]){DrawSquare(140,260,10,colors[RED]);
}if (array1[121]){DrawSquare(190,260,10,colors[RED]);
}if (array1[122]){DrawSquare(240,260,10,colors[RED]);
}if (array1[123]){DrawSquare(290,260,10,colors[RED]);
}if (array1[124]){DrawSquare(340,260,10,colors[RED]);
}if (array1[125]){DrawSquare(390,260,10,colors[RED]);
}if (array1[126]){DrawSquare(440,260,10,colors[RED]);
}if (array1[127]){DrawSquare(490,260,10,colors[RED]);
}if (array1[128]){DrawSquare(540,260,10,colors[RED]);
}if (array1[129]){DrawSquare(590,260,10,colors[RED]);
}if (array1[130]){DrawSquare(640,260,10,colors[RED]);
}if (array1[131]){DrawSquare(690,260,10,colors[RED]);
}if (array1[132]){DrawSquare(740,260,10,colors[RED]);
}if (array1[133]){DrawSquare(795,260,10,colors[RED]);

                 //above last 4rt line
}if (array1[134]){DrawSquare(35,320,10,colors[RED]);
}if (array1[135]){DrawSquare(90,320,10,colors[RED]);
}if (array1[136]){DrawSquare(140,320,10,colors[RED]);
}if (array1[137]){DrawSquare(690,320,10,colors[RED]);
}if (array1[138]){DrawSquare(740,320,10,colors[RED]);
}if (array1[139]){DrawSquare(795,320,10,colors[RED]);}

	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}
//=================================================================================================
                                 //IT IS THE FUNCTION THAT IS USED TO DISPLAY THE MENU INSTRUCTION 
//=================================================================================================


void Gameinstruction(){

glClearColor(148.0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
DrawString( 10, 750, "INSTRUCTIONS::", colors[BLUE]);
DrawString( 10, 650, "(1)PRESS THE 'P' TO PAUSE THE GAME  ", colors[BLUE]);
DrawString( 10, 550, "(2)PRESS THE 'EXIT' TO END THE GAME ", colors[BLUE]);
DrawString( 10, 450, "(3)ALWAYS PALYER START  IN THE CLOCK WISE DIRECTION", colors[BLUE]);
DrawString( 10, 350, "(4)ALWAYS PLAYER START IN THE ANTI CLOCKWISE DIRECTION", colors[BLUE]);
DrawString( 10, 250, "(5)PRESS THE 'SPACE TO SPEED UP'", colors[BLUE]);
DrawString( 10, 50, "EXIT", colors[BLUE]);
glutSwapBuffers();

}



//=============================================================================================================

                                    //IT IS THE LOOP THAT IS USED TO GIVE THE CONTROL INSTRUCTION IN THE MENU
//==============================================================================================================

void Control_Max(){

glClearColor(148.0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
DrawString( 10, 750, "CONTROLS::", colors[BLUE]);
DrawString( 10, 650, "(1)PRESS FORWARD KEY TO MOVE AHEAD  ", colors[BLUE]);
DrawString( 10, 550, "(2)PRESS BACKWARD KEY TO MOVE BACK", colors[BLUE]);
DrawString( 10, 450, "(3)PRESS RIGHT KEY TO MOVE RIGHT", colors[BLUE]);
DrawString( 10, 350, "(4)PRESS LEFT KEY TO MOVE LEFT", colors[BLUE]);
DrawString( 10, 50, "EXIT", colors[BLUE]);

glutSwapBuffers();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                    //IT IS THE FUNCTION THAT IS USED TO GIVE THE MAXIMUM SCORE IN THE MENU 

void Score_Max()
                 {

                        glClearColor(148.0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	                glClear (GL_COLOR_BUFFER_BIT); //Update the colors
                        
                                ostringstream convert;
	                        convert<< v;
                              	scores=convert.str();
                       DrawString( 120, 800,scores, colors[GREEN]);
                      
                        glutSwapBuffers();
                 }
//-------------------------------------------------------------------------------------------------------------------------------



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */




                               void NonPrintableKeys(int key, int x, int y) {
	                   if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
                           {
		// what to do when left key is pressed...
                          if((u>=310&&u<=440)&&t<=795)
                          {t=t-50;
                        
		          }
        } 
                         else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
                   
                           {

                           if((u>=320&&u<=430)&&t<=795)
                          {t=t+50;                           
		           }


                        	} 
                       else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) 
                         {
                           if((t>=380&&t<=440)&&u<=720)
                          {u=u+70;
                         }




                 	}

	               else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) 
                      {
                        if((t>=380&&t<=440)&&u>=40)
                          {u=u-70;  
                          }

                                                 }


/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
 * this function*/




	    glutPostRedisplay();

                   }


//--------------------------------------------------------------------------------------------------------------

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

                                   //these keys are used to pause the game and exit the game 


void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'p' || key == 'P')                               //pauses the game when the 'P' is pressed 
			{
                    pau++;
		
		cout << "p pressed" << endl;
                                          
	}
//---------------------------------------------------------------------------------------------------------------------------------------
//                                             used to speed up the player when the spacekey is pressed
//----------------------------------------------------------------------------------------------------------------------------------------
                       if(key==32)
{
if(u==30&&t!=20)                                                                          
{t=t-10;}
else if(t==20&&u!=700)                  //first arena 
{u=u+10;}
else if(u==700&&t!=780)
{t=t+10;}
else if(t==780&&u!=30)
{u=u-10;}                               //second arena 
else if(u==100&&t!=70)
{t=t-10;}
else if(t==70&&u!=630)
{u=u+10;}
else if(u==630&&t!=730)
{t=t+10;}
else if(t==730&&u!=100)
{u=u-10;}
                                    //third arena 
else if(u==170&&t!=120)
{t=t-10;}
else if(t==120&&u!=560)
{u=u+10;}
else if(u==560&&t!=680)
{t=t+10;}
else if(t==680&&u!=170)
{u=u-10;}

                                            //fourth arena 
else if(u==240&&t!=170)
{t=t-10;}
else if(t==170&&u!=490)
{u=u+10;}
else if(u==490&&t!=630)
{t=t+10;}
else if(t==630&&u!=240)
{u=u-10;}

}
                                                         
	glutPostRedisplay();
}
  //----------------------------------------------------------------------------------------------------------------------------------
/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	// once again we tell the library to call our Timer function after next 1000/FPS

                                                       //IT IS USED TO DRIVE THE CAR OF THE OPPONENT 
if (pau%2!=0)
{u=u;
t=t;
}
else
{
 if (y_1==30&&x_1!=780)
{
x_1=x_1+10;
}

else if(x_1==780&&y_1!=700)
{
y_1=y_1+10;
}
else if(y_1==700&&x_1!=20)
{
x_1=x_1-10;
}

else if(x_1==20&&y_1!=30)
{
y_1=y_1-10;
}

//2 arena
else if (y_1==630&&x_1!=70)
{
x_1=x_1-10;
}
else if (x_1==70&&y_1!=100)
{
y_1=y_1-10;
}
else if (y_1==100&&x_1!=730)
{
x_1=x_1+10;
}
else if(x_1==730&&y_1!=630)
{
y_1=y_1+10;
}
//3arena 
else if(y_1==560&&x_1!=120)
{
x_1=x_1-10;
}
else if (x_1==120&&y_1!=170)
{
y_1=y_1-10;
}
else if(y_1==170&&x_1!=680)
{
x_1=x_1+10;
}
else if (x_1==680&&y_1!=560)
{
y_1=y_1+10;
}
//4th arena 
else if (y_1==490&&x_1!=170)
{
x_1=x_1-10;
}
else if (x_1==170&&y_1!=240)
{
y_1=y_1-10;
}
else if(y_1==240&&x_1!=630)
{
x_1=x_1+10;
}
else if(x_1==630&&y_1!=490)
{
y_1=y_1+10;
}
/* ****************************************************************************************************************************************                                       
                                                condition for the intellegence of the opponent  
                                                                         level 1
                                                                                            
**************************************************************************************************************************************** */   if(l==2||l==3||l==4)
{
                                                     
if(y_1-70==u &&x_1>=380&&x_1<=440&&y_1==700)                      //condition for the first loop
{y_1=y_1-70;}                                                                 //downward movement
if(y_1+70==u &&x_1>=380&&x_1<=440&&y_1==30)                       //condition for the first loop
{y_1=y_1+70;}                                                                 //upward movement 
if(y_1-70==u &&x_1>=380&&x_1<=440&&y_1==630)                      //condition for the second loop                   
{y_1=y_1-70;}                                                                 //downward movement
if(y_1+70==u &&x_1>=380&&x_1<=440&&y_1==100)                       //condition for the second loop
{y_1=y_1+70;}                                                                  //upward movement    
if(y_1+70==u &&x_1>=380&&x_1<=440&&y_1==170)                      //condition for the third loop
{y_1=y_1+70;}                                                                 //upward movement 
if(y_1-70==u &&x_1>=380&&x_1<=440&&y_1==560)                      //condition for the third loop
{y_1=y_1-70;}                                                            
                                                                               //downward loop                                                                
//--------------------------------------------------------------------------------------------------------------------------------------   


if(y_1+70==u &&x_1>=380&&x_1<=440&&y_1==630)                      //condition for the second loop                   
{y_1=y_1+70;}                                                         //up to upward movement  "second  top to first top"
if(y_1-70==u &&x_1>=380&&x_1<=440&&y_1==100)                       //condition for the second loop
{y_1=y_1-70;}                                                          // down to downward movement "second bottom to firstbottom"   
if(y_1-70==u &&x_1>=380&&x_1<=440&&y_1==170)                      //condition for the third loop
{y_1=y_1-70;}                                                          //down to down movwment "third  bottom to second  bottom"
if(y_1+70==u &&x_1>=380&&x_1<=440&&y_1==560)                      //condition for the third loop
{y_1=y_1+70;}                                                           //up to up movement    "third top to second bottom"
if(y_1-70==u &&x_1>=380&&x_1<=440&&y_1==240)                       //condition for the fouth  loop
{y_1=y_1-70;}                                                            //down to down movement "fourth  bottom to third  bottom"


   //                                                      intellegence from the left right
 //                                                              level 2
/******************************************************************************************************************************************/

//                                                           right ward movement
//****************************************************************************************************************************************
if(l==2||l==3||l==4)
{if(x_1+50==t &&y_1>=310&&y_1<=440&&x_1==20)                      //condition for the first loop
{x_1=x_1+50;}                                                                 //right ward  movement"first to second"
 if(x_1+50==t &&y_1>=310&&y_1<=440&&x_1==70)                      //condition for the second loop
{x_1=x_1+50;}                                                                  //right ward  movement                                                                  "second to the third"             
if(x_1+50==t &&y_1>=310&&y_1<=440&&x_1==120)                      //condition for the third loop 
{x_1=x_1+50;}                                                                   //right ward  movement "third to the fourth
 
if(x_1-50==t &&y_1>=310&&y_1<=440&&x_1==170)                      //condition for the fourth loop
{x_1=x_1-50;}                                                                 //right ward  movement"fourth to third"
 if(x_1-50==t &&y_1>=310&&y_1<=440&&x_1==120)                      //condition for the third loop
{x_1=x_1-50;}                                                                  //right ward  movement                                                                  "third to the second "             
if(x_1-50==t &&y_1>=310&&y_1<=440&&x_1==70)                      //condition for the second loop 
{x_1=x_1-50;}                                                                   //right ward  movement "second to the first " 

//***************************************************************************************************************************************

//                                                          left ward movement 
//**************************************************************************************************************************************
if(x_1-50==t &&y_1>=310&&y_1<=440&&x_1==780)                      //condition for the left first loop
{x_1=x_1-50;}                                                                 //right ward  movement"first to second"
 if(x_1-50==t &&y_1>=310&&y_1<=440&&x_1==730)                      //condition for the left second loop
{x_1=x_1-50;}                                                                  //right ward  movement                                                                  "second to the third"             
if(x_1-50==t &&y_1>=310&&y_1<=440&&x_1==680)                      //condition for the left third loop 
{x_1=x_1-50;}                                                                   //right ward  movement "third to the fourth
 


if(x_1+50==t &&y_1>=310&&y_1<=440&&x_1==630)                      //condition for the fourth loop
{x_1=x_1+50;}

                                                                 //left ward  movement"fourth to third"
 if(x_1+50==t &&y_1>=310&&y_1<=440&&x_1==680)                      //condition for the third loop
{x_1=x_1+50;}                                                                  //left ward  movement                                                                  "third to the second "             
if(x_1+50==t &&y_1>=310&&y_1<=440&&x_1==730)                      //condition for the second loop 
{x_1=x_1+50;}                                                                   //left  ward  movement "second to the first" 

//****************************************************************************************************************************************
  //                                                      right ward movement //jump
//***************************************************************************************************************************************** 
if(x_1+100==t &&y_1>=310&&y_1<=440&&x_1==20)                      //condition for the first loop
{x_1=x_1+100;}                                                                 //right ward  movement"first to third"
if(x_1+100==t &&y_1>=310&&y_1<=440&&x_1==70)                      //condition for the second loop
{x_1=x_1+100;}                                                                 //right ward  movement"second to fourth"
if(x_1-100==t &&y_1>=310&&y_1<=440&&x_1==780)                      //condition for the left first loop
{x_1=x_1-100;}                                                                 //right ward  movement"first to third"
if(x_1-100==t &&y_1>=310&&y_1<=440&&x_1==730)                      //condition for the left first loop
{x_1=x_1-100;}                                                                 //right ward  movement"second  to fourth"

//***************************************************************************************************************************************
 //                                                            left ward movement jump 
//****************************************************************************************************************************************
if(x_1-100==t &&y_1>=310&&y_1<=440&&x_1==170)                      //condition for the fourth loop
{x_1=x_1-100;}                                                                 //right ward  movement"fourth to second"
if(x_1-100==t &&y_1>=310&&y_1<=440&&x_1==120)                      //condition for the third loop
{x_1=x_1-100;}                                                                 //right ward  movement"third to first"
if(x_1+100==t &&y_1>=310&&y_1<=440&&x_1==630)                      //condition for the left fourth loop
{x_1=x_1+100;}                                                                 //right ward  movement"fourth to second "
if(x_1+100==t &&y_1>=310&&y_1<=440&&x_1==680)                      //condition for the left third loop
{x_1=x_1+100;}                                                                 //right ward  movement"third  to first "
//**************************************************************************************************************************************
//                                                             downward  movement jump
//***************************************************************************************************************************************
if(y_1-140==u &&x_1>=380&&x_1<=440&&y_1==700)                      //condition for the first loop
{y_1=y_1-140;}                                                                 //downward movement "first  to third"
if(y_1-140==u &&x_1>=380&&x_1<=440&&y_1==630)                      //condition for the second loop                   
{y_1=y_1-140;}                                                                 //downward movement "second to the fourth"  
if(y_1+140==u &&x_1>=380&&x_1<=440&&y_1==240)                      //condition for the fourth loop
{y_1=y_1+140;}                                                                 //downward movement "fourth  to second "
if(y_1+140==u &&x_1>=380&&x_1<=440&&y_1==560)                      //condition for the third loop                   
{y_1=y_1+140;}                                                                 //downward movement "third to the first "  
//****************************************************************************************************************************************
//                                                            upward movement jump
//***************************************************************************************************************************************
if(y_1+140==u &&x_1>=380&&x_1<=440&&y_1==30)                      //condition for the first loop
{y_1=y_1+140;}                                                                 //downward movement "first  to third"
if(y_1+140==u &&x_1>=380&&x_1<=440&&y_1==100)                      //condition for the second loop                   
{y_1=y_1+140;}                                                                 //downward movement "second to the fourth"  
if(y_1-140==u &&x_1>=380&&x_1<=440&&y_1==240)                      //condition for the fourth loop
{y_1=y_1-140;}                                                                 //downward movement "fourth  to third"
if(y_1-140==u &&x_1>=380&&x_1<=440&&y_1==170)                      //condition for the third loop                   
{y_1=y_1-140;}                                                                 //downward movement "third to the first"  
}
//--------------------------------------------------------------------------------------------------------------------------------------
}
}

if(l==2||l==1)
 {glutPostRedisplay();                                                             //condition of timer for level1 and level2

              glutTimerFunc(100.0, Timer, 0);}



if(l==3||l==4)
{ 
glutPostRedisplay();                                                               //condition for the level3

              glutTimerFunc(60.0, Timer, 0);}


}

                    void timmer(int m){


if (pau%2!=0)
{x_2=x_2;
y_2=y_2;
}
 
else{//first arena
if (y_2==30&&x_2!=780)
{
x_2=x_2+10;
}

else if(x_2==780&&y_2!=700)
{
y_2=y_2+10;
}
else if(y_2==700&&x_2!=20)
{
x_2=x_2-10;
}

else if(x_2==20&&y_2!=30)
{
y_2=y_2-10;
}
//2 arena
else if (y_2==630&&x_2!=70)
{
x_2=x_2-10;
}
else if (x_2==70&&y_2!=100)
{
y_2=y_2-10;
}
else if (y_2==100&&x_2!=730)
{
x_2=x_2+10;
}
else if(x_2==730&&y_2!=630)
{
y_2=y_2+10;
}
//3arena 
else if(y_2==560&&x_2!=120)
{
x_2=x_2-10;
}
else if (x_2==120&&y_2!=170)
{
y_2=y_2-10;
}
else if(y_2==170&&x_2!=680)
{
x_2=x_2+10;
}
else if (x_2==680&&y_2!=560)
{
y_2=y_2+10;
}
//4th arena 
else if (y_2==490&&x_2!=170)
{
x_2=x_2-10;
}
else if (x_2==170&&y_2!=240)
{
y_2=y_2-10;
}
else if(y_2==240&&x_2!=630)
{
x_2=x_2+10;
}
else if(x_2==630&&y_2!=490)
{
y_2=y_2+10;
}

}


if(l==4)
{
/* ****************************************************************************************************************************************                                       
                                                condition for the intellegence of the opponent  
                                                                         level 1
                                                                                            
**************************************************************************************************************************************** */
                                                     
if(y_2-70==u &&x_2>=380&&x_2<=440&&y_2==700)                      //condition for the first loop
{y_1=y_1-70;}                                                                 //downward movement
if(y_2+70==u &&x_2>=380&&x_2<=440&&y_2==30)                       //condition for the first loop
{y_2=y_2+70;}                                                                 //upward movement 
if(y_2-70==u &&x_2>=380&&x_2<=440&&y_2==630)                      //condition for the second loop                   
{y_2=y_2-70;}                                                                 //downward movement
if(y_2+70==u &&x_2>=380&&x_2<=440&&y_2==100)                       //condition for the second loop
{y_2=y_2+70;}                                                                  //upward movement    
if(y_2+70==u &&x_2>=380&&x_2<=440&&y_2==170)                      //condition for the third loop
{y_2=y_2+70;}                                                                 //upward movement 
if(y_2-70==u &&x_2>=380&&x_2<=440&&y_2==560)                      //condition for the third loop
{y_2=y_2-70;}                                                            
                                                                               //downward loop                                                                
//--------------------------------------------------------------------------------------------------------------------------------------   


if(y_2+70==u &&x_2>=380&&x_2<=440&&y_2==630)                      //condition for the second loop                   
{y_2=y_2+70;}                                                         //up to upward movement  "second  top to first top"
if(y_2-70==u &&x_2>=380&&x_2<=440&&y_2==100)                       //condition for the second loop
{y_2=y_2-70;}                                                          // down to downward movement "second bottom to firstbottom"   
if(y_2-70==u &&x_2>=380&&x_2<=440&&y_2==170)                      //condition for the third loop
{y_2=y_2-70;}                                                          //down to down movwment "third  bottom to second  bottom"
if(y_2+70==u &&x_2>=380&&x_2<=440&&y_2==560)                      //condition for the third loop
{y_2=y_2+70;}                                                           //up to up movement    "third top to second bottom"
if(y_2-70==u &&x_2>=380&&x_2<=440&&y_2==240)                       //condition for the fouth  loop
{y_2=y_2-70;}                                                            //down to down movement "fourth  bottom to third  bottom"


   //                                                      intellegence from the left right
 //                                                              level 2
/******************************************************************************************************************************************/

//                                                           right ward movement
//****************************************************************************************************************************************

if(x_2+50==t &&y_2>=310&&y_2<=440&&x_2==20)                      //condition for the first loop
{x_2=x_2+50;}                                                                 //right ward  movement"first to second"
 if(x_2+50==t &&y_2>=310&&y_2<=440&&x_2==70)                      //condition for the second loop
{x_2=x_2+50;}                                                                  //right ward  movement                                                                  "second to the third"             
if(x_2+50==t &&y_2>=310&&y_2<=440&&x_2==120)                      //condition for the third loop 
{x_2=x_2+50;}                                                                   //right ward  movement "third to the fourth
 
if(x_2-50==t &&y_2>=310&&y_2<=440&&x_2==170)                      //condition for the fourth loop
{x_2=x_2-50;}                                                                 //right ward  movement"fourth to third"
 if(x_2-50==t &&y_2>=310&&y_2<=440&&x_2==120)                      //condition for the third loop
{x_2=x_2-50;}                                                                  //right ward  movement                                                                  "third to the second "             
if(x_2-50==t &&y_2>=310&&y_2<=440&&x_2==70)                      //condition for the second loop 
{x_2=x_2-50;}                                                                   //right ward  movement "second to the first " 

//***************************************************************************************************************************************

//                                                          left ward movement 
//**************************************************************************************************************************************
if(x_2-50==t &&y_2>=310&&y_2<=440&&x_2==780)                      //condition for the left first loop
{x_2=x_2-50;}                                                                 //right ward  movement"first to second"
 if(x_2-50==t &&y_2>=310&&y_2<=440&&x_2==730)                      //condition for the left second loop
{x_2=x_2-50;}                                                                  //right ward  movement                                                                  "second to the third"             
if(x_2-50==t &&y_2>=310&&y_2<=440&&x_2==680)                      //condition for the left third loop 
{x_2=x_2-50;}                                                                   //right ward  movement "third to the fourth
 


if(x_2+50==t &&y_2>=310&&y_2<=440&&x_2==630)                      //condition for the fourth loop
{x_2=x_2+50;}

                                                                 //left ward  movement"fourth to third"
 if(x_2+50==t &&y_2>=310&&y_2<=440&&x_2==680)                      //condition for the third loop
{x_2=x_2+50;}                                                                  //left ward  movement                                                                  "third to the second "             
if(x_2+50==t &&y_2>=310&&y_2<=440&&x_2==730)                      //condition for the second loop 
{x_2=x_2+50;}                                                                   //left  ward  movement "second to the first" 

//****************************************************************************************************************************************
  //                                                      right ward movement //jump
//***************************************************************************************************************************************** 
if(x_2+100==t &&y_2>=310&&y_2<=440&&x_2==20)                      //condition for the first loop
{x_2=x_2+100;}                                                                 //right ward  movement"first to third"
if(x_2+100==t &&y_2>=310&&y_2<=440&&x_2==70)                      //condition for the second loop
{x_2=x_2+100;}                                                                 //right ward  movement"second to fourth"
if(x_2-100==t &&y_2>=310&&y_2<=440&&x_2==780)                      //condition for the left first loop
{x_2=x_2-100;}                                                                 //right ward  movement"first to third"
if(x_2-100==t &&y_2>=310&&y_2<=440&&x_2==730)                      //condition for the left first loop
{x_2=x_2-100;}                                                                 //right ward  movement"second  to fourth"

//***************************************************************************************************************************************
 //                                                            left ward movement jump 
//****************************************************************************************************************************************
if(x_2-100==t &&y_2>=310&&y_2<=440&&x_2==170)                      //condition for the fourth loop
{x_2=x_2-100;}                                                                 //right ward  movement"fourth to second"
if(x_2-100==t &&y_2>=310&&y_2<=440&&x_2==120)                      //condition for the third loop
{x_2=x_2-100;}                                                                 //right ward  movement"third to first"
if(x_2+100==t &&y_2>=310&&y_2<=440&&x_2==630)                      //condition for the left fourth loop
{x_2=x_2+100;}                                                                 //right ward  movement"fourth to second "
if(x_2+100==t &&y_2>=310&&y_2<=440&&x_2==680)                      //condition for the left third loop
{x_2=x_2+100;}                                                                 //right ward  movement"third  to first "
//**************************************************************************************************************************************
//                                                             downward  movement jump
//***************************************************************************************************************************************
if(y_2-140==u &&x_2>=380&&x_2<=440&&y_2==700)                      //condition for the first loop
{y_1=y_1-140;}                                                                 //downward movement "first  to third"
if(y_2-140==u &&x_2>=380&&x_2<=440&&y_2==630)                      //condition for the second loop                   
{y_2=y_2-140;}                                                                 //downward movement "second to the fourth"  
if(y_2+140==u &&x_2>=380&&x_2<=440&&y_2==240)                      //condition for the fourth loop
{y_2=y_2+140;}                                                                 //downward movement "fourth  to second "
if(y_2+140==u &&x_2>=380&&x_2<=440&&y_2==560)                      //condition for the third loop                   
{y_2=y_2+140;}                                                                 //downward movement "third to the first "  
//****************************************************************************************************************************************
//                                                            upward movement jump
//***************************************************************************************************************************************
if(y_2+140==u &&x_2>=380&&x_2<=440&&y_2==30)                      //condition for the first loop
{y_2=y_2+140;}                                                                 //downward movement "first  to third"
if(y_2+140==u &&x_2>=380&&x_2<=440&&y_2==100)                      //condition for the second loop                   
{y_2=y_2+140;}                                                                 //downward movement "second to the fourth"  
if(y_2-140==u &&x_2>=380&&x_2<=440&&y_2==240)                      //condition for the fourth loop
{y_2=y_2-140;}                                                                 //downward movement "fourth  to third"
if(y_2-140==u &&x_2>=380&&x_2<=440&&y_2==170)                      //condition for the third loop                   
{y_2=y_2-140;}                                                                 //downward movement "third to the first"  

//--------------------------------------------------------------------------------------------------------------------------------------
}
              glutPostRedisplay();                                                               //timer  for the level4
              glutTimerFunc(60.0, timmer, 0);}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                             // IT IS USED TO DRIVE THE CAR OF THE PLAYER


//USED TO STOP THE CAR
   void Clock(int m){
   if (pau%2!=0)
   {u=u;
   t=t;}
   else
   {
                           //first arena 
if(u==30&&t!=20)
{t=t-10;}
else if(t==20&&u!=700)
{u=u+10;}
else if(u==700&&t!=780)
{t=t+10;}
else if(t==780&&u!=30)
{u=u-10;}
                               //second arena 
else if(u==100&&t!=70)
{t=t-10;}
else if(t==70&&u!=630)
{u=u+10;}
else if(u==630&&t!=730)
{t=t+10;}
else if(t==730&&u!=100)
{u=u-10;}
                                    //third arena 
else if(u==170&&t!=120)
{t=t-10;}
else if(t==120&&u!=560)
{u=u+10;}
else if(u==560&&t!=680)
{t=t+10;}
else if(t==680&&u!=170)
{u=u-10;}

                                            //fourth arena 
else if(u==240&&t!=170)
{t=t-10;}
else if(t==170&&u!=490)
{u=u+10;}
else if(u==490&&t!=630)
{t=t+10;}
else if(t==630&&u!=240)
{u=u-10;}

}
                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                            //USED TO SET THE RANGE OF THE FOOD TO PICK UP BY THE CAR

//1 line
if(t==20&&u==700)
{if(array1[0]==1){v++;cout<<"\a";}array1[0]=0;}
if(t==70&&u==700)
{if(array1[1]==1){v++;cout<<"\a";}array1[1]=0;}
if(t==120&&u==700)
{if(array1[2]==1){v++;cout<<"\a";}array1[2]=0;}
if(t==170&&u==700)
{if(array1[3]==1){v++;cout<<"\a";}array1[3]=0;}
if(t==220&&u==700)
{if(array1[4]==1){v++;cout<<"\a";}array1[4]=0;}
if(t==270&&u==700)
{if(array1[5]==1){v++;cout<<"\a";}array1[5]=0;}
if(t==320&&u==700)
{if(array1[6]==1){v++;cout<<"\a";}array1[6]=0;}
if(t==370&&u==700)
{if(array1[7]==1){v++;cout<<"\a";}array1[7]=0;}
if(t==420&&u==700)
{if(array1[8]==1){v++;cout<<"\a";}array1[8]=0;}
if(t==470&&u==700)
{if(array1[9]==1){v++;cout<<"\a";}array1[9]=0;}
if(t==520&&u==700)
{if(array1[10]==1){v++;cout<<"\a";}array1[10]=0;}
if(t==570&&u==700)
{if(array1[11]==1){v++;cout<<"\a";}array1[11]=0;}
if(t==620&&u==700)
{if(array1[12]==1){v++;cout<<"\a";}array1[12]=0;}
if(t==680&&u==700)
{if(array1[13]==1){v++;cout<<"\a";}array1[13]=0;}
if(t==730&&u==700)
{if(array1[14]==1){v++;cout<<"\a";}array1[14]=0;}
if(t==780&&u==700)
{if(array1[15]==1){v++;cout<<"\a";}array1[15]=0;}


//2 line 

if(t==20&&u==630)
{if(array1[16]==1){v++;cout<<"\a";}array1[16]=0;}
if(t==70&&u==630)
{if(array1[17]==1){v++;cout<<"\a";}array1[17]=0;}
if(t==120&&u==630)
{if(array1[18]==1){v++;cout<<"\a";}array1[18]=0;}
if(t==170&&u==630)
{if(array1[19]==1){v++;cout<<"\a";}array1[19]=0;}
if(t==220&&u==630)
{if(array1[20]==1){v++;cout<<"\a";}array1[20]=0;}
if(t==270&&u==630)
{if(array1[21]==1){v++;cout<<"\a";}array1[21]=0;}
if(t==320&&u==630)
{if(array1[22]==1){v++;cout<<"\a";}array1[22]=0;}
if(t==370&&u==630)
{if(array1[23]==1){v++;cout<<"\a";}array1[23]=0;}
if(t==420&&u==630)
{if(array1[24]==1){v++;cout<<"\a";}array1[24]=0;}
if(t==470&&u==630)
{if(array1[25]==1){v++;cout<<"\a";}array1[25]=0;}
if(t==520&&u==630)
{if(array1[26]==1){v++;cout<<"\a";}array1[26]=0;}
if(t==570&&u==630)
{if(array1[27]==1){v++;cout<<"\a";}array1[27]=0;}
if(t==620&&u==630)
{if(array1[28]==1){v++;cout<<"\a";}array1[28]=0;}
if(t==670&&u==630)
{if(array1[29]==1){v++;cout<<"\a";}array1[29]=0;}
if(t==730&&u==630)
{if(array1[30]==1){v++;cout<<"\a";}array1[30]=0;}
if(t==780&&u==630)
{if(array1[31]==1){v++;cout<<"\a";}array1[31]=0;}

//3 line 

if(t==20&&u==560)
{if(array1[32]==1){v++;cout<<"\a";}array1[32]=0;}
if(t==70&&u==560)
{if(array1[33]==1){v++;cout<<"\a";}array1[33]=0;}
if(t==120&&u==560)
{if(array1[34]==1){v++;cout<<"\a";}array1[34]=0;}
if(t==170&&u==560)
{if(array1[35]==1){v++;cout<<"\a";}array1[35]=0;}
if(t==220&&u==560)
{if(array1[36]==1){v++;cout<<"\a";}array1[36]=0;}
if(t==270&&u==560)
{if(array1[37]==1){v++;cout<<"\a";}array1[37]=0;}
if(t==320&&u==560)
{if(array1[38]==1){v++;cout<<"\a";}array1[38]=0;}
if(t==370&&u==560)
{if(array1[39]==1){v++;cout<<"\a";}array1[39]=0;}
if(t==420&&u==560)
{if(array1[40]==1){v++;cout<<"\a";}array1[40]=0;}
if(t==470&&u==560)
{if(array1[41]==1){v++;cout<<"\a";}array1[41]=0;}
if(t==520&&u==560)
{if(array1[42]==1){v++;cout<<"\a";}array1[42]=0;}
if(t==570&&u==560)
{if(array1[43]==1){v++;cout<<"\a";}array1[43]=0;}
if(t==620&&u==560)
{if(array1[44]==1){v++;cout<<"\a";}array1[44]=0;}
if(t==680&&u==560)
{if(array1[45]==1){v++;cout<<"\a";}array1[45]=0;}
if(t==730&&u==560)
{if(array1[46]==1){v++;cout<<"\a";}array1[46]=0;}
if(t==780&&u==560)
{if(array1[47]==1){v++;cout<<"\a";}array1[47]=0;}

//4 th line 
if(t==20&&u==490)
{if(array1[48]==1){v++;cout<<"\a";}array1[48]=0;}
if(t==70&&u==490)
{if(array1[49]==1){v++;cout<<"\a";}array1[49]=0;}
if(t==120&&u==490)
{if(array1[50]==1){v++;cout<<"\a";}array1[50]=0;}
if(t==170&&u==490)
{if(array1[51]==1){v++;cout<<"\a";}array1[51]=0;}
if(t==220&&u==490)
{if(array1[52]==1){v++;cout<<"\a";}array1[52]=0;}
if(t==270&&u==490)
{if(array1[53]==1){v++;cout<<"\a";}array1[53]=0;}
if(t==320&&u==490)
{if(array1[54]==1){v++;cout<<"\a";}array1[54]=0;}
if(t==370&&u==490)
{if(array1[55]==1){v++;cout<<"\a";}array1[55]=0;}
if(t==420&&u==490)
{if(array1[56]==1){v++;cout<<"\a";}array1[56]=0;}
if(t==470&&u==490)
{if(array1[57]==1){v++;cout<<"\a";}array1[57]=0;}
if(t==520&&u==490)
{if(array1[58]==1){v++;cout<<"\a";}array1[58]=0;}
if(t==570&&u==490)
{if(array1[59]==1){v++;cout<<"\a";}array1[59]=0;}
if(t==620&&u==490)
{if(array1[60]==1){v++;cout<<"\a";}array1[60]=0;}
if(t==680&&u==490)
{if(array1[61]==1){v++;cout<<"\a";}array1[61]=0;}
if(t==730&&u==490)
{if(array1[62]==1){v++;cout<<"\a";}array1[62]=0;}
if(t==780&&u==490)
{if(array1[63]==1){v++;}array1[63]=0;}

//below 4th 
if(t==20&&u==410)
{if(array1[64]==1){v++;cout<<"\a";}array1[64]=0;}
if(t==70&&u==410)
{if(array1[65]==1){v++;cout<<"\a";}array1[65]=0;}
if(t==120&&u==410) 
{if(array1[66]==1){v++;cout<<"\a";}array1[66]=0;}
if(t==680&&u==410)
{if(array1[67]==1){v++;cout<<"\a";}array1[67]=0;}
if(t==730&&u==410)
{if(array1[68]==1){v++;cout<<"\a";}array1[68]=0;}
if(t==780&&u==410)
{if(array1[69]==1){v++;cout<<"\a";}array1[69]=0;}

//last line 
if(t==20&&u==30)
{if(array1[70]==1){v++;cout<<"\a";}array1[70]=0;}
if(t==70&&u==30)
{if(array1[71]==1){v++;cout<<"\a";}array1[71]=0;}
if(t==120&&u==30)
{if(array1[72]==1){v++;cout<<"\a";}array1[72]=0;}
if(t==170&&u==30)
{if(array1[73]==1){v++;cout<<"\a";}array1[73]=0;}
if(t==220&&u==30)
{if(array1[74]==1){v++;cout<<"\a";}array1[74]=0;}
if(t==270&&u==30)
{if(array1[75]==1){v++;cout<<"\a";}array1[75]=0;}
if(t==320&&u==30)
{if(array1[76]==1){v++;cout<<"\a";}array1[76]=0;}
if(t==370&&u==30)
{if(array1[77]==1){v++;cout<<"\a";}array1[77]=0;}
if(t==420&&u==30)
{if(array1[78]==1){v++;cout<<"\a";}array1[78]=0;}
if(t==470&&u==30)
{if(array1[79]==1){v++;cout<<"\a";}array1[79]=0;}
if(t==520&&u==30)
{if(array1[80]==1){v++;cout<<"\a";}array1[80]=0;}
if(t==570&&u==30)
{if(array1[81]==1){v++;cout<<"\a";}array1[81]=0;}
if(t==620&&u==30)
{if(array1[82]==1){v++;cout<<"\a";}array1[82]=0;}
if(t==680&&u==30)
{if(array1[83]==1){v++;cout<<"\a";}array1[83]=0;}
if(t==730&&u==30)
{if(array1[84]==1){v++;cout<<"\a";}array1[84]=0;}
if(t==780&&u==30)
{if(array1[85]==1){v++;cout<<"\a";}array1[85]=0;}

//2 last line 
if(t==20&&u==110)
{if(array1[86]==1){v++;cout<<"\a";}array1[86]=0;}
if(t==70&&u==100)
{if(array1[87]==1){v++;cout<<"\a";}array1[87]=0;}
if(t==120&&u==100)
{if(array1[88]==1){v++;cout<<"\a";}array1[88]=0;}
if(t==170&&u==100)
{if(array1[89]==1){v++;cout<<"\a";}array1[89]=0;}
if(t==220&&u==100)
{if(array1[90]==1){v++;cout<<"\a";}array1[90]=0;}
if(t==270&&u==100)
{if(array1[91]==1){v++;cout<<"\a";}array1[91]=0;}
if(t==320&&u==100)
{if(array1[92]==1){v++;cout<<"\a";}array1[92]=0;}
if(t==370&&u==100)
{if(array1[93]==1){v++;cout<<"\a";}array1[93]=0;}
if(t==420&&u==100)
{if(array1[94]==1){v++;cout<<"\a";}array1[94]=0;}
if(t==470&&u==100)
{if(array1[95]==1){v++;cout<<"\a";}array1[95]=0;}
if(t==520&&u==100)
{if(array1[96]==1){v++;cout<<"\a";}array1[96]=0;}
if(t==570&&u==100)
{if(array1[97]==1){v++;cout<<"\a";}array1[97]=0;}
if(t==620&&u==100)
{if(array1[98]==1){v++;cout<<"\a";}array1[98]=0;}
if(t==680&&u==100)
{if(array1[99]==1){v++;cout<<"\a";}array1[99]=0;}
if(t==730&&u==100)
{if(array1[100]==1){v++;cout<<"\a";}array1[100]=0;}
if(t==780&&u==100)
{if(array1[101]==1){v++;cout<<"\a";}array1[101]=0;}

//3rd last line 
if(t==20&&u==170)
{if(array1[102]==1){v++;cout<<"\a";}array1[102]=0;}
if(t==70&&u==170)
{if(array1[103]==1){v++;cout<<"\a";}array1[103]=0;}
if(t==120&&u==170)
{if(array1[104]==1){v++;cout<<"\a";}array1[104]=0;}
if(t==170&&u==170)
{if(array1[105]==1){v++;cout<<"\a";}array1[105]=0;}
if(t==220&&u==170)
{if(array1[106]==1){v++;cout<<"\a";}array1[106]=0;}
if(t==270&&u==170)
{if(array1[107]==1){v++;cout<<"\a";}array1[107]=0;}
if(t==320&&u==170)
{if(array1[108]==1){v++;cout<<"\a";}array1[108]=0;}
if(t==370&&u==170)
{if(array1[109]==1){v++;cout<<"\a";}array1[109]=0;}
if(t==420&&u==170)
{if(array1[110]==1){v++;cout<<"\a";}array1[110]=0;}
if(t==470&&u==170)
{if(array1[111]==1){v++;cout<<"\a";}array1[111]=0;}
if(t==520&&u==170)
{if(array1[112]==1){v++;cout<<"\a";}array1[112]=0;}
if(t==570&&u==170)
{if(array1[113]==1){v++;cout<<"\a";}array1[113]=0;}
if(t==620&&u==170)
{if(array1[114]==1){v++;cout<<"\a";}array1[114]=0;}
if(t==680&&u==170)
{if(array1[115]==1){v++;cout<<"\a";}array1[115]=0;}
if(t==730&&u==170)
{if(array1[116]==1){v++;cout<<"\a";}array1[116]=0;}
if(t==780&&u==170)
{if(array1[117]==1){v++;cout<<"\a";}array1[117]=0;}

//4th last line 


if(t==20&&u==240)
{if(array1[118]==1){v++;cout<<"\a";}array1[118]=0;}
if(t==70&&u==240)
{if(array1[119]==1){v++;cout<<"\a";}array1[119]=0;}
if(t==120&&u==240)
{if(array1[120]==1){v++;cout<<"\a";}array1[120]=0;}
if(t==170&&u==240)
{if(array1[121]==1){v++;cout<<"\a";}array1[121]=0;}
if(t==220&&u==240)
{if(array1[122]==1){v++;cout<<"\a";}array1[122]=0;}
if(t==270&&u==240)
{if(array1[123]==1){v++;cout<<"\a";}array1[123]=0;}
if(t==320&&u==240)
{if(array1[124]==1){v++;cout<<"\a";}array1[124]=0;}
if(t==370&&u==240)
{if(array1[125]==1){v++;cout<<"\a";}array1[125]=0;}
if(t==420&&u==240)
{if(array1[126]==1){v++;cout<<"\a";}array1[126]=0;}
if(t==470&&u==240)
{if(array1[127]==1){v++;cout<<"\a";}array1[127]=0;}
if(t==520&&u==240)
{if(array1[128]==1){v++;cout<<"\a";}array1[128]=0;}
if(t==570&&u==240)
{if(array1[129]==1){v++;cout<<"\a";}array1[129]=0;}
if(t==620&&u==240)
{if(array1[130]==1){v++;cout<<"\a";}array1[130]=0;}
if(t==680&&u==240)
{if(array1[131]==1){v++;cout<<"\a";}array1[131]=0;}
if(t==730&&u==240)
{if(array1[132]==1){v++;cout<<"\a";}array1[132]=0;}
if(t==780&&u==240)
{if(array1[133]==1){v++;cout<<"\a";}array1[133]=0;}


//above 4th line 

if(t==20&&u==300)
{if(array1[134]==1){v++;cout<<"\a";}array1[134]=0;}
if(t==70&&u==300)
{if(array1[135]==1){v++;cout<<"\a";}array1[135]=0;}
if(t==120&&u==300)
{if(array1[136]==1){v++;cout<<"\a";}array1[136]=0; }
if(t==680&&u==300)
{if(array1[137]==1){v++;cout<<"\a";}array1[137]=0;}
if(t==730&&u==300)
{if(array1[138]==1){v++;cout<<"\a";}array1[138]=0;}
if(t==780&&u==300)
{if(array1[139]==1){v++;cout<<"\a";}array1[139]=0;}


glutPostRedisplay();
	glutTimerFunc(30.0, Clock, 0);

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */       
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;



	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
                        cout<<x<<"    "<<y;
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{if ((x>=344&&x<=474)&&(y>=270&&y<=285))
                       {  
                        glutDisplayFunc(GameDisplay); 
 x_1=380; 
 y_1=30;
 t= 350; 
 u= 30;
 x_2=450 ;
 y_2=700  ;
 array1[140];
 s=1;
 v=0,w=3;
 pau=0;

 string scores,lives; 

                                }
                        if ((x>=341&&x<=403)&&(y>=439&&y<=452))                                 //RANGE ADJUST TO JUST CLICK AND OPEN
                        {glutDisplayFunc(Gameinstruction);}   
                              
                        if ((x>=14&&x<=70)&&(y>=643&&y<=670))
                        {glutDisplayFunc(GameMenu);   }
 
                              
                        if ((x>=340&&x<=400)&&(y>=519&&y<=543))
                        {exit(1);}  


                          if ((x>=330&&x<=504)&&(y>=338&&y<=384))
                        {glutDisplayFunc(Control_Max);   }
 
                                       }
                         
	glutPostRedisplay();

     }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
        glutDisplayFunc(GameMenu);
	//glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(100.0, Timer, 0);
	glutTimerFunc(100.0, Clock, 0);
        glutTimerFunc(100.0, timmer, 0);
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
