/*
 * CommonSymmetricKeywrap.h - Wrap a symmetric key with a Key Encryption Key.
 * Copyright (c) 2010-2015 Apple, Inc. All Rights Reserved. Licensed under APSL.
 */

#ifndef _CC_SYMKEYWRAP_H_
#define _CC_SYMKEYWRAP_H_

#include <CommonCrypto/CommonCryptoDefines.h>
#include <CommonCrypto/CommonCryptoError.h>

CC_ASSUME_NONNULL_BEGIN
CC_EXTERN_C_BEGIN

typedef SWIFT_ENUM(uint32_t, CCWrappingAlgorithm) {
    kCCWRAPAES CC_SWIFT_NAME(AES) = 2,
};

extern CC_REFINED_FOR_SWIFT const uint8_t *const CCrfc3394_iv CC_AVAILABLE(macosx, 10_6) CC_AVAILABLE(ios, 5_0);
extern CC_REFINED_FOR_SWIFT const size_t CCrfc3394_ivLen      CC_AVAILABLE(macosx, 10_6) CC_AVAILABLE(ios, 5_0);

extern CCStatus CCSymmetricKeyWrap(CCWrappingAlgorithm algorithm, const uint8_t *iv, const size_t ivLen, const uint8_t *kek, size_t kekLen, const uint8_t *rawKey, size_t rawKeyLen, uint8_t *wrappedKey, size_t *wrappedKeyLen) CC_AVAILABLE(macosx, 10_7) CC_AVAILABLE(ios, 5_0);

extern CCStatus CCSymmetricKeyUnwrap(CCWrappingAlgorithm algorithm, const uint8_t *iv, const size_t ivLen, const uint8_t *kek, size_t kekLen, const uint8_t *wrappedKey, size_t wrappedKeyLen, uint8_t *rawKey, size_t *rawKeyLen) CC_AVAILABLE(macosx, 10_7) CC_AVAILABLE(ios, 5_0);

extern size_t CCSymmetricWrappedSize(CCWrappingAlgorithm algorithm, size_t rawKeyLen) CC_AVAILABLE(macosx, 10_7) CC_AVAILABLE(ios, 5_0);

extern size_t CCSymmetricUnwrappedSize(CCWrappingAlgorithm algorithm, size_t wrappedKeyLen) CC_AVAILABLE(macosx, 10_7) CC_AVAILABLE(ios, 5_0);

CC_EXTERN_C_END
CC_ASSUME_NONNULL_END

#endif /* _CC_SYMKEYWRAP_H_ */
