/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of bert.dat, Sun Oct  6 00:11:47 2019
 *
 * ACPI Data Table [BERT]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "BERT"    [Boot Error Record Table]
[004h 0004   4]                 Table Length : 00000030
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : 94
[00Ah 0010   6]                       Oem ID : "AMI"
[010h 0016   8]                 Oem Table ID : "AMI.BERT"
[018h 0024   4]                 Oem Revision : 00000000
[01Ch 0028   4]              Asl Compiler ID : "AMI."
[020h 0032   4]        Asl Compiler Revision : 00000000

[024h 0036   4]     Boot Error Region Length : 00000014
[028h 0040   8]    Boot Error Region Address : 000000007DD8FF98

Raw Table Data: Length 48 (0x30)

    0000: 42 45 52 54 30 00 00 00 01 94 41 4D 49 00 00 00  // BERT0.....AMI...
    0010: 41 4D 49 2E 42 45 52 54 00 00 00 00 41 4D 49 2E  // AMI.BERT....AMI.
    0020: 00 00 00 00 14 00 00 00 98 FF D8 7D 00 00 00 00  // ...........}....
