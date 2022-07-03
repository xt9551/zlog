//
// Created by maxt on 2022/6/30.
//

#include <stdio.h>

#include "zlog.h"

int main(int argc, char** argv)
{

    int rc;
    zlog_category_t *c;
    printf("hello!\n");

    rc = zlog_init("D:\\test\\zlog.conf");
    if (rc) {
        printf("init failed\n");
        return -1;
    }

    c = zlog_get_category("fgui_cat");
    if (!c) {
        printf("get cat fail\n");
        zlog_fini();
        return -2;
    }

    zlog_info(c, "hello, zlog info");
    zlog_debug(c, "hello, zlog debug");
    zlog_notice(c, "hello, zlog_notice");
    zlog_warn(c, "hello, zlog warn");
    zlog_error(c, "hello, zlog_error");
    zlog_fatal(c, "hello, zlog_fatal");
    zlog_fatal(c, "--------------");
    zlog_fini();
    printf("end\n");
    return 0;
}