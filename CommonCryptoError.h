/*
 * CommonCryptoError.h - Common return values from CommonCrypto operations.
 * Copyright (c) 2006-2015 Apple, Inc. All Rights Reserved. Licensed under APSL.
 */

#include <CommonCrypto/CommonCryptoDefines.h>

#ifndef _CC_COMMON_CRYPTO_ERROR_
#define _CC_COMMON_CRYPTO_ERROR_

CC_ASSUME_NONNULL_BEGIN
CC_EXTERN_C_BEGIN

typedef CC_SWIFT_UNAVAILABLE("Please use CCError type.") SWIFT_ENUM(int32_t, CCStatus) {
    kCCSuccess        = 0,
    kCCParamError     = -4300,
    kCCBufferTooSmall = -4301,
    kCCMemoryFailure  = -4302,
    kCCAlignmentError = -4303,
    kCCDecodeError    = -4304,
    kCCUnimplemented  = -4305,
    kCCOverflow       = -4306,
    kCCRNGFailure     = -4307
};

#define CC_UNIMPLEMENTED CC_UNAVAILABLE(macosx, "Unimplemented for now (not included)") CC_UNAVAILABLE(ios, "Unimplemented for now (not included)")

CC_EXTERN_C_END
CC_ASSUME_NONNULL_END

#endif
