#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigStageRole.h"
#include "StationStoryProp.generated.h"

class UStationStoryPropAttachment;

UCLASS(Abstract, Blueprintable, CollapseCategories)
class UStationStoryProp : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStageRole PropCastMember;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStationStoryPropAttachment* Attachment;
    
    UStationStoryProp();
};

