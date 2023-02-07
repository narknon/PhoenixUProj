#include "ProbeContactShadowsParametersOverride.h"

FProbeContactShadowsParametersOverride::FProbeContactShadowsParametersOverride() {
    this->bOverride_ProbeContactShadowsMinValue = false;
    this->bOverride_ProbeContactShadowsLength = false;
    this->bOverride_ProbeContactShadowsConeAngle = false;
    this->bOverride_ProbeContactShadowsFalloffExponent = false;
    this->bOverride_ProbeContactShadowsDepthTolerance = false;
    this->ProbeContactShadowsMinValue = 0.00f;
    this->ProbeContactShadowsLength = 0.00f;
    this->ProbeContactShadowsConeAngle = 0.00f;
    this->ProbeContactShadowsFalloffExponent = 0.00f;
    this->ProbeContactShadowsDepthTolerance = 0.00f;
}

