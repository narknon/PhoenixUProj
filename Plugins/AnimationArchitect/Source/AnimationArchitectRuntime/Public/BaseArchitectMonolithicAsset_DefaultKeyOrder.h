#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BaseArchitectMonolithicAsset_DefaultKeyOrder.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FBaseArchitectMonolithicAsset_DefaultKeyOrder {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> DefaultKeyOrder;
    
    FBaseArchitectMonolithicAsset_DefaultKeyOrder();
};

