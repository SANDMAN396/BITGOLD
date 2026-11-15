# BitGold Core

**BitGold is a fork of [Bitcoin Core](https://github.com/bitcoin/bitcoin)
(v32.1, merged forward onto upstream master 2026-11-13) — Satoshi Nakamoto's Bitcoin system, mirrored exactly, as its own
standalone chain.** Same consensus rules (21M cap, 50-coin starting reward,
halving every 210,000 blocks, difficulty retarget every 2,016 blocks,
10-minute blocks, double SHA-256 proof of work), same transaction format,
same validation. Only the identity changes: the name (BitGold / BITGOLD),
a new genesis block, and network parameters (magic bytes, ports, address
prefixes) so BitGold can never be confused with Bitcoin.

See [BITGOLD_CHAIN.md](BITGOLD_CHAIN.md) for every parameter changed,
the genesis block, and how to build and run a local regtest chain.

BitGold Core is released under the MIT license (see [COPYING](COPYING)).
Attribution to Satoshi Nakamoto and the Bitcoin Core developers is kept
throughout; the original Bitcoin Core README follows below.

## Status

Phase 1 is done and proven locally: the fork builds, two nodes peered on a
private regtest network, 151 blocks mined, a 10 BITGOLD payment sent and
confirmed, and the reward halving verified. There is **no public network
yet, no real funds, and no launch date**. Nothing here is ready for
mainnet use. See [BITGOLD_CHAIN.md](BITGOLD_CHAIN.md) for what remains.

## How to help

Help is welcome — always with security first. The best places to start:

- **Test transactions** — run the regtest steps in
  [BITGOLD_CHAIN.md](BITGOLD_CHAIN.md), send test payments, and report
  what breaks. Test money only, never real funds.
- **Mining** — mine regtest blocks, try the CPU miner path, and help
  work out fair, honest mining guidance for a future public testnet.
- **Seed nodes** — help design the seed-node and DNS-seed setup so a
  public network can bootstrap itself one day.
- **Tests & GUI** — the test suite still needs a rebrand pass (8 files
  expect Bitcoin's values), and the GUI still shows Bitcoin's artwork.
- **Security review** — read the rebrand diff (96 files vs Bitcoin
  Core v32.1) and report problems privately, never in a public issue —
  see [SECURITY.md](SECURITY.md).

Open an [issue](../../issues) to pick up a task or propose one, and keep
every discussion honest about the status above: local proof only, no
launch yet.

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
