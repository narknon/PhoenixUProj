#pragma once
#include "CoreMinimal.h"
#include "Perception/AISenseConfig.h"
#include "AISenseConfig_NearbyCreatures.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAISenseConfig_NearbyCreatures : public UAISenseConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UAISenseConfig_NearbyCreatures();
};

