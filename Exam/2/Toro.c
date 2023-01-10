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
	double x, y, z, r=0.3, R=0.8, alfa, beta;
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
      0,0,512,512,
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
            glRotatef(theta, 0.0f, 0.0f, 0.0f);
            
			for(beta=0; beta<(4 * M_PI); beta+=0.1){
				glBegin(GL_LINE_LOOP);
            	glColor3f (0,0,0);
            	for(alfa=0; alfa<(4 * M_PI); alfa+=0.2){
            		x = (R + (r * (cos(alfa)) )) * (cos(beta));
            		y = (R + (r * (cos(alfa)) )) * (sin(beta)); 
            		z = r * (sin(alfa));
            		glVertex3d(x,y,z);
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
            		glVertex3d(x,y,z);
				}
				glEnd();
			}
            glPopMatrix ();
            SwapBuffers (hDC);
            theta += 0.0f;
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