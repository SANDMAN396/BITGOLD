# Security Policy

## Supported Versions

BitGold Core 1.0.0 is a local regtest proof only. There is no public
network, no mainnet release, and no version carrying real funds. Do not
run it with real money, and do not trust any BitGold network, wallet, or
exchange that claims to be official — none exists yet.

## Reporting a Vulnerability

**Do not open a public issue for a security problem.** Use GitHub's
private vulnerability reporting on this repository (Security tab →
Report a vulnerability). If private reporting is unavailable, contact
the repository owner directly and wait for a reply before disclosing
anything publicly.

What to include: what is affected, how to reproduce it, and what you
think the impact is. Please do not test a vulnerability against anyone
else's machine or funds.

## Scope

The rebrand diff against upstream Bitcoin Core (Nov 2026) is the highest-value review target —
a mistake there can split the network or strand funds. Reports about
upstream Bitcoin Core code itself should go to the Bitcoin Core
security process instead.

## Ground rules for contributors

- Never commit private keys, seed phrases, wallet files, passwords, or
  API tokens. The signet test keys live outside this repo and must
  never be committed.
- Test transactions use regtest only, with test coins that have no
  value.
- No feature that touches consensus, money handling, or network
  identity merges without review.
