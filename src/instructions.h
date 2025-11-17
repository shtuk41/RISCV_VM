#pragma once

#include <cassert>
#include <cstdint>

using reg = unsigned int;
#define x0 0;
#define zero 0;
#define x1 1;   //return
#define x2 2;   //sp
#define x3 3;
#define x4 4;
#define x5 5;   //alternative link
#define x6 6;
#define x7 7;
#define x8 8;
#define x9 9;
#define x10 10;
#define x11 11;
#define x12 12;
#define x13 13;
#define x14 14;
#define x15 15;
#define x16 16;
#define x17 17;
#define x18 18;
#define x19 19;
#define x20 20;
#define x21 21;
#define x22 22;
#define x23 23;
#define x24 24;
#define x25 25;
#define x26 26;
#define x27 27;
#define x28 28;
#define x29 29;
#define x30 30;
#define x31 31;


typedef struct regfile
{
    reg registers[32];
    reg pc;
} regfile;

struct type
{
private:
    uint32_t value;
public:
    explicit type(uint32_t v = 0) : value(v) {}

    constexpr uint32_t bits(int hi, int lo) const 
    {
        return (value >> lo) & ((1u << (hi - lo + 1)) - 1);
    }

    constexpr uint32_t bits(int num) const 
    {
        return (value >> num) & 1u;
    }

    constexpr uint32_t bits_set(uint32_t val, int hi, int lo)
    {
        uint32_t mask = ((1u << (hi - lo + 1)) - 1) << lo;
        value = (value & ~mask) | ((val << lo) & mask);
        return value;
    }

    constexpr uint32_t bits_set(uint32_t val, int num)
    {
        assert(val <= 1);
        uint32_t mask = (1u << num);
        value = (value & ~mask) | ((val << num) & mask);
        return value;
    }

    constexpr operator uint32_t() const {return value;}
};

struct rinst : private type
{
    using type::type;

    //gets
    constexpr uint32_t funct7() const { return bits(31, 25);}
    constexpr uint32_t rs2() const { return bits(24, 20);}
    constexpr uint32_t rs1() const { return bits(19, 15);}
    constexpr uint32_t funct3() const { return bits(14, 12);}
    constexpr uint32_t rd() const {return bits(11,7); }
    constexpr uint32_t opcode() const { return bits(6,0);} 

    //sets
    constexpr uint32_t funct7(uint32_t val) { return bits_set(val,31, 25);}
    constexpr uint32_t rs2(uint32_t val) { return bits_set(val, 24, 20);}
    constexpr uint32_t rs1(uint32_t val) { return bits_set(val, 9, 15);}
    constexpr uint32_t funct3(uint32_t val) { return bits_set(val, 14, 12);}
    constexpr uint32_t rd(uint32_t val) {return bits_set(val, 11,7); }
    constexpr uint32_t opcode(uint32_t val) { return bits_set(val, 6,0);} 
};

struct iinst : private type
{
    using type::type;

    //gets
    constexpr uint32_t imm() const { return bits(31, 20);}
    constexpr uint32_t rs1() const { return bits(19, 15);}
    constexpr uint32_t funct3() const { return bits(14, 12);}
    constexpr uint32_t rd() const {return bits(11,7); }
    constexpr uint32_t opcode() const { return bits(6,0);} 

    //sets
    constexpr uint32_t imm(uint32_t val) { return bits_set(val,31, 20);}
    constexpr uint32_t rs1(uint32_t val) { return bits_set(val, 9, 15);}
    constexpr uint32_t funct3(uint32_t val) { return bits_set(val, 14, 12);}
    constexpr uint32_t rd(uint32_t val) {return bits_set(val, 11,7); }
    constexpr uint32_t opcode(uint32_t val) { return bits_set(val, 6,0);} 
};

struct sinst : private type
{
    using type::type;

    //gets
    constexpr uint32_t imm11_5() const { return bits(31, 25);}
    constexpr uint32_t rs2() const { return bits(24, 20);}
    constexpr uint32_t rs1() const { return bits(19, 15);}
    constexpr uint32_t funct3() const { return bits(14, 12);}
    constexpr uint32_t imm4_0() const {return bits(11,7); }
    constexpr uint32_t opcode() const { return bits(6,0);} 

    //sets
    constexpr uint32_t imm11_5(uint32_t val) { return bits_set(val, 31, 25);}
    constexpr uint32_t rs2(uint32_t val) { return bits_set(val, 24, 20);}
    constexpr uint32_t rs1(uint32_t val) { return bits_set(val, 19, 15);}
    constexpr uint32_t funct3(uint32_t val) { return bits_set(val, 14, 12);}
    constexpr uint32_t imm4_0(uint32_t val) {return bits_set(val, 11,7); }
    constexpr uint32_t opcode(uint32_t val) { return bits_set(val, 6,0);} 
};

struct binst : private type
{
    using type::type;

    //gets
    constexpr uint32_t imm12() const {return bits(31);}
    constexpr uint32_t imm10_5() const { return bits(30, 25);}
    constexpr uint32_t rs2() const { return bits(24, 20);}
    constexpr uint32_t rs1() const { return bits(19, 15);}
    constexpr uint32_t funct3() const { return bits(14, 12);}
    constexpr uint32_t imm4_1() const {return bits(11,8); }
    constexpr uint32_t imm11() const {return bits(7); }
    constexpr uint32_t opcode() const { return bits(6,0);} 

    //sets
    constexpr uint32_t imm12(uint32_t val) {return bits_set(val, 31);}
    constexpr uint32_t imm10_5(uint32_t val) { return bits_set(val, 30, 25);}
    constexpr uint32_t rs2(uint32_t val) { return bits_set(val, 24, 20);}
    constexpr uint32_t rs1(uint32_t val) { return bits_set(val, 19, 15);}
    constexpr uint32_t funct3(uint32_t val) { return bits_set(val, 14, 12);}
    constexpr uint32_t imm4_1(uint32_t val) {return bits_set(val, 11,8); }
    constexpr uint32_t imm11(uint32_t val) {return bits_set(val, 7);}
    constexpr uint32_t opcode(uint32_t val) { return bits_set(val, 6,0);} 
};


struct uinst : private type
{
    using type::type;

    //gets
    constexpr uint32_t imm() const { return bits(31, 12);}
    constexpr uint32_t rd() const { return bits(11, 7);}
    constexpr uint32_t opcode() const { return bits(6,0);} 

    //sets
    constexpr uint32_t imm(uint32_t val) { return bits_set(val, 31, 12);}
    constexpr uint32_t rd(uint32_t val) { return bits_set(val, 11, 7);}
    constexpr uint32_t opcode(uint32_t val) { return bits_set(val, 6,0);} 
};

struct jinst : private type
{
    using type::type;

    //gets
    constexpr uint32_t imm20() const { return bits(31);}
    constexpr uint32_t imm10_1() const { return bits(30, 21);}
    constexpr uint32_t imm11() const { return bits(20);}
    constexpr uint32_t imm19_12() const { return bits(19, 12);}
    constexpr uint32_t rd() const { return bits(11, 7);}
    constexpr uint32_t opcode() const { return bits(6,0);} 

    //sets
    constexpr uint32_t imm20(uint32_t val)  { return bits_set(val, 31);}
    constexpr uint32_t imm10_1(uint32_t val)  { return bits_set(val, 30, 21);}
    constexpr uint32_t imm11(uint32_t val)  { return bits_set(val, 20);}
    constexpr uint32_t imm19_12(uint32_t val)  { return bits_set(val, 19, 12);}
    constexpr uint32_t rd(uint32_t val) { return bits_set(val, 11, 7);}
    constexpr uint32_t opcode(uint32_t val) { return bits_set(val, 6,0);} 
};

struct iimm: private type
{
    using type::type;
    
    //gets
    constexpr uint32_t inst31() const {return bits(31,11);}
    constexpr uint32_t inst30_25() const {return bits(10,5);}
    constexpr uint32_t inst24_21() const {return bits(4, 1);}
    constexpr uint32_t inst20() const {return bits(0);}

    //sets
    constexpr uint32_t inst31(uint32_t val) { return bits_set(val, 31, 11);}
    constexpr uint32_t inst30_25(uint32_t val) {return bits_set(val, 10,5);}
    constexpr uint32_t inst24_21(uint32_t val) {return bits_set(val, 4, 1);}
    constexpr uint32_t inst20(uint32_t val) {return bits_set(val, 0);}
};

struct simm: private type
{
    using type::type;
    
    //gets
    constexpr uint32_t inst31() const {return bits(31,11);}
    constexpr uint32_t inst30_25() const {return bits(10,5);}
    constexpr uint32_t inst11_8() const {return bits(4, 1);}
    constexpr uint32_t inst7() const {return bits(0);}

    //sets
    constexpr uint32_t inst31(uint32_t val) { return bits_set(val, 31, 11);}
    constexpr uint32_t inst30_25(uint32_t val) {return bits_set(val, 10,5);}
    constexpr uint32_t inst11_8(uint32_t val) {return bits_set(val, 4, 1);}
    constexpr uint32_t inst7(uint32_t val) {return bits_set(val, 0);}
};

struct bimm: private type
{
    using type::type;
    
    //gets
    constexpr uint32_t inst31() const {return bits(31,12);}
    constexpr uint32_t inst7() const {return bits(0);}
    constexpr uint32_t inst30_25() const {return bits(10,5);}
    constexpr uint32_t inst11_8() const {return bits(4, 1);}
    constexpr uint32_t inst0() const {return bits(0);}

    //sets
    constexpr uint32_t inst31(uint32_t val)  {return bits_set(val, 31,12);}
    constexpr uint32_t inst7(uint32_t val)  {return bits_set(val, 0);}
    constexpr uint32_t inst30_25(uint32_t val)  {return bits_set(val, 10,5);}
    constexpr uint32_t inst11_8(uint32_t val)  {return bits_set(val, , 1);}
    constexpr uint32_t inst0(uint32_t val)  {return bits_set(val, 0);}
};

struct uimm: private type
{
    using type::type;

    //gets
    constexpr uint32_t inst31() const { return bits(31);}
    constexpr uint32_t inst30_20() const { return bits(30, 20);}
    constexpr uint32_t inst19_12() const { return bits(19, 12);}
    constexpr uint32_t inst0() const { return bits(11,0); }

    //sets
    constexpr uint32_t inst31(uint32_t val) { return bits_set(val, 31);}
    constexpr uint32_t inst30_20(uint32_t val) { return bits_set(val, 30, 20);}
    constexpr uint32_t inst19_12(uint32_t val) { return bits_set(val, 19, 12);}
    constexpr uint32_t inst0(int32_t val) { return bits_set(val, 11, 0); }
};

struct jimm: private type
{
    using type::type;

    //gets
    constexpr uint32_t inst31() const { return bits(31,20);}
    constexpr uint32_t inst19_12() const { return bits(19, 12);}
    constexpr uint32_t inst20() const {return bits(20);}
    constexpr uint32_t inst30_25() const { return bits(10,5);}
    constexpr uint32_t inst0() const {return bits(0);}

    //sets
    constexpr uint32_t inst31(uint32_t val) { return bits_set(val, 31,20);}
    constexpr uint32_t inst19_12(uint32_t val) { return bits_set(val, 19, 12);}
    constexpr uint32_t inst20(uint32_t val) {return bits_set(val, 20);}
    constexpr uint32_t inst30_25(uint32_t val) { return bits_set(val, 10, 5);}
    constexpr uint32_t inst0(uint32_t val)  {return bits_set(val, 0);}
};









