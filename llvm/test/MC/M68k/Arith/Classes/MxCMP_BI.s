; RUN: llvm-mc -triple=m68k -motorola-integers -show-encoding %s | FileCheck %s

; CHECK:      cmpi.b  #0, $ffffffffffffffff
; CHECK-SAME: encoding: [0x0c,0x39,0x00,0x00,0xff,0xff,0xff,0xff]
cmpi.b	#0, $ffffffffffffffff
; CHECK:      cmpi.b  #-1, $0
; CHECK-SAME: encoding: [0x0c,0x39,0x00,0xff,0x00,0x00,0x00,0x00]
cmpi.b	#-1, $0
; CHECK:      cmpi.l  #-1, $0
; CHECK-SAME: encoding: [0x0c,0xb9,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00]
cmpi.l	#-1, $0
; CHECK:      cmpi.l  #42, $ffffffffffffffff
; CHECK-SAME: encoding: [0x0c,0xb9,0x00,0x00,0x00,0x2a,0xff,0xff,0xff,0xff]
cmpi.l	#42, $ffffffffffffffff

