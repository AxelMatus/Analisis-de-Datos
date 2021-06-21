#include "redblack_tree.hpp"

#include <iostream>
#include <stdexcept>

using namespace std;

int main(){

    redblack_tree<int, char> tree;

    redblack_node<int, char>* n1 = new redblack_node<int, char>(99, 'a', NULL, NULL, NULL, 1);
    redblack_node<int, char>* n2 = new redblack_node<int, char>(14, 'b', NULL, NULL, NULL, 1);
    redblack_node<int, char>* n3 = new redblack_node<int, char>(05, 'c', NULL, NULL, NULL, 1);

    tree.insertNode(n1);
    tree.insertNode(n2);
    tree.insertNode(n3);

    // is balanced root should be node with key 14
    cout<<"Root: " << tree.getRoot()->key<<endl;

    char D1 = '?';
    char D2 = '?';
    char D3 = '?';

    try{
        D1 = tree.at(99);
        D2 = tree.at(14);
        D3 = tree.at(05);
    } catch (const std::exception& e){
        cout << "Error in at()" << endl;
        return 1;
    }

    cout << "Key: " << 99 << " Data: "<< D1 << endl;
    cout << "Key: " << 14 << " Data: "<< D2 << endl;
    cout << "Key: " << 05 << " Data: "<< D3 << endl;

    cout << "\nSize of the current tree: " << tree.size() << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    // Searching for unknown key
    char unknownD = '?';
    int unknownKey = 98;
    try{
        unknownD = tree.at(unknownKey);
    } catch (const std::exception& e){
        cout << "Error Searching key: " << unknownKey << endl;
    }
    cout << "Key: " << unknownKey << " Data: "<< unknownD << endl ;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    redblack_node<int, char>* n4 = new redblack_node<int, char>(100, 'd', NULL, NULL, NULL, 1);
    redblack_node<int, char>* n5 = new redblack_node<int, char>(101, 'e', NULL, NULL, NULL, 1);
    redblack_node<int, char>* n6 = new redblack_node<int, char>(102, 'f', NULL, NULL, NULL, 1);

    tree.insertNode(n4);
    tree.insertNode(n5);
    tree.insertNode(n6);

    char data_key_99 = tree[99]; // 'a'
    char data_key_14 = tree[14]; // 'b'
    char data_key_102 = tree[102]; // 'f'

    cout << "Data in key 99: " << data_key_99 << endl;
    cout << "Data in key 14: " << data_key_14 << endl;
    cout << "Data in key 102: " << data_key_102 << endl;

    cout << "\nSize of the current tree: " << tree.size() << endl ;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    //non-existent key 44 
    // Should insert new node with key 44 and data 'z'
    tree[44] = 'z';
    cout << "Data in key 44: " << tree[44] << endl;

    cout << "Size of the current tree: " << tree.size() << endl;
    
    return 0;
}