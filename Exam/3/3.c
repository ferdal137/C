#include <windows.h>
#include <gl/gl.h>

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

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
      0, 0, 720, 720,
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

            glClearColor (1.0f, 1.0f, 1.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);
        	glColor3f(0.0f, 0.0f, 0.0f);
            glBegin (GL_LINES);
			
			glVertex2f(-0.1,-0.1);
			glVertex2f(-0.1,0.1);
			
			glVertex2f(0.1,-0.1);
			glVertex2f(0.1,0.1);
			
			glVertex2f(-0.1,0.1);
			glVertex2f(0.1,0.1);
			
			glVertex2f(-0.1,-0.1);
			glVertex2f(0.1,-0.1);
			
			
			glVertex2f(-0.1,0.1);
			glVertex2f(-0.05,0.15);
			
			glVertex2f(-0.05,0.15);
			glVertex2f(0.15,0.15);
			
		    glVertex2f(0.15,0.15);
			glVertex2f(0.1,0.1);
			
			
			glVertex2f(-0.1,-0.1);
			glVertex2f(-0.05,-0.05);
			
			glVertex2f(0.15,-0.05);
			glVertex2f(-0.05,-0.05);
			
			glVertex2f(0.15,-0.05);
			glVertex2f(0.1,-0.1);
			
			
			glVertex2f(-0.05,-0.05);
			glVertex2f(-0.05,0.15);
			
			glVertex2f(0.15,-0.05);
			glVertex2f(0.15,0.15);
			
			// Cubo grande
			
			glVertex2f(-0.5,-0.5);
			glVertex2f(-0.5,0.3);
			
			glVertex2f(-0.5 ,0.3);
			glVertex2f(0.3,0.3);
			
			glVertex2f(0.3,0.3);
			glVertex2f(0.3,-0.5);
			
			glVertex2f(0.3,-0.5);
			glVertex2f(-0.5,-0.5);
			
			
			glVertex2f(-0.5,0.3);
			glVertex2f(-0.2,0.5);
			
			glVertex2f(-0.2,0.5);
			glVertex2f(0.6,0.5);
			
		    glVertex2f(0.6,0.5);
			glVertex2f(0.3,0.3);
			
			
			glVertex2f(-0.5,-0.5);
			glVertex2f(-0.2,-0.3);
			
			glVertex2f(-0.2,-0.3);
			glVertex2f(0.6,-0.3);
			
			glVertex2f(0.6,-0.3);
			glVertex2f(0.3,-0.5);
			
			
			glVertex2f(-0.2,-0.3);
			glVertex2f(-0.2,0.5);
			
			glVertex2f(0.6,-0.3);
			glVertex2f(0.6,0.5);
			
			
			//Lineas que unen los dos cubos
			
			glVertex2f(-0.5,0.3);
			glVertex2f(-0.1,0.1);
			
			glVertex2f(-0.05,0.15);
			glVertex2f(-0.2,0.5);
			
			glVertex2f(-0.1,-0.1);
			glVertex2f(-0.5,-0.5);
			
			glVertex2f(-0.05,-0.05);
			glVertex2f(-0.2,-0.3);
			
			glVertex2f(0.1,-0.1);
			glVertex2f(0.3,-0.5);
			
			glVertex2f(0.15,-0.05);
			glVertex2f(0.6,-0.3);
			
			glVertex2f(0.1,0.1);
			glVertex2f(0.3,0.3);
			
			glVertex2f(0.15,0.15);
			glVertex2f(0.6,0.5);
			
			
            glEnd ();
            //glPopMatrix ();
            SwapBuffers (hDC);

          //  theta += 1.0f;
           // Sleep (1);
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