# RUN: %PYTHON %s | FileCheck %s

from mlir.ir import *
from mlir.dialects import arith
from mlir.dialects import builtin
from mlir.dialects import std


def constructAndPrintInModule(f):
  print("\nTEST:", f.__name__)
  with Context(), Location.unknown():
    module = Module.create()
    with InsertionPoint(module.body):
      f()
    print(module)
  return f


# CHECK-LABEL: TEST: testConstantOp


@constructAndPrintInModule
def testConstantOp():
  c1 = arith.ConstantOp(IntegerType.get_signless(32), 42)
  c2 = arith.ConstantOp(IntegerType.get_signless(64), 100)
  c3 = arith.ConstantOp(F32Type.get(), 3.14)
  c4 = arith.ConstantOp(F64Type.get(), 1.23)
  # CHECK: 42
  print(c1.literal_value)

  # CHECK: 100
  print(c2.literal_value)

  # CHECK: 3.140000104904175
  print(c3.literal_value)

  # CHECK: 1.23
  print(c4.literal_value)


# CHECK: = arith.constant 42 : i32
# CHECK: = arith.constant 100 : i64
# CHECK: = arith.constant 3.140000e+00 : f32
# CHECK: = arith.constant 1.230000e+00 : f64


# CHECK-LABEL: TEST: testVectorConstantOp
@constructAndPrintInModule
def testVectorConstantOp():
  int_type = IntegerType.get_signless(32)
  vec_type = VectorType.get([2, 2], int_type)
  c1 = arith.ConstantOp(
      vec_type,
      DenseElementsAttr.get_splat(vec_type, IntegerAttr.get(int_type, 42)))
  try:
    print(c1.literal_value)
  except ValueError as e:
    assert "only integer and float constants have literal values" in str(e)
  else:
    assert False


# CHECK: = arith.constant dense<42> : vector<2x2xi32>


# CHECK-LABEL: TEST: testConstantIndexOp
@constructAndPrintInModule
def testConstantIndexOp():
  c1 = arith.ConstantOp.create_index(10)
  # CHECK: 10
  print(c1.literal_value)


# CHECK: = arith.constant 10 : index


# CHECK-LABEL: TEST: testFunctionCalls
@constructAndPrintInModule
def testFunctionCalls():
  foo = builtin.FuncOp("foo", ([], []))
  bar = builtin.FuncOp("bar", ([], [IndexType.get()]))
  qux = builtin.FuncOp("qux", ([], [F32Type.get()]))

  with InsertionPoint(builtin.FuncOp("caller", ([], [])).add_entry_block()):
    std.CallOp(foo, [])
    std.CallOp([IndexType.get()], "bar", [])
    std.CallOp([F32Type.get()], FlatSymbolRefAttr.get("qux"), [])
    std.ReturnOp([])


# CHECK: func @foo()
# CHECK: func @bar() -> index
# CHECK: func @qux() -> f32
# CHECK: func @caller() {
# CHECK:   call @foo() : () -> ()
# CHECK:   %0 = call @bar() : () -> index
# CHECK:   %1 = call @qux() : () -> f32
# CHECK:   return
# CHECK: }
