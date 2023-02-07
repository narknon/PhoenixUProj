#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "Transform_StoryParticipantExit.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTransform_StoryParticipantExit : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ParticipantChannel;
    
    UTransform_StoryParticipantExit();
};

