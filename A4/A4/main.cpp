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

/*
 * Accept user input for an absolute file path
 */
static string getFilePath()
{
    string inputfilePath;
    cout << "Input the absolute file path for InputFile.dat" << "\n";
    cin >> inputfilePath;
    return inputfilePath;
}

/*
 * Read input data file, parse each line into a Data element,
 * queue each parsed item and return the queue
 */
static Queue* getDataElements()
{
    Queue *q = new LinkedListQueue();
    ifstream file;
    string line;
    int lc = 1;
    
    file.open(getFilePath(), ios::in);
    while(file)
    {
        getline(file, line);
        if (line.length() == 0
            || (line == "\n")
            || (line == "\r")
            || (line == "\r\n")
            || (line == "\n\r"))    // ignore a line that only contains return characters
            continue;
        
        Data *elem = new Data(line);
        int rc = 0;
        
        // drop the invalid line and print warning
        if (!(elem->isValid(&rc)))
        {
            cout << "Skipping line: " << lc << " due to: " << "validation failed" << "\n";
        }
        // queue any valid line
        else
        {
            q->offer(new Node(elem));
        }
        lc++;
    }
    file.close();
    return q;
}

/*
 * Convenience method to prompt "press any key to continue"
 */
void pressAnyKeyToContinue()
{
    cout << "\n" << "Press any key to continue..." << "\n";
    cin.get();
}

/*
 * Convenience method to print step notification message
 */
void notify(string message)
{
    cout << "\n**** " << message << " ****\n\n";
}

int main(int argc, const char * argv[]) {
    
    notify("Welcome");
    
    /* Get data file from user */
    Queue *q0 = getDataElements();
    if (!q0 || q0->count() == 0)
    {
        cout << "No input detected. Exiting..." << "\n";
        return 0;
    }
    notify("Data read into queue");
    pressAnyKeyToContinue();
    
    /* Dequeue, print and requeue */
    notify("About to dequeue, print and requeue the elements of the queue.");
    int totalInputSize = q0->count();
    for (int i = 0; i < totalInputSize; i++)
    {
        Node *n = q0->poll();
        cout << n->getData()->toString() << "\n";
        q0->offer(n);
    }
    pressAnyKeyToContinue();
    
    /* Reverse the order */
    notify("About to reverse the order of the elements.");
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
    
    /* Add to binary tree */
    notify("About to add to binary tree (maintaining shape)");
    BinaryTree *tree = new BinaryTree();
    while (!q1->isEmpty())
    {
        Node *n = q1->poll();
        tree->add(new BinaryTreeNode(n->getData()));
    }
    delete (LinkedListQueue*)q1;
    
    /* preorder print */
    notify("About to print tree in preorder");
    auto printLamda = [](BinaryTreeNode *n)->void {
        cout << n->getData()->toString() << "\n";
    };
    tree->preOrder(printLamda);
    pressAnyKeyToContinue();
    
    /* postorder print */
    notify("About to print tree in postorder");
    tree->postOrder(printLamda);
    pressAnyKeyToContinue();
    
    /* Add to list from tree in inorder */
    notify("About to add to list in inorder");
    List *list = new LinkedList();
    auto addToListLamda = [&](BinaryTreeNode *n)->void {
        list->addLast(new Node(n->getData()));
    };
    tree->inOrder(addToListLamda);
    delete tree;
    
    /* Print list */
    notify("About to print list");
    auto printListLamda = [](Node* n)->void{
        cout << n->getData()->toString() << "\n";
    };
    list->traverse(printListLamda);
    pressAnyKeyToContinue();
    
    /* Sort */
    notify("About to quick sort list and print");
    Sort *qsort = new QuickSort();
    qsort->sort(list);
    list->traverse(printListLamda);
    pressAnyKeyToContinue();
    
    /* Prompt user to entire a new entry */
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
    
    /* Add the new entry (preserving order) and print linked list */
    list->addPreservingOrder(new Node(inputData));
    list->traverse(printListLamda);
    pressAnyKeyToContinue();
    
    return 0;
}
