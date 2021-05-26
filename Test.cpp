#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iterator>

#include "doctest.h"
#include "BinaryTree.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("root"){

    BinaryTree<int> intTree;
    CHECK_THROWS(intTree.add_left(1,2));
    CHECK_THROWS(intTree.add_right(1,3));
    CHECK_NOTHROW(intTree.add_root(5));
    CHECK_NOTHROW(intTree.add_root(10));
    CHECK_THROWS(intTree.add_left(1,2));
    CHECK_THROWS(intTree.add_right(1,3));
    CHECK_NOTHROW(intTree.add_left(10,2));
    CHECK_NOTHROW(intTree.add_right(10,3));
    CHECK_NOTHROW(intTree.add_left(2,5));
    CHECK_NOTHROW(intTree.add_right(2,5));
    CHECK_NOTHROW(intTree.add_left(3,5));
    CHECK_NOTHROW(intTree.add_right(3,5));

    BinaryTree<double> doubleTree;
    CHECK_THROWS(doubleTree.add_left(1.0,2.0));
    CHECK_THROWS(doubleTree.add_right(1.0,3.0));
    CHECK_NOTHROW(doubleTree.add_root(5.0));
    CHECK_NOTHROW(doubleTree.add_root(10.0));
    CHECK_THROWS(doubleTree.add_left(1.0,2.0));
    CHECK_THROWS(doubleTree.add_right(1.0,3.0));
    CHECK_NOTHROW(doubleTree.add_left(10.0,2.0));
    CHECK_NOTHROW(doubleTree.add_right(10.0,3.0));
    CHECK_NOTHROW(doubleTree.add_left(2.0,5.0));
    CHECK_NOTHROW(doubleTree.add_right(2.0,5.0));
    CHECK_NOTHROW(doubleTree.add_left(3.0,5.0));
    CHECK_NOTHROW(doubleTree.add_right(3.0,5.0));

    BinaryTree<char> charTree;
    CHECK_THROWS(charTree.add_left('1','2'));
    CHECK_THROWS(charTree.add_right('1','3'));
    CHECK_NOTHROW(charTree.add_root('5'));
    CHECK_NOTHROW(charTree.add_root('9'));
    CHECK_THROWS(charTree.add_left('1','2'));
    CHECK_THROWS(charTree.add_right('1','3'));
    CHECK_NOTHROW(charTree.add_left('9','2'));
    CHECK_NOTHROW(charTree.add_right('9','3'));
    CHECK_NOTHROW(charTree.add_left('2','5'));
    CHECK_NOTHROW(charTree.add_right('2','5'));
    CHECK_NOTHROW(charTree.add_left('3','5'));
    CHECK_NOTHROW(charTree.add_right('3','5'));
    
    BinaryTree<string> stringTree;
    CHECK_THROWS(stringTree.add_left("1","2"));
    CHECK_THROWS(stringTree.add_right("1","3"));
    CHECK_NOTHROW(stringTree.add_root("5"));
    CHECK_NOTHROW(stringTree.add_root("10"));
    CHECK_THROWS(stringTree.add_left("1","2"));
    CHECK_THROWS(stringTree.add_right("1","3"));
    CHECK_NOTHROW(stringTree.add_left("10","2"));
    CHECK_NOTHROW(stringTree.add_right("10","3"));
    CHECK_NOTHROW(stringTree.add_left("2","5"));
    CHECK_NOTHROW(stringTree.add_right("2","5"));
    CHECK_NOTHROW(stringTree.add_left("3","5"));
    CHECK_NOTHROW(stringTree.add_right("3","5"));


}


TEST_CASE("int Orders"){
    BinaryTree<int> intTree;
    CHECK_NOTHROW(intTree.add_root(10));
    CHECK_NOTHROW(intTree.add_left(10,2));
    CHECK_NOTHROW(intTree.add_right(10,3));
    CHECK_NOTHROW(intTree.add_right(2,25));
    CHECK_NOTHROW(intTree.add_left(3,35));

    int preorder[] = {10,2,25,3,35};
    int inorder[] = {2,25,10,35,3};
    int postorder[] = {25,2,35,3,10};

    int counter = 0;
    for (auto it=intTree.begin_preorder(); it!=intTree.end_preorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
    counter = 0;
    for (auto it=intTree.begin_inorder(); it!=intTree.end_inorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
    counter = 0;
    for (auto it=intTree.begin_postorder(); it!=intTree.end_postorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
}

TEST_CASE("double Orders"){
    BinaryTree<double> doubleTree;
    CHECK_NOTHROW(doubleTree.add_root(10.0));
    CHECK_NOTHROW(doubleTree.add_left(10.0,2.0));
    CHECK_NOTHROW(doubleTree.add_right(10.0,3.0));
    CHECK_NOTHROW(doubleTree.add_right(2.0,25.0));
    CHECK_NOTHROW(doubleTree.add_left(3.0,35.0));

    double preorder[] = {10.0,2.0,25.0,3.0,35.0};
    double inorder[] = {2.0,25.0,10.0,35.0,3.0};
    double postorder[] = {25.0,2.0,35.0,3.0,10.0};

    
    int counter = 0;
    for (auto it=doubleTree.begin_preorder(); it!=doubleTree.end_preorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
    counter = 0;
    for (auto it=doubleTree.begin_inorder(); it!=doubleTree.end_inorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
    counter = 0;
    for (auto it=doubleTree.begin_postorder(); it!=doubleTree.end_postorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
}

TEST_CASE("char Orders"){

BinaryTree<char> charTree;
    CHECK_NOTHROW(charTree.add_root('9'));
    CHECK_NOTHROW(charTree.add_left('9','2'));
    CHECK_NOTHROW(charTree.add_right('9','3'));
    CHECK_NOTHROW(charTree.add_right('2','7'));
    CHECK_NOTHROW(charTree.add_left('3','8'));

    char preorder[] = {'9','2','7','3','8'};
    char inorder[] = {'2','7','9','8','3'};
    char postorder[] = {'7','2','8','3','9'};

    int counter = 0;
    for (auto it=charTree.begin_preorder(); it!=charTree.end_preorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
    counter = 0;
    for (auto it=charTree.begin_inorder(); it!=charTree.end_inorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
    counter = 0;
    for (auto it=charTree.begin_postorder(); it!=charTree.end_postorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }

}

TEST_CASE("string Orders"){

    BinaryTree<string> stringTree;
    CHECK_NOTHROW(stringTree.add_root("10"));
    CHECK_NOTHROW(stringTree.add_left("10","2"));
    CHECK_NOTHROW(stringTree.add_right("10","3"));
    CHECK_NOTHROW(stringTree.add_right("2","25"));
    CHECK_NOTHROW(stringTree.add_left("3","35"));

    string preorder[] = {"10","2","25","3","35"};
    string inorder[] = {"2","25","10","35","3"};
    string postorder[] = {"25","2","35","3","10"};

    int counter = 0;
    for (auto it=stringTree.begin_preorder(); it!=stringTree.end_preorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
    counter = 0;
    for (auto it=stringTree.begin_inorder(); it!=stringTree.end_inorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
    counter = 0;
    for (auto it=stringTree.begin_postorder(); it!=stringTree.end_postorder(); ++it) {
        CHECK_EQ((*it) , inorder[counter]);
        counter++;
    }
}