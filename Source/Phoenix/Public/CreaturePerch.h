#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CreaturePerch.generated.h"

UCLASS(Blueprintable)
class ACreaturePerch : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBidirectional;
    
public:
    ACreaturePerch(const FObjectInitializer& ObjectInitializer);
};

