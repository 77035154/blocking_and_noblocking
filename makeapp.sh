#! /bin/sh

/12.3/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.9/bin/arm-linux-androideabi-gcc 	$1  -o  $2 --sysroot=/12.3/prebuilts/ndk/9/platforms/android-21/arch-arm/  --static
