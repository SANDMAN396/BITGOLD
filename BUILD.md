# BitGold Core — Build Log

BitGold Core 1.0.0, a fork of Bitcoin Core v32.1 (commit
`f0de87f040621468b956f01f526a43a010310501`). Source: `bitgold-core/`.
This log records the exact dependencies and commands used for the first
build (Phase 1, local regtest proof).

## Machine

- Ubuntu 24.04.5 LTS, Linux 7.0.0-44-generic, AMD EPYC 9D64 (SHA-NI)
- 4 vCPUs visible, cell limit 1.5 shared CPUs; 7.7 GB RAM, 1 GB swap
- g++ 13.3, cmake 3.28.3, git, python3 3.12.3, OpenSSL 3.0.13

## Dependencies installed (via apt, 2026-11-15)

```bash
sudo apt-get install -y \
  libevent-dev libboost-dev libboost-system-dev libboost-filesystem-dev \
  libboost-thread-dev libsqlite3-dev libzmq3-dev libminiupnpc-dev \
  libnatpmp-dev ninja-build ccache lld
```

Versions installed: Boost 1.83, ninja 1.11.1, lld 18.1.3.
(One apt warning about deb.nodesource.com failing to fetch is irrelevant;
the Ubuntu repos supplied everything.)

No extra swap could be created (`swapon` is not permitted in this
container), so the build runs with the existing 1 GB swap.

## Configure

```bash
cd bitgold-core
cmake -B build \
  -DCMAKE_BUILD_TYPE=Release \
  -DBUILD_GUI=OFF \
  -DBUILD_TESTS=OFF \
  -DBUILD_BENCH=OFF \
  -DBUILD_FUZZ_BINARY=OFF \
  -DBUILD_TX=ON \
  -DBUILD_UTIL=ON \
  -DBUILD_WALLET_TOOL=ON \
  -DBUILD_UTIL_CHAINSTATE=OFF \
  -DENABLE_IPC=OFF \
  -DWITH_CCACHE=ON \
  -DCMAKE_LINKER_TYPE=LLD
```

Notes:

- GUI off: the Qt GUI is not built in Phase 1 (no Qt dev packages
  installed; the GUI branding is a Phase-2 item).
- IPC off: multiprocess support needs Cap'n Proto, which is not
  installed. The monolithic `bitgoldd` is the daemon used in Phase 1;
  install `libcapnp-dev` and drop `-DENABLE_IPC=OFF` to build the
  multiprocess `bitgold-node`/`bitgold-gui` binaries later.
- Tests/bench/fuzz off: unit tests are not built in Phase 1. (Note for
  later: `src/test/` still contains Bitcoin-specific expectations, e.g.
  hard-coded genesis hashes and address prefixes, and would need a
  rebrand pass before the test suite can run green.)
- `bitgold-tx`, `bitgold-util`, and `bitgold-wallet` are enabled
  explicitly because they default to following `BUILD_TESTS`.
- `bitgold-chainstate` (experimental, needs the kernel library) is off.
- lld is used for linking: the `bitgoldd` link is the memory peak of
  the build, and lld uses less memory than GNU ld here.
- ccache is on (default) so rebuilds are fast.

## Build

```bash
cmake --build build -j1
```

`-j1` is deliberate: this machine has ~2 GB of usable RAM at build time
and parallel compilation of Bitcoin Core's heaviest translation units
would exhaust it. Expect the build to take a while (single-threaded).

If the `bitgoldd` link runs out of memory with lld, the next things to
try, in order, are: `-DCMAKE_EXE_LINKER_FLAGS=-Wl,--no-keep-memory`
(GNU ld), then building with `-O1` (regtest proof only — never ship
that), then a machine with more RAM. Do not fake a build result.

## Outputs (in `build/src/`)

- `bitgoldd` — the node daemon
- `bitgold-cli` — RPC client
- `bitgold` — multicall wrapper (`bitgold node|rpc|wallet|tx|...`)
- `bitgold-tx`, `bitgold-wallet`, `bitgold-util`
- `bitgold-node` (multiprocess node, built when IPC is enabled)

## First build

- Configured: 2026-11-15 (CMake 3.28.3, Release, `-DENABLE_IPC=OFF`, lld).
- First build: **success, exit 0, ~37 min** (`-j1`, lld link, no OOM).
  All six binaries produced in `build/bin/`: `bitgoldd` (18.5 MB),
  `bitgold-cli`, `bitgold` (wrapper), `bitgold-tx`, `bitgold-wallet`,
  `bitgold-util`.
- Incremental rebuilds after the string/units rebrand (commit `93e908c`):
  all exit 0. The final binaries carry the full rebrand
  (`bitgoldd --version` prints "BitGold Core daemon version v1.0.0
  bitgoldd").
- Build logs: `build.log` (first build), `build2.log`, `build3.log`.
