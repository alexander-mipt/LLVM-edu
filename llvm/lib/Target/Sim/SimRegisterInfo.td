//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the Sim register file
//===----------------------------------------------------------------------===//

// For tablegen(... -gen-emitter)  in CMakeLists.txt
class SimReg<bits<16> Enc, string n> : Register<n> {
  let HWEncoding = Enc;
}

//===----------------------------------------------------------------------===//
//@Registers
//===----------------------------------------------------------------------===//
//@ All registers definition
let Namespace = "Sim" in {
  //@ General Purpose Registers
  def R0    : SimReg<0,  "r0">,    DwarfRegNum<[0]>;
  def R1    : SimReg<1,  "r1">,    DwarfRegNum<[1]>; // ra
  def R2    : SimReg<2,  "r2">,    DwarfRegNum<[2]>; // sp
  def R3    : SimReg<3,  "r3">,    DwarfRegNum<[3]>;
  def R4    : SimReg<4,  "r4">,    DwarfRegNum<[4]>;
  def R5    : SimReg<5,  "r5">,    DwarfRegNum<[5]>;
  def R6    : SimReg<6,  "r6">,    DwarfRegNum<[6]>;
  def R7    : SimReg<7,  "r7">,    DwarfRegNum<[7]>;
  def R8    : SimReg<8,  "r8">,    DwarfRegNum<[8]>;
  def R9    : SimReg<9,  "r9">,    DwarfRegNum<[9]>;
  def R10   : SimReg<10, "r10">,   DwarfRegNum<[10]>;
  def R11   : SimReg<11, "r11">,   DwarfRegNum<[11]>;
  def R12   : SimReg<12, "r12">,   DwarfRegNum<[12]>;
  def R13   : SimReg<13, "r13">,   DwarfRegNum<[13]>;
  def R14   : SimReg<14, "r14">,   DwarfRegNum<[14]>;
  def R15   : SimReg<15, "r15">,   DwarfRegNum<[15]>;
}

//===----------------------------------------------------------------------===//
//@Register Classes
//===----------------------------------------------------------------------===//

def GPR : RegisterClass<"Sim", [i32], 32, (add
  R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15)>;