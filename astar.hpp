//
//  astar.hpp
//  ALDA_Exercise7v12023
//
//  Created by Michael Strommer on 19.06.23.
//

#ifndef astar_hpp
#define astar_hpp

#include <stdio.h>
#include <memory.h>
#include <math.h>
#include "pqueue.hpp"

#define INFINITE 0x7FFFFFFF
#define ROWS 10
#define COLS 10

void  g_init(int begin[ROWS][COLS]);
void  g_astar(int start_node[2], int end_node[2]);
int   g_heuristic(int start_node[2], int end_node[2]);
int   g_getNeighbors(int row, int col, int neighbors[8]);
void  g_computeShortestPath(int start_node[2], int end_node[2]);
void  g_print(void);
void  getResult(int result[ROWS][COLS]);

#endif /* astar_hpp */
