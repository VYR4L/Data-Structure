#include <iostream>

using namespace std;

class Node{
private:
    Node *left, *right;
    int key;

public:
    Node(int key){
        this->key = key;
        left = NULL;
        right = NULL;
    }
    int get_key(){
        return key;
    }
    Node* get_left(){
        return left;
    }
    Node* get_right(){
        return right;
    }
    void set_left(Node *node){
        left = node;
    }
    void set_right(Node *node){
        right = node;
    }
};

class Tree{
    Node *root;

public:
    Tree(){
        root = NULL;
    }
    void insert(int key){
        if (root == NULL){
            root = new Node(key);
        }
        else{
            insert_aux(root, key);
        }
    }
    void insert_aux(Node *node, int key){
        if (key < node->get_key()){
            if (node->get_left() == NULL){
                Node *new_node = new Node(key);
                node->set_left(new_node);
            }
            else{
                insert_aux(node->get_left(), key);
            }
        }
        else if(key > node->get_key()){
            if (node->get_right() == NULL){
                Node *new_node = new Node(key);
                node->set_right(new_node);
            }
            else{
                insert_aux(node->get_right(), key);
            }
        }
        else if(key == node->get_key()){
            cout << "Number already exists";
        }
    }
    Node* get_root(){
        return root;
    }
    void in_order(Node* node){
        if (node != NULL){
            in_order(node->get_left());
            cout << node->get_key() << " ";
            in_order(node->get_right());
        }
    }
    void pre_order(Node* node){
        if (node != NULL){
            // TODO;
        }
    }
};

int main(){

}
