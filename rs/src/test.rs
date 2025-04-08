const EXPECTED_HASH: [ u8; 32 ] = [ 0x64, 0x4b, 0xcc, 0x7e, 0x56, 0x43, 0x73, 0x04, 0x09, 0x99, 0xaa, 0xc8,
    0x9e, 0x76, 0x22, 0xf3, 0xca, 0x71, 0xfb, 0xa1, 0xd9, 0x72, 0xfd, 0x94, 0xa3, 0x1c, 0x3b, 0xfb,
    0xf2, 0x4e, 0x39, 0x38 ];

#[allow(dead_code)]
#[test]
pub fn test_sha3() -> Result<(), Box<dyn std::error::Error>> {
    let mut st = [ crate::symcrypt_internal::SYMCRYPT_KECCAK_STATE {
        state: [0u64; 25],
        inputBlockSize: 0,
        stateIndex: 0,
        paddingValue: 0,
        squeezeMode: 0
    } ];
    crate::sha3::SymCryptKeccakReset(&mut st);
    crate::sha3::SymCryptKeccakInit(&mut st, 136, 0x06);
    crate::sha3::SymCryptKeccakAppendBytes(&mut st, "hello world".as_bytes(), 11);
    let mut actual_hash: [u8; 32] = [0; 32];
    crate::sha3::SymCryptKeccakExtract(&mut st, &mut actual_hash, 32, 1);
    assert_eq!(EXPECTED_HASH, actual_hash);
    Ok(())
}
