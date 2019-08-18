/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of tcpa.dat, Mon Aug 12 12:51:47 2019
 *
 * ACPI Data Table [TCPA]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "TCPA"    [Trusted Computing Platform Alliance table]
[004h 0004   4]                 Table Length : 00000032
[008h 0008   1]                     Revision : 02
[009h 0009   1]                     Checksum : F1
[00Ah 0010   6]                       Oem ID : "LENOVO"
[010h 0016   8]                 Oem Table ID : "TC-S06  "
[018h 0024   4]                 Oem Revision : 00001270
[01Ch 0028   4]              Asl Compiler ID : "MSFT"
[020h 0032   4]        Asl Compiler Revision : 01000013

[024h 0036   2]               Platform Class : 0000
[026h 0038   4]         Min Event Log Length : 00010000
[02Ah 0042   8]            Event Log Address : 000000009F2B6028

Raw Table Data: Length 50 (0x32)

    0000: 54 43 50 41 32 00 00 00 02 F1 4C 45 4E 4F 56 4F  // TCPA2.....LENOVO
    0010: 54 43 2D 53 30 36 20 20 70 12 00 00 4D 53 46 54  // TC-S06  p...MSFT
    0020: 13 00 00 01 00 00 00 00 01 00 28 60 2B 9F 00 00  // ..........(`+...
    0030: 00 00                                            // ..
