#pragma once
#include "CoreMinimal.h"
#include "AvaMotionWarpWindowFinder.h"
#include "AblMotionWarpWindowFinder.generated.h"

class UAblAbilityComponent;

UCLASS(Blueprintable, EditInlineNew)
class UAblMotionWarpWindowFinder : public UAvaMotionWarpWindowFinder {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAblAbilityComponent* AblAbilityComponent;
    
public:
    UAblMotionWarpWindowFinder();
};

