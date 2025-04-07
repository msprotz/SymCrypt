#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(unused_assignments)]
#![allow(unreachable_patterns)]
#[derive(PartialEq)]
pub struct SYMCRYPT_KECCAK_STATE <'a>
{
  pub state: &'a mut [u64],
  pub inputBlockSize: u32,
  pub stateIndex: u32,
  pub paddingValue: u8,
  pub squeezeMode: u8
}

pub type PSYMCRYPT_KECCAK_STATE <'a> = &'a [SYMCRYPT_KECCAK_STATE <'a>];

pub type PCSYMCRYPT_KECCAK_STATE <'a> = &'a [SYMCRYPT_KECCAK_STATE <'a>];

#[derive(PartialEq)]
pub struct SYMCRYPT_SHA3_224_STATE <'a>
{ pub ks: SYMCRYPT_KECCAK_STATE <'a>, pub magic: usize }

pub type PSYMCRYPT_SHA3_224_STATE <'a> = &'a [SYMCRYPT_SHA3_224_STATE <'a>];

pub type PCSYMCRYPT_SHA3_224_STATE <'a> = &'a [SYMCRYPT_SHA3_224_STATE <'a>];

#[derive(PartialEq)]
pub struct SYMCRYPT_SHA3_256_STATE <'a>
{ pub ks: SYMCRYPT_KECCAK_STATE <'a>, pub magic: usize }

pub type PSYMCRYPT_SHA3_256_STATE <'a> = &'a [SYMCRYPT_SHA3_256_STATE <'a>];

pub type PCSYMCRYPT_SHA3_256_STATE <'a> = &'a [SYMCRYPT_SHA3_256_STATE <'a>];

#[derive(PartialEq)]
pub struct SYMCRYPT_SHA3_384_STATE <'a>
{ pub ks: SYMCRYPT_KECCAK_STATE <'a>, pub magic: usize }

pub type PSYMCRYPT_SHA3_384_STATE <'a> = &'a [SYMCRYPT_SHA3_384_STATE <'a>];

pub type PCSYMCRYPT_SHA3_384_STATE <'a> = &'a [SYMCRYPT_SHA3_384_STATE <'a>];

#[derive(PartialEq)]
pub struct SYMCRYPT_SHA3_512_STATE <'a>
{ pub ks: SYMCRYPT_KECCAK_STATE <'a>, pub magic: usize }

pub type PSYMCRYPT_SHA3_512_STATE <'a> = &'a [SYMCRYPT_SHA3_512_STATE <'a>];

pub type PCSYMCRYPT_SHA3_512_STATE <'a> = &'a [SYMCRYPT_SHA3_512_STATE <'a>];

#[derive(PartialEq)]
pub struct SYMCRYPT_SHAKE128_STATE <'a>
{ pub ks: SYMCRYPT_KECCAK_STATE <'a>, pub magic: usize }

pub type PSYMCRYPT_SHAKE128_STATE <'a> = &'a [SYMCRYPT_SHAKE128_STATE <'a>];

pub type PCSYMCRYPT_SHAKE128_STATE <'a> = &'a [SYMCRYPT_SHAKE128_STATE <'a>];

#[derive(PartialEq)]
pub struct SYMCRYPT_SHAKE256_STATE <'a>
{ pub ks: SYMCRYPT_KECCAK_STATE <'a>, pub magic: usize }

pub type PSYMCRYPT_SHAKE256_STATE <'a> = &'a [SYMCRYPT_SHAKE256_STATE <'a>];

pub type PCSYMCRYPT_SHAKE256_STATE <'a> = &'a [SYMCRYPT_SHAKE256_STATE <'a>];

#[derive(PartialEq)]
pub struct SYMCRYPT_CSHAKE128_STATE <'a>
{ pub ks: SYMCRYPT_KECCAK_STATE <'a>, pub magic: usize }

pub type PSYMCRYPT_CSHAKE128_STATE <'a> = &'a [SYMCRYPT_CSHAKE128_STATE <'a>];

pub type PCSYMCRYPT_CSHAKE128_STATE <'a> = &'a [SYMCRYPT_CSHAKE128_STATE <'a>];

#[derive(PartialEq)]
pub struct SYMCRYPT_CSHAKE256_STATE <'a>
{ pub ks: SYMCRYPT_KECCAK_STATE <'a>, pub magic: usize }

pub type PSYMCRYPT_CSHAKE256_STATE <'a> = &'a [SYMCRYPT_CSHAKE256_STATE <'a>];

pub type PCSYMCRYPT_CSHAKE256_STATE <'a> = &'a [SYMCRYPT_CSHAKE256_STATE <'a>];
