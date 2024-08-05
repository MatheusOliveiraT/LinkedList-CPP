#include <iostream>

using namespace std;

class Knot {
    public:
        int data;
        Knot* next;
        Knot() {
            this->next = nullptr;
        }
        Knot(int _data) {
            this->data = _data;
            this->next = nullptr;
        }
};

class LinkedList {
    private:
        Knot* primeiro;
        Knot* ultimo;
        int size;
    public:
        LinkedList() {
            this->ultimo = new Knot();
            this->size = 0;
        }
        ~LinkedList() {
            this->clear();
        }
        // Insere o elemento na última posição
        bool push_back(int e) {
            Knot* temp = new Knot(e);
            this->ultimo->next = temp;
            if (this->ultimo->next != temp) return false;
            if (this->size == 0) {
                delete this->ultimo;
                this->ultimo = temp;
                this->primeiro = this->ultimo;
            } else {
                this->ultimo = temp;
            }
            this->size++;
            if (this->ultimo != temp) return false;
            return true;
        }
        // Insere o elemento na primeira posição
        bool push_front(int e) {
            Knot* temp = new Knot(e);
            temp->next = this->primeiro;
            if (temp->next != this->primeiro) return false;
            this->primeiro = temp;
            if (this->primeiro != temp) return false;
            if (this->size == 0) {
                delete this->ultimo;
                this->ultimo = this->primeiro;
            }
            this->size++;
            return true;
        }
        // Insere o elemento na posição pos
        bool insert (int pos, int e) {
            if (pos >= this->size) return false;
            Knot* temp1 = new Knot(e);
            Knot* temp2 = this->primeiro;
            Knot* temp3;
            for (int i = 0; i < pos-1; i++) {
                temp2 = temp2->next;
            }
            temp3 = temp2->next;
            temp2->next = temp1;
            temp1->next = temp3;
            this->size++;
            return true;
        }
        // Remove o último elemento
        int pop_back() {
            if (this->size == 0) return 0;
            Knot* temp = this->primeiro;
            for (int i = 0; i < size-2; i++) {
                temp = temp->next;
            }
            temp->next = nullptr;
            this->size--;
            int aux = this->ultimo->data;
            delete this->ultimo;
            this->ultimo = temp;
            return aux;
        }
        // Remove o primeiro elemento
        int pop_front() {
            if (this->size == 0) return 0;
            Knot* temp = this->primeiro;
            if (this->size != 1) {
                this->primeiro = this->primeiro->next;
            } else {
                this->ultimo = new Knot();
                this->primeiro = nullptr;
            }
            int aux = temp->data;
            this->size--;
            delete temp;
            return aux;
        }
        // Remove o elemento da posição pos e retorna o elemento removido
        int erase(int pos) {
            if (pos >= size) return 0;
            if (pos == 0) return pop_front(); 
            if (pos == size) return pop_back();
            Knot* temp1 = this->primeiro;
            Knot* temp2;
            for (int i = 0; i < pos-2; i++) {
                temp1 = temp1->next;
            }
            temp2 = temp1->next->next;
            int aux = temp1->next->data;
            delete temp1->next;
            temp1->next = temp2;
            this->size--;
            return aux;
        }
        // Retorna o primeiro elemento
        int front() {
            return this->primeiro->data;
        };
        // Retorna o último elemento
        int back() {
            return this->ultimo->data;
        };
        // Retorna o elemento da posição pos
        int at(int pos) {
            if (pos >= size) return 0;
            Knot* temp = this->primeiro;
            for (int i = 0; i < pos-1; i++) {
                temp = temp->next;
            }
            return temp->data;
        };

        // Torna a lista vazia
        void clear() {
            Knot* temp1 = this->primeiro;
            Knot* temp2;
            if (this->size == 1) {
                delete this->primeiro;
            } 
            for (int i = 0; i < this->size; i++) {
                temp2 = temp1->next;
                delete temp1;
                temp1 = temp2;
            }
            this->size = 0;
            this->ultimo = new Knot();
            this->primeiro = nullptr;
        };

        // Verifica se o vetor está vazio
        bool empty() {
            if (this->size != 0) return 1; else return 0;
        };
        // Devolve a quantidade de elementos
        int getSize() {
            return this->size;
        };
        // Substitui o elemento da posição pos pelo elemento e
        bool replace(int pos, int e) {
            if (pos >= size) return false;
        };
        // Imprime todos os elementos no formato [1,2,3]
        void print() {
            if (this->size == 0) {
                cout << "[]" << endl;
            } else {
                cout << "[";
                Knot* temp = this->primeiro;
                for (int i = 0; i < size; i++) {
                    cout << temp->data << ",";
                    temp = temp->next;
                }
                cout <<"\b]" << endl;
            }
        }
};

int main() {
    LinkedList* v = new LinkedList();
    v->push_back(1);
    v->push_back(2);
    v->push_back(3);
    v->push_back(4);
    v->push_back(5);
    v->push_back(6);
    v->push_back(7);
    v->push_back(8);
    v->push_back(9);
    v->push_back(10);
    v->print();
    v->push_front(-2);
    v->push_front(-1);
    v->print();
    v->pop_back();
    v->pop_front();
    v->pop_back();
    v->pop_front();
    v->print();
    v->pop_back();
    v->pop_front();
    v->pop_front();
    v->print();
    v->erase(5);
    v->erase(0);
    v->print();
    v->clear();
    v->print();
    v->push_back(8);
    v->push_back(9);
    v->push_back(10);
    v->print();
    v->push_front(-2);
    v->push_front(-1);
    v->print();
}