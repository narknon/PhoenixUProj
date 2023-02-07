#include "ToolEffectData.h"

UToolEffectData::UToolEffectData() {
    this->EffectType = EToolEffectType::ALPHA;
    this->GraphCurveFloat = NULL;
    this->BaseScale = 1.00f;
}

