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

#include "AErrorNotifier.h"

AFramework::AErrorNotifier::AErrorNotifier(){
    /*  Nulla da commentare                                                     */
    m_err = AAbstractErrorNotifier::NoError;
}

AFramework::AAbstractErrorNotifier::AErrors AFramework::AErrorNotifier::lastError() const volatile{
    /*  Nulla da commentare                                                     */
    return m_err;
}

bool AFramework::AErrorNotifier::good() const volatile{
    /*  Nulla da commentare                                                     */
    return m_err == AAbstractErrorNotifier::NoError;
}

void AFramework::AErrorNotifier::errset(const AAbstractErrorNotifier::AErrors &err) const volatile{
    /*  Nulla da commentare                                                     */
    m_err = err;
}

