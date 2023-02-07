#pragma once
#include "CoreMinimal.h"
#include "AnimationClipProvider.h"
#include "ActionParameter_Object.h"
#include "EStationStoryContent_ClipType.h"
#include "AnimationClip_StationStoryContent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimationClip_StationStoryContent : public UAnimationClipProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStationStoryContent_ClipType ClipType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_Object StoryContentParameter;
    
    UAnimationClip_StationStoryContent();
};

