#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#include <time.h>
#include <sys/time.h>
#include <errno.h>

//  See table 4-7 p. 206 in trm-am3558
#define PRU_ADDR 0x4a300000
#define PRU_LEN 0x80000
#define PRU0_DRAM 0x00000
#define MAXC 2

unsigned int *pru0DRAM_32int_ptr;
unsigned int *pru;

int interval;
struct timeval start, end;

using namespace std;

int getPruMsg()
{
    uint32_t ch = 0;
    unsigned int *pruDRAM_32int_ptr = pru0DRAM_32int_ptr;

    //  Read ticks from shared memory:
    return (pruDRAM_32int_ptr[2 * (ch) + 0]);
}

/**
 * Open the /dev/mem file with read/write access - for some reason, it cannot open it with just read access...
 * If it is possible to map /dev/mem in order to access physical memory, then we can direct the pru0 pointer to the PRU0_RAM location with offset 0x200
 * The /dev/mem can be used to direct towards different memory areas on the OS. We want to direct it towards the PRU0_RAM
 *
 * The issue with /dev/mem is that even if I write into four different channels, I will always
 */
int fileHandler()
{
    int fd;
    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (fd == -1)
    {
        cout << "ERROR: Could not open /dev/mem." << endl;

        //  Enter probe here to know, when the issue occurs:
        gettimeofday(&end, NULL);

        //  Calculate time it took to read shared memory tick:
        interval = 1000000 * (end.tv_sec - start.tv_sec)
                + (end.tv_usec - start.tv_usec);
        cout << "Time when error occured: " << (double) interval / 1000 << " ms" << endl;
        //  Exit the program:
        exit(1);
    }

    //  Pointer to the desired mapping area:
    pru = (unsigned int*) mmap(0, PRU_LEN, PROT_READ | PROT_WRITE, MAP_SHARED,
                               fd, PRU_ADDR);
    if (pru == MAP_FAILED)
    {
        cout << "ERROR: Could not map memory" << endl;
        close(fd);
        exit(1);
    }

    else
    {
        //close(fd);
        pru0DRAM_32int_ptr = pru + PRU0_DRAM / 4 + 0x200 / 4;
        return 0;
    }
}

int main()
{
    int tick, interval_tick, i;
    struct timeval start_tick, end_tick;

    //  Get start time, when program starts up:
    gettimeofday(&start_tick, NULL);

    for (;;)
    {
        //  Get start time:
        gettimeofday(&start_tick, NULL);

        //  Change channel mechanism here...
        //if(it_doesnt_work_then_fix_it)

        //  Open /dev/mem
        fileHandler();

        //  Get ticks:
        tick = getPruMsg();
        cout << "Ticks from pru: " << tick << endl;
        //cout << "DRAM Channel: " << i << endl;

        //  Sleep 500 us:
        //usleep(1000);

        //  Get end time:
        gettimeofday(&end_tick, NULL);

        //  Calculate time it took to read shared memory tick:
        interval_tick = 1000000 * (end_tick.tv_sec - start_tick.tv_sec)
                + (end_tick.tv_usec - start_tick.tv_usec);
        cout << "Elapsed time: " << (double) interval_tick / 1000 << " ms" << endl;
    }

    return 0;
}
