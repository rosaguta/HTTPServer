#include "../../include/utils.h"

void build_http_response(const char *file_name, const char *file_ext, char *response, size_t *response_len)
{
  printf("Considered FILE NAME: %s\n", file_name);
  // building the header
  const char *mime_type = get_mime_type(file_ext);
  char *header = (char *)malloc(BUFFER_SIZE * sizeof(char));

  snprintf(header, BUFFER_SIZE,
           "HTTP/1.1 200 OK\r\n"
           "Content-Type: %s\r\n"
           "\r\n",
           mime_type);
  printf("header: %s", header);
  // try open requested file
  int file_fd = get_file_descriptor(SRC_DIR, file_name);
  if (file_fd == -1)
  {
    snprintf(response, BUFFER_SIZE,
             "HTTP/1.1 404 Not Found\r\n"
             "Content-Type: text/plain\r\n"
             "\r\n"
             "404 Not Found");
    *response_len = strlen(response);
    return;
  }
  // getting file size with fstat https://linux.die.net/man/2/fstat
  struct stat file_stat;
  fstat(file_fd, &file_stat);
  off_t file_size = file_stat.st_size;
  printf("FILE_DESC: %d SIZE: %li\n", file_fd, file_size);

  // copy header to response buffer
  *response_len = 0;
  memcpy(response, header, strlen(header));
  *response_len += strlen(header);
  // copy file to response buffer
  ssize_t bytes_read;
  while ((bytes_read = read(file_fd, response + *response_len, BUFFER_SIZE - *response_len)) > 0)
  {
    *response_len += bytes_read;
  }
  printf("response: %s\n", response);

  free(header);
  close(file_fd);
}
void *handle_client(void *arg)
{
  int client_fd = *((int *)arg);
  char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

  // recieve request data from client and store to buffer
  ssize_t bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);

  if (bytes_received > 0)
  {
    // check if request is GET
    regex_t regex;
    regcomp(&regex, "^GET /([^ ]*) HTTP/1", REG_EXTENDED);
    regmatch_t matches[2];

    if (regexec(&regex, buffer, 2, matches, 0) == 0)
    {
      // get the filename from encoded string
      buffer[matches[1].rm_eo] = '\0';
      const char *url_encoded_file_name = buffer + matches[1].rm_so;
      char *file_name = url_decode(url_encoded_file_name);

      // if the root route is requested in GET, then respsonse the index page
      if (strlen(file_name) == 0)
      {
        strcpy(file_name, "index.html");
      }
      // get file extension
      char file_ext[32];
      strcpy(file_ext, get_file_extension(file_name));

      // build http response
      char *response = (char *)malloc(BUFFER_SIZE * 2 * sizeof(char));
      size_t response_len;
      build_http_response(file_name, file_ext, response, &response_len);

      // send HTTP response to client
      send(client_fd, response, response_len, 0);

      free(response);
      free(file_name);
    }
    regfree(&regex);
  }
  close(client_fd);
  free(arg);
  free(buffer);
  return NULL;
}
