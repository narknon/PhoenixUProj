#include "MaterialPermuterCopyParameterOverrideBase.h"

FMaterialPermuterCopyParameterOverrideBase::FMaterialPermuterCopyParameterOverrideBase() {
    this->ParameterCopy = EMaterialPermuterParameterCopy::Default;
    this->bOnlySpecificMaterials = false;
}

