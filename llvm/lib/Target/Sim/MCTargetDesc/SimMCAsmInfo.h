#ifndef LLVM_LIB_TARGET_USIM_MCTARGETDESC_USIMMCASMINFO_H
#define LLVM_LIB_TARGET_USIM_MCTARGETDESC_USIMMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class SimMCAsmInfo : public MCAsmInfoELF {
  void anchor() override;

public:
  explicit SimMCAsmInfo(const Triple &TT);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_USIM_MCTARGETDESC_USIMMCASMINFO_H
