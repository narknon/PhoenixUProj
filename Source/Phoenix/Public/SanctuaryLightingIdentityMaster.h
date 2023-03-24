#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SanctuaryLightingIdentityMaster.generated.h"

class USanctuaryLightingIdentityMasterComponent;

UCLASS(Blueprintable)
class ASanctuaryLightingIdentityMaster : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USanctuaryLightingIdentityMasterComponent* MasterComponent;
    
    ASanctuaryLightingIdentityMaster(const FObjectInitializer& ObjectInitializer);
};

