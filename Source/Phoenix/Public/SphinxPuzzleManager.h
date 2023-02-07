#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PhxDbRegistryTypeManager.h"
#include "SphinxPuzzleManager.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class USphinxPuzzleManager : public UPhxDbRegistryTypeManager {
    GENERATED_BODY()
public:
    USphinxPuzzleManager();
    UFUNCTION(BlueprintCallable)
    static FVector FlipendoPuzzle_GetRotationFromHitLocation(USceneComponent* BlockComponent, const FVector& HitLocation);
    
};

