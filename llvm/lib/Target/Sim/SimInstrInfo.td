//===----------------------------------------------------------------------===//
//
// This file contains the Sim implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Sim profiles and nodes
//===----------------------------------------------------------------------===//

def SDT_SimCallSeqStart : SDCallSeqStart<[ SDTCisVT<0, i32>,
                                           SDTCisVT<1, i32> ]>;
def SDT_SimCallSeqEnd   : SDCallSeqEnd<[ SDTCisVT<0, i32>,
                                         SDTCisVT<1, i32> ]>;

// These are target-independent nodes, but have target-specific formats.
def callseq_start : SDNode<"ISD::CALLSEQ_START", SDT_SimCallSeqStart,
                           [SDNPHasChain, SDNPOutGlue]>;
def callseq_end   : SDNode<"ISD::CALLSEQ_END",   SDT_SimCallSeqEnd,
                           [SDNPHasChain, SDNPOptInGlue, SDNPOutGlue]>;

def SDT_SimRet          : SDTypeProfile<0, 1, [SDTCisInt<0>]>;

// Return
def SimRet : SDNode<"SimISD::Ret", SDTNone,
                     [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "SimInstrFormats.td"

//===----------------------------------------------------------------------===//
// Pseudo Instructions
//===----------------------------------------------------------------------===//

let Defs = [R0], Uses = [R0] in { // TODO: SP
def ADJCALLSTACKDOWN : SimPseudoInst<(outs), (ins i32imm:$amt, i32imm:$amt2),
                               "# ADJCALLSTACKDOWN $amt, $amt2",
                               [(callseq_start timm:$amt, timm:$amt2)]>;
def ADJCALLSTACKUP : SimPseudoInst<(outs), (ins i32imm:$amt1, i32imm:$amt2),
                            "# ADJCALLSTACKUP $amt1",
                            [(callseq_end timm:$amt1, timm:$amt2)]>;
}

//===----------------------------------------------------------------------===//
// Sim Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Instructions specific format
//===----------------------------------------------------------------------===//

//@Branches {
let isBranch=1, isTerminator=1, isBarrier=1, hasDelaySlot = 1,
    isIndirectBranch = 1 in
class Branches<bits<8> op, string instr_asm, RegisterClass RC>:
  SimInst<op, (outs), (ins RC:$r1),
     !strconcat(instr_asm, "\t$r1"), [(brind RC:$r1)]> {
}
//@Branches }

// Return instruction
class RetBase<RegisterClass RC>: Branches<0x3c, "RET", RC> {
  let isReturn = 1;
  let isCodeGenOnly = 1;
  let hasCtrlDep = 1;
  let hasExtraSrcRegAllocReq = 1;
}


//===----------------------------------------------------------------------===//
// Instruction definition
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Sim Instructions
//===----------------------------------------------------------------------===//

def RET     : RetBase<GPR>;

/// No operation
def NOP   : SimInst<0, (outs), (ins), "nop", []>;