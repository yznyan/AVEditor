//
// Created by 阳坤 on 2020-05-21.
//


#include <cstring>
#include "AVData.h"

bool AVData::alloc(int size, const char *data) {
    drop();
    type = UCHAR_TYPE;
    if (size <= 0)return false;
    this->data = new unsigned char[size];
    if (!this->data) return false;
    if (data) {
        memcpy(this->data, data, size);
    }
    this->size = size;
    return false;
}

void AVData::drop() {
    if (!data || !datas || width == 0 || height == 0) return;
    if (type == AVPACKET_TYPE && (AVPacket **) &data)
        av_packet_free((AVPacket **) &data);
    else
        delete data;
    data = 0;
    size = 0;
}

void AVData::clone(AVData data) {
    this->size = data.size;
    if (size <= 0)return ;
    this->data = new unsigned char[size];
    if (!this->data) return ;
    if (data.data) {
        memcpy(this->data, data.data, size);
    }
    this->pts = data.pts;
    this->isAudio = data.isAudio;
    this->width = data.width;
    this->height = data.height;
    this->endPacket = data.endPacket;
    this->format = data.format;

}
