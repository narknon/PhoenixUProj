#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OverlapEffectsDataAsset.generated.h"

class UOverlapEffectsHandler;

UCLASS(Blueprintable)
class FXUTIL_API UOverlapEffectsDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UOverlapEffectsHandler*> OverlapHandlers;
    
    UOverlapEffectsDataAsset();
};

