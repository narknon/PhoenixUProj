#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BoolClothInteractorValue.h"
#include "FloatClothInteractorValue.h"
#include "IntClothInteractorValue.h"
#include "Vector2DClothInteractorValue.h"
#include "VectorClothInteractorValue.h"
#include "ChaosCloth/ChaosClothConfig.h"
#include "ChaosCloth/ChaosClothingSimulationInteractor.h"
#include "ClothInteractorBlueprintLibrary.generated.h"


class USkeletalMesh;

UCLASS(Blueprintable)
class UClothInteractorBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UClothInteractorBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static UChaosClothSharedSimConfig* GetChaosClothSharedSimConfig(USkeletalMesh* SkeletalMesh, UChaosClothingInteractor* ChaosClothingInteractor);
    
    UFUNCTION(BlueprintCallable)
    static UChaosClothConfig* GetChaosClothConfig(USkeletalMesh* SkeletalMesh, UChaosClothingInteractor* ChaosClothingInteractor);
    
    UFUNCTION(BlueprintCallable)
    static FVector EvaluateVectorClothInteractorValue(const FVectorClothInteractorValue& ClothInteractorValue, const FVector& DefaultValue, float BlendAlpha);
    
    UFUNCTION(BlueprintCallable)
    static FVector2D EvaluateVector2DClothInteractorValue(const FVector2DClothInteractorValue& ClothInteractorValue, const FVector2D& DefaultValue, float BlendAlpha);
    
    UFUNCTION(BlueprintCallable)
    static int32 EvaluateIntClothInteractorValue(const FIntClothInteractorValue& ClothInteractorValue, const int32& DefaultValue, float BlendAlpha);
    
    UFUNCTION(BlueprintCallable)
    static float EvaluateFloatClothInteractorValue(const FFloatClothInteractorValue& ClothInteractorValue, const float& DefaultValue, float BlendAlpha);
    
    UFUNCTION(BlueprintCallable)
    static bool EvaluateBoolClothInteractorValue(const FBoolClothInteractorValue& ClothInteractorValue, const bool& DefaultValue, float BlendAlpha);
    
};

