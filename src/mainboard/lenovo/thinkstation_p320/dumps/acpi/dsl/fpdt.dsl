/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of fpdt.dat, Mon Aug 12 12:51:47 2019
 *
 * ACPI Data Table [FPDT]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "FPDT"    [Firmware Performance Data Table]
[004h 0004   4]                 Table Length : 00000044
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : F1
[00Ah 0010   6]                       Oem ID : "LENOVO"
[010h 0016   8]                 Oem Table ID : "TC-S06  "
[018h 0024   4]                 Oem Revision : 00001270
[01Ch 0028   4]              Asl Compiler ID : "AMI "
[020h 0032   4]        Asl Compiler Revision : 00010013


[024h 0036   2]                Subtable Type : 0001
[026h 0038   1]                       Length : 10
[027h 0039   1]                     Revision : 01
[028h 0040   4]                     Reserved : 00000000
[02Ch 0044   8]          S3PT Record Address : 000000009F5EF130

[034h 0052   2]                Subtable Type : 0000
[036h 0054   1]                       Length : 10
[037h 0055   1]                     Revision : 01
[038h 0056   4]                     Reserved : 00000000
[03Ch 0060   8]     FPDT Boot Record Address : 000000009F5EF150

Raw Table Data: Length 68 (0x44)

    0000: 46 50 44 54 44 00 00 00 01 F1 4C 45 4E 4F 56 4F  // FPDTD.....LENOVO
    0010: 54 43 2D 53 30 36 20 20 70 12 00 00 41 4D 49 20  // TC-S06  p...AMI 
    0020: 13 00 01 00 01 00 10 01 00 00 00 00 30 F1 5E 9F  // ............0.^.
    0030: 00 00 00 00 00 00 10 01 00 00 00 00 50 F1 5E 9F  // ............P.^.
    0040: 00 00 00 00                                      // ....
