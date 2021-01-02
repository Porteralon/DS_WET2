//
// Created by Alon porter on 31/12/2020.
//

#include "HashTable.h"
#include "linkedList.h"

int main(){
    HashTable<int,int> table;
    table.insertItem(234124,4);
    table.insertItem(234129,3);
    table.insertItem(234125,7);
    table.deleteItem(234129);
    table.deleteItem(234125);
    table.insertItem(234121,555);
}