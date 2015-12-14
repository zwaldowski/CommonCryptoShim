/*
 * CommonCryptor.h - Generic interface for symmetric encryption.
 * Copyright (c) 2006-2015 Apple, Inc. All Rights Reserved. Licensed under APSL.
 */

#ifndef _CC_COMMON_CRYPTOR_
#define _CC_COMMON_CRYPTOR_

#include <CommonCrypto/CommonCryptoDefines.h>
#include <CommonCrypto/CommonCryptoError.h>

CC_ASSUME_NONNULL_BEGIN
CC_EXTERN_C_BEGIN

typedef CCStatus CCCryptorStatus;

typedef struct _CCCryptor *CCCryptorRef;

typedef SWIFT_ENUM(uint32_t, CCOperation) {
    kCCEncrypt = 0, 
    kCCDecrypt
};

typedef SWIFT_ENUM(uint32_t, CCAlgorithm) {
    kCCAlgorithmAES128 = 0,
    kCCAlgorithmAES = 0,
    kCCAlgorithmDES,
    kCCAlgorithm3DES CC_SWIFT_NAME(TripleDES),
    kCCAlgorithmCAST,       
    kCCAlgorithmRC4,
    kCCAlgorithmRC2,   
    kCCAlgorithmBlowfish
};

typedef SWIFT_ENUM(uint32_t, CCMode) {
	kCCModeECB                   = 1,
	kCCModeCBC                   = 2,
	kCCModeCFB                   = 3,
	kCCModeCTR                   = 4,
	kCCModeF8 CC_UNIMPLEMENTED   = 5,
	kCCModeLRW CC_UNIMPLEMENTED  = 6,
	kCCModeOFB                   = 7,
	kCCModeXTS                   = 8,
	kCCModeRC4                   = 9,
	kCCModeCFB8                  = 10,
};

typedef SWIFT_ENUM(uint32_t, CCPadding) {
    kCCPaddingNone  = 0,
    kCCPaddingPKCS7 = 1
};

typedef SWIFT_OPTIONS(uint32_t, CCModeOptions) {
	kCCModeOptionCTR_LE = 0x0001,
	kCCModeOptionCTR_BE = 0x0002
};

extern CCCryptorStatus CCCryptorCreateWithMode(CCOperation op, CCMode mode, CCAlgorithm alg, CCPadding padding, const uint8_t *_Nullable iv, const uint8_t *key, size_t keyLength, const uint8_t *_Nullable tweak, size_t tweakLength, int32_t numRounds, CCModeOptions options, CCCryptorRef _Nullable *_Nonnull cryptorRef) CC_AVAILABLE(macosx, 10_7) CC_AVAILABLE(ios, 5_0);

extern CCCryptorStatus CCCryptorRelease(CCCryptorRef cryptorRef) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCCryptorStatus CCCryptorUpdate(CCCryptorRef cryptorRef, const uint8_t *dataIn, size_t dataInLength, uint8_t *dataOut, size_t dataOutAvailable, size_t *dataOutMoved) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCCryptorStatus CCCryptorFinal(CCCryptorRef cryptorRef, uint8_t *dataOut, size_t dataOutAvailable, size_t *dataOutMoved) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCCryptorStatus CCCryptorReset(CCCryptorRef cryptorRef, const uint8_t *_Nullable iv) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern size_t CCCryptorGetOutputLength(CCCryptorRef cryptorRef, size_t inputLength, _Bool final) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

CC_ANON_ENUM(int32_t) {
    kCCBlockSizeAES128    CC_SWIFT_NAME(CCBlockSizeAES128)   = 16,
    kCCBlockSizeDES       CC_SWIFT_NAME(CCBlockSizeDES)      = 8,
    kCCBlockSize3DES      CC_SWIFT_NAME(CCBlockSize3DES)     = 8,
    kCCBlockSizeCAST      CC_SWIFT_NAME(CCBlockSizeCAST)     = 8,
    kCCBlockSizeRC4       CC_SWIFT_NAME(CCBlockSizeRC4)      = 0,
    kCCBlockSizeBlowfish  CC_SWIFT_NAME(CCBlockSizeBlowfish) = 8,
};

CC_ANON_ENUM(int32_t) {
    kCCKeySizeAES128      CC_SWIFT_NAME(CCKeySizeAES128)      = 16,
    kCCKeySizeAES192      CC_SWIFT_NAME(CCKeySizeAES192)      = 24,
    kCCKeySizeAES256      CC_SWIFT_NAME(CCKeySizeAES256)      = 32,
    kCCKeySizeDES         CC_SWIFT_NAME(CCKeySizeDES)         = 8,
    kCCKeySize3DES        CC_SWIFT_NAME(CCKeySize3DES)        = 24,
    kCCKeySizeMinCAST     CC_SWIFT_NAME(CCKeySizeCASTMin)     = 5,
    kCCKeySizeMaxCAST     CC_SWIFT_NAME(CCKeySizeCASTMax)     = 16,
    kCCKeySizeMinRC4      CC_SWIFT_NAME(CCKeySizeRC4Min)      = 1,
    kCCKeySizeMaxRC4      CC_SWIFT_NAME(CCKeySizeRC4Max)      = 512,
    kCCKeySizeMinRC2      CC_SWIFT_NAME(CCKeySizeRC2Min)      = 1,
    kCCKeySizeMaxRC2      CC_SWIFT_NAME(CCKeySizeRC2Max)      = 128,
    kCCKeySizeMinBlowfish CC_SWIFT_NAME(CCKeySizeBlowfishMin) = 8,
    kCCKeySizeMaxBlowfish CC_SWIFT_NAME(CCKeySizeBlowfishMax) = 56,
};

CC_EXTERN_C_END
CC_ASSUME_NONNULL_END

#endif
