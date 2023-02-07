#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblSuperSlamForceHelperScratchpad.generated.h"

class UAblSuperSlamScratchpad;
class USkeletalMeshComponent;

UCLASS(Blueprintable, NonTransient)
class UAblSuperSlamForceHelperScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblSuperSlamScratchpad* SuperSlamScratchpad;
    
    UAblSuperSlamForceHelperScratchpad();
};

