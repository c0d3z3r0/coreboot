/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of hest.dat, Mon Aug 12 12:51:47 2019
 *
 * ACPI Data Table [HEST]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "HEST"    [Hardware Error Source Table]
[004h 0004   4]                 Table Length : 000000A8
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : 41
[00Ah 0010   6]                       Oem ID : "LENOVO"
[010h 0016   8]                 Oem Table ID : "TC-S06  "
[018h 0024   4]                 Oem Revision : 00001270
[01Ch 0028   4]              Asl Compiler ID : "AMI."
[020h 0032   4]        Asl Compiler Revision : 00000000

[024h 0036   4]           Error Source Count : 00000002

[028h 0040   2]                Subtable Type : 0009 [Generic Hardware Error Source]
[02Ah 0042   2]                    Source Id : 0000
[02Ch 0044   2]            Related Source Id : FFFF
[02Eh 0046   1]                     Reserved : 00
[02Fh 0047   1]                      Enabled : 01
[030h 0048   4]       Records To Preallocate : 00000001
[034h 0052   4]      Max Sections Per Record : 00000001
[038h 0056   4]          Max Raw Data Length : 00001000

[03Ch 0060  12]         Error Status Address : [Generic Address Structure]
[03Ch 0060   1]                     Space ID : 00 [SystemMemory]
[03Dh 0061   1]                    Bit Width : 40
[03Eh 0062   1]                   Bit Offset : 00
[03Fh 0063   1]         Encoded Access Width : 04 [QWord Access:64]
[040h 0064   8]                      Address : 000000009EE07018

[048h 0072  28]                       Notify : [Hardware Error Notification Structure]
[048h 0072   1]                  Notify Type : 04 [NMI]
[049h 0073   1]                Notify Length : 1C
[04Ah 0074   2]   Configuration Write Enable : 0000
[04Ch 0076   4]                 PollInterval : 00000000
[050h 0080   4]                       Vector : 00000002
[054h 0084   4]      Polling Threshold Value : 00000000
[058h 0088   4]     Polling Threshold Window : 00000000
[05Ch 0092   4]        Error Threshold Value : 00000000
[060h 0096   4]       Error Threshold Window : 00000000

[064h 0100   4]    Error Status Block Length : 00001000

[068h 0104   2]                Subtable Type : 0009 [Generic Hardware Error Source]
[06Ah 0106   2]                    Source Id : 0001
[06Ch 0108   2]            Related Source Id : FFFF
[06Eh 0110   1]                     Reserved : 00
[06Fh 0111   1]                      Enabled : 01
[070h 0112   4]       Records To Preallocate : 00000001
[074h 0116   4]      Max Sections Per Record : 00000001
[078h 0120   4]          Max Raw Data Length : 00001000

[07Ch 0124  12]         Error Status Address : [Generic Address Structure]
[07Ch 0124   1]                     Space ID : 00 [SystemMemory]
[07Dh 0125   1]                    Bit Width : 40
[07Eh 0126   1]                   Bit Offset : 00
[07Fh 0127   1]         Encoded Access Width : 04 [QWord Access:64]
[080h 0128   8]                      Address : 000000009EE08020

[088h 0136  28]                       Notify : [Hardware Error Notification Structure]
[088h 0136   1]                  Notify Type : 00 [Polled]
[089h 0137   1]                Notify Length : 1C
[08Ah 0138   2]   Configuration Write Enable : 003E
[08Ch 0140   4]                 PollInterval : 0000EA60
[090h 0144   4]                       Vector : 00000002
[094h 0148   4]      Polling Threshold Value : 00000000
[098h 0152   4]     Polling Threshold Window : 00000000
[09Ch 0156   4]        Error Threshold Value : 00000000
[0A0h 0160   4]       Error Threshold Window : 00000000

[0A4h 0164   4]    Error Status Block Length : 00001000

Raw Table Data: Length 168 (0xA8)

    0000: 48 45 53 54 A8 00 00 00 01 41 4C 45 4E 4F 56 4F  // HEST.....ALENOVO
    0010: 54 43 2D 53 30 36 20 20 70 12 00 00 41 4D 49 2E  // TC-S06  p...AMI.
    0020: 00 00 00 00 02 00 00 00 09 00 00 00 FF FF 00 01  // ................
    0030: 01 00 00 00 01 00 00 00 00 10 00 00 00 40 00 04  // .............@..
    0040: 18 70 E0 9E 00 00 00 00 04 1C 00 00 00 00 00 00  // .p..............
    0050: 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    0060: 00 00 00 00 00 10 00 00 09 00 01 00 FF FF 00 01  // ................
    0070: 01 00 00 00 01 00 00 00 00 10 00 00 00 40 00 04  // .............@..
    0080: 20 80 E0 9E 00 00 00 00 00 1C 3E 00 60 EA 00 00  //  .........>.`...
    0090: 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    00A0: 00 00 00 00 00 10 00 00                          // ........
