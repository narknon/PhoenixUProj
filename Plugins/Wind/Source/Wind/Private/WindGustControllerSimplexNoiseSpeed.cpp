#include "WindGustControllerSimplexNoiseSpeed.h"

UWindGustControllerSimplexNoiseSpeed::UWindGustControllerSimplexNoiseSpeed() {
    this->Remap = EWindGustCurveRemap::Clamped;
    this->SpeedOp = EWindGustSpeedOp::Add;
}

