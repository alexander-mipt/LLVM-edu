#ifndef LLVM_LIB_TARGET_USIM_MCTARGETDESC_USIMINFO_H
#define LLVM_LIB_TARGET_USIM_MCTARGETDESC_USIMINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace SimCC {
enum CondCode {
  EQ = 0x0,
  INVALID,
};

enum BRCondCode {
  BREQ = 0x0,
};
} // end namespace SimCC

namespace SimOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace SimOp

} // end namespace llvm

#endif
