//
// Created by Alon porter on 31/12/2020.
//

#ifndef DS_WET2_LIST_H
#define DS_WET2_LIST_H

template<class T, class S=int>
struct node {
    node<T,S>* next;
    node<T,S>* previous;
    S key;
    T data;
    bool operator!=(node<T,S> compare){
        return (compare!=*this);
    }
    bool operator==(node<T,S> compare){
        return (compare==*this);
    }
    S getKey(){
        return this->key;
    }
    S getData(){
        return this->data;
    }
};
template<class T, class S=int>
    class linkedList{
        node<T,S>* head;
        node<T,S>* tail;
    public:
        linkedList<T,S>(){
            head=nullptr;
            tail=nullptr;
        }
        node<T,S>* getHead(){
            return this->head;
        }
        void insert_item(S key, T data){
            if(!head){
                // the list is empty
                head = new node<T,S>;
                head->data = data;
                head->key = key;
                head->next = nullptr;
                head->previous = nullptr;
                tail=head;
            }
            else{
                // the list isn't empty
                if(head==tail){
                    // the list has one element
                    tail = new node<T,S>;
                    tail->data = data;
                    tail->key = key;
                    tail->next = nullptr;
                    tail->previous = head;
                    head->next = tail;
                }
                else{
                    //the list has more than one element
                    node<T,S>* currentNode = new node<T,S>;
                    currentNode->data = data;
                    currentNode->key = key;
                    currentNode->next=nullptr;
                    currentNode->previous = tail;
                    tail->next = currentNode;
                    tail = currentNode;
                }
            }
        }
        node<T,S>* Search(S key){
            node<T,S>* current = head;
            while(current!=nullptr){
                if(current->key == key)
                    return current;
                current = current->next;
            }
            return nullptr;
        }
        void erase_item(){
            if(*tail == nullptr || this == nullptr || *head==nullptr) return;
            if(this == *tail){
                // the node is the last one in the list
                if(*tail==*head) {
                    // the node is the only one in the list
                    delete *this;
                    *head = *tail = nullptr;
                    return;
                }
                node<T,S>* prev = (*tail)->previous;
                if(prev) prev->next = nullptr;
                *tail=prev;
                delete this;
                return;
            }
            else if(*head == this){
                // the node is the first item in the list
                node<T,S>* next = (*head)->next;
                if(next) next->previous = nullptr;
                *head=next;
                delete this;
                return;
            }
            this->next->previous = this->previous;
            this->previous->next = this->next;
            delete this;
        }
};

#endif //DS_WET2_LIST_H
