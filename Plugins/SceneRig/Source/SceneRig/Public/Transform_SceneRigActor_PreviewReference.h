#pragma once
#include "CoreMinimal.h"
#include "WorldActorReference.h"
#include "Transform_SceneRigActor_PreviewReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FTransform_SceneRigActor_PreviewReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldActorReference Reference;
    
    FTransform_SceneRigActor_PreviewReference();
};

