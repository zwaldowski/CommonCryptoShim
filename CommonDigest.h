/*
 * CommonDigest.h - common digest routines: MD2, MD4, MD5, SHA1.
 * Copyright (c) 2004-2015 Apple, Inc. All Rights Reserved. Licensed under APSL.
 */

#ifndef _CC_COMMON_DIGEST_H_
#define _CC_COMMON_DIGEST_H_

#include <CommonCrypto/CommonCryptoDefines.h>

CC_ASSUME_NONNULL_BEGIN
CC_EXTERN_C_BEGIN

typedef CC_SWIFT_UNAVAILABLE("Please ignore the return value.") SWIFT_ENUM(int32_t, CCDigestStatus) {
    kCCDigestSuccess = 1
};

#pragma mark - MD2

CC_ANON_ENUM(int32_t) {
    CC_MD2_DIGEST_LENGTH CC_SWIFT_NAME(CCMD2DigestSize) = 16,
    CC_MD2_BLOCK_BYTES   CC_SWIFT_NAME(CCMD2BlockSize)  = 64,
    CC_MD2_BLOCK_LONG    CC_SWIFT_HIDDEN                = (CC_MD2_BLOCK_BYTES / sizeof(uint32_t))
};

typedef struct CC_MD2state_st {
    int32_t num;
    unsigned char data[CC_MD2_DIGEST_LENGTH];
    uint32_t cksm[CC_MD2_BLOCK_LONG];
    uint32_t state[CC_MD2_BLOCK_LONG];
} CC_MD2_CTX;

extern CCDigestStatus CC_MD2_Init(CC_MD2_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_MD2_Update(CC_MD2_CTX *c, const uint8_t *data, uint32_t len) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_MD2_Final(uint8_t *md, CC_MD2_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern uint8_t *CC_MD2(const uint8_t *data, uint32_t len, uint8_t *md) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

#pragma mark - MD4

CC_ANON_ENUM(int32_t) {
    CC_MD4_DIGEST_LENGTH CC_SWIFT_NAME(CCMD4DigestSize) = 16,
    CC_MD4_BLOCK_BYTES   CC_SWIFT_NAME(CCMD4BlockSize)  = 64,
    CC_MD4_BLOCK_LONG    CC_SWIFT_HIDDEN                = (CC_MD4_BLOCK_BYTES / sizeof(uint32_t))
};

typedef struct CC_MD4state_st {
    uint32_t A,B,C,D;
    uint32_t Nl,Nh;
    uint32_t data[CC_MD4_BLOCK_LONG];
    uint32_t num;
} CC_MD4_CTX;

extern CCDigestStatus CC_MD4_Init(CC_MD4_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_MD4_Update(CC_MD4_CTX *c, const uint8_t *data, uint32_t len) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_MD4_Final(uint8_t *md, CC_MD4_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern uint8_t *CC_MD4(const uint8_t *data, uint32_t len, uint8_t *md) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

#pragma mark - MD5

CC_ANON_ENUM(int32_t) {
    CC_MD5_DIGEST_LENGTH CC_SWIFT_NAME(CCMD5DigestSize) = 16,
    CC_MD5_BLOCK_BYTES   CC_SWIFT_NAME(CCMD5BlockSize)  = 64,
    CC_MD5_BLOCK_LONG    CC_SWIFT_HIDDEN                = (CC_MD5_BLOCK_BYTES / sizeof(uint32_t))
};

typedef struct CC_MD5state_st {
    uint32_t A,B,C,D;
    uint32_t Nl,Nh;
    uint32_t data[CC_MD5_BLOCK_LONG];
    int32_t num;
} CC_MD5_CTX;

extern CCDigestStatus CC_MD5_Init(CC_MD5_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_MD5_Update(CC_MD5_CTX *c, const uint8_t *data, uint32_t len) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_MD5_Final(uint8_t *md, CC_MD5_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern uint8_t *CC_MD5(const uint8_t *data, uint32_t len, uint8_t *md) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

#pragma mark - SHA1

CC_ANON_ENUM(int32_t) {
    CC_SHA1_DIGEST_LENGTH CC_SWIFT_NAME(CCSHA1DigestSize) = 20,
    CC_SHA1_BLOCK_BYTES   CC_SWIFT_NAME(CCSHA1BlockSize)  = 64,
    CC_SHA1_BLOCK_LONG    CC_SWIFT_HIDDEN                 = (CC_SHA1_BLOCK_BYTES / sizeof(uint32_t))
};

typedef struct CC_SHA1state_st
{
    uint32_t h0,h1,h2,h3,h4;
    uint32_t Nl,Nh;
    uint32_t data[CC_SHA1_BLOCK_LONG];
    int32_t num;
} CC_SHA1_CTX;

extern CCDigestStatus CC_SHA1_Init(CC_SHA1_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA1_Update(CC_SHA1_CTX *c, const uint8_t *data, uint32_t len) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA1_Final(uint8_t *md, CC_SHA1_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern uint8_t *CC_SHA1(const uint8_t *data, uint32_t len, uint8_t *md) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

#pragma mark - SHA224 and SHA256

CC_ANON_ENUM(int32_t) {
    CC_SHA224_DIGEST_LENGTH CC_SWIFT_NAME(CCSHA224DigestSize) = 28,
    CC_SHA224_BLOCK_BYTES   CC_SWIFT_NAME(CCSHA224BlockSize)  = 64,
    CC_SHA256_DIGEST_LENGTH CC_SWIFT_NAME(CCSHA256DigestSize) = 32,
    CC_SHA256_BLOCK_BYTES   CC_SWIFT_NAME(CCSHA256BlockSize)  = 64,
};

typedef struct CC_SHA256state_st {
    uint32_t count[2];
    uint32_t hash[8];
    uint32_t wbuf[16];
} CC_SHA256_CTX;

typedef CC_SHA256_CTX CC_SHA224_CTX;

extern CCDigestStatus CC_SHA224_Init(CC_SHA256_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA224_Update(CC_SHA256_CTX *c, const uint8_t *data, uint32_t len) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA224_Final(uint8_t *md, CC_SHA256_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern uint8_t *CC_SHA224(const uint8_t *data, uint32_t len, uint8_t *md) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA256_Init(CC_SHA256_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA256_Update(CC_SHA256_CTX *c, const uint8_t *data, uint32_t len) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA256_Final(uint8_t *md, CC_SHA256_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern uint8_t *CC_SHA256(const uint8_t *data, uint32_t len, uint8_t *md) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

#pragma mark - SHA384 and SHA512

CC_ANON_ENUM(int32_t) {
    CC_SHA384_DIGEST_LENGTH CC_SWIFT_NAME(CCSHA384DigestSize) = 48,
    CC_SHA384_BLOCK_BYTES   CC_SWIFT_NAME(CCSHA384BlockSize)  = 128,
    CC_SHA512_DIGEST_LENGTH CC_SWIFT_NAME(CCSHA512DigestSize) = 64,
    CC_SHA512_BLOCK_BYTES   CC_SWIFT_NAME(CCSHA512BlockSize)  = 128,
};

typedef struct CC_SHA512state_st {
    uint64_t count[2];
    uint64_t hash[8];
    uint64_t wbuf[16];
} CC_SHA512_CTX;

typedef CC_SHA512_CTX CC_SHA384_CTX;

extern CCDigestStatus CC_SHA384_Init(CC_SHA512_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA384_Update(CC_SHA512_CTX *c, const uint8_t *data, uint32_t len) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA384_Final(uint8_t *md, CC_SHA512_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern uint8_t *CC_SHA384(const uint8_t *data, uint32_t len, uint8_t *md) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA512_Init(CC_SHA512_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA512_Update(CC_SHA512_CTX *c, const uint8_t *data, uint32_t len) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern CCDigestStatus CC_SHA512_Final(uint8_t *md, CC_SHA512_CTX *c) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

extern uint8_t *CC_SHA512(const uint8_t *data, uint32_t len, uint8_t *md) CC_AVAILABLE(macosx, 10_4) CC_AVAILABLE(ios, 2_0);

CC_EXTERN_C_END
CC_ASSUME_NONNULL_END

#endif  /* _CC_COMMON_DIGEST_H_ */
