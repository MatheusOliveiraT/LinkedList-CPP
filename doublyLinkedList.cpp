#include <iostream>

using namespace std;

class Knot {
    public:
        Knot* prev;
        int data;
        Knot* next;
        Knot(int _data) {
            this->prev = nullptr;
            this->next = nullptr;
            this->data = _data;
        }
};

class LinkedList {
    private:
        Knot* first;
        Knot* last;
        int size;
    public:
        LinkedList() {
            this->first = nullptr;
            this->last = nullptr;
            this->size = 0;
        }
        ~LinkedList() {
            this->clear();
        }
        // Insere o elemento na última posição
        bool pushBack(int e) {
            Knot* aux = new Knot(e);
            if (this->empty()) {
                this->first = aux;
            } else {
                aux->prev = this->last;
                this->last->next = aux;
            }
            this->last = aux;
            this->size++;
            return true;
        }

        // Insere o elemento na primeira posição
        bool pushFront(int e) {
            Knot* aux = new Knot(e);
            if (this->empty()) {
                this->last = aux;
            } else {
                aux->next = this->first;
                this->first->prev = aux;
            }
            this->first = aux;
            this->size++;
            return true;
        }

        // Insere o elemento na posição pos
        bool insert (int pos, int e) {
            if (pos < 0) return false;
            if (pos > this->size) return false;
            if (this->empty()) {
                return pushBack(e);
            } else if (pos == 0) {
                return pushFront(e);
            } else if (pos == this->size) {
                return pushBack(e);
            } else {
                Knot* knot = new Knot(e);
                Knot* aux;
                if (pos < size/2) {
                    aux = this->first;
                    for (int i = 0; i < pos-1; i++, aux = aux->next);
                } else {
                    aux = this->last;
                    for (int i = this->size; i > pos; i--, aux = aux->prev);
                }
                knot->prev = aux;
                knot->next = aux->next;
                aux->next->prev = knot;
                aux->next = knot;
                this->size++;
                return true;
            }
        }

        // Remove o último elemento
        int popBack() {
            if (this->empty()) return 0;
            int aux = this->last->data;
            if (this->size == 1) {
                delete this->last;
                this->first = nullptr;
                this->last = nullptr;
            } else { 
                Knot* aux = this->last;
                this->last = this->last->prev;
                this->last->next = nullptr;
                delete aux;
            }
            this->size--;
            return aux;
        }

        // Remove o primeiro elemento
        int popFront() {
            if (this->empty()) return 0;
            int aux = this->first->data;
            if (this->size == 1) {
                delete this->first;
                this->first = nullptr;
                this->last = nullptr;
            } else {
                Knot* aux = this->first;
                this->first = this->first->next;
                this->first->prev = nullptr;
                delete aux;
            }
            this->size--;
            return aux;
        }

        // Remove o elemento da posição pos e retorna o elemento removido
        int erase(int pos) {
            if (this->empty()) return 0;
            if (pos < 0) return 0;
            if (pos > this->size) return 0;
            if (pos == 0) {
                return popFront();
            } else if (pos == this->size) {
                return popBack();
            } else {
                int aux;
                Knot* kaux;
                if (pos < size/2) {
                    kaux = this->first;
                    for (int i = 0; i < pos; i++, kaux = kaux->next);
                } else {
                    kaux = this->last;
                    for (int i = this->size; i > pos; i--, kaux = kaux->prev);
                }
                Knot* kaux2 = kaux->next;
                kaux2->prev = kaux->prev;
                kaux->prev->next = kaux2;
                this->size--;
                delete kaux;
                return aux;
            }
        }

        // Retorna o primeiro elemento
        int front() { 
            if (!this->empty()) {
                return this->first->data; 
            } else return 0;
        }

        // Retorna o último elemento
        int back() { 
            if (!this->empty()) {
                return this->last->data; 
            } else return 0;
        }

        // Retorna o elemento da posição pos
        int at(int pos) {
            if (this->empty()) return 0;
            if (pos < 0) return 0;
            if (pos > this->size) return 0;
            Knot* aux;
            if (pos < size/2) {
                aux = this->first;
                for (int i = 0; i < pos; i++, aux = aux->next);
            } else {
                aux = this->last;
                for (int i = this->size; i > pos; i--, aux = aux->prev);
            }
            return aux->data;
        }

        // Torna a lista vazia
        void clear() {
            if (this->empty()) return;
            if (this->size == 1) {
                delete this->first;
            } else {
                Knot* aux1 = this->first;
                Knot* aux2 = this->first->next;
                for (int i = 0; i < this->size; i++) {
                    delete aux1;
                    aux1 = aux2;
                    if (aux2->next != nullptr) aux2 = aux2->next;
                }
            }
            this->first = nullptr;
            this->last = nullptr;
            this->size = 0;
        }

        // Verifica se o vetor está vazio
        bool empty() { return (this->size == 0); }

        // Devolve a quantidade de elementos
        int getSize() { return this->size; }

        // Substitui o elemento da posição pos pelo elemento e
        bool replace(int pos, int e) {
            if (this->empty()) return false;
            if (pos < 0) return false;
            if (pos > this->size) return false;
            Knot* aux;
            if (pos < size/2) {
                aux = this->first;
                for (int i = 0; i < pos; i++, aux = aux->next);
            } else {
                aux = this->last;
                for (int i = this->size; i > pos; i--, aux = aux->prev);
            }
            aux->data = e;
            return true;
        }

        // Imprime todos os elementos no formato [1,2,3]
        void print() {
            cout << "[";
            for (Knot* aux = this->first; aux != nullptr; aux = aux->next) {
                cout << aux->data;
                if (aux->next != nullptr) cout << ",";
            }
            cout << "]" << endl;
        }
};