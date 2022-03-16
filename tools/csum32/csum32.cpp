
/* last update: 28.10.2021 savelij */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// �������� �����
FILE *OpenFile(const char *filename, const char *mode)
{
	FILE *namebuf;

	if(!(namebuf = fopen(filename, mode)))
	{
		printf("file %s not found\n", filename);
		exit(1);
	}
	return namebuf;
}

// ������ �����
unsigned char *ReadFile(FILE *name, char *filename, unsigned int filesize)
{
	unsigned char *buf;

	if(!(buf = (unsigned char *)malloc(filesize)))
	{
		printf("memory allocation error\n");
		exit(1);
	}

	unsigned int rdsize = fread(buf, 1, filesize, name);
	if(rdsize != filesize)
	{
		printf("file %s reading error\n", filename);
		exit(1);
	}
	return buf;
}

// ������ �����
int WriteFile(int size, FILE *dst, unsigned char *buff)
{
	return fwrite(buff, 1, size, dst);
}

// ��������� ������� �����
int FileSize(FILE *p)
{
	int pos, size;

	pos = ftell(p);
	fseek(p, 0, SEEK_END);
	size = ftell(p);
	fseek(p, pos, SEEK_SET);
	return size;
}

// ������� ���������� ������
void usage(void)
{
	printf("Build: %s  %s\n", __DATE__, __TIME__);
	printf("Usage:\n");
	printf("csum32 input.bin >> creating output file \"csum32.bin\"\n");
	printf("csum32 input.bin -a >> no create \"csum32.bin\", add csum32 to input file\n");
	printf("csum32 inpit.bin -o output.ext >> the output file is equal to the input file appended with csum32\n");

	exit(0);
}

int main(int argc, char **argv)
{
	FILE *inp, *outp;				// ������� � �������� ����
	int insize;						// ������ �������� �����
	unsigned char *inputbuf;		// ������� �����
	unsigned int csum = 0;

	if ( argc < 2 ) usage();

	// �������� �������� ����� �� ������
	inp = OpenFile(argv[1], "rb");
	// �������� ������� �����
	insize = FileSize(inp);
	// ������ ������� ���� � �����
	inputbuf = ReadFile(inp, argv[1], FileSize(inp));

	for(int i = 0; i < insize; i++)
	{
		csum += inputbuf[i];
	}

	switch(argc)
	{
	case 4:
		if ( argv[2][0] == '-' && (argv[2][1] == 'o' || argv[2][1] == 'O') )
		{
			// ������� "-o": ����������� �������� ����� � �������� � ���������� csum32
			outp = OpenFile(argv[3], "wb");
			WriteFile(insize, outp, inputbuf);
			WriteFile(4, outp, (unsigned char *)&csum);
			fclose(outp);
		}
		else printf("Unknown key\n");
		break;

	case 3:
		if ( argv[2][0] == '-' && (argv[2][1] == 'a' || argv[2][1] == 'A') )
		{
			// � ������ "-a": ���������� csum32 � �������� �����
			outp = OpenFile(argv[1], "ab");
			WriteFile(4, outp, (unsigned char *)&csum);
			fclose(outp);
		}
		else printf("Unknown key\n");
		break;

	case 2:
	default:
		// ��� ������
		outp = OpenFile("csum32.bin", "wb");
		WriteFile(4, outp, (unsigned char *)&csum);
		fclose(outp);
	}
	
	fclose(inp);
}
