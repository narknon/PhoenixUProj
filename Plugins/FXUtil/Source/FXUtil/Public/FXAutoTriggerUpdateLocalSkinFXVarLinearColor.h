#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateLocalSkinFXVar.h"
#include "FXAutoTriggerUpdateLocalSkinFXVarLinearColor.generated.h"

class UFXAutoTriggerLinearColor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerUpdateLocalSkinFXVarLinearColor : public UFXAutoTriggerUpdateLocalSkinFXVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Var;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerLinearColor* Color;
    
    UFXAutoTriggerUpdateLocalSkinFXVarLinearColor();
};

