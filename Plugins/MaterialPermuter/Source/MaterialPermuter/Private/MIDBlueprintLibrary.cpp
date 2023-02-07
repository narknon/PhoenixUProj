#include "MIDBlueprintLibrary.h"

class AActor;
class UMaterialInstanceDynamic;
class UPrimitiveComponent;
class UTexture;

void UMIDBlueprintLibrary::SetMIDParametersVector(FMIDParameters& Parameters, FMIDVectorParameter Vector) {
}

void UMIDBlueprintLibrary::SetMIDParametersTexture(FMIDParameters& Parameters, FMIDTextureParameter Texture) {
}

void UMIDBlueprintLibrary::SetMIDParametersScalar(FMIDParameters& Parameters, FMIDScalarParameter Scalar) {
}

void UMIDBlueprintLibrary::PrimitiveCreateMIDs(UPrimitiveComponent* Component) {
}

void UMIDBlueprintLibrary::PrimitiveApplyMIDParameters(UPrimitiveComponent* Component, const FMIDParameters& Parameters, bool bAutoCreateMIDs) {
}

void UMIDBlueprintLibrary::MIDParametersIsEmpty(const FMIDParameters& ParameterSet, bool& bIsEmpty) {
}

FMIDVectorParameter UMIDBlueprintLibrary::MakeMIDVectorParameter(FName Name, FLinearColor Vector) {
    return FMIDVectorParameter{};
}

FMIDTextureParameter UMIDBlueprintLibrary::MakeMIDTextureParameter(FName Name, UTexture* Texture) {
    return FMIDTextureParameter{};
}

FMIDScalarParameter UMIDBlueprintLibrary::MakeMIDScalarParameter(FName Name, float Scalar) {
    return FMIDScalarParameter{};
}

FMIDParameters UMIDBlueprintLibrary::MakeMIDParametersVector(FMIDVectorParameter Vector) {
    return FMIDParameters{};
}

FMIDParameters UMIDBlueprintLibrary::MakeMIDParametersTexture(FMIDTextureParameter Texture) {
    return FMIDParameters{};
}

FMIDParameters UMIDBlueprintLibrary::MakeMIDParametersScalar(FMIDScalarParameter Scalar) {
    return FMIDParameters{};
}

FMIDParameters UMIDBlueprintLibrary::MakeMIDParameters(const TArray<FMIDScalarParameter>& Scalars, const TArray<FMIDVectorParameter>& Vectors, const TArray<FMIDTextureParameter>& Textures) {
    return FMIDParameters{};
}

FMIDParameters UMIDBlueprintLibrary::EmptyMIDParameters(FMIDParameters& ParameterSet) {
    return FMIDParameters{};
}

FMIDParameters UMIDBlueprintLibrary::CombineMIDParameters(FMIDParameters A, FMIDParameters B) {
    return FMIDParameters{};
}

void UMIDBlueprintLibrary::ApplyMIDParameters(UMaterialInstanceDynamic* Mid, const FMIDParameters& Parameters) {
}

void UMIDBlueprintLibrary::ActorCreateMIDs(AActor* Actor, bool bIncludeChildActors) {
}

void UMIDBlueprintLibrary::ActorApplyMIDParameters(AActor* Actor, const FMIDParameters& Parameters, bool bIncludeChildActors, bool bAutoCreateMIDs) {
}

UMIDBlueprintLibrary::UMIDBlueprintLibrary() {
}

