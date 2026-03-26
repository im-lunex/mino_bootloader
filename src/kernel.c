// Multiboot2 MAGIC...
#define MULTIBOOT2_MAGIC 0xe85250d6
#define MULTIBOOT_ARCH 0
#define HEADER_LENGTH 16
#define CHECKSUM -(MULTIBOOT2_MAGIC + MULTIBOOT_ARCH + HEADER_LENGTH)

__attribute__((section(".multiboot"))) struct {
	unsigned int magic;
	unsigned int architecture;
	unsigned int header_length;
	unsigned int checksum;
} multiboot_header = {MULTIBOOT2_MAGIC, MULTIBOOT_ARCH, HEADER_LENGTH,
					  CHECKSUM};

void kernel_main(void) {
	const char *msg = "What the Fuck is this piece of shit...";

	char *vga = (char *)0xB8000;
	for (int i = 0; msg[i]; i++) {
		vga[i * 2] = msg[i];
		vga[i * 2 + 1] = 0x0F;
	}

	while (1)
		;
}

// Uhhh MAGIC...
