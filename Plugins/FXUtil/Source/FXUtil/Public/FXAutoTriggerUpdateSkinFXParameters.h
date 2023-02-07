#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateBase.h"
#include "Templates/SubclassOf.h"
#include "FXAutoTriggerUpdateSkinFXParameters.generated.h"

class ASkinFXDefinition;
class UFXAutoTriggerUpdateLocalSkinFXVar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerUpdateSkinFXParameters : public UFXAutoTriggerUpdateBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> SkinFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerUpdateLocalSkinFXVar*> Vars;
    
    UFXAutoTriggerUpdateSkinFXParameters();
};

