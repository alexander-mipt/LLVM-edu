add_llvm_component_group(Sim)

set(LLVM_TARGET_DEFINITIONS Sim.td)

# Generate SimGenRegisterInfo.inc and SimGenInstrInfo.inc which included by
#  your hand code C++ files.
# SimGenRegisterInfo.inc came from SimRegisterInfo.td, SimGenInstrInfo.inc
#  came from SimInstrInfo.td.
tablegen(LLVM SimGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM SimGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM SimGenCallingConv.inc -gen-callingconv)
tablegen(LLVM SimGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM SimGenAsmWriter.inc -gen-asm-writer)

#tablegen(LLVM SimGenDAGISel.inc -gen-dag-isel)
#tablegen(LLVM SimGenDisassemblerTables.inc -gen-disassembler)

# SimCommonTableGen must be defined
add_public_tablegen_target(SimCommonTableGen)

# SimCodeGen should match with LLVMBuild.txt SimCodeGen
add_llvm_target(SimCodeGen
  SimFrameLowering.cpp
  SimInstrInfo.cpp
  SimISelLowering.cpp
  SimRegisterInfo.cpp
  SimSubtarget.cpp
  SimTargetMachine.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  Core
  MC
  SimDesc
  SimInfo
  SelectionDAG
  Support
  Target
  GlobalISel

  ADD_TO_COMPONENT
  Sim
  )

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)