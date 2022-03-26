#include "SimFrameLowering.h"
//#include "SimMachineFunctionInfo.h"
#include "SimSubtarget.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/RegisterScavenging.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

#define DEBUG_TYPE "Sim-frame-lowering"

using namespace llvm;

void SimFrameLowering::determineCalleeSaves(MachineFunction &MF,
                                             BitVector &SavedRegs,
                                             RegScavenger *RS) const {
  llvm_unreachable("");
}

void SimFrameLowering::adjustStackToMatchRecords(
    MachineBasicBlock &MBB, MachineBasicBlock::iterator MBBI,
    bool Allocate) const {
  llvm_unreachable("");
}

void SimFrameLowering::emitPrologue(MachineFunction &MF,
                                     MachineBasicBlock &MBB) const {
  llvm_unreachable("");
}

void SimFrameLowering::emitEpilogue(MachineFunction &MF,
                                     MachineBasicBlock &MBB) const {
  llvm_unreachable("");
}

bool SimFrameLowering::assignCalleeSavedSpillSlots(
    MachineFunction &MF, const TargetRegisterInfo *TRI,
    std::vector<CalleeSavedInfo> &CSI) const {
  llvm_unreachable("");
}

bool SimFrameLowering::spillCalleeSavedRegisters(
    MachineBasicBlock &MBB, MachineBasicBlock::iterator MI,
    ArrayRef<CalleeSavedInfo> CSI, const TargetRegisterInfo *TRI) const {
  llvm_unreachable("");
}

bool SimFrameLowering::restoreCalleeSavedRegisters(
    MachineBasicBlock &MBB, MachineBasicBlock::iterator MI,
    MutableArrayRef<CalleeSavedInfo> CSI, const TargetRegisterInfo *TRI) const {
  llvm_unreachable("");
}

void SimFrameLowering::processFunctionBeforeFrameFinalized(
    MachineFunction &MF, RegScavenger *RS) const {
  llvm_unreachable("");
}

MachineBasicBlock::iterator SimFrameLowering::eliminateCallFramePseudoInstr(
    MachineFunction &MF, MachineBasicBlock &MBB,
    MachineBasicBlock::iterator I) const {
  llvm_unreachable("");
}

bool SimFrameLowering::hasFP(const MachineFunction &MF) const {
  llvm_unreachable("");
}