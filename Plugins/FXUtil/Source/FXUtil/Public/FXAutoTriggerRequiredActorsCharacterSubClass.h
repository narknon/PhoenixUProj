#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsCharacters.h"
#include "FXAutoTriggerRequiredActorsCharacterSubClass.generated.h"

class ACharacter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsCharacterSubClass : public UFXAutoTriggerRequiredActorsCharacters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter> CharacterType;
    
    UFXAutoTriggerRequiredActorsCharacterSubClass();
};

