/*
 * CommonCryptoError.h - Common compiler attributes for CommonCrypto operations.
 * Copyright (c) 2006-2015 Apple, Inc. All Rights Reserved. Licensed under APSL.
 */

#ifndef _CC_COMMON_CRYPTO_DEFINES_
#define _CC_COMMON_CRYPTO_DEFINES_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef __has_feature
#define __has_feature(x) 0
#endif

#ifndef __has_extension
#define __has_extension(x) 0
#endif

#ifndef __has_attribute
#define __has_attribute(x) 0
#endif

// We should namespace these, but Swift specifically looks for the macro names.
#if !defined(SWIFT_ENUM_EXTRA)
#define SWIFT_ENUM_EXTRA
#endif

#if !defined(SWIFT_ENUM)
#define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif

#if !defined(SWIFT_OPTIONS_EXTRA)
#define SWIFT_OPTIONS_EXTRA
#endif

#if !defined(SWIFT_OPTIONS)
#define SWIFT_OPTIONS(_type, _name) enum _name : _type _name; enum SWIFT_OPTIONS_EXTRA _name : _type
#endif

#if !defined(CC_ANON_ENUM)
#if (__cplusplus && __cplusplus >= 201103L && (__has_extension(cxx_strong_enums) || __has_feature(objc_fixed_enum))) || (!__cplusplus && __has_feature(objc_fixed_enum))
#define CC_ANON_ENUM(_type) enum : _type
#else
#define CC_ANON_ENUM(_type) enum
#endif
#endif

#if !defined(CC_EXTERN_C_BEGIN)
#if defined(__cplusplus)
#define CC_EXTERN_C_BEGIN extern "C" {
#define CC_EXTERN_C_END   }
#else
#define CC_EXTERN_C_BEGIN
#define CC_EXTERN_C_END
#endif
#endif

#if !defined(CC_ASSUME_NONNULL_BEGIN)
#if __has_feature(assume_nonnull)
#define CC_ASSUME_NONNULL_BEGIN _Pragma("clang assume_nonnull begin")
#define CC_ASSUME_NONNULL_END   _Pragma("clang assume_nonnull end")
#else
#define CC_ASSUME_NONNULL_BEGIN
#define CC_ASSUME_NONNULL_END
#endif
#endif

#if !__has_feature(nullability)
#if !defined(_Nullable)
#define _Nullable
#endif
#if !defined(_Nonnull)
#define _Nonnull
#endif
#if !defined(_Null_unspecified)
#define _Null_unspecified
#endif
#endif

#if !defined(CC_REFINED_FOR_SWIFT)
#if __has_attribute(swift_private)
# define CC_REFINED_FOR_SWIFT __attribute__((swift_private))
#else
# define CC_REFINED_FOR_SWIFT
#endif
#endif

#if !defined(CC_SWIFT_NAME)
#if __has_attribute(swift_name)
# define CC_SWIFT_NAME(_name) __attribute__((swift_name(#_name)))
#else
# define CC_SWIFT_NAME(_name)
#endif
#endif

#if !defined(CC_SWIFT_HIDDEN)
#if __has_feature(attribute_availability_swift)
#define CC_SWIFT_HIDDEN            __attribute__((availability(swift, unavailable)))
#define CC_SWIFT_UNAVAILABLE(_msg) __attribute__((availability(swift, unavailable, message=_msg)))
#else
#define CC_SWIFT_HIDDEN
#define CC_SWIFT_UNAVAILABLE(_msg)
#endif
#endif

#if !defined(CC_AVAILABLE)
#if __has_feature(attribute_availability_with_version_underscores)
#define CC_AVAILABLE(_os, _vers, ...) __attribute__((availability(_os,introduced=_vers,message="" __VA_ARGS__)))
#define CC_UNAVAILABLE(_os, ...)      __attribute__((availability(_os,unavailable,message="" __VA_ARGS__)))
#else
#define CC_AVAILABLE(_os, _vers, ...)
#define CC_UNAVAILABLE(_os, ...)
#endif
#endif

#endif
