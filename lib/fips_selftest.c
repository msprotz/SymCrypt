//
// fips_selftest.c - Algorithm selftests for FIPS 140 compliance
//
// Copyright (c) Microsoft Corporation. Licensed under the MIT license.
//

#include "precomp.h"

SYMCRYPT_FIPS_SELFTEST g_SymCryptFipsSelftestsPerformed = SYMCRYPT_SELFTEST_NONE;

const BYTE rgbDh2048Modulus[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC9, 0x0F, 0xDA, 0xA2, 0x21, 0x68, 0xC2, 0x34,
    0xC4, 0xC6, 0x62, 0x8B, 0x80, 0xDC, 0x1C, 0xD1, 0x29, 0x02, 0x4E, 0x08, 0x8A, 0x67, 0xCC, 0x74,
    0x02, 0x0B, 0xBE, 0xA6, 0x3B, 0x13, 0x9B, 0x22, 0x51, 0x4A, 0x08, 0x79, 0x8E, 0x34, 0x04, 0xDD,
    0xEF, 0x95, 0x19, 0xB3, 0xCD, 0x3A, 0x43, 0x1B, 0x30, 0x2B, 0x0A, 0x6D, 0xF2, 0x5F, 0x14, 0x37,
    0x4F, 0xE1, 0x35, 0x6D, 0x6D, 0x51, 0xC2, 0x45, 0xE4, 0x85, 0xB5, 0x76, 0x62, 0x5E, 0x7E, 0xC6,
    0xF4, 0x4C, 0x42, 0xE9, 0xA6, 0x37, 0xED, 0x6B, 0x0B, 0xFF, 0x5C, 0xB6, 0xF4, 0x06, 0xB7, 0xED,
    0xEE, 0x38, 0x6B, 0xFB, 0x5A, 0x89, 0x9F, 0xA5, 0xAE, 0x9F, 0x24, 0x11, 0x7C, 0x4B, 0x1F, 0xE6,
    0x49, 0x28, 0x66, 0x51, 0xEC, 0xE4, 0x5B, 0x3D, 0xC2, 0x00, 0x7C, 0xB8, 0xA1, 0x63, 0xBF, 0x05,
    0x98, 0xDA, 0x48, 0x36, 0x1C, 0x55, 0xD3, 0x9A, 0x69, 0x16, 0x3F, 0xA8, 0xFD, 0x24, 0xCF, 0x5F,
    0x83, 0x65, 0x5D, 0x23, 0xDC, 0xA3, 0xAD, 0x96, 0x1C, 0x62, 0xF3, 0x56, 0x20, 0x85, 0x52, 0xBB,
    0x9E, 0xD5, 0x29, 0x07, 0x70, 0x96, 0x96, 0x6D, 0x67, 0x0C, 0x35, 0x4E, 0x4A, 0xBC, 0x98, 0x04,
    0xF1, 0x74, 0x6C, 0x08, 0xCA, 0x18, 0x21, 0x7C, 0x32, 0x90, 0x5E, 0x46, 0x2E, 0x36, 0xCE, 0x3B,
    0xE3, 0x9E, 0x77, 0x2C, 0x18, 0x0E, 0x86, 0x03, 0x9B, 0x27, 0x83, 0xA2, 0xEC, 0x07, 0xA2, 0x8F,
    0xB5, 0xC5, 0x5D, 0xF0, 0x6F, 0x4C, 0x52, 0xC9, 0xDE, 0x2B, 0xCB, 0xF6, 0x95, 0x58, 0x17, 0x18,
    0x39, 0x95, 0x49, 0x7C, 0xEA, 0x95, 0x6A, 0xE5, 0x15, 0xD2, 0x26, 0x18, 0x98, 0xFA, 0x05, 0x10,
    0x15, 0x72, 0x8E, 0x5A, 0x8A, 0xAC, 0xAA, 0x68, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

const BYTE rgbDh2048Generator[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02
};

const BYTE rgbDh2048PublicKey1[] = 
{
    0xC7, 0xCF, 0x6A, 0xA3, 0x34, 0x61, 0x7A, 0x6B, 0x65, 0x2E, 0xE3, 0x73, 0xD8, 0x59, 0x5E, 0x0C,
    0x35, 0x7D, 0x22, 0x5C, 0xC3, 0x9E, 0x3E, 0xAC, 0x81, 0x85, 0x8C, 0x19, 0x86, 0xCC, 0xB4, 0x33,
    0x26, 0x72, 0x6B, 0xD3, 0xE7, 0x6F, 0x99, 0x7A, 0x65, 0x28, 0x10, 0xC9, 0x75, 0xF2, 0x57, 0x45,
    0xD3, 0x4A, 0x9E, 0x00, 0xB7, 0x8F, 0xA7, 0xDA, 0xBF, 0x1D, 0x5C, 0xBD, 0xF6, 0xEA, 0xAB, 0x66,
    0x25, 0x26, 0x74, 0x67, 0xC5, 0x79, 0xEA, 0x69, 0x56, 0x89, 0x89, 0xCE, 0x11, 0x9F, 0xA1, 0xE3,
    0x0B, 0x61, 0x63, 0x10, 0x89, 0x75, 0x0D, 0xAB, 0x1A, 0x59, 0x5E, 0xEF, 0xDC, 0xDD, 0x24, 0x49,
    0xF3, 0x0C, 0x13, 0x04, 0x60, 0x4C, 0xCD, 0x25, 0x82, 0x07, 0xD5, 0x9B, 0x7A, 0x99, 0x86, 0x86,
    0x4F, 0xC6, 0x43, 0x87, 0x55, 0xB2, 0x52, 0x90, 0x8B, 0xB3, 0xDA, 0x71, 0x51, 0x8D, 0x5A, 0xBD,
    0x24, 0xE1, 0x4E, 0x9B, 0xDF, 0xBB, 0xAD, 0x0F, 0xFF, 0x4A, 0xE8, 0xFA, 0xD8, 0xE7, 0x52, 0x10,
    0x65, 0x91, 0x61, 0x0D, 0x09, 0x09, 0xE2, 0x2E, 0x20, 0xC9, 0x0C, 0x76, 0x61, 0x5E, 0xA7, 0xDA,
    0xD0, 0x08, 0x7A, 0xD7, 0x4F, 0xAD, 0x37, 0x57, 0x45, 0x92, 0x38, 0x83, 0x17, 0xF1, 0x04, 0xA9,
    0x38, 0x45, 0xD2, 0xA6, 0xC0, 0xDA, 0x2B, 0xD0, 0xBA, 0x81, 0xD6, 0xF0, 0x2A, 0x0F, 0x03, 0xD6,
    0xD4, 0x31, 0x54, 0x49, 0x0D, 0x87, 0x04, 0x53, 0x51, 0xED, 0xF1, 0x96, 0x65, 0xEA, 0xA1, 0x28,
    0x60, 0x9D, 0xB7, 0x50, 0xA8, 0x66, 0x22, 0x70, 0x74, 0x51, 0x28, 0x81, 0xB2, 0xCA, 0x37, 0x83,
    0xDC, 0x55, 0x4D, 0xF2, 0xBB, 0xBB, 0xD6, 0x33, 0xA4, 0xD4, 0x2A, 0x01, 0xEF, 0xD8, 0xDA, 0xC2,
    0xE1, 0x20, 0xD8, 0xAE, 0x41, 0xEF, 0x5A, 0x63, 0x0D, 0x2B, 0x05, 0xD2, 0x21, 0xCC, 0x2A, 0xCC
};

const BYTE rgbDh2048PrivateKey1[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x5A, 0x39, 0xD6, 0x42, 0xB3, 0xEE, 0xD0, 0x12, 0x2C, 0x47, 0xB3, 0x52, 0xC1, 0xC5, 0x00,
    0x21, 0xAD, 0x3F, 0x1B, 0xFA, 0x3D, 0x9A, 0xD3, 0x6D, 0x28, 0x5C, 0xDE, 0x08, 0xA5, 0xA5, 0xF6,
    0xCA, 0xD0, 0x22, 0xD1, 0x4F, 0x85, 0xF4, 0x49, 0x9F, 0x04, 0x84, 0x8D, 0x72, 0xEA, 0xD8, 0x3F,
    0xE4, 0x2E, 0xE1, 0xF8, 0xE4, 0x7C, 0x4F, 0xDC, 0x16, 0xF6, 0x3D, 0x28, 0x2E, 0x79, 0x8F, 0xC5
};

const BYTE rgbDh2048PublicKey2[] = 
{
    0x4F, 0x43, 0xD9, 0x96, 0x07, 0xFE, 0x75, 0x0A, 0xB9, 0x70, 0x6A, 0x45, 0xB9, 0xCF, 0xA6, 0xA9,
    0x1D, 0x56, 0x7A, 0x2A, 0x87, 0xA1, 0xE6, 0xFF, 0x77, 0xDD, 0x9E, 0x87, 0x45, 0x1E, 0xEC, 0x8D,
    0x6A, 0x31, 0x84, 0xB9, 0x79, 0x9A, 0x1E, 0xFE, 0xEF, 0x4C, 0x3A, 0xF8, 0xA0, 0xEB, 0xCE, 0xA4,
    0x8A, 0xA1, 0x93, 0x55, 0x54, 0x2B, 0x52, 0x9E, 0xF3, 0xE0, 0x61, 0x42, 0x8E, 0x77, 0x7E, 0x2C,
    0xB7, 0x6A, 0xC1, 0x1F, 0xB2, 0xAF, 0x63, 0x48, 0xDC, 0xB6, 0x5D, 0xCB, 0x6B, 0x73, 0xD8, 0x39,
    0x88, 0xFC, 0xC0, 0xCA, 0x90, 0x0A, 0x47, 0x84, 0xA2, 0xC8, 0xB7, 0x43, 0x63, 0x19, 0x4B, 0x8F,
    0x1E, 0x06, 0x77, 0x75, 0x94, 0xF4, 0xD5, 0x50, 0x4B, 0x32, 0xA4, 0xB8, 0xC2, 0xF0, 0xA3, 0xE1,
    0xED, 0x08, 0x7B, 0x52, 0xFF, 0x6D, 0x99, 0xD2, 0x93, 0xD1, 0x7F, 0xA8, 0xF3, 0x01, 0x2D, 0x0B,
    0x4E, 0x51, 0xA3, 0x23, 0x7E, 0xC1, 0x97, 0x30, 0x15, 0xF2, 0xEC, 0x4C, 0x29, 0x0D, 0xEF, 0xF5,
    0xCA, 0x02, 0x0F, 0x46, 0x56, 0xF5, 0xC6, 0xE0, 0x82, 0xBB, 0x4F, 0x9C, 0xC3, 0x35, 0x04, 0x4A,
    0x58, 0x63, 0xA4, 0x4E, 0x23, 0x1B, 0x86, 0xA2, 0x1D, 0x1F, 0x7A, 0x34, 0x3B, 0x9C, 0x81, 0x2F,
    0x9E, 0xFF, 0x9B, 0x32, 0x6B, 0x18, 0x9C, 0xAA, 0xC4, 0x0E, 0x63, 0xAD, 0x56, 0x4A, 0x3A, 0x02,
    0x3F, 0xE9, 0x8A, 0xA1, 0x87, 0xF9, 0xCE, 0x39, 0xEB, 0x47, 0x3A, 0xC2, 0x82, 0x65, 0x7D, 0xC6,
    0x52, 0x33, 0x8B, 0x56, 0xCB, 0x18, 0xD9, 0x08, 0x13, 0xA1, 0xC8, 0x4D, 0xB2, 0x93, 0x1F, 0x4F,
    0x81, 0xBF, 0xD6, 0x5F, 0x58, 0x39, 0x2D, 0xE9, 0xF3, 0x44, 0xC1, 0x46, 0x48, 0x2E, 0xC3, 0x59,
    0xAD, 0xC4, 0x40, 0xED, 0x8D, 0x2C, 0xC4, 0x62, 0x43, 0xA8, 0x42, 0xE1, 0x72, 0xAC, 0xDE, 0x11
};

const BYTE rgbDh2048PrivateKey2[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xCE, 0x80, 0x11, 0x1E, 0x79, 0xCA, 0xBC, 0x8E, 0xBE, 0x82, 0x57, 0xF9, 0x13, 0x17, 0x89, 0x47,
    0xE7, 0xED, 0x1A, 0x0A, 0x29, 0x8E, 0x7A, 0x40, 0xB5, 0xF4, 0x1E, 0xF0, 0x4B, 0x13, 0x28, 0x77,
    0x9B, 0xBF, 0x15, 0xFE, 0xD4, 0xF2, 0x4B, 0x2A, 0x65, 0x40, 0x64, 0xC3, 0x75, 0x16, 0xF8, 0x21,
    0x30, 0x47, 0x08, 0x55, 0x94, 0xD7, 0x4B, 0x9A, 0x26, 0x38, 0xAC, 0x71, 0x44, 0x39, 0x64, 0x8F
};

typedef struct _SYMCRYPT_SELFTEST_ECKEY_P256
{
    BYTE Qx[32];
    BYTE Qy[32];
    BYTE d[32];
} SYMCRYPT_SELFTEST_ECKEY_P256;

const SYMCRYPT_SELFTEST_ECKEY_P256 eckey1 =
{
    // Qx
    {
        0xdd, 0xd5, 0x15, 0x20, 0x43, 0x8d, 0x41, 0xa9,
        0x18, 0xcf, 0x62, 0xc2, 0x13, 0xf7, 0xed, 0xb2,
        0xf9, 0x8f, 0x02, 0xa3, 0x78, 0x30, 0x7e, 0x22,
        0x8f, 0xc1, 0x44, 0xbe, 0xde, 0xc6, 0x65, 0x91
    },
    //Qy
    {
        0x72, 0xad, 0x17, 0xad, 0x51, 0x8c, 0xd3, 0x60,
        0x0f, 0x54, 0xc0, 0xf4, 0xc3, 0x22, 0x5b, 0x44,
        0xab, 0xad, 0x28, 0xb5, 0x56, 0x8e, 0x78, 0x0a,
        0x6a, 0x09, 0x6b, 0x65, 0x81, 0x6d, 0x6f, 0x99
    },
    //d
    {
        0x07, 0x36, 0x9f, 0xb2, 0x35, 0xce, 0xe2, 0xd4,
        0x7e, 0x13, 0x35, 0x31, 0xae, 0xa5, 0x6e, 0x6c,
        0x96, 0xd3, 0x9f, 0x3b, 0xa7, 0x74, 0xae, 0xf9,
        0x7a, 0x56, 0x6e, 0xfe, 0x32, 0x3f, 0x43, 0xaa
    },
};

const SYMCRYPT_SELFTEST_ECKEY_P256 eckey2 =
{
    //Qx
    {
        0x21, 0xf2, 0xf7, 0x08, 0x8c, 0x71, 0x59, 0xa7,
        0x0c, 0xe1, 0xb9, 0x1a, 0xe0, 0xed, 0x69, 0xbe,
        0x44, 0xeb, 0xa3, 0x51, 0xfd, 0x32, 0x4a, 0x90,
        0xdc, 0xde, 0xa4, 0x10, 0xe4, 0x44, 0x69, 0x29
    },
    //Qy
    {
        0x74, 0xd0, 0xc6, 0xbd, 0xe5, 0x13, 0x68, 0x07,
        0x9f, 0x40, 0x5e, 0xbf, 0x9e, 0x61, 0x7c, 0x3f,
        0xc8, 0x16, 0xe2, 0xd5, 0x0e, 0xf8, 0x09, 0x15,
        0xf3, 0x30, 0xba, 0x45, 0x25, 0xab, 0x9a, 0xae
    },
    //d
    {
        0xd0, 0x93, 0xf2, 0x34, 0x82, 0x39, 0xa6, 0x5c,
        0xd7, 0xe5, 0x10, 0x27, 0x0f, 0xfc, 0x0a, 0x0d,
        0x89, 0x97, 0x10, 0xa7, 0x50, 0x5a, 0xc4, 0x1b,
        0x5d, 0x18, 0x03, 0x2f, 0x7d, 0x46, 0x58, 0x4d
    }
};

// Hashed from: {0x61, 0x62, 0x63} using SHA256
const BYTE rgbRsaSignVerifyHash[] =
{
   0xba, 0x78, 0x16, 0xbf, 0x8f, 0x01, 0xcf, 0xea, 
   0x41, 0x41, 0x40, 0xde, 0x5d, 0xae, 0x22, 0x23,
   0xb0, 0x03, 0x61, 0xa3, 0x96, 0x17, 0x7a, 0x9c,
   0xb4, 0x10, 0xff, 0x61, 0xf2, 0x00, 0x15, 0xad
};

//
// KAT from http://csrc.nist.gov/cryptval/dss/RSAExample.zip.
//
typedef struct _SYMCRYPT_SELFTEST_RSAKEY_2048
{
    UINT64 publicExp;
    BYTE modulus[256];
    BYTE prime1[128];
    BYTE prime2[128];
} SYMCRYPT_SELFTEST_RSAKEY_2048;

const SYMCRYPT_SELFTEST_RSAKEY_2048 rsakey =
{
    // publicExp
    0x3,
    // modulus
    {
        0x8f, 0xf3, 0x13, 0xb3, 0xad, 0xd8, 0x83, 0xd8,
        0x82, 0x2f, 0x46, 0xe1, 0x5e, 0x43, 0x6e, 0x38,
        0x7d, 0xa7, 0x84, 0xd3, 0x5e, 0xb4, 0x91, 0x2b,
        0x87, 0x89, 0x95, 0x30, 0x0b, 0x04, 0xdd, 0xe7,
        0x21, 0x6d, 0x24, 0xaf, 0xbe, 0x57, 0x0a, 0x0d,
        0x6a, 0x10, 0xd9, 0xa1, 0xf6, 0x02, 0x03, 0xd1,
        0x7e, 0x4d, 0xdb, 0xda, 0xa4, 0x96, 0x4c, 0x61,
        0x41, 0xfb, 0xbd, 0xc7, 0x2c, 0xd9, 0x30, 0xdb,
        0x0a, 0x43, 0x6d, 0x41, 0xce, 0x28, 0xad, 0xaf,
        0xbe, 0x94, 0x55, 0x39, 0x95, 0x94, 0xfc, 0x9a,
        0x8b, 0x80, 0x25, 0x4b, 0xf7, 0xdc, 0x8c, 0xfb,
        0xce, 0x92, 0xcf, 0x7a, 0xd7, 0x5e, 0x0f, 0x12,
        0x5d, 0xca, 0x5a, 0xaf, 0x94, 0xcf, 0x13, 0x99,
        0x7c, 0xb2, 0x71, 0x81, 0x73, 0x4c, 0xbd, 0x56,
        0x7c, 0x55, 0xc3, 0x73, 0xa4, 0x74, 0xac, 0xb8,
        0xb5, 0x6f, 0xdd, 0x54, 0x3b, 0x97, 0x8a, 0x3a,
        0x72, 0xe0, 0xb3, 0x8d, 0x5a, 0xb4, 0xd8, 0x54,
        0x3d, 0xc1, 0x9f, 0x69, 0x7f, 0xc0, 0x30, 0x1e,
        0xd6, 0xb5, 0x4f, 0xcd, 0xe5, 0xdd, 0x68, 0x08,
        0x93, 0x92, 0x1f, 0x9f, 0xe3, 0x23, 0x84, 0x12,
        0xc9, 0xbb, 0xa5, 0xb8, 0x53, 0x14, 0x8b, 0xe0,
        0xa4, 0x93, 0x97, 0x89, 0x05, 0x16, 0xb2, 0xc8,
        0x70, 0x2a, 0xc8, 0x46, 0xcd, 0x92, 0x43, 0xad,
        0x6a, 0x35, 0x3e, 0x84, 0xcc, 0xbf, 0xa7, 0xfe,
        0x79, 0x9e, 0xf4, 0xc3, 0x7d, 0xde, 0x97, 0xa0,
        0x25, 0x7f, 0x93, 0x9c, 0xbc, 0x14, 0xce, 0xd6,
        0xd8, 0x6c, 0x47, 0x0f, 0xc9, 0x88, 0xd4, 0x35,
        0x05, 0x87, 0x83, 0xf8, 0xcb, 0xd8, 0xa6, 0x7e,
        0xd2, 0xd8, 0xcd, 0xe7, 0x1c, 0x6e, 0x74, 0xdd,
        0xc6, 0x49, 0xe5, 0x6f, 0x51, 0xc6, 0x29, 0x2a,
        0x15, 0xc1, 0xff, 0xbd, 0x85, 0x6e, 0xe1, 0x5f,
        0x49, 0xda, 0xcc, 0xbb, 0x74, 0x2a, 0x8a, 0xb9
    },
    // prime1
    {
        0xc8, 0x23, 0xbd, 0x5e, 0x64, 0x04, 0xba, 0xc4,
        0x51, 0x1d, 0x15, 0x05, 0xdc, 0xd1, 0x33, 0x3c,
        0xc3, 0xbe, 0xca, 0x9a, 0x7f, 0x43, 0x50, 0x0b,
        0x61, 0x3f, 0xb4, 0x16, 0xe0, 0x1c, 0x4b, 0x05,
        0x32, 0x0d, 0x0d, 0x47, 0x19, 0x93, 0x01, 0x12,
        0x00, 0x46, 0xf6, 0x4d, 0x46, 0xd2, 0x74, 0xac,
        0xda, 0x40, 0xf2, 0x1d, 0x08, 0x77, 0x49, 0x63,
        0x92, 0x02, 0x69, 0x00, 0x03, 0x13, 0x4b, 0x59,
        0x40, 0xc8, 0x27, 0x15, 0x60, 0xae, 0xe6, 0xc6,
        0xbd, 0x84, 0xda, 0xcb, 0x4b, 0x41, 0xad, 0x75,
        0x29, 0x58, 0x97, 0x68, 0x76, 0x3a, 0xd4, 0x44,
        0x66, 0x1c, 0x56, 0x85, 0x95, 0xfb, 0xb7, 0xa8,
        0x9b, 0xde, 0x71, 0x90, 0xe0, 0x63, 0x64, 0xdf,
        0xff, 0xc6, 0xe5, 0x2d, 0x5d, 0x87, 0x73, 0x94,
        0x61, 0x89, 0x23, 0x3b, 0x8f, 0x38, 0xdf, 0x67,
        0x14, 0x2b, 0x0a, 0x79, 0x61, 0x2d, 0xed, 0x0f
    },
    // prime2
    {
        0xb8, 0x20, 0x79, 0xad, 0x07, 0x09, 0x04, 0x80,
        0x78, 0x39, 0x24, 0x4a, 0xd8, 0x1f, 0xa3, 0x82,
        0x51, 0x8c, 0x18, 0x31, 0x5e, 0x5c, 0x00, 0xae,
        0x82, 0x58, 0x10, 0xac, 0x3a, 0x5b, 0xca, 0x77,
        0x30, 0xb4, 0x4f, 0x7b, 0xb1, 0xcc, 0x74, 0x06,
        0x61, 0x09, 0x17, 0x4f, 0x2e, 0xf1, 0xb4, 0xb6,
        0x82, 0x93, 0x33, 0x4d, 0xbd, 0x22, 0x04, 0x98,
        0xe2, 0xe4, 0x6e, 0x91, 0x90, 0x4a, 0x24, 0xef,
        0x35, 0x61, 0x1a, 0xa8, 0x7e, 0x69, 0x96, 0xb5,
        0x12, 0xc2, 0x8a, 0x15, 0x7f, 0x10, 0x21, 0x14,
        0x74, 0x97, 0x98, 0xcd, 0x32, 0xe7, 0x4f, 0xee,
        0x3d, 0xbe, 0x20, 0xbb, 0x57, 0x2a, 0xef, 0x56,
        0xae, 0xee, 0x82, 0x3d, 0x55, 0x35, 0xb3, 0x87,
        0x46, 0x96, 0x01, 0xd7, 0x83, 0x40, 0xfd, 0x94,
        0x0d, 0x2f, 0xe3, 0xe0, 0x92, 0x42, 0x02, 0xe7,
        0xbf, 0x02, 0xc1, 0x0f, 0xd1, 0x52, 0x9b, 0xb7
    }
};

const BYTE rgbKnownSignature [] = 
{
    0x8c, 0x01, 0x48, 0x38, 0x1a, 0x8f, 0xa9, 0xae,
    0x55, 0xa6, 0xad, 0x04, 0x5f, 0x78, 0x1a, 0xf5,
    0xae, 0xf4, 0x09, 0x5d, 0x9c, 0x3a, 0xe2, 0x13,
    0xf2, 0x04, 0xd8, 0x8a, 0xf7, 0x58, 0x4f, 0xe5,
    0xb0, 0xcc, 0xea, 0xd8, 0xd0, 0xc4, 0x57, 0xd1,
    0x9e, 0x61, 0xa8, 0x62, 0xb3, 0x39, 0x03, 0xf6,
    0x13, 0x45, 0x6f, 0x88, 0x1a, 0x14, 0x33, 0x07,
    0x20, 0x17, 0xab, 0xe1, 0x00, 0x93, 0x69, 0x03,
    0x37, 0x69, 0xbb, 0x0e, 0x0f, 0x63, 0x57, 0xed,
    0xb7, 0x56, 0x3a, 0x5d, 0xf1, 0x93, 0xd3, 0x76,
    0x90, 0xf3, 0xed, 0x25, 0x6f, 0xc5, 0xc8, 0xcb,
    0x1a, 0xd7, 0xce, 0x02, 0x80, 0x28, 0xa3, 0x5f,
    0x02, 0x6b, 0xf1, 0xfa, 0x94, 0x08, 0xbb, 0x79,
    0xfd, 0x51, 0x37, 0xf1, 0x48, 0xe9, 0x55, 0xaa,
    0x0f, 0xb0, 0xaf, 0x5d, 0x5f, 0xe9, 0x28, 0x7f,
    0xb2, 0x67, 0x96, 0x6d, 0x91, 0x7c, 0x98, 0x0d,
    0x60, 0x27, 0xea, 0x62, 0xf5, 0x22, 0x60, 0x0a,
    0xbd, 0xfe, 0x9d, 0xd5, 0x96, 0xa6, 0x02, 0xbb,
    0x6c, 0x51, 0x36, 0x74, 0x92, 0x23, 0xb9, 0x4b,
    0x87, 0xf4, 0xef, 0x2b, 0x00, 0x34, 0xe3, 0xfb,
    0x10, 0x1b, 0xcc, 0xab, 0xc4, 0xe5, 0xda, 0x27,
    0xf5, 0xf2, 0x55, 0x18, 0x65, 0x59, 0x8b, 0xed,
    0x8e, 0x52, 0x78, 0x5a, 0xc7, 0x4b, 0x6b, 0x1b,
    0x66, 0x67, 0xe6, 0xc0, 0xd7, 0x5a, 0x2a, 0xab,
    0xce, 0x1d, 0xf2, 0xdf, 0x92, 0xe0, 0xdb, 0xf7,
    0x34, 0xe3, 0x05, 0x10, 0xe4, 0x13, 0x7b, 0x29,
    0x14, 0xa5, 0x41, 0xcb, 0x6e, 0x81, 0x33, 0xd0,
    0xf9, 0x93, 0xa8, 0x85, 0xd1, 0xf4, 0xea, 0xfc,
    0xaf, 0x5d, 0x7b, 0xc7, 0xf4, 0xff, 0x6c, 0x1e,
    0x76, 0x18, 0xc6, 0x09, 0xe9, 0x8a, 0xa4, 0x57,
    0xe6, 0x6b, 0x3e, 0x32, 0x36, 0xb4, 0xfd, 0x6a,
    0xea, 0x87, 0xe0, 0xe6, 0x42, 0x3e, 0xdc, 0x58
};

VOID
SYMCRYPT_CALL
SymCryptDhSecretAgreementSelftest()
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    PSYMCRYPT_DLGROUP pDlgroup = NULL;
    PSYMCRYPT_DLKEY pkKey1 = NULL;
    PSYMCRYPT_DLKEY pkKey2 = NULL;

    BYTE rgbSecret1[sizeof(rgbDh2048PublicKey1)];
    BYTE rgbSecret2[sizeof(rgbDh2048PublicKey1)];

    pDlgroup = SymCryptDlgroupAllocate( sizeof(rgbDh2048PublicKey1) * 8, 0 );
    SYMCRYPT_FIPS_ASSERT(pDlgroup != NULL);

    scError = SymCryptDlgroupSetValue(
        rgbDh2048Modulus,
        sizeof(rgbDh2048Modulus),
        NULL, // pbPrimeQ
        0,  // cbPrimeQ
        rgbDh2048Generator,
        sizeof(rgbDh2048Generator),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        NULL, // pHashAlgorithm
        NULL, // pbSeed
        0, // cbSeed
        0, // genCounter
        SYMCRYPT_DLGROUP_FIPS_NONE,
        pDlgroup);
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    pkKey1 = SymCryptDlkeyAllocate( pDlgroup );
    SYMCRYPT_FIPS_ASSERT( pkKey1 != NULL );

    scError = SymCryptDlkeySetValue(
        rgbDh2048PrivateKey1,
        sizeof(rgbDh2048PrivateKey1),
        rgbDh2048PublicKey1,
        sizeof(rgbDh2048PublicKey1),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0,
        pkKey1 );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    pkKey2 = SymCryptDlkeyAllocate( pDlgroup );
    SYMCRYPT_FIPS_ASSERT( pkKey2 != NULL );

    scError = SymCryptDlkeySetValue(
        rgbDh2048PrivateKey2,
        sizeof(rgbDh2048PrivateKey2),
        rgbDh2048PublicKey2,
        sizeof(rgbDh2048PublicKey2),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0,
        pkKey2 );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Calculate secret 1 using private key 1 and public key 2
    scError = SymCryptDhSecretAgreement(
        pkKey1,
        pkKey2,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_FLAG_BYPASS_FIPS_SELFTEST,
        rgbSecret1,
        sizeof(rgbSecret1) );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Calculate secret 2 using private key 2 and public key 1
    scError = SymCryptDhSecretAgreement(
        pkKey2,
        pkKey1,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_FLAG_BYPASS_FIPS_SELFTEST,
        rgbSecret2,
        sizeof(rgbSecret2) );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Verify that secret1 == secret2
    SYMCRYPT_FIPS_ASSERT( memcmp( rgbSecret1, rgbSecret2, sizeof(rgbSecret1) ) == 0 );

    SymCryptDlkeyFree( pkKey2 );
    SymCryptDlkeyFree( pkKey1 );
    SymCryptDlgroupFree( pDlgroup );
}

VOID
SYMCRYPT_CALL
SymCryptEcDhSecretAgreementSelftest( )
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    PSYMCRYPT_ECURVE pCurve = NULL;
    PSYMCRYPT_ECKEY pkKey1 = NULL;
    PSYMCRYPT_ECKEY pkKey2 = NULL;

    BYTE rgbSecret1[SymCryptEcurveParamsNistP256->cbFieldLength];
    BYTE rgbSecret2[SymCryptEcurveParamsNistP256->cbFieldLength];
    UINT32 cbSecret = 0;

    pCurve = SymCryptEcurveAllocate( SymCryptEcurveParamsNistP256, 0 );
    SYMCRYPT_FIPS_ASSERT( pCurve != NULL );

    pkKey1 = SymCryptEckeyAllocate( pCurve );
    SYMCRYPT_FIPS_ASSERT( pkKey1 != NULL );

    scError = SymCryptEckeySetValue(
        eckey1.d,
        sizeof(eckey1.d),
        eckey1.Qx,
        sizeof(eckey1.Qx) + sizeof(eckey1.Qy),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_ECPOINT_FORMAT_XY,
        0, // flags
        pkKey1);
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    pkKey2 = SymCryptEckeyAllocate( pCurve );
    SYMCRYPT_FIPS_ASSERT( pkKey2 != NULL );

    scError = SymCryptEckeySetValue(
        eckey2.d,
        sizeof(eckey2.d),
        eckey2.Qx,
        sizeof(eckey2.Qx) + sizeof(eckey2.Qy),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_ECPOINT_FORMAT_XY,
        0, // flags
        pkKey2);
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Calculate secret 1 using private key 1 and public key 2
    scError = SymCryptEcDhSecretAgreement(
        pkKey1,
        pkKey2,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_FLAG_BYPASS_FIPS_SELFTEST,
        rgbSecret1,
        sizeof(rgbSecret1));
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Calculate secret 2 using private key 2 and public key 1
    scError = SymCryptEcDhSecretAgreement(
        pkKey2,
        pkKey1,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_FLAG_BYPASS_FIPS_SELFTEST,
        rgbSecret2,
        sizeof(rgbSecret2));
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Verify secret 1 == secret 2
    SYMCRYPT_FIPS_ASSERT( memcmp(rgbSecret1, rgbSecret2, sizeof(rgbSecret1)) == 0 );

    SymCryptEckeyFree( pkKey2 );
    SymCryptEckeyFree( pkKey1 );
    SymCryptEcurveFree( pCurve );
}

VOID
SYMCRYPT_CALL
SymCryptDsaPairwiseSelftest(
    _In_ PCSYMCRYPT_DLKEY pkCallerKey )
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    BYTE rbHashValue[SYMCRYPT_SHA256_RESULT_SIZE];
    SIZE_T cbHashValue = sizeof(rbHashValue);

    PBYTE pbSignature = NULL;
    SIZE_T cbSignature = 0;

    scError = SymCryptCallbackRandom( rbHashValue, cbHashValue );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    cbSignature = 2 * SymCryptDlkeySizeofPrivateKey( pkCallerKey );
    pbSignature = SymCryptCallbackAlloc( cbSignature );
    SYMCRYPT_FIPS_ASSERT( pbSignature != NULL );

    scError = SymCryptDsaSign(
                pkCallerKey,
                rbHashValue,
                cbHashValue,
                SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
                0,
                pbSignature,
                cbSignature );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    scError = SymCryptDsaVerify(
                pkCallerKey,
                rbHashValue,
                cbHashValue,
                pbSignature,
                cbSignature,
                SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
                0 );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    SymCryptCallbackFree( pbSignature );
}

VOID
SYMCRYPT_CALL
SymCryptEcDsaPairwiseSelftest( )
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    PSYMCRYPT_ECURVE pCurve = NULL;
    PSYMCRYPT_ECKEY pkEckey = NULL;

    BYTE rgbHashValue[SYMCRYPT_SHA256_RESULT_SIZE];
    BYTE rgbSignature[2 * SymCryptEcurveParamsNistP256->cbFieldLength];

    pCurve = SymCryptEcurveAllocate( SymCryptEcurveParamsNistP256, 0 );
    SYMCRYPT_FIPS_ASSERT( pCurve != NULL );

    pkEckey = SymCryptEckeyAllocate( pCurve );
    SYMCRYPT_FIPS_ASSERT( pkEckey != NULL );

    scError = SymCryptEckeySetValue(
        eckey1.d,
        sizeof(eckey1.d),
        eckey1.Qx,
        sizeof(eckey1.Qx) + sizeof(eckey1.Qy),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_ECPOINT_FORMAT_XY,
        0, // flags
        pkEckey);
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    scError = SymCryptCallbackRandom( rgbHashValue, sizeof(rgbHashValue) );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    scError = SymCryptEcDsaSign(
        pkEckey,
        rgbHashValue,
        sizeof(rgbHashValue),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0,
        rgbSignature,
        sizeof(rgbSignature) );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    scError = SymCryptEcDsaVerify(
        pkEckey,
        rgbHashValue,
        sizeof(rgbHashValue),
        rgbSignature,
        sizeof(rgbSignature),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0 );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR )

    SymCryptEckeyFree( pkEckey );
    SymCryptEcurveFree( pCurve );
}

VOID
SYMCRYPT_CALL
SymCryptRsaPairwiseSelftest( )
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    PSYMCRYPT_RSAKEY pkRsakey = NULL;
    SYMCRYPT_RSA_PARAMS rsaParams = { 0 };

    rsaParams.version = 1;
    rsaParams.nBitsOfModulus = sizeof(rsakey.modulus) * 8;
    rsaParams.nPrimes = 2;
    rsaParams.nPubExp = 1;

    BYTE rgbSignature[sizeof(rsakey.modulus)];
    SIZE_T cbSignature = sizeof(rgbSignature);

    PCBYTE pbPrimes[] = { rsakey.prime1, rsakey.prime2 };
    SIZE_T cbPrimes[] = { sizeof(rsakey.prime1), sizeof(rsakey.prime2) };

    pkRsakey = SymCryptRsakeyAllocate( &rsaParams, 0 );
    SYMCRYPT_FIPS_ASSERT( pkRsakey != NULL );

    scError = SymCryptRsakeySetValue(
        rsakey.modulus,
        sizeof(rsakey.modulus),
        &rsakey.publicExp,
        1,
        pbPrimes,
        cbPrimes,
        sizeof(cbPrimes) / sizeof(cbPrimes[0]),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0,
        pkRsakey );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    scError = SymCryptRsaPkcs1Sign(
        pkRsakey,
        rgbRsaSignVerifyHash,
        sizeof(rgbRsaSignVerifyHash),
        SymCryptSha256OidList,
        SYMCRYPT_SHA256_OID_COUNT,
        0,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        rgbSignature,
        cbSignature,
        &cbSignature );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    SYMCRYPT_FIPS_ASSERT( cbSignature == sizeof(rgbKnownSignature) );
    SYMCRYPT_FIPS_ASSERT( memcmp(rgbSignature, rgbKnownSignature, cbSignature ) == 0);

    scError = SymCryptRsaPkcs1Verify(
        pkRsakey,
        rgbRsaSignVerifyHash,
        sizeof(rgbRsaSignVerifyHash),
        rgbSignature,
        cbSignature,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SymCryptSha256OidList,
        SYMCRYPT_SHA256_OID_COUNT,
        0 );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    SymCryptRsakeyFree( pkRsakey );
}