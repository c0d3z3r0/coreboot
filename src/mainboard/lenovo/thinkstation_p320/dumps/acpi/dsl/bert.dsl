/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of bert.dat, Mon Aug 12 12:51:47 2019
 *
 * ACPI Data Table [BERT]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "BERT"    [Boot Error Record Table]
[004h 0004   4]                 Table Length : 00000030
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : 24
[00Ah 0010   6]                       Oem ID : "LENOVO"
[010h 0016   8]                 Oem Table ID : "TC-S06  "
[018h 0024   4]                 Oem Revision : 00001270
[01Ch 0028   4]              Asl Compiler ID : "AMI."
[020h 0032   4]        Asl Compiler Revision : 00000000

[024h 0036   4]     Boot Error Region Length : 00000014
[028h 0040   8]    Boot Error Region Address : 000000009F2C7018

Raw Table Data: Length 48 (0x30)

    0000: 42 45 52 54 30 00 00 00 01 24 4C 45 4E 4F 56 4F  // BERT0....$LENOVO
    0010: 54 43 2D 53 30 36 20 20 70 12 00 00 41 4D 49 2E  // TC-S06  p...AMI.
    0020: 00 00 00 00 14 00 00 00 18 70 2C 9F 00 00 00 00  // .........p,.....
