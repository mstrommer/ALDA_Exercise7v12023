//
//  astar.cpp
//  ALDA_Exercise7v12023
//
//  Created by Michael Strommer on 19.06.23.
//

#include "astar.hpp"

// Possible values in the graph:
// -1 ... Blocked / NO NODE / Barricade / Wall...
//  0 ... Node - initial value
// >0 ... Actual cost from source to this very node
// -2 ... Shortest Path
// INFINITE ... each Node, except for the source node, is set to INFINITE in the beginning of A*

int graph[ROWS][COLS] = {0};
int updateFrom[ROWS][COLS][2] = {0};

void g_init(int begin[ROWS][COLS]){
    memcpy(graph, begin, ROWS * COLS * sizeof(int));
}

/* Computes some distance between source and target. */
int g_heuristic(int source[2], int target[2]){
    // TODO
    // if nothing is set here, this is baiscally Dijkstra
    return 0;
}

/* A* Algorithm for a given source and target node.*/
void g_astar(int source[2], int target[2]){
    // TODO
}

/* As soon as the target node is reached, this function is used to compute the shortest path. A start and end node is passed. */
void g_computeShortestPath(int source[2], int target[2]){
    int row = target[0], col = target[1];
    while(updateFrom[row][col][0] != 0 && updateFrom[row][col][1] != 0){
        int tmp = row;
        graph[row][col] = -2;
        row = updateFrom[row][col][0];
        col = updateFrom[tmp][col][1];
    }
    graph[source[0]][source[1]] = -2;
}

/* Computes all neighbors for a given cell at coordinates row and col. The function returns the amount of neighbors and stores their values in the array neighbors.
 */
int g_getNeighbors(int row, int col, int neighbors[8]){
    int count = 0;
    if(graph[row + 1][col] != -1){
        neighbors[count] = row + 1;
        neighbors[count+1] = col;
        count+=2;
    }
    if(graph[row][col + 1] != -1){
        neighbors[count] = row;
        neighbors[count+1] = col + 1;
        count+=2;
    }
    if(graph[row - 1][col] != -1){
        neighbors[count] = row - 1;
        neighbors[count+1] = col;
        count+=2;
    }
    if(graph[row][col - 1] != -1){
        neighbors[count] = row;
        neighbors[count+1] = col - 1;
        count+=2;
    }
    return count/2;
}

/* Print the graph. Also used for debugging purposes. */
void g_print(){
    int row, col;
    for(row = 0; row < ROWS; row++){
        for(col = 0; col < COLS; col++){
            if(graph[row][col] == INFINITE){
                //printf("%2i ", 0); // for debugging: shows nodes with infinite cost
                printf("%2c ", ' ');
            }
            else if(graph[row][col] == -1){
                printf("%2c ", '#');
            }
            else if(graph[row][col] == -2){
                printf("%2c ", '.');
            }
            else {
                //printf("%2i ", graph[row][col]); //for debugging: shows actual cost
                printf("%2c ", ' ');
            }
        }
        printf("\n");
    }
}

/* Retrieves the solution. NEEDED FOR AUTO-TESTING PURPOSES. Do not change. */
void getResult(int result[ROWS][COLS]){
    memcpy(result, graph, ROWS * COLS * sizeof(int));
}
