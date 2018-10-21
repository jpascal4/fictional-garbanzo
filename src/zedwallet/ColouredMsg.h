// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018, The TurtleCoin Developers
// Copyright (c) 2018-2019, The BLOC.MONEY Developers
//
// Please see the included LICENSE file for more information.
// 
// BLOC is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// BLOC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with BLOC. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <Common/ConsoleTools.h>

#include <iomanip>

#include <ostream>

#include <string>

class ColouredMsg
{
    public:
        ColouredMsg(std::string msg, Common::Console::Color colour) 
                  : msg(msg), colour(colour) {}

        ColouredMsg(std::string msg, int padding, 
                    Common::Console::Color colour)
                  : msg(msg), colour(colour), padding(padding), pad(true) {}


        /* Set the text colour, write the message, then reset. We use a class
           as it seems the only way to have a valid << operator. We need this
           so we can nicely do something like:

           std::cout << "Hello " << GreenMsg("user") << std::endl;

           Without having to write:

           std::cout << "Hello ";
           GreenMsg("user");
           std::cout << std::endl; */

        friend std::ostream& operator<<(std::ostream& os, const ColouredMsg &m)
        {
            Common::Console::setTextColor(m.colour);

            if (m.pad)
            {
                os << std::left << std::setw(m.padding) << m.msg;
            }
            else
            {
                os << m.msg;
            }

            Common::Console::setTextColor(Common::Console::Color::Default);
            return os;
        }

    protected:
        std::string msg;
        const Common::Console::Color colour;
        const int padding = 0;
        const bool pad = false;
};

class SuccessMsg : public ColouredMsg
{
    public:
        explicit SuccessMsg(std::string msg) 
               : ColouredMsg(msg, Common::Console::Color::Green) {}

        explicit SuccessMsg(std::string msg, int padding)
               : ColouredMsg(msg, padding, Common::Console::Color::Green) {}
};

class InformationMsg : public ColouredMsg
{
    public:
        explicit InformationMsg(std::string msg) 
               : ColouredMsg(msg, Common::Console::Color::BrightYellow) {}

        explicit InformationMsg(std::string msg, int padding)
               : ColouredMsg(msg, padding, 
                             Common::Console::Color::BrightYellow) {}
};

class SuggestionMsg : public ColouredMsg
{
    public:
        explicit SuggestionMsg(std::string msg) 
               : ColouredMsg(msg, Common::Console::Color::BrightYellow) {}

        explicit SuggestionMsg(std::string msg, int padding)
               : ColouredMsg(msg, padding, 
                             Common::Console::Color::BrightYellow) {}
};

class WarningMsg : public ColouredMsg
{
    public:
        explicit WarningMsg(std::string msg) 
               : ColouredMsg(msg, Common::Console::Color::BrightRed) {}

        explicit WarningMsg(std::string msg, int padding)
               : ColouredMsg(msg, padding, 
                             Common::Console::Color::BrightRed) {}
};
