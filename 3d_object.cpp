#include <windows.h>
#include <GL/glut.h>

int i = 0, j = 0, p = 0;
int vel = 50;
float movimenta_esq_dir = 10;
float movimenta_cima_baixo = 10;
float rcolor1 = 0.502f, gcolor1 = 0.0, bcolor1 = 0.0f;
float rcolor2 = 1.0f, gcolor2 = 1.0f, bcolor2 = 1.0f;
float rcolor3 = 1.0f, gcolor3 = 1.0f, bcolor3 = 1.0f;
float rcolor4 = 1.0f, gcolor4 = 1.0f, bcolor4 = 1.0f;
float rcolor5 = 1.0f, gcolor5 = 1.0f, bcolor5 = 1.0f;
float rcolor6 = 1.0f, gcolor6 = 1.0f, bcolor6 = 1.0f;
float rcolor7 = 0.502f, gcolor7 = 0.0f, bcolor7 = 0.0f;

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
}
 
void reshape(int w, int h) {
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void display() { 
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -30.0f);
 
//COR AMBIENTE
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
 
//LUZ POSICIONADA
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
	GLfloat lightPos0[] = {0.0f, -8.0f, 8.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

//LUZ DIRETA
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glRotatef(movimenta_cima_baixo, 1.0f, 0.0f, 0.0f);
	glRotatef(movimenta_esq_dir, 0.0f, 1.0f, 0.0f);

//DESENHO DO BANCO 
	glColor3f(0.502f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
 
//BANCO LADO 1
    glNormal3f(0.0f, 0.0f, 1.0f);        
  	glVertex3f(-3.0f, -0.3f, 1.8f);
	glVertex3f(3.0f, -0.3f, 1.8f);
	glVertex3f(3.0f, 0.3f, 1.8f);
	glVertex3f(-3.0f, 0.3f, 1.8f);
 
//BANCO LADO 2
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(3.0f, -0.3f, -2.2f);
	glVertex3f(3.0f, 0.3f, -2.2f);
	glVertex3f(3.0f, 0.3f, 1.8f);
	glVertex3f(3.0f, -0.3f,1.8f);
 
//BANCO LADO 3
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f, -0.3f, -2.2f);
	glVertex3f(-3.0f, 0.3f, -2.2f);
	glVertex3f(3.0f, 0.3f, -2.2f);
	glVertex3f(3.0f, -0.3f, -2.2f);
 
//BANCO LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f, -0.3f, -2.2f);
	glVertex3f(-3.0f, -0.3f, 1.8f);
	glVertex3f(-3.0f, 0.3f, 1.8);
	glVertex3f(-3.0f, 0.3f, -2.2f);

//BANCO LADO 5
 	glNormal3f(0.0f, 1.0f, 0.0f);
 	glVertex3f(3.0f, 0.3f, 1.8f);
 	glVertex3f(-3.0f, 0.3f, 1.8f);
 	glVertex3f(-3.0f, 0.3f, -2.2f);
 	glVertex3f(3.0f, 0.3f, -2.2f);
 
 //BANCO LADO 6
	glNormal3f(0.0f,-1.0f, 0.0f);
	glVertex3f(3.0f, -0.3f, 1.8f);
	glVertex3f(-3.0f, -0.3f, 1.8f);
	glVertex3f(-3.0f, -0.3f, -2.2f);
	glVertex3f(3.0f, -0.3f, -2.2f);

//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//

//PÉ NUMERO 1
	glColor3f(rcolor1,gcolor1,bcolor1);
	
//PE 1 LADO 1
	
	glVertex3f(3.0f,-0.2f,1.8f);
	glVertex3f(2.6f, -0.2f, 1.8f);
	glVertex3f(2.6f, -4.0f, 1.8f);
	glVertex3f(3.0f, -4.0f, 1.8f);
 
//PE 1 LADO 2
	
	glVertex3f(3.0f,-0.2f, 1.4f);
	glVertex3f(2.6f, -0.2f, 1.4f);
	glVertex3f(2.6f, -4.0f, 1.4f);
	glVertex3f(3.0f, -4.0f, 1.4f);
 
//PE 1 LADO 3
	
	glVertex3f(3.0f,-0.2f,1.8f);
	glVertex3f(3.0f, -0.2f, 1.4f);
	glVertex3f(3.0f, -4.0f, 1.4f);
	glVertex3f(3.0f, -4.0f, 1.8f);
	
//PE 1 LADO 4
	
	glVertex3f(2.6f,-0.2f,1.8f);
	glVertex3f(2.6f, -0.2f, 1.4f);
	glVertex3f(2.6f, -4.0f, 1.4f);
	glVertex3f(2.6f, -4.0f, 1.8f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 
 
//PÉ NUMERO 2
	glColor3f(rcolor2,gcolor2,bcolor2);
	
//PE 2 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0f,-0.2f,1.2f);
	glVertex3f(2.6f, -0.2f, 1.2f);
	glVertex3f(2.6f, -4.0f, 1.2f);
	glVertex3f(3.0f, -4.0f, 1.2f);
 
//PE 2 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(3.0f,-0.2f, 0.8f);
	glVertex3f(2.6f, -0.2f, 0.8f);
	glVertex3f(2.6f, -4.0f, 0.8f);
	glVertex3f(3.0f, -4.0f, 0.8f);
 
//PE 2 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(3.0f,-0.2f,1.2f);
	glVertex3f(3.0f, -0.2f, 0.8f);
	glVertex3f(3.0f, -4.0f, 0.8f);
	glVertex3f(3.0f, -4.0f, 1.2f);
	
//PE 2 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(2.6f,-0.2f,1.2f);
	glVertex3f(2.6f, -0.2f, 0.8f);
	glVertex3f(2.6f, -4.0f, 0.8f);
	glVertex3f(2.6f, -4.0f, 1.2f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ NUMERO 3
	glColor3f(rcolor3,gcolor3,bcolor3);
	
//PE 3 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0f,-0.2f,0.6f);
	glVertex3f(2.6f, -0.2f, 0.6f);
	glVertex3f(2.6f, -4.0f, 0.6f);
	glVertex3f(3.0f, -4.0f, 0.6f);
 
//PE 3 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(3.0f,-0.2f, 0.2f);
	glVertex3f(2.6f, -0.2f, 0.2f);
	glVertex3f(2.6f, -4.0f, 0.2f);
	glVertex3f(3.0f, -4.0f, 0.2f);
 
//PE 3 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(3.0f,-0.2f,0.6f);
	glVertex3f(3.0f, -0.2f, 0.2f);
	glVertex3f(3.0f, -4.0f, 0.2f);
	glVertex3f(3.0f, -4.0f, 0.6f);
	
//PE 3 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(2.6f,-0.2f,0.6f);
	glVertex3f(2.6f, -0.2f, 0.2f);
	glVertex3f(2.6f, -4.0f, 0.2f);
	glVertex3f(2.6f, -4.0f, 0.6f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ NUMERO 4
	glColor3f(rcolor4,gcolor4,bcolor4);
	
//PE 4 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0f,-0.2f,0.0f);
	glVertex3f(2.6f, -0.2f, 0.0f);
	glVertex3f(2.6f, -4.0f, 0.0f);
	glVertex3f(3.0f, -4.0f, 0.0f);
 
//PE 4 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(3.0f,-0.2f, -0.4f);
	glVertex3f(2.6f, -0.2f, -0.4f);
	glVertex3f(2.6f, -4.0f, -0.4f);
	glVertex3f(3.0f, -4.0f, -0.4f);
 
//PE 4 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(3.0f,-0.2f,0.0f);
	glVertex3f(3.0f, -0.2f, -0.4f);
	glVertex3f(3.0f, -4.0f, -0.4f);
	glVertex3f(3.0f, -4.0f, 0.0f);
	
//PE 4 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(2.6f,-0.2f,0.0f);
	glVertex3f(2.6f, -0.2f, -0.4f);
	glVertex3f(2.6f, -4.0f, -0.4f);
	glVertex3f(2.6f, -4.0f, 0.0f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ NUMERO 5
	glColor3f(rcolor5,gcolor5,bcolor5);
	
//PE 5 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0f,-0.2f,-0.6f);
	glVertex3f(2.6f, -0.2f, -0.6f);
	glVertex3f(2.6f, -4.0f, -0.6f);
	glVertex3f(3.0f, -4.0f, -0.6f);
 
//PE 5 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(3.0f,-0.2f, -1.0f);
	glVertex3f(2.6f, -0.2f, -1.0f);
	glVertex3f(2.6f, -4.0f, -1.0f);
	glVertex3f(3.0f, -4.0f, -1.0f);
 
//PE 5 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(3.0f,-0.2f,-0.6f);
	glVertex3f(3.0f, -0.2f, -1.0f);
	glVertex3f(3.0f, -4.0f, -1.0f);
	glVertex3f(3.0f, -4.0f, -0.6f);
	
//PE 5 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(2.6f,-0.2f,-0.6f);
	glVertex3f(2.6f, -0.2f, -1.0f);
	glVertex3f(2.6f, -4.0f, -1.0f);
	glVertex3f(2.6f, -4.0f, -0.6f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ NUMERO 6
	glColor3f(rcolor6,gcolor6,bcolor6);
	
//PE 6 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0f,-0.2f,-1.2f);
	glVertex3f(2.6f, -0.2f, -1.2f);
	glVertex3f(2.6f, -4.0f, -1.2f);
	glVertex3f(3.0f, -4.0f, -1.2f);
 
//PE 6 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(3.0f,-0.2f, -1.6f);
	glVertex3f(2.6f, -0.2f, -1.6f);
	glVertex3f(2.6f, -4.0f, -1.6f);
	glVertex3f(3.0f, -4.0f, -1.6f);
 
//PE 6 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(3.0f,-0.2f,-1.2f);
	glVertex3f(3.0f, -0.2f, -1.6f);
	glVertex3f(3.0f, -4.0f, -1.6f);
	glVertex3f(3.0f, -4.0f, -1.2f);
	
//PE 6 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(2.6f,-0.2f,-1.2f);
	glVertex3f(2.6f, -0.2f, -1.6f);
	glVertex3f(2.6f, -4.0f, -1.6f);
	glVertex3f(2.6f, -4.0f, -1.2f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ NUMERO 7
	glColor3f(rcolor7,gcolor7,bcolor7);
	
//PE 7 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0f,-0.2f,-1.8f);
	glVertex3f(2.6f, -0.2f, -1.8f);
	glVertex3f(2.6f, -4.0f, -1.8f);
	glVertex3f(3.0f, -4.0f, -1.8f);
 
//PE 7 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(3.0f,-0.2f, -2.2f);
	glVertex3f(2.6f, -0.2f, -2.2f);
	glVertex3f(2.6f, -4.0f, -2.2f);
	glVertex3f(3.0f, -4.0f, -2.2f);
 
//PE 7 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(3.0f,-0.2f,-1.8f);
	glVertex3f(3.0f, -0.2f, -2.2f);
	glVertex3f(3.0f, -4.0f, -2.2f);
	glVertex3f(3.0f, -4.0f, -1.8f);
	
//PE 7 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(2.6f,-0.2f,-1.8f);
	glVertex3f(2.6f, -0.2f, -2.2f);
	glVertex3f(2.6f, -4.0f, -2.2f);
	glVertex3f(2.6f, -4.0f, -1.8f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ 8
	glColor3f(rcolor1,gcolor1,bcolor1);

//PÉ 8 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0f,-0.2f,1.8f);
	glVertex3f(-2.6f, -0.2f, 1.8f);
	glVertex3f(-2.6f, -4.0f, 1.8f);
	glVertex3f(-3.0f, -4.0f, 1.8f);
	 
//PÉ 8 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f,-0.2f,1.4f);
	glVertex3f(-2.6f, -0.2f, 1.4f);
	glVertex3f(-2.6f, -4.0f, 1.4f);
	glVertex3f(-3.0f, -4.0f, 1.4f);
	 
//PÉ 8 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f,-0.2f,1.8f);
	glVertex3f(-3.0f, -0.2f, 1.4f);
	glVertex3f(-3.0f, -4.0f, 1.4f);
	glVertex3f(-3.0f, -4.0f, 1.8f);
	 
//PÉ 8 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.6f,-0.2f,1.8f);
	glVertex3f(-2.6f, -0.2f, 1.4f);
	glVertex3f(-2.6f, -4.0f, 1.4f);
	glVertex3f(-2.6f, -4.0f, 1.8f);
	
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ 9 
	glColor3f(rcolor2,gcolor2,bcolor2);

//PÉ 9 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0f,-0.2f,1.2f);
	glVertex3f(-2.6f, -0.2f, 1.2f);
	glVertex3f(-2.6f, -4.0f, 1.2f);
	glVertex3f(-3.0f, -4.0f, 1.2f);
	 
//PÉ 9 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f,-0.2f,0.8f);
	glVertex3f(-2.6f, -0.2f, 0.8f);
	glVertex3f(-2.6f, -4.0f, 0.8f);
	glVertex3f(-3.0f, -4.0f, 0.8f);
	 
//PÉ 9 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f,-0.2f,1.2f);
	glVertex3f(-3.0f, -0.2f, 0.8f);
	glVertex3f(-3.0f, -4.0f, 0.8f);
	glVertex3f(-3.0f, -4.0f, 1.2f);
	 
//PÉ 9 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.6f,-0.2f,1.2f);
	glVertex3f(-2.6f, -0.2f, 0.8f);
	glVertex3f(-2.6f, -4.0f, 0.8f);
	glVertex3f(-2.6f, -4.0f, 1.2f);
	
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ 10
	glColor3f(rcolor3,gcolor3,bcolor3);
	
//PE 10 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0f,-0.2f,0.6f);
	glVertex3f(-2.6f, -0.2f, 0.6f);
	glVertex3f(-2.6f, -4.0f, 0.6f);
	glVertex3f(-3.0f, -4.0f, 0.6f);
 
//PE 10 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f,-0.2f, 0.2f);
	glVertex3f(-2.6f, -0.2f, 0.2f);
	glVertex3f(-2.6f, -4.0f, 0.2f);
	glVertex3f(-3.0f, -4.0f, 0.2f);
 
//PE 10 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f,-0.2f,0.6f);
	glVertex3f(-3.0f, -0.2f, 0.2f);
	glVertex3f(-3.0f, -4.0f, 0.2f);
	glVertex3f(-3.0f, -4.0f, 0.6f);
	
//PE 10 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.6f,-0.2f,0.6f);
	glVertex3f(-2.6f, -0.2f, 0.2f);
	glVertex3f(-2.6f, -4.0f, 0.2f);
	glVertex3f(-2.6f, -4.0f, 0.6f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ 10
	glColor3f(rcolor4,gcolor4,bcolor4);
	
//PE 11 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0f,-0.2f,0.0f);
	glVertex3f(-2.6f, -0.2f, 0.0f);
	glVertex3f(-2.6f, -4.0f, 0.0f);
	glVertex3f(-3.0f, -4.0f, 0.0f);
 
//PE 11 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f,-0.2f, -0.4f);
	glVertex3f(-2.6f, -0.2f, -0.4f);
	glVertex3f(-2.6f, -4.0f, -0.4f);
	glVertex3f(-3.0f, -4.0f, -0.4f);
 
//PE 11 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f,-0.2f,0.0f);
	glVertex3f(-3.0f, -0.2f, -0.4f);
	glVertex3f(-3.0f, -4.0f, -0.4f);
	glVertex3f(-3.0f, -4.0f, 0.0f);
	
//PE 11 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.6f,-0.2f,0.0f);
	glVertex3f(-2.6f, -0.2f, -0.4f);
	glVertex3f(-2.6f, -4.0f, -0.4f);
	glVertex3f(-2.6f, -4.0f, 0.0f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ 12
	glColor3f(rcolor5,gcolor5,bcolor5);
	
//PE 12 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0f,-0.2f,-0.6f);
	glVertex3f(-2.6f, -0.2f, -0.6f);
	glVertex3f(-2.6f, -4.0f, -0.6f);
	glVertex3f(-3.0f, -4.0f, -0.6f);
 
//PE 12 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f,-0.2f, -1.0f);
	glVertex3f(-2.6f, -0.2f, -1.0f);
	glVertex3f(-2.6f, -4.0f, -1.0f);
	glVertex3f(-3.0f, -4.0f, -1.0f);
 
//PE 12 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f,-0.2f,-0.6f);
	glVertex3f(-3.0f, -0.2f, -1.0f);
	glVertex3f(-3.0f, -4.0f, -1.0f);
	glVertex3f(-3.0f, -4.0f, -0.6f);
	
//PE 12 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.6f,-0.2f,-0.6f);
	glVertex3f(-2.6f, -0.2f, -1.0f);
	glVertex3f(-2.6f, -4.0f, -1.0f);
	glVertex3f(-2.6f, -4.0f, -0.6f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ 13
	glColor3f(rcolor6,gcolor6,bcolor6);
	
//PE 13 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0f,-0.2f,-1.2f);
	glVertex3f(-2.6f, -0.2f, -1.2f);
	glVertex3f(-2.6f, -4.0f, -1.2f);
	glVertex3f(-3.0f, -4.0f, -1.2f);
 
//PE 13 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f,-0.2f, -1.6f);
	glVertex3f(-2.6f, -0.2f, -1.6f);
	glVertex3f(-2.6f, -4.0f, -1.6f);
	glVertex3f(-3.0f, -4.0f, -1.6f);
 
//PE 13 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f,-0.2f,-1.2f);
	glVertex3f(-3.0f, -0.2f, -1.6f);
	glVertex3f(-3.0f, -4.0f, -1.6f);
	glVertex3f(-3.0f, -4.0f, -1.2f);
	
//PE 13 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.6f,-0.2f,-1.2f);
	glVertex3f(-2.6f, -0.2f, -1.6f);
	glVertex3f(-2.6f, -4.0f, -1.6f);
	glVertex3f(-2.6f, -4.0f, -1.2f);
 
//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~//~~// 

//PÉ 14
	glColor3f(rcolor7,gcolor7,bcolor7);
	
//PE 14 LADO 1
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0f,-0.2f,-1.8f);
	glVertex3f(-2.6f, -0.2f, -1.8f);
	glVertex3f(-2.6f, -4.0f, -1.8f);
	glVertex3f(-3.0f, -4.0f, -1.8f);
 
//PE 14 LADO 2
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.0f,-0.2f, -2.2f);
	glVertex3f(-2.6f, -0.2f, -2.2f);
	glVertex3f(-2.6f, -4.0f, -2.2f);
	glVertex3f(-3.0f, -4.0f, -2.2f);
 
//PE 14 LADO 3
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f,-0.2f,-1.8f);
	glVertex3f(-3.0f, -0.2f, -2.2f);
	glVertex3f(-3.0f, -4.0f, -2.2f);
	glVertex3f(-3.0f, -4.0f, -1.8f);
	
//PE 14 LADO 4
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-2.6f,-0.2f,-1.8f);
	glVertex3f(-2.6f, -0.2f, -2.2f);
	glVertex3f(-2.6f, -4.0f, -2.2f);
	glVertex3f(-2.6f, -4.0f, -1.8f);

 //COSTA
	glColor3f(0.0f, 0.0f, 0.0f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f, 0.2f, -1.8f);
	glVertex3f(3.0f, 0.2f, -1.8f);
	glVertex3f(3.0f, 5.0f, -1.8f);
	glVertex3f(-3.0f, 3.5f, -1.8f);
 
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f, 0.2f, -2.0f);
	glVertex3f(3.0f, 0.2f, -2.0f);
	glVertex3f(3.0f, 5.0f, -2.0f);
	glVertex3f(-3.0f, 5.0f, -2.0f);
 
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f, 0.2f, -2.0f);
	glVertex3f(-3.0f, 5.0f, -2.0f);
	glVertex3f(-3.0f, 5.0f, -1.8f);
	glVertex3f(-3.0f, 0.2f, -1.8f);
 
 	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(3.0f, 0.2f, -2.0f);
	glVertex3f(3.0f, 5.0f, -2.0f);
	glVertex3f(3.0f, 5.0f, -1.8f);
	glVertex3f(3.0f, 0.2f, -1.8f);
 
 	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f, 5.0f, -2.0f);
	glVertex3f(-3.0f, 5.0f, -1.8f);
	glVertex3f(3.0f, 5.0f, -1.8f);
	glVertex3f(3.0f, 5.0f, -2.0f);

	glEnd();
	glutSwapBuffers();
}

void keyboard(int key, int x, int y)
{
	switch(key){
		case GLUT_KEY_RIGHT:
			movimenta_esq_dir = movimenta_esq_dir + 10;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			movimenta_esq_dir = movimenta_esq_dir - 10;
			glutPostRedisplay();
			break;
		case GLUT_KEY_UP:
			movimenta_cima_baixo = movimenta_cima_baixo + 10;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			movimenta_cima_baixo = movimenta_cima_baixo - 10;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F1:
			p=0;
			rcolor1 = 0.502f, gcolor1 = 0.0f, bcolor1 = 0.0f;
			rcolor2 = 1.0f, gcolor2 = 1.0f, bcolor2 = 1.0f;
			rcolor3 = 1.0f, gcolor3 = 1.0f, bcolor3 = 1.0f;
			rcolor4 = 1.0f, gcolor4 = 1.0f, bcolor4 = 1.0f;
			rcolor5 = 1.0f, gcolor5 = 1.0f, bcolor5 = 1.0f;
			rcolor6 = 1.0f, gcolor6 = 1.0f, bcolor6 = 1.0f;
			rcolor7 = 0.502f, gcolor7 = 0.0f, bcolor7 = 0.0f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F2:
			p=0;
			rcolor1 = 1.0f, gcolor1 = 0.0f, bcolor1 = 0.0f;
			rcolor2 = 1.0f, gcolor2 = 0.647f, bcolor2 = 0.0f;
			rcolor3 = 1.0f, gcolor3 = 1.0f, bcolor3 = 0.0f;
			rcolor4 = 0.0f, gcolor4 = 0.502f, bcolor4 = 0.0f;
			rcolor5 = 0.0f, gcolor5 = 1.0f, bcolor5 = 1.0f;
			rcolor6 = 1.0f, gcolor6 = 0.0f, bcolor6 = 1.0f;
			rcolor7 = 0.502f, gcolor7 = 0.0f, bcolor7 = 0.502f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F3:
			vel=20;
			p=1;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F4:
			p=0;
			rcolor1 = 0.5f, gcolor1 = 0.0f, bcolor1 = 0.0f;
			rcolor2 = 0.0f, gcolor2 = 0.0f, bcolor2 = 0.5f;
			rcolor3 = 0.0f, gcolor3 = 0.5f, bcolor3 = 0.0f;
			rcolor4 = 0.25f, gcolor4 = 0.0f, bcolor4 = 0.0f;
			rcolor5 = 0.0f, gcolor5 = 0.0f, bcolor5 = 0.25f;
			rcolor6 = 0.0f, gcolor6 = 0.25f, bcolor6 = 0.0f;
			rcolor7 = 0.125f, gcolor7 = 0.0f, bcolor7 = 0.0f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F9:
			vel=20;
			i=1;
			glutPostRedisplay();
			break;
	 	case GLUT_KEY_F10:
			i=0;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F11:
			vel=20;
			j=1;
			glutPostRedisplay();
			break;
		case GLUT_KEY_F12:
			j=0;
			glutPostRedisplay();
			break;
	}
}

void Timer(int value) {
	if(i==1){
		movimenta_cima_baixo += 10;
		i=2;         
	}else if(i==2){
		movimenta_cima_baixo += 10;
		i=1;
	}
	if(j==1){
		movimenta_esq_dir += 10;
		j=2;
	}else if(j==2){
		movimenta_esq_dir += 10;
		j=1;
	}
	if(p==1){
		rcolor1 = 1.0f, gcolor1 = 0.0, bcolor1 = 0.0f;
		rcolor2 = 1.0f, gcolor2 = 0.647f, bcolor2 = 0.0f;
		rcolor3 = 1.0f, gcolor3 = 1.0f, bcolor3 = 0.0f;
		rcolor4 = 0.0f, gcolor4 = 0.502f, bcolor4 = 0.0f;
		rcolor5 = 0.0f, gcolor5 = 1.0f, bcolor5 = 1.0f;
		rcolor6 = 1.0f, gcolor6 = 0.0f, bcolor6 = 1.0f;
		rcolor7 = 0.502f, gcolor7 = 0.0f, bcolor7 = 0.502f;	
		p=2;
	}else if(p==2){
		rcolor7 = 1.0f, gcolor1 = 0.0, bcolor1 = 0.0f;
		rcolor6 = 1.0f, gcolor2 = 0.647f, bcolor2 = 0.0f;
		rcolor5 = 1.0f, gcolor3 = 1.0f, bcolor3 = 0.0f;
		rcolor4 = 0.0f, gcolor4 = 0.502f, bcolor4 = 0.0f;
		rcolor3 = 0.0f, gcolor5 = 1.0f, bcolor5 = 1.0f;
		rcolor2 = 1.0f, gcolor6 = 0.0f, bcolor6 = 1.0f;
		rcolor1 = 0.502f, gcolor7 = 0.0f, bcolor7 = 0.502f;
		p=1;
	}
	glutPostRedisplay(); //manda o m?todo Desenha ser executado novamente
	glutTimerFunc(vel, Timer, 0); // define que a fun??o Timer dever? ser executada novamente ap?s 1 segundo
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
 	glutCreateWindow("Trabalho Final - Cadeira do Ricardo");
 	initRendering(); //AAAAAAAAAAAAAAAAAAA
 	glClearColor(1.0f,1.0f,1.0f,0.0f);
 	glutTimerFunc(vel, Timer, 0);
 	glutDisplayFunc(display);
	glutSpecialFunc(keyboard);
 	glutReshapeFunc(reshape);
 	glutMainLoop();
 	return 0;
}
