#include "MaterialPermuterBlueprintLibrary.h"

class AActor;

void UMaterialPermuterBlueprintLibrary::SimpleMaterialSwapParametersIsEmpty(const FMaterialSwapParametersSimple& ParameterSet, bool& bIsEmpty) {
}

FString UMaterialPermuterBlueprintLibrary::SimpleMaterialSwapParametersDump(FMaterialSwapParametersSimple ParameterSet, const FString& Delimiter) {
    return TEXT("");
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::SimpleCombineMaterialSwapParameters(FMaterialSwapParametersSimple A, FMaterialSwapParametersSimple B) {
    return FMaterialSwapParametersSimple{};
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::SetSimpleMaterialSwapParametersVector(FMaterialSwapParametersSimple& Parameters, FMaterialSwapVectorParameter Vector) {
    return FMaterialSwapParametersSimple{};
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::SetSimpleMaterialSwapParametersTexture(FMaterialSwapParametersSimple& Parameters, FMaterialSwapTextureParameter Texture) {
    return FMaterialSwapParametersSimple{};
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::SetSimpleMaterialSwapParametersScalar(FMaterialSwapParametersSimple& Parameters, FMaterialSwapScalarParameter Scalar) {
    return FMaterialSwapParametersSimple{};
}

void UMaterialPermuterBlueprintLibrary::SetMaterialSwapTransformedPairClosestBone(FMaterialSwapParameters& Parameters, AActor* Actor, FName PositionParameterName, FName VectorParameterName, FVector WorldPosition, FVector WorldVector) {
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::SetMaterialSwapParametersVector(FMaterialSwapParameters& Parameters, FMaterialSwapVectorParameter Vector) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::SetMaterialSwapParametersTransformedVector(FMaterialSwapParameters& Parameters, FMaterialSwapTransformedVector TransformedVector) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::SetMaterialSwapParametersTransformedPosition(FMaterialSwapParameters& Parameters, FMaterialSwapTransformedPosition TransformedPosition) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::SetMaterialSwapParametersTexture(FMaterialSwapParameters& Parameters, FMaterialSwapTextureParameter Texture) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::SetMaterialSwapParametersScalar(FMaterialSwapParameters& Parameters, FMaterialSwapScalarParameter Scalar) {
    return FMaterialSwapParameters{};
}

void UMaterialPermuterBlueprintLibrary::MaterialSwapParametersIsEmpty(const FMaterialSwapParameters& ParameterSet, bool& bIsEmpty) {
}

FString UMaterialPermuterBlueprintLibrary::MaterialSwapParametersDump(FMaterialSwapParameters ParameterSet, const FString& Delimiter) {
    return TEXT("");
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::MakeSimpleMaterialSwapParametersVector(FMaterialSwapVectorParameter Vector) {
    return FMaterialSwapParametersSimple{};
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::MakeSimpleMaterialSwapParametersTexture(FMaterialSwapTextureParameter Texture) {
    return FMaterialSwapParametersSimple{};
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::MakeSimpleMaterialSwapParametersScalar(FMaterialSwapScalarParameter Scalar) {
    return FMaterialSwapParametersSimple{};
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::MakeSimpleMaterialSwapParameters(TArray<FMaterialSwapScalarParameter> Scalars, TArray<FMaterialSwapVectorParameter> Vectors, TArray<FMaterialSwapTextureParameter> Textures) {
    return FMaterialSwapParametersSimple{};
}

FMaterialSwapTransformedVector UMaterialPermuterBlueprintLibrary::MakeMaterialSwapTransformedVectorClosestBone(AActor* Actor, FName ParameterName, FVector WorldPosition, FVector WorldVector) {
    return FMaterialSwapTransformedVector{};
}

FMaterialSwapTransformedVector UMaterialPermuterBlueprintLibrary::MakeMaterialSwapTransformedVector(AActor* Actor, FName ParameterName, FVector Vector, ETransformedParameterSpace Space, FName TransformSource, ETransformedParameterSource TransformType) {
    return FMaterialSwapTransformedVector{};
}

FMaterialSwapTransformedPosition UMaterialPermuterBlueprintLibrary::MakeMaterialSwapTransformedPositionClosestBone(AActor* Actor, FName ParameterName, FVector WorldPosition) {
    return FMaterialSwapTransformedPosition{};
}

FMaterialSwapTransformedPosition UMaterialPermuterBlueprintLibrary::MakeMaterialSwapTransformedPosition(AActor* Actor, FName ParameterName, FVector Position, ETransformedParameterSpace Space, FName TransformSource, ETransformedParameterSource TransformType) {
    return FMaterialSwapTransformedPosition{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::MakeMaterialSwapTransformedPairClosestBone(AActor* Actor, FName PositionParameterName, FName VectorParameterName, FVector WorldPosition, FVector WorldVector) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::MakeMaterialSwapParametersVector(FMaterialSwapVectorParameter Vector) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::MakeMaterialSwapParametersTexture(FMaterialSwapTextureParameter Texture) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::MakeMaterialSwapParametersScalar(FMaterialSwapScalarParameter Scalar) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::MakeMaterialSwapParametersFromSimple(FMaterialSwapParametersSimple Parameters) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::MakeMaterialSwapParametersFromNotSimple(FMaterialSwapParameters Parameters) {
    return FMaterialSwapParametersSimple{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::MakeMaterialSwapParameters(const TArray<FMaterialSwapScalarParameter>& Scalars, const TArray<FMaterialSwapVectorParameter>& Vectors, const TArray<FMaterialSwapTextureParameter>& Textures, const TArray<FMaterialSwapTransformedPosition>& TransformedPositions, const TArray<FMaterialSwapTransformedVector>& TransformedVectors) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParametersSimple UMaterialPermuterBlueprintLibrary::EmptySimpleMaterialSwapParameters(FMaterialSwapParametersSimple& ParameterSet) {
    return FMaterialSwapParametersSimple{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::EmptyMaterialSwapParameters(FMaterialSwapParameters& ParameterSet) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::CombineSimpleMaterialSwapParameters(FMaterialSwapParameters A, FMaterialSwapParametersSimple B) {
    return FMaterialSwapParameters{};
}

FMaterialSwapParameters UMaterialPermuterBlueprintLibrary::CombineMaterialSwapParameters(FMaterialSwapParameters A, FMaterialSwapParameters B) {
    return FMaterialSwapParameters{};
}

UMaterialPermuterBlueprintLibrary::UMaterialPermuterBlueprintLibrary() {
}

