#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <assert.h>

#include "sinoca.h"

#define POINTS_3 3
#define POINTS_J 5
#define POINTS_Q 8
#define POINTS_K 12
#define POINTS_A 20

void slotRand(deck line[])
{
    /* Values between 0 y 4 pseudo-randomly */
    for (int i=0; i < LINE_SIZE; i++) {
       line[i] = (rand() % (MAX_VAL - MIN_VAL + 1));
    }
}

int slot() 
{
    deck line[3];
    char opt;

    srand(time(NULL));
    initUI();
    int isPlaying = 1;
    int points = 0;
    while((opt = getch()) == ' ' && isPlaying) {
        
        slotRand(line);
        board(line);

        /* Give user points if made a line. */ 
                                                // Preguntar -> Como puedo
                                                // guardar info de users?
        printw("%d", rewards(line, &points));
        
        // Agregar opciones para menu. 
    }

    endwin();
    printf("Gracias por jugar al sinoca.\n");
    return 1;
}

// Hacer un csv que lea con un strtok
int rewards(deck line[], int * points)
{
    
    if (line[0] == line[1] && line[0] == line[2]) {
        switch (line[0])
        {
        case 0:
                *points+=POINTS_3;
            break;
        case 1:
                *points+=POINTS_J;
            break;
        case 2:
                *points+=POINTS_Q;
            break;
        case 3:
                *points+=POINTS_K;
            break;
        case 4:
                *points+=POINTS_A;
            break;
        default:
            break;
        }            
        printw("Yay!\n");
            
    }
    return *points;
}
