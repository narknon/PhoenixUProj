#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "MercunaNavExclusionVolume.generated.h"

class AMercunaNavOctree;

UCLASS(Blueprintable)
class MERCUNA_API AMercunaNavExclusionVolume : public AVolume {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyToAllNavOctrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AMercunaNavOctree*> NavOctrees;
    
public:
    AMercunaNavExclusionVolume(const FObjectInitializer& ObjectInitializer);
};

