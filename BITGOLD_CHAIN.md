# BitGold — the chain

**BitGold is Bitcoin's system, mirrored exactly, as its own standalone
chain.** It is a fork of [Bitcoin Core](https://github.com/bitcoin/bitcoin)
**v32.1** (commit `f0de87f040621468b956f01f526a43a010310501`), built off
Satoshi Nakamoto's white paper, *"Bitcoin: A Peer-to-Peer Electronic Cash
System"* (31 October 2008), using Satoshi's code and rules.

The public branch is the v32.1 rebrand **merged forward onto upstream
master `a527a007` (2026-11-13)** — same identity changes, plus the new
upstream work (silent-payments HRPs, signet datadirs, placeholder man
pages). The merged tree was rebuilt and re-proven on regtest
2026-11-15 (same genesis, 151 blocks, 10 BITGOLD test transaction,
halving at block 150 — see the proof section below).

BitGold is **not** an Ethereum token. The ERC20 BitGold in
`~/workspace/tokennine/` is only a model. This — `bitgold-core/` — is the
real BitGold: its own chain, its own network, its own genesis block.

## Status: Phase 1 — local regtest proof only

BitGold has been built and proven on a **local regtest network only**.
There is no public network, no seed nodes, no mining community, no
wallets, no exchanges, and no funds. Nothing has been launched, and
nothing here is ready for a public launch. See
[What remains before any public launch](#what-remains-before-any-public-launch).

## What changed, what didn't

**Unchanged — Bitcoin's consensus rules, exactly:**

| Rule | Value (same as Bitcoin) |
|---|---|
| Total supply cap | 21,000,000 BITGOLD |
| Starting block reward | 50 BITGOLD |
| Halving interval | every 210,000 blocks |
| Difficulty retarget | every 2,016 blocks |
| Target block time | 10 minutes |
| Proof of work | double SHA-256 |
| Block size / weight limits | same as Bitcoin |
| Transaction format & validation | same as Bitcoin |
| Script rules (incl. segwit, taproot) | same as Bitcoin |
| Halving schedule | 50 → 25 → 12.5 … (regtest halves every 150 blocks, as Bitcoin's regtest does) |

**Changed — identity and network parameters only:**

| Parameter | Bitcoin | BitGold |
|---|---|---|
| Coin name / ticker | Bitcoin / BTC | BitGold / BITGOLD |
| Smallest unit | satoshi (sat) | **grain** (1 BITGOLD = 100,000,000 grains; a grain is a real unit of gold weight — 1 troy oz = 480 grains) |
| Client name / version | Bitcoin Core 32.1.0 | BitGold Core 1.0.0 |
| User agent | `/Satoshi:32.1.0/` | `/BitGold:1.0.0/` |
| Genesis block | 2009-01-03, Times headline | 2026-11-15, see below |
| Genesis message | "The Times 03/Jan/2009 Chancellor on brink of second bailout for banks" | "15/Nov/2026 US flights grounded for hours after air traffic control outage" |
| P2P magic, mainnet | `f9 be b4 d9` | `31 20 e9 70` |
| P2P magic, testnet | `0b 11 09 07` | `c7 53 db d1` |
| P2P magic, testnet4 | `1c 16 3f 28` | `22 5c ad ac` |
| P2P magic, signet | derived from challenge | derived from new challenge: `41 04 e7 c5` |
| P2P magic, regtest | `fa bf b5 da` | `31 6b fc a4` |
| P2P port, mainnet / testnet / testnet4 / signet / regtest | 8333 / 18333 / 48333 / 38333 / 18444 | 28333 / 28343 / 28353 / 28363 / 28373 |
| RPC port, mainnet / testnet / testnet4 / signet / regtest | 8332 / 18332 / 48332 / 38332 / 18443 | 28332 / 28342 / 28352 / 28362 / 28372 |
| P2PKH address version, mainnet | 0 (`1…`) | 25 (`B…`) |
| P2SH address version, mainnet | 5 (`3…`) | 38 (`G…`) |
| WIF secret key version, mainnet | 128 | 70 (compressed keys start with `B`) |
| Extended public key, mainnet | `0488B21E` (`xpub`) | `0488C21E` (`xq5h`) |
| Extended secret key, mainnet | `0488ADE4` (`xprv`) | `0488CDE4` (`xqD9`) |
| P2PKH / P2SH / WIF, test networks | 111 / 196 / 239 (`m…`/`n…`, `2…`) | 127 / 65 / 180 (`t…`, `T…`) |
| Extended keys, test networks | `043587CF` / `04358394` (`tpub`/`tprv`) | `043597CF` / `04359394` (`tq5h`/`tq32`) |
| Bech32 HRP, mainnet / test / regtest | `bc` / `tb` / `bcrt` | `bg` / `tbg` / `bgrt` |
| DNS seeds / fixed seeds | Bitcoin's seed nodes | **none** — peers must be added explicitly until seed infrastructure exists |
| Checkpoints / assume-valid block | Bitcoin's | **none** |
| UTXO snapshots (assumeutxo) | Bitcoin's | **none** |
| Minimum chain work | Bitcoin's | none (null) |
| Buried deployments (BIP34/65/66, CSV, segwit) | Bitcoin's historical heights | active from height 1 (a new chain has no pre-activation history — the same pattern Bitcoin Core itself uses for testnet4; the rules are identical) |
| Signet challenge | Bitcoin's 2-of-2 multisig | fresh 2-of-2 multisig (new signers; keys in `signet-keys.txt`, test network only) |
| Message-signing magic | "Bitcoin Signed Message:" | "BitGold Signed Message:" (a BitGold signature must not verify as a Bitcoin signature) |
| BIP324 v2 transport salt | `bitcoin_v2_shared_secret` | `bitgold_v2_shared_secret` |
| Internal-address IPv6 prefix | `FD 6B 88 C0 87 24` (0xFD + SHA256("bitcoin")[0:5]) | `FD E1 AB 71 31 CA` (0xFD + SHA256("bitgold")[0:5]) |
| Currency ticker (fee displays, RPC) | BTC | BITGOLD |
| Smallest-unit display (fee rates) | sat (`sat/vB`) | grain (`grain/vB`) |
| Data directory | `~/.bitcoin` | `~/.bitgold` |
| Config file | `bitcoin.conf` | `bitgold.conf` |
| PID file | `bitcoind.pid` | `bitgoldd.pid` |
| Binaries | `bitcoin`, `bitcoind`, `bitcoin-cli`, `bitcoin-tx`, `bitcoin-wallet`, `bitcoin-util`, `bitcoin-node`, `bitcoin-qt` | `bitgold`, `bitgoldd`, `bitgold-cli`, `bitgold-tx`, `bitgold-wallet`, `bitgold-util`, `bitgold-node`, `bitgold-qt` |
| Man pages | `bitcoin*.1` | `bitgold*.1` |
| Init/service files | `bitcoind.*` | `bitgoldd.*` |

Magic bytes are the first 4 bytes of SHA-256("BitGold \<network>") —
deterministic, and none collide with Bitcoin's, Litecoin's, or
Dogecoin's. Address version bytes were chosen so BitGold addresses
start with `B` (P2PKH) and `G` (P2SH) on mainnet and can never be
confused with Bitcoin addresses. Ports are spaced 10 apart so the
Tor/onion port (P2P + 1) never collides with another network's RPC
port (P2P − 1).

**Deliberately left as-is (internal identifiers, not user-visible):**
library target names (`bitcoin_node`, `bitcoin_common`, …), source file
names (`bitcoin-cli.cpp`, …), include guards, namespaces, the
`bitcoin-build-config.h` generated header, and the test/bench binary
names (`test_bitcoin`, `bench_bitcoin`). Renaming them would churn the
diff for zero user-visible benefit. The Qt GUI keeps its `BitcoinUnit`
class name internally; its *displayed* unit names are BitGold's
(BITGOLD, mBITGOLD, µBITGOLD, grain).

**Attribution kept:** the MIT license (`COPYING`), the "Bitcoin Core"
copyright strings, and the upstream homepage URL (BitGold has no
homepage yet). The bug-report URL still points at Bitcoin's issue
tracker until BitGold has its own repo — a pre-launch item.

## Genesis blocks

All five networks share one coinbase (and therefore one merkle root),
exactly as Bitcoin's networks do. The coinbase pays 50 BITGOLD to
Satoshi's genesis pubkey — unspendable on any chain, a mirror of
Bitcoin's genesis. The message is the real headline of 2026-11-15
(the day the US grounded flights for hours after an air traffic
control outage — the same event Pops asked about on 2026-11-13). The
format is dated like Satoshi's, but it does not fake a newspaper name.

- Message: `15/Nov/2026 US flights grounded for hours after air traffic control outage`
- Shared merkle root: `e79fd87366b69d64f6d2b6e39e8cd7052c2866bb730ee91c44951d258fd602d6`
- Coinbase scriptSig (82 bytes): `04ffff001d01044a31352f4e6f762f3230323620555320666c69676874732067726f756e64656420666f7220686f75727320616674657220616972207472616666696320636f6e74726f6c206f7574616765`

| Network | nBits | Timestamp (UTC) | Nonce | Genesis hash |
|---|---|---|---|---|
| mainnet | 0x1d00ffff | 1794724824 (2026-11-15 06:40:24) | 1403313620 | `00000000ff64546f2fd9b68319581cc411e075cb1a4d4df84380d00a6d25a5a1` |
| testnet | 0x1d00ffff | 1794724884 (2026-11-15 06:41:24) | 3011183091 | `0000000007f55d05faae8a36c7afb0d24f432473a7b4c82e6ce413f5ca7c868b` |
| testnet4 | 0x1d00ffff | 1794724945 (2026-11-15 06:42:25) | 3579803585 | `00000000dc1d79e95f7ad14648162d6db59fefccfe0b330f6b26e5bb78ed9dfd` |
| signet | 0x1e0377ae | 1794725004 (2026-11-15 06:43:24) | 11714297 | `000002850eb3cc20c5aeb63709b5091c72f40f1ae88ba22f32d889626310c15c` |
| regtest | 0x207fffff | 1794725064 (2026-11-15 06:44:24) | 2 | `60d9d910c28e59e529a06aea432bfc99520410223536c8fdf6bf59313393cfe5` |

Each genesis block was mined properly (valid proof of work at its
network's difficulty) and each hash was independently verified in
Python (double SHA-256 of the 80-byte header, hash ≤ target).
Mainnet took 1,403,313,621 hashes (~2.0M/s, ~12 min). The timestamps
are staggered 60 seconds apart so the five genesis blocks are
distinct. Full record: `GENESIS_RESULTS.md`. Miner: `genesis_mine.c`
(C, OpenSSL, midstate optimization); header builder: `genesis.py`
(verified by reproducing Bitcoin's genesis exactly).

## Signet

BitGold signet uses a fresh 2-of-2 multisig challenge (same format as
Bitcoin's default signet):

- Challenge (71 bytes): `5121039b439521942dd9fdf29ff194a72894fd30bbbc7df4a4416b8d909df707b3855521025375720c8e642910a063eb77a0bb8f5a0f4d3e43e0fea97f9b73ba2c4d9bb7ea52ae`
- Signer 1 pubkey: `039b439521942dd9fdf29ff194a72894fd30bbbc7df4a4416b8d909df707b38555`
- Signer 2 pubkey: `025375720c8e642910a063eb77a0bb8f5a0f4d3e43e0fea97f9b73ba2c4d9bb7ea`
- Resulting signet magic: `41 04 e7 c5`
- Private keys: `signet-keys.txt` (0600, outside the git repo) — **test
  network keys only, never mainnet funds.** A production signet would
  use its own signers.

## How to build

See [BUILD.md](BUILD.md) for the full log (dependencies, exact
commands, memory notes). Short version (Ubuntu 24.04):

```bash
cd bitgold-core
cmake -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_GUI=OFF -DBUILD_TESTS=OFF \
  -DBUILD_BENCH=OFF -DBUILD_FUZZ_BINARY=OFF -DBUILD_TX=ON -DBUILD_UTIL=ON \
  -DBUILD_WALLET_TOOL=ON -DBUILD_UTIL_CHAINSTATE=OFF -DENABLE_IPC=OFF \
  -DWITH_CCACHE=ON -DCMAKE_LINKER_TYPE=LLD
cmake --build build -j1
```

Binaries land in `build/src/`: `bitgoldd`, `bitgold-cli`, `bitgold`,
`bitgold-tx`, `bitgold-wallet`, `bitgold-util`.

## How to run regtest + mine (local proof)

Two nodes on one machine, connected to each other, mining regtest
blocks. **Never run a public node from this build; never connect it
to the Bitcoin network.**

```bash
BIN=bitgold-core/build/src
mkdir -p node1 node2   # bitgoldd -daemon needs the datadirs to exist
# Node 1 (datadir ./node1, P2P 28373, RPC 28372)
# -fallbackfee is required: a fresh regtest chain has no fee history,
# so sendtoaddress fails without it ("Fee estimation failed").
$BIN/bitgoldd -regtest -datadir=$PWD/node1 -fallbackfee=0.00001 -daemon
# Node 2 (datadir ./node2, P2P 28374, RPC 28375), connected to node 1
$BIN/bitgoldd -regtest -datadir=$PWD/node2 -port=28374 -rpcport=28375 \
  -connect=127.0.0.1:28373 -fallbackfee=0.00001 -daemon
# NOTE: bitgold-cli does not read the daemon's RPC port from the
# datadir — node 2 commands below need -rpcport=28375 added.

# Create wallets and mine 101 blocks on node 1 (coinbase matures after 100)
$BIN/bitgold-cli -regtest -datadir=$PWD/node1 createwallet "miner"
ADDR=$($BIN/bitgold-cli -regtest -datadir=$PWD/node1 getnewaddress)
$BIN/bitgold-cli -regtest -datadir=$PWD/node1 generatetoaddress 101 "$ADDR"

# Check the chain: genesis hash, height, reward
$BIN/bitgold-cli -regtest -datadir=$PWD/node1 getblockhash 0
$BIN/bitgold-cli -regtest -datadir=$PWD/node1 getblockcount
$BIN/bitgold-cli -regtest -datadir=$PWD/node1 getbalance

# Send from node 1 to node 2 and confirm
$BIN/bitgold-cli -regtest -datadir=$PWD/node2 -rpcport=28375 createwallet "receiver"
RADDR=$($BIN/bitgold-cli -regtest -datadir=$PWD/node2 -rpcport=28375 getnewaddress)
$BIN/bitgold-cli -regtest -datadir=$PWD/node1 sendtoaddress "$RADDR" 10
$BIN/bitgold-cli -regtest -datadir=$PWD/node1 generatetoaddress 1 "$ADDR"
$BIN/bitgold-cli -regtest -datadir=$PWD/node2 -rpcport=28375 getbalance   # 10 (after 1 confirmation)
```

Expected regtest genesis hash: `60d9d910c28e59e529a06aea432bfc99520410223536c8fdf6bf59313393cfe5`.
Block reward is 50 BITGOLD; on regtest it halves every 150 blocks
(Bitcoin's regtest halves every 150 too — mainnet halves every
210,000, verified in code).

## Regtest proof — run 2026-11-15 (local only, no public network)

Two nodes on one machine, `node1` (P2P 28373 / RPC 28372) and `node2`
(P2P 28374 / RPC 28375, `-connect=127.0.0.1:28373`). All values below
were read back from the running chain with `bitgold-cli`:

- **Genesis hash (regtest):** `60d9d910c28e59e529a06aea432bfc99520410223536c8fdf6bf59313393cfe5`
  — matches the mined genesis. Genesis header read back from the chain:
  time 1794725064, nonce 2, bits 0x207fffff, merkle root
  `e79fd87366b69d64f6d2b6e39e8cd7052c2866bb730ee91c44951d258fd602d6`,
  coinbase output 50.0, coinbase message
  "15/Nov/2026 US flights grounded for hours after air traffic control
  outage".
- **Identity:** `getnetworkinfo` reports version 10000, subversion
  `/BitGold:1.0.0/`, protocol 70017 (same protocol as upstream v32.1).
  Both nodes show each other as peers with subversion
  `/BitGold:1.0.0/`.
- **Addresses:** `getnewaddress` returns bech32 `bgrt1...` addresses
  (regtest HRP `bgrt`): miner `bgrt1qnnxvmvrmj9jwexw5td8cq358ff37r4auraajp3`,
  receiver `bgrt1qqs92wkae6mzxetc5kqxtmyzzl5yrf0m763sgem`.
- **Mining + propagation:** node 1 mined 101 blocks; node 2 synced to
  height 101. Node 1 balance after 101 blocks: 50 BITGOLD (only block
  1's coinbase is mature at height 101 — coinbase maturity is 100
  blocks, same as Bitcoin).
- **Block reward:** block 1 coinbase pays **50.0 BITGOLD**.
- **Transaction between nodes:** node 1 sent 10 BITGOLD to node 2,
  tx `5b03a25d6a2b8363d487f0e411b186f87661655f736339d7c868a0a0d73a314f`.
  Node 2 saw it in its mempool (P2P propagation), then node 1 mined
  1 block: node 2 balance **10.00000000**, 1 confirmation.
- **Halving (regtest):** mined to height 151. Block 149 coinbase pays
  50.0, block 150 pays **25.0** — the halving boundary is exactly at
  block 150 (50 >> (150/150) = 25), as Bitcoin's subsidy rule dictates.
  Mainnet's 210,000-block interval is unchanged in code.
- **All five genesis blocks verified from running binaries** (each
  network started with `-connect=0 -listen=0 -dnsseed=0`, no network
  contact; the chainparams asserts would abort the node on a wrong
  value): mainnet `00000000ff64…25a5a1`, testnet `0000000007f5…c868b`,
  testnet4 `00000000dc1d…9dfd`, signet `000002850eb3…0c15c`, regtest
  `60d9d910…3cfe5` — all match the mined values in `GENESIS_RESULTS.md`.

The proof chain datadirs are kept at `node1/` and `node2/` (18 MB each).
Both nodes were stopped cleanly after the proof.

### Re-proof on the merged tree — run 2026-11-15 (local only)

The merged tree (`bitgold-master`, rebrand on upstream master
`a527a007`) was built from scratch (100%, zero errors) and re-proven
on fresh regtest datadirs: same regtest genesis
`60d9d910…3cfe5`, two nodes peered (`/BitGold:1.0.0/`), 151 blocks,
block 1 coinbase 50.0, 10 BITGOLD test transaction
(`6245121d66c8bc907123a574d8ad6b28ccd41bdfe16a45cf666592ac97cdab23`,
node 2 balance 10.00000000 after 1 confirmation), block 149 pays
50.0 and block 150 pays 25.0. No code fixes were needed — the public
branch behaves exactly like the v32.1 tree.

## What remains before any public launch could even be considered

This is a local regtest proof, not a launch. A public BitGold network
would need, at minimum:

- **Seed nodes and DNS seeds** — there are none; the network cannot
  bootstrap itself today.
- **A mining community** — mainnet difficulty 1 with no miners is not a
  secure chain; it needs real hash power and a fair launch story.
- **Wallets** — the GUI is not built or branded (icons still show
  Bitcoin's artwork; translations still say Bitcoin), and no mobile or
  hardware wallet supports BitGold addresses.
- **Exchanges and listings** — none, and no ticker is registered
  anywhere.
- **A public repo + issue tracker** — the repo is public at
  `SANDMAN396/BITGOLD-` (branch `main`); the issue tracker still needs
  enabling in repo Settings, and the bug-report URL still points at
  Bitcoin's tracker.
- **Security review** — the rebrand touched consensus-adjacent code
  (chainparams, genesis, address prefixes); it needs independent
  review, and the full test suite needs a rebrand pass before it can
  run green (8 test files still expect Bitcoin's genesis hashes,
  addresses, and key vectors: `src/test/data/blockfilters.json`,
  `src/test/data/key_io_{valid,invalid}.json`,
  `src/test/descriptor_tests.cpp`,
  `src/test/fuzz/p2p_headers_presync.cpp`,
  `src/test/kernel/test_kernel.cpp`, `src/test/uint256_tests.cpp`,
  `src/qt/test/rpcnestedtests.cpp`).
- **Legal review** — launching a new coin has legal and regulatory
  implications that vary by jurisdiction; none of that work is done.
- **Signet signers** — the current signet keys are throwaway test keys.

Forking Bitcoin Core is legal under the MIT license with attribution
kept — which is why the license, the copyright strings, and the
upstream links stay in the tree.

## Files

- `bitgold-core/` — the fork (git repo; pristine v32.1 is commit
  `b4940c9`, the rebrand is `e022d03` + follow-ups)
- `BUILD.md` — build log (dependencies, commands, results)
- `GENESIS_RESULTS.md` — genesis mining record
- `genesis.py` — genesis header builder (verified against Bitcoin's genesis)
- `genesis_mine.c` — genesis miner (C, OpenSSL)
- `genesis_<network>.txt` — header templates used for mining
- `choose_params.py` — magic-byte / address-prefix chooser
- `rebrand_chainparams_pass1.py` — the chainparams rebrand script
- `signet-keys.txt` — signet signer private keys (0600, **not in git**)
- `v32.1.tar.gz` — upstream release tarball (source of the fork)
