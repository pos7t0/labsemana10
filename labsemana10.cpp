#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct Arbol
{
    int data;
    Arbol* left;
    Arbol* right;
};
Arbol *createarbol(int data){
    Arbol* newarbol = new Arbol;
    newarbol->data= data;
    newarbol->left=NULL;
    newarbol->right=NULL;
    return newarbol;
}
Arbol* insertNode(Arbol* root,int data){
    if(root==NULL){
        root=createarbol(data);
    }else{
        if(root->data>data){
            root->left=insertNode(root->left,data);
        }else{
            root->right=insertNode(root->right,data);
        }
    }
    return root;
}
void printarbol(Arbol* root){
    if (root == NULL) {
        return;
    }
    printarbol(root->left);
    cout << root->data << " ";
    printarbol(root->right);

}
//      ****ejercicio 2*****
void printarbol_pre_order(Arbol* root){
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printarbol_pre_order(root->left);
    printarbol_pre_order(root->right);

}
//      ****ejercicio 3*****
void printarbol_in_order(Arbol* root){
    if (root == NULL) {
        return;
    }
    printarbol_in_order(root->left);
    cout << root->data << " ";
    printarbol_in_order(root->right);
    
}
//      ****ejercicio 4*****
void printarbol_post_order(Arbol* root){
    if (root == NULL) {
        return;
    }
    printarbol_post_order(root->left);
    printarbol_post_order(root->right);
    cout << root->data << " ";
}
//      ****ejercicio 6*****
Arbol *dfs(Arbol* root, int data){
    if(root==NULL || root->data==data){
        return root;
    }
    Arbol* left_result = dfs(root->left,data);
    if(left_result !=NULL){
        return left_result;
    }
    Arbol* right_result = dfs(root->right,data);
    if(right_result!=NULL){
        return right_result;
    }

    return NULL;
}
//      ****ejercicio 7*****
Arbol* bfs(Arbol* root, int data){
    queue<Arbol*> q;
    q.push(root);
    while(!q.empty()){
        Arbol* current =q.front();
        q.pop();
        if(current->data==data){
            return current;
        }
        if(current->left !=NULL){
            q.push(current->left);
        }
        if(current->right !=NULL){
            q.push(current->right);
        }
    }

    return NULL;
}
Arbol* deleteNode(Arbol* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
        Arbol* temp = root->right;
        delete root;
        return temp;
        } else if (root->right == NULL) {
        Arbol* temp = root->left;
        delete root;
        return temp;
        }
        Arbol* temp = root->right;
        while (temp->left != NULL) {
        temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    //*********no cambie arreglo**********
    int arreglo[10]={10,9,7, 6, 5,12, 15, 18, 19, 21};
    Arbol *root=NULL;
    Arbol *rootejercicio5=NULL;
    //      ****ejercicio 1*****
    //creo el arbol de la imagen
    root=createarbol(1);
    root->left=createarbol(2);
    root->right=createarbol(3);
    root->left->left=createarbol(4);
    root->left->right=createarbol(5);
    root->right->left=createarbol(6);
    root->right->right=createarbol(7);  
    //printarbol(root);
    //cout << " "<< endl;
    //      ****ejercicio 2*****
    //printarbol_pre_order(root);
    //cout << " "<< endl;
    //      ****ejercicio 3*****
    //printarbol_in_order(root);
    //cout << " "<< endl;
    //      ****ejercicio 4*****
    //printarbol_post_order(root);
    //      ****ejercicio 5*****
    //agrego todo lo que esta en el arreglo
    for(int i=0;i<10;i++){

        rootejercicio5=insertNode(rootejercicio5,arreglo[i]);

    }
    //imprimo in order para ordenar los datos
    cout << " "<< endl;
    printarbol_in_order(rootejercicio5);
    
    //      ****ejercicio 6*****
    //imprimo para saber si devuelve un arbol o no
    //en este caso si lo imprime porque existe
    cout << dfs(root,7)->data << endl;
    //en este caso no lo imprime porque no existe
    cout << dfs(root,8)->data << endl;

    //      ****ejercicio 7*****
    //imprimo para saber si devuelve un arbol o no
    //en este caso si lo imprime porque existe
    cout << bfs(root,7)->data << endl;
    //en este caso no lo imprime porque no existe
    cout << bfs(root,8)->data << endl;
    //elimino los datos
    for(int i=1;i<22;i++){
        deleteNode(root,i);
        deleteNode(rootejercicio5,i);
    }
    return 0;
}