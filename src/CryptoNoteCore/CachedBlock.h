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

#include <boost/optional.hpp>
#include <CryptoNote.h>
#include "crypto/crypto.h"

namespace CryptoNote {

class CachedBlock {
public:
  explicit CachedBlock(const BlockTemplate& block);
  const BlockTemplate& getBlock() const;
  const Crypto::Hash& getTransactionTreeHash() const;
  const Crypto::Hash& getBlockHash() const;
  const Crypto::Hash& getBlockLongHash(Crypto::cn_pow_hash& cryptoContext) const;
  const Crypto::Hash& getAuxiliaryBlockHeaderHash() const;
  const BinaryArray& getBlockHashingBinaryArray() const;
  const BinaryArray& getParentBlockBinaryArray(bool headerOnly) const;
  const BinaryArray& getParentBlockHashingBinaryArray(bool headerOnly) const;
  uint32_t getBlockIndex() const;

private:
  const BlockTemplate& block;
  mutable boost::optional<BinaryArray> blockHashingBinaryArray;
  mutable boost::optional<BinaryArray> parentBlockBinaryArray;
  mutable boost::optional<BinaryArray> parentBlockHashingBinaryArray;
  mutable boost::optional<BinaryArray> parentBlockBinaryArrayHeaderOnly;
  mutable boost::optional<BinaryArray> parentBlockHashingBinaryArrayHeaderOnly;
  mutable boost::optional<uint32_t> blockIndex;
  mutable boost::optional<Crypto::Hash> transactionTreeHash;
  mutable boost::optional<Crypto::Hash> blockHash;
  mutable boost::optional<Crypto::Hash> blockLongHash;
  mutable boost::optional<Crypto::Hash> auxiliaryBlockHeaderHash;
};

}
