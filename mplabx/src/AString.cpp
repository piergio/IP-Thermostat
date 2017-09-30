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

#include "AString.h"

const char * AFramework::endl = "\n";

AFramework::uint32 AFramework::AString::strlen(const char * val){
    uint32 res = 0;
    /*  se la stringa non è vuota                                               */
    if(val){
        /*  fino a che il carattere puntato è diverso da quello di terminazione */
        while(*val++){
            /*  incremento il contatore                                         */
            res++;
        }
    }
    /*  ritorno il risultato                                                    */
    return res;
}

AFramework::AString::AString() : AErrorNotifier(), m_str(NULL), m_dim(0) {
    /*  Nulla da commentare                                                     */
}

AFramework::AString::AString(const AString& str) : AString(str.m_str){
    /*  Nulla da commentare                                                     */
}

AFramework::AString::AString(const char * str) : AString(){
    uint32 dim = 1 + strlen(str);
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  se il puntatore non è null                                              */
    if(str){
        /*  provo ad allocare il vettore                                        */
        if(System::safeAlloc(&m_str, dim)){
            /*  copio i caratteri                                               */
            for(uint32 i = 0; i < dim; i++){
                m_str[i] = str[i];
            }
            /*  e setto la dimensione (decremento per coerenza, praticamente    */
            /*  strlen conta tutto tranne l'ultimo carattere per cui "pippo\0"  */
            /*  anche se come lunghezza fisica è 6 da come risultato 5 perchè   */
            /*  non conta \0)                                                   */
            m_dim = --dim;
        }else{
            errset(NoMemory);
        }
    }
}

AFramework::AString::AString(const sint32 & val) : AString(){
    /*  assegno il puntatore dato da numToASCII                                 */
    m_str = numToASCII(val, 0);
    /*  imposto la dimensione con strlen                                        */
    m_dim = strlen(m_str);
    /*  setto l'errore a NoError se la stringa non è null, altrimenti vuol dire */
    /*  che l'allocazione interna a numToASCII è fallita percui metto NoMemory  */
    errset(m_str ? NoError : NoMemory);
}

AFramework::AString::AString(const float & val, const uint8 & prec) : AString(){
    /*  assegno il puntatore dato da numToASCII                                 */
    m_str = numToASCII(val, prec);
    /*  imposto la dimensione con strlen                                        */
    m_dim = strlen(m_str);
    /*  setto l'errore a NoError se la stringa non è null, altrimenti vuol dire */
    /*  che l'allocazione interna a numToASCII è fallita percui metto NoMemory  */
    errset(m_str ? NoError : NoMemory);
}

AFramework::AString::AString(const double & val, const uint8 & prec) : AString(){
    /*  assegno il puntatore dato da numToASCII                                 */
    m_str = numToASCII(val, prec);
    /*  imposto la dimensione con strlen                                        */
    m_dim = strlen(m_str);
    /*  setto l'errore a NoError se la stringa non è null, altrimenti vuol dire */
    /*  che l'allocazione interna a numToASCII è fallita percui metto NoMemory  */
    errset(m_str ? NoError : NoMemory);
}

AFramework::AString::~AString(){
    /*  nulla da commentare                                                     */
    clear();
}

bool AFramework::AString::remove(const AString & str, const bool & cs){
    uint32 newDim = 0;
    uint32 tmpInd = 0;
    sint32 strInd = 0;
    char * newStr = NULL;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  calcolo la dimensione della nuova stringa                               */
    newDim = 1 + m_dim - str.m_dim;
    /*  cerco l'indice della sottostringa                                       */
    strInd = indexOf(str, 0, cs);
    /*  se non ho trovato la sottostringa da rimuovere                          */
    if(strInd < 0){
        /*  ritorno false                                                       */
        return false;
    }
    /*  provo ad allocare il nuovo vettore                                      */
    if(System::safeAlloc(&newStr, newDim)){
        /*  se ci sono riuscito inizio la copia                                 */
        for(uint32 i = 0; i < newDim - 1; i++){
            /*  quando il contatore è uguale all'indice della sottostringa      */
            if(i == strInd){
                /*  aggiungo l'offset per saltarla                              */
                tmpInd += str.m_dim;
            }
            /*  copio i caratteri                                               */
            newStr[i] = m_str[tmpInd++];
        }
        /*  inserisco la terminazione                                           */
        newStr[newDim - 1] = 0x00;
        /*  scambio i puntatori (al solido decrementando la dimensione di uno)  */
        ptrswp(newStr, --newDim);
        /*  ritorno true                                                        */
        return true;
    }
    /*  se l'allocazione fallisce setto l'errore a NoMemory e ritorno false     */
    errset(NoMemory);
    return false;
}

bool AFramework::AString::remove(const char & chr, const bool & cs){
    uint32 tmpInd = 0;
    sint32 chrInd = 0;
    char * newStr = NULL;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  cerco l'indice del carattere                                            */
    chrInd = indexOf(chr, 0, cs);
    /*  se non ho trovato il carattere da rimuovere                             */
    if(chrInd < 0){
        /*  ritorno false                                                       */
        return false;
    }
    /*  provo ad allocare il nuovo vettore                                      */
    if(System::safeAlloc(&newStr, m_dim)){
        /*  se ci sono riuscito inizio la copia                                 */
        for(uint32 i = 0; i < m_dim - 1; i++){
            /*  quando il contatore è uguale all'indice del carattere           */
            if(i == chrInd){
                /*  incremento l'indice temporaneo di uno così salto la copia   */
                tmpInd++;
            }
            /*  copio i caratteri                                               */
            newStr[i] = m_str[tmpInd++];
        }
        /*  aggiungo la terminazione                                            */
        newStr[m_dim - 1] = 0x00;
        /*  scambio i puntatori (al solito decrementando la dimensione di uno)  */
        ptrswp(newStr, --m_dim);
        /*  ritorno true                                                        */
        return true;
    }
    /*  se l'allocazione fallisce setto l'errore a NoMemory e ritorno false     */
    errset(NoMemory);
    return false;
}

bool AFramework::AString::contains(const AString & str, const bool & cs) const{
    /*  nulla da commentare                                                     */
    return (indexOf(str, 0, cs) != -1);
}

bool AFramework::AString::contains(const char & chr, const bool & cs) const{
    /*  nulla da commentare                                                     */
    return (indexOf(chr, 0, cs) != -1);
}

bool AFramework::AString::compare(const AString & str, const bool & cs) const{
    /*  se hanno dimensione diversa sono ovviamente diverse, per cui            */
    if(m_dim != str.m_dim){
        /*  ritorno false                                                       */
        return false;
    }
    /*  se hanno la stessa dimensione allora chiamo indexOf che deve dare zero  */
    /*  come risultato                                                          */
    return (indexOf(str, 0, cs) == 0);
}

bool AFramework::AString::compare(const char & chr, const bool & cs) const{
    /*  se la dimensione è diversa da 1 non possono mai essere confrontati      */
    /*  per cui                                                                 */
    if(m_dim != 1){
        /*  in questo caso ritorno false                                        */
        return false;
    }
    /*  altrimenti ritorno il confronto dei caratteri con ccmp                  */
    return ccmp(chr, m_str[0], cs);
}

bool AFramework::AString::replace(const AString & before, const AString & after, const bool & cs){
    uint32 tmpDim = 0;
    uint32 indOne = 0;
    uint32 indTwo = 0;
    sint32 strInd = 0;
    char * newStr = NULL;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  calcolo la dimensione della stringa dopo la dimensione di before        */
    tmpDim = 1 + m_dim - before.m_dim;
    /*  cerco l'indice della sottostringa before                                */
    strInd = indexOf(before, 0, cs);
    /*  se non ho trovato la sottostringa                                       */
    if(strInd < 0){
        /*  ritorno false                                                       */
        return false;
    }
    /*  provo ad allocare il nuovo vettore                                      */
    if(System::safeAlloc(&newStr, tmpDim + after.m_dim)){
        /*  se ci sono riuscito inizio la copia delle stringhe                  */
        for(uint32 i = 0; i < tmpDim + after.m_dim - 1; i++){
            /*  se il contatore è uguale all'indice di inizio di before aggiun- */
            /*  la dimensione di before così quando ricopio parto dai caratteri */
            /*  che seguono                                                     */
            if(i == strInd){
                indOne += before.m_dim + 1;
            }
            /*  se il contatore è minore dell'indice di inizio di before o mag- */
            /*  giore dello stesso indice più la dimensione di after            */
            if(i < strInd || i > strInd + after.m_dim){
                /*  ricopio i caratteri della vecchia stringa                   */
                newStr[i] = m_str[indOne++];
            /*  altrimenti                                                      */
            }else{
                /*  inserisco i caratteri di after                              */
                newStr[i] = after.m_str[indTwo++];
            }
        }
        /*  inserisco la terminazione                                           */
        newStr[tmpDim + after.m_dim - 1] = 0x00;
        /*  scambio i puntatori (al solito decrementando la dimensione di uno)  */
        ptrswp(newStr, tmpDim + after.m_dim);
        /*  ritorno true                                                        */
        return true;
    }
    /*  se l'allocazione fallisce setto l'errore a NoMemory e ritorno false     */
    errset(NoMemory);
    return false;
}

bool AFramework::AString::replace(const char & before, const char & after, const bool & cs){
    sint32 chrInd = indexOf(before, 0, cs);
    /*  se trovo il carattere                                                   */
    if(chrInd != -1){
        /*  lo sostituisco                                                      */
        m_str[chrInd] = after;
        /*  e ritorno true                                                      */
        return true;
    }
    /*  altrimenti false                                                        */
    return false;
}

AFramework::sint32 AFramework::AString::indexOf(const AString & str, const uint32 & index, const bool & cs) const{
    bool    flag = true;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  se la sottostringa passata è vuota oppure indice e/o dimensione non     */
    /*  premettono la ricerca                                                   */
    if(!str.m_dim || (index + str.m_dim > m_dim)){
        /*  setto l'errore ad OutOfRange                                        */
        errset(OutOfRange);
        /*  e ritorno -1                                                        */
        return -1;
    }
    /*  inizio a scorrere la stringa fino a quando posso fare l'ultimo confron- */
    /*  to                                                                      */
    for(uint32 i = index; i <= m_dim - str.m_dim; i++){
        /*  esamino in modo simmetrico                                          */
        for(uint32 j = 0; j <= str.m_dim / 2; j++){
            /*  alla prima differenza trovata                                   */
            if(!ccmp(str.m_str[j                ], m_str[i + j                ], cs) ||
               !ccmp(str.m_str[str.m_dim - 1 - j], m_str[str.m_dim - 1 + i - j], cs) ){
                /*  metto il flag a false                                       */
                flag = false;
                /*  e smetto di esaminare                                       */
                break;
            }
        }
        /*  se trovo il flag a false vuol dire che non ho trovato la sotto-     */
        /*  stringa, per cui                                                    */
        if(!flag){
            /*  lo rimetto a true, di modo che se non viene toccato significa   */
            /*  che la sottostringa è stata trovata                             */
            flag = true;
        /*  se invece trovo il flag a true implica che ho trovato la sotto-     */
        /*  stringa, per cui ritorno l'indice                                   */
        }else{
            return i;
        }
    }
    /*  se sono arrivato qui vuol dire che la sottostringa non è presente per   */
    /*  cui ritorno -1                                                          */
    return -1;
}

AFramework::sint32 AFramework::AString::indexOf(const char & chr, const uint32 & index, const bool & cs) const{
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  praticamente il problema non sussiste perchè se l'indice è fuori range  */
    /*  le iterazioni neanche partono, però per coerenza ritengo sia meglio     */
    /*  inserire il controllo                                                   */
    if(index > m_dim){
        /*  per cui come dicevo setto l'errore                                  */
        errset(OutOfRange);
        /*  e ritorno -1                                                        */
        return -1;
    }
    /*  inizio a scorrere la stringa dall'indice passato                        */
    for(uint32 i = index; i < m_dim; i++){
        /*  se trovo il carattere                                               */
        if(ccmp(chr, m_str[i], cs)){
            /*  ritorno l'indice corrispondete                                  */
            return i;
        }
    }
    /*  altrimenti -1                                                           */
    return -1;
}

AFramework::AString AFramework::AString::right(const uint32 index) const{
    AString str;
    char * newStr = NULL;
    uint32 newSize = m_dim - index + 1;
    uint32 tmpIndex = 0;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  se l'indice è fuori range                                               */
    if(index >= m_dim){
        /*  setto l'errore ad out of range                                      */
        errset(OutOfRange);
        /*  ritorno un oggetto al volo                                          */
        return str;
    }
    /*  provo ad allocare il nuovo vettore                                      */
    if(!System::safeAlloc(&newStr, newSize)){
      
        errset(NoMemory); 
    }
    
    for(uint32 i = index; i < m_dim; i++){
        
        newStr[tmpIndex++] = m_str[i];
    }
    
    newStr[newSize - 1] = 0x00;
    str.ptrswp(newStr, --newSize);
    return str;
}

AFramework::AString AFramework::AString::left(const uint32 index) const{
 
    AString str;
    char * newStr = NULL;
    uint32 newSize = index + 1;
    uint32 tmpIndex = 0;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  se l'indice è fuori range                                               */
    if(index >= m_dim){
        /*  setto l'errore ad out of range                                      */
        errset(OutOfRange);
        /*  ritorno un oggetto al volo                                          */
        return str;
    }
    /*  provo ad allocare il nuovo vettore                                      */
    if(!System::safeAlloc(&newStr, newSize)){
      
        errset(NoMemory); 
    }
    
    for(uint32 i = 0; i <= index; i++){
        
        newStr[tmpIndex++] = m_str[i];
    }
    
    newStr[newSize - 1] = 0x00;
    str.ptrswp(newStr, --newSize);
    return str;
}

bool AFramework::AString::insert(const AString & str, const uint32 & index){
    uint32  indOne = 0;
    uint32  indTwo = 0;
    uint32  newDim = 0;
    char * newStr = NULL;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  se l'indice passato è più grande della dimensione attuale               */
    if(index > m_dim){
        /*  setto l'errore ad OutOfRange                                        */
        errset(OutOfRange);
        /*  e ritorno false                                                     */
        return false;
    }
    /*  calcolo la dimensione del nuovo vettore                                 */
    newDim = 1 + m_dim + str.m_dim;
    /*  provo ad allocare il vettore                                            */
    if(System::safeAlloc(&newStr, newDim)){
        /*  se ci sono riuscito inizio la copia delle stringhe                  */
        for(uint32 i = 0; i < newDim - 1; i++){
            /*  se il contatore è compreso tra l'indice da dove inserire e lo   */
            /*  stesso indice più la dimensione della stringa da inserire       */
            if(i >= index && i <= index + str.m_dim - 1){
                /*  inserisco i caratteri della nuova sottostringa              */
                newStr[i] = str.m_str[indTwo++];
            }else{
                /*  altrimenti ricopio i vecchi caratteri                       */
                newStr[i] = m_str[indOne++];
            }
        }
        /*  inserisco la terminazione                                           */
        newStr[newDim - 1] = 0x00;
        /*  scambio i puntatori (decrementando la dimensione)                   */
        ptrswp(newStr, --newDim);
        /*  e ritorno true                                                      */
        return true;
    }
    /*  altrimenti setto l'errore                                               */
    errset(NoMemory);
    /*  e ritorno false                                                         */
    return false;
}

bool AFramework::AString::insert(const AString & str, const AString & after, const bool & cs){
    sint32 strInd = 0;
    /*  ricerco l'indice della sottostringa after                               */
    strInd = indexOf(after);
    /*  se non ho trovato la sottostringa                                       */
    if(strInd < 0){
        /*  ritorno false                                                       */
        return false;
    }
    /*  se invece l'ho trovata, chiamo la versione di insert con l'indice som-  */
    /*  mando a index la dimensione di after                                    */
    return insert(str, strInd + after.m_dim);
}

bool AFramework::AString::insert(const char & chr, const uint32 & index){
    uint32 newDim = 2 + m_dim;
    uint32 strInd = 0;
    char * newStr = NULL;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  se l'indice è fuori range                                               */
    if(index > m_dim){
        /*  imposto l'errore come OutOfRange                                    */
        errset(OutOfRange);
        /*  e ritorno false                                                     */
        return false;
    }
    /*  provo ad allocare il nuovo vettore                                      */
    if(System::safeAlloc(&newStr, newDim)){
        /*  se ci sono riuscito inizio la copia                                 */
        for(uint32 i = 0; i < newDim - 1; i++){
            /*  inserisco i vari caratteri a seconda che sia nel posto giusto o */
            /*  no                                                              */
            newStr[i] = (i == index ? chr : m_str[strInd++]);
        }
        /*  inserisco la terminazione                                           */
        newStr[newDim - 1] = 0x00;
        /*  scambio i puntatori (al solito decrementando la dimensione di uno)  */
        ptrswp(newStr, --newDim);
        /*  ritorno true                                                        */
        return true;
    }
    /*  altrimenti setto l'errore a NoMemory e ritorno false                    */
    errset(NoMemory);
    return false;
}

bool AFramework::AString::append(const AString & str){
    /*  nulla da commentare                                                     */
    return insert(str, m_dim);
}

bool AFramework::AString::append(const char & chr){
    /*  nulla da commentare                                                     */
    return insert(chr, m_dim);
}

bool AFramework::AString::prepend(const AString & str){
    /*  nulla da commentare                                                     */
    uint32 i = 0;
    return insert(str, i);
}

bool AFramework::AString::prepend(const char & chr){
    /*  nulla da commentare                                                     */
    uint32 i = 0;
    return insert(chr, i);
}

void AFramework::AString::toLower(){
    char * tmp = m_str;
    /*  se la stringa non è vuota                                               */
    if(tmp){
        /*  fino a che non trovo il carattere di terminazione                   */
        while(*tmp != 0x00){
            /*  se il carattere puntato è compreso tra A e Z                    */
            if(*tmp >= 0x41 && *tmp <= 0x5A){
                /*  sommo 32 ed ottengo il minuscolo                            */
                *tmp += 0x20;
            }
            /*  incremento il puntatore                                         */
            tmp++;
        }
    }
}

void AFramework::AString::toUpper(){
    char * tmp = m_str;
    /*  se la stringa non è vuota                                               */
    if(tmp){
        /*  fino a che non trovo il carattere di terminazione                   */
        while(*tmp != 0x00){
            /*  se il carattere puntato è compreso tra a e z                    */
            if(*tmp >= 0x61 && *tmp <= 0x7A){
                /*  sottraggo 32 ed ottengo il maiuscolo                        */
                *tmp -= 0x20;
            }
            /*  incremento il puntatore                                         */
            tmp++;
        }
    }
}

void AFramework::AString::reverse(){
    char tmp = 0x00;
    /*  scorro la stringa fino a metà (se la stringa è vuota non succede nulla) */
    for(uint32 i = 0; i < m_dim / 2; i++){
        /*  copio temporaneamente l'ultimo i-esimo elemento                     */
        tmp = m_str[m_dim - 1 - i];
        /*  sostituisco l'ultimo i-esimo con l'i-esimo                          */
        m_str[m_dim - 1 - i] = m_str[i];
        /*  sostituisco l'i-esimo con la copia dell'ultimo i-esimo              */
        m_str[i] = tmp;
    }
}

AFramework::uint32 AFramework::AString::size() const{
    /*  nulla da commentare                                                     */
    return m_dim;
}

bool AFramework::AString::isEmpty() const{
    /*  nulla da commentare                                                     */
    return !m_dim;
}

bool AFramework::AString::clear(){
    /*  se la stringa è già vuota                                               */
    if(!m_str){
        /*  ritorno false                                                       */
        return false;
    }
    /*  libero la memoria                                                       */
    delete [] m_str;
    /*  imposto a NULL                                                          */
    m_str = NULL;
    /*  azzero la dimensione                                                    */
    m_dim = 0;
    /*  ritorno true                                                            */
    return true;
}

char AFramework::AString::at(const uint32 & index) const{
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  se il puntatore è null (stringa totalmente vuota) o l'indice fuori è    */
    /*  fuori range                                                             */
    if(!m_str || index > m_dim){
        /*  setto l'errore ad OutOfRange                                        */
        errset(OutOfRange);
        /*  ritorno il carattere di terminazione                                */
        return 0x00;
    }
    /*  altrimenti l'indice corrispondete                                       */
    return m_str[index];
}

bool AFramework::AString::startsWith(const AString & str, const bool & cs){
    /*  nulla da commentare                                                     */
    return (indexOf(str, 0, cs) == 0);
}

bool AFramework::AString::startsWith(const char & chr, const bool & cs){
    /*  nulla da commentare                                                     */
    return (indexOf(chr, 0, cs) == 0);
}

bool AFramework::AString::endsWith(const AString & str, const bool & cs){
    /*  nulla da commentare                                                     */
    return (indexOf(str, m_dim - str.m_dim, cs) == m_dim - str.m_dim);
}

bool AFramework::AString::endsWith(const char & chr, const bool & cs){
    /*  se la stringa è vuota                                                   */
    if(isEmpty()){
        /*  ovviamente ritorno false                                            */
        return false;
    }
    /*  altrimenti confronto l'ultimo carattere                                 */
    return ccmp(chr, m_str[size() - 1], cs);
}

AFramework::sint32 AFramework::AString::toInt32(bool & ok) const{
    sint32 sig = 1;
    sint32 res = 0;
    char * str = m_str;
    /*  metto il flag a false                                                   */
    ok = false;
    /*  se la stringa non è vuota                                               */
    if(str){
        /*  se il primo carattere è un meno o un più                            */
        if(*str == 0x2D || *str == 0x2B){
            /*  imposto il segno                                                */
            sig = (*str == 0x2D ? -1 : 1);
            /*  incremento il puntatore                                         */
            str++;
        }
        /*  fino a che non sono alla fine                                       */
        while(*str){
            /*  non appena trovo un carattere che non sia numerico              */
            if(*str < 0x30 || *str > 0x39){
                /*  ritorno zero con il flag ok a false                         */
                ok = false;
                return 0;
            /*  se invece il carattere è numerico                               */
            }else{
                /*  metto il flag a true e accodo le cifre                      */
                ok = true;
                res = (res * 10) + static_cast<sint32>(*str - 0x30);
            }
            /*  sposto in avanti il puntatore                                   */
            str++;
        }
    }
    /*  ritorno il valore                                                       */
    return sig * res;
}

float AFramework::AString::toFloat(bool & ok) const{
    float  res = 0;
    sint32 sig = 1;
    uint32 dot = 0;
    uint32 stp = 0;
    char * str = m_str;
    /*  metto il flag a false                                                   */
    ok = false;
    /*  se la stringa non è vuota                                               */
    if(str){
        /*  se il primo carattere è un meno o un più                            */
        if(*str == 0x2D || *str == 0x2B){
            /*  imposto il segno                                                */
            sig = (*str == 0x2D ? -1 : 1);
            /*  incremento il puntatore                                         */
            str++;
        }
        /*  fino a che non sono alla fine                                       */
        while(*str){
            /*  incremento il numero di step                                    */
            stp++;
            /*  se il carattere non è numerico                                  */
            if((*str < 0x30 || *str > 0x39)){
                /*  se è un punto o una virgola e non ne ho trovati altri prima */
                /*  e inoltre non è neanche il primo carattere                  */
                if((*str == 0x2C || *str == 0x2E) && (stp != 1) && !dot){
                    /*  tengo traccia di dove ho trovato il punto               */
                    dot = stp;
                /*  altrimenti                                                  */
                }else{
                    /*  ritorno zero con il flag ok a false                     */
                    ok = false;
                    return 0;
                }
            /*  se invece il carattere è numerico                               */
            }else{
                /*  metto il flag a true e accodo le cifre                      */
                ok = true;
                res = (res * 10) + static_cast<sint32>(*str - 0x30);
            }
            /*  sposto in avanti il puntatore                                   */
            str++;
        }
    }
    /*  imposto per quante volte devo dividere per 10                           */
    dot = (dot ? stp - dot : 0);
    /*  effettuo la divisione                                                   */
    while(dot){
        dot--;
        res /= 10;
    }
    /*  ritorno il valore                                                       */
    return sig * res;
}

double AFramework::AString::toDouble(bool & ok) const{
    double res = 0;
    sint32 sig = 1;
    uint32 dot = 0;
    uint32 stp = 0;
    char * str = m_str;
    /*  metto il flag a false                                                   */
    ok = false;
    /*  se la stringa non è vuota                                               */
    if(str){
        /*  se il primo carattere è un meno o un più                            */
        if(*str == 0x2D || *str == 0x2B){
            /*  imposto il segno                                                */
            sig = (*str == 0x2D ? -1 : 1);
            /*  incremento il puntatore                                         */
            str++;
        }
        /*  fino a che non sono alla fine                                       */
        while(*str){
            /*  incremento il numero di step                                    */
            stp++;
            /*  se il carattere non è numerico                                  */
            if((*str < 0x30 || *str > 0x39)){
                /*  se è un punto o una virgola e non ne ho trovati altri prima */
                /*  e inoltre non è neanche il primo carattere                  */
                if((*str == 0x2C || *str == 0x2E) && (stp != 1) && !dot){
                    /*  tengo traccia di dove ho trovato il punto               */
                    dot = stp;
                /*  altrimenti                                                  */
                }else{
                    /*  ritorno zero con il flag ok a false                     */
                    ok = false;
                    return 0;
                }
            /*  se invece il carattere è numerico                               */
            }else{
                /*  metto il flag a true e accodo le cifre                      */
                ok = true;
                res = (res * 10) + static_cast<sint32>(*str - 0x30);
            }
            /*  sposto in avanti il puntatore                                   */
            str++;
        }
    }
    /*  imposto per quante volte devo dividere per 10                           */
    dot = (dot ? stp - dot : 0);
    /*  effettuo la divisione                                                   */
    while(dot){
        dot--;
        res /= 10;
    }
    /*  ritorno il valore                                                       */
    return sig * res;
}

char * AFramework::AString::c_str() const{
    /*  nulla da commentare                                                     */
    return m_str;
}

AFramework::AStringList * AFramework::AString::split(const char & sep, const bool &keepEmpty, const bool & cs) const{
    bool          flag =  false;
    uint32        tdim =  0;
    uint32        tind =  0;
    sint32        prev =  0;
    sint32        next = -1;
    sint32        temp =  0;
    AString       item;
    AStringList * list =  NULL;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  se la stringa non è vuota e l'ultimo carattere prima della terminazione */
    /*  è diverso dal separatore imposto il flag a true perchè vuol dire che    */
    /*  devo controllare anche l'ultima parte della stringa                     */
    flag = (m_dim && (m_str[m_dim - 1] != sep) ? true : false);
    /*  provo ad allocare la StringList                                         */
    if(System::safeAlloc(&list)){
        /*  se la lista è stata allocata correttamente cerco tutti gli indici   */
        /*  trovo il separatore indicato                                        */
        while(((next = indexOf(sep, prev, cs)) != -1) || flag){
            /*  se l'indice non è cambiato (nel senso che ho iniziato con un un */
            /*  separatore                                                      */
            if(next == prev){
                /*  sposto l'indice in avanti                                   */
                prev++;
                /*  e continuo a cercare                                        */
                continue;
            }
            /*  per evitare di fare casini con gli indici copio next su un      */
            /*  altra variabile posizionandomi una posizione prima del separa-  */
            /*  tore, inoltre se trovo next negativo vuol dire che il flag è    */
            /*  true per cui devo controlloare anche la parte finale della      */
            /*  stringa                                                         */
            temp = (next > 0 ? next - 1 : m_dim - 1);
            /*  in questo caso quindi next e prev sono diversi, prev è l'indice */
            /*  dove inizia il token mentre next è l'indice del separatore suc- */
            /*  cessivo. Adesso la politica dipende da keepEmpty:               */
            /*  Se keepEmpty è true copio il token per come lo trovo, mentre    */
            /*  se keepEmpty è false                                            */
            if(!keepEmpty){
                /*  devo riscalare gli indici fino a quando non trovo caratteri */
                /*  per cui porto prev in avanti                                */
                while(m_str[prev] == 0x20 && prev < temp){
                    prev++;
                }
                /*  se sono andato avanti fino a raggiungere prev vuol dire che */
                /*  tutto il token è fatto da caratteri non stampabili per cui  */
                /*  va ignorato                                                 */
                if(prev == temp && m_str[prev] == 0x20){
                    /*  quindi sposto l'indice in avanti                        */
                    prev = 1 + next;
                    /*  e continuo a cercare                                    */
                    continue;
                }
                /*  se sono arrivato qui vuol dire che tra prev ed temp ci sono */
                /*  caratteri, per cui posso tranquillamente scorrere a ritroso */
                /*  senza avere paura di bucare l'array                         */
                while(m_str[temp] == 0x20){
                    temp--;
                }
            }
            /* calcolo la dimensione                                            */
            tdim = 2 + temp - prev;
            if(!System::safeAlloc(&(item.m_str), tdim)){
                /*  setto la variabile d'errore                                 */
                errset(NoMemory);
                /*  faccio rollback, elimino tutto e purtroppo torno null       */
                delete list;
                return NULL;
            }
            /*  copio il token */
            for(uint32 i = prev; i <= temp; i++){
                item.m_str[tind++] = m_str[i];
            }
            /*  aggiungo la terminazione */
            item.m_str[tdim - 1] = 0x00;
            /*  setto la dimensione*/
            item.m_dim = tdim - 1;
            /*  se fallisce l'append                                            */
            if(!(list->append(item))){
                /*  setto la variabile d'errore                                 */
                errset(NoMemory);
                /*  al solito rollback e torno null                             */
                delete list;
                return NULL;
            }
            /*  libero la memoria allocata alla stringa                         */
            item.clear();
            /*  azzero l'indice per la copia                                    */
            tind = 0;
            /*  se trovo sia next uguale a -1 che il flag a true metto flag a   */
            /*  false così termino le iterazioni                                */
            if(next == -1 && flag){
                flag = false;
            }else{
                /*  altrimenti sposto in avanti l'indice                        */
                prev = 1 + next;
            }
        }
    }else{
        /*  setto l'errore a NoMemory                                           */
        errset(NoMemory);
    }
    return list;
}

char AFramework::AString::operator[](const uint32 & index) const{
    /*  nulla da commentare                                                     */
    return at(index);
}

bool AFramework::AString::operator==(const AString & str) const{
    /*  nulla da commentare                                                     */
    return compare(str);
}

bool AFramework::AString::operator==(const char & chr) const{
    /*  nulla da commentare                                                     */
    return compare(chr);
}

bool AFramework::AString::operator!=(const AString & str) const{
    /*  nulla da commentare                                                     */
    return !compare(str);
}

bool AFramework::AString::operator!=(const char & chr) const{
    /*  nulla da commentare                                                     */
    return !compare(chr);
}

bool AFramework::AString::operator+=(const AString & str){
    /*  nulla da commentare                                                     */
    return append(str);
}

bool AFramework::AString::operator+=(const char & chr){
    /*  nulla da commentare                                                     */
    return append(chr);
}

bool AFramework::AString::operator-=(const AString & str){
    /*  nulla da commentare                                                     */
    return remove(str);
}

bool AFramework::AString::operator-=(const char & chr){
    /*  nulla da commentare                                                     */
    return remove(chr);
}

AFramework::AString AFramework::AString::operator+(const AString & str){
    /*  nulla da commentare                                                     */
    return operator+(str.m_str);
}


AFramework::AString AFramework::AString::operator+(const char & chr){
    AString m_res = *this;
    /*  nulla da commentare                                                     */
    m_res.append(chr);
    return m_res;
}

AFramework::AString AFramework::AString::operator-(const AString & str){
    /*  nulla da commentare                                                     */
    return operator-(str.m_str);
}

AFramework::AString AFramework::AString::operator-(const char & chr){
    AString m_res = *this;
    /*  nulla da commentare                                                     */
    m_res.remove(chr);
    return m_res;
}

AFramework::AString & AFramework::AString::operator=(const AString & str){
    uint32  newDim = 1 + str.m_dim;
    char * newStr = NULL;
    /*  resetto la variabile d'errore                                           */
    errset();
    /*  provo ad allocare un il nuvo vettore                                    */
    if(System::safeAlloc(&newStr, newDim)){
        /*  se ci sono riuscito                                                 */
        for(uint32 i = 0; i < newDim; i++){
            /*  copio i caratteri                                               */
            newStr[i] = str.m_str[i];
        }
        /*  scambio i puntatori                                                 */
        ptrswp(newStr, --newDim);
    }else{
        /*  altrimenti setto l'errore a NoMemory                                */
        errset(NoMemory);
    }
    return *this;
}

AFramework::AString & AFramework::AString::operator=(const char & chr){
    char * m_new = new char[2];
    /*  se sono riuscito ad allocare la memoria                                 */
    if(m_new){
        /*  cancello la vecchia stringa                                         */
        clear();
        /*  copio il carattere                                                  */
        m_new[0] = chr;
        /*  inserisco la terminazione                                           */
        m_new[1] = 0x00;
        /*  riassegno il puntatore                                              */
        m_str = m_new;
    }
    /*  ritorno l'oggetto corrente                                              */
    return *this;
}

bool AFramework::AString::ccmp(const char & ch1, const char & ch2, const bool & cs){
    bool m_ch1 = (ch1 >= 0x41 && ch1 <= 0x5A) || (ch1 >= 0x61 && ch1 <= 0x7A);
    bool m_ch2 = (ch2 >= 0x41 && ch2 <= 0x5A) || (ch2 >= 0x61 && ch2 <= 0x7A);
    bool m_res = (ch1 == ch2);
    /*  se il confronto non è case sensitive e ch1 e ch2 sono caratteri         */
    if(!cs && m_ch1 && m_ch2){
        m_res = (ch1 == ch2) || (ch1 == ch2 + 0x20) || (ch1 == ch2 - 0x20);
    }
    return m_res;
}

void AFramework::AString::ptrswp(char * ptr, const uint32 & dim){
    /*  libero la memoria                                                       */
    delete [] m_str;
    /*  assegno ptr al puntatore membro                                         */
    m_str = ptr;
    /*  aggiorno la dimensione                                                  */
    m_dim = dim;
}
