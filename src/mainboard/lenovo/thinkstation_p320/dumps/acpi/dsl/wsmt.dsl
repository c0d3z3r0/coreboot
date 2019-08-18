/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of wsmt.dat, Mon Aug 12 12:51:47 2019
 *
 * ACPI Data Table [WSMT]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "WSMT"    [Windows SMM Security Migrations Table]
[004h 0004   4]                 Table Length : 00000028
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : E1
[00Ah 0010   6]                       Oem ID : "LENOVO"
[010h 0016   8]                 Oem Table ID : "TC-S06  "
[018h 0024   4]                 Oem Revision : 00001270
[01Ch 0028   4]              Asl Compiler ID : "MSFT"
[020h 0032   4]        Asl Compiler Revision : 0000005F

[024h 0036   4]             Protection Flags : 00000000
                          FIXED_COMM_BUFFERS : 0
           COMM_BUFFER_NESTED_PTR_PROTECTION : 0
                  SYSTEM_RESOURCE_PROTECTION : 0

Raw Table Data: Length 40 (0x28)

    0000: 57 53 4D 54 28 00 00 00 01 E1 4C 45 4E 4F 56 4F  // WSMT(.....LENOVO
    0010: 54 43 2D 53 30 36 20 20 70 12 00 00 4D 53 46 54  // TC-S06  p...MSFT
    0020: 5F 00 00 00 00 00 00 00                          // _.......
