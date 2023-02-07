#pragma once
#include "CoreMinimal.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_PlayerScore.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_PlayerScore : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinPlayerScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxPlayerScore;
    
    UWorldEventCondition_PlayerScore();
};

