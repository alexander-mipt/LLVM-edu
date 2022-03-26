#include "SimISelLowering.h"
#include "Sim.h"
//#include "SimMachineFunctionInfo.h"
#include "MCTargetDesc/SimInfo.h"
#include "SimRegisterInfo.h"
#include "SimSubtarget.h"
#include "SimTargetMachine.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineJumpTableInfo.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/ValueTypes.h"
#include "llvm/IR/CallingConv.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include <algorithm>

#define DEBUG_TYPE "Sim-lower"

using namespace llvm;

void SimTargetLowering::ReplaceNodeResults(SDNode *N,
                                            SmallVectorImpl<SDValue> &Results,
                                            SelectionDAG &DAG) const {
  llvm_unreachable("");
}

SimTargetLowering::SimTargetLowering(const TargetMachine &TM,
                                       const SimSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  addRegisterClass(MVT::i32, &Sim::GPRRegClass);

  computeRegisterProperties(STI.getRegisterInfo());

  setStackPointerRegisterToSaveRestore(Sim::R2);

  // setSchedulingPreference(Sched::Source);

  for (unsigned Opc = 0; Opc < ISD::BUILTIN_OP_END; ++Opc)
    setOperationAction(Opc, MVT::i32, Expand);

  setOperationAction(ISD::ADD, MVT::i32, Legal);
  // ...
}

const char *SimTargetLowering::getTargetNodeName(unsigned Opcode) const {
  llvm_unreachable("");
}

//===----------------------------------------------------------------------===//
//  Misc Lower Operation implementation
//===----------------------------------------------------------------------===//

#include "SimGenCallingConv.inc"

//===----------------------------------------------------------------------===//
//                  Call Calling Convention Implementation
//===----------------------------------------------------------------------===//

SDValue SimTargetLowering::LowerCall(TargetLowering::CallLoweringInfo &CLI,
                                      SmallVectorImpl<SDValue> &InVals) const {
  llvm_unreachable("");
}

//===----------------------------------------------------------------------===//
//             Formal Arguments Calling Convention Implementation
//===----------------------------------------------------------------------===//

/// Sim formal arguments implementation
SDValue SimTargetLowering::LowerFormalArguments(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    const SmallVectorImpl<ISD::InputArg> &Ins, const SDLoc &Dl,
    SelectionDAG &DAG, SmallVectorImpl<SDValue> &InVals) const {
  llvm_unreachable("");
}

//===----------------------------------------------------------------------===//
//               Return Value Calling Convention Implementation
//===----------------------------------------------------------------------===//

bool SimTargetLowering::CanLowerReturn(
    CallingConv::ID CallConv, MachineFunction &MF, bool IsVarArg,
    const SmallVectorImpl<ISD::OutputArg> &Outs, LLVMContext &Context) const {
  llvm_unreachable("");
}

SDValue
SimTargetLowering::LowerReturn(SDValue Chain, CallingConv::ID CallConv,
                                bool IsVarArg,
                                const SmallVectorImpl<ISD::OutputArg> &Outs,
                                const SmallVectorImpl<SDValue> &OutVals,
                                const SDLoc &DL, SelectionDAG &DAG) const {
  llvm_unreachable("");
}

//===----------------------------------------------------------------------===//
// Target Optimization Hooks
//===----------------------------------------------------------------------===//

SDValue SimTargetLowering::PerformDAGCombine(SDNode *N,
                                              DAGCombinerInfo &DCI) const {
  llvm_unreachable("");
  return {};
}

//===----------------------------------------------------------------------===//
//  Addressing mode description hooks
//===----------------------------------------------------------------------===//

/// Return true if the addressing mode represented by AM is legal for this
/// target, for a load/store of the specified type.
bool SimTargetLowering::isLegalAddressingMode(const DataLayout &DL,
                                               const AddrMode &AM, Type *Ty,
                                               unsigned AS,
                                               Instruction *I) const {
  llvm_unreachable("");
}

// Don't emit tail calls for the time being.
bool SimTargetLowering::mayBeEmittedAsTailCall(const CallInst *CI) const {
  return false;
}

SDValue SimTargetLowering::LowerOperation(SDValue Op,
                                           SelectionDAG &DAG) const {
  llvm_unreachable("");
}