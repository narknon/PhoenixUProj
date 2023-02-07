#pragma once
#include "CoreMinimal.h"
#include "ConversationPreset_FinalTransform.h"
#include "ConversationPreset_FinalTransform_MoveRelative.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UConversationPreset_FinalTransform_MoveRelative : public UConversationPreset_FinalTransform {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PositionDirectionAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StepDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSteps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotationOffset;
    
    UConversationPreset_FinalTransform_MoveRelative();
};

