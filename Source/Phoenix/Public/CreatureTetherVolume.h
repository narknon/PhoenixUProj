#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "CreatureTetherVolume.generated.h"

UCLASS(Blueprintable)
class ACreatureTetherVolume : public AVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeAutoDetected;
    
    ACreatureTetherVolume(const FObjectInitializer& ObjectInitializer);
};

