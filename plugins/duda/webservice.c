/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Monkey HTTP Daemon
 *  ------------------
 *  Copyright (C) 2001-2012, Eduardo Silva P.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "MKPlugin.h"
#include "webservice.h"

/* Creates a new interface */
duda_interface_t *duda_interface_new(char *uid)
{
  duda_interface_t *iface;

  iface = mk_api->mem_alloc(sizeof(duda_interface_t));
  iface->uid = uid;
  mk_list_init(&iface->methods);

  return iface;
}

/* Add a method to an interface */
void duda_interface_add_method(duda_method_t *method,
                               duda_interface_t *iface)
{
    mk_list_add(&method->_head, &iface->methods);
}


/* Creates a new method */
duda_method_t *duda_method_new(char *uid, char *callback, int n_params)
{
    duda_method_t *method;

    method = mk_api->mem_alloc(sizeof(duda_method_t));
    method->uid = uid;
    method->num_params = n_params;
    method->callback = callback;
    method->func_cb = NULL;
    mk_list_init(&method->params);

    return method;
}

/* Add a parameter to a method */
void duda_method_add_param(duda_param_t *param, duda_method_t *method)
{
    mk_list_add(&param->_head, &method->params);
}

/* Creates a new parameter */
duda_param_t *duda_param_new(char *uid, short int max_len)
{
    duda_param_t *param;

    param = mk_api->mem_alloc(sizeof(duda_method_t));
    param->max_len = max_len;

    return param;
}

