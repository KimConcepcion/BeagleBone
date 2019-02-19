
#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define PRU_ADDR 0x4a300000
#define PRU_LEN 0x80000
#define PRU0_DRAM 0x00000
#define PRU1_DRAM 0x02000
#define PRU_SHAREDMEM 0x10000

unsigned int *pru0DRAM_32int_ptr;
unsigned int *pru1DRAM_32int_ptr;
unsigned int *prusharedMem_32int_ptr;
unsigned int *pru;

using namespace std;

int getPruMsg()
{
    int tick;
    int ch = 0;
    unsigned int *pruDRAM_32int_ptr = pru0DRAM_32int_ptr;

    //  Read from shared memory:
    tick = pruDRAM_32int_ptr[2 * (ch) + 0];
    return tick;
}

int fileHandler()
{
    int fd;

    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd == -1)
    {
        cout << "ERROR: Could not open /dev/mem." << endl;
        return 1;
    }

    pru = (unsigned int*) mmap(0, PRU_LEN, PROT_READ | PROT_WRITE, MAP_SHARED,
                               fd, PRU_ADDR);
    if (pru == MAP_FAILED)
    {
        cout << "ERROR: Could not map memory" << endl;
        return 1;
    }

    close(fd);

    pru0DRAM_32int_ptr = pru + PRU0_DRAM / 4 + 0x200 / 4;
    pru1DRAM_32int_ptr = pru + PRU1_DRAM / 4 + 0x200 / 4;
    prusharedMem_32int_ptr = pru + PRU_SHAREDMEM / 4;

    return 0;
}

int main()
{
    int tick;

    for (;;)
    {
        //  open /dev/mem:
        fileHandler();

        //  Receive msg from pru:
        tick = getPruMsg();
        cout << "Ticks from pru: " << tick << endl;

        //  Perform munmap:
        if (munmap(pru, PRU_LEN))
        {
            cout << "munmap failed!" << endl;
        }

        else
        {
            cout << "munmap succeeded!" << endl;
        }
    }

    return 0;
}
