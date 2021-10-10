#define beige                   0xBE
#define mac99                   0x5A

#define __VRAM__BEIGE           0x80000000
#define __BIOS__BEIGE           0xFFC00000

#define __VRAM__MAC99           0x81000000
#define __BIOS__MAC99           0XFFF00000
#define __USB_KEYBOARD__MAC99   0x80080038
#define __USB_MOUSE__MAC99      0x8008003C

unsigned char  IO_TYPE;
unsigned char* p_vram;
unsigned char* p_bios;

void get_io_type(void)
{
        if (*(unsigned char*)__VRAM__BEIGE == beige) IO_TYPE = beige;
	else if (*(unsigned char*)__VRAM__MAC99 == mac99) IO_TYPE = mac99;

}
void init(void)
{
	if (IO_TYPE == beige)
	{
		for(;;); // unsupported yet.
	}
	else if (IO_TYPE == mac99)
	{
		p_vram = __VRAM__MAC99;
		p_bios = __BIOS__MAC99;
	}
}

void main(void)
{
	get_io_type();
	init();
	clearscreen(100,85,100, 0x100000);
	for(;;);
}

void clearscreen(unsigned char a, unsigned char b, unsigned char c, int n)
{
	init();
	for (unsigned int i = 0; i<n; i++)
	{
		//24-bit VGA
		*p_vram = 0;
		p_vram++;
		*p_vram = a;
		p_vram++;
		*p_vram = b;
		p_vram++;
		*p_vram = c;
		p_vram++;
	}
}
