//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
__fastcall TGLForm2D::TGLForm2D(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormCreate(TObject *Sender)
{
    hdc = GetDC(Handle);
    SetPixelFormatDescriptor();
    hrc = wglCreateContext(hdc);
    if(hrc == NULL)
    	ShowMessage(":-)~ hrc == NULL");
    if(wglMakeCurrent(hdc, hrc) == false)
    	ShowMessage("Could not MakeCurrent");
    //Cor de fondo de la ventana
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //inicializaci�n del volumen de vista
    xRight=200.0; xLeft=-xRight;
    yTop=xRight; yBot=-yTop;
    //Radio del volumen de vista == 1

    //inicializaci�n del puerto de vista
    //ClientWidth=400;
    //ClientHeight=400;
    RatioViewPort=1.0;

    // inicializaci�n de las variables del programa

    mDesplazar = false;
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::SetPixelFormatDescriptor()
{
    PIXELFORMATDESCRIPTOR pfd = {
    	sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0
    };
    int PixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, PixelFormat, &pfd);
}
//---------------------------------------------------------------------
void __fastcall TGLForm2D::FormResize(TObject *Sender)
{

 //se actualiza puerto de vista y su radio
  if ((ClientWidth<=1)||(ClientHeight<=1)){
     ClientWidth=400;
     ClientHeight=400;
     RatioViewPort=1.0;
     }
  else RatioViewPort= (float)ClientWidth/(float)ClientHeight;

  glViewport(0,0,ClientWidth,ClientHeight);

  // se actualiza el volumen de vista
  // para que su radio coincida con ratioViewPort
  GLfloat RatioVolVista=(xRight-xLeft)/(yTop-yBot);

  if (RatioViewPort<=RatioVolVista){//hemos hecho la ventana mas alta que ancha
     //Aumentamos yTop-yBot
     GLdouble altoNew= (xRight-xLeft)/RatioViewPort;
     GLdouble yCentro= (yTop+yBot)/2.0;
     yTop= yCentro + altoNew/2.0;
     yBot= yCentro - altoNew/2.0;

     }
  else{                //hemos hecho la ventana mas ancha que alta
     //Aumentamos xRight-xLeft
     GLdouble anchoNew= RatioViewPort*(yTop-yBot);
     GLdouble xCentro= (xRight+xLeft)/2.0;
     xRight= xCentro + anchoNew/2.0;
     xLeft= xCentro - anchoNew/2.0;
  }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft,xRight, yBot,yTop);


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  GLScene();

}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::GLScene()
{
glClear(GL_COLOR_BUFFER_BIT);

// comandos para dibujar la escena

glFlush();
SwapBuffers(hdc);
}

//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormPaint(TObject *Sender)
{
  GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TGLForm2D::FormDestroy(TObject *Sender)
{
    ReleaseDC(Handle,hdc);
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);
    // eliminar objetos creados
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Lineas1Click(TObject *Sender)
{
//Dibujar poli_lineas    
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Poligono1Click(TObject *Sender)
{
//Dibujar Poligonos    
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Espiral1Click(TObject *Sender)
{
//Dibujar espiral    
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Seleccionar1Click(TObject *Sender)
{
//Seleccionar poli_linea
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Borrar1Click(TObject *Sender)
{
// Borrar poli_linea    
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Zoom1Click(TObject *Sender)
{
//Zoom progresivo    
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Traslacion1Click(TObject *Sender)
{
//Trasladar el AVE
    mDesplazar = true; 
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::K1Click(TObject *Sender)
{
//fractal Koch1    
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Koch21Click(TObject *Sender)
{
// Fractal Koch2    
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Dragon1Click(TObject *Sender)
{
//Fractal dragon    
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::Cortar1Click(TObject *Sender)
{
//Selecionar un area y borrar lo que haya dentro    
}
//---------------------------------------------------------------------------

void __fastcall TGLForm2D::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (mDesplazar){
 	    switch (Key){
            case 37:{
            
                GLfloat xRight_aux = xRight - (xRight-xLeft)*0.05;
                GLfloat xLeft_aux = xLeft - (xRight-xLeft)*0.05;
                xRight = xRight_aux;
                xLeft = xLeft_aux;
                break;
            }
        //Abajo
   		    case 38:{
                GLfloat yBot_aux = yBot - (yBot-yTop)*0.05;
                GLfloat yTop_aux = yTop - (yBot-yTop)*0.05;
                yBot = yBot_aux;
                yTop = yTop_aux;
                break;
            }
        //Derecha
   		    case 39:{
               GLfloat xRight_aux = xRight + (xRight-xLeft)*0.05;
               GLfloat xLeft_aux = xLeft + (xRight-xLeft)*0.05;
               xRight = xRight_aux;
               xLeft = xLeft_aux;
               break;
            }
        //Arriba
   		    case 40:{
                GLfloat yBot_aux = yBot + (yBot-yTop)*0.05;
                GLfloat yTop_aux = yTop + (yBot-yTop)*0.05;
                yBot = yBot_aux;
                yTop = yTop_aux;
                break;
            }
        }

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(xLeft,xRight,yBot,yTop);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        GLScene();
    }
}
//--------------------------------------------------------------------------

void __fastcall TGLForm2D::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// Detectar click
}
//---------------------------------------------------------------------------

void TGLForm2D::procesarCoor(int X, int Y)
{
       //Transforma a coordenadas en la escena
       GLfloat xAux = X*((xRight-xLeft)/ClientWidth) + xLeft;
       GLfloat yAux = -Y*((yTop - yBot)/ClientHeight) + yTop;
       //tPV* punto = new tPV(xAux,yAux);
       //return punto; cambiar el tipo devuelto por tPV*
}