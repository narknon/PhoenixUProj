#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigShimDynamic.generated.h"

UCLASS(Blueprintable)
class USceneRigShimDynamic : public UObject {
    GENERATED_BODY()
public:
    USceneRigShimDynamic();
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnGameToBeSaved();
    
};

