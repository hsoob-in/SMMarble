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

#define SMMNODE_TYPE_LECTURE            0
#define SMMNODE_TYPE_RESTAURANT         1
#define SMMNODE_TYPE_LABORATORY         2
#define SMMNODE_TYPE_HOME               3
#define SMMNODE_TYPE_GOTOLAB            4
#define SMMNODE_TYPE_FOODCHANCE         5
#define SMMNODE_TYPE_FESTIVAL           6

//node name expression
static char smmNodeName[MAX_NODETYPE][MAX_CHARNAME] = {
       "lecture",
       "restaurant",
       "laboratory",
       "home",
       "gotolab",
       "foodchance",
       "festival"
};

static int smm_nodeNr=0; // 몇 개의 노드 집합이 있는가 
static char smm_name[MAX_NODENR][MAX_CHARNAME];
static int smm_type[MAX_NODENR];
static int smm_credit[MAX_NODENR];
static int smm_energy[MAX_NODENR];

static int smm_foodNr=0; // 몇 개의 음식이 있는가 
static char smm_food[MAX_NODENR][MAX_CHARNAME];
static int smm_foodenergy[MAX_NODENR];

static int smm_festivalNr=0; //몇 개의 미션이 있는가
static char smm_festival[MAX_NODENR][MAX_CHARNAME];

//object generation
int smmObj_genNode(char* name, int type, int credit, int energy)
{
    strcpy(smm_name[smm_nodeNr],name);
    smm_type[smm_nodeNr] = type;
    smm_credit[smm_nodeNr] = credit;
    smm_energy[smm_nodeNr] = energy;
    
    smm_nodeNr++; 
    
    return (smm_nodeNr); //노드 몇개인지 반환 
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
char* smmObj_getName(int node_nr)
{
      return (smm_name[node_nr]);
}

int smmObj_getType(int node_nr)
{
      return (smm_type[node_nr]);
}

char* smmObj_getTypeName(int node_nr)
{
      return (smmNodeName[smm_type[node_nr]]);
}



#if 0
//element to string
char* smmObj_getNodeName(smmNode_e type)
{
    return smmNodeName[type];
}

char* smmObj_getGradeName(smmGrade_e grade)
{
    return smmGradeName[grade];
}
#endif
