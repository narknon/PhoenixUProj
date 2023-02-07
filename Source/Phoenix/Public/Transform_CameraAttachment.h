#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "Transform_CameraAttachment.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UTransform_CameraAttachment : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* TargetActor;
    
    UTransform_CameraAttachment();
};

