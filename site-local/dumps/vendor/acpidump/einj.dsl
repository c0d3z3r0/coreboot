/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of einj.dat, Sun Oct  6 00:11:47 2019
 *
 * ACPI Data Table [EINJ]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "EINJ"    [Error Injection table]
[004h 0004   4]                 Table Length : 00000130
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : 47
[00Ah 0010   6]                       Oem ID : "AMI"
[010h 0016   8]                 Oem Table ID : "AMI.EINJ"
[018h 0024   4]                 Oem Revision : 00000000
[01Ch 0028   4]              Asl Compiler ID : "AMI."
[020h 0032   4]        Asl Compiler Revision : 00000000

[024h 0036   4]      Injection Header Length : 0000000C
[028h 0040   1]                        Flags : 00
[029h 0041   3]                     Reserved : 000000
[02Ch 0044   4]        Injection Entry Count : 00000008

[030h 0048   1]                       Action : 00 [Begin Operation]
[031h 0049   1]                  Instruction : 03 [Write Register Value]
[032h 0050   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[033h 0051   1]                     Reserved : 00

[034h 0052  12]              Register Region : [Generic Address Structure]
[034h 0052   1]                     Space ID : 00 [SystemMemory]
[035h 0053   1]                    Bit Width : 08
[036h 0054   1]                   Bit Offset : 00
[037h 0055   1]         Encoded Access Width : 01 [Byte Access:8]
[038h 0056   8]                      Address : 000000007D1D5E98

[040h 0064   8]                        Value : 0000000000000000
[048h 0072   8]                         Mask : 00000000000000FF

[050h 0080   1]                       Action : 01 [Get Trigger Table]
[051h 0081   1]                  Instruction : 00 [Read Register]
[052h 0082   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[053h 0083   1]                     Reserved : 00

[054h 0084  12]              Register Region : [Generic Address Structure]
[054h 0084   1]                     Space ID : 00 [SystemMemory]
[055h 0085   1]                    Bit Width : 40
[056h 0086   1]                   Bit Offset : 00
[057h 0087   1]         Encoded Access Width : 04 [QWord Access:64]
[058h 0088   8]                      Address : 000000007D1D5E9A

[060h 0096   8]                        Value : 0000000000000000
[068h 0104   8]                         Mask : FFFFFFFFFFFFFFFF

[070h 0112   1]                       Action : 02 [Set Error Type]
[071h 0113   1]                  Instruction : 02 [Write Register]
[072h 0114   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[073h 0115   1]                     Reserved : 00

[074h 0116  12]              Register Region : [Generic Address Structure]
[074h 0116   1]                     Space ID : 00 [SystemMemory]
[075h 0117   1]                    Bit Width : 20
[076h 0118   1]                   Bit Offset : 00
[077h 0119   1]         Encoded Access Width : 03 [DWord Access:32]
[078h 0120   8]                      Address : 000000007D1D5EA2

[080h 0128   8]                        Value : 0000000000000000
[088h 0136   8]                         Mask : 00000000FFFFFFFF

[090h 0144   1]                       Action : 03 [Get Error Type]
[091h 0145   1]                  Instruction : 00 [Read Register]
[092h 0146   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[093h 0147   1]                     Reserved : 00

[094h 0148  12]              Register Region : [Generic Address Structure]
[094h 0148   1]                     Space ID : 00 [SystemMemory]
[095h 0149   1]                    Bit Width : 20
[096h 0150   1]                   Bit Offset : 00
[097h 0151   1]         Encoded Access Width : 03 [DWord Access:32]
[098h 0152   8]                      Address : 000000007D1D5EAA

[0A0h 0160   8]                        Value : 0000000000000000
[0A8h 0168   8]                         Mask : 00000000FFFFFFFF

[0B0h 0176   1]                       Action : 04 [End Operation]
[0B1h 0177   1]                  Instruction : 03 [Write Register Value]
[0B2h 0178   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[0B3h 0179   1]                     Reserved : 00

[0B4h 0180  12]              Register Region : [Generic Address Structure]
[0B4h 0180   1]                     Space ID : 00 [SystemMemory]
[0B5h 0181   1]                    Bit Width : 10
[0B6h 0182   1]                   Bit Offset : 00
[0B7h 0183   1]         Encoded Access Width : 02 [Word Access:16]
[0B8h 0184   8]                      Address : 000000007D1D5EAE

[0C0h 0192   8]                        Value : 0000000000000000
[0C8h 0200   8]                         Mask : 000000000000FFFF

[0D0h 0208   1]                       Action : 05 [Execute Operation]
[0D1h 0209   1]                  Instruction : 03 [Write Register Value]
[0D2h 0210   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[0D3h 0211   1]                     Reserved : 00

[0D4h 0212  12]              Register Region : [Generic Address Structure]
[0D4h 0212   1]                     Space ID : 01 [SystemIO]
[0D5h 0213   1]                    Bit Width : 08
[0D6h 0214   1]                   Bit Offset : 00
[0D7h 0215   1]         Encoded Access Width : 01 [Byte Access:8]
[0D8h 0216   8]                      Address : 00000000000000B2

[0E0h 0224   8]                        Value : 0000000000000075
[0E8h 0232   8]                         Mask : 00000000000000FF

[0F0h 0240   1]                       Action : 06 [Check Busy Status]
[0F1h 0241   1]                  Instruction : 01 [Read Register Value]
[0F2h 0242   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[0F3h 0243   1]                     Reserved : 00

[0F4h 0244  12]              Register Region : [Generic Address Structure]
[0F4h 0244   1]                     Space ID : 00 [SystemMemory]
[0F5h 0245   1]                    Bit Width : 08
[0F6h 0246   1]                   Bit Offset : 00
[0F7h 0247   1]         Encoded Access Width : 01 [Byte Access:8]
[0F8h 0248   8]                      Address : 000000007D1D5EA6

[100h 0256   8]                        Value : 0000000000000001
[108h 0264   8]                         Mask : 0000000000000001

[110h 0272   1]                       Action : 07 [Get Command Status]
[111h 0273   1]                  Instruction : 00 [Read Register]
[112h 0274   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[113h 0275   1]                     Reserved : 00

[114h 0276  12]              Register Region : [Generic Address Structure]
[114h 0276   1]                     Space ID : 00 [SystemMemory]
[115h 0277   1]                    Bit Width : 10
[116h 0278   1]                   Bit Offset : 00
[117h 0279   1]         Encoded Access Width : 02 [Word Access:16]
[118h 0280   8]                      Address : 000000007D1D5EA8

[120h 0288   8]                        Value : 0000000000000000
[128h 0296   8]                         Mask : 000000000000FFFE

Raw Table Data: Length 304 (0x130)

    0000: 45 49 4E 4A 30 01 00 00 01 47 41 4D 49 00 00 00  // EINJ0....GAMI...
    0010: 41 4D 49 2E 45 49 4E 4A 00 00 00 00 41 4D 49 2E  // AMI.EINJ....AMI.
    0020: 00 00 00 00 0C 00 00 00 00 00 00 00 08 00 00 00  // ................
    0030: 00 03 00 00 00 08 00 01 98 5E 1D 7D 00 00 00 00  // .........^.}....
    0040: 00 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
    0050: 01 00 00 00 00 40 00 04 9A 5E 1D 7D 00 00 00 00  // .....@...^.}....
    0060: 00 00 00 00 00 00 00 00 FF FF FF FF FF FF FF FF  // ................
    0070: 02 02 00 00 00 20 00 03 A2 5E 1D 7D 00 00 00 00  // ..... ...^.}....
    0080: 00 00 00 00 00 00 00 00 FF FF FF FF 00 00 00 00  // ................
    0090: 03 00 00 00 00 20 00 03 AA 5E 1D 7D 00 00 00 00  // ..... ...^.}....
    00A0: 00 00 00 00 00 00 00 00 FF FF FF FF 00 00 00 00  // ................
    00B0: 04 03 00 00 00 10 00 02 AE 5E 1D 7D 00 00 00 00  // .........^.}....
    00C0: 00 00 00 00 00 00 00 00 FF FF 00 00 00 00 00 00  // ................
    00D0: 05 03 00 00 01 08 00 01 B2 00 00 00 00 00 00 00  // ................
    00E0: 75 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // u...............
    00F0: 06 01 00 00 00 08 00 01 A6 5E 1D 7D 00 00 00 00  // .........^.}....
    0100: 01 00 00 00 00 00 00 00 01 00 00 00 00 00 00 00  // ................
    0110: 07 00 00 00 00 10 00 02 A8 5E 1D 7D 00 00 00 00  // .........^.}....
    0120: 00 00 00 00 00 00 00 00 FE FF 00 00 00 00 00 00  // ................
