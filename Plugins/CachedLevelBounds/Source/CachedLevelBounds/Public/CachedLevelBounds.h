#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldLevelsBounds.h"
#include "CachedLevelBounds.generated.h"

class UWorld;

UCLASS(Blueprintable, Transient)
class CACHEDLEVELBOUNDS_API UCachedLevelBounds : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UWorld>, FWorldLevelsBounds> Worlds;
    
    UCachedLevelBounds();
};

