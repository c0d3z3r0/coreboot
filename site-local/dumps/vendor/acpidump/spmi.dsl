/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of spmi.dat, Sun Oct  6 00:11:47 2019
 *
 * ACPI Data Table [SPMI]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "SPMI"    [Server Platform Management Interface table]
[004h 0004   4]                 Table Length : 00000041
[008h 0008   1]                     Revision : 05
[009h 0009   1]                     Checksum : D7
[00Ah 0010   6]                       Oem ID : "SUPERM"
[010h 0016   8]                 Oem Table ID : "SMCI--MB"
[018h 0024   4]                 Oem Revision : 00000000
[01Ch 0028   4]              Asl Compiler ID : "AMI."
[020h 0032   4]        Asl Compiler Revision : 00000000

[024h 0036   1]               Interface Type : 01
[025h 0037   1]                     Reserved : 01
[026h 0038   2]            IPMI Spec Version : 0200
[028h 0040   1]               Interrupt Type : 00
[029h 0041   1]                   GPE Number : 00
[02Ah 0042   1]                     Reserved : 00
[02Bh 0043   1]              PCI Device Flag : 00
[02Ch 0044   4]                    Interrupt : 00000000

[030h 0048  12]                IPMI Register : [Generic Address Structure]
[030h 0048   1]                     Space ID : 01 [SystemIO]
[031h 0049   1]                    Bit Width : 00
[032h 0050   1]                   Bit Offset : 00
[033h 0051   1]         Encoded Access Width : 01 [Byte Access:8]
[034h 0052   8]                      Address : 0000000000000CA2

[03Ch 0060   1]                  PCI Segment : 00
[03Dh 0061   1]                      PCI Bus : 00
[03Eh 0062   1]                   PCI Device : 00
[03Fh 0063   1]                 PCI Function : 00
[040h 0064   1]                     Reserved : 00

Raw Table Data: Length 65 (0x41)

    0000: 53 50 4D 49 41 00 00 00 05 D7 53 55 50 45 52 4D  // SPMIA.....SUPERM
    0010: 53 4D 43 49 2D 2D 4D 42 00 00 00 00 41 4D 49 2E  // SMCI--MB....AMI.
    0020: 00 00 00 00 01 01 00 02 00 00 00 00 00 00 00 00  // ................
    0030: 01 00 00 01 A2 0C 00 00 00 00 00 00 00 00 00 00  // ................
    0040: 00                                               // .
