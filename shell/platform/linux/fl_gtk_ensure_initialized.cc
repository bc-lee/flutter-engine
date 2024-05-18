#ifdef FLUTTER_DLOPEN_GTK3

#include "flutter/shell/platform/linux/fl_gtk_ensure_initialized.h"

#include <dlfcn.h> // for dlopen
#include "flutter/fml/logging.h"
#include "flutter/shell/platform/linux/config/gtk3_stubs.h"

#include <mutex>

namespace {
std::once_flag g_gtk3_init_flag;

void InitializeGtk3Once() {
  void* handle = dlopen("libgtk-3.so", RTLD_LAZY | RTLD_GLOBAL);
  if (!handle) {
    FML_LOG(ERROR) << "Failed to load libgtk-3.so: " << dlerror();
  }
  flutter_shell_platform_linux_config::InitializeGtk3(handle);
}
} // namespace


void fl_gtk_ensure_initialized() {
  std::call_once(g_gtk3_init_flag, [] { InitializeGtk3Once(); });
}

#endif // FLUTTER_DLOPEN_GTK3
