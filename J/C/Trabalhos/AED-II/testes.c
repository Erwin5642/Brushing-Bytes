#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"

const unsigned short g_X_NODE_SIZE = 75;
const unsigned short g_Y_NODE_SIZE = 50;
const unsigned short g_X_SCREEN_SIZE = 800;
const unsigned short g_Y_SCREEN_SIZE = 600;
static int g_X_NODE = g_X_NODE_SIZE;
static int g_Y_NODE = g_Y_NODE_SIZE;

void inverteString(char str[], int length){
    int start = 0, end = length - 1;
    char temp;
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

char *intToString(int valor, char *str){
    int i = 0, isNegative = 0;
    if(valor == 0){
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if(valor < 0){
        isNegative = 1;
        valor = -valor;
    }
    while(valor != 0){
        str[i++] ='0' + (valor % 10);
        valor = valor / 10;
    }
    if(isNegative){
        str[i++] = '-';
    }
    str[i] = '\0';
    inverteString(str, i);
    return str;
}
void drawNode(int valor){
    char v[4];
    gfx_rectangle(g_X_NODE, g_Y_NODE, g_X_NODE + g_X_NODE_SIZE, g_Y_NODE + g_Y_NODE_SIZE);
    intToString(valor, v);
    gfx_text((g_X_NODE_SIZE)/2 + g_X_NODE, (g_Y_NODE_SIZE)/2 + g_Y_NODE - 5, v);
    g_X_NODE += g_X_NODE_SIZE + 50;
}

void drawArrow(){
    int x = g_X_NODE - 35, y = g_Y_NODE + g_Y_NODE_SIZE/2;
    gfx_line(x, y, x + 20, y);
    gfx_line(x + 10, y + 10, x + 20, y);
    gfx_line(x + 10, y - 10, x + 20, y);
}
//void drawLinkedList(LinkedList *L, int qtd){
//
//}

int main(){
    gfx_init(g_X_SCREEN_SIZE, g_Y_SCREEN_SIZE, "Teste");

    drawNode(1);
    drawArrow();
    drawNode(2);
    drawArrow();
    drawNode(3);
    drawArrow();
    drawNode(4);
    drawArrow();

    gfx_paint();
    getchar();

    gfx_quit();
    return 0;
}