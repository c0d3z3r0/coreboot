/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20190703 (64-bit version)
 * Copyright (c) 2000 - 2019 Intel Corporation
 * 
 * Disassembling to symbolic ASL+ operators
 *
 * Disassembly of ssdt10.dat, Sun Oct  6 00:11:47 2019
 *
 * Original Table Header:
 *     Signature        "SSDT"
 *     Length           0x00000130 (304)
 *     Revision         0x02
 *     Checksum         0x85
 *     OEM ID           "PmRef"
 *     OEM Table ID     "HwpLvt"
 *     OEM Revision     0x00003000 (12288)
 *     Compiler ID      "INTL"
 *     Compiler Version 0x20120913 (538052883)
 */
DefinitionBlock ("", "SSDT", 2, "PmRef", "HwpLvt", 0x00003000)
{
    External (_PR_.CPU0, ProcessorObj)
    External (_PR_.CPU1, ProcessorObj)
    External (_PR_.CPU2, ProcessorObj)
    External (_PR_.CPU3, ProcessorObj)
    External (_PR_.CPU4, ProcessorObj)
    External (_PR_.CPU5, ProcessorObj)
    External (_PR_.CPU6, ProcessorObj)
    External (_PR_.CPU7, ProcessorObj)
    External (TCNT, FieldUnitObj)

    Scope (\_GPE)
    {
        Method (HLVT, 0, Serialized)
        {
            Switch (ToInteger (TCNT))
            {
                Case (0x08)
                {
                    Notify (\_PR.CPU0, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU1, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU2, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU3, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU4, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU5, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU6, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU7, 0x83) // Guaranteed Change
                }
                Case (0x04)
                {
                    Notify (\_PR.CPU0, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU1, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU2, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU3, 0x83) // Guaranteed Change
                }
                Case (0x02)
                {
                    Notify (\_PR.CPU0, 0x83) // Guaranteed Change
                    Notify (\_PR.CPU1, 0x83) // Guaranteed Change
                }
                Default
                {
                    Notify (\_PR.CPU0, 0x83) // Guaranteed Change
                }

            }
        }
    }
}

