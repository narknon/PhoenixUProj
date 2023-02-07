#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "SocialSemanticIDs.h"
#include "FXAutoTriggerScalarSocialSemanticValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarSocialSemanticValue : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> SemanticID;
    
    UFXAutoTriggerScalarSocialSemanticValue();
};

