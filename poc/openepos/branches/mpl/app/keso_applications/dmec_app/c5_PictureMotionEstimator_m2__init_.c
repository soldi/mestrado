/* THIS FILE IS AUTO GENERATED BY KESO! DON'T EDIT */

#include <keso_support.h>
#include <keso_types.h>
#include "global.h"
#include "domains.h"
#include "c5_PictureMotionEstimator.h"
#include "c31_PictureMotionCounterpart.h"


/*
 * call analyse 1 c5_PictureMotionEstimator_m2__init_
 *
 * c4_DmecApp_m1_launch
 * (valid,176,144,1)
 *
 * total (valid,176,144,1)
 */

/* dmec/PictureMotionEstimator.<init>(III)V */

void c5_PictureMotionEstimator_m2__init_(object_t* obj0,jint i1,jint i2,jint i3) {
	((c5_PictureMotionEstimator_t*) obj0)->__inner = pme_getInstance(i1,i2,i3);
    ((c5_PictureMotionEstimator_t*) obj0)->__pmcWrapper = KESO_ALLOC(C31_PICTUREMOTIONCOUNTERPART_ID,sizeof(c31_PictureMotionCounterpart_t),0);
	((c31_PictureMotionCounterpart_t*) ((c5_PictureMotionEstimator_t*) obj0)->__pmcWrapper)->__inner = 0;
}
