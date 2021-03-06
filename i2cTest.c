#include <stdio.h>
#include <unistd.h>			       //Needed for I2C port
#include <fcntl.h>			       //Needed for I2C port
#include <sys/ioctl.h>			       //Needed for I2C port
#include <linux/i2c-dev.h>		       //Needed for I2C port

int addr = 0x04;                               //<<<<<The I2C address of the slave
int file_i2c;
int length = 25;
unsigned char data[128] = {0};
unsigned char buffer[128] = {0};


//----- OPEN THE I2C BUS -----
char *filename = (char*)"/dev/i2c-1";

int open_i2c()
{
	if ((file_i2c = open(filename, O_RDWR)) < 0)
	{
		//ERROR HANDLING: you can check errno to see what went wrong
		printf("Failed to open the i2c bus");
		return -1;
	}

	if (ioctl(file_i2c, I2C_SLAVE, addr) < 0)
	{
		printf("Failed to acquire bus access and/or talk to slave.\n");
		//ERROR HANDLING; you can check errno to see what went wrong
		return -1;
	}
	return 0;
}
//----- READ BYTES -----

void readData(unsigned char* buffer, int len)
{
	if (read(file_i2c, buffer, len) != len)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		printf("Failed to read from the i2c bus.\n");
	}
	else
	{
		printf("Data read: %s\n", buffer);
	}
}

//----- WRITE BYTES -----
void sendData()
{

	buffer[0] = 0x01;
	buffer[1] = 0x02;
	length = 2;			//<<< Number of bytes to write
	if (write(file_i2c, buffer, length) != length)		//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		/* ERROR HANDLING: i2c transaction failed */
		printf("Failed to write to the i2c bus.\n");
	}
}
int main()
{
	readData(data, length);
}
