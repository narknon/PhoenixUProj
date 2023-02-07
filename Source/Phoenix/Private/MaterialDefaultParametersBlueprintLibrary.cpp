#include "MaterialDefaultParametersBlueprintLibrary.h"

class UMaterialInterface;
class UTexture;

void UMaterialDefaultParametersBlueprintLibrary::GetMaterialDefaultVectorParameter(const FMaterialDefaultParameters& MaterialDefaultParameters, FName ParameterName, FLinearColor& DefaultValue, bool& bSuccess) {
}

void UMaterialDefaultParametersBlueprintLibrary::GetMaterialDefaultTextureParameter(const FMaterialDefaultParameters& MaterialDefaultParameters, FName ParameterName, UTexture*& DefaultValue, bool& bSuccess) {
}

void UMaterialDefaultParametersBlueprintLibrary::GetMaterialDefaultScalarParameter(const FMaterialDefaultParameters& MaterialDefaultParameters, FName ParameterName, float& DefaultValue, bool& bSuccess) {
}

void UMaterialDefaultParametersBlueprintLibrary::GetMaterialDefaultParameters(UMaterialInterface* Material, FMaterialDefaultParameters& MaterialDefaultParameters) {
}

UMaterialDefaultParametersBlueprintLibrary::UMaterialDefaultParametersBlueprintLibrary() {
}

