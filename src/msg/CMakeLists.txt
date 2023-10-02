set(SOURCES
    on_off_msg.c
    unrecognized_arg_msg.c
    no_arg_value_msg.c
    argc_error_msg.c
    extra_arg_error_msg.c
    no_home_error_msg.c
    file_open_error_msg.c
    no_json_error_msg.c
    json_parse_error_msg.c
    no_results_error_msg.c
    cjson_error_msg.c
    malloc_error_msg.c
    system_func_error_msg.c
    already_conf_msg.c
    conf_successful_msg.c
    access_error_msg.c
)

add_library(yiffy-messages STATIC ${SOURCES})