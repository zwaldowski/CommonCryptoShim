/*
 * CommonHMAC.h - Keyed Message Authentication Code (HMAC) functions.
 * Copyright (c) 2004-2015 Apple, Inc. All Rights Reserved. Licensed under APSL.
 */

#ifndef _CC_COMMON_HMAC_H_
#define _CC_COMMON_HMAC_H_

#include <CommonCrypto/CommonCryptoDefines.h>
#include <CommonCrypto/CommonCryptoError.h>
#include <CommonCrypto/CommonDigest.h>

CC_ASSUME_NONNULL_BEGIN
CC_EXTERN_C_BEGIN

typedef SWIFT_ENUM(uint32_t, CCHmacAlgorithm) {
    kCCHmacAlgMD5    CC_SWIFT_NAME(MD5),
    kCCHmacAlgSHA1   CC_SWIFT_NAME(SHA1),
    kCCHmacAlgSHA224 CC_SWIFT_NAME(SHA224),
    kCCHmacAlgSHA256 CC_SWIFT_NAME(SHA256),
    kCCHmacAlgSHA384 CC_SWIFT_NAME(SHA384),
    kCCHmacAlgSHA512 CC_SWIFT_NAME(SHA512)
};

CC_ANON_ENUM(int32_t) {
    CC_HMAC_CONTEXT_SIZE CC_SWIFT_NAME(CCHmacContextSize) = 96
};

typedef struct {
    uint32_t ctx[CC_HMAC_CONTEXT_SIZE];
} CCHmacContext;

extern void CCHmacInit(CCHmacContext *ctx, CCHmacAlgorithm algorithm, const uint8_t *key, size_t keyLength) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern void CCHmacUpdate(CCHmacContext *ctx, const uint8_t *data, size_t dataLength) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern void CCHmacFinal(CCHmacContext *ctx, uint8_t *macOut) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern void CCHmac(CCHmacAlgorithm algorithm, const void *key, size_t keyLength, const uint8_t *data, size_t dataLength, uint8_t *macOut) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

CC_EXTERN_C_END
CC_ASSUME_NONNULL_END

#endif  /* _CC_COMMON_HMAC_H_ */
