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

#include <zedwallet/Types.h>

template<typename T>
std::string parseCommand(const std::vector<T> &printableCommands,
                         const std::vector<T> &availableCommands,
                         std::string prompt,
                         bool backgroundRefresh,
                         std::shared_ptr<WalletInfo> walletInfo);

std::tuple<bool, std::shared_ptr<WalletInfo>>
    selectionScreen(Config &config, CryptoNote::WalletGreen &wallet,
                    CryptoNote::INode &node);

bool checkNodeStatus(CryptoNote::INode &node);

std::string getAction(Config &config);

void mainLoop(std::shared_ptr<WalletInfo> walletInfo, CryptoNote::INode &node);

template<typename T>
void printCommands(const std::vector<T> &commands, int offset = 0);
