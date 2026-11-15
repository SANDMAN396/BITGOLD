# BitGold genesis blocks — mining results

Message (all networks): `15/Nov/2026 US flights grounded for hours after air traffic control outage`
Shared merkle root (same coinbase on all networks, as in Bitcoin):
`e79fd87366b69d64f6d2b6e39e8cd7052c2866bb730ee91c44951d258fd602d6`
Coinbase: 50 BITGOLD to Satoshi's genesis pubkey (unspendable, a mirror of Bitcoin's genesis).

| Network | nBits | Timestamp (UTC) | Nonce | Genesis hash |
|---|---|---|---|---|
| mainnet | 0x1d00ffff | 1794724824 (2026-11-15 06:40:24) | 1403313620 | `00000000ff64546f2fd9b68319581cc411e075cb1a4d4df84380d00a6d25a5a1` |
| testnet | 0x1d00ffff | 1794724884 (2026-11-15 06:41:24) | 3011183091 | `0000000007f55d05faae8a36c7afb0d24f432473a7b4c82e6ce413f5ca7c868b` |
| testnet4 | 0x1d00ffff | 1794724945 (2026-11-15 06:42:25) | 3579803585 | `00000000dc1d79e95f7ad14648162d6db59fefccfe0b330f6b26e5bb78ed9dfd` |
| signet | 0x1e0377ae | 1794725004 (2026-11-15 06:43:24) | 11714297 | `000002850eb3cc20c5aeb63709b5091c72f40f1ae88ba22f32d889626310c15c` |
| regtest | 0x207fffff | 1794725064 (2026-11-15 06:44:24) | 2 | `60d9d910c28e59e529a06aea432bfc99520410223536c8fdf6bf59313393cfe5` |

Verification: each hash was independently recomputed in Python (double SHA-256 of
the 80-byte header with the found nonce) and confirmed ≤ its nBits target.
Mainnet: 1,403,313,621 hashes in ~11.7 min (~2.0M/s).
Testnet: 3,011,183,092 hashes in ~20.8 min (~2.4M/s).
Testnet4: 7,874,770,882 hashes in ~43.9 min (~3.0M/s) — the full 2^32
nonce range was exhausted at the base timestamp, so the miner rolled
the timestamp forward 1 second (1794724944 → 1794724945) and found it
there (nonce 3,579,803,585 at the new timestamp).
Signet: 11,714,298 hashes in 7.3s. Regtest: 3 hashes.
