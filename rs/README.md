# SymCrypt, in Rust

Automatically migrated by translating C to Rust via Scylla.

Invocation (adjust sysroot, etc.):

```
../scylla/scylla --ccopts -isysroot,/opt/homebrew/Cellar/llvm@15/15.0.7/Toolchains/LLVM15.0.7.xctoolchain/,-DSYMCRYPT_IGNORE_PLATFORM,-Iinc,-Ibuild/inc,-std=gnu11,-DSCYLLA inc/symcrypt_internal.h lib/sha3.c --errors_as_warnings
```
