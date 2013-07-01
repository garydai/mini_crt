void mini_crt_entry(void);
bool mini_crt_heap_init();
bool mini_crt_io_init();
typedef int FILE
#define EOF (-1)
#define stdin ((FILE*)(GetStdHandle(STD_INPUT_HANDLE)))
#define stdout ((FILE*)(GetStdHandle(STD_OUTPUT_HANDLE)))
#define stderr ((FILE*)(GetStdHandle(STD_ERROR_HANDLE)))