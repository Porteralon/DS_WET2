//
// Created by Alon porter on 02/01/2021.
//

#ifndef DS_WET2_COURSEMANAGER_H
#define DS_WET2_COURSEMANAGER_H

#include "AVL_Tree.h"
#include "HashTable.h"

typedef HashTable<linkedList<HashTable<AVL_Node<int,int>,int>,int>,int> Course_hash_table;

class CourseManager {
    Course_hash_table CoursesTable;
    AVL_Tree<int,int> time_tree;

public:
    coursesManager();
    ~coursesManager();
    AddCourse(int courseID);
    RemoveCourse(int courseID);
    AddClass(int courseID,*);
    WatchClass(int courseID,int classID, int time);
    TimeViewed(int courseID,int classID,*);
    GetIthWatchedClass(int i,*,*);
};


#endif //DS_WET2_COURSEMANAGER_H
