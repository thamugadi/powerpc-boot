# powerpc-boot
Boots through OpenFirmware.
Produces a HFS+ disk image formatted with Apple Partition Map partition scheme, compatible with old PowerPC-based Macs.

Run it with QEMU :

```make && qemu-system-ppc DISK.APM```
