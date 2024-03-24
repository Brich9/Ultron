#ifndef ULTRON_H_
#define ULTRON_H_

// Ultron computers have only 32 words worth of memory
#define ULTRON_MEMORY_SIZE 32

// Abstract type that defines an Ultron computer
typedef struct {
    int arr[32];
    int programC;
    int accumC;
} Ultron;


// Ultron methods
void ultron_init(Ultron* ultron);
void ultron_dump(Ultron* ultron);
int ultron_memory(Ultron* ultron, int location);
int ultron_accumulator(Ultron* ultron);
int ultron_pc(Ultron* ultron);
void ultron_load(Ultron* ultron, int size, int* instructions);
int ultron_run(Ultron* ultron);

// Ultron instructions
#define READ         10         // read a word from input into memory
#define WRITE        11         // write a word from memory to the screen

#define LOAD         20         // load a word from memory into accumulator
#define STORE        21         // store a word from accumulator into memory

#define ADD          30         // add to accumulator the value from memory
#define SUBTRACT     31         // subtract from accum the value in memory

#define BRANCHNEG    40         // branch if accumulator is negative to location
#define HALT         43         // stop executing

#endif   // ULTRON_H_
