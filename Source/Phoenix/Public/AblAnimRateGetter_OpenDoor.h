#pragma once
#include "CoreMinimal.h"
#include "AblAnimRateGetter.h"
#include "AblAnimRateGetter_OpenDoor.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimRateGetter_OpenDoor : public UAblAnimRateGetter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPlayRate;
    
    UAblAnimRateGetter_OpenDoor();
};

