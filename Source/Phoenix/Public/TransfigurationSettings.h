#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TransfigurationSettings.generated.h"

class ATransfigurationPreviewActor;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class UTransfigurationSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ATransfigurationPreviewActor> PreviewActorClass;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSecondsBetweenVanishments;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FoliageHidingZOffset;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoundsMinZ;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoundsMaxZ;
    
    UTransfigurationSettings();
};

