#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FXAutoTriggerScalar.h"
#include "SocialSemanticIDs.h"
#include "FXAutoTriggerScalarSocialSemanticRemap.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarSocialSemanticRemap : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialSemanticIDs> SemanticID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SemanticInputStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D OutputStrength;
    
    UFXAutoTriggerScalarSocialSemanticRemap();
};

