#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "SocialSemanticIDs.h"
#include "FXAutoTriggerBoolSocialSemanticValue.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolSocialSemanticValue : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> SemanticID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UFXAutoTriggerBoolSocialSemanticValue();
};

