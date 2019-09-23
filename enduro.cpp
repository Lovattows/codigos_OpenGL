#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

float xr = 0, yr = 0;
int seg = 0;
int vel = 0;
float timer = 1;
float p1 = -0.25;
float p2 = 0.25;

void Inicializa(void)
{
	glClearColor(0,0.5,1,0); 
}
void Desenha(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	//FUNDO VERDE
    glColor3f(0.000, 0.392, 0.000); 
	glBegin(GL_QUADS); 
		glVertex2f(-1.0, -1.0);
    	glVertex2f( 1.0, -1.0);
	    glVertex2f( 1.0,  0.45);
    	glVertex2f(-1.0,  0.45);
    glEnd();
	
	//PISTA
   	glColor3f(0.663, 0.663, 0.663); 
   	glBegin(GL_QUADS);
    	glVertex2f(-0.75,-1.0);
    	glVertex2f(p1, 0.45);
    	glVertex2f(p2, 0.45);
    	glVertex2f(0.75,-1.0);
	glEnd();
	
	//LINHA ESQUERDA PISTA
	glLineWidth(3); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(-0.75,-1.0);
		glVertex2f(p1, 0.45);
	glEnd();
	
	//LINHA ESQUERDA PISTA
	glLineWidth(3); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0.75,-1.0);
		glVertex2f(p2, 0.45);
	glEnd();
	
	//LISTRA MEIO 1
	glLineWidth(4); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0.0,0.45*timer);
		glVertex2f(0.0,0.35*timer);
	glEnd();
	
	//LISTRA MEIO 2
	glLineWidth(4); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0.0,0.25*timer);
		glVertex2f(0.0,0.15*timer);
	glEnd();
	
	//LISTRA MEIO 3
	glLineWidth(4); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0.0,0.05*timer);
		glVertex2f(0.0,-0.05*timer);
	glEnd();
	
	//LISTRA MEIO 4
	glLineWidth(4); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0.0,-0.15*timer);
		glVertex2f(0.0,-0.25*timer);
	glEnd();
	
	//LISTRA MEIO 5
	glLineWidth(4); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0.0,-0.35*timer);
		glVertex2f(0.0,-0.45*timer);
	glEnd();
	
	//LISTRA MEIO 6
	glLineWidth(4); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0.0,-0.55*timer);
		glVertex2f(0.0,-0.65*timer);
	glEnd();
	
	//LISTRA MEIO 7
	glLineWidth(4); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0.0,-0.75*timer);
		glVertex2f(0.0,-0.85*timer);
	glEnd();
    
	//LISTRA MEIO 8
	glLineWidth(4); 
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0.0,-0.95*timer);
		glVertex2f(0.0,-1.0*timer);
	glEnd();
	
    //RODA 1
    glLineWidth(2.5); 
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2f(-0.07+xr,-0.91);
		glVertex2f(0.07+xr, -0.91);
	glEnd();
		
    //RODA 2
	glLineWidth(2.5); 
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2f(-0.07+xr,-0.93);
		glVertex2f(0.07+xr, -0.93);
	glEnd();
	
	//RODA 3
	glLineWidth(2.5); 
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2f(-0.07+xr,-0.95);
		glVertex2f(0.07+xr, -0.95);
	glEnd();
	
	//RODA 4
	glLineWidth(2.5); 
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex2f(-0.07+xr,-0.97);
		glVertex2f(0.07+xr, -0.97);
	glEnd();
	
	//RODA 5     
	glLineWidth(2.5); 
		glColor3f(1.0, 0.0, 0.0);;
		glBegin(GL_LINES);
		glVertex2f(-0.07+xr,-0.99);
		glVertex2f(0.07+xr, -0.99);
	glEnd();
	
	//CARRO
	glColor3f(0.545, 0.271, 0.075); 
	glBegin(GL_QUADS); 
		glVertex2f(-0.05+xr, -1.0);
    	glVertex2f( 0.05f+xr, -1.0);
	    glVertex2f( 0.05f+xr, -0.9);
    	glVertex2f(-0.05f+xr, -0.9);
    glEnd();
    
    glutPostRedisplay();
    glutSwapBuffers();
}

void Timer(int value)
{
   	if(seg==1){
   	    timer = 0; 
   	    seg=0;         
   	}
   	else{
   	    timer = 1;
   	    seg=1;
   	}
   	int aleatorio = rand() % 9;
	//CENTRO DA PISTA
	if(aleatorio == 0){
		p1 = -0.25;
		p2 = 0.25;
	}
	//PISTA VAI PARA <<<<<
	else if(aleatorio == 1){
	    p1 = -0.45;
		p2 = 0.05;
	}else if(aleatorio == 2){
	   	p1 = -0.40;
		p2 = 0.10;
	}else if(aleatorio == 3){
	   	p1 = -0.35;
		p2 = 0.15;
	}else if(aleatorio == 4){
	   	p1 = -0.30;
		p2 = 0.20;
	}
	//PISTA VAI PARA >>>>>
	else if(aleatorio == 5){
	    p1 = -0.25;
		p2 = 0.25;
	}else if(aleatorio == 6){
	   	p1 = -0.20;
		p2 = 0.30;
	}else if(aleatorio == 7){
	   	p1 = -0.15;
		p2 = 0.35;
	}else if(aleatorio == 8){
	   	p1 = -0.10;
		p2 = 0.40;
	}
   glutPostRedisplay(); 
   glutTimerFunc(500+vel, Timer, 0);
}

void Buttons(int key, int x, int y)
{
	switch(key){
		case GLUT_KEY_LEFT:
			xr = xr - 0.1;
			glutPostRedisplay();
			break; 
		case GLUT_KEY_RIGHT:
			xr = xr + 0.1;
			glutPostRedisplay();
			break;
		case GLUT_KEY_UP:
			vel = -250;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			vel = +250;
			glutPostRedisplay();
			break;
	}
}

int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //buffer simples
	glutInitWindowSize(800,600); //define o tamanho da janela
	glutInitWindowPosition(250,250); // posiciona a janela, cuja origem é no canto superior esquerdo
	glutCreateWindow("Enduro - Gabriel Lovatto"); //cria uma janela com o título especificado
	glutTimerFunc(500+vel, Timer, 0); //define a fun??o de tempo, que come?a a executar 1000 milisegundos depois da inicializa??o
	glutDisplayFunc(Desenha); //registra a função callback de redesenhenho
	glutSpecialFunc(Buttons);
	Inicializa(); //inicialização própria desse programa
	glutMainLoop(); // entra no laço de processamento de eventos
	return 0;
}
