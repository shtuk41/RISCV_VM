#include "instructions.h"

bool execute(uint32_t code)
{
    uint32_t opcode = code & 0x7f;
    uint32_t funct3 = (code >> 12) & 0x7;
    uint32_t funct7 = (code >> 25) & 0b1111111;
    uint32_t bits31_25 = (code >> 25) & 0b111111111111;

    uint32_t key0 = (funct7 << 3) | funct3;
    uint32_t key1 = (bits31_25 << 8) | (funct3 << 5);

    switch (opcode)
    {
        case 0b0010011: 
            switch(funct3)
            {
                case 0b000: //ADDI
                break;
                case 0b010: //SLTI
                break;
                case 0b011: //SLTIU
                break;
                case 0b100: //XORI
                break;
                case 0b110: //ORI
                break;
                case 0b111: //ANDI
                break;
                case 0b001:
                    if (funct7 == 0b0000000)
                        ; //SLLI
                    else
                        return false; 
                case 0b101:
                    if (funct7 == 0b0000000)
                        ;//SRLI
                    else if (funct7 == 0b0100000)
                        ;//SRAI
                    else
                        return false; 
                default:
                    return false;
            }
        break;

        case 0b0110111: //LUI
            break;

        case 0b0010111: //AUIPC
            break;

        case 0b1101111: //JAL
            break;

        case 0b1100111:
            if (funct3 == 0x0)
                ;//JALR
            else
                return false;

            break;
        
        case 0b1100011:
            switch (funct3)
            {
                case 0b000:
                //BEQ
                break;
                case 0b001:
                //BNE
                break;
                case 0b100:
                //BLT
                case 0b101:
                //BGE    
                case 0b110:
                //BLTU    
                case 0b111:
                //BGEU 
                default:
                    return false;   
            }

            break;
        case 0b0000011:
            switch (funct3)
            {    
                case 0b000:// LB
                    break;
                case 0b001:// LH
                    break;
                case 0b010:// LW
                    break; 
                case 0b100:// LBU
                    break; 
                case 0b101:// LHU
                    break;
                default:
                    return false;
            }

        case 0b0100011:
            switch(funct3)
            {
                case 0b000:// SB 
                    break;
                case 0b001:// SH 
                    break;
                case 0b010:// SW
                    break;
                default:
                    return false; 
            }
        case 0b0110011:
            switch (key0)
            {
                case 0b0000000'000: // ADD 
                    break;
                case 0b0100000'000: // SUB
                    break;
                case 0b0000000'001: // SLL 
                    break;
                case 0b0000000'010: //  SLT
                    break;
                case 0b0000000'011: // SLTU
                    break; 
                case 0b0000000'100: //  XOR
                    break;
                case 0b0000000'101: //  SRL
                    break; 
                case 0b0100000'101: //  SRA
                    break; 
                case 0b0000000'110: //  OR
                    break; 
                case 0b0000000'111: //  and
                    break;
                default:
                    return false;
            }
        case 0b0001111:
            if (key1 == 0b1000'0011'0011'000'00000)
                    ; //FENCE.TSO
            else if (key1 == 0b0000'0001'0000'000'00000)
                    ; //PAUSE
            else if (funct3 == 0b000)
                    ; //FENCE
            else
                return false;
                
        case 0b111011:
            if (key1 ==  0b000000000000'000'00000)
                ;// ECALL
            else if (key1 == 000000000001'000'00000)
                ;//EBREAK
            else
                return false;
            
        default:
            return false;
    }

    return true;
}
