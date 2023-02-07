#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WorldEventCondition.generated.h"

UCLASS(Abstract, Blueprintable)
class UWorldEventCondition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNotValid;
    
    UWorldEventCondition();
};

