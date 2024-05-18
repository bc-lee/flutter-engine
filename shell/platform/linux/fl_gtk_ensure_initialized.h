// Copyright 2024 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_LINUX_FL_GTK_ENSURE_INITIALIZED_H_
#define FLUTTER_SHELL_PLATFORM_LINUX_FL_GTK_ENSURE_INITIALIZED_H_

#ifdef FLUTTER_DLOPEN_GTK3

/**
 * fl_gtk_ensure_initialized:
 *
 * When libflutter_linux_gtk.so don't link to libgtk-3.so, it needs to dlopen
 * libgtk-3.so and find necessary symbols. This function should be called before
 * any GTK functions are called.
 */
void fl_gtk_ensure_initialized();

#endif  // FLUTTER_DLOPEN_GTK3

#endif  // FLUTTER_SHELL_PLATFORM_LINUX_FL_GTK_ENSURE_INITIALIZED_H_
