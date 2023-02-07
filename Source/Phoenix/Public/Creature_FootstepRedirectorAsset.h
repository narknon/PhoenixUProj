#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "Creature_FootstepRedirectorAsset.generated.h"

class UCreature_FootstepDataAsset;

UCLASS(Blueprintable)
class UCreature_FootstepRedirectorAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCreature_FootstepDataAsset> AssetClass;
    
    UCreature_FootstepRedirectorAsset();
};

