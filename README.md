# Simple-Scaler

Simple-Scaler is a CPU simulation toolkit built on the SimpleScalar framework. This guide provides full installation instructions for setting up SimpleScalar along with its tools, utilities, and cross-compiler on a modern Linux system.

> These instructions were originally written for Ubuntu 8.04 but can be adapted for other Linux distributions.

---

To get started, clone the repository:

```bash
git clone https://github.com/AbduAllahhany/Simple-Scalar
cd simple-scaler
```

---

## 📦 Prerequisites


Install required packages and 32 bit support :

```bash
sudo apt update
sudo apt install build-essential flex bison gcc-multilib g++-multilib lib32z1 libc6-i386 lib32gcc-s1 binutils-multiarch wget
```



---

## 📁 Setup

### 1. Environment Variables

Set these environment variables (adjust to your actual home path):

```bash
export IDIR=$HOME/simplescalar
export HOST=i686-pc-linux
export TARGET=sslittle-na-sstrix
```

Then:

```bash
mkdir -p $IDIR
```

---

## 🔧 Installation Steps

### Step 3: Install SimpleTools

```bash
tar xvfz simpletools-2v0.tgz
rm -rf gcc-2.6.3
```

---

### Step 4: Install SimpleUtils

```bash
tar xvfz simpleutils-990811.tar.gz
cd simpleutils-990811
```

Edit `ld/ldlex.l`: replace all `yy_current_buffer` with `YY_CURRENT_BUFFER`.

Then run:

```bash
./configure --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
make CFLAGS=-O
make install
```

> If `yy_current_buffer` errors persist, install a compatible version of Flex:  
> [Download Flex](http://www.ict.kth.se/courses/IS2202/flex.tar.gz)  
> Run:  
> `./configure && make && sudo make install`

---

### Step 5: Build the Simulator

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

### Step 6: Install GCC Cross-Compiler

```bash
cd $IDIR
tar xvfz gcc-2.7.2.3.ss.tar.gz
cd gcc-2.7.2.3
./configure --host=$HOST --target=$TARGET --with-gnu-as --with-gnu-ld --prefix=$IDIR
chmod -R +w .
```
#### 🔧Fix for ar and ranlib buffer overflow

```bash
mv ar ranlib $IDIR/sslittle-na-sstrix/bin/
chmod +x $IDIR/sslittle-na-sstrix/bin/ar
chmod +x $IDIR/sslittle-na-sstrix/bin/ranlib

```

#### Manual Fixes Required:

- In `Makefile` (around line 130), add: `-I/usr/include` at the end of the line.
- In `protoize.c` (line 60): change `#include <varargs.h>` to `#include <stdarg.h>`
- In `obstack.h` (line 341), replace:
  ```c
  *((void **)__o->next_free)++=((void *)datum);
  ```
  with:
  ```c
  *((void **)__o->next_free++)=((void *)datum);
  ```

Then run:

```bash
cp ./patched/sys/cdefs.h ../sslittle-na-sstrix/include/sys/cdefs.h
cp ../sslittle-na-sstrix/lib/libc.a ../lib/
cp ../sslittle-na-sstrix/lib/crt0.o ../lib/
```

Now compile:

```bash
make LANGUAGES=c CFLAGS=-O CC="gcc -m32"
```

> If errors appear in `insn-output.c`, add `\` to lines 675, 750, and 823.  
 Remove lines 2978-2979 from `cxxmain.c` if compilation halts.


Continue:

```bash
make LANGUAGES=c CFLAGS=-O CC="gcc -m32"
make enquire
../simplesim-3.0/sim-safe ./enquire -f > float.h-cross
make LANGUAGES=c CFLAGS=-O CC="gcc -m32" install
```

---

## ✅ Testing the Setup

Create a new file `hello.c`:

```c
#include <stdio.h>
int main() {
    printf("Hello World!\n");
    return 0;
}
```

Compile it using:

```bash
$IDIR/bin/sslittle-na-sstrix-gcc -o hello hello.c
```

Run it in the simulator:

```bash
$IDIR/simplesim-3.0/sim-safe hello
```

Expected output:

```
sim: ** starting functional simulation **
Hello World!
```

---

## ✅ Testing with Your Own Programs

 we have source files like `2bit_test.c`, `2lev_test.c`, `notTaken_test.c`, etc., located in the `tests/` directory, you can compile and simulate them as follows:

### 🧪 Compile Test Program

```bash
cd $IDIR 
$IDIR/bin/sslittle-na-sstrix-gcc -o /tests/<output_binary> /tests/<source_file.c>
```
### ▶️ Run Simulation with Branch Predictor
```bash
cd $IDIR
$IDIR/simplesim-3.0/sim-bpred <configuration> <output_binary>

```

## 💡 Notes for Windows Users

You can run SimpleScalar on Windows using a Linux virtual machine. One tested option is [VMware Server](http://www.vmware.com) Or you can install WSL 

---

