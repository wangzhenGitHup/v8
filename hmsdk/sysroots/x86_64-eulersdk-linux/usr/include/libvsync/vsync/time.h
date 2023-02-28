/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: vsync rand
 * Author: Huawei Dresden Research Center
 * Create: Fri 31 Jan 2020 03:21:29 PM CET
 */

#ifndef VSYNC_TIME_H
#define VSYNC_TIME_H

#ifndef VSYNC_FREESTANDING

#include <time.h>
#define VSYNC_SRAND() srand(((unsigned int)time(NULL)))
#define VSYNC_RAND() rand()

#endif /* VSYNC_FREESTANDING */

#endif /* VSYNC_TIME_H */
