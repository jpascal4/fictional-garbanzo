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
#include "Rpc/CoreRpcServerCommandsDefinitions.h"

namespace Common
{
  std::string get_mining_speed(uint32_t hr);
  std::string get_sync_percentage(uint64_t height, uint64_t target_height);
  std::string get_upgrade_time(uint64_t height, uint64_t upgrade_height);
  std::string get_status_string(CryptoNote::COMMAND_RPC_GET_INFO::response iresp);
}
