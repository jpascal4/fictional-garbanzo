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

#include <Wallet/WalletGreen.h>

bool handleCommand(const std::string command,
                   std::shared_ptr<WalletInfo> walletInfo,
                   CryptoNote::INode &node);

void changePassword(std::shared_ptr<WalletInfo> walletInfo);

void printPrivateKeys(CryptoNote::WalletGreen &wallet, bool viewWallet);

void reset(CryptoNote::INode &node, std::shared_ptr<WalletInfo> walletInfo);

void status(CryptoNote::INode &node, CryptoNote::WalletGreen &wallet);

void printHeights(uint32_t localHeight, uint32_t remoteHeight,
                  uint32_t walletHeight);

void printSyncStatus(uint32_t localHeight, uint32_t remoteHeight,
                     uint32_t walletHeight);

void printSyncSummary(uint32_t localHeight, uint32_t remoteHeight,
                      uint32_t walletHeight);

void printPeerCount(size_t peerCount);

void printHashrate(uint64_t difficulty);

void balance(CryptoNote::INode &node, CryptoNote::WalletGreen &wallet,
             bool viewWallet);

void exportKeys(std::shared_ptr<WalletInfo> walletInfo);

void saveCSV(CryptoNote::WalletGreen &wallet, CryptoNote::INode &node);

void save(CryptoNote::WalletGreen &wallet);

void listTransfers(bool incoming, bool outgoing, 
                   CryptoNote::WalletGreen &wallet, CryptoNote::INode &node);

void printOutgoingTransfer(CryptoNote::WalletTransaction t,
                           CryptoNote::INode &node);

void printIncomingTransfer(CryptoNote::WalletTransaction t,
                           CryptoNote::INode &node);

void createIntegratedAddress();

void help(std::shared_ptr<WalletInfo> wallet);

void advanced(std::shared_ptr<WalletInfo> wallet);
