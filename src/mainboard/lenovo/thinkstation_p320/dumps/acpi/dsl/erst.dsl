/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of erst.dat, Mon Aug 12 12:51:47 2019
 *
 * ACPI Data Table [ERST]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "ERST"    [Error Record Serialization Table]
[004h 0004   4]                 Table Length : 00000230
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : 58
[00Ah 0010   6]                       Oem ID : "LENOVO"
[010h 0016   8]                 Oem Table ID : "TC-S06  "
[018h 0024   4]                 Oem Revision : 00001270
[01Ch 0028   4]              Asl Compiler ID : "AMI."
[020h 0032   4]        Asl Compiler Revision : 00000000

[024h 0036   4]  Serialization Header Length : 0000000C
[028h 0040   4]                     Reserved : 00000000
[02Ch 0044   4]      Instruction Entry Count : 00000010

[030h 0048   1]                       Action : 00 [Begin Write Operation]
[031h 0049   1]                  Instruction : 03 [Write Register Value]
[032h 0050   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[033h 0051   1]                     Reserved : 00

[034h 0052  12]              Register Region : [Generic Address Structure]
[034h 0052   1]                     Space ID : 00 [SystemMemory]
[035h 0053   1]                    Bit Width : 08
[036h 0054   1]                   Bit Offset : 00
[037h 0055   1]         Encoded Access Width : 01 [Byte Access:8]
[038h 0056   8]                      Address : 000000009E1A3018

[040h 0064   8]                        Value : 0000000000000000
[048h 0072   8]                         Mask : 00000000000000FF

[050h 0080   1]                       Action : 01 [Begin Read Operation]
[051h 0081   1]                  Instruction : 03 [Write Register Value]
[052h 0082   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[053h 0083   1]                     Reserved : 00

[054h 0084  12]              Register Region : [Generic Address Structure]
[054h 0084   1]                     Space ID : 00 [SystemMemory]
[055h 0085   1]                    Bit Width : 08
[056h 0086   1]                   Bit Offset : 00
[057h 0087   1]         Encoded Access Width : 01 [Byte Access:8]
[058h 0088   8]                      Address : 000000009E1A3018

[060h 0096   8]                        Value : 0000000000000001
[068h 0104   8]                         Mask : 00000000000000FF

[070h 0112   1]                       Action : 02 [Begin Clear Operation]
[071h 0113   1]                  Instruction : 03 [Write Register Value]
[072h 0114   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[073h 0115   1]                     Reserved : 00

[074h 0116  12]              Register Region : [Generic Address Structure]
[074h 0116   1]                     Space ID : 00 [SystemMemory]
[075h 0117   1]                    Bit Width : 08
[076h 0118   1]                   Bit Offset : 00
[077h 0119   1]         Encoded Access Width : 01 [Byte Access:8]
[078h 0120   8]                      Address : 000000009E1A3018

[080h 0128   8]                        Value : 0000000000000002
[088h 0136   8]                         Mask : 00000000000000FF

[090h 0144   1]                       Action : 03 [End Operation]
[091h 0145   1]                  Instruction : 03 [Write Register Value]
[092h 0146   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[093h 0147   1]                     Reserved : 00

[094h 0148  12]              Register Region : [Generic Address Structure]
[094h 0148   1]                     Space ID : 00 [SystemMemory]
[095h 0149   1]                    Bit Width : 08
[096h 0150   1]                   Bit Offset : 00
[097h 0151   1]         Encoded Access Width : 01 [Byte Access:8]
[098h 0152   8]                      Address : 000000009E1A3019

[0A0h 0160   8]                        Value : 0000000000000003
[0A8h 0168   8]                         Mask : 00000000000000FF

[0B0h 0176   1]                       Action : 04 [Set Record Offset]
[0B1h 0177   1]                  Instruction : 02 [Write Register]
[0B2h 0178   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[0B3h 0179   1]                     Reserved : 00

[0B4h 0180  12]              Register Region : [Generic Address Structure]
[0B4h 0180   1]                     Space ID : 00 [SystemMemory]
[0B5h 0181   1]                    Bit Width : 20
[0B6h 0182   1]                   Bit Offset : 00
[0B7h 0183   1]         Encoded Access Width : 03 [DWord Access:32]
[0B8h 0184   8]                      Address : 000000009E1A301C

[0C0h 0192   8]                        Value : 0000000000000000
[0C8h 0200   8]                         Mask : 00000000FFFFFFFF

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

[0E0h 0224   8]                        Value : 0000000000000070
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
[0F8h 0248   8]                      Address : 000000009E1A3020

[100h 0256   8]                        Value : 0000000000000001
[108h 0264   8]                         Mask : 00000000000000FF

[110h 0272   1]                       Action : 07 [Get Command Status]
[111h 0273   1]                  Instruction : 00 [Read Register]
[112h 0274   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[113h 0275   1]                     Reserved : 00

[114h 0276  12]              Register Region : [Generic Address Structure]
[114h 0276   1]                     Space ID : 00 [SystemMemory]
[115h 0277   1]                    Bit Width : 08
[116h 0278   1]                   Bit Offset : 00
[117h 0279   1]         Encoded Access Width : 01 [Byte Access:8]
[118h 0280   8]                      Address : 000000009E1A3021

[120h 0288   8]                        Value : 0000000000000000
[128h 0296   8]                         Mask : 00000000000000FF

[130h 0304   1]                       Action : 08 [Get Record Identifier]
[131h 0305   1]                  Instruction : 00 [Read Register]
[132h 0306   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[133h 0307   1]                     Reserved : 00

[134h 0308  12]              Register Region : [Generic Address Structure]
[134h 0308   1]                     Space ID : 00 [SystemMemory]
[135h 0309   1]                    Bit Width : 40
[136h 0310   1]                   Bit Offset : 00
[137h 0311   1]         Encoded Access Width : 04 [QWord Access:64]
[138h 0312   8]                      Address : 000000009E1A3028

[140h 0320   8]                        Value : 0000000000000000
[148h 0328   8]                         Mask : FFFFFFFFFFFFFFFF

[150h 0336   1]                       Action : 09 [Set Record Identifier]
[151h 0337   1]                  Instruction : 02 [Write Register]
[152h 0338   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[153h 0339   1]                     Reserved : 00

[154h 0340  12]              Register Region : [Generic Address Structure]
[154h 0340   1]                     Space ID : 00 [SystemMemory]
[155h 0341   1]                    Bit Width : 40
[156h 0342   1]                   Bit Offset : 00
[157h 0343   1]         Encoded Access Width : 04 [QWord Access:64]
[158h 0344   8]                      Address : 000000009E1A3030

[160h 0352   8]                        Value : 0000000000000000
[168h 0360   8]                         Mask : FFFFFFFFFFFFFFFF

[170h 0368   1]                       Action : 0A [Get Record Count]
[171h 0369   1]                  Instruction : 00 [Read Register]
[172h 0370   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[173h 0371   1]                     Reserved : 00

[174h 0372  12]              Register Region : [Generic Address Structure]
[174h 0372   1]                     Space ID : 00 [SystemMemory]
[175h 0373   1]                    Bit Width : 10
[176h 0374   1]                   Bit Offset : 00
[177h 0375   1]         Encoded Access Width : 02 [Word Access:16]
[178h 0376   8]                      Address : 000000009E1A3038

[180h 0384   8]                        Value : 0000000000000000
[188h 0392   8]                         Mask : 000000000000FFFF

[190h 0400   1]                       Action : 0B [Begin Dummy Write]
[191h 0401   1]                  Instruction : 03 [Write Register Value]
[192h 0402   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[193h 0403   1]                     Reserved : 00

[194h 0404  12]              Register Region : [Generic Address Structure]
[194h 0404   1]                     Space ID : 00 [SystemMemory]
[195h 0405   1]                    Bit Width : 08
[196h 0406   1]                   Bit Offset : 00
[197h 0407   1]         Encoded Access Width : 01 [Byte Access:8]
[198h 0408   8]                      Address : 000000009E1A3018

[1A0h 0416   8]                        Value : 000000000000000B
[1A8h 0424   8]                         Mask : 00000000000000FF

[1B0h 0432   1]                       Action : 0C [Unused/Unknown Action]
[1B1h 0433   1]                  Instruction : 04 [Noop]
[1B2h 0434   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[1B3h 0435   1]                     Reserved : 00

[1B4h 0436  12]              Register Region : [Generic Address Structure]
[1B4h 0436   1]                     Space ID : 00 [SystemMemory]
[1B5h 0437   1]                    Bit Width : 08
[1B6h 0438   1]                   Bit Offset : 00
[1B7h 0439   1]         Encoded Access Width : 01 [Byte Access:8]
[1B8h 0440   8]                      Address : 0000000000000000

[1C0h 0448   8]                        Value : 0000000000000000
[1C8h 0456   8]                         Mask : 00000000000000FF

[1D0h 0464   1]                       Action : 0D [Get Error Address Range]
[1D1h 0465   1]                  Instruction : 00 [Read Register]
[1D2h 0466   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[1D3h 0467   1]                     Reserved : 00

[1D4h 0468  12]              Register Region : [Generic Address Structure]
[1D4h 0468   1]                     Space ID : 00 [SystemMemory]
[1D5h 0469   1]                    Bit Width : 40
[1D6h 0470   1]                   Bit Offset : 00
[1D7h 0471   1]         Encoded Access Width : 04 [QWord Access:64]
[1D8h 0472   8]                      Address : 000000009E1A3040

[1E0h 0480   8]                        Value : 0000000000000000
[1E8h 0488   8]                         Mask : FFFFFFFFFFFFFFFF

[1F0h 0496   1]                       Action : 0E [Get Error Address Length]
[1F1h 0497   1]                  Instruction : 00 [Read Register]
[1F2h 0498   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[1F3h 0499   1]                     Reserved : 00

[1F4h 0500  12]              Register Region : [Generic Address Structure]
[1F4h 0500   1]                     Space ID : 00 [SystemMemory]
[1F5h 0501   1]                    Bit Width : 20
[1F6h 0502   1]                   Bit Offset : 00
[1F7h 0503   1]         Encoded Access Width : 03 [DWord Access:32]
[1F8h 0504   8]                      Address : 000000009E1A3048

[200h 0512   8]                        Value : 0000000000000000
[208h 0520   8]                         Mask : 00000000FFFFFFFF

[210h 0528   1]                       Action : 0F [Get Error Attributes]
[211h 0529   1]                  Instruction : 00 [Read Register]
[212h 0530   1]        Flags (decoded below) : 00
                      Preserve Register Bits : 0
[213h 0531   1]                     Reserved : 00

[214h 0532  12]              Register Region : [Generic Address Structure]
[214h 0532   1]                     Space ID : 00 [SystemMemory]
[215h 0533   1]                    Bit Width : 08
[216h 0534   1]                   Bit Offset : 00
[217h 0535   1]         Encoded Access Width : 01 [Byte Access:8]
[218h 0536   8]                      Address : 000000009E1A304C

[220h 0544   8]                        Value : 0000000000000000
[228h 0552   8]                         Mask : 00000000000000FF

Raw Table Data: Length 560 (0x230)

    0000: 45 52 53 54 30 02 00 00 01 58 4C 45 4E 4F 56 4F  // ERST0....XLENOVO
    0010: 54 43 2D 53 30 36 20 20 70 12 00 00 41 4D 49 2E  // TC-S06  p...AMI.
    0020: 00 00 00 00 0C 00 00 00 00 00 00 00 10 00 00 00  // ................
    0030: 00 03 00 00 00 08 00 01 18 30 1A 9E 00 00 00 00  // .........0......
    0040: 00 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
    0050: 01 03 00 00 00 08 00 01 18 30 1A 9E 00 00 00 00  // .........0......
    0060: 01 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
    0070: 02 03 00 00 00 08 00 01 18 30 1A 9E 00 00 00 00  // .........0......
    0080: 02 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
    0090: 03 03 00 00 00 08 00 01 19 30 1A 9E 00 00 00 00  // .........0......
    00A0: 03 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
    00B0: 04 02 00 00 00 20 00 03 1C 30 1A 9E 00 00 00 00  // ..... ...0......
    00C0: 00 00 00 00 00 00 00 00 FF FF FF FF 00 00 00 00  // ................
    00D0: 05 03 00 00 01 08 00 01 B2 00 00 00 00 00 00 00  // ................
    00E0: 70 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // p...............
    00F0: 06 01 00 00 00 08 00 01 20 30 1A 9E 00 00 00 00  // ........ 0......
    0100: 01 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
    0110: 07 00 00 00 00 08 00 01 21 30 1A 9E 00 00 00 00  // ........!0......
    0120: 00 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
    0130: 08 00 00 00 00 40 00 04 28 30 1A 9E 00 00 00 00  // .....@..(0......
    0140: 00 00 00 00 00 00 00 00 FF FF FF FF FF FF FF FF  // ................
    0150: 09 02 00 00 00 40 00 04 30 30 1A 9E 00 00 00 00  // .....@..00......
    0160: 00 00 00 00 00 00 00 00 FF FF FF FF FF FF FF FF  // ................
    0170: 0A 00 00 00 00 10 00 02 38 30 1A 9E 00 00 00 00  // ........80......
    0180: 00 00 00 00 00 00 00 00 FF FF 00 00 00 00 00 00  // ................
    0190: 0B 03 00 00 00 08 00 01 18 30 1A 9E 00 00 00 00  // .........0......
    01A0: 0B 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
    01B0: 0C 04 00 00 00 08 00 01 00 00 00 00 00 00 00 00  // ................
    01C0: 00 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
    01D0: 0D 00 00 00 00 40 00 04 40 30 1A 9E 00 00 00 00  // .....@..@0......
    01E0: 00 00 00 00 00 00 00 00 FF FF FF FF FF FF FF FF  // ................
    01F0: 0E 00 00 00 00 20 00 03 48 30 1A 9E 00 00 00 00  // ..... ..H0......
    0200: 00 00 00 00 00 00 00 00 FF FF FF FF 00 00 00 00  // ................
    0210: 0F 00 00 00 00 08 00 01 4C 30 1A 9E 00 00 00 00  // ........L0......
    0220: 00 00 00 00 00 00 00 00 FF 00 00 00 00 00 00 00  // ................
