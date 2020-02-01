/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of hest.dat, Sun Oct  6 00:11:47 2019
 *
 * ACPI Data Table [HEST]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "HEST"    [Hardware Error Source Table]
[004h 0004   4]                 Table Length : 0000027C
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : 8E
[00Ah 0010   6]                       Oem ID : "AMI"
[010h 0016   8]                 Oem Table ID : "AMI.HEST"
[018h 0024   4]                 Oem Revision : 00000000
[01Ch 0028   4]              Asl Compiler ID : "AMI."
[020h 0032   4]        Asl Compiler Revision : 00000000

[024h 0036   4]           Error Source Count : 00000003

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
[040h 0064   8]                      Address : 000000007D21F018

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
[080h 0128   8]                      Address : 000000007D220020

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

[0A8h 0168   2]                Subtable Type : 0001 [IA-32 Corrected Machine Check]
[0AAh 0170   2]                    Source Id : 0002
[0ACh 0172   2]                    Reserved1 : 0000
[0AEh 0174   1]        Flags (decoded below) : 01
                              Firmware First : 1
                                 GHES Assist : 0
[0AFh 0175   1]                      Enabled : 01
[0B0h 0176   4]       Records To Preallocate : 00000001
[0B4h 0180   4]      Max Sections Per Record : 00000001

[0B8h 0184  28]                       Notify : [Hardware Error Notification Structure]
[0B8h 0184   1]                  Notify Type : 00 [Polled]
[0B9h 0185   1]                Notify Length : 1C
[0BAh 0186   2]   Configuration Write Enable : 0000
[0BCh 0188   4]                 PollInterval : 00000000
[0C0h 0192   4]                       Vector : 00000000
[0C4h 0196   4]      Polling Threshold Value : 00000009
[0C8h 0200   4]     Polling Threshold Window : 00000000
[0CCh 0204   4]        Error Threshold Value : 00000009
[0D0h 0208   4]       Error Threshold Window : 00000000

[0D4h 0212   1]           Num Hardware Banks : 0F
[0D5h 0213   3]                    Reserved2 : 000000

[0D8h 0216   1]                  Bank Number : 00
[0D9h 0217   1]         Clear Status On Init : 00
[0DAh 0218   1]                Status Format : 00
[0DBh 0219   1]                     Reserved : 00
[0DCh 0220   4]             Control Register : 00000000
[0E0h 0224   8]                 Control Data : 0000000000000010
[0E8h 0232   4]              Status Register : 00000000
[0ECh 0236   4]             Address Register : 00000000
[0F0h 0240   4]                Misc Register : 00000000

[0F4h 0244   1]                  Bank Number : 01
[0F5h 0245   1]         Clear Status On Init : 00
[0F6h 0246   1]                Status Format : 00
[0F7h 0247   1]                     Reserved : 00
[0F8h 0248   4]             Control Register : 00000000
[0FCh 0252   8]                 Control Data : 0000000000000010
[104h 0260   4]              Status Register : 00000000
[108h 0264   4]             Address Register : 00000000
[10Ch 0268   4]                Misc Register : 00000000

[110h 0272   1]                  Bank Number : 02
[111h 0273   1]         Clear Status On Init : 00
[112h 0274   1]                Status Format : 00
[113h 0275   1]                     Reserved : 00
[114h 0276   4]             Control Register : 00000000
[118h 0280   8]                 Control Data : 0000000000000010
[120h 0288   4]              Status Register : 00000000
[124h 0292   4]             Address Register : 00000000
[128h 0296   4]                Misc Register : 00000000

[12Ch 0300   1]                  Bank Number : 03
[12Dh 0301   1]         Clear Status On Init : 00
[12Eh 0302   1]                Status Format : 00
[12Fh 0303   1]                     Reserved : 00
[130h 0304   4]             Control Register : 00000000
[134h 0308   8]                 Control Data : 0000000000000010
[13Ch 0316   4]              Status Register : 00000000
[140h 0320   4]             Address Register : 00000000
[144h 0324   4]                Misc Register : 00000000

[148h 0328   1]                  Bank Number : 04
[149h 0329   1]         Clear Status On Init : 00
[14Ah 0330   1]                Status Format : 00
[14Bh 0331   1]                     Reserved : 00
[14Ch 0332   4]             Control Register : 00000000
[150h 0336   8]                 Control Data : 0000000000000010
[158h 0344   4]              Status Register : 00000000
[15Ch 0348   4]             Address Register : 00000000
[160h 0352   4]                Misc Register : 00000000

[164h 0356   1]                  Bank Number : 05
[165h 0357   1]         Clear Status On Init : 00
[166h 0358   1]                Status Format : 00
[167h 0359   1]                     Reserved : 00
[168h 0360   4]             Control Register : 00000000
[16Ch 0364   8]                 Control Data : 0000000000000010
[174h 0372   4]              Status Register : 00000000
[178h 0376   4]             Address Register : 00000000
[17Ch 0380   4]                Misc Register : 00000000

[180h 0384   1]                  Bank Number : 06
[181h 0385   1]         Clear Status On Init : 00
[182h 0386   1]                Status Format : 00
[183h 0387   1]                     Reserved : 00
[184h 0388   4]             Control Register : 00000000
[188h 0392   8]                 Control Data : 0000000000000010
[190h 0400   4]              Status Register : 00000000
[194h 0404   4]             Address Register : 00000000
[198h 0408   4]                Misc Register : 00000000

[19Ch 0412   1]                  Bank Number : 07
[19Dh 0413   1]         Clear Status On Init : 00
[19Eh 0414   1]                Status Format : 00
[19Fh 0415   1]                     Reserved : 00
[1A0h 0416   4]             Control Register : 00000000
[1A4h 0420   8]                 Control Data : 0000000000000010
[1ACh 0428   4]              Status Register : 00000000
[1B0h 0432   4]             Address Register : 00000000
[1B4h 0436   4]                Misc Register : 00000000

[1B8h 0440   1]                  Bank Number : 08
[1B9h 0441   1]         Clear Status On Init : 00
[1BAh 0442   1]                Status Format : 00
[1BBh 0443   1]                     Reserved : 00
[1BCh 0444   4]             Control Register : 00000000
[1C0h 0448   8]                 Control Data : 0000000000000010
[1C8h 0456   4]              Status Register : 00000000
[1CCh 0460   4]             Address Register : 00000000
[1D0h 0464   4]                Misc Register : 00000000

[1D4h 0468   1]                  Bank Number : 09
[1D5h 0469   1]         Clear Status On Init : 00
[1D6h 0470   1]                Status Format : 00
[1D7h 0471   1]                     Reserved : 00
[1D8h 0472   4]             Control Register : 00000000
[1DCh 0476   8]                 Control Data : 0000000000000010
[1E4h 0484   4]              Status Register : 00000000
[1E8h 0488   4]             Address Register : 00000000
[1ECh 0492   4]                Misc Register : 00000000

[1F0h 0496   1]                  Bank Number : 0A
[1F1h 0497   1]         Clear Status On Init : 00
[1F2h 0498   1]                Status Format : 00
[1F3h 0499   1]                     Reserved : 00
[1F4h 0500   4]             Control Register : 00000000
[1F8h 0504   8]                 Control Data : 0000000000000010
[200h 0512   4]              Status Register : 00000000
[204h 0516   4]             Address Register : 00000000
[208h 0520   4]                Misc Register : 00000000

[20Ch 0524   1]                  Bank Number : 0B
[20Dh 0525   1]         Clear Status On Init : 00
[20Eh 0526   1]                Status Format : 00
[20Fh 0527   1]                     Reserved : 00
[210h 0528   4]             Control Register : 00000000
[214h 0532   8]                 Control Data : 0000000000000010
[21Ch 0540   4]              Status Register : 00000000
[220h 0544   4]             Address Register : 00000000
[224h 0548   4]                Misc Register : 00000000

[228h 0552   1]                  Bank Number : 0C
[229h 0553   1]         Clear Status On Init : 00
[22Ah 0554   1]                Status Format : 00
[22Bh 0555   1]                     Reserved : 00
[22Ch 0556   4]             Control Register : 00000000
[230h 0560   8]                 Control Data : 0000000000000010
[238h 0568   4]              Status Register : 00000000
[23Ch 0572   4]             Address Register : 00000000
[240h 0576   4]                Misc Register : 00000000

[244h 0580   1]                  Bank Number : 0D
[245h 0581   1]         Clear Status On Init : 00
[246h 0582   1]                Status Format : 00
[247h 0583   1]                     Reserved : 00
[248h 0584   4]             Control Register : 00000000
[24Ch 0588   8]                 Control Data : 0000000000000010
[254h 0596   4]              Status Register : 00000000
[258h 0600   4]             Address Register : 00000000
[25Ch 0604   4]                Misc Register : 00000000

[260h 0608   1]                  Bank Number : 0E
[261h 0609   1]         Clear Status On Init : 00
[262h 0610   1]                Status Format : 00
[263h 0611   1]                     Reserved : 00
[264h 0612   4]             Control Register : 00000000
[268h 0616   8]                 Control Data : 0000000000000010
[270h 0624   4]              Status Register : 00000000
[274h 0628   4]             Address Register : 00000000
[278h 0632   4]                Misc Register : 00000000

Raw Table Data: Length 636 (0x27C)

    0000: 48 45 53 54 7C 02 00 00 01 8E 41 4D 49 00 00 00  // HEST|.....AMI...
    0010: 41 4D 49 2E 48 45 53 54 00 00 00 00 41 4D 49 2E  // AMI.HEST....AMI.
    0020: 00 00 00 00 03 00 00 00 09 00 00 00 FF FF 00 01  // ................
    0030: 01 00 00 00 01 00 00 00 00 10 00 00 00 40 00 04  // .............@..
    0040: 18 F0 21 7D 00 00 00 00 04 1C 00 00 00 00 00 00  // ..!}............
    0050: 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    0060: 00 00 00 00 00 10 00 00 09 00 01 00 FF FF 00 01  // ................
    0070: 01 00 00 00 01 00 00 00 00 10 00 00 00 40 00 04  // .............@..
    0080: 20 00 22 7D 00 00 00 00 00 1C 3E 00 60 EA 00 00  //  ."}......>.`...
    0090: 02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    00A0: 00 00 00 00 00 10 00 00 01 00 02 00 00 00 01 01  // ................
    00B0: 01 00 00 00 01 00 00 00 00 1C 00 00 00 00 00 00  // ................
    00C0: 00 00 00 00 09 00 00 00 00 00 00 00 09 00 00 00  // ................
    00D0: 00 00 00 00 0F 00 00 00 00 00 00 00 00 00 00 00  // ................
    00E0: 10 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    00F0: 00 00 00 00 01 00 00 00 00 00 00 00 10 00 00 00  // ................
    0100: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    0110: 02 00 00 00 00 00 00 00 10 00 00 00 00 00 00 00  // ................
    0120: 00 00 00 00 00 00 00 00 00 00 00 00 03 00 00 00  // ................
    0130: 00 00 00 00 10 00 00 00 00 00 00 00 00 00 00 00  // ................
    0140: 00 00 00 00 00 00 00 00 04 00 00 00 00 00 00 00  // ................
    0150: 10 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    0160: 00 00 00 00 05 00 00 00 00 00 00 00 10 00 00 00  // ................
    0170: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    0180: 06 00 00 00 00 00 00 00 10 00 00 00 00 00 00 00  // ................
    0190: 00 00 00 00 00 00 00 00 00 00 00 00 07 00 00 00  // ................
    01A0: 00 00 00 00 10 00 00 00 00 00 00 00 00 00 00 00  // ................
    01B0: 00 00 00 00 00 00 00 00 08 00 00 00 00 00 00 00  // ................
    01C0: 10 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    01D0: 00 00 00 00 09 00 00 00 00 00 00 00 10 00 00 00  // ................
    01E0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    01F0: 0A 00 00 00 00 00 00 00 10 00 00 00 00 00 00 00  // ................
    0200: 00 00 00 00 00 00 00 00 00 00 00 00 0B 00 00 00  // ................
    0210: 00 00 00 00 10 00 00 00 00 00 00 00 00 00 00 00  // ................
    0220: 00 00 00 00 00 00 00 00 0C 00 00 00 00 00 00 00  // ................
    0230: 10 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    0240: 00 00 00 00 0D 00 00 00 00 00 00 00 10 00 00 00  // ................
    0250: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  // ................
    0260: 0E 00 00 00 00 00 00 00 10 00 00 00 00 00 00 00  // ................
    0270: 00 00 00 00 00 00 00 00 00 00 00 00              // ............
