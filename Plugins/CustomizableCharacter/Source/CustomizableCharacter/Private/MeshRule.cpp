#include "MeshRule.h"

FMeshRule::FMeshRule() {
    this->Comparison = EComparisonEnum::COMP_EQUAL;
    this->Gender = EGenderEnum::GENDER_MALE;
    this->SleeveLength = ESleeveLengthEnum::SLEEVE_LENGTH_NOSLEEVES;
    this->HatType = EHatTypeEnum::HAT_TYPE_A;
    this->ShoeHeight = EShoeHeightEnum::SHOE_HEIGHT_THIGH;
    this->PantLength = EPantLengthEnum::PANT_LENGTH_DRESS;
    this->RobeType = ERobeTypeEnum::ROBE_TYPE_A;
    this->GloveType = EGloveTypeEnum::GLOVE_TYPE_NORMAL;
    this->RobeShoulderType = ERobeShoulderTypeEnum::ROBE_SHOULDER_TYPE_BULKY;
}

