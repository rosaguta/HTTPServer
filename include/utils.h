#ifndef utils_H_
#define utils_H_
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include "./FileHelper.h"
#include "./HTTPHelper.h"

#define BUFFER_SIZE 104857600 // 10MB
#define SRC_DIR "./html/"
void build_http_response(const char *file_name, const char *file_ext, char *response, size_t *repsonse_len);
void *handle_client(void *arg);

#endif