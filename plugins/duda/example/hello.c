/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Service Example", "service");

duda_global_t my_data_mem;
duda_global_t my_data_empty;

/*
 *
 * URI Map example
 * +--------------------------------------------------------------+
 * |  Interface         Method     Param Name  Param Max Length   |
 * +--------------------------------------------------------------+
 * |  examples         hello_world                   0            |
 * +--------------------------------------------------------------+
 * |                   sendfile                      0            |
 * +--------------------------------------------------------------+
 * |                   json                          0            |
 * +--------------------------------------------------------------+
 *
 */

void cb_end(duda_request_t *dr)
{
    msg->info("my end callback");
}

void cb_hello_world(duda_request_t *dr)
{
    msg->warn("my global key: %p", global->get(my_data_mem));

    response->http_status(dr, 200);
    response->http_header(dr, "Content-Type: text/plain", 24);

    response->body_write(dr, "hello world!\n", 13);
    response->end(dr, cb_end);
}

void cb_sendfile(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->http_header(dr, "Content-Type: text/plain", 24);

    response->sendfile(dr, "/etc/issue");
    response->sendfile(dr, "/etc/motd");
    response->end(dr, cb_end);

}

void cb_json(duda_request_t *dr)
{
    char *resp;
    json_t *jroot;

    response->http_status(dr, 200);
    response->http_header(dr, "Content-Type: text/plain", 24);

    jroot = json->create_object();
    json->add_to_object(jroot, "name", json->create_string("Michel Perez"));

    resp = json->print(jroot);
    response->body_write(dr, resp, strlen(resp));
    response->end(dr, cb_end);
}

void *cb_global_mem()
{
    void *mem = malloc(16);
    return mem;
}

int duda_init(struct duda_api_objects *api)
{
    duda_interface_t *if_system;
    duda_method_t    *method;

    duda_service_init();

    /* An empty global variable */
    duda_global_init(my_data_empty, NULL);

    /* A global variable with the value returned by the callback */
    duda_global_init(my_data_mem, cb_global_mem);

    /* archive interface */
    if_system = map->interface_new("examples");

    /* URI: /hello/examples/hello_word */
    method = map->method_new("hello_world", "cb_hello_world", 0);
    map->interface_add_method(method, if_system);

    /* URI: /hello/examples/json */
    method = map->method_new("json", "cb_json", 0);
    map->interface_add_method(method, if_system);

    /* URI: /hello/examples/sendfile */
    method = map->method_new("sendfile", "cb_sendfile", 0);
    map->interface_add_method(method, if_system);

    /* Add interface to map */
    duda_service_add_interface(if_system);

    duda_service_ready();
}
