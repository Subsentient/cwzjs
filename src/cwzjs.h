#ifndef _CWZJS_H_
#define _CWZJS_H_

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/**Inline support?**/
#if __STDC_VERSION__ >= 199901L || defined(__cplusplus)
#define _inline inline

#if __STDC_VERSION__ >= 199901L
#include <stdbool.h>
#else
typedef unsigned char bool;
enum { false, true };
#endif //__STDC_VERSION__ >= 199901L

#else //__STDC_VERSION__ >= 199901L || defined(__cplusplus)

#define _inline
#endif //__STDC_VERSION__ >= 199901L || defined(__cplusplus)

#include <stdint.h> //This breaks C89 technically but most stuff still works with it.

#include "cwzjs_constants.h"

struct CWZJS_BASE_OBJECT
{
	const char *name;
	int id;
	int x, y, z; //Coordinates
	int armour;
	int thermal;
	int type;
	int8_t player;
	bool selected : 1;
	bool born : 1;
};
	
struct CWZJS_FEATURE
{
	int health;
	int stattype;
	bool damageable;
};

struct CWZJS_WEAPON
{
	const char *id;
	const char *fullname;
	const char *name;
	int lastFired;
	int armed;
};
	
	
struct CWZJS_DROID
{
	struct CWZJS_WEAPON *weapons;
	const char *name;
	const char *body;
	const char *propulsion;
	double health;
	int id;
	int x, y, z; //Coordinates
	int player;
	int armour;
	int thermal;
	int type;
	int selected;
	int born;
	int *group;
	int action;
	int *range;
	int order;
	int cost;
	int bodySize;
	int droidType;
	int experience;
	int cargoSize;
	bool isRadarDetector : 1;
	bool isCB : 1;
	bool isSensor : 1;
	bool canHitAir : 1;
	bool canHitGround : 1;
	bool isVTOL : 1;
	bool hasIndirect : 1;
};
struct CWZJS_STRUCTURE
{
    double health;
    int *range;
    int status;
    int cost;
    int stattype;
    int *capacity;
    bool isCB : 1;
    bool isSensor : 1;
    bool canHitAir : 1;
    bool canHitGround : 1;
    bool hasIndirect : 1;
    bool isRadarDetector : 1;

};

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_CWZJS_H_
