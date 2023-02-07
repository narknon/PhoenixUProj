#include "RenderSettingsPPFilm.h"

FRenderSettingsPPFilm::FRenderSettingsPPFilm() {
    this->bOverride_FilmSlope = false;
    this->bOverride_FilmToe = false;
    this->bOverride_FilmShoulder = false;
    this->bOverride_FilmBlackClip = false;
    this->bOverride_FilmWhiteClip = false;
    this->bOverride_FilmWhitePoint = false;
    this->bOverride_FilmSaturation = false;
    this->bOverride_FilmContrast = false;
    this->FilmSlope = 0.00f;
    this->FilmToe = 0.00f;
    this->FilmShoulder = 0.00f;
    this->FilmBlackClip = 0.00f;
    this->FilmWhiteClip = 0.00f;
    this->FilmSaturation = 0.00f;
    this->FilmContrast = 0.00f;
}

