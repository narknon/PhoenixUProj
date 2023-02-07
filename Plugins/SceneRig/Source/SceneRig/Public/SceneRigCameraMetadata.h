#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "ESceneRigCameraAttachment.h"
#include "SceneRigCameraMetadata.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneRigCameraMetadata : public UAnimMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigCameraAttachment Attachment;
    
    USceneRigCameraMetadata();
};

