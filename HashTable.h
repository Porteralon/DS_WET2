//
// Created by Alon porter on 31/12/2020.
//

#ifndef DS_WET2_HASHTABLE_H
#define DS_WET2_HASHTABLE_H
#include <cmath>

#define INITIAL_SIZE 2
#define QUARTER 0.25
#define LOAD_FACTOR (sqrt(5)-1)/2

#include "linkedList.h"
#include <exception>

class HashException : public std::exception{};

template<class T,class S=int>
class HashTable{
    int table_size;
    int num_of_items;
    linkedList<T,S>* table;
public :
    HashTable(): table_size(INITIAL_SIZE), num_of_items(0){
        table = new linkedList<T,S>[table_size];
    }
    HashTable(int table_size): table_size(table_size), num_of_items(0){
        table = new linkedList<T,S>[table_size];
    }
    void expand(){
        int old_table_size = table_size;
        table_size *=2;
        HashTable<T,S>* new_table = new HashTable<T,S>(table_size);
        for(int i=0;i<old_table_size;i++){
            node<T,S>* iterable = table[i].getHead();
            while(iterable!=nullptr){
                new_table->insertItem(iterable->getKey(),iterable->getData());
                iterable=iterable->next;
            }
        }
        delete table;
        table = new_table->table;
        delete new_table;
    };
    void decrease(){
        int old_table_size = table_size;
        table_size =table_size/2;
        HashTable<T,S>* new_table = new HashTable<T,S>(table_size);
        for(int i=0;i<old_table_size;i++){
            node<T,S>* iterable = table[i].getHead();
            while(iterable!= nullptr){
                new_table->insertItem(iterable->getKey(),iterable->getData());
                iterable=iterable->next;
            }
        }
        delete table;
        table = new_table->table;
        delete new_table;
    };
    int hashFunction(T item){
        double frac = LOAD_FACTOR*double(item)-int(LOAD_FACTOR*double(item));
        return int(table_size*frac);
    }
    linkedList<T,S> getItem(S key){
        int index = hashFunction(key);
        return table[index].Search(key);
    }
    void insertItem(S key, T data){
        int index = hashFunction(key);
        if(table[index].Search(key)!= nullptr){
            throw HashException();
        }
        table[index].insert_item(key,data);
        num_of_items++;
        if(num_of_items==table_size){this->expand();}
    }
    void deleteItem(S key){
        int index = hashFunction(key);
        if(!table[index].Search(key)){
            throw HashException();
        }
        node<T,S>* item_to_delete = table[index].Search(key);
        if(item_to_delete!=NULL){
            table[index].erase_item(item_to_delete);
        }
            num_of_items--;
            if(num_of_items==QUARTER*table_size){
                this->decrease();
            }
        }
};

#endif //DS_WET2_HASHTABLE_H
