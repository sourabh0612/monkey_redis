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

#ifndef DUDA_COOKIE_H
#define DUDA_COOKIE_H

#include "duda.h"

#define COOKIE_CRLF          "\r\n"
#define COOKIE_EQUAL         "="
#define COOKIE_SET           "Set-Cookie: "
#define COOKIE_HEADER        "Cookie:"
#define COOKIE_EXPIRE        "; expires="
#define COOKIE_PATH          "; path=/"
#define COOKIE_SEMICOLON     "; "
#define COOKIE_DELETED       "deleted"
#define COOKIE_EXPIRE_TIME   337606980
#define COOKIE_MAX_DATE_LEN  32

mk_pointer mk_cookie_crlf;
mk_pointer mk_cookie_equal;
mk_pointer mk_cookie_set;
mk_pointer mk_cookie_expire;
mk_pointer mk_cookie_expire_value;
mk_pointer mk_cookie_path;
mk_pointer mk_cookie_semicolon;

struct duda_api_cookie {
    int (*set) (duda_request_t *, char *, int, char *, int, int);
    int (*get) (duda_request_t *, char *, char **, int *);
    int (*cmp) (duda_request_t *, char *, char *);
    int (*destroy) (duda_request_t *, char *, int);
};

struct duda_api_cookie *duda_cookie_object();
int duda_cookie_set(duda_request_t *dr, char *key, int key_len,
                    char *val, int val_len, int expires);
int duda_cookie_get(duda_request_t *dr, char *key, char **val, int *val_len);
int duda_cookie_cmp(duda_request_t *dr, char *key, char *cmp);
int duda_cookie_destroy(duda_request_t *dr, char *key, int key_len);
#endif
