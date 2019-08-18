/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of dmar.dat, Mon Aug 12 12:51:47 2019
 *
 * ACPI Data Table [DMAR]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "DMAR"    [DMA Remapping table]
[004h 0004   4]                 Table Length : 00000070
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : B1
[00Ah 0010   6]                       Oem ID : "LENOVO"
[010h 0016   8]                 Oem Table ID : "TC-S06  "
[018h 0024   4]                 Oem Revision : 00001270
[01Ch 0028   4]              Asl Compiler ID : "INTL"
[020h 0032   4]        Asl Compiler Revision : 00000001

[024h 0036   1]           Host Address Width : 26
[025h 0037   1]                        Flags : 01
[026h 0038  10]                     Reserved : 00 00 00 00 00 00 00 00 00 00

[030h 0048   2]                Subtable Type : 0000 [Hardware Unit Definition]
[032h 0050   2]                       Length : 0020

[034h 0052   1]                        Flags : 01
[035h 0053   1]                     Reserved : 00
[036h 0054   2]           PCI Segment Number : 0000
[038h 0056   8]        Register Base Address : 00000000FED90000

[040h 0064   1]            Device Scope Type : 03 [IOAPIC Device]
[041h 0065   1]                 Entry Length : 08
[042h 0066   2]                     Reserved : 0000
[044h 0068   1]               Enumeration ID : 02
[045h 0069   1]               PCI Bus Number : F0

[046h 0070   2]                     PCI Path : 1F,00


[048h 0072   1]            Device Scope Type : 04 [Message-capable HPET Device]
[049h 0073   1]                 Entry Length : 08
[04Ah 0074   2]                     Reserved : 0000
[04Ch 0076   1]               Enumeration ID : 00
[04Dh 0077   1]               PCI Bus Number : 00

[04Eh 0078   2]                     PCI Path : 1F,00


[050h 0080   2]                Subtable Type : 0001 [Reserved Memory Region]
[052h 0082   2]                       Length : 0020

[054h 0084   2]                     Reserved : 0000
[056h 0086   2]           PCI Segment Number : 0000
[058h 0088   8]                 Base Address : 000000009E183000
[060h 0096   8]          End Address (limit) : 000000009E1A2FFF

[068h 0104   1]            Device Scope Type : 01 [PCI Endpoint Device]
[069h 0105   1]                 Entry Length : 08
[06Ah 0106   2]                     Reserved : 0000
[06Ch 0108   1]               Enumeration ID : 00
[06Dh 0109   1]               PCI Bus Number : 00

[06Eh 0110   2]                     PCI Path : 14,00


Raw Table Data: Length 112 (0x70)

    0000: 44 4D 41 52 70 00 00 00 01 B1 4C 45 4E 4F 56 4F  // DMARp.....LENOVO
    0010: 54 43 2D 53 30 36 20 20 70 12 00 00 49 4E 54 4C  // TC-S06  p...INTL
    0020: 01 00 00 00 26 01 00 00 00 00 00 00 00 00 00 00  // ....&...........
    0030: 00 00 20 00 01 00 00 00 00 00 D9 FE 00 00 00 00  // .. .............
    0040: 03 08 00 00 02 F0 1F 00 04 08 00 00 00 00 1F 00  // ................
    0050: 01 00 20 00 00 00 00 00 00 30 18 9E 00 00 00 00  // .. ......0......
    0060: FF 2F 1A 9E 00 00 00 00 01 08 00 00 00 00 14 00  // ./..............
