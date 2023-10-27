#ifndef SYSCALL_H
#define SYSCALL_H

#include "../types.h"

/**
 * @defgroup SystemCalls System Call Vectors
 * 
 * @brief Exception vectors corresponding to system calls.
 * 
 * The table outlines the exception vectors used for various system calls.
 * 
 * | Vector Number | System Call Number | Name               | Details                                 |
 * |---------------|--------------------|--------------------|-----------------------------------------|
 * | 32            | 0                  | reboot             |                                         |
 * | 33            | 1                  | exit               |                                         |
 * | 34            | 2                  | create_process     |                                         |
 * | 35            | 3                  | write              |                                         |
 * | 36            | 4                  | read               |                                         |
 * | 37            | 5                  | get_pid            |                                         |
 * | 38            | 6                  | (reserved)         | reserved for SCI expansion adjust priority? |
 * | 39            | 7                  | yield              |                                         |
 * | 40            | 8                  | wait               | not implemented                          |
 * | 41            | 9                  | (reserved)         | reserved for SCI expansion               |
 * | 42            | 10                 | semaphore operation| not implemented                          |
 * | 43            | 11                 | (reserved)         | reserved for SCI expansion               |
 * | 44            | 12                 | open               | not implemented                          |
 * | 45            | 13                 | close              | not implemented                          |
 * | 46            | 14                 | create_file        | not implemented                          |
 * | 47            | 15                 | delete_file        | not implemented                          |
 * 
 * @{
 */

extern void reboot();                 /**< System function to reboot the system. */
extern void sys_reboot();            /**< System reboot function. */

extern void exit();                  /**< System function to exit a process. */
extern void sys_exit();              /**< System exit function. */

extern void create_process(UINT16 prog_num, UINT16 is_fg);  /**< System function to create a new process. */
extern void sys_create_process();    /**< System function to create a process. */

extern void write(const char *buf, unsigned int len);       /**< System function to write data. */
extern void sys_write();             /**< System write function. */

extern int read(char *buf, unsigned int len);               /**< System function to read data. */
extern void sys_read();              /**< System read function. */

extern int get_pid();                /**< System function to get the process ID. */
extern void sys_get_pid();           /**< System function to get process ID. */

extern void yield();                 /**< System function for a process to yield its execution. */
extern void sys_yield();             /**< System yield function. */
/** @} */

#endif /* SYSCALL_H */
