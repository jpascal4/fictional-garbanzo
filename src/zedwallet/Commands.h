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

#include <string>
#include <vector>
#include <zedwallet/WalletConfig.h>

class Command
{
    public:
        Command(std::string commandName, std::string description) :
                commandName(commandName), description(description) {}

        const std::string commandName;
        const std::string description;
};

class AdvancedCommand : public Command
{
    public:
        AdvancedCommand(std::string commandName, std::string description,
                        bool viewWalletSupport, bool advanced) :
                        Command(commandName, description),
                        viewWalletSupport(viewWalletSupport),
                        advanced(advanced) {}

        const bool viewWalletSupport;
        const bool advanced;
};

std::vector<Command> startupCommands();

std::vector<Command> nodeDownCommands();

std::vector<AdvancedCommand> allCommands();

std::vector<AdvancedCommand> basicCommands();

std::vector<AdvancedCommand> advancedCommands();

std::vector<AdvancedCommand> basicViewWalletCommands();

std::vector<AdvancedCommand> advancedViewWalletCommands();

std::vector<AdvancedCommand> allViewWalletCommands();
