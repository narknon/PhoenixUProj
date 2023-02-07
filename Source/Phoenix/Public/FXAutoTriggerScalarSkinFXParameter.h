#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "Templates/SubclassOf.h"
#include "FXAutoTriggerScalarSkinFXParameter.generated.h"

class ASkinFXDefinition;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarSkinFXParameter : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> Effect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValue;
    
    UFXAutoTriggerScalarSkinFXParameter();
};

