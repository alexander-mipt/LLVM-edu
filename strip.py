#!/usr/bin/python3
import re
import sys

endLabel = re.compile(r"\.Lfunc_end.*")
label = re.compile(r".*:$")

header = \
"""
MOVli r2 32767
BL r1 main
EXIT
"""

if __name__ == '__main__':

    if len(sys.argv) != 2:
        print("wrong args\nUsage: ./<script> <input.s>")
        exit(-1)

    input = sys.argv[1]

    with open(input, "r") as f:
        print("=== Past it to simulator Window -> [load CPU] -> [stop CPU] -> [run CPU] ===")
        print(header)
        line = f.readline()
        while line and not re.search(label, line):
            line = f.readline()

        skip = False
        while line:
            if re.search(endLabel, line):
                skip = True
            elif re.search(label, line):
                skip = False
        
            if not skip:
                print(line.lstrip().strip())
            line = f.readline()
        print("=== Past it to simulator Window -> [load CPU] -> [stop CPU] -> [run CPU] ===")

