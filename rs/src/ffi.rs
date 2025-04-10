#[no_mangle]
pub extern "C" fn SymCryptSha3_256(
    pb_data: *const u8,
    cbData: usize,
    pb_result: &mut [u8; SHA3_256_RESULT_SIZE],
);

#[no_mangle]
pub extern "C" fn SymCryptSha3_256Init(p_state: &mut HashState);

#[no_mangle]
pub extern "C" fn SymCryptSha3_256Append(p_state: &mut HashState, pb_data: *const u8, cbData: usize);

#[no_mangle]
pub extern "C" fn SymCryptSha3_256Result(p_state: &mut HashState, pb_result: &mut [u8; SHA3_256_RESULT_SIZE]);

#[no_mangle]
pub extern "C" fn SymCryptSha3_256StateCopy(p_src: &HashState, p_dst: &mut HashState);
