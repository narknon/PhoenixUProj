#include "ClothInteractorBlueprintLibrary.h"


UChaosClothSharedSimConfig* UClothInteractorBlueprintLibrary::GetChaosClothSharedSimConfig(USkeletalMesh* SkeletalMesh, UChaosClothingInteractor* ChaosClothingInteractor) {
    return NULL;
}

UChaosClothConfig* UClothInteractorBlueprintLibrary::GetChaosClothConfig(USkeletalMesh* SkeletalMesh, UChaosClothingInteractor* ChaosClothingInteractor) {
    return NULL;
}

FVector UClothInteractorBlueprintLibrary::EvaluateVectorClothInteractorValue(const FVectorClothInteractorValue& ClothInteractorValue, const FVector& DefaultValue, float BlendAlpha) {
    return FVector{};
}

FVector2D UClothInteractorBlueprintLibrary::EvaluateVector2DClothInteractorValue(const FVector2DClothInteractorValue& ClothInteractorValue, const FVector2D& DefaultValue, float BlendAlpha) {
    return FVector2D{};
}

int32 UClothInteractorBlueprintLibrary::EvaluateIntClothInteractorValue(const FIntClothInteractorValue& ClothInteractorValue, const int32& DefaultValue, float BlendAlpha) {
    return 0;
}

float UClothInteractorBlueprintLibrary::EvaluateFloatClothInteractorValue(const FFloatClothInteractorValue& ClothInteractorValue, const float& DefaultValue, float BlendAlpha) {
    return 0.0f;
}

bool UClothInteractorBlueprintLibrary::EvaluateBoolClothInteractorValue(const FBoolClothInteractorValue& ClothInteractorValue, const bool& DefaultValue, float BlendAlpha) {
    return false;
}

UClothInteractorBlueprintLibrary::UClothInteractorBlueprintLibrary() {
}

