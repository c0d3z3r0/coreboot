/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembly of slic.dat, Mon Aug 12 12:51:47 2019
 *
 * ACPI Data Table [SLIC]
 *
 * Format: [HexOffset DecimalOffset ByteLength]  FieldName : FieldValue
 */

[000h 0000   4]                    Signature : "SLIC"    [Software Licensing Description Table]
[004h 0004   4]                 Table Length : 00000176
[008h 0008   1]                     Revision : 01
[009h 0009   1]                     Checksum : E8
[00Ah 0010   6]                       Oem ID : "LENOVO"
[010h 0016   8]                 Oem Table ID : "TC-S06  "
[018h 0024   4]                 Oem Revision : 00001270
[01Ch 0028   4]              Asl Compiler ID : "AMI "
[020h 0032   4]        Asl Compiler Revision : 00010013

[024h 0036 338] Software Licensing Structure : \
    00 00 00 00 9C 00 00 00 06 02 00 00 00 24 00 00 \
    52 53 41 31 00 04 00 00 01 00 01 00 69 16 4A 9F \
    B1 4B 3A FB 80 20 AA AF C4 F9 3E C1 80 49 EE 6A \
    65 26 72 1E CD BF 5F 2F 96 D6 C0 0A 92 F5 06 B5 \
    00 B2 3B 29 02 E2 4C 8D C2 F2 BC 41 77 9C 70 F0 \
    F3 1B 09 D2 63 5A DC A8 83 F8 5E C9 15 95 F9 FA \
    FD DC 05 B7 4D 67 7F 2D B3 84 33 20 E1 D1 79 2A \
    A7 6A 77 D1 B6 20 2A 76 42 C5 D5 E9 B6 43 40 55 \
    44 C3 C9 37 99 5F 41 97 70 F3 D1 F6 07 EC 7B 1A \
    29 A1 C1 F1 91 FD 48 86 6E 3E CE CB 01 00 00 00 \
    B6 00 00 00 00 00 02 00 4C 45 4E 4F 56 4F 54 43 \
    2D 53 30 36 20 20 57 49 4E 44 4F 57 53 20 04 00 \
    02 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 \
    00 00 BE 43 50 3F 68 40 1F 96 F4 FC 4F 49 D4 27 \
    D9 20 C6 43 77 50 BF 6B D7 3F 7E 0E 7F AA C5 30 \
    83 AA 52 1A F5 17 0A A7 E9 EE 66 97 20 A1 B3 4B \
    4C 98 70 84 27 CC F9 06 5D 16 F2 44 87 13 CB BB \
    8D 29 BB F4 19 AD 0E 8E 92 20 93 74 D3 2A D3 A6 \
    D4 9D 00 53 00 4C EC 8E 8D D6 5A 2A 72 45 85 D6 \
    AB 6C F0 D2 3C 7A 88 EF 56 5E 99 53 37 D3 A1 4C \
    F6 91 52 C6 52 E8 76 D1 F4 09 EB 9F 54 6B 3C C6 \
    83 21 

Raw Table Data: Length 374 (0x176)

    0000: 53 4C 49 43 76 01 00 00 01 E8 4C 45 4E 4F 56 4F  // SLICv.....LENOVO
    0010: 54 43 2D 53 30 36 20 20 70 12 00 00 41 4D 49 20  // TC-S06  p...AMI 
    0020: 13 00 01 00 00 00 00 00 9C 00 00 00 06 02 00 00  // ................
    0030: 00 24 00 00 52 53 41 31 00 04 00 00 01 00 01 00  // .$..RSA1........
    0040: 69 16 4A 9F B1 4B 3A FB 80 20 AA AF C4 F9 3E C1  // i.J..K:.. ....>.
    0050: 80 49 EE 6A 65 26 72 1E CD BF 5F 2F 96 D6 C0 0A  // .I.je&r..._/....
    0060: 92 F5 06 B5 00 B2 3B 29 02 E2 4C 8D C2 F2 BC 41  // ......;)..L....A
    0070: 77 9C 70 F0 F3 1B 09 D2 63 5A DC A8 83 F8 5E C9  // w.p.....cZ....^.
    0080: 15 95 F9 FA FD DC 05 B7 4D 67 7F 2D B3 84 33 20  // ........Mg.-..3 
    0090: E1 D1 79 2A A7 6A 77 D1 B6 20 2A 76 42 C5 D5 E9  // ..y*.jw.. *vB...
    00A0: B6 43 40 55 44 C3 C9 37 99 5F 41 97 70 F3 D1 F6  // .C@UD..7._A.p...
    00B0: 07 EC 7B 1A 29 A1 C1 F1 91 FD 48 86 6E 3E CE CB  // ..{.).....H.n>..
    00C0: 01 00 00 00 B6 00 00 00 00 00 02 00 4C 45 4E 4F  // ............LENO
    00D0: 56 4F 54 43 2D 53 30 36 20 20 57 49 4E 44 4F 57  // VOTC-S06  WINDOW
    00E0: 53 20 04 00 02 00 00 00 00 00 00 00 00 00 00 00  // S ..............
    00F0: 00 00 00 00 00 00 BE 43 50 3F 68 40 1F 96 F4 FC  // .......CP?h@....
    0100: 4F 49 D4 27 D9 20 C6 43 77 50 BF 6B D7 3F 7E 0E  // OI.'. .CwP.k.?~.
    0110: 7F AA C5 30 83 AA 52 1A F5 17 0A A7 E9 EE 66 97  // ...0..R.......f.
    0120: 20 A1 B3 4B 4C 98 70 84 27 CC F9 06 5D 16 F2 44  //  ..KL.p.'...]..D
    0130: 87 13 CB BB 8D 29 BB F4 19 AD 0E 8E 92 20 93 74  // .....)....... .t
    0140: D3 2A D3 A6 D4 9D 00 53 00 4C EC 8E 8D D6 5A 2A  // .*.....S.L....Z*
    0150: 72 45 85 D6 AB 6C F0 D2 3C 7A 88 EF 56 5E 99 53  // rE...l..<z..V^.S
    0160: 37 D3 A1 4C F6 91 52 C6 52 E8 76 D1 F4 09 EB 9F  // 7..L..R.R.v.....
    0170: 54 6B 3C C6 83 21                                // Tk<..!
