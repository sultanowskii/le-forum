#pragma ocnce

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>

#include <unistd.h>

#include <pthread.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#include "lib/constants.h"
#include "lib/queue.h"
#include "lib/status.h"
#include "lib/util.h"

#include "client/arg.h"

/**
 * @brief Main command list. 
 * 
 */
enum MainCmdIDs {
	_mcid_BEGIN,
	mcid_SERVER,
	mcid_THREAD,
	mcid_SETTINGS,
	mcid_EXIT,
	_mcid_END,
};

/**
 * @brief Server command list. 
 * 
 */
enum ServerCmdIDs {
	_scid_BEGIN,
	scid_CONNECT_DISCONNECT,
	scid_HISTORY,
	scid_BACK,
	_scid_END,
};

/**
 * @brief Thread command list. 
 * 
 */
enum ThreadCmdIDs {
	_tcid_BEGIN,
	tcid_INFO,
	tcid_MESSAGES,
	tcid_POST_MESSAGE,
	tcid_BACK,
	_tcid_END,
};

/**
 * @brief Settings command list.  
 * 
 */
enum SettingsCmdIDs {
	_stgcid_BEGIN,
	stgcid_BACK,
	_stgcid_END,
};


/* ---- Command string representators ----- */
/**
 * @brief Returns string representation of main command with provided id. 
 * 
 * @param id Command ID
 * @return Command string representation. LESTATUS_NFND is returned if there is no such command with given id
 */
const char *MainCmdID_REPR(enum MainCmdIDs id);

/**
 * @brief Returns string representation of server command with provided id. 
 * 
 * @param id Command ID
 * @return Command string representation. LESTATUS_NFND is returned if there is no such command with given id
 */
const char *ServerCmdID_REPR(enum ServerCmdIDs id);

/**
 * @brief Returns string representation of thread command with provided id. 
 * 
 * @param id Command ID
 * @return Command string representation. LESTATUS_NFND is returned if there is no such command with given id
 */
const char *ThreadCmdID_REPR(enum ThreadCmdIDs id);

/**
 * @brief Returns string representation of settings command with provided id. 
 * 
 * @param id Command ID
 * @return Command string representation. LESTATUS_NFND is returned if there is no such command with given id
 */
const char *SettingsCmdID_REPR(enum SettingsCmdIDs id);
/* ---------------------------------------- */


/**
 * @brief Initialises program, 
 * 
 * @return LESTATUS_OK on success 
 */
status_t startup();

/**
 * @brief Cleans all the program data. 
 * 
 * @return LESTATUS_OK on success 
 */
status_t cleanup();

/**
 * @brief Program termination handler. Simply modifies g_working value. 
 * 
 * @param Signum
 */
void stop_program_handle(const int signum);


/* ------------ Menu printers-------------- */
/**
 * @brief Prints server menu. 
 * 
 */
void print_menu_server();

/**
 * @brief Prints thread menu. 
 * 
 */
void print_menu_thread();

/**
 * @brief Prints settings menu. 
 * 
 */
void print_menu_settings();

/**
 * @brief Prints main menu. 
 * 
 */
void print_menu_main();
/* ---------------------------------------- */


/* ---------------- Prefix ---------------- */
/**
 * @brief Prints server prefix before user input
 * 
 */
void print_prefix_server();

/**
 * @brief Prints thread prefix before user input
 * 
 */
void print_prefix_thread();

/**
 * @brief Prints settings prefix before user input
 * 
 */
void print_prefix_settings();

/**
 * @brief Prints main prefix before user input
 * 
 */
void print_prefix_main();
/* ---------------------------------------- */


/* -------------- Commands ---------------- */
/**
 * @brief Processes Server commands. 
 * 
 */
void cmd_server();

/**
 * @brief Connects to the server
 * 
 */
void cmd_server_connect();

/**
 * @brief Disconnects from the current server
 * 
 */
void cmd_server_disconnect();

/**
 * @brief Processes Thread commands.
 * 
 */
void cmd_thread();

/**
 * @brief Processes Settings commands. 
 * 
 */
void cmd_settings();

/**
 * @brief Processes Exit commands. 
 * 
 */
void cmd_exit();
/* ---------------------------------------- */


/**
 * @brief Prints all the menues and stuff, then reads command from user. 
 * 
 * @param print_menu Function that prints menu
 * @param print_prefix Function that prints prefix before user input
 * @return User command
 */
int leclient_loop_process(void (*print_menu)(), void (*print_prefix)());

status_t main(size_t argc, char **argv);