
# BitGold Core — Tech9 Blockchain

**Tech9 Blockchain is live.** BitGold Core is a fork of [Bitcoin
Core](https://github.com/bitcoin/bitcoin) (v32.1, merged forward onto
upstream master 2026-11-13) — Satoshi Nakamoto's Bitcoin system, as its
own standalone chain, with faster blocks. Same proof of work (double
SHA-256), same 21,000,000 cap, same transaction format, same validation.
The differences: **2.5-minute blocks** (Bitcoin: 10), **12.5 BITGOLD**
per block (Bitcoin: 50 — daily issuance is unchanged at 7,200),
**halving every 840,000 blocks** (~4 years), difficulty retarget every
2,016 blocks (~3.5 days), coinbase maturity 400 blocks (~16.7 hours).
Plus a new genesis block and network parameters (magic bytes, ports,
address prefixes) so BitGold can never be confused with Bitcoin.

- Coin: **BITGOLD** — smallest unit the **grain** (1 BITGOLD =
  100,000,000 grains)
- Addresses: **B…** (P2PKH), **G…** (P2SH), **bg1…** (bech32)
- P2P port **28333**, RPC port **28332**
- Genesis block: `00000000ff64546f2fd9b68319581cc411e075cb1a4d4df84380d00a6d25a5a1`
  — "15/Nov/2026 US flights grounded for hours after air traffic control
  outage"

See [BITGOLD_CHAIN.md](BITGOLD_CHAIN.md) for every parameter changed,
the genesis block, and how to build and run a local regtest chain.

BitGold Core is released under the MIT license (see [COPYING](COPYING)).
Attribution to Satoshi Nakamoto and the Bitcoin Core developers is kept
throughout; the original Bitcoin Core README follows below.

## Status: mainnet is LIVE

The Tech9 Blockchain mainnet is live. The chain starts at genesis
with a fair launch: no premine, no reserved coins — every BITGOLD in
existence is mined, starting from block 1.

**This is a brand-new network.** There is one seed node, no exchanges,
no listings, and no independent security audit yet. Run a node, mine,
and use the wallet — but treat it as early software: don't put in more
than you can afford to lose, and report problems privately (see
[SECURITY.md](SECURITY.md)).

## Run a node

Build from source (Linux, see [BUILD.md](BUILD.md)):

```bash
git clone https://github.com/SANDMAN396/BITGOLD.git
cd BITGOLD
cmake -B build -DCMAKE_BUILD_TYPE=Release -DBUILD_GUI=OFF -DBUILD_TESTS=OFF \
  -DBUILD_BENCH=OFF -DBUILD_FUZZ_BINARY=OFF -DBUILD_TX=ON -DBUILD_UTIL=ON \
  -DBUILD_WALLET_TOOL=ON -DBUILD_UTIL_CHAINSTATE=OFF -DENABLE_IPC=OFF
cmake --build build -j$(nproc)
```

Then connect to the seed node and start syncing:

```bash
./build/src/bitgoldd -addnode=159.89.239.187 -daemon
./build/src/bitgold-cli getblockcount
```

First seed node: `159.89.239.187` (P2P port 28333). More seeds
will be listed here as the network grows. If you run a node that stays
up, open an issue and we'll add it.

## Get the wallet

- **Android:** two apps, both in the [v1.0.0 release](../../releases/tag/v1.0.0):
  **BitGold Miner** (mining + BITGOLD wallet) and **Tech Smart Wallet**
  (Tech9 tokens — Tech, Dollar, and any token you add). Both come
  pre-filled with the seed node above. Mining is only in the Miner app;
  it heats the phone and drains the battery, so plug in while it runs.
- **Desktop (Linux):** `bitgold-qt` — build with `-DBUILD_GUI=ON`
  (see [BUILD.md](BUILD.md)). Windows and Mac binaries are coming.

## Mine

At launch, difficulty is 1 — the lowest it can ever be. Any CPU can
mine, including the phone app's built-in miner. Each block pays **12.5
BITGOLD**; mined coins mature after 400 blocks (~16.7 hours).
Difficulty retargets every 2,016 blocks (~3.5 days), so it follows
hash power quickly as miners join.

## How to help

- **Run a node** — every node makes the network stronger. Keep it up
  and we'll list it as a seed.
- **Mine** — fair launch, lowest difficulty ever, right now.
- **Test transactions** — send payments, try the wallet, report what
  breaks (test amounts first).
- **Tests & GUI** — the test suite still needs a rebrand pass (8 files
  expect Bitcoin's values), and the GUI needs a rebuild on the new
  block-time parameters.
- **Security review** — read the code and report problems privately,
  never in a public issue — see [SECURITY.md](SECURITY.md).

Open an [issue](../../issues) to pick up a task or propose one.

---

Bitcoin Core integration/staging tree
=====================================

https://bitcoincore.org

For an immediately usable, binary version of the Bitcoin Core software, see
https://bitcoincore.org/en/download/.

What is Bitcoin Core?
---------------------

Bitcoin Core connects to the Bitcoin peer-to-peer network to download and fully
validate blocks and transactions. It also includes a wallet and graphical user
interface, which can be optionally built.

Further information about Bitcoin Core is available in the [doc folder](/doc).

License
-------

Bitcoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/license/MIT.

Development Process
-------------------

The `master` branch is regularly built (see `doc/build-*.md` for instructions) and tested, but it is not guaranteed to be
completely stable. [Tags](https://github.com/bitcoin/bitcoin/tags) are created
regularly from release branches to indicate new official, stable release versions of Bitcoin Core.

The https://github.com/bitcoin-core/gui repository is used exclusively for the
development of the GUI. Its master branch is identical in all monotree
repositories. Release branches and tags do not exist, so please do not fork
that repository unless it is for development reasons.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled during the generation of the build system) with: `ctest`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python.
These tests can be run (if the [test dependencies](/test) are installed) with: `build/test/functional/test_runner.py`
(assuming `build` is your build directory).

The CI (Continuous Integration) systems make sure that every pull request is tested on Windows, Linux, and macOS.
The CI must pass on all commits before merge to avoid unrelated CI failures on new pull requests.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Bitcoin Core's Transifex page](https://explore.transifex.com/bitcoin/bitcoin/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.
