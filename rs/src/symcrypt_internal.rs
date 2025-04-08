#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(unused_assignments)]
#![allow(unreachable_patterns)]
#[derive(PartialEq, Clone, Copy)]
pub struct SYMCRYPT_KECCAK_STATE
{
  pub state: [u64; 25],
  pub inputBlockSize: u32,
  pub stateIndex: u32,
  pub paddingValue: u8,
  pub squeezeMode: u8
}

pub type PSYMCRYPT_KECCAK_STATE <'a> = &'a [SYMCRYPT_KECCAK_STATE];

pub type PCSYMCRYPT_KECCAK_STATE <'a> = &'a [SYMCRYPT_KECCAK_STATE];
