#include <iostream>
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef DEF_HPP_
#define DEF_HPP_
#define soundso "./libsqc.so"
#define photoso "./libBKKAdaptor.so"
#define soundconfig "./cv_configuration.json"
#define photoconfig "./ci_configuration.json"
#define soundindex 0
#define photoindex 1

class Version{
public:
	int major;
	int minor;
	int build;
} ;

class Session{
public:
	Version version;
	char *id;
	void *payment;
	int last_error;
};

enum SessionValueState {
    SESSION_VALUE_UNDEFINED,
    SESSION_VALUE_PASSED,
    SESSION_VALUE_FAILED,
    SESSION_VALUE_ERROR
};

class SessionValue {
    char *name;
    bool enable;
    enum SessionValueState state;
    double value;
    SessionValue* next;
};

typedef int (*BKKCheck)(Session*,  uint8_t* , uint64_t);
typedef int (*create_session)(Session*, char*);
typedef int (*BKKCheck)(Session*,  uint8_t* , uint64_t);

typedef int (*BKK)(Session*,  char*);
typedef int (*i_check_format)(Session*,  uint8_t*, uint64_t);
typedef char* (*v_session_configuration_version)(Session*);

typedef bool (*i_result_session)(Session*, SessionValue**);
typedef bool (*v_result_session)(Session*, SessionValue**);
#endif /* DEF_HPP_ */
