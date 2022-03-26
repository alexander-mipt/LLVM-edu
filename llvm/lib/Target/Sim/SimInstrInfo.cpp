#include "SimInstrInfo.h"
#include "Sim.h"
//#include "SimMachineFunctionInfo.h"
#include "MCTargetDesc/SimInfo.h"
#include "SimSubtarget.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "SimGenInstrInfo.inc"

#define DEBUG_TYPE "Sim-inst-info"

void SimInstrInfo::anchor() {}

SimInstrInfo::SimInstrInfo(const SimSubtarget &STI)
    : SimGenInstrInfo(Sim::ADJCALLSTACKDOWN, Sim::ADJCALLSTACKUP), STI(STI) {
}

unsigned SimInstrInfo::isLoadFromStackSlot(const MachineInstr &MI,
                                            int &FrameIndex) const {
  llvm_unreachable("");
  return 0;
}

unsigned SimInstrInfo::isStoreToStackSlot(const MachineInstr &MI,
                                           int &FrameIndex) const {
  llvm_unreachable("");
  return 0;
}

bool SimInstrInfo::analyzeBranch(MachineBasicBlock &MBB,
                                  MachineBasicBlock *&TBB,
                                  MachineBasicBlock *&FBB,
                                  SmallVectorImpl<MachineOperand> &Cond,
                                  bool AllowModify) const {
  llvm_unreachable("");
}

unsigned SimInstrInfo::removeBranch(MachineBasicBlock &MBB,
                                     int *BytesRemoved) const {
  llvm_unreachable("");
}

void SimInstrInfo::copyPhysReg(MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator I,
                                const DebugLoc &DL, MCRegister DestReg,
                                MCRegister SrcReg, bool KillSrc) const {
  llvm_unreachable("");
}

void SimInstrInfo::storeRegToStackSlot(MachineBasicBlock &MBB,
                                        MachineBasicBlock::iterator I,
                                        Register SrcReg, bool IsKill,
                                        int FrameIndex,
                                        const TargetRegisterClass *RC,
                                        const TargetRegisterInfo *TRI) const {
  llvm_unreachable("");
}

void SimInstrInfo::loadRegFromStackSlot(MachineBasicBlock &MBB,
                                         MachineBasicBlock::iterator I,
                                         Register DestReg, int FrameIndex,
                                         const TargetRegisterClass *RC,
                                         const TargetRegisterInfo *TRI) const {
  llvm_unreachable("");
}

bool SimInstrInfo::reverseBranchCondition(
    SmallVectorImpl<MachineOperand> &Cond) const {
  llvm_unreachable("");
}

unsigned SimInstrInfo::insertBranch(
    MachineBasicBlock &MBB, MachineBasicBlock *TBB, MachineBasicBlock *FBB,
    ArrayRef<MachineOperand> Cond, const DebugLoc &DL, int *BytesAdded) const {
  llvm_unreachable("");
}

unsigned SimInstrInfo::getInstSizeInBytes(const MachineInstr &MI) const {
  llvm_unreachable("");
}

bool SimInstrInfo::getBaseAndOffsetPosition(const MachineInstr &MI,
                                             unsigned &BasePos,
                                             unsigned &OffsetPos) const {
  llvm_unreachable("");
}