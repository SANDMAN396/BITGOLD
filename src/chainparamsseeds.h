// Copyright (c) The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://opensource.org/license/mit.

#ifndef BITCOIN_CHAINPARAMSSEEDS_H
#define BITCOIN_CHAINPARAMSSEEDS_H

#include <array>
#include <cstdint>

/**
 * List of fixed seed nodes for the BitGold network.
 *
 * BitGold has no seed nodes yet, so all four arrays are empty. Peers must
 * be added explicitly (addnode / connect) until seed infrastructure exists.
 *
 * When BitGold has seed nodes, regenerate this file the way Bitcoin Core
 * does (contrib/seeds/generate-seeds.py) with BitGold's own seed list and
 * the upstream raw-array format. The empty std::array form below is used
 * because a zero-length C array is not valid C++.
 */
inline constexpr std::array<uint8_t, 0> chainparams_seed_main{};
inline constexpr std::array<uint8_t, 0> chainparams_seed_signet{};
inline constexpr std::array<uint8_t, 0> chainparams_seed_test{};
inline constexpr std::array<uint8_t, 0> chainparams_seed_testnet4{};
#endif // BITCOIN_CHAINPARAMSSEEDS_H
