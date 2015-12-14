/*
 * CommonRandom.h - An interface to a system random number generator.
 * Copyright (c) 2014-2015 Apple, Inc. All Rights Reserved. Licensed under APSL.
 */

#include <CommonCrypto/CommonCryptoDefines.h>
#include <CommonCrypto/CommonCryptoError.h>

#ifndef _CC_COMMON_RANDOM_
#define _CC_COMMON_RANDOM_

CC_ASSUME_NONNULL_BEGIN
CC_EXTERN_C_BEGIN

typedef CCStatus CCRNGStatus;

extern CCRNGStatus CCRandomGenerateBytes(uint8_t *bytes, size_t count) CC_AVAILABLE(macosx, 10_10) CC_AVAILABLE(ios, 8_0);

CC_EXTERN_C_END
CC_ASSUME_NONNULL_END

#endif
