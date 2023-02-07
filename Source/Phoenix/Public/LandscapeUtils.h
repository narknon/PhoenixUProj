#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LayerInfoWeight.h"
#include "LandscapeUtils.generated.h"

class ULandscapeHeightfieldCollisionComponent;
class UPhysicalMaterial;

UCLASS(Blueprintable)
class ULandscapeUtils : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULandscapeUtils();
    UFUNCTION(BlueprintCallable)
    static void LogLandscapeComponentLayerInfoData(ULandscapeHeightfieldCollisionComponent* LandColComponent);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FLayerInfoWeight> LineTraceForLayerInfoWeight(FVector Start, FVector End);
    
    UFUNCTION(BlueprintCallable)
    static float GetWetnessFromLayerInfoData(ULandscapeHeightfieldCollisionComponent* LandColComponent, const FVector& InLocation, const TArray<FString>& InWetnessLayerInfoNames, UPhysicalMaterial*& OutPhysMaterial);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FLayerInfoWeight> GetLandscapeComponentLayerInfoData(ULandscapeHeightfieldCollisionComponent* LandColComponent);
    
    UFUNCTION(BlueprintCallable)
    static void ClearLandscapeComponentLayerInfoData();
    
};

