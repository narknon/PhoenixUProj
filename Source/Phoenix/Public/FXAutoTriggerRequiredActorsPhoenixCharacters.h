#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsBase.h"
#include "FXAutoTriggerRequiredActorsPhoenixCharacters.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsPhoenixCharacters : public UFXAutoTriggerRequiredActorsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludePlayer;
    
    UFXAutoTriggerRequiredActorsPhoenixCharacters();
};

