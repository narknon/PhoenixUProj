#include "AvatarPreset.h"

FAvatarPreset::FAvatarPreset() {
    this->PresetType = EAvatarPresetType::EYEBROWCOLOR;
    this->Gender = EGenderEnum::GENDER_MALE;
    this->DisplayInEditor = false;
    this->SortOrder = 0.00f;
}

