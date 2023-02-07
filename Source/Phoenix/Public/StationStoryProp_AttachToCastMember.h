#pragma once
#include "CoreMinimal.h"
#include "SceneRigStageRole.h"
#include "StationStoryPropAttachment.h"
#include "StationStoryProp_AttachToCastMember.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStationStoryProp_AttachToCastMember : public UStationStoryPropAttachment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStageRole AttachParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString AttachSocket;
    
    UStationStoryProp_AttachToCastMember();
};

