#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AblAbilityChannel.h"
#include "AblAbilityAsset.generated.h"

UCLASS(Blueprintable)
class ABLECORE_API UAblAbilityAsset : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FAblAbilityChannel> AbilityChannelMap;
    
public:
    UAblAbilityAsset();
};

