#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainerWrapper.generated.h"

USTRUCT(BlueprintType)
struct FGameplayTagContainerWrapper {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer m_gameplayTagContainer;
    
    PHOENIX_API FGameplayTagContainerWrapper();
};

