#include <iostream>
#include <string>

using namespace std;

struct studentname {
char letter;
struct studentname *next;
};

typedef struct studentname STUDENTName;
typedef STUDENTName *STUDENTNamePtr;


