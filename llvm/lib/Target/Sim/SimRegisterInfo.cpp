#include "SimRegisterInfo.h"
#include "Sim.h"
#include "SimInstrInfo.h"
//#include "SimMachineFunctionInfo.h"
#include "SimSubtarget.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/RegisterScavenging.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

using namespace llvm;

#define DEBUG_TYPE "Sim-reg-info"

#define GET_REGINFO_TARGET_DESC
#include "SimGenRegisterInfo.inc"

SimRegisterInfo::SimRegisterInfo() : SimGenRegisterInfo(Sim::R1) {}

#if 0
bool SimRegisterInfo::needsFrameMoves(const MachineFunction &MF) {
  return MF.needsFrameMoves();
}
#endif

const MCPhysReg *
SimRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  llvm_unreachable("");
  // const SimSubtarget &Subtarget = MF.getSubtarget<SimSubtarget>();
}

BitVector SimRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  llvm_unreachable("");
}

bool SimRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  llvm_unreachable("");
}

#if 0
bool SimRegisterInfo::useFPForScavengingIndex(
    const MachineFunction &MF) const {
  llvm_unreachable("");
}
#endif

void SimRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                           int SPAdj, unsigned FIOperandNum,
                                           RegScavenger *RS) const {
  llvm_unreachable("");
}

Register SimRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  llvm_unreachable("");
}

const uint32_t *
SimRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                       CallingConv::ID CC) const {
  llvm_unreachable("");
}