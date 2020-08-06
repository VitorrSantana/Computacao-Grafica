#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "inimigos.h"
#include "variaveisGlobais.h"
#include "tiroLink.h"
#include "desenhaJogo.h"
#include "estadoJogo.h"
#include "estadoTela.h"
#include "teclado.h"
#include "inicializando.h"
#include "texturas.h"

 int num(){

      for(int i1 = (NUM_INI_HORI-1)-i; i1 >= 0 ;i1--){

        for(int j1 = j;j1< NUM_INI_VERT; j1++){
        
        if(inimigos[i1][j1].posicao.x==0  && gravaJ!=j1){

          gravaJ=j1;
          return 1;
        }
        else{return 0;}
      
      }
    }
}

int num1(){

      for(int i2 = iDirecao; iDirecao <NUM_INI_HORI ;iDirecao++){

        for(int j2 = jDirecao;jDirecao < NUM_INI_VERT; jDirecao++){
          if(inimigos[i2][j2].posicao.x==0  && gravaJDirecao!=j2){
            gravaJDirecao=j2;
            return 1;
        }
        else{return 0;}
      
      }
    }
}



void verificaColisaoBorda(){
      
      if(direcao == 1){
        j+=num();
        if((inimigos[8-i][j].posicao.x + LINK_LARG/2) == LARGURA_MUNDO){
          direcao*=-1; 
          contador++;
          if(contador % 3 == 0){
            ALTURA_INICIAL_INIMIGOS-=INI_ALT;
          }
        }
        X_INICIAL_INIMIGOS++;
      }

      if(direcao == -1){
        
        jDirecao += num1();

        if((inimigos[iDirecao][jDirecao].posicao.x - LINK_LARG/2) == 0){
          direcao*=-1; 
          contador++;
          if(contador % 3 == 0){
            ALTURA_INICIAL_INIMIGOS-=INI_ALT;
          }
        }
        X_INICIAL_INIMIGOS--;
      }
      if(jDirecao==4){
        jDirecao=0;
        iDirecao++;
      }

    if(j==4){
      j=0;
      i++;
    }
    if(ALTURA_INICIAL_INIMIGOS<=20){
    verificaGameOver();
    }
  
  glutPostRedisplay();
  glutTimerFunc(PERIODO , verificaColisaoBorda, 1);
}



/*void movimentoIni(){
  //direita]
  if(direcao == 1){
    if(verifica != (LARGURA_MUNDO - 2)){// deslIniFinalTela==112
        X_INICIAL_INIMIGOS++;
        if(verifica == (LARGURA_MUNDO - 3)){//delsIniFinalTela-1==111 PARA MUDAR A DIRECAO PARA O SENTIDO OPOSTO
          direcao*=-1; 
          contador++;
          if(contador % 3 == 0){
            ALTURA_INICIAL_INIMIGOS-=INI_ALT;
          }
        }
        verifica++;
    }
  }
  if(direcao == -1){
    if(verifica != LARGURA_MUNDO/2 ){//deslIniInicioTela==78
        X_INICIAL_INIMIGOS--;
       
        if(verifica == 82){//deslIniInicioTela==82 mesma coisa da de cima kkk
          direcao*=-1;
          contador++;
          if(contador % 3 == 0){
            ALTURA_INICIAL_INIMIGOS-=INI_ALT;
          }
        }
        verifica--;
    }
  } 
  if(ALTURA_INICIAL_INIMIGOS<=20){
    verificaGameOver();
  }
   glutPostRedisplay();
  glutTimerFunc(PERIODO , movimentoIni, 1);
}
*/


/*void movimentoTiroIni(){
  
  tiroIni.posicao.y--;
  if(tiroIni.posicao.y == 0){
    tiroIni.existencia = 0;
  }

  glutPostRedisplay();
  glutTimerFunc(PERIODO, movimentoTiroIni, 1);
}*/


// Rotina principal
int main(int argc, char **argv){
    // Acordando o GLUT
    glutInit(&argc, argv);

    // Definindo a versão do OpenGL que vamos usar
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    // Configuração inicial da janela do GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    // Abre a janela
    glutCreateWindow("Joguito");

    // Registra callbacks para alguns eventos
    inicializa();
    glutDisplayFunc(desenhaCena);
    //glutTimerFunc(PERIODO/2 , movimentoTiroLink, 1);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(tecladoEsp);

    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}