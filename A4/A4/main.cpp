//
//  main.cpp
//  A4
//
//  Created by Weinan Qiu on 2016-10-11.
//  Copyright © 2016 17630. All rights reserved.
//

#include <iostream>
#include "node.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "linked_list_queue.hpp"
#include "linked_list_stack.hpp"
#include "linked_list.hpp"
#include "data.hpp"
#include "bt_node.hpp"
#include "binary_tree.hpp"
#include "sort.hpp"
#include "quick_sort.hpp"

#include <fstream>
#include <string>

using namespace std;

static string getFilePath()
{
//    string inputfilePath;
//    cout << "Input the absolute file path for InputFile.dat" << "\n";
//    cin >> inputfilePath;
//    return inputfilePath;
    return "/Users/davidiamyou/Downloads/InputFile.dat";
}

static Queue* getDataElements()
{
    Queue *q = new LinkedListQueue();
    ifstream file;
    string line;
    int lc = 1;
    
    //file.open(getFilePath(), ios::in);
    file.open(getFilePath(), ios::in);
    while(file)
    {
        getline(file, line);
        if (line.length() == 0
            || (line == "\n")
            || (line == "\r")
            || (line == "\r\n")
            || (line == "\n\r"))
            continue;
        
        Data *elem = new Data(line);
        int rc = 0;
        if (!(elem->isValid(&rc)))
        {
            cout << "Skipping line: " << lc << " due to: " << "validation failed" << "\n";
        }
        else
        {
            q->offer(new Node(elem));
        }
        lc++;
    }
    file.close();
    return q;
}

void pressAnyKeyToContinue()
{
    cout << "\n" << "Press any key to continue..." << "\n";
    cin.get();
}



int main(int argc, const char * argv[]) {
    
    Queue *q0 = getDataElements();
    if (!q0 || q0->count() == 0)
    {
        cout << "No input detected. Exiting..." << "\n";
        return 0;
    }
    
    int totalInputSize = q0->count();
    for (int i = 0; i < totalInputSize; i++)
    {
        Node *n = q0->poll();
        cout << n->getData()->toString() << "\n";
        q0->offer(n);
    }
    pressAnyKeyToContinue();
    
    Stack *s1 = new LinkedListStack();
    Queue *q1 = new LinkedListQueue();
    while (!q0->isEmpty())
    {
        s1->push(q0->poll());
    }
    delete (LinkedListQueue*)q0;
    while (!s1->isEmpty())
    {
        q1->offer(s1->pop());
    }
    for (int i = 0; i < totalInputSize; i++)
    {
        Node *n = q1->poll();
        cout << n->getData()->toString() << "\n";
        q1->offer(n);
    }
    pressAnyKeyToContinue();
    
    BinaryTree *tree = new BinaryTree();
    while (!q1->isEmpty())
    {
        Node *n = q1->poll();
        tree->add(new BinaryTreeNode(n->getData()));
    }
    delete (LinkedListQueue*)q1;
    
    auto printLamda = [](BinaryTreeNode *n)->void {
        cout << n->getData()->toString() << "\n";
    };
    tree->preOrder(printLamda);
    pressAnyKeyToContinue();
    
    tree->postOrder(printLamda);
    pressAnyKeyToContinue();
    
    List *list = new LinkedList();
    auto addToListLamda = [&](BinaryTreeNode *n)->void {
        list->addLast(new Node(n->getData()));
    };
    tree->inOrder(addToListLamda);
    delete tree;
    auto printListLamda = [](Node* n)->void{
        cout << n->getData()->toString() << "\n";
    };
    list->traverse(printListLamda);
    pressAnyKeyToContinue();
    
    Sort *qsort = new QuickSort();
    qsort->sort(list);
    list->traverse(printListLamda);
    pressAnyKeyToContinue();
    
    string input = "";
    cout << "Please enter another entry:" << "\n";
    getline(cin, input);
    
    Data *inputData = new Data(input);
    int rc = 0;
    if (!(inputData->isValid(&rc)))
    {
        cout << "Input not valid: " << rc << "\n";
        return -1;
    }
    list->addPreservingOrder(new Node(inputData));
    list->traverse(printListLamda);
    pressAnyKeyToContinue();
    
    return 0;
}
