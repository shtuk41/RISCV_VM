VM for running a machine code generated for RISV V processor

### Install GCC

sudo apt update<br>
sudo apt install gcc-riscv64-unknown-elf<br>
riscv64-unknown-elf-gcc --version<br>

riscv64-unknown-elf-gcc -march=rv32im -mabi=ilp32 main.c -o main32.elf <br>
riscv64-unknown-elf-readelf -h main.elf<br>

