# SymCrypt, in Rust

Automatically migrated by translating C to Rust via Scylla.

Invocation (adjust sysroot, etc.):

```
../scylla/scylla --ccopts -DSYMCRYPT_IGNORE_PLATFORM,-Iinc,-Ibuild/inc,-std=gnu11,-DSCYLLA inc/symcrypt_internal.h lib/sha3.c lib/sha3_*.c lib/shake.c --errors_as_warnings --output rs/src  --bundle symcrypt_internal
```
