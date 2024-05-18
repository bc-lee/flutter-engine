// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_FML_COMPILER_SPECIFIC_H_
#define FLUTTER_FML_COMPILER_SPECIFIC_H_

#if !defined(__GNUC__) && !defined(__clang__) && !defined(_MSC_VER)
#error Unsupported compiler.
#endif

// Annotate a variable indicating it's ok if the variable is not used.
// (Typically used to silence a compiler warning when the assignment
// is important for some other reason.)
// Use like:
//   int x = ...;
//   FML_ALLOW_UNUSED_LOCAL(x);
#define FML_ALLOW_UNUSED_LOCAL(x) false ? (void)x : (void)0

// Annotate a typedef or function indicating it's ok if it's not used.
// Use like:
//   typedef Foo Bar ALLOW_UNUSED_TYPE;
#if defined(__GNUC__) || defined(__clang__)
#define FML_ALLOW_UNUSED_TYPE __attribute__((unused))
#else
#define FML_ALLOW_UNUSED_TYPE
#endif

#ifdef __has_attribute
#if __has_attribute(no_sanitize)
#define FML_NO_SANITIZE(what) __attribute__((no_sanitize(what)))
#endif
#endif
#ifndef FML_NO_SANITIZE
#define FML_NO_SANITIZE(what)
#endif

// DISABLE_CFI_ICALL -- Disable Control Flow Integrity indirect call checks.
// Note that the same macro is defined in "base/compiler_specific.h" of Chromium.
#if !defined(DISABLE_CFI_ICALL)
#if defined(FML_OS_WIN)
// Windows also needs __declspec(guard(nocf)).
#define DISABLE_CFI_ICALL FML_NO_SANITIZE("cfi-icall") __declspec(guard(nocf))
#else
#define DISABLE_CFI_ICALL FML_NO_SANITIZE("cfi-icall")
#endif  // defined(FML_OS_WIN)
#endif  // !defined(DISABLE_CFI_ICALL)


#endif  // FLUTTER_FML_COMPILER_SPECIFIC_H_
