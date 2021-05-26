#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iterator>
using namespace std;


namespace ariel{




    template <typename T> 
    class BinaryTree{



        class Node{
            public:
            Node *parent;
            Node *left;
            Node *right;
            T value;
            Node (T value) : value(value), left(NULL),right(NULL),parent(NULL){};
        };



        Node *root;

        public:
        
        BinaryTree() : root(nullptr){
        }

        BinaryTree& add_root(const T &i){return *this;}
        BinaryTree& add_left(const T &dad, const T &child){return *this;}
        BinaryTree& add_right(const T &dad, const T &child){return *this;}
        friend ostream &operator<<(ostream &os, const BinaryTree<T> &BinaryTree){return os;}

        class Preorder{
            public:
            Node *current;
            Preorder(Node *ptr = NULL) : current(ptr){};
            T &operator*() const {return current -> value;}
            T *operator->() const {return &(current -> value);}
            Preorder &operator ++(){return *this;}
            bool operator ==(const Preorder &other) const {return false;}
            bool operator !=(const Preorder &other) const {return false;}


        };

        Preorder begin_preorder(){return Preorder{};}
        Preorder end_preorder(){return Preorder{};}


        class Inorder{
            public:
            Node *current;
            Inorder(Node *ptr = NULL) : current(ptr){};
            T &operator*() const {return current -> value;}
            T *operator->() const {return &(current -> value);}
            Inorder &operator ++(){return *this;}
            bool operator ==(const Inorder &other) const {return false;}
            bool operator !=(const Inorder &other) const {return false;}


        };

        Inorder begin_inorder(){return Inorder{};};
        Inorder end_inorder(){return Inorder{};};

        Inorder begin(){return Inorder{};};
        Inorder end(){return Inorder{};};


        class Postorder{
            public:
            Node *current;
            Postorder(Node *ptr = NULL) : current(ptr){};
            T &operator*() const {return current -> value;}
            T *operator->() const {return &(current -> value);}
            Postorder &operator ++(){return *this;}
            bool operator ==(const Postorder &other) const {return false;}
            bool operator !=(const Postorder &other) const {return false;}


        };

        Postorder begin_postorder(){return Postorder{};};
        Postorder end_postorder(){return Postorder{};};
    };
}