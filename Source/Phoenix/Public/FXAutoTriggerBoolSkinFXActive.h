#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "Templates/SubclassOf.h"
#include "FXAutoTriggerBoolSkinFXActive.generated.h"

class ASkinFXDefinition;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolSkinFXActive : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> Effect;
    
    UFXAutoTriggerBoolSkinFXActive();
};

