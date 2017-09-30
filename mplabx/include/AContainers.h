/*******************************************************************************
*   @author:    Milazzo Giuseppe
*               Università KORE Enna
*   @e-mail:    milazzo.ga@gmail.com
*               info@antipode-dev.org
*******************************************************************************
*   Software Licence:
*******************************************************************************
*
*   This file is part of AFramework.
*
*   AFramework is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   AFramework is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with AFramework. If not, see <http://www.gnu.org/licenses/>.
*
*   Copyright 2015, 2016 Milazzo Giuseppe
*
*/

#ifndef ACONTAINERS_H
#define ACONTAINERS_H

#include "ACore.h"
#include "AErrorNotifier.h"

namespace AFramework{

    template <class T> class AAbstractList;
    template <class T> class ALinkedList;
    template <class T> class AList;

    template <class T> AAbstractList<T> & operator<<(AAbstractList<T> & list, const T & item);

    template <class T> class AAbstractList : public AErrorNotifier{
        public:
            AAbstractList();
            virtual ~AAbstractList();
            virtual void indexClear() const = 0;
            virtual uint32 removeAll(const T & item) = 0;
            virtual bool contains(const T & item) const = 0;
            virtual bool replace(const T & item, const uint32 & index) const = 0;
            virtual bool hasNext() const = 0;
            virtual bool insert(const T & item, const uint32 & index) = 0;
            virtual bool remove(const uint32 & index) = 0;
            virtual bool clear() = 0;
            virtual T next() const = 0;
            virtual T at(const uint32 & index) const = 0;
            bool isEmpty() const;
            bool prepend(const T & item);
            bool append(const T & item);
            uint32 size() const;
            bool operator&&(const T & item) const;
            T operator[](const uint32 & index) const;
        protected:
            uint32 m_size;
            mutable bool m_flag;
        private:
            AAbstractList(const AAbstractList<T> & list);
    };

    template <class T> class AList : public AAbstractList<T>{
        public:
            AList();
            ~AList();
            void indexClear() const;
            uint32 removeAll(const T & item);
            bool contains(const T & item) const;
            bool compare(const AList<T> & list) const;
            bool replace(const T & item, const uint32 & index) const;
            bool hasNext() const;
            bool insert(const T & item, const uint32 & index);
            bool remove(const uint32 & index);
            AList<T> * clone() const;
            bool clear();
            T next() const;
            T at(const uint32 & index) const;
            bool operator==(const AList<T> & list) const;
            bool operator!=(const AList<T> & list) const;
        private:
            void ptrswp(T * ptr, const uint32 & dim);
            AList(const AList<T> & list);
            T * m_list;
            mutable uint32 m_temp;
    };

    template <class T> class ALinkedList : public AAbstractList<T>{
        public:
            ALinkedList();
            ~ALinkedList();
            void indexClear() const;
            uint32 removeAll(const T & item);
            bool contains(const T & item) const;
            bool compare(const ALinkedList<T> & list) const;
            bool replace(const T & item, const uint32 & index) const;
            bool hasNext() const;
            bool insert(const T & item, const uint32 & index);
            bool remove(const uint32 & index);
            ALinkedList<T> * clone() const;
            bool clear();
            T next() const;
            T at(const uint32 & index) const;
            bool operator==(const ALinkedList<T> & list) const;
            bool operator!=(const ALinkedList<T> & list) const;
        private:
            template <class K> struct ANode{
                                    ANode<K> * m_prev;
                                    ANode<K> * m_next;
                                    K m_item;
                                };
            ALinkedList(const ALinkedList<T> & list);
            void seek (const uint32 & index, ANode<T> ** cur) const;
            ANode<T> * m_head;
            ANode<T> * m_tail;
            mutable ANode<T> * m_temp;
    };

    template <class T> AAbstractList<T>::AAbstractList() : AErrorNotifier(), m_size(0), m_flag(false){
        /*  Nulla da commentare                                                 */
    }

    template <class T> AAbstractList<T>::AAbstractList(const AAbstractList<T>& list){
        /*  Non fa assolutamente nulla e non può essere chiamato (pena possi-   */
        /*  bile eccezione e quindi blocco della CPU)                           */
    }

    template <class T> AAbstractList<T>::~AAbstractList(){

    }

    template <class T> bool AAbstractList<T>::isEmpty() const{
        /*  Nulla da commentare                                                 */
        return m_size == 0;
    }

    template <class T> bool AAbstractList<T>::prepend(const T & item){
        /*  Nulla da commentare                                                 */
        return insert(item, 0);
    }

    template <class T> bool AAbstractList<T>::append(const T & item){
        /*  Nulla da commentare                                                 */
        return insert(item, m_size);
    }

    template <class T> uint32 AAbstractList<T>::size() const{
        /*  Nulla da commentare                                                 */
        return m_size;
    }

    template <class T> bool AAbstractList<T>::operator&&(const T & item) const{
        /*  Nulla da commentare                                                 */
        return contains(item);
    }

    template <class T> T AAbstractList<T>::operator[](const uint32 & index) const{
        /*  Nulla da commentare                                                 */
        return at(index);
    }

    template <class T> AList<T>::AList() : AAbstractList<T>(), m_list(NULL), m_temp(0){
        /*  Nulla da commentare                                                 */
    }

    template <class T> AList<T>::AList(const AList<T> & list){
        /*  Non fa assolutamente nulla e non può essere chiamato (pena possi-   */
        /*  bile eccezione e quindi blocco della CPU)                           */
    }

    template <class T> AList<T>::~AList(){
        /*  nulla da commentare                                                 */
        clear();
    }

    template <class T> void AList<T>::indexClear() const{
        /*  Resetto il flag per hasNext                                         */
        this->m_flag = false;
        /*  e resetto l'indice                                                  */
        m_temp = 0;
    }

    template <class T> uint32 AList<T>::removeAll(const T & item){
        uint32 occNum = 0;
        uint32 tmpInd = 0;
        T *    newLst = NULL;
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  come prima cosa scorro la lista                                     */
        for(uint32 i = 0; i < this->m_size; i++){
            /*  se l'i-esimo elemento è uguale al parametro                     */
            if(m_list[i] == item){
            /*  incremento le occorrenze                                        */
                occNum++;
            }
        }
        /*  se il numero di occorrenze è non nullo                              */
        if(occNum){
            /*  provo ad allocare il nuovo vettore                              */
            if(System::safeAlloc(&newLst, this->m_size - occNum)){
                /*  se l'allocazione riesce inizio a scorrere il vettore        */
                for(uint32 i = 0; i < this->m_size; i++){
                    /*  se l'i-esimo elemento è diverso dal parametro           */
                    if(m_list[i] != item){
                        /*  lo copio incrementando l'indice                     */
                        newLst[tmpInd++] = m_list[i];
                    }
                }
                /*  scambio i puntatori                                         */
                ptrswp(newLst, this->size - occNum);
            }else{
                /*  setto la variabile d'errore                                 */
                this->errset(AAbstractErrorNotifier::NoMemory);
            }
        }
        /*  ritorno il numero di occorrenze eliminate                           */
        return occNum;
    }

    template <class T> bool AList<T>::contains(const T& item) const{
        /*  Scorro la lista                                                     */
        for(uint32 i = 0; i < this->m_size; i++){
            /*  alla prima corrispondenza                                       */
            if(m_list[i] == item){
                /*  ritorno true                                                */
                return true;
            }
        }
        /*  se non ho trovato corrispondenze ritorno false                      */
        return false;
    }

    template <class T> bool AList<T>::compare(const AList<T>& list) const{
        /*  se hanno dimensione diversa sono ovviamente diverse                 */
        if(this->m_size != list.m_size){
            /*  per cui ritorno false                                           */
            return false;
        }
        /*  altrimenti confronto elemento per elemento                          */
        for(uint32 i = 0; i < this->m_size; i++){
            /*  al primo elemento diverso                                       */
            if(m_list[i] != list.m_list[i]){
                /*  restituisco false                                           */
                return false;
            }
        }
        /*  se siamo arrivati qui vuol dire che le liste sono identiche         */
        return true;
    }

    template <class T> bool AList<T>::replace(const T& item, const uint32& index) const{
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  se l'indice passato è maggiore o uguale alla dimensione della lista */
        if(index >= this->m_size){
            /*  imposto l'errore                                                */
            this->errset(AAbstractErrorNotifier::OutOfRange);
            /*  restituisco false                                               */
            return false;
        }
        /*  altrimenti faccio la sostituzione                                   */
        m_list[index] = item;
        /*  e ritorno true                                                      */
        return true;
    }

    template <class T> bool AList<T>::hasNext() const{
        /*  se sto iniziando un nuovo while                                     */
        if(!this->m_flag){
            /*  imposto il falg a true                                          */
            this->m_flag = true;
            /*  azzero l'indice temporaneo                                      */
            m_temp = 0;
        /*  altrimenti se sono nelle interazioni                                */
        }else{
            /*  incremento l'indice                                             */
            m_temp++;
        }
        /*  se ho finito gli elementi                                           */
        if(m_temp == this->m_size){
            /*  azzero gli indici                                               */
            indexClear();
            /*  e ritorno false                                                 */
            return false;
        }
        /*  altrimenti ritorno true                                             */
        return true;
    }

    template <class T> bool AList<T>::insert(const T& item, const uint32& index){
        T *    newLst = NULL;
        uint32 tmpInd = 0;
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  se l'indice passato è più grande della dimensione della lista       */
        if(index > this->m_size){
            /*  setto la variabile d'errore                                     */
            this->errset(AAbstractErrorNotifier::OutOfRange);
            /*  ritorno false                                                   */
            return false;
        }
        /*  provo ad allocare un nuovo vettore                                  */
        if(System::safeAlloc(&newLst, this->m_size + 1)){
            /*  se l'allocazione è andata a buon fine inizio l'inserimento      */
            for(uint32 i = 0; i < this->m_size + 1; i++){
                /*  se sono arrivato al punto giusto                            */
                if(i == index){
                    /*  inserisco l'elemento                                    */
                    newLst[i] = item;
                }else{
                    /*  altrimenti inserisco l'elemento della vecchia lista     */
                    newLst[i] = m_list[tmpInd++];
                }
            }
            /*  scambio i puntatori                                             */
            ptrswp(newLst, this->m_size + 1);
            /*  e ritorno true                                                  */
            return true;
        }
        /*  in questo caso la memoria è finita per cui setto l'errore           */
        this->errset(AAbstractErrorNotifier::NoMemory);
        /*  e ritorno false                                                     */
        return false;
    }

    template <class T> bool AList<T>::remove(const uint32& index){
        T *    newLst = NULL;
        uint32 tmpInd = 0;
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  se l'indice è maggiore o uguale alla dimensione della lista         */
        if(index >= this->m_size){
            /*  setto la variabile d'errore                                     */
            this->errset(AAbstractErrorNotifier::OutOfRange);
            /*  ritorno false                                                   */
            return false;
        }
        /*  provo ad allocare un nuovo vettore                                  */
        if(System::safeAlloc(&newLst, this->m_size - 1)){
            /*  se l'allocazione è andata a buon fine inizio l'inserimento      */
            for(uint32 i = 0; i < this->m_size; i++){
                /*  se l'indice corrente è diverso da quello che devo eliminare */
                if(i != index){
                    /*  effettuo la copia                                       */
                    newLst[tmpInd++] = m_list[i];
                }
            }
            /*  scambio i puntatori                                             */
            ptrswp(newLst, this->m_size - 1);
            /*  e ritorno true                                                  */
            return true;
        }
        /*  se non c'è memoria setto la variabile d'errore                      */
        this->errset(AAbstractErrorNotifier::NoMemory);
        /*  e ritorno false                                                     */
        return false;
    }

    template <class T> AList<T> * AList<T>::clone() const{
        AList<T> * m_new = NULL;
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  provo ad allocare la lista clone                                    */
        if(System::safeAlloc(&m_new)){
        /*  se l'allocazione è andata a buon fine controllo se la lista non è   */
        /*  vuota */
            if(this->m_size){
                /*  provo ad allocare il nuovo vettore                          */
                if(System::safeAlloc(&(m_new->m_list), this->m_size)){
                    /*  se l'allocazione è andata a buon fine effettuo la copia */
                    for(uint32 i = 0; i < this->m_size; i++){
                        m_new->m_list[i] = m_list[i];
                    }
                    /*  setto la dimensione                                     */
                    m_new->m_size = this->m_size;
                }else{
                    /*  Altrimenti setto la variabile d'errore                  */
                    this->errset(AAbstractErrorNotifier::NoMemory);
                    /*  faccio rollback cancellando la lista                    */
                    delete m_new;
                    /*  e metto a NULL                                          */
                    m_new = NULL;
                }
            }
        }else{
            this->errset(AAbstractErrorNotifier::NoMemory);
        }
        /*  ritorno il puntatore alla lista                                     */
        return m_new;
    }

    template <class T> bool AList<T>::clear(){
        /*  se la lista è già vuota                                             */
        if(!this->m_size){
            /*  ritorno false                                                   */
            return false;
        }
        /*  altrimenti cancello tutto, metto a null                             */
        ptrswp(NULL, 0);
        /*  e ritorno true                                                      */
        return true;
    }

    template <class T> T AList<T>::next() const{
        /*  nulla da commentare                                                 */
        return at(m_temp);
    }

    template <class T> T AList<T>::at(const uint32& index) const{
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  se l'indice è non valido                                            */
        if(index >= this->m_size){
            /*  setto la variabile d'errore                                     */
            this->errset(AAbstractErrorNotifier::OutOfRange);
            /*  e per evitare errori strani, ritorno un oggetto al volo         */
            return T();
        }
        /*  altrimenti ritorno l'oggetto corretto                               */
        return m_list[index];
    }

    template <class T> bool AList<T>::operator==(const AList<T>& list) const{
        /*  nulla da commentare                                                 */
        return compare(list);
    }

    template <class T> bool AList<T>::operator!=(const AList<T>& list) const{
        /*  nulla da commentare                                                 */
        return !compare(list);
    }

    template <class T> void AList<T>::ptrswp(T * ptr, const uint32 & dim){
        /*  libero la memoria                                                   */
        delete [] m_list;
        /*  riassegno il puntatore                                              */
        m_list = ptr;
        /*  aggiorno la dimensione                                              */
        this->m_size = dim;
    }

    template <class T> ALinkedList<T>::ALinkedList() : AAbstractList<T>(), m_head(NULL), m_tail(NULL), m_temp(NULL){
        /*  Nulla da commentare                                                 */
    }

    template <class T> ALinkedList<T>::ALinkedList(const ALinkedList<T>& list){
        /*  Non fa assolutamente nulla e non può essere chiamato (pena possi-   */
        /*  bile eccezione e quindi blocco della CPU)                           */
    }

    template <class T> ALinkedList<T>::~ALinkedList(){
        /*  Nulla da commentare                                                 */
        clear();
    }

    template <class T> void ALinkedList<T>::indexClear() const{
        /*  metto a false il flag                                               */
        this->m_flag = false;
        /*  metto a NULL il puntatore                                           */
        m_temp = NULL;
    }

    template <class T> uint32 ALinkedList<T>::removeAll(const T& item){
        uint32     occNum = 0;
        ANode<T> * navPtr = NULL;
        ANode<T> * tmpPtr = NULL;
        /*  assegno la testa al puntatore di navigazione                        */
        navPtr = m_head;
        /*  inizio a scorrere                                                   */
        while(navPtr){
            /*  se l'item coincide                                              */
            if(navPtr->m_item == item){
                /*  incremento le occorrenze                                    */
                occNum++;
                /*  punto il nodo da eliminare                                  */
                tmpPtr = navPtr;
                /*  se sono in testa ed in coda (la lista ha un solo elemento)  */
                if(!tmpPtr->m_prev && !tmpPtr->m_next){
                    /*  imposto testa e coda a NULL                             */
                    m_head = m_tail = NULL;
                /*  altrimenti se sono in testa                                 */
                }else if(!tmpPtr->m_prev){
                    /*  sposto in avanti la testa                               */
                    m_head = navPtr->m_next;
                    /*  rimuovo la connessione con il precedente                */
                    m_head->m_prev = NULL;
                /*  altrimenti se sono in coda                                  */
                }else if(!tmpPtr->m_next){
                    /*  sposto indietro la coda                                 */
                    m_tail = navPtr->m_prev;
                    /*  rimuovo la connessione con il successivo                */
                    m_tail->m_next = NULL;
                /*  altrimenti per qualsiasi altra posizione                    */
                }else{
                    /*  collego il successivo al precedente                     */
                    navPtr->m_next->m_prev = tmpPtr->m_prev;
                    /*  collego il precedente al successivo                     */
                    navPtr->m_prev->m_next = tmpPtr->m_next;
                }
            }
            /*  sposto il puntatore di navigazione avanti                       */
            navPtr = navPtr->m_next;
            /*  libero la memoria (tanto delete non lancia nulla)               */
            delete tmpPtr;
            /*  assegno tmpPtr a NULL (evito double free)                       */
            tmpPtr = NULL;
        }
        /*  aggiorno la dimensione                                              */
        this->m_size -= occNum;
        /*  ritorno il numero di elementi eliminati                             */
        return occNum;
    }

    template <class T> bool ALinkedList<T>::contains(const T& item) const{
        ANode<T> * navPtr = m_head;
        /*  inizio a scorrere la lista                                          */
        while(navPtr){
            /*  se trovo una corrispondenza                                     */
            if(navPtr->m_item == item){
            /*  ritorno true                                                    */
            return true;
            }
            /*  sposto il puntatore di navigazione al nodo successivo           */
            navPtr = navPtr->m_next;
        }
        /*  altrimenti se sono qua vuol dire che non ho trovato corrispondenze  */
        /*  per cui ritorno false                                               */
        return false;
    }

    template <class T> bool ALinkedList<T>::compare(const ALinkedList<T>& list) const{
        ANode<T> * navPtr1 = NULL;
        ANode<T> * navPtr2 = NULL;
        /*  se le dimensioni sono diverse                                       */
        if(this->m_size != list.m_size){
            /*  le liste sono ovviamente diverse per cui ritorno false          */
            return false;
        }
        /*  assegno al puntatore di navigazione navPtr1 la testa della lista    */
        navPtr1 = m_head;
        /*  assegno al puntatore di navigazione navPtr2 la testa dell'altra     */
        navPtr2 = list.m_head;
        /*  inizio a scorrere                                                   */
        while(navPtr1){
            /*  al primo elemento diverso                                       */
            if(navPtr1->m_item != navPtr2->m_item){
                /*  ritorno false                                               */
                return false;
            }
            /*  sposto il puntatore di navigazione di questa lista              */
            navPtr1 = navPtr1->m_next;
            /*  e dell'altra                                                    */
            navPtr2 = navPtr2->m_next;
        }
        /*  ritorno true                                                        */
        return true;
    }

    template <class T> bool ALinkedList<T>::replace(const T& item, const uint32& index) const{
        ANode<T> * navPtr = NULL;
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  controllo che l'indice sia valido                                   */
        if(index >= this->m_size){
            /*  se non è così setto la variabile d'errore                       */
            this->errset(AAbstractErrorNotifier::OutOfRange);
            /*  e ritorno false                                                 */
            return false;
        }
        /*  mi posiziono                                                        */
        seek(index, &navPtr);
        /*  sostituisco l'item                                                  */
        navPtr->m_item = item;
        /*  e ritorno true                                                      */
        return true;
    }

    template <class T> bool ALinkedList<T>::hasNext() const{
        /*  se sto iniziando un nuovo while                                     */
        if(!this->m_flag){
            /*  resetto il puntatore                                            */
            m_temp = m_head;
            /*  e metto a true il flag                                          */
            this->m_flag = true;
        /*  altrimenti, se sono già dentro un while                             */
        }else{
            /*  sposto il puntatore                                             */
            m_temp = m_temp->m_next;
        }
        /*  se il puntatore è NULL                                              */
        if(!m_temp){
            /*  resetto il flag per un nuovo while                              */
            indexClear();
            /*  e ritorno false                                                 */
            return false;
        }
        /*  ritorno true                                                        */
        return true;
    }

    template <class T> bool ALinkedList<T>::insert(const T& item, const uint32& index){
        ANode<T> * curPtr = NULL;
        ANode<T> * newPtr = NULL;
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  controllo che l'indice sia valido                                   */
        if(index > this->m_size){
            /*  se non è così imposto la variabile d'errore                     */
            this->errset(AAbstractErrorNotifier::OutOfRange);
            /*  e ritorno false                                                 */
            return false;
        }
        /*  provo ad allocare un nodo                                           */
        if(System::safeAlloc(&newPtr)){
            /*  se l'allocazione è andata a buon fine imposto l'item del nuovo  */
            /*  nodo lasciando i puntatori prev e next per come mi vengono dati */
            /*  da new (sono già a NULL grazie alla chiamata interna a memset)  */
            newPtr->m_item = item;
            /*  se la lista è vuota (solo nel caso in cui index sia zero e con- */
            /*  temporaneamente la lista è vuota)                               */
            if(!this->m_size){
                /*  assegno i puntatori ed ho finito                            */
                m_head = m_tail = newPtr;
            /*  altrimenti se la lista non è vuota ma l'indice è sempre zero    */
            /*  (operazione di prepend)                                         */
            }else if(!index){
                /*  collego la testa al successivo del nuovo nodo               */
                newPtr->m_next = m_head;
                /*  collego il precedente della testa al nuovo nodo             */
                m_head->m_prev = newPtr;
                /*  sposto indietro la testa                                    */
                m_head = newPtr;
            /*  altrimenti se la lista non è vuota è l'indice è pari alla di-   */
            /*  mensione della lista (operazione di append)                     */
            }else if(index == this->m_size){
                /*  collego la coda al precedente del nuovo nodo                */
                newPtr->m_prev = m_tail;
                /*  collego il successivo della coda al nuovo nodo              */
                m_tail->m_next = newPtr;
                /*  sposto in avanti la coda                                    */
                m_tail = newPtr;
            /*  altrimenti per tutti gli altri indici intermedi                 */
            }else{
                /*  mi posiziono correttamente                                  */
                seek(index, &curPtr);
                /*  collego il precedente del nuovo nodo al precedente del nodo */
                /*  corrente                                                    */
                newPtr->m_prev = curPtr->m_prev;
                /*  collego il successivo del nuovo nodo al nodo corrente       */
                newPtr->m_next = curPtr;
                /*  collego il successivo del nodo precedente al nodo corrente  */
                /*  al nuovo nodo                                               */
                curPtr->m_prev->m_next = newPtr;
                /*  collego il precedente del nodo corrente al nuovo nodo       */
                curPtr->m_prev = newPtr;
            }
            /*  incremento la dimensione                                        */
            this->m_size++;
            /*  ritorno true                                                    */
            return true;
        }
        /*  se non sono riuscito ad allocare imposto la variabile d'errore      */
        this->errset(AAbstractErrorNotifier::NoMemory);
        /*  e ritorno false                                                     */
        return false;
    }

    template <class T> bool ALinkedList<T>::remove(const uint32& index){
        ANode<T> * curPtr = NULL;
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  controllo che l'indice passato sia un indice valido                 */
        if(index >= this->m_size){
            /*  se non è così imposto la variabile d'errore                     */
            this->errset(AAbstractErrorNotifier::OutOfRange);
            /*  e ritorno false                                                 */
            return false;
        }
        /*  se c'è un solo elemento                                             */
        if(this->m_size == 1){
            /*  elimino la testa                                                */
            delete m_head;
            /*  faccio puntare a NULL la testa                                  */
            m_head = NULL;
            /*  e la coda                                                       */
            m_tail = NULL;
        /*  se devo eliminare la testa                                          */
        }else if(!index){
            /*  assegno la testa al nodo corrente                               */
            curPtr = m_head;
            /*  sposto in avanti la testa                                       */
            m_head = m_head->m_next;
            /*  metto a NULL il puntatore precedente (unlink)                   */
            m_head->m_prev = NULL;
        /* se devo eliminare la coda                                            */
        }else if(index == this->m_size - 1){
            /*  assegno la coda al nodo corrente                                */
            curPtr = m_tail;
            /*  sposto indietro la coda                                         */
            m_tail = m_tail->m_prev;
            /*  metto a NULL il puntatore successivo (unlink)                   */
            m_tail->m_next = NULL;
        /*  se l'indice è intermedio                                            */
        }else{
            /*  posiziono i puntatori                                           */
            seek(index, &curPtr);
            /*  assegno il puntatore successivo                                 */
            curPtr->m_prev->m_next = curPtr->m_next;
            /*  collego il successivo del precedente al successivo              */
            curPtr->m_next->m_prev = curPtr->m_prev;
        }
        /*  cancello il nodo                                                    */
        delete curPtr;
        /*  decremento la dimensione                                            */
        this->m_size--;
        /*  ritorno true                                                        */
        return true;
    }

    template <class T> ALinkedList<T> * ALinkedList<T>::clone() const{
        ANode<T>        * navPtr = NULL;
        ALinkedList<T>  * newLst = NULL;
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  provo ad allocare la nuova lista                                    */
        if(System::safeAlloc(&newLst)){
            /*  se la lista è stata correttamente allocata assegno il puntatore */
            /*  di navigazione la testa della lista                             */
            navPtr = m_head;
            /*  inizio a scorrere la lista                                      */
            while(navPtr){
                /*  se riesco ad inserire i nodi                                */
                if(newLst->append(navPtr->m_item)){
                    /*  sposto il puntatore di navigazione                      */
                    navPtr = navPtr->m_next;
                /*  altrimenti                                                  */
                }else{
                    /*  imposto l'errore e faccio rollback                      */
                    this->errset(AAbstractErrorNotifier::NoMemory);
                    /*  cancellando gli elementi che fino ad ora sono riuscito  */
                    /*  a clonare                                               */
                    newLst->clear();
                    /*  liberando la memoria occupata dalla nuova lista         */
                    delete newLst;
                    /*  mettendo il puntatore a NULL                            */
                    newLst = NULL;
                    /*  ed ovviamente smetto di scorrere                        */
                    break;
                }
            }
        }else{
            /*  se l'allocazione non è andata a buon fine imposto l'errore      */
            this->errset(AAbstractErrorNotifier::NoMemory);
        }
        /*  alla fine ritorno la lista (che può anche essere NULL)              */
        return newLst;
    }

    template <class T> bool ALinkedList<T>::clear(){
        ANode<T> * navPtr = NULL;
        /*  se la lista è già vuota                                             */
        if(!this->m_size){
            /*  ritorno false                                                   */
            return false;
        }
        /*  altrimenti assegno la testa a navPtr                                 */
        navPtr = m_head;
        /*  ed inizio a scorre                                                  */
        while(navPtr){
            /*  sponstando prima il puntatore alla testa                        */
            m_head = m_head->m_next;
            /*  eliminando ogni nodo                                            */
            delete navPtr;
            /*  e spostando in puntatore di navigazione                         */
            navPtr = m_head;
        }
        /*  faccio puntare a NULL la coda                                       */
        m_tail = NULL;
        /*  azzero la dimensione                                                */
        this->m_size = 0;
        /*  ritorno true                                                        */
        return true;
    }

    template <class T> T ALinkedList<T>::next() const{
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  se m_temp non è NULL                                                */
        if(m_temp){
            /*  ritorno l'item corretto                                         */
            return m_temp->m_item;
        }
        /*  altrimenti imposto l'errore                                         */
        this->errset(AAbstractErrorNotifier::OutOfRange);
        /*  e ritorno un item al volo                                           */
        return T();
    }

    template <class T> T ALinkedList<T>::at(const uint32& index) const{
        ANode<T> * curPtr = NULL;
        /*  resetto la variabile d'errore                                       */
        this->errset();
        /*  se l'indice non è valido                                            */
        if(index >= this->m_size){
            /*  imposto la variabile d'errore e                                 */
            this->errset(AAbstractErrorNotifier::OutOfRange);
            /*  per evitare errori strani, ritorno un oggetto al volo           */
            return T();
        }
        /*  se l'indice è fuori range lo imposto come l'ultimo e mi posiziono   */
        seek(index, &curPtr );
        /*  ritorno l'elemento                                                  */
        return curPtr->m_item;
    }

    template <class T> bool ALinkedList<T>::operator==(const ALinkedList<T>& list) const{
        /*  nulla da commentare                                                 */
        return compare(list);
    }

    template <class T> bool ALinkedList<T>::operator!=(const ALinkedList<T>& list) const{
        /*  nulla da commentare                                                 */
        return !compare(list);
    }

    template <class T> void ALinkedList<T>::seek(const uint32 & index, ANode<T> **cur) const{
        uint32 cnt = 0;
        uint32 jmp = 0;
        bool var = false;
        /*  stabilisco se conviene partire dalla testa o dalla coda             */
        var = (index <= (this->m_size - 1) / 2);
        /*  se conviene partire dalla testa assegno al puntatore di navigazione */
        /*  la testa, altrimenti la coda                                        */
        *cur = var ? m_head : m_tail;
        /*  riscalo il numero di salti in base a dove conviene partire          */
        jmp = var ? index : this->m_size - 1 - index;
        /*  scorro la lista                                                     */
        while(cnt < jmp){
            /*  muovendomi o avanti o indietro a seconda di dove sono partito   */
            *cur = var ? (*cur)->m_next : (*cur)->m_prev;
            /*  ed incrementando volta per volta il contatore                   */
            cnt++;
        }
    }

    template <class T> AAbstractList<T> & operator<<(AAbstractList<T> & list, const T & item){
        /*  accodo l'item                                                       */
        list.append(item);
        /*  ritorno il riferimento                                              */
        return list;
    }
}
#endif // ACONTAINERS_H
