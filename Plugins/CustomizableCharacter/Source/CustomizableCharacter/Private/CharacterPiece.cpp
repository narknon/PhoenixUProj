#include "CharacterPiece.h"

FName UCharacterPiece::ToId() const {
    return NAME_None;
}

UCharacterPiece::UCharacterPiece() {
    this->Gender = ECharacterPieceGenderEnum::GENDER_ANY;
    this->SleeveLength = ESleeveLengthEnum::SLEEVE_LENGTH_LONG;
    this->HatType = EHatTypeEnum::HAT_TYPE_A;
    this->ShoeHeight = EShoeHeightEnum::SHOE_HEIGHT_SLIPPER;
    this->PantLength = EPantLengthEnum::PANT_LENGTH_DRESS;
    this->RobeType = ERobeTypeEnum::ROBE_TYPE_A;
    this->GloveType = EGloveTypeEnum::GLOVE_TYPE_NORMAL;
    this->RobeShoulderType = ERobeShoulderTypeEnum::ROBE_SHOULDER_TYPE_BULKY;
    this->DefaultMesh = NULL;
    this->FacialPoseAsset = NULL;
    this->AnimClass = NULL;
}

