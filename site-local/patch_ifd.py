#!/usr/bin/env python3

import os
import sys
from operator import lshift, or_
from functools import reduce
from enum import IntEnum, auto


class regions(IntEnum):
    IFD = 0
    BIOS = 1
    ME = 2
    GBE = 3
    PDR = 4
    EC = 8

def read(f, offset, size):
    f.seek(offset)
    val = f.read(size)
    return int.from_bytes(val, 'little')

def write(f, offset, size, val):
    f.seek(offset)
    f.write(val.to_bytes(size, 'little'))

def bits(*args):
    if len(args) == 2 and all(type(x)==int for x in args):
        rng = sorted(args)
        rng = range(rng[0], rng[1]+1)
    else:
        rng = args[0]

    return reduce(or_, map(lambda x: lshift(1, x), rng))

def region_range(o, rgnum):
    val = read(o, 0x40 + (rgnum << 2), 4)
    base = ((val & bits(14, 0)) << 12)
    limit = ((val & bits(30, 16)) >> 4) | 0xfff

    return base, limit

def set_region_range(o, rgnum, rng):
    base, limit = rng
    val = read(o, 0x40 + (rgnum << 2), 4) & bits([15, 31])
    val |= (base >> 12)
    val |= ((limit & ~0xfff) << 4)

    write(o, 0x40 + (rgnum << 2), 4, val)


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: ./patch_ifd.py <ifd/flash file>")
        sys.exit(1)

    if not os.path.isfile(sys.argv[1]):
        print(f"Error: File {sys.argv[1]} does not exist.")
        sys.exit(1)

    o = open(sys.argv[1], "r+b")

   ## Shrink ME region
   #me_range = region_range(o, regions.ME)
   #bios_range = region_range(o, regions.BIOS)
   #me_imgsize = int(sys.argv[2])
   #me_range = (me_range[0], me_range[0] + me_imgsize -1)
   #bios_range = (me_range[1] + 1, bios_range[1])
   #set_region_range(o, regions.ME, me_range)
   #set_region_range(o, regions.BIOS, bios_range)

   ## Disable Intel ME
   #val = read(o, 0x100, 4)
   #val |= bits([16])
   #write(o, 0x100, 4, val)

    # Disable DCI
    val = read(o, 0x100, 4)
    val &= ~(1<<17)
    write(o, 0x100, 4, val)

    # Enable Fast Read Support
    val = read(o, 0x30, 4)
    val |= (1<<20)
    write(o, 0x30, 4, val)

    # Enable dual I/O
    val = read(o, 0x248, 1)
    val |= 0x03
    write(o, 0x248, 1, val)

    o.close()
