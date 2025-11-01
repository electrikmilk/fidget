# Fidget

This is a tiny hobby OS kernel that boots into 32‑bit mode and writes directly to the VGA text buffer at 0xB8000.
The build produces a 32‑bit kernel.bin linked with a boot object via a custom linker script.
The runtime is freestanding (no libc), and text output is implemented manually.

Just for fun :)
