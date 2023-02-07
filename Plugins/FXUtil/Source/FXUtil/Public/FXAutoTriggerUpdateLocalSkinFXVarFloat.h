#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateLocalSkinFXVar.h"
#include "FXAutoTriggerUpdateLocalSkinFXVarFloat.generated.h"

class UFXAutoTriggerScalar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerUpdateLocalSkinFXVarFloat : public UFXAutoTriggerUpdateLocalSkinFXVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Var;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* Scalar;
    
    UFXAutoTriggerUpdateLocalSkinFXVarFloat();
};

