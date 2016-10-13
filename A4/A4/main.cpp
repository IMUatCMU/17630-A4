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

void testBTree()
{
    BinaryTree *tree = new BinaryTree();
    tree->add(new BinaryTreeNode(new Data("Commodore James Norrington, 1, 12-29-1677")));
    tree->add(new BinaryTreeNode(new Data("Lord Cutler Beckett, 2, 4-28-1675")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 3, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 4, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 5, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 6, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 7, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 8, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 9, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 10, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 11, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 12, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 13, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 14, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 15, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 16, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 17, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 18, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 19, 6-10-1612")));
    tree->add(new BinaryTreeNode(new Data("Davy Jones, 20, 6-10-1612")));
    
    cout << "\n" << "Press any key to continue..." << "\n";
    cin.get();
}

void pressAnyKeyToContinue()
{
    cout << "\n" << "Press any key to continue..." << "\n";
    cin.get();
}

int main(int argc, const char * argv[]) {

    testBTree();
    
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
    // TODO Print the list, also lamda
    pressAnyKeyToContinue();
    
    return 0;
}
