#include "RenderSettingsPPFilmAdvanced.h"

FRenderSettingsPPFilmAdvanced::FRenderSettingsPPFilmAdvanced() {
    this->bOverride_FilmShadowTint = false;
    this->bOverride_FilmShadowTintBlend = false;
    this->bOverride_FilmShadowTintAmount = false;
    this->bOverride_FilmChannelMixerRed = false;
    this->bOverride_FilmChannelMixerGreen = false;
    this->bOverride_FilmChannelMixerBlue = false;
    this->bOverride_FilmToeAmount = false;
    this->bOverride_FilmHealAmount = false;
    this->bOverride_FilmDynamicRange = false;
    this->FilmShadowTintBlend = 0.00f;
    this->FilmShadowTintAmount = 0.00f;
    this->FilmToeAmount = 0.00f;
    this->FilmHealAmount = 0.00f;
    this->FilmDynamicRange = 0.00f;
}

