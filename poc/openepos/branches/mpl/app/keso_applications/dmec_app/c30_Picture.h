/* THIS FILE IS AUTO GENERATED BY KESO! DON'T EDIT */

/* Class: dmec/Picture */

#ifndef __c30_Picture_H__
#define __c30_Picture_H__ 1
#include <keso_types.h>

#define C30_PICTURE_ID ((class_id_t)30)
#define C30_PICTURE_OBJ(_obj_) ((c30_Picture_t*)(_obj_))

/* class methods prototypes */
/* <init>()V */
void c30_Picture_m1__init_(object_t* obj0);

/* object data */
typedef struct {
#include <app_include/c_picture.h>
/* c30_Picture */
/* c1_Object */
OBJECT_HEADER
/* c1_Object */
	void* __inner;
/* c30_Picture */
} c30_Picture_t;

#endif
