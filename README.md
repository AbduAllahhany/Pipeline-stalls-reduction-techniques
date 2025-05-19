
# 🚀 Simulation of Pipeline Stalls Reduction Techniques 

A simulation project that models and analyzes Enhance a 5-stage pipeline simulator (from Assignment 1) to implement and analyze techniques for reducing control hazards using RAS,BTB and branch prediction, with a focus on understanding and solving challenges that arose during development.


**Course Name:** ELE336 - Computer Architecture  
We extend our sincere gratitude and appreciation to Dr. May Salama for her exceptional supervision and dedication throughout the Computer Architecture course. Her clear explanations, continuous support, and insightful guidance greatly enriched our learning experience. 

---

## 📚 Table of Contents

- [💡 Acknowledgments](#-acknowledgments)
- [🔍 Problem Description](#-problem-description)
- [🧰 Prerequisites](#-prerequisites)
- [🖥️ Environment Setup](#-environment-setup)
- [✏️ Simulation Code Implementation](#-simulation-code-implementation)
- [🏁 Compile and Run](#-compile-and-run)
- [🧪 Testing and Validation](#-testing-and-validation)
- [🧩 Challenges Encountered](#-challenges-encountered)
- [🛠️ Handling Challenges](#-handling-challenges)
- [📝 Conclusion](#-conclusion)
- [📌 References](#-references)
- [👥 Contributors](#-contributors)

---

## 💡 Acknowledgments

**Course Name:** ELE336 - Computer Architecture  
We extend our sincere gratitude and appreciation to Dr. May Salama for her exceptional supervision and dedication throughout the Computer Architecture course. Her clear explanations, continuous support, and insightful guidance greatly enriched our learning experience. 

---


## 🔍 Problem Description

Modern microprocessors execute multiple instructions per clock cycle using deep instruction pipelines. However, control hazards — due to unpredictable branch instructions — can cause stalls and decrease efficiency.

In a basic 5-stage pipeline (IF, ID, EX, MEM, WB), branches are resolved in the EX stage. This delay results in penalties if the pipeline fetches the wrong path.

To mitigate this:
- **Branch Prediction** predicts if a branch is taken.
- **BTB** provides the predicted target address early.
- **RAS** helps accurately predict return addresses of function calls.

---

## 🧰 Prerequisites

Install dependencies and enable 32-bit support:
```bash
sudo apt update
sudo apt install build-essential flex bison gcc-multilib g++-multilib lib32z1 libc6-i386 lib32gcc-s1 binutils-multiarch wget
```

---

## 🖥️ Environment Setup
Clone the repo and create directory:
```bash
git clone https://github.com/AbduAllahhany/Pipeline-stalls-reduction-techniques
cd Pipeline-stalls-reduction-techniques

export IDIR=$HOME/Pipeline-stalls-reduction-techniques
export HOST=i686-pc-linux
export TARGET=sslittle-na-sstrix

mkdir -p $IDIR
```
---

## ✏️ Simulation Code Implementation

---

## 🏁 Compile and Run
Clone the repo and create directory:
```bash
git clone https://github.com/AbduAllahhany/Pipeline-stalls-reduction-techniques
cd Pipeline-stalls-reduction-techniques

export IDIR=$HOME/Pipeline-stalls-reduction-techniques
export HOST=i686-pc-linux
export TARGET=sslittle-na-sstrix

mkdir -p $IDIR
```

---

### 🔧 Installation Steps

#### Step 1: Install SimpleTools
```bash
tar xvfz simpletools-2v0.tgz
rm -rf gcc-2.6.3
```

#### Step 2: Install SimpleUtils
```bash
tar xvfz simpleutils-990811.tar.gz
cd simpleutils-990811
```

**Fix Required:**  
Replace `yy_current_buffer` with `YY_CURRENT_BUFFER` in `ld/ldlex.l`.

Then:
```bash
./configure --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
make CFLAGS=-O
make install
```

---

#### Step 3: Build the Simulator
```bash
cd $IDIR
tar xvfz simplesim-3v0d-with-cheetah.tar.gz
cd simplesim-3.0
make config-pisa
make
```

Test:
```bash
./sim-safe tests/bin.little/test-math
```

---

#### Step 4: Install GCC Cross-Compiler
```bash
cd $IDIR
tar xvfz gcc-2.7.2.3.ss.tar.gz
cd gcc-2.7.2.3
./configure --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
chmod -R +w .
```

##### Fix: `ar` & `ranlib` buffer overflow
```bash
mv ar ranlib $IDIR/sslittle-na-sstrix/bin/
chmod +x $IDIR/sslittle-na-sstrix/bin/ar
chmod +x $IDIR/sslittle-na-sstrix/bin/ranlib
```

##### Manual Fixes
- `Makefile`: Add `-I/usr/include`
- `protoize.c`: `#include <varargs.h>` → `#include <stdarg.h>`
- `obstack.h`:  
  ```c
  *((void **)__o->next_free++) = ((void *)datum);
  ```

Then:
```bash
cp ./patched/sys/cdefs.h ../sslittle-na-sstrix/include/sys/cdefs.h
cp ../sslittle-na-sstrix/lib/libc.a ../lib/
cp ../sslittle-na-sstrix/lib/crt0.o ../lib/
```

Compile:
```bash
make LANGUAGES=c CFLAGS=-O CC="gcc -m32"
make enquire
../simplesim-3.0/sim-safe ./enquire -f > float.h-cross
make LANGUAGES=c CFLAGS=-O CC="gcc -m32" install
```

---

## 🧪 Testing and Validation
| Program         | Description                                |
|----------------|--------------------------------------------|
| `test.c`        | Evaulate fibonacci sequence     |
| `Taken_test.c`  | 90 of 100 branch is taken  |
| `test-printf`   | Moderate-sized program using function calls |
| `anagram`       | Larger benchmark with file input/output   |

### 🔧 Configurations Tested

| Predictor Type | BTB | RAS | Command-Line Option Example |
|----------------|-----|-----|------------------------------|
| Taken          | ❌  | ❌ | `-bpred taken`                |
| Not taken      | ❌  | ❌ | `-bpred nottaken`                |
| 2-bit          | ✅  | ❌ | `-bpred:2bit -bpred:btb`           |
| 2-bit          | ✅  | ✅ | `-bpred:2lev -bpred:btb -bpred:ras`      |
| Correlating    | ✅  | ✅ | `-bpred:2lev -bpred:btb -bpred:ras`    |

### 📋 Sample Output Summary 
#### Taken test 

![alt text](test%20photos/image-1.png)


#### Not Taken test
![alt text](test%20photos/image-2.png)

#### Bimod (table size 1024)

![alt text](test%20photos/image-3.png)

#### 2lev ( lev1_size:1 lev2_size:2048 history_bit: 8 xor: 0)

![alt text](test%20photos/image-4.png)

#### ras 8

![alt text](test%20photos/image-5.png)

#### Correlating + BTB + RAS	

![alt text](test%20photos/image-6.png)

---

## 🧩 Challenges Encountered

- ❌ `as: unrecognized option '--32'`: The system was invoking the wrong assembler (`as`) from the SimpleScalar toolchain that doesn’t support 32-bit flags used by modern `gcc`.
- ❌ Buffer overflow during `ar rc libgcc1.null`: SimpleScalar's version of `ar` was outdated and incompatible with modern ELF object files.
- ❌ `sys_nerr` undefined: Legacy GCC used a deprecated glibc variable no longer available in modern systems.
- ❌ Architecture mismatch: 32-bit objects were being linked with a 64-bit `ld`, causing failure.
- ❌ `sim-safe` failed to run binaries: Programs compiled with the host GCC were not compatible with the SimpleScalar simulator.
- ❌ `sslittle-na-sstrix-gcc: No such file or directory`: Even though the binary existed, missing 32-bit runtime support caused execution failure on modern Ubuntu.

---

## 🛠️ Handling Challenges

To resolve the above issues, the following steps were taken:

- ✅ **Assembler Conflict:**  
  The system `$PATH` was temporarily reordered to ensure that `/usr/bin/as` was used instead of the incompatible SimpleScalar version.

- ✅ **Broken `ar`/`ranlib`:**  
  Pre-existing working versions of `ar` and `ranlib` were placed in `sslittle-na-sstrix/bin/` and made executable, replacing the broken versions.

- ✅ **Source Code Patches:**  
  Manual fixes were applied to several source files:
  - Replaced `#include <varargs.h>` with `#include <stdarg.h>`
  - Fixed buffer overflows in `obstack.h`
  - Added missing includes and build flags in the `Makefile`

- ✅ **Installed 32-bit Compatibility Libraries:**  
  Required 32-bit development and runtime packages were installed (`libc6-i386`, `lib32z1`, `gcc-multilib`, etc.) to support cross-compilation and execution.

- ✅ **Proper Compilation Flow:**  
  Ensured that test programs were compiled using `sslittle-na-sstrix-gcc` and verified as PISA binaries using the `file` command.

---
### 🔍 Observations

- Branch prediction reduces pipeline stalls significantly.
- BTB improves penalty handling by resolving target addresses earlier.
- RAS is especially effective for procedure returns.
- The best performance is achieved with Correlating Predictor + BTB + RAS.

---

## 📝 Conclusion

Setting up SimpleScalar on a modern Linux system involves several compatibility fixes due to its reliance on legacy toolchains and libraries. Through manual patching, legacy `ar`/`ranlib` replacements, and environment setup, we successfully:

- Installed and configured the SimpleScalar simulator and toolchain
- Built a working cross-compiler (`sslittle-na-sstrix-gcc`)
- Patched and compiled legacy GCC (2.7.2.3) for PISA architecture
- Created and ran a sample C program through the SimpleScalar simulator

This environment can now be used for experimenting with compiler behavior, running statically compiled PISA binaries, and simulating program execution in research or academic contexts.

> ✅ You now have a fully functioning SimpleScalar system ready to run and analyze programs for the PISA architecture.
---

## 📌 References
[Simple Scalar link](https://github.com/toddmaustin/simplesim-3.0)

[Simple Scalar compiler and tools ](https://github.com/Awesome-BUPT/simple-scalar.git)
---

## 💡 Notes for Windows Users

You can run SimpleScalar using:
- A Linux virtual machine (e.g., VMware or VirtualBox)
- WSL (Windows Subsystem for Linux) on Windows 10+

---

## 👥 Contributors
1. Ahmed Bahy Yousef Shahat  
2. Hassan Hussein Azmy  
3. Abdelrahman Mahmoud Mohamed Mohamed  
4. Abdallah Hany Ragab Mohamed  
5. Mahmoud Ahmed Mahmoud Mohamed 
