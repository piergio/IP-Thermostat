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

#ifndef ASTRING_H
#define ASTRING_H

#include "ACore.h"
#include "AErrorNotifier.h"
#include "AContainers.h"

namespace AFramework{
    
    class AString;
    typedef ALinkedList<AString> AStringList;
    
    class AString : public AErrorNotifier{
        public:
            static  uint32  strlen(const char  * str);
            
            AString();
            AString(const AString & str);
            AString(const char    * str);
            explicit AString(const sint32 & val);
            explicit AString(const float  & val, const uint8 & prec = 3);
            explicit AString(const double & val, const uint8 & prec = 3);
            ~AString();
            bool remove(const AString & str, const bool & cs = false);
            bool remove(const char    & chr, const bool & cs = false);
            bool contains(const AString & str, const bool & cs = false) const;
            bool contains(const char    & chr, const bool & cs = false) const;
            bool compare(const AString & str, const bool & cs = false) const;
            bool compare(const char    & chr, const bool & cs = false) const;
            bool replace(const AString & before, const AString & after, const bool & cs = false);
            bool replace(const char    & before, const char    & after, const bool & cs = false);
            sint32 indexOf(const AString & str, const uint32 & index = 0, const bool & cs = false) const;
            sint32 indexOf(const char    & chr, const uint32 & index = 0, const bool & cs = false) const;
            AString right(const uint32 index) const;
            AString left(const uint32 index) const;
            bool insert(const AString & str, const uint32  & index);
            bool insert(const AString & str, const AString & after, const bool & cs = false);
            bool insert(const char & chr, const uint32 & index);
            bool insert(const char & chr, const char   * after, const bool & cs = false);
            bool append(const AString & str);
            bool append(const char    & chr);
            bool prepend(const AString & str);
            bool prepend(const char    & chr);
            void toLower();
            void toUpper();
            void reverse();
            uint32 size() const;
            bool isEmpty() const;
            bool clear();
            char at(const uint32 & index) const;
            bool startsWith(const AString & str, const bool & cs = false);
            bool startsWith(const char    & chr, const bool & cs = false);
            bool endsWith(const AString & str, const bool & cs = false);
            bool endsWith(const char    & chr, const bool & cs = false);
            sint32 toInt32(bool & ok) const;
            float toFloat(bool & ok) const;
            double toDouble(bool & ok) const;
            char * c_str() const;
            AStringList * split(const char & sep, const bool & keepEmpty = false, const bool & cs = false) const;
            char operator[](const uint32 & index) const;
            bool operator==(const AString & str) const;
            bool operator==(const char    & chr) const;
            bool operator!=(const AString & str) const;
            bool operator!=(const char    & chr) const;
            bool operator+=(const AString & str);
            bool operator+=(const char    & chr);
            bool operator-=(const AString & str);
            bool operator-=(const char    & chr);
            AString operator+(const AString & str);
            AString operator+(const char    & chr);
            AString operator-(const AString & str);
            AString operator-(const char    & chr);
            AString & operator=(const AString & str);
            AString & operator=(const char    & chr);
        private:
            template <class T>  static  char * numToASCII(const T val, const uint8 prc);
            static  bool   ccmp(const char & ch1, const char & ch2, const bool & cs = true );
            void   ptrswp(char * ptr, const uint32 & dim);
            uint32 m_dim;
            char * m_str;
    };

    template <class T> char * AString::numToASCII(const T val, const uint8 prc){
        /*  Per questioni di risparmio di memoria ho preferito sviluppare la    */
        /*  funzione per la conversione dei numeri in stringa come template.    */
        /*  Utilizzando questa versione (ovvero richiamando la presente)        */
        /*  l'occupazione in memoria diminuisce del 1% sul totale (25% sulla    */
        /*  classe AString). L'algoritmo che ho sviluppato opera nel seguente   */
        /*  modo: moltiplico il numero passato per una potenza di 10 (tengo     */
        /*  queste in un vettore perchè i passaggi sono tanti, se devo mettermi */
        /*  anche a moltiplicare è finita...) dopo averne fatto il valore       */
        /*  assoluto, dopo di che considero il numero di elementi della stringa */
        /*  tramite la variabile m_dig (m_digits): nel caso il numero sia nega- */
        /*  tivo aggiungo oltre che al carattere di terminazione un elemento    */
        /*  per il segno meno, aggiungo anche se è richiesta precisione supe-   */
        /*  riore a zero un elemento per il carattere '.'. Considero poi un     */
        /*  flag che metto a true se il numero è negativo e mi serve per capire */
        /*  se aggiungere il segno meno o no                                    */
        uint32 pow[] = {0x00001, 0x0000A, 0x00064, 0x003E8, 0x02710, 0x186A0, 0xF4240 };
        uint32 raw   = (val < 0 ? -1 * val : val ) * pow[prc > 0x5 ? 0x6 : prc ];
        uint32 dig   = (val < 0 ?        2 : 1   ) +    (prc       ?   1 :   0 );
        uint32 tmp   =  raw;
        bool   flg   = (val < 0 ? true : false );
        char * res   =  NULL;
        /*  dopo quanto detto al numero di cifre precedente (carattere termina- */
        /*  zione, eventuali punto e segno meno) il numero di cifre proprie del */
        /*  numero moltiplicato per la potenza di 10, contandole come segue:    */
        /*  fino a che il numero è diverso da zero                              */
        while(tmp){
            /*  riassegno al numero la sua divisione per 10                     */
            tmp /= 10;
            /*  ed incremento il numero di cifre                                */
            dig++;
        }
        /*  se il numero è zero                                                 */
        if(raw == 0){
            /*  incremento il numero di cifre                                   */
            dig++;
        }
        /*  provo ad allocare la stringa della dimensione necessaria            */
        if(System::safeAlloc(&res, dig)){
            /*  se l'allocazione è andata a buon fine aggiungo subito il carat- */
            /*  tere di terminazione a fine stringa                             */
            res[dig - 1] = 0x00;
            /*  se il numero era negativo                                       */
            if(flg){
                /*  aggiungo il segno meno                                      */
                res[0] = 0x2D;
            }
            /*  partendo poi dalla coda della stringa e scorrendola all'indie-  */
            /*  tro fino a 0 nel caso sia positivo o ad uno nel caso sia nega-  */
            /*  tivo                                                            */
            for(sint32 i = dig - 2; i >= (flg ? 1 : 0) ; i--){
                /*  se la precisione richiesta è diversa da zero e sono arriva- */
                /*  to alla posizione dove dovrebbe stare il punto              */
                if(prc && (i == dig - 2 - (prc > 0x5 ? 0x6 : prc))){
                    /*  aggiungo in punto                                       */
                    res[i] = 0x2E;
                }else{
                    /*  altrimenti assegno il resto della divisione per 10      */
                    /*  sommato a 48 per la conversione                         */
                    res[i] = (raw % 10) + 0x30;
                    /*  e divido ancora per 10 riassegnando                     */
                    raw /= 10;
                }
                /*  praticamente il numero se prima era 134.444 diventa 134444  */
                /*  e tengo traccia delle cifre decimali utilizzando la preci-  */
                /*  sione passata                                               */
            }
        }
        /*  alla fine restituisco il risultato (che può anche essere NULL)      */
        return res;
    }
    
    extern const char * endl;
}
#endif /* ASTRING_H */
