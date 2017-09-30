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

#ifndef AERRORNOTIFIER_H
#define	AERRORNOTIFIER_H

namespace AFramework{

    class AAbstractErrorNotifier{
        public:
            enum AErrors{   
                            NoError,
                            NoMemory,
                            OutOfRange,
                            InvalidGpio,
                            MultipleGpio,
                            NotEnoughOutput
                        };
            virtual bool good() const volatile = 0;
            virtual AErrors lastError() const volatile = 0;
        protected:
            virtual void errset(const AErrors &err = NoError) const volatile = 0;
    };
    
    class AErrorNotifier : public AAbstractErrorNotifier{
        public:
            AErrorNotifier();
            AAbstractErrorNotifier::AErrors lastError() const volatile;
            bool good() const volatile;
        protected:
            mutable volatile AErrors m_err;
            void errset(const AAbstractErrorNotifier::AErrors &err = AAbstractErrorNotifier::NoError) const volatile;
    };
}

#endif	/* AERRORNOTIFIER_H */

