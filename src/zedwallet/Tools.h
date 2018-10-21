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

#include <algorithm>

#include <string>

#include <vector>

#include <iterator>

void confirmPassword(const std::string &walletPass, const std::string &msg="");

void removeCharFromString(std::string &str, const char c);

void trim(std::string &str);

void leftTrim(std::string &str);

void rightTrim(std::string &str);

bool confirm(const std::string &msg);
bool confirm(const std::string &msg, const bool defaultReturn);

bool startsWith(const std::string &str, const std::string &substring);

bool fileExists(const std::string &filename);

std::string formatAmountBasic(const uint64_t amount);
std::string formatAmount(const uint64_t amount);
std::string formatDollars(const uint64_t amount);
std::string formatCents(const uint64_t amount);

std::string getPaymentIDFromExtra(const std::string &extra);

std::string unixTimeToDate(const uint64_t timestamp);

std::string createIntegratedAddress(const std::string &address,
                                    const std::string &paymentID);

uint64_t getDivisor();

uint64_t getScanHeight();

template <typename T, typename Function>
std::vector<T> filter(const std::vector<T> &input, Function predicate)
{
    std::vector<T> result;

    std::copy_if(
        input.begin(), input.end(), std::back_inserter(result), predicate
    );

    return result;
}
