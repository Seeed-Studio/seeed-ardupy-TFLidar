/**
 * The MIT License (MIT)
 *
 * Author: Junjie Chen (595355940@qq.com)
 *
 * Copyright (C) 2020  Seeed Technology Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include "Seeed_Arduino_TFlidar/src/TFLidar.h"
extern "C"{
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "shared-bindings/util.h"
}


#define  lidar     (*(TFLidar  *)self->module)
void * operator new(size_t, void *);

extern "C"{
    void common_hal_tf_lidar_construct(abstract_module_t * self){
        TFLuna * SeeedTFLuna =new TFLuna();
        self->module = new(m_new_obj(TFLidar)) TFLidar(SeeedTFLuna);
        lidar.begin(&Serial1,115200); 
    }
    void common_hal_tf_lidar_deinit(abstract_module_t * self){
        lidar.~TFLidar();
    }
    bool common_hal_tf_lidar_get_frame_data(abstract_module_t * self){
        return lidar.get_frame_data();
    }
    uint16_t common_hal_tf_lidar_get_distance(abstract_module_t * self){
        return lidar.get_distance();
    }
    uint16_t common_hal_tf_lidar_get_strength(abstract_module_t * self){
        return lidar.get_strength();
    }
    uint8_t common_hal_tf_lidar_get_chip_temperature(abstract_module_t * self){
        return lidar.get_chip_temperature();
    }    
}