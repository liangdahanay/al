#ifndef LOWESTCOMMOMANCESTOR_H_
#define LOWESTCOMMOMANCESTOR_H_
#include "tree.h"
#include <vector>

using namespace std;


Node* LCAUpDown(Node* root, Node* p, Node* q);
Node* LCADownUp(Node* root, Node* p, Node* q);
Node* LCABST(Node* root, Node* p, Node* q);
void lowestCommonAncestorTest();

#endif
