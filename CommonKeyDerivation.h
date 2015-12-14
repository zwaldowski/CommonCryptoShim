/*
 * CommonKeyDerivation.h - Derive a key from a text password/passphrase.
 * Copyright (c) 2010-2015 Apple, Inc. All Rights Reserved. Licensed under APSL.
 */

#ifndef _CC_PBKDF_H_
#define _CC_PBKDF_H_

#include <CommonCrypto/CommonCryptoDefines.h>
#include <CommonCrypto/CommonCryptoError.h>
#include <CommonCrypto/CommonDigest.h>
#include <CommonCrypto/CommonHMAC.h>

CC_ASSUME_NONNULL_BEGIN
CC_EXTERN_C_BEGIN

typedef SWIFT_ENUM(uint32_t, CCPBKDFAlgorithm) {
    kCCPBKDF2 CC_SWIFT_NAME(PBKDF2) = 2,
};
    
typedef SWIFT_ENUM(uint32_t, CCPseudoRandomAlgorithm) {
    kCCPRFHmacAlgSHA1   CC_SWIFT_NAME(SHA1)   = 1,
    kCCPRFHmacAlgSHA224 CC_SWIFT_NAME(SHA224) = 2,
    kCCPRFHmacAlgSHA256 CC_SWIFT_NAME(SHA256) = 3,
    kCCPRFHmacAlgSHA384 CC_SWIFT_NAME(SHA384) = 4,
    kCCPRFHmacAlgSHA512 CC_SWIFT_NAME(SHA512) = 5,
};

extern CCStatus CCKeyDerivationPBKDF(CCPBKDFAlgorithm algorithm, const uint8_t *password, size_t passwordLen, const uint8_t *salt, size_t saltLen, CCPseudoRandomAlgorithm prf, uint32_t rounds, uint8_t *derivedKey, size_t derivedKeyLen) CC_AVAILABLE(macosx, 10_7) CC_AVAILABLE(ios, 5_0);

extern uint32_t CCCalibratePBKDF(CCPBKDFAlgorithm algorithm, size_t passwordLen, size_t saltLen, CCPseudoRandomAlgorithm prf, size_t derivedKeyLen, uint32_t msec) CC_AVAILABLE(macosx, 10_7) CC_AVAILABLE(ios, 5_0);

CC_EXTERN_C_END
CC_ASSUME_NONNULL_END

#endif  /* _CC_PBKDF_H_ */
