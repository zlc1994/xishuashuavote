#include "md5.h"
#include <Python.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MD5LEN    32
 
static const char hex_chars[] = "0123456789abcdef";

 
void convert_hex(unsigned char *md, char *mdstr)
{
    int i;
    int j = 0;
    unsigned int c;
 
    for (i = 0; i < 16; i++) {
        c = (md[i] >> 4) & 0x0f;
        mdstr[j++] = hex_chars[c];
        mdstr[j++] = hex_chars[md[i] & 0x0f];
    }
    mdstr[MD5LEN] = '\0';
}
 

void computerMD5(char *data, char *mdstr)
{
    MD5_CTX md5_ctx;
     
    unsigned char md[64];
 
    // 初始化
    MD5_Init(&md5_ctx);    
 
    // md5 加密
    MD5_Update(&md5_ctx, (unsigned char *)data, strlen(data));
 
    MD5_Final(md, &md5_ctx);
 
    convert_hex(md, mdstr);
 
}


int check(char *str)
{
    if (strncmp(str, "000000", 6) == 0)
        return 1;
    else
        return 0;
}


char* inttos(long long i, char b[]){
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = hex_chars[i%10];
        i = i/10;
    }while(i);
    return b;
}


long long computerCode(char *info)
{
    long long i = 0;
    char buffer[20], mdstr[MD5LEN+1], str[50];

    for (;;) {
        i++;
        inttos(i, buffer);
        memset(str, '\0', 50);
        strcat(str, info);
        strcat(str, buffer);

        computerMD5(str, mdstr);

        if (check(mdstr))
            break;
    }

    return i;
}        

static PyObject* wrap_computerCode(PyObject* self, PyObject* args)
{
  long long result;
  char *info;

  if (! PyArg_ParseTuple(args, "s", &info))
    return NULL;
  result = computerCode(info);
  return Py_BuildValue("L", result);
}


static PyMethodDef handsomeMethods[] =
{
  {"computerCode", wrap_computerCode, METH_VARARGS, "Caculate Code"},
  {NULL, NULL, 0, NULL}
};


static struct PyModuleDef handsome_module_definition = { 
    PyModuleDef_HEAD_INIT,
    "handsome",
    "A Python module that computer handsome code for qlcode.com.",
    -1, 
    handsomeMethods
};



PyMODINIT_FUNC PyInit_handsome(void)
{
    return PyModule_Create(&handsome_module_definition);
}
