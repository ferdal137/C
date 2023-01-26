/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>


/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

/**************
 *Declaraciones
 **************/

#include "logo.h"
#include "koch.h"
#include "rama.h"
#include "misFuncs.h"
#include "Dragon.h"
#include "Hilbert.h"
#include "Sierpinsky.h"
#include "Abel.h"
#include "Gosper.h"
#include "Snow.h"
#include "Corner.h"
#include "Weave.h"
#include "Nest.h"
#include "Maze.h"
#include "Hook.h"
#include "Nest.h"

#define escX 0.125
#define escY 0.125
#define MX 0.0
#define MY 0.0

void segmento(double, double, double, double);
//DibujaSegmentos dibujaSegmento=segmento;



/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "graficos";
    RegisterClass (&wc);

    char fractales=0, funciones=0;
    f_RenR miFuncion;
    misFractales miFractal;
    int nRecursion = 5;
    LOGO miTortuga;
    char *miParametro="Rama"; 

    if (iCmdShow>1) miParametro = lpCmdLine;
    if (strlen(lpCmdLine)==0) miParametro= "Triangulo"; 
     asignaModoDibujarSegmento(segmento, &miTortuga);

    if((strncmp(miParametro, "Koch", 4)==0)) { 
    	        iniciaKoch(nRecursion, 10.0, -5.0, 0.0, &miTortuga);
        miFractal = dibujaKoch;
    }else if (strncmp(miParametro, "Rama", 4)==0){
        iniciaRama(nRecursion, 13.0, 110, 0.0, -5.0, &miTortuga);
        miFractal = dibujaRama;
      } else if (strncmp(miParametro, "KochII", 6)==0){ 
        iniciaKoch(nRecursion, 30.0, -5.0, -2.5, &miTortuga);
        miFractal = dibujaKochII;
      } else if (strncmp(miParametro, "KochI", 5)==0){ 
        iniciaKoch(nRecursion, 10.0, -5.0, 2.5, &miTortuga);
        miFractal = dibujaKochI;
      } else if(strncmp(miParametro, "Dragon", 6)==0){ 
		iniciaDragon(17, 0.02, -4.0, 1.0, &miTortuga);
		miFractal = dibujaDragon;
      }else if(strncmp(miParametro, "Hilbert", 5)==0){ 
		iniciaHilbert(6, 0.215,-6.5,-6.0, &miTortuga);
		miFractal = dibujaHilbert;
      }else if(strncmp(miParametro, "Abelson", 5)==0){ 
		iniciaAbelson(14, 0.051,1.0,-2.5, &miTortuga);
		miFractal = dibujaAbelson;
      }else if(strncmp(miParametro, "Maze", 5)==0){ 
		iniciaMazeM(3,15.0,-7.5,-0.1, &miTortuga);
		miFractal = dibujaMaze;
      }else if(strncmp(miParametro, "Corner", 5)==0){ 
		iniciaCorner(220, 5.0,1.2,-2.5,0.0, &miTortuga);
		miFractal = dibujaCorner;
      }else if(strncmp(miParametro, "Weave", 5)==0){ 
		iniciaWeave(3, 10.0,-6.0,0.0, &miTortuga);
		miFractal = dibujaWeave;
      }else if(strncmp(miParametro, "Gosper", 5)==0){ 
		iniciaGosper(4, 10.0,-5.5,2.0, &miTortuga);
		miFractal = dibujaGosper;
      }else if(strncmp(miParametro, "HSnow", 5)==0){
		iniciaHook(4, 12.0, -6.0, -3.0, &miTortuga);
		miFractal = dibujaHook;
	  }else if(strncmp(miParametro, "SquareSnow", 5)==0){ 
		iniciaSnow(5, 7.0,-3.5,4.5, &miTortuga);
		miFractal = dibujaSnow;
	  }else if(strncmp(miParametro, "Sierpinsky", 5)==0){
		iniciaSierpinsky(6, 0.1, -6.5,7.0, &miTortuga);
		miFractal = dibujaSierpinsky;
      }else if(strncmp(miParametro, "Triangulo", 5)==0){
		iniciaNest(8, 11, -5.5, 4.0, &miTortuga);
		miFractal = dibujaNest;
      }
      



    /* create main window */
    hWnd = CreateWindow (
      "graficos", 
      "Fractales", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 3*256, 3*256,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */

            glClearColor (1.0f, 1.0f, 1.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);

            glPushMatrix ();
            glRotatef (theta, 0.1f, 0.2f, 0.0f);
            glColor3d(0.1, 0.2, 0.1);

            
            miFractal();
            glPopMatrix ();

            SwapBuffers (hDC);

            //theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}

void segmento(double x1, double y1, double x2, double y2)
{
  glBegin (GL_LINES);
    glVertex2d (MX+escX*x1, MY+escY*y1);
    glVertex2d (MX+escX*x2, MY+escY*y2);
    
  glEnd ();
  
}


