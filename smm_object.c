//
//  smm_node.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODENR      100
#define MAX_NODETYPE    7
#define MAX_GRADE       9



//node name expression
static char smmObj_NodeName[MAX_NODETYPE][MAX_CHARNAME] = {
       "lecture",
       "restaurant",
       "laboratory",
       "home",
       "gotolab",
       "foodchance",
       "festival"
};

static int smmObj_nodeNr=0; // 몇 개의 노드 집합이 있는가 

//structure type definition

typedef struct {
    char name[MAX_CHARNAME];
    int type;
    int credit;
    int energy; 
} smmObj_board_t;

//struct instance array definition
static smmObj_board_t smmObj_board[MAX_NODENR];


static int smm_foodNr=0; // 몇 개의 음식이 있는가 
static char smm_food[MAX_NODENR][MAX_CHARNAME];
static int smm_foodenergy[MAX_NODENR];

static int smm_festivalNr=0; //몇 개의 미션이 있는가
static char smm_festival[MAX_NODENR][MAX_CHARNAME];

//object generation
int smmObj_genNode(char* name, int type, int credit, int energy)
{
    strcpy(smmObj_board[smmObj_nodeNr].name, name);
    smmObj_board[smmObj_nodeNr].type = type;
    smmObj_board[smmObj_nodeNr].credit = credit;
    smmObj_board[smmObj_nodeNr].energy = energy;
    
    smmObj_nodeNr++; 
    
    return (smmObj_nodeNr); //노드 몇개인지 반환 
}

int smmObj_genFood(char* food, int foodenergy)
{
    strcpy(smm_food[smm_foodNr], food);
    smm_foodenergy[smm_foodNr] = foodenergy;
    
    smm_foodNr++;
    
    return (smm_foodNr);
}

int smmObj_genFestival(char* festival)
{
    strcpy(smm_festival[smm_festivalNr], festival);
    
    smm_festivalNr++;
    
    return (smm_festivalNr);
}

//member retrieving
char* smmObj_getNodeName(int node_nr)
{
      return (smmObj_board[node_nr].name);
}

int smmObj_getNodeType(int node_nr)
{
      return (smmObj_board[node_nr].type);
}

int smmObj_getNodeEnergy(int node_nr)
{
      return (smmObj_board[node_nr].energy);
}

int smmObj_getNodeCredit(int node_nr)
{
      return (smmObj_board[node_nr].credit);
}


char* smmObj_getTypeName(int node_type)
{
      return (smmObj_NodeName[node_type]);
}



#if 0
//element to string

char* smmObj_getGradeName(smmGrade_e grade)
{
    return smmGradeName[grade];
}
#endif
