#pragma once
#include "CoreMinimal.h"
#include "CreatureNurturingVolumeBase.h"
#include "CreatureNurturingVolume.generated.h"

UCLASS(Blueprintable)
class ACreatureNurturingVolume : public ACreatureNurturingVolumeBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NurturingSpaceID;
    
public:
    ACreatureNurturingVolume();
};

