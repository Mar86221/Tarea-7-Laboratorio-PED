//Luis Mario Valencia #00086221
#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *subLeft;
    nodo *subRight;
};

class BinarySearchTree{
    private:
        nodo *pBinarySearchTree;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertar(void);
    void insertarBST(nodo **, int);
    void showPreorder(nodo *);
    void showInorder(void);
    void showIn(nodo *);
    void showPost(nodo *);
    void showPostOrder(void);
    void showPreorder(void);
    void showPre(nodo *);
    void deleteNodo(int);
    void deleteNodoRec(nodo **, int);
    void searchNodo(int);
    void searchN(nodo *, int);
};

BinarySearchTree::BinarySearchTree(void)
{
    pBinarySearchTree = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    cout << "Program Execution" << endl;
}

void BinarySearchTree::insertar(void)
{
    int dato=0;
    char resp;

    do{
        cout << "Escriba 's' para continuar" << endl;
        cout << "Desea digitar un dato? ";
        cin >> resp;
        if(resp == 's'){
            cout << "Elemento que desea ingresar: ";
            cin >> dato;
            insertarBST(&pBinarySearchTree, dato);
        }

    }while(resp == 's');
}

void BinarySearchTree::insertarBST(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->subLeft = NULL;
        (*p)->subRight = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->subLeft), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->subRight), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void BinarySearchTree::showInorder(void)
{
    showIn(pBinarySearchTree);
}

void BinarySearchTree::showIn(nodo *p)
{
    if(p){
        showIn(p->subLeft);
        cout << p->dato << " ";
        showIn(p->subRight);
    }
}

void BinarySearchTree::showPreorder(void)
{
    showPre(pBinarySearchTree);
}

void BinarySearchTree::showPre(nodo *p)
{
    if(p){
        cout << p->dato << " ";
        showPre(p->subLeft);
        showPre(p->subRight);
    }
}

void BinarySearchTree::showPostOrder(void)
{
    showPost(pBinarySearchTree);
}

void BinarySearchTree::showPost(nodo *p)
{
    if(p)
    {
        showPost(p->subLeft);
        showPost(p->subRight);
        cout << p->dato << " ";
    }
}

void BinarySearchTree::deleteNodo(int dato)
{
    deleteNodoRec(&pBinarySearchTree, dato);
}

void BinarySearchTree::deleteNodoRec(nodo **r, int dato)
{
    nodo *p;

    if(!(*r)) 
        cout << "La llave NO esta en el arbol" << endl << endl;
    else
        if(dato < (*r)->dato) 
            deleteNodoRec(&((*r)->subLeft), dato);
        else
            if(dato > (*r)->dato) 
                deleteNodoRec(&((*r)->subRight), dato);
            else{ 
                if(!((*r)->subLeft) && !((*r)->subRight)){ 
                    p = *r;
                    *r = NULL;
                }
                else
                    if(!((*r)->subLeft) && (*r)->subRight){ 
                        p = *r; 
                        *r = (*r)->subRight;
                    }
                    else
                        if((*r)->subLeft && !((*r)->subRight)){ 
                            p = *r; 
                            *r = (*r)->subLeft; 
                        }
                        else
                            if((*r)->subLeft && (*r)->subRight){ 
                                p = (*r)->subLeft; 
                                if(!p->subRight){
                                    (*r)->dato = p ->dato;
                                    (*r)->subLeft = p->subLeft;
                                }
                                else{
                                    nodo *q;
                                    while(p->subRight){
                                        q = p;
                                        p = p->subRight;
                                    }
                                    (*r)->dato = p->dato;
                                    q->subRight = p->subLeft;
                                }
                            }
                delete p;
            }
}

void BinarySearchTree::searchNodo(int dato)
{
    searchN(pBinarySearchTree, dato);
}

void BinarySearchTree::searchN(nodo *p, int dato)
{
    if(!p)
        cout << "La llave no esta en el arbol" << endl << endl;
    else
        if(dato < p->dato)
            searchN(p->subLeft, dato);
        else
            if(dato > p->dato)
                searchN(p->subRight, dato);
            else
                cout << "Se ha encontrado la llave" << endl << endl;
}

int main(void)
{
    int data=0, datas=0;
    cout << endl;
    cout << "Binary Search Tree :D modificado" << endl;

    BinarySearchTree objBinarySearchTree;

    cout << "Insertar datos en el arbol:" <<  endl;
    objBinarySearchTree.insertar();

    cout << "Mostrar Pre-orden: " << endl;
    objBinarySearchTree.showPreorder();
    cout << endl;

    cout << "Mostrar In-Orden: " << endl;
    objBinarySearchTree.showInorder();
    cout << endl;

    cout << "Mostrar Post-Orden: " << endl;
    objBinarySearchTree.showPostOrder();
    cout << endl;

    cout << "Que dato desea buscar: " << endl;
    cin >> datas;
    objBinarySearchTree.searchNodo(datas);

    cout << "Que dato desea eliminar: " <<endl;
    cin >> data;
    objBinarySearchTree.deleteNodo(data);

    cout << "Mostrar In-Orden: " << endl;
    objBinarySearchTree.showInorder();
    cout << endl;

    return 0;
}