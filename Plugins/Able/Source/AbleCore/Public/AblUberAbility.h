#pragma once
#include "CoreMinimal.h"
#include "AblAbilityChannel.h"
#include "AblUberAbility.generated.h"

USTRUCT(BlueprintType)
struct ABLECORE_API FAblUberAbility {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAblAbilityChannel> SortedAbilityChannels;
    
public:
    FAblUberAbility();
};

