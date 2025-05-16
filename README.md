
# 📘 Pipeline Stalls Reduction Techniques  
**Course Name:** ELE336 - Computer Architecture  

We extend our sincere gratitude and appreciation to Dr. May Salama for her exceptional supervision and dedication throughout the Computer Architecture course. Her clear explanations, continuous support, and insightful guidance greatly enriched our learning experience. ## 👥 Team Members

1. Ahmed Bahy Yousef Shahat  
2. Hassan Hussein Azmy  
3. Abdelrahman Mahmoud Mohamed Mohamed  
4. Abdallah Hany Ragab Mohamed  
5. Mahmoud Ahmed Mahmoud Mohamed  

---

## 📑 Table of Contents
- [📘 Assignment Overview](#-assignment-overview)  
- [📌 The Problem](#-the-problem)  
- [🎯 Assignment Goal](#-assignment-goal)  
- [🧠 Implementation Plan](#-implementation-plan)  
- [⚙️ SimpleScalar Installation Guide](#️-simplescalar-installation-guide)  
  - [📦 Prerequisites](#-prerequisites)  
  - [📁 Setup](#-setup)  
  - [🔧 Installation Steps](#-installation-steps)  
  - [✅ Testing the Setup](#-testing-the-setup)  
  - [✅ Running Your Own Programs](#-running-your-own-programs)  
- [📊 Results & Analysis](#-results--analysis)  
- [💡 Notes for Windows Users](#-notes-for-windows-users)  

---

## 📘 Assignment Overview
Enhance a 5-stage pipeline simulator (from Assignment 1) to implement and analyze techniques for reducing control hazards using:
- Branch Prediction: Predicts whether a branch will be taken or not before its actual resolution, allowing the pipeline to continue fetching instructions along the predicted path.  
- Branch Target Buffer (BTB): Stores the target addresses of previously encountered branch instructions to reduce the time needed to determine where to jump.  
- Return Address Stack (RAS): Specifically aids in predicting return addresses of function calls, which are otherwise difficult to predict accurately using BTB alone.  

---

## 📌 The Problem

Modern microprocessors execute multiple instructions per clock cycle using deep instruction pipelines. However, control hazards — due to unpredictable branch instructions — can cause stalls and decrease efficiency.

In a basic 5-stage pipeline (IF, ID, EX, MEM, WB), branches are resolved in the EX stage. This delay results in penalties if the pipeline fetches the wrong path.

To mitigate this:
- **Branch Prediction** predicts if a branch is taken.
- **BTB** provides the predicted target address early.
- **RAS** helps accurately predict return addresses of function calls.

---

## 🎯 Assignment Goal

Extend the simulator to:
- Simulate realistic branch prediction techniques
- Integrate BTB for early jump target prediction
- Incorporate RAS for function call return tracking
- Evaluate and compare these techniques in reducing stalls and improving instruction throughput

---

## 🧠 Implementation Plan

### ✔️ Implement Branch Prediction
- Use `bpred.c/h` from SimpleScalar
- Support:
  - 2-bit Saturating Counter (BPred2Bit)
  - (2,2) Correlating Predictor (BPred2Level)
- Add `-bpred` option
- Handle prediction and correction in ID and EX stages

### ✔️ Add Branch Target Buffer (BTB)
- Predict target address during IF stage
- Add `-btb` option to enable/disable
- Track predicted targets and compare for accuracy

### ✔️ Add Return Address Stack (RAS)
- Stack size = 8
- Used for procedure returns
- Enable with `-ras` flag

---

## ⚙️ SimpleScalar Installation Guide

### 📦 Prerequisites

Install dependencies and enable 32-bit support:
```bash
sudo apt update
sudo apt install build-essential flex bison gcc-multilib g++-multilib lib32z1 libc6-i386 lib32gcc-s1 binutils-multiarch wget
```

---

### 📁 Setup

Clone the repo and create directory:
```bash
git clone https://github.com/AbduAllahhany/Simple-Scalar
cd simple-scaler

export IDIR=$HOME/simplescalar
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

## ✅ Testing the Setup

Create a file `hello.c`:
```c
#include <stdio.h>
int main() {
    printf("Hello World!\n");
    return 0;
}
```

Compile:
```bash
$IDIR/bin/sslittle-na-sstrix-gcc -o hello hello.c
```

Run:
```bash
$IDIR/simplesim-3.0/sim-safe hello
```

Expected Output:
```
sim: ** starting functional simulation **
Hello World!
```

---

## ✅ Running Your Own Programs

If your test files (e.g. `2bit_test.c`) are in `/tests/`:

### 🧪 Compile Test
```bash
$IDIR/bin/sslittle-na-sstrix-gcc -o /tests/2bit_test.bin /tests/2bit_test.c
```

### ▶️ Run with Branch Prediction
```bash
$IDIR/simplesim-3.0/sim-bpred -bpred 2bit -btb -ras /tests/2bit_test.bin
```

---

## 📊 Results & Analysis

### 🧪 Test Programs Used

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


### 🔍 Observations

- Branch prediction reduces pipeline stalls significantly.
- BTB improves penalty handling by resolving target addresses earlier.
- RAS is especially effective for procedure returns.
- The best performance is achieved with Correlating Predictor + BTB + RAS.

---

## 💡 Notes for Windows Users

You can run SimpleScalar using:
- A Linux virtual machine (e.g., VMware or VirtualBox)
- WSL (Windows Subsystem for Linux) on Windows 10+

---
