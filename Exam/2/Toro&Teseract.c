#include <windows.h>
#include <gl/gl.h>
#include <math.h>

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
	double x, y, z, r=0.1, R=0.3, alfa, beta;
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;
    

    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "GLSample";
    RegisterClass (&wc);

    hWnd = CreateWindow (
      "GLSample", "OpenGL Sample", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 700, 700,
      NULL, NULL, hInstance, NULL);

    EnableOpenGL (hWnd, &hDC, &hRC);

    while (!bQuit)
    {

        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {

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
			
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glPushMatrix();
            glRotatef(45.0f, 0.8f, 0.7f, 0.9f);
			
			
			
            glBegin(GL_LINE_LOOP);
            glColor4f(0.0f,0.0f,0.0f,0.0f);
		    //cara frontal
		    glVertex3f(-0.25+0.35, -0.25+0.35, 0.25+0.35);
		    glVertex3f(0.25+0.35, -0.25+0.35, 0.25+0.35);
		    glVertex3f(0.25+0.35, -0.25+0.35, -0.25+0.35);
		    glVertex3f(-0.25+0.35, -0.25+0.35, -0.25+0.35);
		    glVertex3f(-0.25+0.35, -0.25+0.35, 0.25+0.35);
		    // cara superior
		    glVertex3f(-0.25+0.35, 0.25+0.35, 0.25+0.35);
		    glVertex3f(0.25+0.35, 0.25+0.35, 0.25+0.35);
		    glVertex3f(0.25+0.35, -0.25+0.35, 0.25+0.35);
		    glVertex3f(-0.25+0.35, -0.25+0.35, 0.25+0.35);
		    //cara izq
		    glVertex3f(-0.25+0.35, -0.25+0.35, -0.25+0.35);
		    glVertex3f(-0.25+0.35, 0.25+0.35, -0.25+0.35);
		    glVertex3f(-0.25+0.35, 0.25+0.35, 0.25+0.35);
		    //cara trasera
		    glVertex3f(0.25+0.35, 0.25+0.35, 0.25+0.35);
		    glVertex3f(0.25+0.35, 0.25+0.35, -0.25+0.35);
		    glVertex3f(-0.25+0.35, 0.25+0.35, -0.25+0.35);
		    //cara inf
		    glVertex3f(-0.25+0.35, -0.25+0.35, -0.25+0.35);
		    glVertex3f(0.25+0.35, -0.25+0.35, -0.25+0.35);
		    glVertex3f(0.25+0.35, 0.25+0.35, -0.25+0.35);
		    //cara derecha
		    glVertex3f(0.25+0.35, 0.25+0.35, 0.25+0.35);
		    glVertex3f(0.25+0.35, -0.25+0.35, 0.25+0.35);
		    glVertex3f(-0.25+0.35, -0.25+0.35, 0.25+0.35);
			glEnd();

            //CUBO2
           
            glBegin(GL_LINE_LOOP);
		    //cara front
		    glVertex3f(-0.125+0.35, -0.125+0.35, 0.125+0.35);
		    glVertex3f(0.125+0.35, -0.125+0.35, 0.125+0.35);
		    glVertex3f(0.125+0.35, -0.125+0.35, -0.125+0.35);
		    glVertex3f(-0.125+0.35, -0.125+0.35, -0.125+0.35);
		    glVertex3f(-0.125+0.35, -0.125+0.35, 0.125+0.35);
		    //cara sup
		    glVertex3f(-0.125+0.35, 0.125+0.35, 0.125+0.35);
		    glVertex3f(0.125+0.35, 0.125+0.35, 0.125+0.35);
		    glVertex3f(0.125+0.35, -0.125+0.35, 0.125+0.35);
		    glVertex3f(-0.125+0.35, -0.125+0.35, 0.125+0.35);
		    //cara izq
		    glVertex3f(-0.125+0.35, -0.125+0.35, -0.125+0.35);
		    glVertex3f(-0.125+0.35, 0.125+0.35, -0.125+0.35);
		    glVertex3f(-0.125+0.35, 0.125+0.35, 0.125+0.35);
		    //cara trasera
		    glVertex3f(0.125+0.35, 0.125+0.35, 0.125+0.35);
		    glVertex3f(0.125+0.35, 0.125+0.35, -0.125+0.35);
		    glVertex3f(-0.125+0.35, 0.125+0.35, -0.125+0.35);
		    //cara inf
		    glVertex3f(-0.125+0.35, -0.125+0.35, -0.125+0.35);
		    glVertex3f(0.125+0.35, -0.125+0.35, -0.125+0.35);
		    glVertex3f(0.125+0.35, 0.125+0.35, -0.125+0.35);
		    //cara derecha
		    glVertex3f(0.125+0.35, 0.125+0.35, 0.125+0.35);
		    glVertex3f(0.125+0.35, -0.125+0.35, 0.125+0.35);
		    glVertex3f(-0.125+0.35, -0.125+0.35, 0.125+0.35);
			glEnd();
            
            //LINEAS (1)
            
            glBegin(GL_LINE_LOOP);
            glVertex3f(-0.25+0.35, -0.25+0.35, 0.25+0.35);
		    glVertex3f(-0.125+0.35, -0.125+0.35, 0.125+0.35);
		    glVertex3f(0.125+0.35, -0.125+0.35, 0.125+0.35);
		    glVertex3f(0.25+0.35, -0.25+0.35, 0.25+0.35);
		    glVertex3f(0.25+0.35, -0.25+0.35, -0.25+0.35);
		    glVertex3f(0.125+0.35, -0.125+0.35, -0.125+0.35);
		    glVertex3f(-0.125+0.35, -0.125+0.35, -0.125+0.35);
		    glVertex3f(-0.25+0.35, -0.25+0.35, -0.25+0.35);
            glEnd();
            //LINEAS (2)
          
            glBegin(GL_LINE_LOOP);
            glVertex3f(-0.25+0.35, 0.25+0.35, 0.25+0.35);
		    glVertex3f(-0.125+0.35, 0.125+0.35, 0.125+0.35);
		    glVertex3f(0.125+0.35, 0.125+0.35, 0.125+0.35);
		    glVertex3f(0.25+0.35, 0.25+0.35, 0.25+0.35);
		    glVertex3f(0.25+0.35, 0.25+0.35, -0.25+0.35);
		    glVertex3f(0.125+0.35, 0.125+0.35, -0.125+0.35);
		    glVertex3f(-0.125+0.35, 0.125+0.35, -0.125+0.35);
		    glVertex3f(-0.25+0.35, 0.25+0.35, -0.25+0.35);
		    glEnd ();
		    
		    
            
			for(beta=0; beta<(4 * M_PI); beta+=0.1){
				glBegin(GL_LINE_LOOP);
            	glColor3f (0,0,0);
            	for(alfa=0; alfa<(4 * M_PI); alfa+=0.2){
            		x = (R + (r * (cos(alfa)) )) * (cos(beta));
            		y = (R + (r * (cos(alfa)) )) * (sin(beta)); 
            		z = r * (sin(alfa));
            		glVertex3d(x-0.5,y-0.5,z-0.5);
				}
				glEnd();
			}
			
			
			for(alfa=0; alfa<(4 * M_PI); alfa+=0.3){
				glBegin(GL_LINE_LOOP);
            	glColor3f(0,0,0);
            	for(beta=0; beta<(4 * M_PI); beta+=0.2){
            		x = (R + (r * (cos(alfa)) )) * (cos(beta));
            		y = (R + (r * (cos(alfa)) )) * (sin(beta)); 
            		z = r * (sin(alfa));
            		glVertex3d(x-0.5,y-0.5,z-0.5);
            		
				}		
				glEnd();
		} 
            
            glPopMatrix ();
            SwapBuffers (hDC);

          	theta += 1.0f;
           	Sleep (1);
        }
    }

    DisableOpenGL (hWnd, hDC, hRC);

    DestroyWindow (hWnd);

    return msg.wParam;
}


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


void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;
    
    *hDC = GetDC (hWnd);

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

    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}



