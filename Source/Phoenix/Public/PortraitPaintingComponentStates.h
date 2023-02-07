#pragma once
#include "CoreMinimal.h"
#include "PortraitPaintingComponentState.h"
#include "PortraitPaintingComponentStates.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FPortraitPaintingComponentStates {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<USceneComponent>, FPortraitPaintingComponentState> States;
    
    PHOENIX_API FPortraitPaintingComponentStates();
};

