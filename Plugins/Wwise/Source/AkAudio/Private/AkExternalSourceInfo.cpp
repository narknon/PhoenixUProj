#include "AkExternalSourceInfo.h"

FAkExternalSourceInfo::FAkExternalSourceInfo() {
    this->CodecID = AkCodecId::None;
    this->ExternalSourceAsset = NULL;
    this->IsStreamed = false;
}

