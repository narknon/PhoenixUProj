#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsHandlerInstancedFoliageBVHTestEntry.generated.h"

class UFoliageType;
class UOverlapEffectsHandlerEffect;

USTRUCT(BlueprintType)
struct FXUTIL_API FOverlapEffectsHandlerInstancedFoliageBVHTestEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UFoliageType>> FoliageTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UOverlapEffectsHandlerEffect*> Effects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActorXYBoundsPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float NextUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bReadyToTest;
    
    FOverlapEffectsHandlerInstancedFoliageBVHTestEntry();
};

