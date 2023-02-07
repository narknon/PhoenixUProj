#pragma once
#include "CoreMinimal.h"
#include "ConversationPreset_DistanceProvider.h"
#include "ConversationPreset_DistanceProvider_AlongLine.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UConversationPreset_DistanceProvider_AlongLine : public UConversationPreset_DistanceProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StepDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSteps;
    
    UConversationPreset_DistanceProvider_AlongLine();
};

